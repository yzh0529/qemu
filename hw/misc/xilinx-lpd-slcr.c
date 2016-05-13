/*
 * QEMU model of the LPD_SLCR Global system level control registers for the low power domain
 *
 * Copyright (c) 2014 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2014-12-16.
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

#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"

#ifndef XILINX_LPD_SLCR_ERR_DEBUG
#define XILINX_LPD_SLCR_ERR_DEBUG 0
#endif

#define TYPE_XILINX_LPD_SLCR "xlnx.lpd-slcr"

#define XILINX_LPD_SLCR(obj) \
     OBJECT_CHECK(LPD_SLCR, (obj), TYPE_XILINX_LPD_SLCR)

REG32(WPROT0, 0x0)
    FIELD(WPROT0, ACTIVE, 1, 0)
REG32(CTRL, 0x4)
    FIELD(CTRL, SLVERR_ENABLE, 1, 0)
REG32(ISR, 0x8)
    FIELD(ISR, ADDR_DECODE_ERR, 1, 0)
REG32(IMR, 0xc)
    FIELD(IMR, ADDR_DECODE_ERR, 1, 0)
REG32(IER, 0x10)
    FIELD(IER, ADDR_DECODE_ERR, 1, 0)
REG32(IDR, 0x14)
    FIELD(IDR, ADDR_DECODE_ERR, 1, 0)
REG32(ITR, 0x18)
    FIELD(ITR, ADDR_DECODE_ERR, 1, 0)
REG32(ECO, 0x1c)
REG32(PERSISTENT0, 0x20)
REG32(PERSISTENT1, 0x24)
REG32(PERSISTENT2, 0x28)
REG32(PERSISTENT3, 0x2c)
REG32(PERSISTENT4, 0x30)
REG32(PERSISTENT5, 0x34)
REG32(PERSISTENT6, 0x38)
REG32(PERSISTENT7, 0x3c)
REG32(SAFETY_CHK0, 0x40)
REG32(SAFETY_CHK1, 0x44)
REG32(SAFETY_CHK2, 0x48)
REG32(SAFETY_CHK3, 0x4c)
REG32(CSUPMU_WDT_CLK_SEL, 0x00000050)
REG32(ADMA_CFG, 0x0000200C)
REG32(ADMA_RAM, 0x00002010)
REG32(ERR_AIBAXI_ISR, 0x00003000)
REG32(ERR_AIBAXI_IMR, 0x00003008)
REG32(ERR_AIBAXI_IER, 0x00003010)
REG32(ERR_AIBAXI_IDR, 0x00003018)
REG32(ERR_AIBAPB_ISR, 0x00003020)
REG32(ERR_AIBAPB_IMR, 0x00003024)
REG32(ERR_AIBAPB_IER, 0x00003028)
REG32(ERR_AIBAPB_IDR, 0x0000302C)
REG32(ISO_AIBAXI_REQ, 0x00003030)
REG32(ISO_AIBAXI_TYPE, 0x00003038)
REG32(ISO_AIBAXI_ACK, 0x00003040)
REG32(ISO_AIBAPB_REQ, 0x00003048)
REG32(ISO_AIBAPB_TYPE, 0x0000304C)
REG32(ISO_AIBAPB_ACK, 0x00003050)
REG32(ERR_ATB_ISR, 0x00006000)
REG32(ERR_ATB_IMR, 0x00006004)
REG32(ERR_ATB_IER, 0x00006008)
REG32(ERR_ATB_IDR, 0x0000600C)
REG32(ATB_CMD_STORE_EN, 0x00006010)
REG32(ATB_RESP_EN, 0x00006014)
REG32(ATB_RESP_TYPE, 0x00006018)
REG32(ATB_PRESCALE, 0x00006020)
REG32(MUTEX0, 0x00007000)
REG32(MUTEX1, 0x00007004)
REG32(MUTEX2, 0x00007008)
REG32(MUTEX3, 0x0000700C)
REG32(GICP0_IRQ_STATUS, 0x00008000)
REG32(GICP0_IRQ_MASK, 0x00008004)
REG32(GICP0_IRQ_ENABLE, 0x00008008)
REG32(GICP0_IRQ_DISABLE, 0x0000800C)
REG32(GICP0_IRQ_TRIGGER, 0x00008010)
REG32(GICP1_IRQ_STATUS, 0x00008014)
REG32(GICP1_IRQ_MASK, 0x00008018)
REG32(GICP1_IRQ_ENABLE, 0x0000801C)
REG32(GICP1_IRQ_DISABLE, 0x00008020)
REG32(GICP1_IRQ_TRIGGER, 0x00008024)
REG32(GICP2_IRQ_STATUS, 0x00008028)
REG32(GICP2_IRQ_MASK, 0x0000802C)
REG32(GICP2_IRQ_ENABLE, 0x00008030)
REG32(GICP2_IRQ_DISABLE, 0x00008034)
REG32(GICP2_IRQ_TRIGGER, 0x00008038)
REG32(GICP3_IRQ_STATUS, 0x0000803C)
REG32(GICP3_IRQ_MASK, 0x00008040)
REG32(GICP3_IRQ_ENABLE, 0x00008044)
REG32(GICP3_IRQ_DISABLE, 0x00008048)
REG32(GICP3_IRQ_TRIGGER, 0x0000804C)
REG32(GICP4_IRQ_STATUS, 0x00008050)
REG32(GICP4_IRQ_MASK, 0x00008054)
REG32(GICP4_IRQ_ENABLE, 0x00008058)
REG32(GICP4_IRQ_DISABLE, 0x0000805C)
REG32(GICP4_IRQ_TRIGGER, 0x00008060)
REG32(GICP_PMU_IRQ_STATUS, 0x000080A0)
REG32(GICP_PMU_IRQ_MASK, 0x000080A4)
REG32(GICP_PMU_IRQ_ENABLE, 0x000080A8)
REG32(GICP_PMU_IRQ_DISABLE, 0x000080AC)
REG32(GICP_PMU_IRQ_TRIGGER, 0x000080B0)
REG32(AFI_FS, 0x00009000)
REG32(LPD_CCI, 0x0000A000)
REG32(LPD_CCI_ADDRMAP, 0x0000A004)
REG32(LPD_CCI_QVNPREALLOC, 0x0000A008)
REG32(LPD_SMMU, 0x0000A020)
REG32(LPD_APU, 0x0000A040)

#define R_MAX (R_LPD_APU + 1)

typedef struct LPD_SLCR {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_isr;

    uint32_t regs[R_MAX];
    RegisterInfo regs_info[R_MAX];
} LPD_SLCR;

static void isr_update_irq(LPD_SLCR *s)
{
    bool pending = s->regs[R_ISR] & ~s->regs[R_IMR];
    qemu_set_irq(s->irq_isr, pending);
}

static void isr_postw(RegisterInfo *reg, uint64_t val64)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(reg->opaque);
    isr_update_irq(s);
}

static uint64_t ier_prew(RegisterInfo *reg, uint64_t val64)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IMR] &= ~val;
    isr_update_irq(s);
    return 0;
}

static uint64_t idr_prew(RegisterInfo *reg, uint64_t val64)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IMR] |= val;
    isr_update_irq(s);
    return 0;
}

static uint64_t itr_prew(RegisterInfo *reg, uint64_t val64)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(reg->opaque);
    uint32_t val = val64;

    s->regs[R_ISR] |= val;
    isr_update_irq(s);
    return 0;
}

static RegisterAccessInfo lpd_slcr_regs_info[] = {
    {   .name = "WPROT0",  .decode.addr = A_WPROT0,
        .reset = 0x1,
    },{ .name = "CTRL",  .decode.addr = A_CTRL,
    },{ .name = "ISR",  .decode.addr = A_ISR,
        .w1c = 0x1,
        .post_write = isr_postw,
    },{ .name = "IMR",  .decode.addr = A_IMR,
        .reset = 0x1,
        .ro = 0x1,
    },{ .name = "IER",  .decode.addr = A_IER,
        .pre_write = ier_prew,
    },{ .name = "IDR",  .decode.addr = A_IDR,
        .pre_write = idr_prew,
    },{ .name = "ITR",  .decode.addr = A_ITR,
        .pre_write = itr_prew,
    },{ .name = "ECO",  .decode.addr = A_ECO,
    },{ .name = "PERSISTENT0",  .decode.addr = A_PERSISTENT0,
    },{ .name = "PERSISTENT1",  .decode.addr = A_PERSISTENT1,
    },{ .name = "PERSISTENT2",  .decode.addr = A_PERSISTENT2,
    },{ .name = "PERSISTENT3",  .decode.addr = A_PERSISTENT3,
    },{ .name = "PERSISTENT4",  .decode.addr = A_PERSISTENT4,
    },{ .name = "PERSISTENT5",  .decode.addr = A_PERSISTENT5,
    },{ .name = "PERSISTENT6",  .decode.addr = A_PERSISTENT6,
    },{ .name = "PERSISTENT7",  .decode.addr = A_PERSISTENT7,
    },{ .name = "SAFETY_CHK0",  .decode.addr = A_SAFETY_CHK0,
    },{ .name = "SAFETY_CHK1",  .decode.addr = A_SAFETY_CHK1,
    },{ .name = "SAFETY_CHK2",  .decode.addr = A_SAFETY_CHK2,
    },{ .name = "SAFETY_CHK3",  .decode.addr = A_SAFETY_CHK3,
    },{ .name = "CSUPMU_WDT_CLK_SEL", .decode.addr = A_CSUPMU_WDT_CLK_SEL,
        .reset = 0,
        .ro = 0xFFFFFFFE,
    },{ .name = "ADMA_CFG", .decode.addr = A_ADMA_CFG,
        .reset = 0x00000028,
        .ro = 0xFFFFFFFF,
    },{ .name = "ADMA_RAM", .decode.addr = A_ADMA_RAM,
        .reset = 0x00003B3B,
        .ro = 0xFFFFFF00,
    },{ .name = "ERR_AIBAXI_ISR", .decode.addr = A_ERR_AIBAXI_ISR,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "ERR_AIBAXI_IMR", .decode.addr = A_ERR_AIBAXI_IMR,
        .reset = 0x1DCF000F,
        .ro = 0xFFFFFFFF,
    },{ .name = "ERR_AIBAXI_IER", .decode.addr = A_ERR_AIBAXI_IER,
        .reset = 0,
    },{ .name = "ERR_AIBAXI_IDR", .decode.addr = A_ERR_AIBAXI_IDR,
        .reset = 0,
    },{ .name = "ERR_AIBAPB_ISR", .decode.addr = A_ERR_AIBAPB_ISR,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "ERR_AIBAPB_IMR", .decode.addr = A_ERR_AIBAPB_IMR,
        .reset = 0x00000001,
        .ro = 0xFFFFFFFF,
    },{ .name = "ERR_AIBAPB_IER", .decode.addr = A_ERR_AIBAPB_IER,
        .reset = 0,
    },{ .name = "ERR_AIBAPB_IDR", .decode.addr = A_ERR_AIBAPB_IDR,
        .reset = 0,
    },{ .name = "ISO_AIBAXI_REQ", .decode.addr = A_ISO_AIBAXI_REQ,
        .reset = 0,
    },{ .name = "ISO_AIBAXI_TYPE", .decode.addr = A_ISO_AIBAXI_TYPE,
        .reset = 0x19CF000F,
    },{ .name = "ISO_AIBAXI_ACK", .decode.addr = A_ISO_AIBAXI_ACK,
        .reset = 0,
        .ro = 0xFFFFFFFF,
    },{ .name = "ISO_AIBAPB_REQ", .decode.addr = A_ISO_AIBAPB_REQ,
        .reset = 0,
    },{ .name = "ISO_AIBAPB_TYPE", .decode.addr = A_ISO_AIBAPB_TYPE,
        .reset = 0x00000001,
    },{ .name = "ISO_AIBAPB_ACK", .decode.addr = A_ISO_AIBAPB_ACK,
        .reset = 0,
        .ro = 0xFFFFFFFF,
    },{ .name = "ERR_ATB_ISR", .decode.addr = A_ERR_ATB_ISR,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "ERR_ATB_IMR", .decode.addr = A_ERR_ATB_IMR,
        .reset = 0x00000003,
        .ro = 0xFFFFFFFF,
    },{ .name = "ERR_ATB_IER", .decode.addr = A_ERR_ATB_IER,
        .reset = 0,
    },{ .name = "ERR_ATB_IDR", .decode.addr = A_ERR_ATB_IDR,
        .reset = 0,
    },{ .name = "ATB_CMD_STORE_EN", .decode.addr = A_ATB_CMD_STORE_EN,
        .reset = 0x00000003,
    },{ .name = "ATB_RESP_EN", .decode.addr = A_ATB_RESP_EN,
        .reset = 0,
    },{ .name = "ATB_RESP_TYPE", .decode.addr = A_ATB_RESP_TYPE,
        .reset = 0x00000003,
    },{ .name = "ATB_PRESCALE", .decode.addr = A_ATB_PRESCALE,
        .reset = 0x0000FFFF,
    },{ .name = "MUTEX0", .decode.addr = A_MUTEX0,
        .reset = 0,
    },{ .name = "MUTEX1", .decode.addr = A_MUTEX1,
        .reset = 0,
    },{ .name = "MUTEX2", .decode.addr = A_MUTEX2,
        .reset = 0,
    },{ .name = "MUTEX3", .decode.addr = A_MUTEX3,
        .reset = 0,
    },{ .name = "GICP0_IRQ_STATUS", .decode.addr = A_GICP0_IRQ_STATUS,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "GICP0_IRQ_MASK", .decode.addr = A_GICP0_IRQ_MASK,
        .reset = 0xFFFFFFFF,
        .ro = 0xFFFFFFFF,
    },{ .name = "GICP0_IRQ_ENABLE", .decode.addr = A_GICP0_IRQ_ENABLE,
        .reset = 0,
    },{ .name = "GICP0_IRQ_DISABLE", .decode.addr = A_GICP0_IRQ_DISABLE,
        .reset = 0,
    },{ .name = "GICP0_IRQ_TRIGGER", .decode.addr = A_GICP0_IRQ_TRIGGER,
        .reset = 0,
    },{ .name = "GICP1_IRQ_STATUS", .decode.addr = A_GICP1_IRQ_STATUS,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "GICP1_IRQ_MASK", .decode.addr = A_GICP1_IRQ_MASK,
        .reset = 0xFFFFFFFF,
        .ro = 0xFFFFFFFF,
    },{ .name = "GICP1_IRQ_ENABLE", .decode.addr = A_GICP1_IRQ_ENABLE,
        .reset = 0,
    },{ .name = "GICP1_IRQ_DISABLE", .decode.addr = A_GICP1_IRQ_DISABLE,
        .reset = 0,
    },{ .name = "GICP1_IRQ_TRIGGER", .decode.addr = A_GICP1_IRQ_TRIGGER,
        .reset = 0,
    },{ .name = "GICP2_IRQ_STATUS", .decode.addr = A_GICP2_IRQ_STATUS,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "GICP2_IRQ_MASK", .decode.addr = A_GICP2_IRQ_MASK,
        .reset = 0xFFFFFFFF,
        .ro = 0xFFFFFFFF,
    },{ .name = "GICP2_IRQ_ENABLE", .decode.addr = A_GICP2_IRQ_ENABLE,
        .reset = 0,
    },{ .name = "GICP2_IRQ_DISABLE", .decode.addr = A_GICP2_IRQ_DISABLE,
        .reset = 0,
    },{ .name = "GICP2_IRQ_TRIGGER", .decode.addr = A_GICP2_IRQ_TRIGGER,
        .reset = 0,
    },{ .name = "GICP3_IRQ_STATUS", .decode.addr = A_GICP3_IRQ_STATUS,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "GICP3_IRQ_MASK", .decode.addr = A_GICP3_IRQ_MASK,
        .reset = 0xFFFFFFFF,
        .ro = 0xFFFFFFFF,
    },{ .name = "GICP3_IRQ_ENABLE", .decode.addr = A_GICP3_IRQ_ENABLE,
        .reset = 0,
    },{ .name = "GICP3_IRQ_DISABLE", .decode.addr = A_GICP3_IRQ_DISABLE,
        .reset = 0,
    },{ .name = "GICP3_IRQ_TRIGGER", .decode.addr = A_GICP3_IRQ_TRIGGER,
        .reset = 0,
    },{ .name = "GICP4_IRQ_STATUS", .decode.addr = A_GICP4_IRQ_STATUS,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "GICP4_IRQ_MASK", .decode.addr = A_GICP4_IRQ_MASK,
        .reset = 0xFFFFFFFF,
        .ro = 0xFFFFFFFF,
    },{ .name = "GICP4_IRQ_ENABLE", .decode.addr = A_GICP4_IRQ_ENABLE,
        .reset = 0,
    },{ .name = "GICP4_IRQ_DISABLE", .decode.addr = A_GICP4_IRQ_DISABLE,
        .reset = 0,
    },{ .name = "GICP4_IRQ_TRIGGER", .decode.addr = A_GICP4_IRQ_TRIGGER,
        .reset = 0,
    },{ .name = "GICP_PMU_IRQ_STATUS", .decode.addr = A_GICP_PMU_IRQ_STATUS,
        .reset = 0,
        .w1c = 0xFFFFFFFF,
    },{ .name = "GICP_PMU_IRQ_MASK", .decode.addr = A_GICP_PMU_IRQ_MASK,
        .reset = 0x000000FF,
        .ro = 0xFFFFFFFF,
    },{ .name = "GICP_PMU_IRQ_ENABLE", .decode.addr = A_GICP_PMU_IRQ_ENABLE,
        .reset = 0,
    },{ .name = "GICP_PMU_IRQ_DISABLE", .decode.addr = A_GICP_PMU_IRQ_DISABLE,
        .reset = 0,
    },{ .name = "GICP_PMU_IRQ_TRIGGER", .decode.addr = A_GICP_PMU_IRQ_TRIGGER,
        .reset = 0,
    },{ .name = "AFI_FS", .decode.addr = A_AFI_FS,
        .reset = 0x00000200,
    },{ .name = "LPD_CCI", .decode.addr = A_LPD_CCI,
        .reset = 0x03801C07,
    },{ .name = "LPD_CCI_ADDRMAP", .decode.addr = A_LPD_CCI_ADDRMAP,
        .reset = 0x00C000FF,
    },{ .name = "LPD_CCI_QVNPREALLOC", .decode.addr = A_LPD_CCI_QVNPREALLOC,
        .reset = 0x00330330,
        .ro = 0x0000F00F,
    },{ .name = "LPD_SMMU", .decode.addr = A_LPD_SMMU,
        .reset = 0x0000003F,
    },{ .name = "LPD_APU", .decode.addr = A_LPD_APU,
        .reset = 0x00000001,
    },
};

static void lpd_slcr_reset(DeviceState *dev)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    isr_update_irq(s);
}

static uint64_t lpd_slcr_read(void *opaque, hwaddr addr, unsigned size)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(opaque);
    RegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        return 0;
    }
    return register_read(r);
}

static void lpd_slcr_write(void *opaque, hwaddr addr, uint64_t value,
                      unsigned size)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(opaque);
    RegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, value);
        return;
    }
    register_write(r, value, ~0);
}

static const MemoryRegionOps lpd_slcr_ops = {
    .read = lpd_slcr_read,
    .write = lpd_slcr_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void lpd_slcr_realize(DeviceState *dev, Error **errp)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(dev);
    const char *prefix = object_get_canonical_path(OBJECT(dev));
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(lpd_slcr_regs_info); ++i) {
        RegisterInfo *r = &s->regs_info[lpd_slcr_regs_info[i].decode.addr/4];

        *r = (RegisterInfo) {
            .data = (uint8_t *)&s->regs[
                    lpd_slcr_regs_info[i].decode.addr/4],
            .data_size = sizeof(uint32_t),
            .access = &lpd_slcr_regs_info[i],
            .debug = XILINX_LPD_SLCR_ERR_DEBUG,
            .prefix = prefix,
            .opaque = s,
        };
    }
}

static void lpd_slcr_init(Object *obj)
{
    LPD_SLCR *s = XILINX_LPD_SLCR(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &lpd_slcr_ops, s,
                          TYPE_XILINX_LPD_SLCR, R_MAX * 4);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_isr);
}

static const VMStateDescription vmstate_lpd_slcr = {
    .name = TYPE_XILINX_LPD_SLCR,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, LPD_SLCR, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void lpd_slcr_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = lpd_slcr_reset;
    dc->realize = lpd_slcr_realize;
    dc->vmsd = &vmstate_lpd_slcr;
}

static const TypeInfo lpd_slcr_info = {
    .name          = TYPE_XILINX_LPD_SLCR,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(LPD_SLCR),
    .class_init    = lpd_slcr_class_init,
    .instance_init = lpd_slcr_init,
};

static void lpd_slcr_register_types(void)
{
    type_register_static(&lpd_slcr_info);
}

type_init(lpd_slcr_register_types)
