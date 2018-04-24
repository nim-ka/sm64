#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"

/**
 * Determine if mario is standing on a platform object, meaning that he is
 * within 4 units of the floor. Set his referenced platform object accordingly.
 */
void update_mario_platform(void)
{
    struct Surface *floor;
    UNUSED u32 unused;
    f32 marioX;
    f32 marioY;
    f32 marioZ;
    f32 floorHeight;
    u32 awayFromFloor;

    if (gMarioObject == NULL) return;

    marioX = gMarioObject->pos[0];
    marioY = gMarioObject->pos[1];
    marioZ = gMarioObject->pos[2];
    floorHeight = func_80381900(marioX, marioY, marioZ, &floor);

    if (func_802A2E8C(marioY - floorHeight) < 4.0f)
        awayFromFloor = 0;
    else
        awayFromFloor = 1;

    switch (awayFromFloor)
    {
    case 1:
        gMarioPlatform = NULL;
        gMarioObject->platform = NULL;
        break;

    case 0:
        if (floor != NULL && floor->object != NULL) {
            gMarioPlatform = floor->object;
            gMarioObject->platform = floor->object;
        }
        else {
            gMarioPlatform = NULL;
            gMarioObject->platform = NULL;
        }
        break;
    }
}

/**
 * Get mario's position and store it in x, y, and z.
 */
void get_mario_pos(f32 *x, f32 *y, f32 *z)
{
    *x = gMarioStates[0].pos[0];
    *y = gMarioStates[0].pos[1];
    *z = gMarioStates[0].pos[2];
}

/**
 * Set mario's position.
 */
void set_mario_pos(f32 x, f32 y, f32 z)
{
    gMarioStates[0].pos[0] = x;
    gMarioStates[0].pos[1] = y;
    gMarioStates[0].pos[2] = z;
}

/**
 * Apply one frame of platform rotation to mario or an object using the given
 * platform. If isMario is 0, use gCurrentObject.
 */
void apply_platform_displacement(u32 isMario, struct Object *platform)
{
    f32 x;
    f32 y;
    f32 z;
    f32 platformPosX;
    f32 platformPosY;
    f32 platformPosZ;
    Vec3f currentObjectOffset;
    Vec3f relativeOffset;
    Vec3f newObjectOffset;
    Vec3s rotation;
    UNUSED s16 unused1;
    UNUSED s16 unused2;
    UNUSED s16 unused3;
    f32 displaceMatrix[4][4];

    rotation[0] = platform->platformRotation[0];
    rotation[1] = platform->platformRotation[1];
    rotation[2] = platform->platformRotation[2];

    if (isMario)
    {
        D_8032FEC0 = 0;
        get_mario_pos(&x, &y, &z);
    }
    else
    {
        x = gCurrentObject->pos[0];
        y = gCurrentObject->pos[1];
        z = gCurrentObject->pos[2];
    }

    x += platform->vel[0];
    z += platform->vel[2];

    if (rotation[0] != 0 || rotation[1] != 0 || rotation[2] != 0)
    {        
        unused1 = rotation[0];
        unused2 = rotation[2];
        unused3 = platform->faceAngle[1];

        if (isMario)
            gMarioStates[0].faceAngle[1] += rotation[1];

        platformPosX = platform->pos[0];
        platformPosY = platform->pos[1];
        platformPosZ = platform->pos[2];

        currentObjectOffset[0] = x - platformPosX;
        currentObjectOffset[1] = y - platformPosY;
        currentObjectOffset[2] = z - platformPosZ;

        rotation[0] = platform->faceAngle[0] - platform->platformRotation[0];
        rotation[1] = platform->faceAngle[1] - platform->platformRotation[1];
        rotation[2] = platform->faceAngle[2] - platform->platformRotation[2];

        mtxf_rotate_zxy_and_translate(displaceMatrix, currentObjectOffset, rotation);
        func_8029EAF8(displaceMatrix, relativeOffset, currentObjectOffset);

        rotation[0] = platform->faceAngle[0];
        rotation[1] = platform->faceAngle[1];
        rotation[2] = platform->faceAngle[2];

        mtxf_rotate_zxy_and_translate(displaceMatrix, currentObjectOffset, rotation);
        func_8029EA84(displaceMatrix, newObjectOffset, relativeOffset);

        x = platformPosX + newObjectOffset[0];
        y = platformPosY + newObjectOffset[1];
        z = platformPosZ + newObjectOffset[2];
    }

    if (isMario)
    {
        set_mario_pos(x, y, z);
    }
    else
    {
        gCurrentObject->pos[0] = x;
        gCurrentObject->pos[1] = y;
        gCurrentObject->pos[2] = z;
    }
}

/**
 * If mario's platform is not null, apply platform displacement.
 */
void apply_mario_platform_displacement(void)
{
    struct Object *platform;

    platform = gMarioPlatform;
    if (!(D_8033C110 & 0x00000040) && gMarioObject != NULL && platform != NULL)
        apply_platform_displacement(1, platform);
}
