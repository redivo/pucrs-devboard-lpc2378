/**************************************************************************************************/
/**
 * \brief  GPIO pins library
 *
 * Lib dependencies: N/A
 */
/**************************************************************************************************/

#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdbool.h>
#include "general.h"

/**************************************************************************************************/
/**
 * \brief  This type defines the GPIO pin.
 *         The GPIO pins are distributed in 4 blocks of 12 pins called EXP<num> and are mapped as
           described below.
           The enum name is formed this way: GPIO_EXP<expansion block number>_<pin number>
 */
typedef enum {
    GPIO_EXP1_01, //!< P4.8
    GPIO_EXP1_02, //!< P4.9
    GPIO_EXP1_03, //!< P4.10
    GPIO_EXP1_04, //!< P4.11
//  GPIO_EXP1_05       GND (it's not a GIPO)
//  GPIO_EXP1_06       3V3 (it's not a GIPO)
    GPIO_EXP1_07, //!< P4.12
    GPIO_EXP1_08, //!< P4.13
    GPIO_EXP1_09, //!< P4.14
    GPIO_EXP1_10, //!< P4.15
//  GPIO_EXP1_11       GND (it's not a GIPO)
//  GPIO_EXP1_12       3V3 (it's not a GIPO)

    GPIO_EXP2_01, //!< P4.24
    GPIO_EXP2_02, //!< P4.25
    GPIO_EXP2_03, //!< P4.28
    GPIO_EXP2_04, //!< P4.29
//  GPIO_EXP2_05,      GND (it's not a GIPO)
//  GPIO_EXP2_06,      3V3 (it's not a GIPO)
    GPIO_EXP2_07, //!< P4.30
    GPIO_EXP2_08, //!< P4.31
    GPIO_EXP2_09, //!< P0.0 (XXX it has a pull-up resistor to use I²C, so be careful using this pin)
    GPIO_EXP2_10, //!< P0.1 (XXX it has a pull-up resistor to use I²C, so be careful using this pin)
//  GPIO_EXP2_11,      GND (it's not a GIPO)
//  GPIO_EXP2_12,      3V3 (it's not a GIPO)

    GPIO_EXP3_01, //!< P0.4
    GPIO_EXP3_02, //!< P0.5
    GPIO_EXP3_03, //!< P3.23
    GPIO_EXP3_04, //!< P3.24
//  GPIO_EXP3_05,      GND (it's not a GIPO)
//  GPIO_EXP3_06,      3V3 (it's not a GIPO)
    GPIO_EXP3_07, //!< P3.25
    GPIO_EXP3_08, //!< P3.26 (XXX it is shorted with P4.0 and LED0, so be careful using this pin)
//  GPIO_EXP3_09, /    UNCONNECTED (it's not a GIPO)
//  GPIO_EXP3_10,      UNCONNECTED (it's not a GIPO)
//  GPIO_EXP3_11,      GND (it's not a GIPO)
//  GPIO_EXP3_12,      3V3 (it's not a GIPO)

    GPIO_EXP4_01, //!< P1.22
    GPIO_EXP4_02, //!< P1.25
    GPIO_EXP4_03, //!< P1.27
    GPIO_EXP4_04, //!< P1.26
//  GPIO_EXP4_05,      GND (it's not a GIPO)
//  GPIO_EXP4_06,      3V3 (it's not a GIPO)
    GPIO_EXP4_07, //!< P1.29
    GPIO_EXP4_08, //!< P1.28
    GPIO_EXP4_09, //!< P0.14
    GPIO_EXP4_10, //!< P0.15
//  GPIO_EXP4_11,      GND (it's not a GIPO)
//  GPIO_EXP4_12,      3V3 (it's not a GIPO)

    GPIO_EXP_LEN, //!< It's the number of GPIO_EXP definition. Don't use it as a real GPIO
} gpio_exp_pin_t;

/**************************************************************************************************/
/**
 * \brief  Pin direction
 */
typedef enum {
    GPIO_PIN_IN,  //!< Input signal
    GPIO_PIN_OUT, //!< Ouput signal
} gpio_exp_pin_direction_t;

/**************************************************************************************************/
/**
 * \brief  Perform hardware initializations to GPIO pins
 */
void gpio__init();

/**************************************************************************************************/
/**
 * \brief  Configure the direction of a GPIO pin
 * \param  pin        Pin to be configured
 * \param  direction  Inform if the pin will be an input or output pin
 * \return PUCRSDEVBOARD__OK if OK, error code otherwise
 */
pucrsdevboard__error_t gpio__configure(gpio_exp_pin_t pin, gpio_exp_pin_direction_t direction);

/**************************************************************************************************/
/**
 * \brief  Get the value of a specific GPIO pin
 * \param  pin    Pin to read the value
 * \param  value  Pre allocated pointer to be filled with the read value
 * \return PUCRSDEVBOARD__OK if OK, error code otherwise
 */
pucrsdevboard__error_t gpio__get(gpio_exp_pin_t pin, bool *value);

/**************************************************************************************************/
/**
 * \brief  Set a value into a GPIO pin
 * \param  pin    Pin to set the value
 * \param  value  Value to be set into the GPIO pin
 * \return PUCRSDEVBOARD__OK if OK, error code otherwise
 */
pucrsdevboard__error_t gpio__set(gpio_exp_pin_t pin, bool value);

#endif /* __GPIO_H__ */
