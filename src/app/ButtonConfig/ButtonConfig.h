#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H
#include "sys.h"
#include "Controller.h"

#define CONTROLLER_INTERFACE 0x2000

typedef enum
{
    NO_BUTTON,
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_INDEX
} ButtonID_t;

extern __xdata u16 ButtonPressed;

void ControllerSetup(void);
void InterfaceCheck(void);

#endif