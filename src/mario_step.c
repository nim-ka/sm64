#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"
#include "surface_collision.h"
#include "mario.h"
#include "audio_interface_2.h"
#include "display.h"
#include "interaction.h"
#include "mario_step.h"

static s16 sMovingSandSpeeds[] = { 12, 8, 4, 0 };

struct Surface gWaterSurfacePseudoFloor = {
  SURFACE_0013,
  0,
  0,
  0,
  0,
  0,
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0.0f, 1.0f, 0.0f },
  0.0f,
  NULL,
};

f32 zero_80254E20(void)
{
    return 0.0f;
}

void nop_80254E3C(UNUSED u32 x)
{
}

void nop_80254E50(void)
{
}

void transfer_bully_speed(struct BullyCollisionData *obj1, struct BullyCollisionData *obj2)
{
    f32 rx = obj2->posX - obj1->posX;
    f32 rz = obj2->posZ - obj1->posZ;

    //! Bully NaN crash
    f32 projectedV1 = (rx * obj1->velX + rz * obj1->velZ) / (rx*rx + rz*rz);
    f32 projectedV2 = (-rx * obj2->velX - rz * obj2->velZ) / (rx*rx + rz*rz);

    // Kill speed along r. Convert one object's speed along r and transfer it to
    // the other object.
    obj2->velX += obj2->conversionRatio * projectedV1 * rx - projectedV2 * -rx;
    obj2->velZ += obj2->conversionRatio * projectedV1 * rz - projectedV2 * -rz;

    obj1->velX += -projectedV1 * rx + obj1->conversionRatio * projectedV2 * -rx;
    obj1->velZ += -projectedV1 * rz + obj1->conversionRatio * projectedV2 * -rz;

    //! Bully battery
}

void init_bully_collision_data(
    struct BullyCollisionData *data,
    f32 posX,
    f32 posZ,
    f32 forwardVel,
    s16 yaw,
    f32 conversionRatio,
    f32 radius)
{
    if (forwardVel < 0.0f)
    {
        forwardVel *= -1.0f;
        yaw += 0x8000;
    }

    data->radius = radius;
    data->conversionRatio = conversionRatio;
    data->posX = posX;
    data->posZ = posZ;
    data->velX = forwardVel * sins(yaw);
    data->velZ = forwardVel * coss(yaw);
}

void mario_bonk_reflection(struct MarioState *m, u32 negateSpeed)
{
    if (m->wall != NULL)
    {
        s16 wallAngle = func_8037A9A8(m->wall->normal[2], m->wall->normal[0]);
        m->faceAngle[1] = wallAngle - (s16) (m->faceAngle[1] - wallAngle);

        SetSound((m->flags & MARIO_METAL_CAP) ? 0x04428081 : 0x0445A081, &m->marioObj->gfx.unk54);
    }
    else
    {
        SetSound(0x0444C081, &m->marioObj->gfx.unk54);
    }

    if (negateSpeed)
        func_802514DC(m, -m->forwardVel);
    else
        m->faceAngle[1] += 0x8000;
}

u32 mario_update_quicksand(struct MarioState *m, f32 sinkingSpeed)
{
    if (m->action & ACT_FLAG_RIDING_SHELL)
    {
        m->quicksandDepth = 0.0f;
    }
    else
    {
        if (m->quicksandDepth < 1.1f)
            m->quicksandDepth = 1.1f;

        switch (m->floor->type)
        {
        case SURFACE_0021:
            if ((m->quicksandDepth += sinkingSpeed) >= 10.0f)
                m->quicksandDepth = 10.0f;
            break;

        case SURFACE_0025:
            if ((m->quicksandDepth += sinkingSpeed) >= 25.0f)
                m->quicksandDepth = 25.0f;
            break;

        case SURFACE_0026:
        case SURFACE_0027:
            if ((m->quicksandDepth += sinkingSpeed) >= 60.0f)
                m->quicksandDepth = 60.0f;
            break;

        case SURFACE_0022:
        case SURFACE_0024:
            if ((m->quicksandDepth += sinkingSpeed) >= 160.0f)
            {
                func_80251F74(m);
                return drop_and_set_mario_action(m, ACT_QUICKSAND_DEATH, 0);
            }
            break;

        case SURFACE_0023:
        case SURFACE_002D:
            func_80251F74(m);
            return drop_and_set_mario_action(m, ACT_QUICKSAND_DEATH, 0);
            break;

        default:
            m->quicksandDepth = 0.0f;
            break;
        }
    }

    return 0;
}

