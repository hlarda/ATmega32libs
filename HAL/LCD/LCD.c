#include"LCD.h"
#include"LCDprivate.h"

void LCDinit(void){
	#if    LCD_MODE   ==   _8_BIT_MODE
		DIOsetPinDirection(LCD_PD0,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD1,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD2,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD3,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD4,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD5,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD6,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD7,OUTPUT_PIN);

		DIOsetPinDirection(LCD_RS,OUTPUT_PIN);
		DIOsetPinDirection(LCD_RW,OUTPUT_PIN);
		DIOsetPinDirection(LCD_EN,OUTPUT_PIN);
		
		_delay_ms(40);
		DIOsetPinValue(LCD_RW,LOW_PIN);
		LCDwriteCommand(LCD_8_BIT_MODE_CMD);
	#elif  LCD_MODE   ==   _4_BIT_MODE
		DIOsetPinDirection(LCD_PD4,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD5,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD6,OUTPUT_PIN);
		DIOsetPinDirection(LCD_PD7,OUTPUT_PIN);

		DIOsetPinDirection(LCD_RS,OUTPUT_PIN);
		DIOsetPinDirection(LCD_RW,OUTPUT_PIN);
		DIOsetPinDirection(LCD_EN,OUTPUT_PIN);
		
		_delay_ms(40);
		DIOsetPinValue(LCD_RW,LOW_PIN);
		LCDwriteCommand(LCD_4_BIT_MODE_CMD_1);
		LCDwriteCommand(LCD_4_BIT_MODE_CMD_2);
		LCDwriteCommand(LCD_4_BIT_MODE_CMD_3);
	

	#endif
		LCDwriteCommand(LCD_DISPLAY_ON_CMD);
		LCDwriteCommand(LCD_RETURN_HOME_CMD);
		LCDwriteCommand(LCD_CLR_CMD);	
		_delay_ms(2);
}
void LCDwriteCharacter(u8 character){
	DIOsetPinValue(LCD_RS,HIGH_PIN);
	#if		LCD_MODE   ==   _8_BIT_MODE
		DIOsetPinValue(LCD_PD0,GET_BIT(character,0));
		DIOsetPinValue(LCD_PD1,GET_BIT(character,1));
		DIOsetPinValue(LCD_PD2,GET_BIT(character,2));
		DIOsetPinValue(LCD_PD3,GET_BIT(character,3));
		DIOsetPinValue(LCD_PD4,GET_BIT(character,4));
		DIOsetPinValue(LCD_PD5,GET_BIT(character,5));
		DIOsetPinValue(LCD_PD6,GET_BIT(character,6));
		DIOsetPinValue(LCD_PD7,GET_BIT(character,7));

		DIOsetPinValue(LCD_EN,HIGH);
		_delay_ms(1);
		DIOsetPinValue(LCD_EN,LOW);
	#elif	LCD_MODE   ==   _4_BIT_MODE
		DIOsetPinValue(LCD_PD4,GET_BIT(character,4));
		DIOsetPinValue(LCD_PD5,GET_BIT(character,5));
		DIOsetPinValue(LCD_PD6,GET_BIT(character,6));
		DIOsetPinValue(LCD_PD7,GET_BIT(character,7));
		DIOsetPinValue(LCD_EN,HIGH_PIN);
		_delay_ms(1);
		DIOsetPinValue(LCD_EN,LOW_PIN);
		_delay_ms(1);
		DIOsetPinValue(LCD_PD4,GET_BIT(character,0));
		DIOsetPinValue(LCD_PD5,GET_BIT(character,1));
		DIOsetPinValue(LCD_PD6,GET_BIT(character,2));
		DIOsetPinValue(LCD_PD7,GET_BIT(character,3));
		DIOsetPinValue(LCD_EN,HIGH_PIN);
		_delay_ms(1);
		DIOsetPinValue(LCD_EN,LOW_PIN);
		_delay_ms(5);
	#endif
}
void LCDwriteCommand(u8 cmd){
	DIOsetPinValue(LCD_RS,LOW_PIN);
	#if		LCD_MODE   ==   _8_BIT_MODE
		DIOsetPinValue(LCD_PD0,GET_BIT(cmd,0));
		DIOsetPinValue(LCD_PD1,GET_BIT(cmd,1));
		DIOsetPinValue(LCD_PD2,GET_BIT(cmd,2));
		DIOsetPinValue(LCD_PD3,GET_BIT(cmd,3));
		DIOsetPinValue(LCD_PD4,GET_BIT(cmd,4));
		DIOsetPinValue(LCD_PD5,GET_BIT(cmd,5));
		DIOsetPinValue(LCD_PD6,GET_BIT(cmd,6));
		DIOsetPinValue(LCD_PD7,GET_BIT(cmd,7));

		DIOsetPinValue(LCD_EN,HIGH);
		_delay_ms(1);
		DIOsetPinValue(LCD_EN,LOW);
	#elif	LCD_MODE   ==   _4_BIT_MODE
		DIOsetPinValue(LCD_PD4,GET_BIT(cmd,4));
		DIOsetPinValue(LCD_PD5,GET_BIT(cmd,5));
		DIOsetPinValue(LCD_PD6,GET_BIT(cmd,6));
		DIOsetPinValue(LCD_PD7,GET_BIT(cmd,7));
		DIOsetPinValue(LCD_EN,HIGH_PIN);
		_delay_ms(1);
		DIOsetPinValue(LCD_EN,LOW_PIN);
		_delay_ms(1);
		DIOsetPinValue(LCD_PD4,GET_BIT(cmd,0));
		DIOsetPinValue(LCD_PD5,GET_BIT(cmd,1));
		DIOsetPinValue(LCD_PD6,GET_BIT(cmd,2));
		DIOsetPinValue(LCD_PD7,GET_BIT(cmd,3));
		_delay_ms(1);
		DIOsetPinValue(LCD_EN,LOW_PIN);
		_delay_ms(5);
	#endif
}
void LCDwriteString(u8* string){
	u8 index=0;
	while (string[index]!=NULL){
		LCDwriteCharacter(string[index]);
		index++;
	}
}

void LCDwriteSignedNumber(s32 num){
	s8 numIndex = 0;
	u8 numArr[10] = {0};
	if(num < 0){
		num = num * -1;
		LCDwriteCharacter('-');
	}

	do{
		numArr[numIndex] = num % 10;
		num /= 10;
		numIndex++;
	}while(num != 0);

	while(numIndex > 0){
		LCDwriteCharacter(numArr[--numIndex] + ASCII_DIGIT_OFFSET);
	}
}

void LCDgoTo(u8 row,u8 col){
	u8 rows[2] = {LCD_ROW0_CMD , LCD_ROW1_CMD};
	LCDwriteCommand(rows[row] + col);
}
void LCDclear(void){
	LCDwriteCommand(LCD_CLR_CMD);
}