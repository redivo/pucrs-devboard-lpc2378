/**************************************************************************************************/
/**
 * \brief  General defines
 *
 * Lib dependencies: N/A
 */
/**************************************************************************************************/

#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <stdint.h>

/**
 * \brief  Error and warning codes
 */
typedef enum {
    PUCRSDEVBOARD__SHARED_RESOURCE_WARNING = 2,
    PUCRSDEVBOARD__GENERIC_WARNING = 1,

    PUCRSDEVBOARD__OK = 0,

    PUCRSDEVBOARD__GENERIC_ERR = 1,
    PUCRSDEVBOARD__TOO_LONG_ERR = -2,
    PUCRSDEVBOARD__INVALID_ARG_ERR = -3,
    PUCRSDEVBOARD__NOT_INITIALIZED_ERR = -4,
    PUCRSDEVBOARD__WRONG_TYPE_ERR = -5,
} pucrsdevboard__error_t;

/**
 * \brief  Pin description
 */
typedef struct {
    volatile unsigned long *fiodir;
    volatile unsigned long *fiopin;
    volatile unsigned long *pinsel;
    uint8_t bit_offset;
    uint8_t pinsel_offset;
} pucrsdevboard__pin_description_t;
#endif /* __GENERAL_H__ */
