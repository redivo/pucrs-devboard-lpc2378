/**************************************************************************************************/
/**
 * \brief  LEDs Libraries
 *
 * Lib dependencies: N/A
 */
/**************************************************************************************************/

#ifndef __LED_H__
#define __LED_H__

#include <stdbool.h>
#include "general.h"

/**************************************************************************************************/
/**
 * \brief  This type defines the LED identification
 */
typedef enum {
    LED_0,
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,

    LED_LEN,
} led_id_t;

/**************************************************************************************************/
/**
 * \brief  Perform hardware initializations to LEDs if not initialized yet
 */
void led__init();

/**************************************************************************************************/
/**
 * \brief  Set LED state
 * \param  led_id  LED Identification
 * \param  on      TRUE to turn the led ON or FALSE to turn OFF
 * \return PUCRSDEVBOARD__OK if OK, error code otherwise
*/
pucrsdevboard__error_t led__set(led_id_t led_id, bool on);

#endif /* __LED_H__ */
