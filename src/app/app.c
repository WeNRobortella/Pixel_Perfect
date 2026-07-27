/* -----------------------------------------------------------------------------
 *  Project : DWIN-T5L-SDCC-Template
 *  File    : app.c
 *  Author  : Recep Şenbaş (https://github.com/recepsenbas)
 *  License : CC BY-NC-SA 4.0 (https://creativecommons.org/licenses/by-nc-sa/4.0/)
 *  Contact : recepsenbas@gmail.com
 *  Description :
 *    Application layer entry point. This file contains user-defined logic,
 *    DGUS event handling, and system-level coordination functions.
 *    Use this space to implement project-specific behavior and extend
 *    the base template with your own features.
 * ----------------------------------------------------------------------------- */
#include "t5l1.h"
#include "uart.h"
#include "sys.h"
#include "timer.h"
#include "rtc.h"

#include "DeltaTime.h"
#include "ButtonConfig.h"
#include "MovementComponent.h"
#include "PlayerCharacter.h"

#define SECOND_SCALE 1000
#define SCREEN_WIDTH 0x01E0
#define SCREEN_HEIGHT 0x0110

// idata u16 Debugger = 0x3000;




// xdata u16 PlayerCurrentPosition = 0x0000;
// xdata u8 MovementAxisCheck = 0x00;

// xdata u16 XAxisMovementLimit = SCREEN_WIDTH - 0x064;
// xdata u16 YAxisMovementLimit = SCREEN_HEIGHT - 0x064;

// void CheckPlayerMovement(u16 ButtonVP, u16 PlayerCurrentPositionAddress, u16 AxisMovementLimit);

void App_Init(void)
{
	DeltaTime_Init();
	ControllerSetup();
	DefinePlayerAttributes();
}

void App_Update(void)
{
	DeltaTime_Tick();
	InterfaceCheck();
	PlayerCharacter_Tick();

        // CheckPlayerMovement(XButtonVP, PlayerXPositionOffset, XAxisMovementLimit);
		// if (ButtonPressed == 0x0000)
		// {
		// 	if (!MovementAxisCheck)
		// 	{
		// 		PositionAccumulator = 0;
		// 		MovementAxisCheck = 0x01;
		// 		LastButtonPressed = 0x0000;
		// 	}
		// 	CheckPlayerMovement(YButtonVP, PlayerYPositionOffset, YAxisMovementLimit);
		// }
}

// void CheckPlayerMovement(u16 ButtonVP, u16 PlayerCurrentPositionAddress, u16 AxisMovementLimit)
// {
// 	PlayerCurrentPositionAddress += PlayerSP;
// 	sys_read_vp(ButtonVP, (u8*)&ButtonPressed, 0x0001);
// 	if (ButtonPressed != 0x0000)
// 	{
// 		if (ButtonVP == XButtonVP && MovementAxisCheck)
// 		{
// 			PositionAccumulator = 0;
// 			MovementAxisCheck = 0x00;
// 			LastButtonPressed = 0x0000;
// 		}
// 		sys_read_vp(PlayerCurrentPositionAddress, (u8*)&PlayerCurrentPosition, 0x0001);
// 		DistanceToMove = (u32)PlayerSpeed * DeltaTime;
// 		if (ButtonPressed == 0x0001)
// 		{
// 			if (ButtonPressed != LastButtonPressed)
// 				PositionAccumulator = 0;
// 			PlayerNewPosition = (u32)PlayerCurrentPosition + DistanceToMove / SECOND_SCALE;
// 		}
// 		else if (ButtonPressed == 0x0002)
// 		{
// 			if (ButtonPressed != LastButtonPressed)
// 				PositionAccumulator = 0;
// 			PlayerNewPosition = (u32)PlayerCurrentPosition - DistanceToMove / SECOND_SCALE;
// 		}
// 		PositionAccumulator += DistanceToMove % SECOND_SCALE;
// 		if (PositionAccumulator >= SECOND_SCALE)
// 		{
// 			if (ButtonPressed == 0x0001)
// 			{
// 				PlayerNewPosition += PositionAccumulator / SECOND_SCALE;
// 			} else if (ButtonPressed == 0x0002)
// 			{
// 				PlayerNewPosition -= PositionAccumulator / SECOND_SCALE;
// 			}
// 			PositionAccumulator %= SECOND_SCALE;
// 		}
// 		PlayerCurrentPosition = (u16)PlayerNewPosition;
// 		if (PlayerCurrentPosition > AxisMovementLimit)
// 		{
// 			if (ButtonPressed == 0x0001
// 			{
// 				PlayerCurrentPosition = AxisMovementLimit;
// 			}
// 			else
// 			{
// 				PlayerCurrentPosition = 0x0000;
// 			}
// 		}
// 		sys_write_vp(PlayerCurrentPositionAddress, (u8*)&PlayerCurrentPosition, 0x0001);
// 		sys_write_vp(Debugger, (u8*)&PlayerCurrentPosition, 0x0001);
// 		LastButtonPressed = ButtonPressed;
// 	}
// }