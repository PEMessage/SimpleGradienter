#include "digtube.h"


static unsigned char  dec_list[10]  ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};// 显示段码值0~9
static unsigned char  control_code[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//分别对应相应的数码管点亮,即位码


unsigned char digtube_buffer[4] ={0} ;

static void delay_dig(unsigned int i)
{
	while(i--);	
}   
	
void DigTube_Display()
{
	unsigned char i=0;
	for(i=0;i<4;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{

			case(0):
				DIGTUBE_CON= control_code[2]; break;//显示第1位
			case(1):
				DIGTUBE_CON= control_code[3];break;//显示第2位
			case(2):
				DIGTUBE_CON= control_code[1];break;//显示第3位
			case(3):
				DIGTUBE_CON= control_code[0];break;//显示第4位
		}
		DIGTUBE_SEG=digtube_buffer[i];//发送段码
		delay_dig(100); //间隔一段时间扫描	
		DIGTUBE_SEG=0x00;//消隐
	}
} 

void DigTube_LoadNum(unsigned int num)
{
	    int temp = num ;
			 digtube_buffer[0]=dec_list[ (temp/1000) %10];
			 digtube_buffer[1]=dec_list[ (temp/100)  %10];
			 digtube_buffer[2]=dec_list[ (temp/10)   %10];
			 digtube_buffer[3]=dec_list[ (temp/1)    %10];
			return ;
}

void DigTube_LoadDirection(enum direction dir)
{
	switch(dir)
	{
		case CENTER : digtube_buffer[0] = 0x00; digtube_buffer[1] = 0x40; digtube_buffer[2] = 0x40; digtube_buffer[3] = 0x00; break;
		case RIGHT  : digtube_buffer[0] = 0x00; digtube_buffer[1] = 0x00; digtube_buffer[2] = 0x00; digtube_buffer[3] = 0x06; break;
		case UP     : digtube_buffer[0] = 0x00; digtube_buffer[1] = 0x01; digtube_buffer[2] = 0x01; digtube_buffer[3] = 0x00; break;
		case LEFT   : digtube_buffer[0] = 0x30; digtube_buffer[1] = 0x00; digtube_buffer[2] = 0x00; digtube_buffer[3] = 0x00; break;
		case DOWN   : digtube_buffer[0] = 0x00; digtube_buffer[1] = 0x08; digtube_buffer[2] = 0x08; digtube_buffer[3] = 0x00; break;
	}
}