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
#ifndef HAL_GPIO_H
#define HAL_GPIO_H

/** @file hal_gpio.h
 ** @brief Definición de funciones que reemplazará Cmock para el test unitario
 **/

#include "stdint.h"

//uint16_t PORT_GPIOB;
//int LEDx;
//int GPIO_PIN_STATUS;

/* ========= Funciones destinadas a ser remmplazadas con mock ==================*/
/** 
 ** @brief MX_GPIO_Init() usa datos definidos en la HAL de la placa por lo que la 
 **        evitaremos en el testing unitario y usaremos otra funcion "init_GPIO()" 
 **/
void MX_GPIO_Init(void);

void HAL_GPIO_WritePin(uint16_t PORT_GPIOB, int LEDx, int GPIO_PIN_STATUS);

void HAL_GPIO_TogglePin(uint16_t PORT_GPIOB, int LEDx);

#endif //HAL_GPIO_H