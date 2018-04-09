
#include "type.h"

#define COLOR	0x002e	

/* header of extern file defined in lib.asm  
void __disp_str(u8_t * string, u32_t  color);
void __init8259(); */

int _begin (u32_t ver)  {
/*
	__disp_str("****************************************************\n", COLOR);
	__disp_str("*               IoTa Version 0.b              *\n", COLOR);
	__disp_str("****************************************************\n", COLOR);*/
	__disp_str("Press a key to start ...", COLOR);

	__init8259();
	
	return 0;
}
