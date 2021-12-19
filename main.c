#include <STC89C5xRC.H>
#include "mpu6050.h"
#include "digtube.h"
#include "math.h"
//*********************************************************
//主程序
//*********************************************************
void main(void)
{
	long x = 0;
	long y = 0;
	long z = 0 ;
	long abs = 1 ;
	
	long abs_x ;
	long abs_y ;

	//unsigned int i = 1234;
	delay(500);		//上电延时
	InitMPU6050();	//初始化MPU6050
	delay(150);

	
	//DigTube_LoadNum(i);
	while(1)
	{
		x = GetData(ACCEL_XOUT_H) ;
		y = GetData(ACCEL_YOUT_H) ;
		z = GetData(ACCEL_ZOUT_H) ;
		
		abs = sqrt( x*x + y*y + z*z ) ;

		x = x*100 ;
		y = y*100 ;
		z = z*100 ;
		
		abs_x = x>=0 ? x : -x ;
		abs_y = y>=0 ? y : -y ;

		if( (z/abs) > 95 )
		{
			DigTube_LoadDirection(0);
		}
		else if( abs_x>abs_y  )
		{
			if(x>0){DigTube_LoadDirection(DOWN);}
			if(x<0){DigTube_LoadDirection(UP  );}
		}
		else if(abs_x<abs_y)
		{
			if(y>0){DigTube_LoadDirection(RIGHT);}
			if(y<0){DigTube_LoadDirection(LEFT );}
		}
		
		DigTube_Display();
	}
	return ;
}