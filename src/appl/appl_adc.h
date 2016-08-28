/**
 * \file
 *
 * TODO
 */

#ifndef _APPL_ADC_H
#define _APPL_ADC_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

//-- for T_ADCHandler_Voltage
#include "adc_handler.h"

//-- for enum E_ApplAdcChannel
#include "appl_adc_channels.h"



/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

/*******************************************************************************
 *    GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

/*******************************************************************************
 *    PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/

/**
 * Initialize module
 */
void appl_adc__init(void);

/**
 * Get current voltage of the given channel.
 */
T_ADCHandler_Voltage appl_adc__voltage__get(enum E_ApplAdcChannel channel_num);

#endif // _APPL_ADC_H


/*******************************************************************************
 *    end of file
 ******************************************************************************/