#ifndef _APP_H_
#define _APP_H_

#include "STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/LED/LED.h"

void App_init(void)
{
	KPD_init();
	LED_init();
}

void App_prog(void)
{
	uint8_t local_u8Pressed;

	while(1)
	{
			local_u8Pressed=KPD_u8GetPressedKey();

		if(local_u8Pressed==1)
		{
			TurnLedON(LED0);
			TurnLedOFF(LED1);
			TurnLedOFF(LED2);
			TurnLedOFF(LED3);
		}

		else if(local_u8Pressed==2)
		{
			TurnLedOFF(LED0);
			TurnLedON(LED1);
			TurnLedOFF(LED2);
			TurnLedOFF(LED3);
		}
		else if(local_u8Pressed==3)
		{
			TurnLedOFF(LED0);
			TurnLedOFF(LED1);
			TurnLedON(LED2);
			TurnLedOFF(LED3);
		}

		else if(local_u8Pressed==4)
		{
			TurnLedOFF(LED0);
			TurnLedOFF(LED1);
			TurnLedOFF(LED2);
			while(local_u8Pressed==4)
			{
				local_u8Pressed=KPD_u8GetPressedKey();
			}
			TurnLedON(LED3);
		}
		else
		{
			TurnLedOFF(LED0);
			TurnLedOFF(LED1);
			TurnLedOFF(LED2);
		}
	}
}

#endif
