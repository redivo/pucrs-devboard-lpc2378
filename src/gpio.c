/**************************************************************************************************/
/**
 * \brief  GPIO pins library
 *
 * Lib dependencies: N/A
 */
/**************************************************************************************************/

#include "gpio.h"

#include "lpc23xx.h"

bool _global_gpio__initialized = 0;
pucrsdevboard__pin_description_t _global_gpio_description[GPIO_EXP_LEN];

/**************************************************************************************************/

void gpio__init() {
    if(_global_gpio__initialized) {
        return;
    }

    /* TODO
     * A T1 should be wrote for this.
     * The number of PINSEL can be described as:
     *   (((PortNum * 32) + PinNum) * 2) <int division> 32
     *
     * The number of pinsel_offset can be described as:
     *   ((PortNum * 32) + PinNum) * 2) - (PinselNumber * 32)
     */
    _global_gpio_description[GPIO_EXP1_01].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_01].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_01].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_01].bit_offset = 8;
    _global_gpio_description[GPIO_EXP1_01].pinsel_offset = 16;

    _global_gpio_description[GPIO_EXP1_02].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_02].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_02].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_02].bit_offset = 9;
    _global_gpio_description[GPIO_EXP1_02].pinsel_offset = 18;

    _global_gpio_description[GPIO_EXP1_03].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_03].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_03].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_03].bit_offset = 10;
    _global_gpio_description[GPIO_EXP1_03].pinsel_offset = 20;

    _global_gpio_description[GPIO_EXP1_04].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_04].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_04].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_04].bit_offset = 11;
    _global_gpio_description[GPIO_EXP1_04].pinsel_offset = 22;

    _global_gpio_description[GPIO_EXP1_07].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_07].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_07].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_07].bit_offset = 12;
    _global_gpio_description[GPIO_EXP1_07].pinsel_offset = 24;

    _global_gpio_description[GPIO_EXP1_08].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_08].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_08].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_08].bit_offset = 13;
    _global_gpio_description[GPIO_EXP1_08].pinsel_offset = 26;

    _global_gpio_description[GPIO_EXP1_09].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_09].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_09].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_09].bit_offset = 14;
    _global_gpio_description[GPIO_EXP1_09].pinsel_offset = 28;

    _global_gpio_description[GPIO_EXP1_10].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP1_10].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP1_10].pinsel = &(PINSEL8);
    _global_gpio_description[GPIO_EXP1_10].bit_offset = 15;
    _global_gpio_description[GPIO_EXP1_10].pinsel_offset = 30;

    _global_gpio_description[GPIO_EXP2_01].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP2_01].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP2_01].pinsel = &(PINSEL9);
    _global_gpio_description[GPIO_EXP2_01].bit_offset = 24;
    _global_gpio_description[GPIO_EXP2_01].pinsel_offset = 16;

    _global_gpio_description[GPIO_EXP2_02].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP2_02].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP2_02].pinsel = &(PINSEL9);
    _global_gpio_description[GPIO_EXP2_02].bit_offset = 25;
    _global_gpio_description[GPIO_EXP2_02].pinsel_offset = 18;

    _global_gpio_description[GPIO_EXP2_03].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP2_03].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP2_03].pinsel = &(PINSEL9);
    _global_gpio_description[GPIO_EXP2_03].bit_offset = 28;
    _global_gpio_description[GPIO_EXP2_03].pinsel_offset = 24;

    _global_gpio_description[GPIO_EXP2_04].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP2_04].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP2_04].pinsel = &(PINSEL9);
    _global_gpio_description[GPIO_EXP2_04].bit_offset = 29;
    _global_gpio_description[GPIO_EXP2_04].pinsel_offset = 26;

    _global_gpio_description[GPIO_EXP2_07].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP2_07].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP2_07].pinsel = &(PINSEL9);
    _global_gpio_description[GPIO_EXP2_07].bit_offset = 30;
    _global_gpio_description[GPIO_EXP2_07].pinsel_offset = 28;

    _global_gpio_description[GPIO_EXP2_08].fiodir = &(FIO4DIR);
    _global_gpio_description[GPIO_EXP2_08].fiopin = &(FIO4PIN);
    _global_gpio_description[GPIO_EXP2_08].pinsel = &(PINSEL9);
    _global_gpio_description[GPIO_EXP2_08].bit_offset = 31;
    _global_gpio_description[GPIO_EXP2_08].pinsel_offset = 30;

    _global_gpio_description[GPIO_EXP2_09].fiodir = &(FIO0DIR);
    _global_gpio_description[GPIO_EXP2_09].fiopin = &(FIO0PIN);
    _global_gpio_description[GPIO_EXP2_09].pinsel = &(PINSEL0);
    _global_gpio_description[GPIO_EXP2_09].bit_offset = 0;
    _global_gpio_description[GPIO_EXP2_09].pinsel_offset = 0;

    _global_gpio_description[GPIO_EXP2_10].fiodir = &(FIO0DIR);
    _global_gpio_description[GPIO_EXP2_10].fiopin = &(FIO0PIN);
    _global_gpio_description[GPIO_EXP2_10].pinsel = &(PINSEL0);
    _global_gpio_description[GPIO_EXP2_10].bit_offset = 1;
    _global_gpio_description[GPIO_EXP2_10].pinsel_offset = 2;

    _global_gpio_description[GPIO_EXP3_01].fiodir = &(FIO0DIR);
    _global_gpio_description[GPIO_EXP3_01].fiopin = &(FIO0PIN);
    _global_gpio_description[GPIO_EXP3_01].pinsel = &(PINSEL0);
    _global_gpio_description[GPIO_EXP3_01].bit_offset = 4;
    _global_gpio_description[GPIO_EXP3_01].pinsel_offset = 8;

    _global_gpio_description[GPIO_EXP3_02].fiodir = &(FIO0DIR);
    _global_gpio_description[GPIO_EXP3_02].fiopin = &(FIO0PIN);
    _global_gpio_description[GPIO_EXP3_02].pinsel = &(PINSEL0);
    _global_gpio_description[GPIO_EXP3_02].bit_offset = 5;
    _global_gpio_description[GPIO_EXP3_02].pinsel_offset = 10;

    _global_gpio_description[GPIO_EXP3_03].fiodir = &(FIO3DIR);
    _global_gpio_description[GPIO_EXP3_03].fiopin = &(FIO3PIN);
    _global_gpio_description[GPIO_EXP3_03].pinsel = &(PINSEL7);
    _global_gpio_description[GPIO_EXP3_03].bit_offset = 23;
    _global_gpio_description[GPIO_EXP3_03].pinsel_offset = 14;

    _global_gpio_description[GPIO_EXP3_04].fiodir = &(FIO3DIR);
    _global_gpio_description[GPIO_EXP3_04].fiopin = &(FIO3PIN);
    _global_gpio_description[GPIO_EXP3_04].pinsel = &(PINSEL7);
    _global_gpio_description[GPIO_EXP3_04].bit_offset = 24;
    _global_gpio_description[GPIO_EXP3_04].pinsel_offset = 16;

    _global_gpio_description[GPIO_EXP3_07].fiodir = &(FIO3DIR);
    _global_gpio_description[GPIO_EXP3_07].fiopin = &(FIO3PIN);
    _global_gpio_description[GPIO_EXP3_07].pinsel = &(PINSEL7);
    _global_gpio_description[GPIO_EXP3_07].bit_offset = 25;
    _global_gpio_description[GPIO_EXP3_07].pinsel_offset = 18;

    _global_gpio_description[GPIO_EXP3_08].fiodir = &(FIO3DIR);
    _global_gpio_description[GPIO_EXP3_08].fiopin = &(FIO3PIN);
    _global_gpio_description[GPIO_EXP3_08].pinsel = &(PINSEL7);
    _global_gpio_description[GPIO_EXP3_08].bit_offset = 26;
    _global_gpio_description[GPIO_EXP3_08].pinsel_offset = 20;

    _global_gpio_description[GPIO_EXP4_01].fiodir = &(FIO1DIR);
    _global_gpio_description[GPIO_EXP4_01].fiopin = &(FIO1PIN);
    _global_gpio_description[GPIO_EXP4_01].pinsel = &(PINSEL3);
    _global_gpio_description[GPIO_EXP4_01].bit_offset = 22;
    _global_gpio_description[GPIO_EXP4_01].pinsel_offset = 12;

    _global_gpio_description[GPIO_EXP4_02].fiodir = &(FIO1DIR);
    _global_gpio_description[GPIO_EXP4_02].fiopin = &(FIO1PIN);
    _global_gpio_description[GPIO_EXP4_02].pinsel = &(PINSEL3);
    _global_gpio_description[GPIO_EXP4_02].bit_offset = 25;
    _global_gpio_description[GPIO_EXP4_02].pinsel_offset = 18;

    _global_gpio_description[GPIO_EXP4_03].fiodir = &(FIO1DIR);
    _global_gpio_description[GPIO_EXP4_03].fiopin = &(FIO1PIN);
    _global_gpio_description[GPIO_EXP4_03].pinsel = &(PINSEL3);
    _global_gpio_description[GPIO_EXP4_03].bit_offset = 27;
    _global_gpio_description[GPIO_EXP4_03].pinsel_offset = 22;

    _global_gpio_description[GPIO_EXP4_04].fiodir = &(FIO1DIR);
    _global_gpio_description[GPIO_EXP4_04].fiopin = &(FIO1PIN);
    _global_gpio_description[GPIO_EXP4_04].pinsel = &(PINSEL3);
    _global_gpio_description[GPIO_EXP4_04].bit_offset = 26;
    _global_gpio_description[GPIO_EXP4_04].pinsel_offset = 20;

    _global_gpio_description[GPIO_EXP4_07].fiodir = &(FIO1DIR);
    _global_gpio_description[GPIO_EXP4_07].fiopin = &(FIO1PIN);
    _global_gpio_description[GPIO_EXP4_07].pinsel = &(PINSEL3);
    _global_gpio_description[GPIO_EXP4_07].bit_offset = 29;
    _global_gpio_description[GPIO_EXP4_07].pinsel_offset = 26;

    _global_gpio_description[GPIO_EXP4_08].fiodir = &(FIO1DIR);
    _global_gpio_description[GPIO_EXP4_08].fiopin = &(FIO1PIN);
    _global_gpio_description[GPIO_EXP4_08].pinsel = &(PINSEL3);
    _global_gpio_description[GPIO_EXP4_08].bit_offset = 28;
    _global_gpio_description[GPIO_EXP4_08].pinsel_offset = 24;

    _global_gpio_description[GPIO_EXP4_09].fiodir = &(FIO0DIR);
    _global_gpio_description[GPIO_EXP4_09].fiopin = &(FIO0PIN);
    _global_gpio_description[GPIO_EXP4_09].pinsel = &(PINSEL0);
    _global_gpio_description[GPIO_EXP4_09].bit_offset = 14;
    _global_gpio_description[GPIO_EXP4_09].pinsel_offset = 28;

    _global_gpio_description[GPIO_EXP4_10].fiodir = &(FIO0DIR);
    _global_gpio_description[GPIO_EXP4_10].fiopin = &(FIO0PIN);
    _global_gpio_description[GPIO_EXP4_10].pinsel = &(PINSEL0);
    _global_gpio_description[GPIO_EXP4_10].bit_offset = 15;
    _global_gpio_description[GPIO_EXP4_10].pinsel_offset = 30;

    _global_gpio__initialized = 1;
}