u32 mario_push_off_steep_floor(struct MarioState *m, u32 action, u32 actionArg)
{
    s16 floorDYaw = m->floorAngle - m->faceAngle[1];

    if (floorDYaw > -0x4000 && floorDYaw < 0x4000)
    {
        m->forwardVel = 16.0f;
        m->faceAngle[1] = m->floorAngle;
    }
    else
    {
        m->forwardVel = -16.0f;
        m->faceAngle[1] = m->floorAngle + 0x8000;
    }

    return set_mario_action(m, action, actionArg);
}

u32 mario_update_moving_sand(struct MarioState *m)
{
    struct Surface *floor = m->floor;
    s32 floorType = floor->type;

    if (floorType == SURFACE_0024 ||
        floorType == SURFACE_0025 ||
        floorType == SURFACE_0027 ||
        floorType == SURFACE_002D)
    {
        s16 pushAngle = floor->force << 8;
        f32 pushSpeed = sMovingSandSpeeds[floor->force >> 8];

        m->vel[0] += pushSpeed * sins(pushAngle);
        m->vel[2] += pushSpeed * coss(pushAngle);

        return 1;
    }

    return 0;
}

u32 mario_update_windy_ground(struct MarioState *m)
{
    struct Surface *floor = m->floor;

    if (floor->type == SURFACE_002C)
    {
        f32 pushSpeed;
        s16 pushAngle = floor->force << 8;

        if (m->action & ACT_FLAG_UNKNOWN_10)
        {
            s16 pushDYaw = m->faceAngle[1] - pushAngle;

            pushSpeed = m->forwardVel > 0.0f ? -m->forwardVel * 0.5f : -8.0f;

            if (pushDYaw > -0x4000 && pushDYaw < 0x4000)
                pushSpeed *= -1.0f;

            pushSpeed *= coss(pushDYaw);
        }
        else
        {
            pushSpeed = 3.2f + (D_8032C694 % 4);
        }

        m->vel[0] += pushSpeed * sins(pushAngle);
        m->vel[2] += pushSpeed * coss(pushAngle);

#if !VERSION_US
        SetSound(0x40108001, &m->marioObj->gfx.unk54);
#endif
        return 1;
    }

    return 0;
}

void stop_and_set_height_to_floor(struct MarioState *m)
{
    struct Object *marioObj = m->marioObj;

    func_802514DC(m, 0.0f);
    m->vel[1] = 0.0f;

    //! This is responsible for some downwarps.
    m->pos[1] = m->floorHeight;

    vec3f_copy(marioObj->gfx.unk20, m->pos);
    vec3s_set(marioObj->gfx.unk1A, 0, m->faceAngle[1], 0);
}

u32 stationary_ground_step(struct MarioState *m)
{
    u32 takeStep;
    struct Object *marioObj = m->marioObj;
    u32 stepResult = GROUND_STEP_NONE;

    func_802514DC(m, 0.0f);

    takeStep = mario_update_moving_sand(m);
    takeStep |= mario_update_windy_ground(m);
    if (takeStep)
    {
        stepResult = perform_ground_step(m);
    }
    else
    {
        //! This is responsible for several stationary downwarps.
        m->pos[1] = m->floorHeight;

        vec3f_copy(marioObj->gfx.unk20, m->pos);
        vec3s_set(marioObj->gfx.unk1A, 0, m->faceAngle[1], 0);
    }

    return stepResult;
}

