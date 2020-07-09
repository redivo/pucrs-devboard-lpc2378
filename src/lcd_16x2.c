/**************************************************************************************************/
/**
 * \brief  LCD 16x2 display library
 */
/**************************************************************************************************/

#include "lcd_16x2.h"

#include <stdint.h>
#include <stdbool.h>
#include "lpc23xx.h"
#include "time.h"

#define LCD_E 8
#define LCD_RS 4
#define LCD_MAX_COLUMNS 16
#define LCD_MAX_LINES 2

bool _global_lcd_16x2__initialized = 0;

/**************************************************************************************************/
/**
 * \brief  Send command to LCD display
 * \param  cmd  Command to be sent
 */
static void lcd_command(uint8_t cmd)
{
    FIO3PIN0 = cmd;
    FIO2CLR = LCD_RS; // Clear RS to send a commmand
    FIO2SET = LCD_E;
    FIO2CLR = LCD_E;
    time__ms_sleep(20);
}

/**************************************************************************************************/
/**
 * \brief  Send a character to LCD display
 * \param  c  Character to be sent
 */
static void lcd_char(char c)
{
    FIO3PIN0 = c;
    FIO2SET = LCD_RS; // set RS to send a character
    FIO2SET = LCD_E;
    FIO2CLR = LCD_E;

    time__ms_sleep(2);
}

/**************************************************************************************************/

void lcd_16x2__init()
{
    if(_global_lcd_16x2__initialized) {
        return;
    }

    FIO3DIR |= 0xff; // Set as out
    FIO2DIR  |= LCD_E | LCD_RS; // EN and RS from LCD as out */
    FIO2CLR = LCD_E;

    time__ms_sleep(20); // Wait

    lcd_command(0x38); // Configure LCD to 2 lines
    lcd_command(1);  // Clear display
    lcd_command(0x0c); // Hide cursor

    _global_lcd_16x2__initialized = 1;
}

/**************************************************************************************************/

pucrsdevboard__error_t lcd_16x2__print(char *txt)
{
    // If not initialized yet, initialize it!
    if(!_global_lcd_16x2__initialized) {
        lcd_16x2__init();
    }

    static uint8_t column = 0;
    static uint8_t line = 0;

    /* Iterate over received text and print it on LCD display */
    while (*txt) {
        switch (*txt) {
            /* Handle new line */
            case '\n':
                /* Check boundaries */
                if ((line + 1) >= LCD_MAX_LINES) {
                    return PUCRSDEVBOARD__TOO_LONG_ERR;
                }

                if (line == 0) {
                    lcd_command(0xC0 + column);
                }

                line++;
                break;

            /* Handle return */
            case '\r':
                if (line == 0) {
                    lcd_command(0x80);
                } else {
                    lcd_command(0xC0);
                }

                column = 0;
                break;

            /* FormFeed return to the begin of the LCD display */
            case '\f':
                lcd_command(0x80);
                column = 0;
                line = 0;
                break;

            default:
                /* Check boundaries */
                if (column >= LCD_MAX_COLUMNS) {
                    return PUCRSDEVBOARD__TOO_LONG_ERR;
                }

                lcd_char(*txt);
                column++;
        }

        txt++;
    }

    return PUCRSDEVBOARD__OK;
}

/**************************************************************************************************/

void lcd_16x2__clean()
{
    // If not initialized yet, initialize it!
    if(!_global_lcd_16x2__initialized) {
        lcd_16x2__init();
    }

    // Clear screen and go back to the begin of the scree
    lcd_command(0x01);
    lcd_16x2__print("\f");
}
/**************************************************************************************************/
