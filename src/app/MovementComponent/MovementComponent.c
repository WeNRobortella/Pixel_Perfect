#include "MovementComponent.h"
#include "GameInstance.h"
#include "PlayerCharacter.h"
#include "DeltaTime.h"
#include "ButtonConfig.h"

static __xdata s16 PositionAccumulator = 0x0000;
static __xdata s16 XAccumulator = 0x0000;
static __xdata s16 YAccumulator = 0x0000;
static __xdata s16 PlayerCurrentPosition = 0x0000;
static __xdata s16 PlayerNewPosition = 0x0000;
static __xdata s32 DistanceToMove = 0x0000;
static __xdata s16 AxisMovementLimit = 0x0000;
static __xdata s16 XAxisMovementLimit = SCREEN_WIDTH;
static __xdata s16 YAxisMovementLimit = SCREEN_HEIGHT;

void DefineMovementComponent(void)
{
    XAxisMovementLimit -= Player.PlayerSize;
    YAxisMovementLimit -= Player.PlayerSize;
}

void UpdatePosition(s8 Polarity, u16 MovementAxis) __reentrant 
{
u16 PlayerCurrentPositionAddress = Player.PlayerSP + MovementAxis;
// sys_read_vp(ButtonVP, (u8*)&ButtonPressed, 0x0001);
// if (ButtonPressed != 0x0000)
// {
//     if (ButtonVP == XButtonVP && MovementAxisCheck)
//     {
//         PositionAccumulator = 0;
//         MovementAxisCheck = 0x00;
//         LastButtonPressed = 0x0000;
//     }
    PlayerCurrentPosition = DGUS_Read_VP(PlayerCurrentPositionAddress);
    DistanceToMove = (s32)Player.PlayerSpeed * Polarity * (s32)Get_DeltaTime();
    // if (ButtonPressed == 0x0001)
    // {
        // if (ButtonPressed != LastButtonPressed)
            // PositionAccumulator = 0;
        PlayerNewPosition = PlayerCurrentPosition + DistanceToMove / SECOND_SCALE;
    // }
    // else if (ButtonPressed == 0x0002)
    // {
        // if (ButtonPressed != LastButtonPressed)
        //     PositionAccumulator = 0;
    //     PlayerNewPosition = (u32)PlayerCurrentPosition - DistanceToMove / SECOND_SCALE;
    // }
    if (MovementAxis == X_POSITION_SP_OFFSET)
    {
        AxisMovementLimit = XAxisMovementLimit;
        XAccumulator += DistanceToMove % SECOND_SCALE;
        if (XAccumulator >= SECOND_SCALE || XAccumulator <= (SECOND_SCALE * -1))
        {
            PositionAccumulator = XAccumulator / SECOND_SCALE;
            XAccumulator %= SECOND_SCALE;
        }
    }
    else
    {
        AxisMovementLimit = YAxisMovementLimit;
        YAccumulator += DistanceToMove % SECOND_SCALE;
        if (YAccumulator >= SECOND_SCALE || YAccumulator <= (SECOND_SCALE * -1))
        {
            PositionAccumulator = YAccumulator / SECOND_SCALE;
            YAccumulator %= SECOND_SCALE;
        }
    }
    
    if (PositionAccumulator != 0x0000)
    {
        // if (ButtonPressed == 0x0001)
        // {
            PlayerNewPosition += PositionAccumulator;
        // }
        // else if (ButtonPressed == 0x0002)
        // {
        //     PlayerNewPosition -= PositionAccumulator / SECOND_SCALE;
        // }
        PositionAccumulator = 0x0000;
    }
    PlayerCurrentPosition = PlayerNewPosition;
    if (PlayerCurrentPosition > AxisMovementLimit)
    {
        PlayerCurrentPosition = AxisMovementLimit;
    }
    else if (PlayerCurrentPosition < 0x0000)
    {
         PlayerCurrentPosition = 0x0000;
    }
    DGUS_Write_VP(PlayerCurrentPositionAddress, PlayerCurrentPosition);
    // sys_write_vp(Debugger, (u8*)&PlayerCurrentPosition, 0x0001);
    // LastButtonPressed = ButtonPressed;
}

//     if (ButtonPressed == 0x0000)
//     {
//         if (!MovementAxisCheck)
//         {
//             PositionAccumulator = 0;
//             MovementAxisCheck = 0x01;
//             LastButtonPressed = 0x0000;
//         }
//         CheckPlayerMovement(YButtonVP, PlayerYPositionOffset);
//     }
// }

// void CheckPlayerMovement(u16 ButtonVP, u16 PlayerCurrentPositionAddress, u16 AxisMovementLimit)
// {
//     u16 PlayerCurrentPositionAddress = Player.PlayerSP + MovementAxis;
//     sys_read_vp(ButtonVP, (u8*)&ButtonPressed, 0x0001);
//     if (ButtonPressed != 0x0000)
//     {
//         if (ButtonVP == XButtonVP && MovementAxisCheck)
//         {
//             PositionAccumulator = 0;
//             MovementAxisCheck = 0x00;
//             LastButtonPressed = 0x0000;
//         }
//         sys_read_vp(PlayerCurrentPositionAddress, (u8*)&PlayerCurrentPosition, 0x0001);
//         DistanceToMove = (u32)PlayerSpeed * DeltaTime;
//         if (ButtonPressed == 0x0001)
//         {
//             if (ButtonPressed != LastButtonPressed)
//                 PositionAccumulator = 0;
//             PlayerNewPosition = (u32)PlayerCurrentPosition + DistanceToMove / SECOND_SCALE;
//         }
//         else if (ButtonPressed == 0x0002)
//         {
//             if (ButtonPressed != LastButtonPressed)
//                 PositionAccumulator = 0;
//             PlayerNewPosition = (u32)PlayerCurrentPosition - DistanceToMove / SECOND_SCALE;
//         }
//         PositionAccumulator += DistanceToMove % SECOND_SCALE;
//         if (PositionAccumulator >= SECOND_SCALE)
//         {
//             if (ButtonPressed == 0x0001)
//             {
//                 PlayerNewPosition += PositionAccumulator / SECOND_SCALE;
//             } else if (ButtonPressed == 0x0002)
//             {
//                 PlayerNewPosition -= PositionAccumulator / SECOND_SCALE;
//             }
//             PositionAccumulator %= SECOND_SCALE;
//         }
//         PlayerCurrentPosition = (u16)PlayerNewPosition;
//         if (PlayerCurrentPosition > AxisMovementLimit)
//         {
//             if (ButtonPressed == 0x0001
//             {
//                 PlayerCurrentPosition = AxisMovementLimit;
//             }
//             else
//             {
//                 PlayerCurrentPosition = 0x0000;
//             }
//         }
//         sys_write_vp(PlayerCurrentPositionAddress, (u8*)&PlayerCurrentPosition, 0x0001);
//         sys_write_vp(Debugger, (u8*)&PlayerCurrentPosition, 0x0001);
//         LastButtonPressed = ButtonPressed;
//     }
// }