static u32 perform_ground_quarter_step(struct MarioState *m, Vec3f nextPos)
{
    UNUSED struct Surface *lowerWall;
    struct Surface *upperWall;
    struct Surface *ceil;
    struct Surface *floor;
    f32 ceilHeight;
    f32 floorHeight;
    f32 waterLevel;

    lowerWall = func_8025181C(nextPos, 30.0f, 24.0f);
    upperWall = func_8025181C(nextPos, 60.0f, 50.0f);

    floorHeight = func_80381900(nextPos[0], nextPos[1], nextPos[2], &floor);
    ceilHeight = func_802518D0(nextPos, floorHeight, &ceil);

    waterLevel = func_80381BA0(nextPos[0], nextPos[2]);

    m->wall = upperWall;

    if (floor == NULL)
        return GROUND_STEP_HIT_WALL_STOP_QSTEPS;

    if ((m->action & ACT_FLAG_RIDING_SHELL) && floorHeight < waterLevel)
    {
        floorHeight = waterLevel;
        floor = &gWaterSurfacePseudoFloor;
        floor->originOffset = floorHeight; //! Wrong origin offset (no effect)
    }

    if (nextPos[1] > floorHeight + 100.0f)
    {
        if (nextPos[1] + 160.0f >= ceilHeight)
            return GROUND_STEP_HIT_WALL_STOP_QSTEPS;

        vec3f_copy(m->pos, nextPos);
        m->floor = floor;
        m->floorHeight = floorHeight;
        return GROUND_STEP_LEFT_GROUND;
    }

    if (floorHeight + 160.0f >= ceilHeight)
        return GROUND_STEP_HIT_WALL_STOP_QSTEPS;

    vec3f_set(m->pos, nextPos[0], floorHeight, nextPos[2]);
    m->floor = floor;
    m->floorHeight = floorHeight;

    if (upperWall != NULL)
    {
        s16 wallDYaw = func_8037A9A8(upperWall->normal[2], upperWall->normal[0]) - m->faceAngle[1];

        if (wallDYaw >= 0x2AAA && wallDYaw <= 0x5555)
            return GROUND_STEP_NONE;
        if (wallDYaw <= -0x2AAA && wallDYaw >= -0x5555)
            return GROUND_STEP_NONE;

        return GROUND_STEP_HIT_WALL_CONTINUE_QSTEPS;
    }

    return GROUND_STEP_NONE;
}

u32 perform_ground_step(struct MarioState *m)
{
    s32 i;
    u32 stepResult;
    Vec3f intendedPos;

    for (i = 0; i < 4; i++)
    {
        intendedPos[0] = m->pos[0] + m->floor->normal[1] * (m->vel[0] / 4.0f);
        intendedPos[2] = m->pos[2] + m->floor->normal[1] * (m->vel[2] / 4.0f);
        intendedPos[1] = m->pos[1];

        stepResult = perform_ground_quarter_step(m, intendedPos);
        if (stepResult == GROUND_STEP_LEFT_GROUND ||
            stepResult == GROUND_STEP_HIT_WALL_STOP_QSTEPS)
        {
            break;
        }
    }

    m->unk14 = func_8025167C(m);
    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
    vec3s_set(m->marioObj->gfx.unk1A, 0, m->faceAngle[1], 0);

    if (stepResult == GROUND_STEP_HIT_WALL_CONTINUE_QSTEPS)
        stepResult = GROUND_STEP_HIT_WALL;
    return stepResult;
}

static u32 check_ledge_grab(
    struct MarioState *m, struct Surface *wall, Vec3f intendedPos, Vec3f nextPos)
{
    struct Surface *ledgeFloor;
    Vec3f ledgePos;
    f32 displacementX;
    f32 displacementZ;

    if (m->vel[1] > 0.0f)
        return 0;

