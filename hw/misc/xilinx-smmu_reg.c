/*
 * QEMU model of the SMMU_REG System Memory Management Unit Configuration
 * and event registers
 *
 * Copyright (c) 2015 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2015-04-05.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "hw/fdt_generic_util.h"

#ifndef XILINX_SMMU_REG_ERR_DEBUG
#define XILINX_SMMU_REG_ERR_DEBUG 0
#endif

#define TYPE_XILINX_SMMU_REG "xlnx.smmu-reg"

#define XILINX_SMMU_REG(obj) \
     OBJECT_CHECK(SMMU_REG, (obj), TYPE_XILINX_SMMU_REG)

REG32(MISC_CTRL, 0x0)
    FIELD(MISC_CTRL, SLVERR_ENABLE, 1, 0)
REG32(ISR_0, 0x10)
    FIELD(ISR_0, ADDR_DECODE_ERR, 1, 31)
    FIELD(ISR_0, GBL_FLT_IRPT_NS, 1, 4)
    FIELD(ISR_0, GBL_FLT_IRPT_S, 1, 3)
    FIELD(ISR_0, COMB_PERF_IRPT_TBU, 1, 2)
    FIELD(ISR_0, COMB_IRPT_S, 1, 1)
    FIELD(ISR_0, COMB_IRPT_NS, 1, 0)
REG32(IMR_0, 0x14)
    FIELD(IMR_0, ADDR_DECODE_ERR, 1, 31)
    FIELD(IMR_0, GBL_FLT_IRPT_NS, 1, 4)
    FIELD(IMR_0, GBL_FLT_IRPT_S, 1, 3)
    FIELD(IMR_0, COMB_PERF_IRPT_TBU, 1, 2)
    FIELD(IMR_0, COMB_IRPT_S, 1, 1)
    FIELD(IMR_0, COMB_IRPT_NS, 1, 0)
REG32(IER_0, 0x18)
    FIELD(IER_0, ADDR_DECODE_ERR, 1, 31)
    FIELD(IER_0, GBL_FLT_IRPT_NS, 1, 4)
    FIELD(IER_0, GBL_FLT_IRPT_S, 1, 3)
    FIELD(IER_0, COMB_PERF_IRPT_TBU, 1, 2)
    FIELD(IER_0, COMB_IRPT_S, 1, 1)
    FIELD(IER_0, COMB_IRPT_NS, 1, 0)
REG32(IDR_0, 0x1c)
    FIELD(IDR_0, ADDR_DECODE_ERR, 1, 31)
    FIELD(IDR_0, GBL_FLT_IRPT_NS, 1, 4)
    FIELD(IDR_0, GBL_FLT_IRPT_S, 1, 3)
    FIELD(IDR_0, COMB_PERF_IRPT_TBU, 1, 2)
    FIELD(IDR_0, COMB_IRPT_S, 1, 1)
    FIELD(IDR_0, COMB_IRPT_NS, 1, 0)
REG32(ITR_0, 0x20)
    FIELD(ITR_0, ADDR_DECODE_ERR, 1, 31)
    FIELD(ITR_0, GBL_FLT_IRPT_NS, 1, 4)
    FIELD(ITR_0, GBL_FLT_IRPT_S, 1, 3)
    FIELD(ITR_0, COMB_PERF_IRPT_TBU, 1, 2)
    FIELD(ITR_0, COMB_IRPT_S, 1, 1)
    FIELD(ITR_0, COMB_IRPT_NS, 1, 0)
REG32(QREQN, 0x40)
    FIELD(QREQN, TBU_TBU5_5_CG, 1, 14)
    FIELD(QREQN, TBU_TBU5_5_PD, 1, 13)
    FIELD(QREQN, TBU_TBU4_4_CG, 1, 12)
    FIELD(QREQN, TBU_TBU4_4_PD, 1, 11)
    FIELD(QREQN, TBU_TBU3_3_CG, 1, 10)
    FIELD(QREQN, TBU_TBU3_3_PD, 1, 9)
    FIELD(QREQN, PD_MST_BR_TBU2_2, 1, 8)
    FIELD(QREQN, PD_SLV_BR_TBU2_2, 1, 7)
    FIELD(QREQN, TBU_TBU2_2_CG, 1, 6)
    FIELD(QREQN, TBU_TBU2_2_PD, 1, 5)
    FIELD(QREQN, TBU_TBU1_1_CG, 1, 4)
    FIELD(QREQN, TBU_TBU1_1_PD, 1, 3)
    FIELD(QREQN, TBU_TBU0_0_CG, 1, 2)
    FIELD(QREQN, TBU_TBU0_0_PD, 1, 1)
    FIELD(QREQN, TCU, 1, 0)
REG32(MISC, 0x54)
    FIELD(MISC, SPNIDEN, 1, 12)
    FIELD(MISC, ARQOSARB, 4, 8)
    FIELD(MISC, AWAKEUP_PROG, 1, 7)
    FIELD(MISC, EMAS, 1, 6)
    FIELD(MISC, EMAW, 2, 4)
    FIELD(MISC, EMA, 3, 1)
REG32(CONFIG_SIGNALS, 0x58)
    FIELD(CONFIG_SIGNALS, CFG_NORMALIZE, 1, 1)
REG32(ECO_INFO, 0x100)
    FIELD(ECO_INFO, ECOREVNUM, 4, 0)
REG32(ECO_0, 0x104)
REG32(ECO_1, 0x108)

#define R_MAX (R_ECO_1 + 1)

typedef struct SMMU_REG {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_imr_0;

    uint32_t irq_src;

    uint32_t regs[R_MAX];
    RegisterInfo regs_info[R_MAX];
} SMMU_REG;

static void imr_0_update_irq(SMMU_REG *s)
{
    bool global_irq;
    bool ctxt_irq;
    bool pending;

    global_irq = s->irq_src & 1;
    ctxt_irq = s->irq_src & (~1);
    s->regs[R_ISR_0] |= ctxt_irq << 0;
    s->regs[R_ISR_0] |= ctxt_irq << 1;
    s->regs[R_ISR_0] |= global_irq << 3;
    s->regs[R_ISR_0] |= global_irq << 4;

    pending = s->regs[R_ISR_0] & ~s->regs[R_IMR_0];
    qemu_set_irq(s->irq_imr_0, pending);
}

static void isr_0_postw(RegisterInfo *reg, uint64_t val64)
{
    SMMU_REG *s = XILINX_SMMU_REG(reg->opaque);
    imr_0_update_irq(s);
}

static uint64_t ier_0_prew(RegisterInfo *reg, uint64_t val64)
{
    SMMU_REG *s = XILINX_SMMU_REG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IMR_0] &= ~val;
    imr_0_update_irq(s);
    return 0;
}

static uint64_t idr_0_prew(RegisterInfo *reg, uint64_t val64)
{
    SMMU_REG *s = XILINX_SMMU_REG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IMR_0] |= val;
    imr_0_update_irq(s);
    return 0;
}

static uint64_t itr_0_prew(RegisterInfo *reg, uint64_t val64)
{
    SMMU_REG *s = XILINX_SMMU_REG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_ISR_0] |= val;
    imr_0_update_irq(s);
    return 0;
}

static RegisterAccessInfo smmu_reg_regs_info[] = {
    {   .name = "MISC_CTRL",  .decode.addr = A_MISC_CTRL,
    },{ .name = "ISR_0",  .decode.addr = A_ISR_0,
        .rsvd = 0x7fffffe0,
        .ro = 0x7fffffe0,
        .w1c = 0x8000001f,
        .post_write = isr_0_postw,
    },{ .name = "IMR_0",  .decode.addr = A_IMR_0,
        .reset = 0x8000001f,
        .rsvd = 0x7fffffe0,
        .ro = 0x7fffffff,
        .w1c = 0x80000000,
    },{ .name = "IER_0",  .decode.addr = A_IER_0,
        .rsvd = 0x7fffffe0,
        .ro = 0x7fffffe0,
        .w1c = 0x80000000,
        .pre_write = ier_0_prew,
    },{ .name = "IDR_0",  .decode.addr = A_IDR_0,
        .rsvd = 0x7fffffe0,
        .ro = 0x7fffffe0,
        .w1c = 0x80000000,
        .pre_write = idr_0_prew,
    },{ .name = "ITR_0",  .decode.addr = A_ITR_0,
        .rsvd = 0x7fffffe0,
        .ro = 0x7fffffe0,
        .w1c = 0x80000000,
        .pre_write = itr_0_prew,
    },{ .name = "QREQN",  .decode.addr = A_QREQN,
        .reset = 0x7fff,
        .rsvd = 0xffff8000,
    },{ .name = "MISC",  .decode.addr = A_MISC,
        .reset = 0x16,
        .rsvd = 0xffffe001,
        .ro = 0xf00,
    },{ .name = "CONFIG_SIGNALS",  .decode.addr = A_CONFIG_SIGNALS,
        .rsvd = 0xfffffffd,
    },{ .name = "ECO_INFO",  .decode.addr = A_ECO_INFO,
    },{ .name = "ECO_0",  .decode.addr = A_ECO_0,
    },{ .name = "ECO_1",  .decode.addr = A_ECO_1,
        .reset = 0xffffffff,
    }
};

static void smmu_reg_reset(DeviceState *dev)
{
    SMMU_REG *s = XILINX_SMMU_REG(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    imr_0_update_irq(s);
}

static uint64_t smmu_reg_read(void *opaque, hwaddr addr, unsigned size)
{
    SMMU_REG *s = XILINX_SMMU_REG(opaque);
    RegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        return 0;
    }
    return register_read(r);
}

static void smmu_reg_write(void *opaque, hwaddr addr, uint64_t value,
                      unsigned size)
{
    SMMU_REG *s = XILINX_SMMU_REG(opaque);
    RegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, value);
        return;
    }
    register_write(r, value, ~0);
}

static const MemoryRegionOps smmu_reg_ops = {
    .read = smmu_reg_read,
    .write = smmu_reg_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void irq_handler(void *opaque, int irq, int level)
{
    SMMU_REG *s = XILINX_SMMU_REG(opaque);

    s->irq_src &= ~(1 << irq);
    s->irq_src |= level << irq;
    imr_0_update_irq(s);
}

static void smmu_reg_realize(DeviceState *dev, Error **errp)
{
    SMMU_REG *s = XILINX_SMMU_REG(dev);
    const char *prefix = object_get_canonical_path(OBJECT(dev));
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(smmu_reg_regs_info); ++i) {
        RegisterInfo *r = &s->regs_info[smmu_reg_regs_info[i].decode.addr/4];

        *r = (RegisterInfo) {
            .data = (uint8_t *)&s->regs[
                    smmu_reg_regs_info[i].decode.addr/4],
            .data_size = sizeof(uint32_t),
            .access = &smmu_reg_regs_info[i],
            .debug = XILINX_SMMU_REG_ERR_DEBUG,
            .prefix = prefix,
            .opaque = s,
        };
    }

    qdev_init_gpio_in(dev, irq_handler, 17);
}

static void smmu_reg_init(Object *obj)
{
    SMMU_REG *s = XILINX_SMMU_REG(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &smmu_reg_ops, s,
                          TYPE_XILINX_SMMU_REG, R_MAX * 4);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_imr_0);
}

static int smmu_reg_fdt_get_irq(FDTGenericIntc *obj, qemu_irq *irqs,
                                uint32_t *cells, int ncells, int max,
                                Error **errp)
{
    /* FIXME: Add Error checking */
    (*irqs) = qdev_get_gpio_in(DEVICE(obj), cells[0]);
    return 1;
};

static const VMStateDescription vmstate_smmu_reg = {
    .name = TYPE_XILINX_SMMU_REG,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, SMMU_REG, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void smmu_reg_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericIntcClass *fgic = FDT_GENERIC_INTC_CLASS(klass);

    dc->reset = smmu_reg_reset;
    dc->realize = smmu_reg_realize;
    dc->vmsd = &vmstate_smmu_reg;
    fgic->get_irq = smmu_reg_fdt_get_irq;
}

static const TypeInfo smmu_reg_info = {
    .name          = TYPE_XILINX_SMMU_REG,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(SMMU_REG),
    .class_init    = smmu_reg_class_init,
    .instance_init = smmu_reg_init,
    .interfaces = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_INTC },
        { }
    },
};

static void smmu_reg_register_types(void)
{
    type_register_static(&smmu_reg_info);
}

type_init(smmu_reg_register_types)
