
/*tiva one*/

#include "timer.h"
#include "button.h"
#include "UART.h"
#if TIVA_TYPE == TIVA1
int main(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
   volatile  uint8_t InitialTimeCounter = 0,InitialSpeedCounter = 0;
    vUART_Init();
    Button_Init();
    for(; InitialTimeCounter<4 ; InitialTimeCounter++)
    {
        time = ( (time *10) +   (UARTCharGet (UART0_BASE )-48));
    }
    UARTprintf("Start Time: %d\n",time);
    for(; InitialSpeedCounter<3 ; InitialSpeedCounter++)
    {
        speed = ( (speed *10) + (UARTCharGet (UART0_BASE )-48));
    }
    UARTprintf("Start Speed: %d\n",speed);
    Timer0_Init();

    while(1)
    {
        Button_press();
    }
}
/*Tiva 2*/
#elif TIVA_TYPE == TIVA2

int main(void)
{
    vUART_Init();
    Button_Init();
    while(1)
    {
        Button_press();
    }
}
#endif

