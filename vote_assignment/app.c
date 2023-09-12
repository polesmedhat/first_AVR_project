#include"lcd.h"
#include"keypad.h"
#include "std_types.h"
#include"app.h"
#include<util/delay.h>

static uint8 counter[] = {0,0,0,0};

static uint8 max(uint8 x,uint8 y);
static uint8 APP_max();
static void APP_winnercreen();

void APP_Init(){
	LCD_init();
}

void APP_mainScreen(){
	LCD_clearScreen();
	_delay_ms(SHORT_DELAY);
	LCD_displayString("A=");
	LCD_integerToString(counter[0]);

	LCD_moveCursor(0,8);
	LCD_displayString("B=");
	LCD_integerToString(counter[1]);

	LCD_moveCursor(1,0);
	LCD_displayString("C=");
	LCD_integerToString(counter[2]);

	LCD_moveCursor(1,8);
	LCD_displayString("D=");
	LCD_integerToString(counter[3]);

	uint8 input = KEYPAD_getPressedKey();
	_delay_ms(KEYPAD_DELAY);

	switch (input) {
		case candidateA:
			counter[0]++;
			break;
		case candidateB:
			counter[1]++;
			break;
		case candidateC:
			counter[2]++;
			break;
		case candidateD:
			counter[3]++;
			break;
		case reset:
			for (uint8 var = 0; var < 4; ++var) {
				counter[var]=0;
			}
			break;
		case winner:
			APP_winnercreen();
			break;
		default:
			break;
	}
	APP_mainScreen();
}

static void APP_winnercreen(){
	uint8 maxcounter =APP_max();
	uint8 flag=0;
	LCD_clearScreen();
	_delay_ms(SHORT_DELAY);
	LCD_displayString("winner: ");

	for (uint8 var = 0;var < 4; ++var) {

		if(counter[var]==maxcounter){
			if(flag==1)
				LCD_displayCharacter(',');
				flag=1;
			LCD_displayCharacter(65+var);}
	}
	_delay_ms(screen_DELAY);
	APP_mainScreen();
}

static uint8 max(uint8 x,uint8 y){
	if(x>y)
		return x;
	else
		return y;
}

static uint8 APP_max(){
	uint8 maxCounter = counter[0];
	for (uint8 var = 1;var < 4; ++ var)
		maxCounter = max(maxCounter,counter[var]);
	return maxCounter;

}
