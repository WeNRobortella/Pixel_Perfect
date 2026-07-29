#ifndef DELTA_TIME_H
#define DELTA_TIME_H
#include "sys.h"

#define SECOND_SCALE 1000

void DeltaTime_Init(void);
u16 Get_DeltaTime(void);
void DeltaTime_Tick(void);

#endif