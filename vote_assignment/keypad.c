#include"common_macros.h"
#include"gpio.h"
#include"keypad.h"

/*******************************************************************************/

/*******************************************************************************
 *                      		   FUNCTIONS                                   *
 *******************************************************************************/
/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void)
{
	uint8 row,col;
	GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID  ,INPUT);
	GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+1,INPUT);
	GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+2,INPUT);
	GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+3,INPUT);

	GPIO_setup_Pin_Direction(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID,INPUT);
	GPIO_setup_Pin_Direction(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+1,INPUT);
	GPIO_setup_Pin_Direction(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+2,INPUT);
#if (KEYPAD_NUM_COLS==4)
	GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+3,INPUT);
#endif

	while(1)
	{
		for(row=0;row<KEYPAD_NUM_ROWS;row++)
		{
			GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,OUTPUT);
			GPIO_write_Pin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID+row, KEYPAD_BUTTON_PRESSED);

			for(col=0;col<KEYPAD_NUM_COLS;col++)
			{
				if(GPIO_read_Pin(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+col) == KEYPAD_BUTTON_PRESSED)
				{
					#if (KEYPAD_NUM_COLS == 3)

					#ifdef STANDARD_KEYPAD
						return ((row*KEYPAD_NUM_COLS)+col+1);
					#else
						return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif

					#elif (KEYPAD_NUM_COLS == 4)

					#ifdef STANDARD_KEYPAD
						return ((row*KEYPAD_NUM_COLS)+col+1);
					#else
						return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif
					#endif

				}
			}
			GPIO_setup_Pin_Direction(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,INPUT);
		}
	}
}

