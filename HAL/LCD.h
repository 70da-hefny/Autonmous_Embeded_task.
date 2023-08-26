/*
 * LCD.h
 *
 * Created: 8/22/2023 3:10:06 PM
 *  Author: MAHMOUD
 */ 


#ifndef LCD_H_
#define LCD_H_

#define FIRST_LINE(x)  (0x80 + x)
#define SECOND_LINE(x)  (0xC0 + x)
#include "generic_macros_header.h"

//functions prototype 

void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_num(uint16_t);
void LCD_write_char(uint8_t);
void LCD_write_string(uint8_t*);

 




#endif /* LCD_H_ */