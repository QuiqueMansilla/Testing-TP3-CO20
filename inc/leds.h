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

#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Función de inicialización del puerto de bits a utilizar
 * @param puerto Dirección del puerto (Dirección física memo) con el que trabajaremos
 */
void leds_init(uint16_t *puerto);

/**
 * @brief Función de encendido de un bit del puerto configurado en "leds_init"
 * @param led Numero de bit con el que trabajaremos
 */
void led_turn_on(int led);

/**
 * @brief Función de apagado de un bit del puerto configurado en "leds_init"
 * @param led Numero de bit con el que trabajaremos
 */
void led_turn_off(int led);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */