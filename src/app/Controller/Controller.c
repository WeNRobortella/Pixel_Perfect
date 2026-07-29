#include "Controller.h"

static __xdata ButtonDef ButtonList[MAX_BUTTONS];

void Controller_Init(void)
{
	u8 i;
	for (i = 0; i < MAX_BUTTONS; i++)
	{
		ButtonList[i].OnPress = 0;
		ButtonList[i].OnRelease = 0;
	}
}

void ButtonRegister(u8 ID, s8 Polarity, u16 MovementAxis)
{
	ButtonList[ID].Polarity = Polarity;
	ButtonList[ID].MovementAxis = MovementAxis;
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
		if (ButtonList[ID].OnPress != 0)
			ButtonList[ID].OnPress(ButtonList[ID].Polarity, ButtonList[ID].MovementAxis);
	}
	else
	{
		if (ButtonList[ID].OnRelease != 0)
			ButtonList[ID].OnRelease(ButtonList[ID].Polarity, ButtonList[ID].MovementAxis);
	}
		
}