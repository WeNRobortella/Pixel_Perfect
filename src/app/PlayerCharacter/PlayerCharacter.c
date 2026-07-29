#include "PlayerCharacter.h"
#include "Controller.h"
#include "ButtonConfig.h"
#include "MovementComponent.h"

CharacterAttributes __xdata Player;

void DefinePlayerAttributes(void)
{
    Player.PlayerSP = 0x7800;
    Player.PlayerSpeed = 0x0096;
    Player.PlayerSize = 0x0064;
    ButtonBindOnPress(BUTTON_UP, UpdatePosition);
    ButtonBindOnPress(BUTTON_DOWN, UpdatePosition);
    ButtonBindOnPress(BUTTON_LEFT, UpdatePosition);
    ButtonBindOnPress(BUTTON_RIGHT, UpdatePosition);
}

void PlayerCharacter_Tick(void)
{

}

