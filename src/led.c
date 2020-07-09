/**************************************************************************************************/
/**
 * \brief  LEDs Libraries
 *
 * Lib dependencies: N/A
 */
/**************************************************************************************************/

#include "led.h"

#include "lpc23xx.h"

bool _global_led__initialized = 0;
pucrsdevboard__pin_description_t _global_led_description[LED_LEN];

/**************************************************************************************************/

void led__init()
{
    if(_global_led__initialized) {
        return;
    }

    _global_led_description[LED_0].fiodir = &(FIO4DIR);
    _global_led_description[LED_0].fiopin = &(FIO4PIN);
    _global_led_description[LED_0].pinsel = &(PINSEL8);
    _global_led_description[LED_0].bit_offset = 0;
    _global_led_description[LED_0].pinsel_offset = 0;

    _global_led_description[LED_1].fiodir = &(FIO4DIR);
    _global_led_description[LED_1].fiopin = &(FIO4PIN);
    _global_led_description[LED_1].pinsel = &(PINSEL8);
    _global_led_description[LED_1].bit_offset = 1;
    _global_led_description[LED_1].pinsel_offset = 2;

    _global_led_description[LED_2].fiodir = &(FIO4DIR);
    _global_led_description[LED_2].fiopin = &(FIO4PIN);
    _global_led_description[LED_2].pinsel = &(PINSEL8);
    _global_led_description[LED_2].bit_offset = 2;
    _global_led_description[LED_2].pinsel_offset = 4;

    _global_led_description[LED_3].fiodir = &(FIO4DIR);
    _global_led_description[LED_3].fiopin = &(FIO4PIN);
    _global_led_description[LED_3].pinsel = &(PINSEL8);
    _global_led_description[LED_3].bit_offset = 3;
    _global_led_description[LED_3].pinsel_offset = 6;

    _global_led_description[LED_4].fiodir = &(FIO4DIR);
    _global_led_description[LED_4].fiopin = &(FIO4PIN);
    _global_led_description[LED_4].pinsel = &(PINSEL8);
    _global_led_description[LED_4].bit_offset = 4;
    _global_led_description[LED_4].pinsel_offset = 8;

    _global_led_description[LED_5].fiodir = &(FIO4DIR);
    _global_led_description[LED_5].fiopin = &(FIO4PIN);
    _global_led_description[LED_5].pinsel = &(PINSEL8);
    _global_led_description[LED_5].bit_offset = 5;
    _global_led_description[LED_5].pinsel_offset = 10;

    _global_led_description[LED_6].fiodir = &(FIO4DIR);
    _global_led_description[LED_6].fiopin = &(FIO4PIN);
    _global_led_description[LED_6].pinsel = &(PINSEL8);
    _global_led_description[LED_6].bit_offset = 6;
    _global_led_description[LED_6].pinsel_offset = 12;

    _global_led_description[LED_7].fiodir = &(FIO4DIR);
    _global_led_description[LED_7].fiopin = &(FIO4PIN);
    _global_led_description[LED_7].pinsel = &(PINSEL8);
    _global_led_description[LED_7].bit_offset = 7;
    _global_led_description[LED_7].pinsel_offset = 14;

    // Configure LEDs pins
    for (int i = 0; i < LED_LEN; i++) {
        // Set PINSEL to GPIO (00)
        *(_global_led_description[i].pinsel) &= ~(1 << _global_led_description[i].pinsel_offset);
        *(_global_led_description[i].pinsel)
                &= ~(1 << (_global_led_description[i].pinsel_offset + 1));

        // Set direction to out (1)
        *(_global_led_description[i].fiodir) |= (1 << _global_led_description[i].bit_offset);

        // Turn the led off
        *(_global_led_description[i].fiopin) |= (1 << _global_led_description[i].bit_offset);
    }

    // LED_0 is shorted with P3.26, so lets configure is manually
    PINSEL7 &= ~(1 << 20);
    PINSEL7 &= ~(1 << 21);
    FIO3DIR |= 1 << 26;
    FIO3PIN |= 1 << 26;

    _global_led__initialized = 1;
}

pucrsdevboard__error_t led__set(led_id_t led_id, bool on)
{
    // If not initialized yet, initialize it!
    if(!_global_led__initialized) {
        led__init();
    }

    // Skip on invalid LED
    if (led_id == LED_LEN) {
        return PUCRSDEVBOARD__INVALID_ARG_ERR;
    }

    // Set LED
    if (on) {
        *(_global_led_description[led_id].fiopin)
                &= ~(1 << _global_led_description[led_id].bit_offset);

        // LED_0 is shorted with P3.26, so lets configure it too
        if (led_id == LED_0) {
            FIO3PIN &= ~(1 << 26);
        }
    } else {
        *(_global_led_description[led_id].fiopin)
                |= (1 << _global_led_description[led_id].bit_offset);
        // LED_0 is shorted with P3.26, so lets configure it too
        if (led_id == LED_0) {
            FIO3PIN |= (1 << 26);
        }
    }

    return PUCRSDEVBOARD__OK;
}
