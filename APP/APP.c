/*
 * test 2.c
 *
 * Created: 8/26/2023 4:25:26 AM
 * Author : MAHMOUD
 */ 

#include "APP.h"

uint8_t Valid_Frame();
int main(void)
{
	UART_Init();
    LCD_init();
    
	while (1)  // XXXAYYBE
    {
			char str[10]={0};
		UART_RecieveString(str);
		while( !Valid_Frame(str) ){
			UART_RecieveString(str);
		}

		LCD_write_string("SPEED: ");
		LCD_write_char(str[0]);		
		LCD_write_char(str[1]);
		LCD_write_char(str[2]);
		LCD_write_string("% Direction: ");
		if(str[3] == 'F'){
			LCD_write_char('+');
		}else{
			LCD_write_char('-');
		}
		LCD_write_char(str[4]);
		LCD_write_char(str[5]);
		LCD_write_command(0xC0);
		LCD_write_string("   Time:");  
		
		//print a simple digital clock
		
		uint16_t hr=0;
		uint16_t mm=0;
		uint16_t ss=0;
		for(hr=0;hr<=24;hr++) {
			for(mm=0;mm<=59;mm++){
				for(ss=0;ss<=59;ss++){
					LCD_write_num((hr/10));
					LCD_write_num((hr%10));
					LCD_write_char(':');
					LCD_write_num((mm/10));
					LCD_write_num((mm%10));
					LCD_write_char(':');
					LCD_write_num((ss/10));
					LCD_write_num((ss%10));
					LCD_write_string(" AM");
					_delay_ms(1000);
					LCD_write_command(0xC8);
				}
			}
		}
	
		
		
		
	}
    
}

