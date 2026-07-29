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

// idata u16 Debugger = 0x3000;
// xdata u8 MovementAxisCheck = 0x00;

void App_Init(void)
{
	DeltaTime_Init();
	ControllerSetup();
	DefineMovementComponent();
	DefinePlayerAttributes();
}

void App_Update(void)
{
	DeltaTime_Tick();
	InterfaceCheck();
}