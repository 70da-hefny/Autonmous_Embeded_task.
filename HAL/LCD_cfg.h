/*
 * LCD_cfg.h
 *
 * Created: 8/25/2023 4:52:46 AM
 *  Author: MAHMOUD
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "generic_macros_header.h"

#define LCD_CFG_PINS DDRA|=0b111111100 // macro that configures pins 2->7 as OUTPUT pins 

#define RS(X) if( X == 0 ) CLRBIT(PORTA,PA2) ; else SETBIT(PORTA,PA2) ; // to make the Driver generic as much as i can
#define EN(X) if( X == 0 ) CLRBIT(PORTA,PA3) ; else SETBIT(PORTA,PA3) ;
#define D4(X) if( X == 0 ) CLRBIT(PORTA,PA4) ; else SETBIT(PORTA,PA4) ;
#define D5(X) if( X == 0 ) CLRBIT(PORTA,PA5) ; else SETBIT(PORTA,PA5) ;
#define D6(X) if( X == 0 ) CLRBIT(PORTA,PA6) ; else SETBIT(PORTA,PA6) ;
#define D7(X) if( X == 0 ) CLRBIT(PORTA,PA7) ; else SETBIT(PORTA,PA7) ;


#endif /* LCD_CFG_H_ */