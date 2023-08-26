/*
 * CFG_interface.c
 *
 * Created: 8/26/2023 8:23:03 AM
 *  Author: MAHMOUD
 */ 

#include "CFG_interface.h"

//function prototype


uint8_t Valid_Frame(char* str){
	if(str[7]=='E' && str[8]=='\0'){
		return 1;	
	}
	else{
		return 0;
	}
}

		