    displacementX = nextPos[0] - intendedPos[0];
    displacementZ = nextPos[2] - intendedPos[2];

    // Only ledge grab if the wall displaced mario in the opposite direction of
    // his velocity.
    if (displacementX * m->vel[0] + displacementZ * m->vel[2] > 0.0f)
        return 0;

    //! Since the search for floors starts at y + 160, we will sometimes grab
    // a higher ledge than expected (glitchy ledge grab)
    ledgePos[0] = nextPos[0] - wall->normal[0] * 60.0f;
    ledgePos[2] = nextPos[2] - wall->normal[2] * 60.0f;
    ledgePos[1] = func_80381900(
        ledgePos[0], nextPos[1] + 160.0f, ledgePos[2], &ledgeFloor);

    if (ledgePos[1] - nextPos[1] <= 100.0f)
        return 0;

    vec3f_copy(m->pos, ledgePos);
    m->floor = ledgeFloor;
    m->floorHeight = ledgePos[1];

    m->floorAngle = func_8037A9A8(ledgeFloor->normal[2], ledgeFloor->normal[0]);

    m->faceAngle[0] = 0;
    m->faceAngle[1] = func_8037A9A8(wall->normal[2], wall->normal[0]) + 0x8000;
    return 1;
}

static u32 perform_air_quarter_step(
    struct MarioState *m, Vec3f intendedPos, u32 stepArg)
{
    s16 wallDYaw;
    Vec3f nextPos;
    struct Surface *upperWall;
    struct Surface *lowerWall;
    struct Surface *ceil;
    struct Surface *floor;
    f32 ceilHeight;
    f32 floorHeight;
    f32 waterLevel;

    vec3f_copy(nextPos, intendedPos);

    upperWall = func_8025181C(nextPos, 150.0f, 50.0f);
    lowerWall = func_8025181C(nextPos, 30.0f, 50.0f);

    floorHeight = func_80381900(nextPos[0], nextPos[1], nextPos[2], &floor);
    ceilHeight = func_802518D0(nextPos, floorHeight, &ceil);

    waterLevel = func_80381BA0(nextPos[0], nextPos[2]);

    m->wall = NULL;

    //! The water pseudo floor is not referenced when your intended qstep is
    // out of bounds, so it won't detect you as landing.

    if (floor == NULL)
    {
        if (nextPos[1] <= m->floorHeight)
        {
            m->pos[1] = m->floorHeight;
            return AIR_STEP_LANDED;
        }

        m->pos[1] = nextPos[1];
        return AIR_STEP_HIT_WALL;
    }

    if ((m->action & ACT_FLAG_RIDING_SHELL) && floorHeight < waterLevel)
    {
        floorHeight = waterLevel;
        floor = &gWaterSurfacePseudoFloor;
        floor->originOffset = floorHeight; //! Incorrect origin offset (no effect)
    }

    //! This check uses float, but findFloor uses short (overflow jumps)
    if (nextPos[1] <= floorHeight)
    {
        if (ceilHeight - floorHeight > 160.0f)
        {
            m->pos[0] = nextPos[0];
            m->pos[2] = nextPos[2];
            m->floor = floor;
            m->floorHeight = floorHeight;
        }

        //! When ceilHeight - floorHeight <= 160, the step result says that
        // mario landed, but his movement is cancelled and his referenced floor
        // isn't updated (pedro spots)
        m->pos[1] = floorHeight;
        return AIR_STEP_LANDED;
    }

    if (nextPos[1] + 160.0f > ceilHeight)
    {
        if (m->vel[1] >= 0.0f)
        {
            m->vel[1] = 0.0f;

            //! Uses referenced ceiling instead of ceil (ceiling hang upwarp)
            if ((stepArg & AIR_STEP_CHECK_HANG) && m->ceil != NULL &&
                m->ceil->type == SURFACE_HANGABLE)
            {
                return AIR_STEP_GRABBED_CEILING;
            }

            return AIR_STEP_NONE;
        }

        //! Potential subframe downwarp->upwarp?
        if (nextPos[1] <= m->floorHeight)
        {
            m->pos[1] = m->floorHeight;
            return AIR_STEP_LANDED;
        }

        m->pos[1] = nextPos[1];
        return AIR_STEP_HIT_WALL;
    }

