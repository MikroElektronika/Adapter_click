![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Adapter Click

---

- **CIC Prefix**  : ADAPTER
- **Author**      : Jovan Stajkovic
- **Verison**     : 1.0.0
- **Date**        : Feb 2019.

---

### Software Support

We provide a library for the Adapter Click on our [LibStock](${LIBSTOCK_LINK}) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

${LIBRARY_DESCRIPTION}

Key functions :

- ``` void adapter_writeData( uint8_t regAddress, uint8_t wrData ); ``` - Function is used to write the 8-bit data into chosen register.
- ``` uint8_t adapter_readData( uint8_t regAddress ); ``` - Function read the 8-bit data from the chosen register.
- ```  ``` - 

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, sets INT pin as input, and  CS, PWM , RX and TX pins as output.
- Application Initialization - Initalizes I2C driver and makes an initial log.
- Application Task - (code snippet)  This is an example that shows the use of the Adapter click board. In this example we are reading
                     ID registrer from another device (THERMO 5 click board).


```.c

void applicationTask()
{
    uint8_t rdValue;
    uint8_t logTxt[ 50 ];
    
    rdValue = adapter_readData( 0xFD );
    IntToStr( rdValue, logTxt );
	
    Ltrim( logTxt );
    mikrobus_logWrite( " Read data :  ", _LOG_LINE );
    mikrobus_logWrite( logTxt, _LOG_LINE );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
	
    Delay_ms( 2000 );
}

```


The full application code, and ready to use projects can be found on our 
[LibStock](${LIBSTOCK_LINK}) page.

Other mikroE Libraries used in the example:

- SPI
- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
