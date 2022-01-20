/***********************************************************/
/***********************************************************/
/******************** Author : Mohamed Alaa ****************/
/******************** Layer : APP **************************/
/******************** Driver : Control leds by keypad ******/
/***********************************************************/
/***********************************************************/
#ifndef _APP_H_
#define _APP_H_

#include "STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/LED/LED.h"

void App_init(void)
{
	/*Call Keypad initialization*/
	KPD_init();
	/*Call LED initialization*/
	LED_init();
}

void App_prog(void)
{
	uint8_t local_u8Pressed;//local variable to hold the value of the pressed key

	while(1)
	{
			local_u8Pressed=KPD_u8GetPressedKey();
		/*Check if the pressed key is button1*/
		if(local_u8Pressed==1)
		{
			TurnLedON(LED0);
			TurnLedOFF(LED1);
			TurnLedOFF(LED2);
			TurnLedOFF(LED3);
		}
		/*Check if the pressed key is button2*/
		else if(local_u8Pressed==2)
		{
			TurnLedOFF(LED0);
			TurnLedON(LED1);
			TurnLedOFF(LED2);
			TurnLedOFF(LED3);
		}
		/*Check if the pressed key is button3*/
		else if(local_u8Pressed==3)
		{
			TurnLedOFF(LED0);
			TurnLedOFF(LED1);
			TurnLedON(LED2);
			TurnLedOFF(LED3);
		}
		/*Check if the pressed key is button4*/
		else if(local_u8Pressed==4)
		{
			TurnLedOFF(LED0);
			TurnLedOFF(LED1);
			TurnLedOFF(LED2);
			/*Pooling to keep led 3 value*/
			while(local_u8Pressed==4)
			{
				local_u8Pressed=KPD_u8GetPressedKey();
			}
			TurnLedON(LED3);
		}
		/*If no key pressed*/
		else
		{
			TurnLedOFF(LED0);
			TurnLedOFF(LED1);
			TurnLedOFF(LED2);
		}
	}
}

#endif
