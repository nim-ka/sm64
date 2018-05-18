#ifndef _LEVEL_UPDATE_H
#define _LEVEL_UPDATE_H

#include "types.h"

#define TIMER_CONTROL_SHOW  0
#define TIMER_CONTROL_START 1
#define TIMER_CONTROL_STOP  2
#define TIMER_CONTROL_HIDE  3


#define WARP_OP_NONE          0x00
#define WARP_OP_UNKNOWN_01    0x01
#define WARP_OP_UNKNOWN_02    0x02
#define WARP_OP_WARP_DOOR     0x03
#define WARP_OP_WARP_OBJECT   0x04
#define WARP_OP_TELEPORT      0x05
#define WARP_OP_STAR_EXIT     0x11
#define WARP_OP_DEATH         0x12
#define WARP_OP_WARP_FLOOR    0x13
#define WARP_OP_GAME_OVER     0x14
#define WARP_OP_CREDITS_END   0x15
#define WARP_OP_DEMO_NEXT     0x16
#define WARP_OP_CREDITS_START 0x17
#define WARP_OP_CREDITS_NEXT  0x18
#define WARP_OP_DEMO_END      0x19

#define WARP_OP_TRIGGERS_LEVEL_SELECT 0x10

#define MARIO_SPAWN_UNKNOWN_01 0x01
#define MARIO_SPAWN_UNKNOWN_02 0x02
#define MARIO_SPAWN_UNKNOWN_03 0x03
#define MARIO_SPAWN_UNKNOWN_04 0x04
#define MARIO_SPAWN_UNKNOWN_10 0x10
#define MARIO_SPAWN_UNKNOWN_11 0x11
#define MARIO_SPAWN_UNKNOWN_12 0x12
#define MARIO_SPAWN_UNKNOWN_13 0x13
#define MARIO_SPAWN_UNKNOWN_14 0x14
#define MARIO_SPAWN_UNKNOWN_15 0x15
#define MARIO_SPAWN_UNKNOWN_16 0x16
#define MARIO_SPAWN_UNKNOWN_17 0x17
#define MARIO_SPAWN_UNKNOWN_20 0x20
#define MARIO_SPAWN_UNKNOWN_21 0x21
#define MARIO_SPAWN_UNKNOWN_22 0x22
#define MARIO_SPAWN_UNKNOWN_23 0x23
#define MARIO_SPAWN_UNKNOWN_24 0x24
#define MARIO_SPAWN_UNKNOWN_25 0x25
#define MARIO_SPAWN_UNKNOWN_27 0x27

struct UnknownArea1C
{
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ Vec3s displacement;
};

struct UnknownArea24 // Camera or camera related
{
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ s16 unk02;
};

struct WarpNode
{
    /*00*/ u8 id;
    /*01*/ u8 destLevel;
    /*02*/ u8 destArea;
    /*03*/ u8 destNode;
};

struct ObjectWarpNode
{
    /*0x00*/ struct WarpNode node;
    /*0x04*/ struct Object *object;
    /*0x08*/ struct ObjectWarpNode *unk8;
};

struct Whirlpool
{
    /*0x00*/ Vec3s pos;
    /*0x03*/ s16 strength;
};

struct Area
{
    /*0x00*/ s8 index;
    /*0x01*/ s8 unk01;
    /*0x02*/ u16 unk02;
    /*0x04*/ struct GraphNode *unk04;
    /*0x08*/ s16 *unk08;
    /*0x0C*/ u32 unk0C;
    /*0x10*/ s16 *unk10;
    /*0x14*/ struct ObjectWarpNode *unk14;
    /*0x18*/ struct WarpNode *paintingWarpNodes;
    /*0x1C*/ struct UnknownArea1C *unk1C;
    /*0x20*/ u32 unk20;
    /*0x24*/ struct UnknownArea24 *unk24;
    /*0x28*/ u32 unk28;
    /*0x2C*/ struct Whirlpool *whirlpools[2];
    /*0x34*/ u8 unk34[1];
    /*0x35*/ u8 unk35;
    /*0x36*/ u16 unk36;
    /*0x38*/ u16 unk38;
};

struct Struct8033A140 // Level, I think
{
    /*0x00*/ Vec3s marioStartPos;
    /*0x06*/ Vec3s marioStartAngle;
    /*0x0C*/ s8 areaIndex[1];
    /*0x0D*/ s8 unk0D;
    /*0x10*/ u32 unk10;
    /*0x14*/ u32 unk14;
    /*0x18*/ u32 unk18;
    /*0x1C*/ u32 unk1C;
};

struct CreditsEntry
{
    /*0x00*/ u8 levelNum;
    /*0x01*/ u8 areaIndex;
    /*0x02*/ u8 unk02;
    /*0x03*/ s8 marioAngle;
    /*0x04*/ Vec3s marioPos;
    /*0x0C*/ const char **unk0C;
};


extern struct CreditsEntry *gCurrCreditsEntry;

extern struct MarioState *gMarioState;
extern struct MarioState gMarioStates[];

extern s16 gDisplayedLives;
extern s16 gDisplayedCoins;
extern s16 gDisplayedStars;
extern s16 gDisplayedHealthWedges;
extern s16 gDisplayedKeys;
extern s16 gHudDisplayFlags;
extern u16 gTimerValueInFrames;
extern s8 D_80339EFE;

extern s16 gCurrCourseNum;
extern s16 D_8033A758;
extern s16 D_8033A75A;
extern s16 D_8033A75C;
extern s16 D_8033A75E;
extern struct Area D_8033A560[];
extern struct Area *D_8032CE68;
extern struct Area *D_8032CE6C;

extern s16 gCurrSaveFileNum;
extern s16 gCurrLevelNum;

// extern s8 D_8032C9E0;

u16 level_control_timer(u32 timerOp);
void func_80249788(u32 arg, u32 color);
void func_8024980C(u32 arg);
s16 level_trigger_warp(struct MarioState *m, s32 warpOp);
void level_set_transition(s16 length, void (*updateFunction)(s16 *));

s32 lvl_init_or_update(s16 initOrUpdate, s32);
s32 lvl_init_from_save_file(s16, s32 levelNum);
s32 lvl_set_current_level(s16, s32 levelNum);
s32 lvl_play_the_end_screen_sound(s16, s32);


#endif
