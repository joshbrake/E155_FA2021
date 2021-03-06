// STM32F401RE_SPI.h
// Header for SPI functions

#ifndef STM32F4_SPI_H
#define STM32F4_SPI_H

#include <stdint.h> // Include stdint header

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define SPI1_BASE (0x40013000UL)

///////////////////////////////////////////////////////////////////////////////
// Bitfield structs
///////////////////////////////////////////////////////////////////////////////

typedef struct {
  volatile uint32_t CPHA        : 1;
  volatile uint32_t CPOL        : 1;
  volatile uint32_t MSTR        : 1;
  volatile uint32_t BR          : 3;
  volatile uint32_t SPE         : 1;
  volatile uint32_t LSBFIRST    : 1;
  volatile uint32_t SSI         : 1;
  volatile uint32_t SSM         : 1;
  volatile uint32_t RXONLY      : 1;
  volatile uint32_t DFF         : 1;
  volatile uint32_t CRCNEXT     : 1;
  volatile uint32_t CRCEN       : 1;
  volatile uint32_t BIDIOE      : 1;
  volatile uint32_t BIDIMODE    : 1;
  volatile uint32_t             : 16;
} SPI_CR1_bits;

typedef struct {
  volatile uint32_t RXDMAEN     : 1;
  volatile uint32_t TXDMAEN     : 1;
  volatile uint32_t SSOE        : 1;
  volatile uint32_t             : 1;
  volatile uint32_t FRF         : 1;
  volatile uint32_t ERRIE       : 1;
  volatile uint32_t RXNEIE      : 1;
  volatile uint32_t TXEIE       : 1;
  volatile uint32_t             : 24;
} SPI_CR2_bits;

typedef struct {
  volatile uint32_t RXNE        : 1;
  volatile uint32_t TXE         : 1;
  volatile uint32_t CHSIDE      : 1;
  volatile uint32_t UDR         : 1;
  volatile uint32_t CRCERR      : 1;
  volatile uint32_t MODF        : 1;
  volatile uint32_t OVR         : 1;
  volatile uint32_t BSY         : 1;
  volatile uint32_t FRE         : 1;
  volatile uint32_t             : 23;
} SPI_SR_bits;

typedef struct {
  volatile uint32_t DR  : 16;
  volatile uint32_t     : 16;
} SPI_DR_bits;


typedef struct {
  volatile SPI_CR1_bits CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  volatile SPI_CR2_bits CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
  volatile SPI_SR_bits SR;         /*!< SPI status register,                                Address offset: 0x08 */
  volatile SPI_DR_bits DR;         /*!< SPI data register,                                  Address offset: 0x0C */
  volatile uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  volatile uint32_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  volatile uint32_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  volatile uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  volatile uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;

// Pointers to GPIO-sized chunks of memory for each peripheral
#define SPI1 ((SPI_TypeDef *) SPI1_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

/* Enables the SPI peripheral and intializes its clock speed (baud rate), polarity, and phase. */
void spiInit(int clkdivide, int cpol, int cpha);

/* Transmits a character (1 byte) over SPI and returns the received character.
 *    -- send: the character to send over SPI
 *    -- return: the character received over SPI */
uint8_t spiSendReceive(uint8_t send);

/* Transmits a short (2 bytes) over SPI and returns the received short.
 *    -- send: the short to send over SPI
 *    -- return: the short received over SPI */
uint16_t spiSendReceive16(uint16_t send);

#endif