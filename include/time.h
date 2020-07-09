/**************************************************************************************************/
/**
 * \brief  Time library
 *
 * Lib dependencies: N/A
 */
/**************************************************************************************************/

#ifndef __TIME_H__
#define __TIME_H__

#include <stdint.h>

/**************************************************************************************************/
/**
 * \brief  Perform hardware initializations to timer if not initialized yet
 */
void time__init();

/**************************************************************************************************/
/**
 * \brief  Sleep for an specific time in milliseconds
 * \param  t  Time, in milliseconds, to sleep
 */
void time__ms_sleep(uint32_t t);

/**************************************************************************************************/

#endif /* __TIME_H__ */
