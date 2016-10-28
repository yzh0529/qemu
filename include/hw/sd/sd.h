/*
 * SD Memory Card emulation.  Mostly correct for MMC too.
 *
 * Copyright (c) 2006 Andrzej Zaborowski  <balrog@zabor.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __hw_sd_h
#define __hw_sd_h		1

#include "hw/qdev.h"

#define OUT_OF_RANGE		(1 << 31)
#define ADDRESS_ERROR		(1 << 30)
#define BLOCK_LEN_ERROR		(1 << 29)
#define ERASE_SEQ_ERROR		(1 << 28)
#define ERASE_PARAM		(1 << 27)
#define WP_VIOLATION		(1 << 26)
#define CARD_IS_LOCKED		(1 << 25)
#define LOCK_UNLOCK_FAILED	(1 << 24)
#define COM_CRC_ERROR		(1 << 23)
#define ILLEGAL_COMMAND		(1 << 22)
#define CARD_ECC_FAILED		(1 << 21)
#define CC_ERROR		(1 << 20)
#define SD_ERROR		(1 << 19)
#define CID_CSD_OVERWRITE	(1 << 16)
#define WP_ERASE_SKIP		(1 << 15)
#define CARD_ECC_DISABLED	(1 << 14)
#define ERASE_RESET		(1 << 13)
#define CURRENT_STATE		(7 << 9)
#define READY_FOR_DATA		(1 << 8)
#define SWTICH_ERROR		(1 << 7)
#define APP_CMD			(1 << 5)
#define AKE_SEQ_ERROR		(1 << 3)
#define OCR_CCS_BITN        30

#define EXCSD_BUS_WIDTH_OFFSET 183
#define BUS_WIDTH_8_MASK    0x4
#define BUS_WIDTH_4_MASK    0x2

#define SD_TUNING_BLOCK_SIZE    64
#define MMC_TUNING_BLOCK_SIZE   128

typedef enum {
    sd_none = -1,
    sd_bc = 0,	/* broadcast -- no response */
    sd_bcr,	/* broadcast with response */
    sd_ac,	/* addressed -- no data transfer */
    sd_adtc,	/* addressed with data transfer */
} sd_cmd_type_t;

typedef struct {
    uint8_t cmd;
    uint32_t arg;
    uint8_t crc;
} SDRequest;

#define SD_VOLTAGE_33 33
#define SD_VOLTAGE_18 18

typedef struct SDState SDState;
typedef struct SDBus SDBus;

#define TYPE_SD_CARD "sd-card"
#define SD_CARD(obj) OBJECT_CHECK(SDState, (obj), TYPE_SD_CARD)
#define SD_CARD_CLASS(klass) \
    OBJECT_CLASS_CHECK(SDCardClass, (klass), TYPE_SD_CARD)
#define SD_CARD_GET_CLASS(obj) \
    OBJECT_GET_CLASS(SDCardClass, (obj), TYPE_SD_CARD)

typedef struct {
    /*< private >*/
    DeviceClass parent_class;
    /*< public >*/

    uint8_t (*get_dat_lines)(SDState *sd);
    bool (*get_cmd_line)(SDState *sd);
    void (*set_voltage)(SDState *sd, int v);
    int (*do_command)(SDState *sd, SDRequest *req, uint8_t *response);
    void (*write_data)(SDState *sd, uint8_t value);
    uint8_t (*read_data)(SDState *sd);
    bool (*data_ready)(SDState *sd);
    void (*enable)(SDState *sd, bool enable);
    bool (*get_inserted)(SDState *sd);
    bool (*get_readonly)(SDState *sd);
} SDCardClass;

#define TYPE_SD_BUS "sd-bus"
#define SD_BUS(obj) OBJECT_CHECK(SDBus, (obj), TYPE_SD_BUS)
#define SD_BUS_CLASS(klass) OBJECT_CLASS_CHECK(SDBusClass, (klass), TYPE_SD_BUS)
#define SD_BUS_GET_CLASS(obj) OBJECT_GET_CLASS(SDBusClass, (obj), TYPE_SD_BUS)

struct SDBus {
    BusState qbus;
};

typedef struct {
    /*< private >*/
    BusClass parent_class;
    /*< public >*/

    /* These methods are called by the SD device to notify the controller
     * when the card insertion or readonly status changes
     */
    void (*set_inserted)(DeviceState *dev, bool inserted);
    void (*set_readonly)(DeviceState *dev, bool readonly);
} SDBusClass;

/* Legacy functions to be used only by non-qdevified callers */
SDState *sd_init(BlockBackend *bs, bool is_spi);
SDState *mmc_init(BlockBackend *bs);

int sd_do_command(SDState *sd, SDRequest *req,
                  uint8_t *response);
void sd_write_data(SDState *sd, uint8_t value);
uint8_t sd_read_data(SDState *sd);
void sd_set_cb(SDState *sd, qemu_irq readonly, qemu_irq insert);
bool sd_data_ready(SDState *sd);
/* sd_enable should not be used -- it is only used on the nseries boards,
 * where it is part of a broken implementation of the MMC card slot switch
 * (there should be two card slots which are multiplexed to a single MMC
 * controller, but instead we model it with one card and controller and
 * disable the card when the second slot is selected, so it looks like the
 * second slot is always empty).
 */
void sd_enable(SDState *sd, bool enable);
uint8_t sd_get_dat_lines(SDState *sd);
bool sd_get_cmd_line(SDState *sd);
void sd_set_voltage(SDState *sd, int v);

/* Functions to be used by qdevified callers (working via
 * an SDBus rather than directly with SDState)
 */
uint8_t sdbus_get_dat_lines(SDBus *sdbus);
bool sdbus_get_cmd_line(SDBus *sdbus);
void sdbus_set_voltage(SDBus *sdbus, int v);
int sdbus_do_command(SDBus *sd, SDRequest *req, uint8_t *response);
void sdbus_write_data(SDBus *sd, uint8_t value);
uint8_t sdbus_read_data(SDBus *sd);
bool sdbus_data_ready(SDBus *sd);
bool sdbus_get_inserted(SDBus *sd);
bool sdbus_get_readonly(SDBus *sd);

/* Functions to be used by SD devices to report back to qdevified controllers */
void sdbus_set_inserted(SDBus *sd, bool inserted);
void sdbus_set_readonly(SDBus *sd, bool inserted);

#endif	/* __hw_sd_h */
