#include "DeltaTime.h"

static __idata u16 PreviousTime = 0;
static __idata u16 CurrentTime = 0;
static __idata u16 DeltaTime = 0;

void DeltaTime_Init(void)
{
    PreviousTime = sys_tick_ms;
}

u16 Get_DeltaTime(void)
{
    return DeltaTime;
}

void DeltaTime_Tick(void)
{
    CurrentTime = sys_tick_ms;
    DeltaTime = CurrentTime - PreviousTime;
    if (DeltaTime > 100)
	    DeltaTime = 100;
    PreviousTime = CurrentTime;
}