/*
 * UART.h
 *
 * Created: 8/26/2023 3:09:15 AM
 *  Author: MAHMOUD
 */ 


#ifndef UART_H_
#define UART_H_

#include "generic_macros_header.h"

//function prototype

void UART_Init(void);
void UART_SendByte(const char data);
char UART_RecieveByte(void);
void UART_SendString(const char *str);
void UART_RecieveString(char* str);  




#endif /* UART_H_ */