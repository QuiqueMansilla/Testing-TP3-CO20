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

/** @file test_leds.c
 ** @brief Funciones de prueba para la capa de abstracción para gestión de puertos digitales de leds.c
 **/

#include "leds.h"
#include "unity.h"

static uint16_t leds_virtuales;

static const int LED = 3;
//static const int ALL_LEDS_OFF = 0x00;

void setUp(void) {
    leds_init(&leds_virtuales); // inicializo el driver, esta linea va en todas la pruebas
}

/** 
 ** @brief Prueba1: Al iniciar el controlador los Leds deben quedar todos apagados 
 ** los bits en 0 sin importar el estado anterior.
 **/
void test_todos_los_leds_inician_apagados(void) {
    //TEST_FAIL_MESSAGE("Arrancamos");
    uint16_t leds_virtuales = 0xFF; // direccion del puerto
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0X00, leds_virtuales);
}

/** 
 ** @brief Prueba2: Con todos los Leds apagados prender el Led 3 y verificar que
 ** efectivamente el bit 2 se pone en 1 y el resto permanece en cero
 **/
void test_prender_un_led(void) {
    led_turn_on(LED);

    // El bit 2 está en alto
    TEST_ASSERT_BIT_HIGH(LED - 1, leds_virtuales);
    // Todos los otros bits están en bajo
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

/** 
 ** @brief Prueba3: Apagar un Led prendido y ver que efectivamente
 ** se apaga y que el resto no cambia
 **/
void test_apagar_un_led(void) {
    led_turn_on(LED);
    led_turn_off(LED);

    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/** 
 ** @brief Prueba4_y_5: 4_ Apagar todos los leds que ya estan prendidos
 ** 5_ Prender Leds ya estan prendidos antes
 **/
void test_prender_y_apagar_varios_leds(void) {
    led_turn_on(5);
    led_turn_on(7);
    led_turn_on(5);
    led_turn_off(5);
    led_turn_off(9);

    TEST_ASSERT_EQUAL_UINT16(1 << (7-1), leds_virtuales);
}