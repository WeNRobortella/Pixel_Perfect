#include "PlayerCharacter.h"

void DefinePlayerAttributes(void)
{
    Player.PlayerSP = 0x7800;
    Player.PlayerSpeed = 0x0096;
    Player.PlayerSize = 0x0064;
}

void PlayerCharacter_Tick(void)
{
    UpdatePosition();
}