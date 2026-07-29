#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H
#include "sys.h"

void DefineMovementComponent(void);
void UpdatePosition(s8 Polarity, u16 MovementAxis) __reentrant;

#endif