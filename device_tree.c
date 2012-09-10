/*
 * Functions to help device tree manipulation using libfdt.
 * It also provides functions to read entries from device tree proc
 * interface.
 *
 * Copyright 2008 IBM Corporation.
 * Authors: Jerone Young <jyoung5@us.ibm.com>
 *          Hollis Blanchard <hollisb@us.ibm.com>
 *
 * This work is licensed under the GNU GPL license version 2 or later.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "config.h"
#include "qemu-common.h"
#include "device_tree.h"
#include "hw/loader.h"
#include "qemu-option.h"
#include "qemu-config.h"

#include <libfdt.h>

#define FDT_MAX_SIZE  0x10000

void *create_device_tree(int *sizep)
{
    void *fdt;
    int ret;

    *sizep = FDT_MAX_SIZE;
    fdt = g_malloc0(FDT_MAX_SIZE);
    ret = fdt_create(fdt, FDT_MAX_SIZE);
    if (ret < 0) {
        goto fail;
    }
    ret = fdt_begin_node(fdt, "");
    if (ret < 0) {
        goto fail;
    }
    ret = fdt_end_node(fdt);
    if (ret < 0) {
        goto fail;
    }
    ret = fdt_finish(fdt);
    if (ret < 0) {
        goto fail;
    }
    ret = fdt_open_into(fdt, fdt, *sizep);
    if (ret) {
        fprintf(stderr, "Unable to copy device tree in memory\n");
        exit(1);
    }

    return fdt;
fail:
    fprintf(stderr, "%s Couldn't create dt: %s\n", __func__, fdt_strerror(ret));
    exit(1);
}

void *load_device_tree(const char *filename_path, int *sizep)
{
    int dt_size;
    int dt_file_load_size;
    int ret;
    void *fdt = NULL;

    *sizep = 0;
    dt_size = get_image_size(filename_path);
    if (dt_size < 0) {
        printf("Unable to get size of device tree file '%s'\n",
            filename_path);
        goto fail;
    }

    /* Expand to 2x size to give enough room for manipulation.  */
    dt_size += 10000;
    dt_size *= 2;
    /* First allocate space in qemu for device tree */
    fdt = g_malloc0(dt_size);

    dt_file_load_size = load_image(filename_path, fdt);
    if (dt_file_load_size < 0) {
        printf("Unable to open device tree file '%s'\n",
               filename_path);
        goto fail;
    }

    ret = fdt_open_into(fdt, fdt, dt_size);
    if (ret) {
        printf("Unable to copy device tree in memory\n");
        goto fail;
    }

    /* Check sanity of device tree */
    if (fdt_check_header(fdt)) {
        printf ("Device tree file loaded into memory is invalid: %s\n",
            filename_path);
        goto fail;
    }
    *sizep = dt_size;
    return fdt;

fail:
    g_free(fdt);
    return NULL;
}

static int findnode_nofail(void *fdt, const char *node_path)
{
    int offset;

    offset = fdt_path_offset(fdt, node_path);
    if (offset < 0) {
        fprintf(stderr, "%s Couldn't find node %s: %s\n", __func__, node_path,
                fdt_strerror(offset));
        exit(1);
    }

    return offset;
}

int qemu_devtree_setprop(void *fdt, const char *node_path,
                         const char *property, const void *val_array, int size)
{
    int r;

    r = fdt_setprop(fdt, findnode_nofail(fdt, node_path), property, val_array, size);
    if (r < 0) {
        fprintf(stderr, "%s: Couldn't set %s/%s: %s\n", __func__, node_path,
                property, fdt_strerror(r));
        exit(1);
    }

    return r;
}

int qemu_devtree_setprop_cell(void *fdt, const char *node_path,
                              const char *property, uint32_t val)
{
    int r;

    r = fdt_setprop_cell(fdt, findnode_nofail(fdt, node_path), property, val);
    if (r < 0) {
        fprintf(stderr, "%s: Couldn't set %s/%s = %#08x: %s\n", __func__,
                node_path, property, val, fdt_strerror(r));
        exit(1);
    }

    return r;
}

int qemu_devtree_setprop_u64(void *fdt, const char *node_path,
                             const char *property, uint64_t val)
{
    val = cpu_to_be64(val);
    return qemu_devtree_setprop(fdt, node_path, property, &val, sizeof(val));
}

int qemu_devtree_setprop_string(void *fdt, const char *node_path,
                                const char *property, const char *string)
{
    int r;

    r = fdt_setprop_string(fdt, findnode_nofail(fdt, node_path), property, string);
    if (r < 0) {
        fprintf(stderr, "%s: Couldn't set %s/%s = %s: %s\n", __func__,
                node_path, property, string, fdt_strerror(r));
        exit(1);
    }

    return r;
}