/**************************************************************************************************/

pucrsdevboard__error_t gpio__configure(gpio_exp_pin_t pin, gpio_exp_pin_direction_t direction)
{
    // If not initialized yet, initialize it!
    if(!_global_gpio__initialized) {
        gpio__init();
    }

    // Exit on invalid pin
    if (pin == GPIO_EXP_LEN) {
        return PUCRSDEVBOARD__INVALID_ARG_ERR;
    }

    // Inform warning to shared-usage pins
    pucrsdevboard__error_t ret = PUCRSDEVBOARD__OK;
    if (pin == GPIO_EXP2_09 || pin == GPIO_EXP2_10 || pin == GPIO_EXP3_08) {
        ret = PUCRSDEVBOARD__SHARED_RESOURCE_WARNING;
    }

    // Configure pin to 00 (1 nible), that is, GPIO
    uint8_t pinsel_offset = _global_gpio_description[pin].pinsel_offset;
    *(_global_gpio_description[pin].pinsel) &= ~(1 << pinsel_offset);
    *(_global_gpio_description[pin].pinsel) &= ~(1 << (pinsel_offset + 1));

    // Set direction
    if (direction == GPIO_PIN_OUT) {
        // Set direction to 1 (output)
        *(_global_gpio_description[pin].fiodir) |= (1 << _global_gpio_description[pin].bit_offset);
    }
    else {
        // Set direction to 0 (input)
        *(_global_gpio_description[pin].fiodir) &= ~(1 << _global_gpio_description[pin].bit_offset);
    }

    return ret;
}

