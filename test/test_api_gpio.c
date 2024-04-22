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
#define LED1_ON 0x01
#define LED2_ON 0x02
#define LED3_ON 0x04
#define LED1_OFF 0xFE  // 0b 1111 1110
#define LED2_OFF 0xFD  // 0b 1111 1101
#define LED3_OFF 0xFB  // 0b 1111 1011
#define MASK_LED1 0x01 // Usar con LED1_OFF o LED1_ON en TETS_ASSERT_BITS() 
#define MASK_LED2 0x02 // Usar con LED2_OFF o LED2_ON en TETS_ASSERT_BITS()
#define MASK_LED3 0x04 // Usar con LED3_OFF o LED3_ON en TETS_ASSERT_BITS()
#define EXPECTED_MASK_OFF 0x00 // Usar solo en "test_apagar_un_led(void)" como mascara
#define EXPECTED_MASK_ON_LED1 0x01 // Usar solo en "test_encender_un_led(void)" como mascara para LED1_ON
#define EXPECTED_MASK_ON_LED2 0x02 // Usar solo en "test_encender_un_led(void)" como mascara para LED2_ON
#define EXPECTED_MASK_ON_LED3 0x03 // Usar solo en "test_encender_un_led(void)" como mascara para LED3_ON
#define PORT_ADDRESS_GPIOB 0xFF


/* === Private data type declarations ==================================== */

/* === Private variable declarations ====================================== */
static uint16_t leds_virtuales;
extern uint16_t * Puerto_GPIO;
extern uint16_t * GPIOB;

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
 ** @brief Test2: verificar que la funcion del driver enciende el led correspondiente
 ** Debe encender un led de tres disponibles en la placa y solo ese led
 **/
void test_encender_un_led(void) {
    //Definir comportamiento esperado de la funcion HAL
    HAL_GPIO_WritePin_Expect(GPIOB, LD2, GPIO_PIN_SET);

    //Llamar a la funcion bajo prueba
    leds_virtuales |= LED2_ON;
    writeLedOn_GPIO(LD2);

    //Verificar que el LED1 se haya encendico correctamente
    TEST_ASSERT_BITS(MASK_LED2, EXPECTED_MASK_ON_LED2 ,leds_virtuales);
    //TEST_ASSERT_EQUAL_HEX16(LED1_ON, leds_virtuales);
//    led_turn_on(LED03);
    // El bit 2 está en alto
//    TEST_ASSERT_BIT_HIGH(LED03 - LED_OFFSET, leds_virtuales);
    // Todos los otros bits están en bajo
//    TEST_ASSERT_BITS_LOW(~(1 << (LED03 - LED_OFFSET)), leds_virtuales);
}

/** 
 ** @brief Test3: verificar que la funcion del driver apaga el led correspondiente
 ** Debe apagar un led de tres disponibles en la placa y solo ese led
 **/
void test_apagar_un_led(void) {
    //Definir comportamiento esperado de la funcion HAL
    HAL_GPIO_WritePin_Expect(GPIOB, LD1, GPIO_PIN_RESET);

    //Llamar a la funcion bajo prueba
    leds_virtuales &= LED1_OFF;
    writeLedOff_GPIO(LD1);

    //Verificar que unicamente el LED1 se haya apagado correctamente
    TEST_ASSERT_BITS(MASK_LED1, EXPECTED_MASK_OFF ,leds_virtuales);
}

/** 
 ** @brief Test4: Verificar que todos los leds encienden con una sola funcion del driver
 **/
void test_encender_todos_los_leds(void) {
    //Definir comportamiento esperado de la funcion HAL
    HAL_GPIO_WritePin_Expect(GPIOB, LD1, GPIO_PIN_SET);
    HAL_GPIO_WritePin_Expect(GPIOB, LD2, GPIO_PIN_SET);
    HAL_GPIO_WritePin_Expect(GPIOB, LD3, GPIO_PIN_SET);

    //Llamar a la funcion bajo prueba
    leds_virtuales = ALL_LEDS_ON;
    writeLedOnAll_GPIO();

    //Verificar que los 3 leds: LED1, LED2 y LED3 enciendan
    TEST_ASSERT_EQUAL_UINT16(ALL_LEDS_ON, leds_virtuales);
}

/** 
 ** @brief Test5: Verificar que todos los leds se apaguen con una sola funcion del driver
 **/
void test_apagar_todos_los_leds(void) {
    //Definir comportamiento esperado de la funcion HAL
    HAL_GPIO_WritePin_Expect(GPIOB, LD1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin_Expect(GPIOB, LD2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin_Expect(GPIOB, LD3, GPIO_PIN_RESET);

    //Llamar a la funcion bajo prueba
    leds_virtuales = ALL_LEDS_OFF;
    writeLedOffAll_GPIO();

    //Verificar que los 3 leds: LED1, LED2 y LED3 se apaguen
    TEST_ASSERT_EQUAL_UINT16(ALL_LEDS_OFF, leds_virtuales);
}

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