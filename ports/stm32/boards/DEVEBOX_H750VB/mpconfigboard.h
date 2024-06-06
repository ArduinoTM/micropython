/* This file is part of the MicroPython project, http://micropython.org/
 * MIT License; Copyright (c) 2021 Damien P. George
 */

// STM32H743VIT6 H7 core board by VCC-GND Studio
// http://vcc-gnd.com/
// https://item.taobao.com/item.htm?ft=t&id=614466740679
// https://www.aliexpress.com/wholesale?SearchText=STM32H743VIT6

#define MICROPY_HW_BOARD_NAME       "DEVEBOX STM32H750VB"
#define MICROPY_HW_MCU_NAME         "STM32H750VB"
#define MICROPY_HW_FLASH_FS_LABEL   "DEVEBOXH7"

// 1 = use internal flash (1 MByte)
// 0 = use onboard SPI flash (512 KByte) Winbond W25X40
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)

#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_FATFS_EXFAT         (1)

#define MICROPY_BOARD_EARLY_INIT    DEVEBOX_H750VB_board_early_init
void DEVEBOX_H750VB_board_early_init(void);

// The board has an 25MHz HSE, the following gives 480MHz CPU speed
#define MICROPY_HW_CLK_PLLM         (5)
#define MICROPY_HW_CLK_PLLN         (192)
#define MICROPY_HW_CLK_PLLP         (2)
#define MICROPY_HW_CLK_PLLQ         (4)
#define MICROPY_HW_CLK_PLLR         (2)
#define MICROPY_HW_CLK_PLLVCI       (RCC_PLL1VCIRANGE_1)
#define MICROPY_HW_CLK_PLLVCO       (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC      (0)


// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M        (5)
#define MICROPY_HW_CLK_PLL3N        (48)
#define MICROPY_HW_CLK_PLL3P        (2)
#define MICROPY_HW_CLK_PLL3Q        (5)
#define MICROPY_HW_CLK_PLL3R        (2)
#define MICROPY_HW_CLK_PLL3VCI      (RCC_PLL3VCIRANGE_1)
#define MICROPY_HW_CLK_PLL3VCO      (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC     (0)

// 5 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_5

// UART config
#define MICROPY_HW_UART1_TX         (pin_A9)
#define MICROPY_HW_UART1_RX         (pin_A10)
#define MICROPY_HW_UART2_TX         (pin_D5)
#define MICROPY_HW_UART2_RX         (pin_D6)
#define MICROPY_HW_UART2_RTS        (pin_D4)
#define MICROPY_HW_UART2_CTS        (pin_D3)
#define MICROPY_HW_UART3_TX         (pin_D8)
#define MICROPY_HW_UART3_RX         (pin_D9)
#define MICROPY_HW_UART5_TX         (pin_B6)
#define MICROPY_HW_UART5_RX         (pin_B12)
#define MICROPY_HW_UART6_TX         (pin_C6)
#define MICROPY_HW_UART6_RX         (pin_C7)
#define MICROPY_HW_UART8_TX         (pin_E1)
#define MICROPY_HW_UART8_RX         (pin_E0)

// I2C buses
#define MICROPY_HW_I2C1_SCL         (pin_B6)
#define MICROPY_HW_I2C1_SDA         (pin_B7)
#define MICROPY_HW_I2C2_SCL         (pin_B10)
#define MICROPY_HW_I2C2_SDA         (pin_B11)
#define MICROPY_HW_I2C3_SCL         (pin_A8)
#define MICROPY_HW_I2C3_SDA         (pin_C9)

// SPI buses
#define MICROPY_HW_SPI1_NSS         (pin_A4)
#define MICROPY_HW_SPI1_SCK         (pin_A5)
#define MICROPY_HW_SPI1_MISO        (pin_A6)
#define MICROPY_HW_SPI1_MOSI        (pin_A7)
#define MICROPY_HW_SPI2_NSS         (pin_B12)
#define MICROPY_HW_SPI2_SCK         (pin_B13)
#define MICROPY_HW_SPI2_MISO        (pin_B14)
#define MICROPY_HW_SPI2_MOSI        (pin_B15)

// USRSW is pulled high. Pressing the button makes the input go low.
#define MICROPY_HW_USRSW_PIN        (pin_E3)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pin_A1)   // yello
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// If using onboard SPI flash
#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE

// W25X40 SPI Flash = 64 Mbit (8 MByte)
// #define MICROPY_HW_SPIFLASH_SIZE_BITS (64 * 1024 * 1024)
// #define MICROPY_HW_SPIFLASH_CS      (pin_B6)
// #define MICROPY_HW_SPIFLASH_SCK     (pin_B2)
// #define MICROPY_HW_SPIFLASH_MISO    (pin_D11)
// #define MICROPY_HW_SPIFLASH_MOSI    (pin_D12)
#define MICROPY_HW_SPIFLASH_SIZE_BITS   (64 * 1024 * 1024)
#define MICROPY_HW_SPIFLASH_CS         (pin_B6)
#define MICROPY_HW_SPIFLASH_SCK        (pin_B2)
#define MICROPY_HW_SPIFLASH_IO0        (pin_D11)
#define MICROPY_HW_SPIFLASH_IO1        (pin_D12)
#define MICROPY_HW_SPIFLASH_IO2        (pin_E2)
#define MICROPY_HW_SPIFLASH_IO3        (pin_D13)

extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_BDEV_SPIFLASH    (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol

#endif

// USB config
#define MICROPY_HW_USB_FS           (1)
//#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
//#define MICROPY_HW_USB_OTG_ID_PIN   (pin_A10)

// FDCAN bus
#define MICROPY_HW_CAN1_NAME        "FDCAN1"
#define MICROPY_HW_CAN1_TX          (pin_D1)
#define MICROPY_HW_CAN1_RX          (pin_D0)

// SD card detect switch
//#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_A8)
//#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
//#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)
