#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/leds.h"






void test_todos_los_leds_inician_apagados(void) {



    uint16_t leds_virtuales = 0xFF;

    leds_init(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0X00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_UINT16);

}
