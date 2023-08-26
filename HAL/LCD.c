/*
 * LCD.c
 *
 * Created: 8/22/2023 3:09:50 PM
 *  Author: MAHMOUD
 */ 

#include "LCD.h"
#include "LCD_cfg.h"
// functions implementation



/********************************************************
* function: LCD_init
* purpose:   Configure 6 pins as OUTPUT,initiate LCD by several commands (e.g. 4-bit mode) 
* parameters: void
* return value: void
********************************************************/



void LCD_init(void){
	LCD_CFG_PINS;
	LCD_write_command(0x3); 
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x8);
	LCD_write_command(0x1);
	LCD_write_command(0x6);
	LCD_write_command(0xc);
	_delay_ms(20);
	
	
	
}



/********************************************************
* function: LCD_write_command
* purpose:  send command to LCD
* parameters: cmd
* return value: void
********************************************************/


void LCD_write_command(uint8_t cmd){
	RS(0);
	D7(READBIT(cmd,7));
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	



}


/********************************************************
* function: LCD_write_num
* purpose:  print a number on LCD 
* parameters: void
* return value: void

********************************************************/

void LCD_write_num(uint16_t Num){
	uint8_t NumDigits[5];
	int8_t i=0;
	
	if(Num==0){
		LCD_write_char(48);
		return;
	}
	
	for( i=0 ; Num !=0 ;i++){
		NumDigits[i]= Num%10 +48 ; // 123--->3  and  convert it to ASCII
		Num /=10;
	}
	i--;
	while(i>=0){
		LCD_write_char(NumDigits[i]);
		i--;
	}
}


/********************************************************
* function: LCD_write_char
* purpose:  print char on LCD
* parameters: data
* return value: void
********************************************************/


void LCD_write_char(uint8_t data){
	RS(1);
	D7(READBIT(data,7));
	D6(READBIT(data,6));
	D5(READBIT(data,5));
	D4(READBIT(data,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
	D7(READBIT(data,3));
	D6(READBIT(data,2));
	D5(READBIT(data,1));
	D4(READBIT(data,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
}


/********************************************************
* function: LCD_write_string
* purpose:  print string on LCD
* parameters: Str
* return value: void
********************************************************/


void LCD_write_string(uint8_t* Str){
	uint8_t i=0;
	for( i=0 ; Str[i] != '\0' ; i++ ){
	LCD_write_char(Str[i]);		
	}
}

