/*
    __adapter_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __adapter_driver.h
@brief    Adapter Driver
@mainpage Adapter Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ADAPTER
@brief      Adapter Click Driver
@{

| Global Library Prefix | **ADAPTER** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2019.**      |
| Developer             | **Jovan Stajkovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

/** 
 * @macro T_ADAPTER_P
 * @brief Driver Abstract type 
 */
#define T_ADAPTER_P    const uint8_t*

/** @defgroup ADAPTER_COMPILE Compilation Config */              /** @{ */

   #define   __ADAPTER_DRV_SPI__                            /**<     @macro __ADAPTER_DRV_SPI__  @brief SPI driver selector */
   #define   __ADAPTER_DRV_I2C__                            /**<     @macro __ADAPTER_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ADAPTER_DRV_UART__                           /**<     @macro __ADAPTER_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ADAPTER_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup ADAPTER_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ADAPTER_INIT Driver Initialization */              /** @{ */

#ifdef   __ADAPTER_DRV_SPI__
void adapter_spiDriverInit(T_ADAPTER_P gpioObj, T_ADAPTER_P spiObj);
#endif
#ifdef   __ADAPTER_DRV_I2C__
void adapter_i2cDriverInit(T_ADAPTER_P gpioObj, T_ADAPTER_P i2cObj, uint8_t slave);
#endif
#ifdef   __ADAPTER_DRV_UART__
void adapter_uartDriverInit(T_ADAPTER_P gpioObj, T_ADAPTER_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void adapter_gpioDriverInit(T_ADAPTER_P gpioObj);
                                                                       /** @} */
/** @defgroup ADAPTER_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Generic write the byte of data function
 *
 * @param[in] regAddress   8-bit data representing the register address
 *
 * @param[in] writeData    8-bit data representing the Byte of data to write
 *
 * Function is used to write the 8-bit data into chosen register.
 */

void adapter_writeData( uint8_t regAddress, uint8_t wrData );

/**
 * @brief Generic read the byte of data function
 *
 * @param[in] regAddress   8-bit data representing the register address
 *
 * @return   8-bit data read from the register
 *
 * Function read the 8-bit data from the chosen register.
 */

uint8_t adapter_readData( uint8_t regAddress );

/**
 * @brief Turn TX on function
 *
 * Function is used to set TX pin to 1.
**/
void adapter_turnTxOn();

/**
 * @brief Turn RX on function
 *
 * Function is used to set RX pin to 1.
**/
void adapter_turnRxOn();

/**
 * @brief Turn PWM on function
 *
 * Function is used to set PWM pin to 1.
**/
void adapter_turnPwmOn();

/**
 * @brief Turn TX off function
 *
 * Function is used to set TX pin to 0.
**/
void adapter_turnTxOff();

/**
 * @brief Turn RX off function
 *
 * Function is used to set RX pin to 0.
**/
void adapter_turnRxOff();

/**
 * @brief Turn PWM off function
 *
 * Function is used to set PWM pin to 0.
**/
void adapter_turnPwmOff();

/**
 * @brief Check INT function
 *
 * @returns Result  State of the INT pin
 *
 * Function is used to check the state of INT pin.
**/
uint8_t adapter_checkInt();
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Adapter_STM.c
    @example Click_Adapter_TIVA.c
    @example Click_Adapter_CEC.c
    @example Click_Adapter_KINETIS.c
    @example Click_Adapter_MSP.c
    @example Click_Adapter_PIC.c
    @example Click_Adapter_PIC32.c
    @example Click_Adapter_DSPIC.c
    @example Click_Adapter_AVR.c
    @example Click_Adapter_FT90x.c
    @example Click_Adapter_STM.mbas
    @example Click_Adapter_TIVA.mbas
    @example Click_Adapter_CEC.mbas
    @example Click_Adapter_KINETIS.mbas
    @example Click_Adapter_MSP.mbas
    @example Click_Adapter_PIC.mbas
    @example Click_Adapter_PIC32.mbas
    @example Click_Adapter_DSPIC.mbas
    @example Click_Adapter_AVR.mbas
    @example Click_Adapter_FT90x.mbas
    @example Click_Adapter_STM.mpas
    @example Click_Adapter_TIVA.mpas
    @example Click_Adapter_CEC.mpas
    @example Click_Adapter_KINETIS.mpas
    @example Click_Adapter_MSP.mpas
    @example Click_Adapter_PIC.mpas
    @example Click_Adapter_PIC32.mpas
    @example Click_Adapter_DSPIC.mpas
    @example Click_Adapter_AVR.mpas
    @example Click_Adapter_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __adapter_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */