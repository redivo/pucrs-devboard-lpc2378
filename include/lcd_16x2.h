/**************************************************************************************************/
/**
 * \brief  LCD 16x2 display library
 *
 * Lib dependencies: time
 */
/**************************************************************************************************/

#ifndef __LCD_16X2_H__
#define __LCD_16X2_H__

#include "general.h"

/**************************************************************************************************/
/**
 * \brief  This function perform the hardware initializations to LCD 16x2 display initializations to
 *         timer if not initialized yet
 */
void lcd_16x2__init();

/**************************************************************************************************/
/**
 * \brief  Print a string on LCD 16x2
 * \param  txt  String to be printed
 * \return PUCRSDEVBOARD__OK if OK, error code otherwise
 */
pucrsdevboard__error_t lcd_16x2__print(char *txt);

/**************************************************************************************************/
/**
 * \brief  Clean LCD screen
 */
void lcd_16x2__clean();

/**************************************************************************************************/
#endif /* __LCD_16X2_H__ */
