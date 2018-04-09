
#include "type.h"

#define COLOR	0x001a	

/* header of extern file defined in lib.asm  
void __disp_str(u8_t * string, u32_t  color);
void __init8259(); */

int  lasp_time=18;
int ticks;
int hour, minute, second;
char *time ="00:00:00";


int _begin (u32_t ver)  {

	__disp_str("\n\n\n\n\n\n\n\n\n\xFF\xFF\xFF\xFF\xFF\xB2\xFF\xFF\xB2\xFF\xFF\xB2\xB2\xFF\n\xFF\xFF\xFF\xFF\xFF\xB2\xB2\xB2\xFF\xFF\xB2\xFF\xFF\xB2\n\xFF\xFF\xFF\xFF\xFF\xB2\xB2\xB2\xFF\xFF\xB2\xFF\xFF\xB2\n\xFF\xFF\xFF\xFF\xFF\xB2\xFF\xFF\xB2\xFF\xFF\xB2\xB2\xFF\n", COLOR);	
        __disp_str(" \xFF\xFF\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n\xFF\xFF\xFF\xBA\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xBA\n\xFF\xFF\xFF\xBA", COLOR);
	__disp_str("(c) CaoLing's OS", COLOR);
	__disp_str(" \xFF\xFF\xFF\xFF\xBA\n", COLOR);
	__disp_str(" \xFF\xFF\xBA\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xBA\n \xFF\xFF\xBA\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xBA\n\xFF\xFF\xFF\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n", COLOR);
	
	time ="00:00:00";

	__init8259();
	ticks=0;
	return 0;
}

void _inc_clock(){
ticks=ticks+1;
		if(ticks==18){
			ticks = 0;
			time[7]= time[7] + 1;
			if(time[7] == 58)
				{ 
					time[7] = 48;
					time[6] = time[6]+1;
					if(time[6]==54)

				{ 	time[6] =48;
					time[4]=time[4]+1;
					if(time[4]==58)
						{
							time[4]=48;
							time[3]=time[3]+1;
							if(time[3]==54){
								time[3]=48;
									time[1]=time[1]+1;
									if(time[0]==50 && time[1]==52)
									{
										time[0]=48;
										time[1]=48;
										}
											else if(time[1] ==58)
											{
												time[1]=48;
												time[0]=time[0]+1;
													}
												}
											}
										}
									}
							}
        __disp_clk(time,COLOR);

	}

										

					

			