    //! When the wall is not completely vertical or there is a slight wall
    // misalignment, you can activate these conditions in unexpected situations
    if ((stepArg & AIR_STEP_CHECK_LEDGE_GRAB) && upperWall == NULL && lowerWall != NULL)
    {
        if (check_ledge_grab(m, lowerWall, intendedPos, nextPos))
        {
            return AIR_STEP_GRABBED_LEDGE;
        }

        vec3f_copy(m->pos, nextPos);
        m->floor = floor;
        m->floorHeight = floorHeight;
        return AIR_STEP_NONE;
    }

    vec3f_copy(m->pos, nextPos);
    m->floor = floor;
    m->floorHeight = floorHeight;

    if (upperWall != NULL || lowerWall != NULL)
    {
        m->wall = upperWall != NULL ? upperWall : lowerWall;
        wallDYaw = func_8037A9A8(m->wall->normal[2], m->wall->normal[0]) - m->faceAngle[1];

        if (m->wall->type == SURFACE_LAVA)
            return AIR_STEP_HIT_LAVA_WALL;

        if (wallDYaw < -0x6000 || wallDYaw > 0x6000)
        {
            m->flags |= MARIO_UNKNOWN_30;
            return AIR_STEP_HIT_WALL;
        }
    }

    return AIR_STEP_NONE;
}

static void apply_twirl_gravity(struct MarioState *m)
{
    f32 terminalVelocity;
    f32 heaviness = 1.0f;

    if (m->angleVel[1] > 1024)
        heaviness = 1024.0f / m->angleVel[1];

    terminalVelocity = -75.0f * heaviness;

    m->vel[1] -= 4.0f * heaviness;
    if (m->vel[1] < terminalVelocity)
        m->vel[1] = terminalVelocity;
}

static u32 should_strengthen_gravity_for_jump_ascent(struct MarioState *m)
{
    if (!(m->flags & MARIO_UNKNOWN_08))
        return 0;

    if (m->action & (ACT_FLAG_INTANGIBLE | ACT_FLAG_UNKNOWN_17))
        return 0;

    if (!(m->input & INPUT_A_DOWN) && m->vel[1] > 20.0f)
        return (m->action & ACT_FLAG_CONTROL_JUMP_HEIGHT) != 0;

    return 0;
}

static void apply_gravity(struct MarioState *m)
{
    if (m->action == ACT_TWIRLING && m->vel[1] < 0.0f)
    {
        apply_twirl_gravity(m);
    }
    else if (m->action == ACT_SHOT_FROM_CANNON)
    {
        m->vel[1] -= 1.0f;
        if (m->vel[1] < -75.0f)
            m->vel[1] = -75.0f;
    }
    else if (m->action == ACT_LONG_JUMP || m->action == ACT_SLIDE_KICK ||
        m->action == ACT_BBH_ENTER_SPIN)
    {
        m->vel[1] -= 2.0f;
        if (m->vel[1] < -75.0f)
            m->vel[1] = -75.0f;
    }
    else if (m->action == ACT_LAVA_BOOST || m->action == ACT_FALL_AFTER_STAR_GRAB)
    {
        m->vel[1] -= 3.2f;
        if (m->vel[1] < -65.0f)
            m->vel[1] = -65.0f;
    }
    else if (m->action == ACT_GETTING_BLOWN)
    {
        m->vel[1] -= m->unkC4;
        if (m->vel[1] < -75.0f)
            m->vel[1] = -75.0f;
    }
    else if (should_strengthen_gravity_for_jump_ascent(m))
    {
        m->vel[1] /= 4.0f;
    }
    else if (m->action & ACT_FLAG_METAL_WATER)
    {
        m->vel[1] -= 1.6f;
        if (m->vel[1] < -16.0f)
            m->vel[1] = -16.0f;
    }
    else if ((m->flags & MARIO_WING_CAP) && m->vel[1] < 0.0f && (m->input & INPUT_A_DOWN))
    {
        m->unk98->unk07 = 1;

        m->vel[1] -= 2.0f;
        if (m->vel[1] < -37.5f)
        {
            if ((m->vel[1] += 4.0f) > -37.5f)
                m->vel[1] = -37.5f;
        }
    }
    else
    {
        m->vel[1] -= 4.0f;
        if (m->vel[1] < -75.0f)
            m->vel[1] = -75.0f;
    }
}

