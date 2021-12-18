#include <STC89C5xRC.H>
#include "mpu6050.h"

//*********************************************************
//主程序
//*********************************************************
void main()
{
	delay(500);		//上电延时
//	InitLcd();		//液晶初始化
	InitMPU6050();	//初始化MPU6050
	delay(150);
	while(1)
	{
		GetData(ACCEL_XOUT_H);

		delay(500 );
	}
}