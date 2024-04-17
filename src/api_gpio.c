/********************************************************************
Copyright (c) 2024 Rubén Darío Mansilla <quiquemansilla1@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
***********************************************************************/

/** @file api_gpio.c
 ** @brief capa de abstracción para gestión de puertos GPIO con 3 leds on
 **        board para placa STM32-NucleoF4xx conectados al puerto GPIO GPIOB
 **/

/* === Headers files inclusions =========================================== */
#include "api_gpio.h"
#include "hal_gpio.h"

/* === Macros definitions =========================================== */
#define LD1 1
#define LD2 2
#define LD3 3
#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0
#define LED_OFFSET 1
#define ALL_LEDS_OFF 0x00
#define ALL_LEDS_ON 0x03
#define PORT_ADDRESS_GPIOB 0xFF

/* === Private data type declarations ==================================== */

/* === Private variable declarations ====================================== */

/* === Private function declarations ====================================== */

/* === Public variable definitions ===========================================*/

/* === Private variable definitions ==========================================*/
static uint16_t * Puerto_GPIO;
static uint16_t * GPIOB;

/* === Private function implementation ====================================== */
static uint16_t led_to_mask(int LDx) {
    return (GPIO_PIN_SET << (LDx - LED_OFFSET));
}

void init_GPIO(uint16_t *GPIOB) {
    Puerto_GPIO = GPIOB;
    *Puerto_GPIO = ALL_LEDS_OFF;
}

void writeLedOn_GPIO(int LDx) {
    
    HAL_GPIO_WritePin(GPIOB, LDx, GPIO_PIN_SET);
    //*Puerto_GPIO |= led_to_mask(Ledx);
}

void writeLedOff_GPIO(int LDx) {
    
    HAL_GPIO_WritePin(GPIOB, LDx, GPIO_PIN_RESET);
    //*Puerto_GPIO &= ~led_to_mask(Ledx);
}

bool toggleLed_GPIO(int LDx) {
    
    HAL_GPIO_TogglePin(GPIOB, LDx);
    
}

void writeLedOnAll_GPIO(void) {
    
    HAL_GPIO_WritePin(GPIOB, LD1|LD2|LD3, GPIO_PIN_SET);
    //Puerto_GPIO = GPIOB;
    //*Puerto_GPIO = ALL_LEDS_ON;
}

void writeLedOffAll_GPIO(void) {
    
    HAL_GPIO_WritePin(GPIOB, LD1|LD2|LD3, GPIO_PIN_RESET);
    //Puerto_GPIO = GPIOB;
    //*Puerto_GPIO = ALL_LEDS_OFF;
}
/* === End of documentation =========================================== */