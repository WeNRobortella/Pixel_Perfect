#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "sys.h"

#define MAX_BUTTONS 30

typedef void (*ButtonCall)(void);

typedef struct
{
	u8 IsRegistered;
	ButtonCall OnPress;
	ButtonCall OnRelease;
} ButtonDef;

void ButtonRegister(u8 ID);
void ButtonBindOnPress(u8 ID, ButtonCall FunCall);
void ButtonBindOnRelease(u8 ID, ButtonCall FunCall);
void GetButton(u8 ID, u8 Trigger);

#endif