/**************************************************************************************************/

pucrsdevboard__error_t gpio__get(gpio_exp_pin_t pin, bool *value)
{
    // If not initialized yet, initialize it!
    if(!_global_gpio__initialized) {
        gpio__init();
    }

    // Exit on invalid pin
    if (pin == GPIO_EXP_LEN) {
        return PUCRSDEVBOARD__INVALID_ARG_ERR;
    }

    // Exit on not GPIO configured pins
    uint8_t pinsel_offset = _global_gpio_description[pin].pinsel_offset;
    bool bit0 = !!(*(_global_gpio_description[pin].pinsel) & (1 << pinsel_offset));
    bool bit1 = !!(*(_global_gpio_description[pin].pinsel) & (1 << (pinsel_offset + 1)));
    if (!bit0 && !bit1) {
        return PUCRSDEVBOARD__NOT_INITIALIZED_ERR;
    }

    // Inform warning to shared-usage pins
    pucrsdevboard__error_t ret = PUCRSDEVBOARD__OK;
    if (pin == GPIO_EXP2_09 || pin == GPIO_EXP2_10 || pin == GPIO_EXP3_08) {
        ret = PUCRSDEVBOARD__SHARED_RESOURCE_WARNING;
    }

    // Get the value
    *value = !!(*(_global_gpio_description[pin].fiopin)
                    & (1 << _global_gpio_description[pin].bit_offset));

    return ret;
}

