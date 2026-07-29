#include "ButtonConfig.h"

__xdata u16 ButtonPressed = NO_BUTTON;

void ControllerSetup(void)
{
    Controller_Init();
    ButtonRegister(BUTTON_UP, -1, Y_POSITION_SP_OFFSET);
    ButtonRegister(BUTTON_DOWN, 1, Y_POSITION_SP_OFFSET);
    ButtonRegister(BUTTON_LEFT, -1, X_POSITION_SP_OFFSET);
    ButtonRegister(BUTTON_RIGHT, 1, X_POSITION_SP_OFFSET);
}

void InterfaceCheck(void)
{
    __xdata u16 TriggerValue = 0x0000;
    if (ButtonPressed > 0x0000)
    {
        TriggerValue = ButtonPressed;
    }
    ButtonPressed = DGUS_Read_VP(CONTROLLER_INTERFACE);
    if (ButtonPressed == 0x0000 && TriggerValue > 0x0000)
    {
        GetButton(TriggerValue, ButtonPressed);
        return;
    }
    else
    {
        TriggerValue = ButtonPressed;
    }
    GetButton(ButtonPressed, TriggerValue);
}