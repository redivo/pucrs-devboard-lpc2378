/**************************************************************************************************/
/**
 * \brief  Time library
 */
/**************************************************************************************************/

#include "time.h"

#include <stdbool.h>
#include "lpc23xx.h"

#define CCLK 12000000

bool _global_time__initialized = 0;

/**************************************************************************************************/

void time__init()
{
    if(_global_time__initialized) {
        return;
    }

    // Turn on power of T0
    PCONP |= 2;

    PCLKSEL0 = (PCLKSEL0 & (~0x0c)) | 0x04;
    T0TCR = 0; // Disable T0
    T0PR = CCLK/1000 - 1; // Increments  T0TC 1000 times per second
    T0TCR = 2; // Initialize T0
    T0TCR = 1; // Enable T0

    _global_time__initialized = 1;
}

/**************************************************************************************************/

void time__ms_sleep(uint32_t t)
{
    // If not initialized yet, initialize it!
    if(!_global_time__initialized) {
        time__init();
    }

    uint32_t tf;

    // T0TC is counting in milliseconds, so let tf be T0TC (now) + time to sleep
    tf = T0TC + t;

    // Now wait until T0TC reaches tf
    while(tf != T0TC);
}
