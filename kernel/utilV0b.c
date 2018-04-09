//header of extern file defined in lib.asm  
//void __disp_str(u8_t * string, u32_t  color);
//void __disp_clk(u8_t * string, u32_t color);
//void __init8259(); 

#include "type.h"
#include <stdio.h>
#define	COLOR		0x000e	

int hh,mm,ss,tick;
char clk[8];				//sting for output clock

int _begin ()  {

	//initialize global variables
	hh=0;
	mm=0;
	ss=0;
	tick=0;
	int i,j;

	//print name, OS LOGO, lines etc.,
	__disp_str("         \xC9", COLOR);			//NW corner
	for(i=0;i<60;i++)
		__disp_str("\xCD", COLOR);			//double horizon line
	__disp_str("\xBB        \n", COLOR);		//NE corner
	
	__disp_str("         \xBA               Jingjing Zhou's OS Version 0.b               \xBA        \n", COLOR);
        ;i++;
	__disp_str("         \xC8", COLOR);			//SW corner
	for(i=0;i<60;i++)
		__disp_str("\xCD", COLOR);			//double horizon line
	__disp_str("\xBC        \n", COLOR);		//SE corner

	__init8259();								//initialize 8259
	
	return 0;
}

void  _inc_clock(){

	tick=tick+1;				//increase tick

	//reach a second, reprint the clock
	if(tick%18==0){
		ss=ss+1;
		if(ss==60){
			ss=0;
			mm=mm+1;
			if(mm==60){
				mm=0;
				hh=hh+1;
				if(hh==25){
					hh=0;
					mm=0;
					ss=0;
				}
			}
		}

		//construct output string for clock
//		if(hh<10)
//			sprintf(clk,"0%d",hh);
//		else
//			sprintf(clk,"%d",hh);
//		if(mm<10)
//			sprintf(clk,":0%d:",mm);
//		else
//			sprintf(clk,":%d:",mm);
//		if(ss<10)
//			sprintf(clk,"0%d",ss);
//		else
//			sprintf(clk,"%d",ss);

		clk[0]=hh/10;
		clk[1]=hh%10;
		clk[2]=':';
		clk[3]=mm/10;
		clk[4]=mm%10;
		clk[5]=':';
		clk[6]=ss/10;
		clk[7]=ss%10;
		//update the clock
		__disp_clk(clk, COLOR);
	}
}
