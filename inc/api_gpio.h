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
#ifndef API_GPIO_H
#define API_GPIO_H

/** @file api_gpio.h
 ** @brief Definición de funciones de capa de abstracción para gestión de puertos GPIO 
 **        con 3 leds on board para placa STM32-NucleoF4xx
 **/

/* === Headers files inclusions ===================================== */
#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions ===================================== */

/* === Public data type declarations ===================================== */

/* === Public variable declarations ===================================== */

/* === Public function declarations ===================================== */
/**
 * @brief Función de inicialización del puerto GPIO a utilizar que reemplaza a la
 *        función MX_GPIO_Init() del driver original ya que usa elementos de la HAL 
 * @param GPIOB Dirección del puerto B del GPIO con el que trabajamos
 */
void init_GPIO(uint16_t *GPIOB);

/**
 * @brief Función de encendido de un bit del puerto GPIO configurado en "init_GPIO()"
 * @param LDx Numero de bit (led) con el que trabajamos
 */
void writeLedOn_GPIO(int LDx);

/**
 * @brief Función de apagado de un bit del puerto GPIO configurado en "init_GPIO()"
 * @param LDx Numero de bit (led) con el que trabajaremos
 */
void writeLedOff_GPIO(int LDx);

/**
 * @brief Función que hace un toggle sobre el led (bit) que se pasa como parámetro
 * @param LDx Numero de bit (led) con el que trabajaremos
 */
bool toggleLed_GPIO(int LDx);

/**
 * @brief Función que prende los 3 leds de la placa del puerto GPIO configurado
 * @param GPIOB Dirección del puerto B del GPIO con el que trabajamos
 */
void writeLedOnAll_GPIO(void);

/**
 * @brief Función que apaga los 3 leds de la placa del puerto configurado
 * @param GPIOB Dirección del puerto B del GPIO con el que trabajamos
 */
void writeLedOffAll_GPIO(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* API_GPIO_H */