const void *qemu_devtree_getprop(void *fdt, const char *node_path,
                                 const char *property, int *lenp,
                                 bool inherit, Error **errp)
{
    int len;
    const void *r;
    if (!lenp) {
        lenp = &len;
    }
    r = fdt_getprop(fdt, findnode_nofail(fdt, node_path), property, lenp);
    if (!r) {
        char parent[DT_PATH_LENGTH];
        if (inherit && !qemu_devtree_getparent(fdt, parent, node_path)) {
            return qemu_devtree_getprop(fdt, parent, property, lenp, true,
                                                                errp);
        }
        fprintf(stderr, "%s: Couldn't get %s/%s: %s\n", __func__,
                node_path, property, fdt_strerror(*lenp));
        /* FIXME: Be smarter */
        error_set(errp, QERR_UNDEFINED_ERROR);
        return NULL;
    }
    return r;
}

uint32_t qemu_devtree_getprop_cell(void *fdt, const char *node_path,
                                   const char *property, int offset,
                                   bool inherit, Error **errp)
{
    int len;
    const uint32_t *p = qemu_devtree_getprop(fdt, node_path, property, &len,
                                                                inherit, errp);
    if (errp && *errp) {
        return 0;
    }
    if (len < (offset+1)*4) {
        fprintf(stderr, "%s: %s/%s not long enough to hold %d properties "
                "(length = %d)\n", __func__, node_path, property,
                offset+1, len);
        /* FIXME: Be smarter */
        error_set(errp, QERR_UNDEFINED_ERROR);
        return 0;
    }
    return be32_to_cpu(p[offset]);
}

uint32_t qemu_devtree_get_phandle(void *fdt, const char *path)
{
    uint32_t r;

    r = fdt_get_phandle(fdt, findnode_nofail(fdt, path));
    if (r <= 0) {
        fprintf(stderr, "%s: Couldn't get phandle for %s: %s\n", __func__,
                path, fdt_strerror(r));
        exit(1);
    }

    return r;
}

int qemu_devtree_setprop_phandle(void *fdt, const char *node_path,
                                 const char *property,
                                 const char *target_node_path)
{
    uint32_t phandle = qemu_devtree_get_phandle(fdt, target_node_path);
    return qemu_devtree_setprop_cell(fdt, node_path, property, phandle);
}

uint32_t qemu_devtree_alloc_phandle(void *fdt)
{
    static int phandle = 0x0;

    /*
     * We need to find out if the user gave us special instruction at
     * which phandle id to start allocting phandles.
     */
    if (!phandle) {
        QemuOpts *machine_opts;
        machine_opts = qemu_opts_find(qemu_find_opts("machine"), 0);
        if (machine_opts) {
            const char *phandle_start;
            phandle_start = qemu_opt_get(machine_opts, "phandle_start");
            if (phandle_start) {
                phandle = strtoul(phandle_start, NULL, 0);
            }
        }
    }

    if (!phandle) {
        /*
         * None or invalid phandle given on the command line, so fall back to
         * default starting point.
         */
        phandle = 0x8000;
    }

    return phandle++;
}

int qemu_devtree_nop_node(void *fdt, const char *node_path)
{
    int r;

    r = fdt_nop_node(fdt, findnode_nofail(fdt, node_path));
    if (r < 0) {
        fprintf(stderr, "%s: Couldn't nop node %s: %s\n", __func__, node_path,
                fdt_strerror(r));
        exit(1);
    }

    return r;
}

int qemu_devtree_add_subnode(void *fdt, const char *name)
{
    char *dupname = g_strdup(name);
    char *basename = strrchr(dupname, '/');
    int retval;
    int parent = 0;

    if (!basename) {
        g_free(dupname);
        return -1;
    }

    basename[0] = '\0';
    basename++;

    if (dupname[0]) {
        parent = findnode_nofail(fdt, dupname);
    }

    retval = fdt_add_subnode(fdt, parent, basename);
    if (retval < 0) {
        fprintf(stderr, "FDT: Failed to create subnode %s: %s\n", name,
                fdt_strerror(retval));
        exit(1);
    }

    g_free(dupname);
    return retval;
}

void qemu_devtree_dumpdtb(void *fdt, int size)
{
    QemuOpts *machine_opts;

    machine_opts = qemu_opts_find(qemu_find_opts("machine"), 0);
    if (machine_opts) {
        const char *dumpdtb = qemu_opt_get(machine_opts, "dumpdtb");
        if (dumpdtb) {
            /* Dump the dtb to a file and quit */
            exit(g_file_set_contents(dumpdtb, fdt, size, NULL) ? 0 : 1);
        }
    }

}
