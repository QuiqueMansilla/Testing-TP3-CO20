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

/** @file test_api_gpio.c
 ** @brief Funciones de prueba para la capa de abstracción para gestión de puertos digitales de leds.c
 **/

/* === Headers files inclusions ===================================== */
#include "api_gpio.h"
#include "unity.h"
#include "mock_hal_gpio.h"

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
static uint16_t leds_virtuales;

/* === Private function declarations ====================================== */

/* === Public variable definitions ===========================================*/

/* === Private variable definitions ==========================================*/

/* === Private function implementation ====================================== */

/** 
 ** @brief Inicializo el driver, MX_GPIO_init(&leds_virtuales) va en todos los tests 
 **/
void setUp(void) {
    init_GPIO(&leds_virtuales);
}

/** 
 ** @brief Test1: Al iniciar el controlador los Leds deben quedar todos apagados 
 ** los bits en 0 sin importar el estado anterior.
 **/
void test_todos_los_leds_inician_apagados(void) {
    uint16_t leds_virtuales = PORT_ADDRESS_GPIOB;
    init_GPIO(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(ALL_LEDS_OFF, leds_virtuales);
}

/** 
 ** @brief Prueba2: Con todos los Leds apagados prender el Led 3 y verificar que
 ** efectivamente el bit 2 se pone en 1 y el resto permanece en cero
 **/
//void test_prender_un_led(void) {
//    led_turn_on(LED03);
    // El bit 2 está en alto
//    TEST_ASSERT_BIT_HIGH(LED03 - LED_OFFSET, leds_virtuales);
    // Todos los otros bits están en bajo
//    TEST_ASSERT_BITS_LOW(~(1 << (LED03 - LED_OFFSET)), leds_virtuales);
//}

/** 
 ** @brief Prueba3: Apagar un Led prendido y ver que efectivamente
 ** se apaga y que el resto no cambia
 **/
//void test_apagar_un_led(void) {
//    led_turn_on(LED03);
//    led_turn_off(LED03);
//    TEST_ASSERT_EQUAL_UINT16(ALL_LEDS_OFF, leds_virtuales);
//}

/** 
 ** @brief Prueba4: combina 4_ Apagar todos los leds que ya estan prendidos
 ** y 5_ Prender Leds ya estan prendidos antes.
 ** En esta prueba enciende 3 leds y apaga 2
 **/
//void test_prender_y_apagar_varios_leds(void) {
//    led_turn_on(LED05);
//    led_turn_on(LED07);
//    led_turn_on(LED05);
//    led_turn_off(LED05);
//    led_turn_off(LED09);

//    TEST_ASSERT_EQUAL_UINT16(BIT_HIGH << (LED07-LED_OFFSET), leds_virtuales);
//}

/** 
 ** @brief Prueba5: Con todos los Leds apagados prender un Led y verificar
 ** que al consultar el estado del mismo, me informa que está prendido
 **/
//void test_con_todos_leds_apagados_prender_uno_y_verificar_prendido(void) {
//    leds_init(&leds_virtuales);
//    led_turn_on(LED07);
//    TEST_ASSERT_TRUE(led_get_status(LED07, &leds_virtuales));
//}

/** 
 ** @brief Prueba6: Con todos los Leds apagados prender todos los leds y verificar
 ** que efectivamente se prendieron todos los leds
 **/
//void test_con_todos_los_leds_apagados_encender_todos_los_leds(void) {
//    leds_init(&leds_virtuales);
//    led_turn_on_all(&leds_virtuales);
//    TEST_ASSERT_EQUAL_UINT16(ALL_LEDS_ON, leds_virtuales);
//}

/** 
 ** @brief Prueba7: Con todos los Leds encendidos apagar todos los leds y verificar
 ** que efectivamente se apagaron todos los leds
 **/
//void test_con_todos_los_leds_encendidos_apagar_todos_los_leds(void) {
//    led_turn_on_all(&leds_virtuales);
//    led_turn_off_all(&leds_virtuales);
//    TEST_ASSERT_EQUAL_UINT16(ALL_LEDS_OFF, leds_virtuales);
//}