static void apply_vertical_wind(struct MarioState *m)
{
    f32 maxVelY;
    f32 offsetY;

    if (m->action != ACT_GROUND_POUND)
    {
        offsetY = m->pos[1] - -1500.0f;

        if (m->floor->type == SURFACE_0038 && -3000.0f < offsetY && offsetY < 2000.0f)
        {
            if (offsetY >= 0.0f)
                maxVelY = 10000.0f / (offsetY + 200.0f);
            else
                maxVelY = 50.0f;

            if (m->vel[1] < maxVelY)
            {
                m->vel[1] += maxVelY / 8.0f;
                if (m->vel[1] > maxVelY)
                    m->vel[1] = maxVelY;
            }

#if !VERSION_US
            SetSound(0x40108001, &m->marioObj->gfx.unk54);
#endif
        }
    }
}

u32 perform_air_step(struct MarioState *m, u32 stepArg)
{
    Vec3f intendedPos;
    s32 i;
    u32 quarterStepResult;
    u32 stepResult = AIR_STEP_NONE;

    m->wall = NULL;

    for (i = 0; i < 4; i++)
    {
        intendedPos[0] = m->pos[0] + m->vel[0] / 4.0f;
        intendedPos[1] = m->pos[1] + m->vel[1] / 4.0f;
        intendedPos[2] = m->pos[2] + m->vel[2] / 4.0f;

        quarterStepResult = perform_air_quarter_step(m, intendedPos, stepArg);

        //! On one qf, hit OOB/ceil/wall to store the 2 return value, and continue
        // getting 0s until your last qf. Graze a wall on your last qf, and it will
        // return the stored 2 with a sharply angled reference wall. (some gwks)

        if (quarterStepResult != AIR_STEP_NONE)
            stepResult = quarterStepResult;

        if (quarterStepResult == AIR_STEP_LANDED ||
            quarterStepResult == AIR_STEP_GRABBED_LEDGE ||
            quarterStepResult == AIR_STEP_GRABBED_CEILING ||
            quarterStepResult == AIR_STEP_HIT_LAVA_WALL)
        {
            break;
        }
    }

    if (m->vel[1] >= 0.0f)
        m->peakHeight = m->pos[1];

    m->unk14 = func_8025167C(m);
    
    if (m->action != ACT_FLYING)
        apply_gravity(m);
    apply_vertical_wind(m);

    vec3f_copy(m->marioObj->gfx.unk20, m->pos);
    vec3s_set(m->marioObj->gfx.unk1A, 0, m->faceAngle[1], 0);

    return stepResult;
}

// They had these functions the whole time and never used them? Lol

static void set_vel_from_pitch_and_yaw(struct MarioState *m)
{
    m->vel[0] = m->forwardVel * coss(m->faceAngle[0]) * sins(m->faceAngle[1]);
    m->vel[1] = m->forwardVel * sins(m->faceAngle[0]);
    m->vel[2] = m->forwardVel * coss(m->faceAngle[0]) * coss(m->faceAngle[1]);
}

static void set_vel_from_yaw(struct MarioState *m)
{
    m->vel[0] = m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
    m->vel[1] = 0.0f;
    m->vel[2] = m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);
}
