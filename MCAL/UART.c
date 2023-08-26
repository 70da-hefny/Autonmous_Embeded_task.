/*
 * UART.c
 *
 * Created: 8/26/2023 3:08:42 AM
 * Author : MAHMOUD
 */ 

#include "UART.h"

// function implementation

/********************************************************
* function: UART_Init
* purpose:  initialize UART 
* parameters: void
* return value: void
********************************************************/

void UART_Init(void){

SETBIT(UCSRA,U2X); // enable double transmitting speed
SETBIT(UCSRB,TXEN);  SETBIT(UCSRB,RXEN); // enable UART as transmitter and receiver.
SETBIT(UCSRC,URSEL); SETBIT(UCSRC,UCSZ1); SETBIT(UCSRC,UCSZ0); // the frame : 8-bit date , no parity , 1 stop -> ASYN
 /* baud rate=9600 & Fosc=1MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */  
UBRRL = 12;
UBRRH=0;
}


/********************************************************
* function: UART_SendByte
* purpose:  sent Byte via UART
* parameters: char
* return value: void
********************************************************/


void UART_SendByte(const char data){
	while((UCSRA & (1<<UDRE)) == 0){} //UDRE flag is set when the buffer is empty and ready for transmitting
	UDR = data;
}

/********************************************************
* function: UART_RecieveByte
* purpose:  Recieve Byte via UART
* parameters: void
* return value: void
********************************************************/


char UART_RecieveByte(void){
	while((UCSRA & (1<<RXC)) == 0){} //RXC flag is set when the UART is ready to receive data
	return UDR;
}

/********************************************************
* function: UART_SendString
* purpose:  send string via UART
* parameters: pointer to constant char
* return value: void
********************************************************/


void UART_SendString(const char *str){
	uint8_t i=0;
	while(str[i]!='\0'){
		UART_SendByte(str[i++]);
	}	
}


/********************************************************
* function: UART_RecieveString
* purpose:  receive string via UART
* parameters: pointer to char
* return value: void
********************************************************/

void UART_RecieveString(char* str){
	uint8_t i =0;
	str[i]=UART_RecieveByte();
	while(str[i]!='E') //        'E' ---> the end of string
	{
	i++;	  
	str[i]=UART_RecieveByte();
	}
}
