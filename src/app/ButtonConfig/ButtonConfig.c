#include "ButtonConfig.h"

__xdata u16 ButtonPressed = NO_BUTTON;

void ControllerSetup(void)
{
    ButtonRegister(BUTTON_UP);
    ButtonRegister(BUTTON_DOWN);
    ButtonRegister(BUTTON_LEFT);
    ButtonRegister(BUTTON_RIGHT);
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