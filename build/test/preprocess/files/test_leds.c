#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/leds.h"












static uint16_t leds_virtuales;

void setUp(void) {

    leds_init(&leds_virtuales);

}











void test_todos_los_leds_inician_apagados(void) {



    uint16_t leds_virtuales = 0xFF;

    leds_init(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_UINT16);

}











void test_prender_un_led(void) {

    led_turn_on(3);



    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (3 - 1))), (UNITY_INT)((UNITY_UINT)(-1)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(70));



    UnityAssertBits((UNITY_INT)((~(1 << (3 - 1)))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(72));

}











void test_apagar_un_led(void) {

    led_turn_on(3);

    led_turn_off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_UINT16);

}













void test_prender_y_apagar_varios_leds(void) {

    led_turn_on(5);

    led_turn_on(7);

    led_turn_on(5);

    led_turn_off(5);

    led_turn_off(9);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (7 -1))), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_UINT16);

}











void test_con_todos_leds_apagados_prender_uno_y_verificar_prendido(void) {

    leds_init(&leds_virtuales);

    led_turn_on(7);

    do {if ((led_get_status(7, &leds_virtuales))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(107)));}} while(0);

}
