#include <STC89C5xRC.H>
#include "mpu6050.h"
#include "digtube.h"
//*********************************************************
//主程序
//*********************************************************
void main()
{
	unsigned int i = 1234;
	delay(500);		//上电延时

	InitMPU6050();	//初始化MPU6050
	delay(150);
	DigTube_LoadNum(i);
	while(1)
	{

		DigTube_Display();
	}
}