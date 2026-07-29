#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "sys.h"

#define MAX_BUTTONS 30

typedef void (*ButtonCall)(s8 Polarity, u16 MovementAxis) __reentrant;

typedef struct
{
	s8 Polarity;
	u16 MovementAxis;
	ButtonCall OnPress;
	ButtonCall OnRelease;
} ButtonDef;

void Controller_Init(void);
void ButtonRegister(u8 ID, s8 Polarity, u16 MovementAxis);
void ButtonBindOnPress(u8 ID, ButtonCall FunCall);
void ButtonBindOnRelease(u8 ID, ButtonCall FunCall);
void GetButton(u8 ID, u8 Trigger);

#endif