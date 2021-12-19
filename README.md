# SimpleGradienter

---

## Describe

1. This is a SimpleGradienter using 
   
   * STC89C52RC 
   
   * MPU6050 Accelerometer
   
   * Digital Tube x 4 (for display)

2. Pin Configuration
   
   * P10 -> MPU6050 SCL
   
   * P11 -> MPU6050 SDA
   
   * P0   -> Digital Tube Segments
   
   * P4   -> Digital Tube Select

3. Notice
   
   * If you using other MCU, Please change  `Delay5us(void)` in `mpu6050.c` to meet timing requirement

## 简介

1. 简单的水平仪,如下为所用的器件表
   
   * STC89C52RC
   
   * MPU6050 陀螺仪
   
   * 4位数码管

2. 引脚定义
   
   * P10 -> MPU6050 SCL
   
   * P11 -> MPU6050 SDA
   
   * P0   -> 数码管段选
   
   * P4   -> 数码管位选

3. 注意
   
   * 如果使用其他的MCU记得修改`mpu6050.c` 中的`Delay5us(void)` 来满足时序要求
