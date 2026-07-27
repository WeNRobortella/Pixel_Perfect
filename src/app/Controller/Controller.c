#include "Controller.h"

static __xdata ButtonDef ButtonList[MAX_BUTTONS] = {0};

void ButtonRegister(u8 ID)
{
	ButtonList[ID].OnPress = 0;
	ButtonList[ID].OnRelease = 0;
}

void ButtonBindOnPress(u8 ID, ButtonCall FunCall)
{
	ButtonList[ID].OnPress = FunCall;
}

void ButtonBindOnRelease(u8 ID, ButtonCall FunCall)
{
	ButtonList[ID].OnRelease = FunCall;
}

void GetButton(u8 ID, u8 Trigger)
{
	if (ID == 0) return;
	if (Trigger)
	{
		ButtonList[ID].OnPress();
	}
	else
	{
		ButtonList[ID].OnRelease();
	}
		
}