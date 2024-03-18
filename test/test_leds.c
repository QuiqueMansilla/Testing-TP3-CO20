/*
2 Con todos los Leds apagados prender el Led 3 y verificar que efectivamente el bit 3 se pone en 1 y el resto esta en cero
3 Apagar un Led prendido y ver que efectivamente se apaga y que el resto no cambia
4 Con todos los Leds apagados prender un Led y verificar que al consultar el estado del mismo, me informa que está prendido
5 Prender todos los Leds que estan apagados antes de la operacion
6 Apagar todos los leds que ya estan prendidos
7 Prender Leds ya estan prendidos antes
8 Apagar Leds que ya estan apagados 
9 Comprobar valores prohibidos
10 Comprobar los valores de limite (--> Comprobar valores de borde (Antes y despues de una comparacion))
*/
#include "leds.h"
#include "unity.h"

// Al iniciar el c ontrolador los Leds deben quedar todos apagados 
// los bits en 0 sin importar el estado anterior.
void test_todos_los_leds_inician_apagados(void) {
    //TEST_FAIL_MESSAGE("Arrancamos");
    uint16_t leds_virtuales = 0xFF; // direccion del puerto
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0X00, leds_virtuales);
}
