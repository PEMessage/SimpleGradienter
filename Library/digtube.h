#ifndef __DIGTUBE_H_
#define __DIGTUBE_H_
#include <STC89C5xRC.H>

#define DIGTUBE_CON P4
#define DIGTUBE_SEG P0

typedef enum direction {CENTER=0 , RIGHT=1 , UP=2 , LEFT=3 , DOWN = 4} ;

void DigTube_Display() ;
void DigTube_LoadNum(unsigned int num) ;
void DigTube_LoadDirection(enum direction dir) ;
#endif 
