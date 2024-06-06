#include "py/mphal.h"

void DEVEBOX_H750VB_board_early_init(void) {
    // set SPI and QSPI flashes CS pin high
    mp_hal_pin_output(pin_B6);
    mp_hal_pin_write(pin_B6, 1);

    mp_hal_pin_output(pin_B12);
    mp_hal_pin_write(pin_B12, 1);
}