/**************************************************************************************************/

pucrsdevboard__error_t gpio__set(gpio_exp_pin_t pin, bool value)
{
    // If not initialized yet, initialize it!
    if(!_global_gpio__initialized) {
        gpio__init();
    }

    // Exit on invalid pin
    if (pin == GPIO_EXP_LEN) {
        return PUCRSDEVBOARD__INVALID_ARG_ERR;
    }

    // Exit on not GPIO configured pins
    uint8_t pinsel_offset = _global_gpio_description[pin].pinsel_offset;
    bool bit0 = !!(*(_global_gpio_description[pin].pinsel) & (1 << pinsel_offset));
    bool bit1 = !!(*(_global_gpio_description[pin].pinsel) & (1 << (pinsel_offset + 1)));
    if (!bit0 && !bit1) {
        return PUCRSDEVBOARD__NOT_INITIALIZED_ERR;
    }

    // Verify direction and exit if it is different of 0 (input)
    if ((*(_global_gpio_description[pin].fiodir) & (1 << _global_gpio_description[pin].bit_offset))
            != 0) {
        return PUCRSDEVBOARD__WRONG_TYPE_ERR;
    }

    // Inform warning to shared-usage pins
    pucrsdevboard__error_t ret = PUCRSDEVBOARD__OK;
    if (pin == GPIO_EXP2_09 || pin == GPIO_EXP2_10 || pin == GPIO_EXP3_08) {
        ret = PUCRSDEVBOARD__SHARED_RESOURCE_WARNING;
    }

    // Set the value
    if (value == 1) {
        *(_global_gpio_description[pin].fiopin) |= (1 << _global_gpio_description[pin].bit_offset);
    } else {
        *(_global_gpio_description[pin].fiopin) &= ~(1 << _global_gpio_description[pin].bit_offset);
    }

    return PUCRSDEVBOARD__OK;
}

/**************************************************************************************************/
