/*
Example for Adapter Click

    Date          : Feb 2019.
    Author        : Jovan Stajkovic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, sets INT pin as input, and  CS, PWM , RX and TX pins as output.
- Application Initialization - Initalizes I2C driver and makes an initial log.
- Application Task - (code snippet)  This is an example that shows the use of the Adapter click board. In this example we are reading
                     ID registrer from another device (THERMO 5 click board).

*/

#include "Click_Adapter_types.h"
#include "Click_Adapter_config.h"

uint8_t i2cSlaveAddrDemo = 0x4C;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RX_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_TX_PIN, _GPIO_OUTPUT );

     mikrobus_i2cInit( _MIKROBUS1, &_ADAPTER_I2C_CFG[0] );

     mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    adapter_i2cDriverInit( (T_ADAPTER_P)&_MIKROBUS1_GPIO, (T_ADAPTER_P)&_MIKROBUS1_I2C, i2cSlaveAddrDemo );
    Delay_ms( 100 );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
    mikrobus_logWrite( " Adapter  Click  ", _LOG_LINE );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
}

void applicationTask()
{
    uint8_t rdValue;
    char logTxt[ 50 ];
    
    rdValue = adapter_readData( 0xFD );
    IntToStr( rdValue, logTxt );
	
    Ltrim( logTxt );
    mikrobus_logWrite( " Read data :  ", _LOG_LINE );
    mikrobus_logWrite( logTxt, _LOG_LINE );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
	
    Delay_ms( 2000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
    	applicationTask();
    }
}