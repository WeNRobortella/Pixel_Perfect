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
static __xdata s16 XAxisMovementLimit = 0x0000;
static __xdata s16 YAxisMovementLimit = 0x0000;

void DefineMovementComponent(void)
{
    XAxisMovementLimit = (s16)(SCREEN_WIDTH - Player.PlayerSize);
    YAxisMovementLimit = (s16)(SCREEN_HEIGHT - Player.PlayerSize);
}

void UpdatePosition(s8 Polarity, u16 MovementAxis) __reentrant 
{
u16 PlayerCurrentPositionAddress = Player.PlayerSP + MovementAxis;
    PlayerCurrentPosition = DGUS_Read_VP(PlayerCurrentPositionAddress);
    DistanceToMove = (s32)Player.PlayerSpeed * Polarity * (s32)Get_DeltaTime();
        PlayerNewPosition = PlayerCurrentPosition + DistanceToMove / SECOND_SCALE;
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
        PlayerNewPosition += PositionAccumulator;
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
}