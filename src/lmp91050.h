//
// Created by ali-k on 25.07.2023.
//

#ifndef TUBITAK_LMP91050_LMP91050_H
#define TUBITAK_LMP91050_LMP91050_H

#include "SPI.h"

#define LMP_SPI_MODE            arduino::SPI_MODE0
#define LMP_SPI_FREQ            10000000

#define LMP91050_DEV_CONFIG_REG                         (0x0)                  // Device Configuration
#define LMP91050_DAC_CONFIG_REG                         (0x1)                  // DAC Configuration
#define LMP91050_SDIO_MODE_ENABLE_REG                   (0xF)                  // SDIO Mode Enable

#define LMP91050_RW_BIT                                 (0x80)                  // Read Write Bit
#define LMP91050_SDIO_SEQ_BYTE1                         (0xFE)                  // Byte1 to write to enter SDIO Mode
#define LMP91050_SDIO_SEQ_BYTE2                         (0xED)                  // Byte2 to write to enter SDIO Mode

// PGA1 ON, PGA2 ON, external filter, 1.15V, gain2 = 4, gain1 = 250 (01110000)
#define LMP_CONFIG_DEFAULT      0x70

class lmp91050 {
private:
    SPIClass * _spi{};
    uint8_t _cs{};
    void writeRegister(uint8_t addr, uint8_t value);
    uint8_t readRegister(uint8_t addr) const;
public:
    lmp91050();
    void begin(SPIClass *userSPI,uint8_t userCS);
    void modeSDIO(bool state);
    void writeDevConf(uint8_t conf);
    uint8_t readDevConf();
    void writeDAC(uint8_t value);
    uint8_t readDAC();
};


#endif //TUBITAK_LMP91050_LMP91050_H
