#ifndef __DIGTUBE_H_
#define __DIGTUBE_H_
#include <STC89C5xRC.H>

#define DIGTUBE_CON P4
#define DIGTUBE_SEG P0

void DigTube_Display() ;
void DigTube_LoadNum(unsigned int num) ;
#endif 
