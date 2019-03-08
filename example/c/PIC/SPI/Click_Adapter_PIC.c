/*
Example for Adapter Click

    Date          : Feb 2019.
    Author        : Jovan Stajkovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, SPI and LOG structures, sets INT pin as input, and  CS, PWM , RX and TX pins as output.
- Application Initialization - Initalizes SPI driver and makes an initial log.
- Application Task - (code snippet)  This is an example that shows the use of the Adapter click board. In this example we are writing
                     into a shift register.

*/

#include "Click_Adapter_types.h"
#include "Click_Adapter_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RX_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_TX_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_ADAPTER_SPI_CFG[0] );

    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    adapter_spiDriverInit( (T_ADAPTER_P)&_MIKROBUS1_GPIO, (T_ADAPTER_P)&_MIKROBUS1_SPI );
    Delay_ms( 100 );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
    mikrobus_logWrite( " Adapter  Click  ", _LOG_LINE );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
}

void applicationTask()
{
    adapter_turnPwmOn();
    adapter_writeData( 0x00, 0x79 );

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