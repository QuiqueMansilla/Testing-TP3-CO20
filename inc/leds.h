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
#ifndef LEDS_H
#define LEDS_H

/** @file leds.h
 ** @brief Definición de funciones de capa de abstracción para gestión de puertos digitales de leds
 **/

/* === Headers files inclusions ===================================== */
#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions ===================================== */
#define LED01 1
#define LED02 2
#define LED03 3
#define LED04 4
#define LED05 5
#define LED06 6
#define LED07 7
#define LED08 8
#define LED09 9
#define LED10 10
#define LED11 11
#define LED12 12
#define LED13 13
#define LED14 14
#define LED15 15
#define LED16 16
#define BIT_HIGH 1
#define LED_OFFSET 1
#define ALL_LEDS_OFF 0x00
#define ALL_LEDS_ON 0xFF
#define PORT_ADDRESS 0xFF

/* === Public data type declarations ===================================== */

/* === Public variable declarations ===================================== */

/* === Public function declarations ===================================== */
/**
 * @brief Función de inicialización del puerto de bits a utilizar
 * @param puerto Dirección del puerto (Dirección física memo) con el que trabajaremos
 */
void leds_init(uint16_t *puerto);

/**
 * @brief Función de encendido de un bit del puerto configurado en "leds_init"
 * @param led Numero de bit (led) con el que trabajamos
 */
void led_turn_on(int led);

/**
 * @brief Función de apagado de un bit del puerto configurado en "leds_init"
 * @param led Numero de bit (led) con el que trabajaremos
 */
void led_turn_off(int led);

/**
 * @brief Función que consulta y devuelve el estado de un led (bit)
 * @param led Numero de bit (led) con el que trabajaremos
 */
bool led_get_status(int led, uint16_t *puerto);

/**
 * @brief Función que prende todos los leds del puerto configurado
 * @param puerto Dirección del puerto (Dirección física memo) con el que trabajamos
 */
void led_turn_on_all(uint16_t *puerto);

/**
 * @brief Función que apaga todos los leds del puerto configurado
 * @param puerto Dirección del puerto (Dirección física memo) con el que trabajamos
 */
void led_turn_off_all(uint16_t *puerto);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */