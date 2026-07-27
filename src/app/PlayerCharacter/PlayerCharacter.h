#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include "sys.h"

typedef struct
{
	u16 PlayerSP;
	u16 PlayerSpeed;
	u16 PlayerSize;
} CharacterAttributes;

extern CharacterAttributes __xdata Player;

void DefinePlayerAttributes(void);
void PlayerCharacter_Tick(void);

#endif