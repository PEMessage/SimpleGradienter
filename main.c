#include <STC89C5xRC.H>
#include "mpu6050.h"
#include "digtube.h"
//*********************************************************
//������
//*********************************************************
void main()
{
	unsigned int i = 1234;
	delay(500);		//�ϵ���ʱ

	InitMPU6050();	//��ʼ��MPU6050
	delay(150);
	DigTube_LoadNum(i);
	while(1)
	{

		DigTube_Display();
	}
}