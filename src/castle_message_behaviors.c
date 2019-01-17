#include <ultra64.h>

#include "sm64.h"
#include "area.h"
#include "audio/interface_2.h"
#include "camera.h"
#include "castle_message_behaviors.h"
#include "behavior_actions.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "game.h"
#include "graph_node.h"
#include "ingame_menu_2.h"
#include "level_update.h"
#include "math_util.h"
#include "memory.h"
#include "object_helpers.h"
#include "object_helpers2.h"
#include "goddard/mario_head_6.h"
//#include "rendering.h"
#include "rendering_graph_node.h"
#include "save_file.h"
#include "sound_init.h"
#include "skybox.h"
#include "interaction.h"

static s8 D_8032CDF0[7] = {0x01, 0x02, 0x01, 0x00, 0x01, 0x02, 0x01};
static s8 D_8032CDF8[] = {0x0a, 0x0c, 0x10, 0x18, 0x0a, 0x0a, 0x0a, 0x0e, 0x14, 0x1e, 0x0a, 0x0a, 0x0a, 0x10, 0x14, 0x1a, 0x1a, 0x14, 0x00, 0x00};
static s16 D_8032CE0C = 0;


struct GraphNodeObject D_80339FE0;
struct Struct8033A040 D_8033A040[2]; 

Gfx *Geo18_802761D0(int a, struct GraphNode *b, float c[4][4])
{
    Vec3s sp50;
    Vec3s sp48;
    Vec3s sp40;
    void *sp3C;
    Gfx *sp38 = NULL;

    if (a == 1 && D_8032CF9C != NULL)
    {
        struct Struct802761D0 *sp34 = (struct Struct802761D0 *)b;
        struct Struct802761D0 *sp30 = sp34 + 1;

        if (sp30->unk0 != gAreaUpdateCounter)
        {
            UNUSED int sp2C = D_8032CF9C->unk18;
            int sp28 = (u16)sp30->unk2;

            vec3f_to_vec3s(sp40, D_8032CF9C->unk28);
            vec3f_to_vec3s(sp48, D_8032CF9C->unk1C);
            vec3f_to_vec3s(sp50, D_8033B1B0->unk4);
            sp3C = func_802DECB8(sp28, sp50, sp40, sp48);
            if (sp3C != NULL)
            {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                sp38 = alloc_display_list(2 * sizeof(*sp38));
                mtxf_to_mtx(mtx, c);
                gSPMatrix(&sp38[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD);
                gSPBranchList(&sp38[1], VIRTUAL_TO_PHYSICAL(sp3C));
                sp34->unk2 = (sp34->unk2 & 0xFF) | 0x400;
            }
            sp30->unk0 = gAreaUpdateCounter;
        }
    }
    else if (a == 4)
    {
        vec3s_copy(sp40, D_80385FDC);
        vec3s_copy(sp48, D_80385FDC);
        vec3s_copy(sp50, D_80385FDC);
        func_802DECB8(0, sp50, sp40, sp48);
    }
    return sp38;
}

Gfx *Geo19_802763D4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    Gfx *sp3C = NULL;
    struct Struct802763D4 *sp38 = (struct Struct802763D4 *)b;

    if (a == 3)
    {
        sp38->unk18 = 0;
    }
    else if (a == 1)
    {
        struct GraphNode *sp34 = D_8032CF90->unk20[0];
        struct Struct802763D4_Unknown *sp30 = (struct Struct802763D4_Unknown *)sp34->parent;

        sp3C = func_802CF414(0, sp38->unk1C, sp30->unk1C,
            D_8033B328.unk8C[0], D_8033B328.unk8C[1], D_8033B328.unk8C[2],
            D_8033B328.unk80[0], D_8033B328.unk80[1], D_8033B328.unk80[2]);
    }
    return sp3C;
}

Gfx *Geo18_802764B0(int a, struct GraphNode *b, Mat4 *c)
{
    Gfx *sp24 = NULL;
    s16 sp22 = 0;
    struct Struct802763D4 *sp1C = (struct Struct802763D4 *)b;
    UNUSED Mat4 *sp18 = c;

    if (a == 1)
    {
        if (gPlayer1Controller->controllerData != NULL && D_8033A740 == 0)
            gd_copy_p1_contpad(gPlayer1Controller->controllerData);
        sp24 = (Gfx *)PHYSICAL_TO_VIRTUAL(gdm_gettestdl(sp1C->unk18));
        D_8032C6A0 = Proc8019C734;
        sp22 = func_8019C888();
        func_80248E24(sp22);
    }
    return sp24;
}

static void beh_toad_message_faded(void)
{
    if (gCurrentObject->oDistanceToMario > 700.0f)
        gCurrentObject->oToadMessageRecentlyTalked = 0;
    if (gCurrentObject->oToadMessageRecentlyTalked == 0 && gCurrentObject->oDistanceToMario < 600.0f)
        gCurrentObject->oToadMessageState = TOAD_MESSAGE_OPACIFYING;
}

static void beh_toad_message_opaque(void)
{
    if (gCurrentObject->oDistanceToMario > 700.0f)
    {
        gCurrentObject->oToadMessageState = TOAD_MESSAGE_FADING;
    }
    else
    {
        if (gCurrentObject->oToadMessageRecentlyTalked == 0)
        {
            gCurrentObject->oUnk190 = (1 << 14);
            if (gCurrentObject->oInteractStatus & INT_STATUS_INTERACTED)
            {
                gCurrentObject->oInteractStatus = 0;
                gCurrentObject->oToadMessageState = TOAD_MESSAGE_TALKING;
                func_8032132C();
            }
        }
    }
}

static void beh_toad_message_talking(void)
{
    if (obj_update_dialogue_unk2(3, 1, 162, gCurrentObject->oToadMessageDialogNum) != 0)
    {
        gCurrentObject->oToadMessageRecentlyTalked = 1;
        gCurrentObject->oToadMessageState = TOAD_MESSAGE_FADING;
        switch (gCurrentObject->oToadMessageDialogNum)
        {
        case TOAD_STAR_1_DIALOG:
            gCurrentObject->oToadMessageDialogNum = TOAD_STAR_1_DIALOG_AFTER;
            func_802AACE4(0);
            break;
        case TOAD_STAR_2_DIALOG:
            gCurrentObject->oToadMessageDialogNum = TOAD_STAR_2_DIALOG_AFTER;
            func_802AACE4(1);
            break;
        case TOAD_STAR_3_DIALOG:
            gCurrentObject->oToadMessageDialogNum = TOAD_STAR_3_DIALOG_AFTER;
            func_802AACE4(2);
            break;
        }
    }
}

static void beh_toad_message_opacifying(void)
{
    if ((gCurrentObject->oOpacity += 6) == 255)
        gCurrentObject->oToadMessageState = TOAD_MESSAGE_OPAQUE;
}

static void beh_toad_message_fading(void)
{
    if ((gCurrentObject->oOpacity -= 6) == 81)
        gCurrentObject->oToadMessageState = TOAD_MESSAGE_FADED;
}

void beh_toad_message_loop(void)
{
    if (gCurrentObject->header.gfx.node.flags & 1)
    {
        gCurrentObject->oUnk190 = 0;
        switch (gCurrentObject->oToadMessageState)
        {
        case TOAD_MESSAGE_FADED:
            beh_toad_message_faded();
            break;
        case TOAD_MESSAGE_OPAQUE:
            beh_toad_message_opaque();
            break;
        case TOAD_MESSAGE_OPACIFYING:
            beh_toad_message_opacifying();
            break;
        case TOAD_MESSAGE_FADING:
            beh_toad_message_fading();
            break;
        case TOAD_MESSAGE_TALKING:
            beh_toad_message_talking();
            break;
        }
    }
}

void beh_toad_message_init(void)
{
    int saveFlags = save_file_get_flags();
    int starCount = save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24);
    int dialogNum = (gCurrentObject->oBehParams >> 24) & 0xFF;
    int enoughStars = TRUE;

    switch (dialogNum)
    {
    case TOAD_STAR_1_DIALOG:
        enoughStars = (starCount >= TOAD_STAR_1_REQUIREMENT);
        if (saveFlags & (1 << 24))
            dialogNum = TOAD_STAR_1_DIALOG_AFTER;
        break;
    case TOAD_STAR_2_DIALOG:
        enoughStars = (starCount >= TOAD_STAR_2_REQUIREMENT);
        if (saveFlags & (1 << 25))
            dialogNum = TOAD_STAR_2_DIALOG_AFTER;
        break;
    case TOAD_STAR_3_DIALOG:
        enoughStars = (starCount >= TOAD_STAR_3_REQUIREMENT);
        if (saveFlags & (1 << 26))
            dialogNum = TOAD_STAR_3_DIALOG_AFTER;
        break;
    }
    if (enoughStars)
    {
        gCurrentObject->oToadMessageDialogNum = dialogNum;
        gCurrentObject->oToadMessageRecentlyTalked = 0;
        gCurrentObject->oToadMessageState = TOAD_MESSAGE_FADED;
        gCurrentObject->oOpacity = 81;
    }
    else
    {
        mark_object_for_deletion(gCurrentObject);
    }
}

static void beh_unlock_door_star_spawn_particle(s16 angleOffset)
{
    struct Object *sparkleParticle = spawn_object(gCurrentObject, 0, beh_powerup_sparkles2);

    sparkleParticle->oPosX += 100.0f * sins((gCurrentObject->oUnlockDoorStarTimer * 0x2800) + angleOffset);
    sparkleParticle->oPosZ += 100.0f * coss((gCurrentObject->oUnlockDoorStarTimer * 0x2800) + angleOffset);
    // Particles are spawned lower each frame
    sparkleParticle->oPosY -= gCurrentObject->oUnlockDoorStarTimer * 10.0f;
}

void beh_unlock_door_star_init(void)
{
    gCurrentObject->oUnlockDoorStarState = UNLOCK_DOOR_STAR_RISING;
    gCurrentObject->oUnlockDoorStarTimer = 0;
    gCurrentObject->oUnlockDoorStarYawVel = 0x1000;
    gCurrentObject->oPosX += 30.0f * sins(gMarioState->faceAngle[1] - 0x4000);
    gCurrentObject->oPosY += 160.0f;
    gCurrentObject->oPosZ += 30.0f * coss(gMarioState->faceAngle[1] - 0x4000);
    gCurrentObject->oMoveAngleYaw = 0x7800;
    scale_object(gCurrentObject, 0.5f);
}

void beh_unlock_door_star_loop(void)
{
    UNUSED u8 unused1[4];
    s16 prevYaw = gCurrentObject->oMoveAngleYaw;
    UNUSED u8 unused2[4];

    // Speed up the star every frame
    if (gCurrentObject->oUnlockDoorStarYawVel < 0x2400)
        gCurrentObject->oUnlockDoorStarYawVel += 0x60;
    switch (gCurrentObject->oUnlockDoorStarState)
    {
    case UNLOCK_DOOR_STAR_RISING:
        gCurrentObject->oPosY += 3.4f; // Raise the star up in the air
        gCurrentObject->oMoveAngleYaw += gCurrentObject->oUnlockDoorStarYawVel; // Apply yaw velocity
        scale_object(gCurrentObject, gCurrentObject->oUnlockDoorStarTimer / 50.0f + 0.5f); // Scale the star to be bigger
        if (++gCurrentObject->oUnlockDoorStarTimer == 30)
        {
            gCurrentObject->oUnlockDoorStarTimer = 0;
            gCurrentObject->oUnlockDoorStarState++; // Sets state to UNLOCK_DOOR_STAR_WAITING
        }
        break;
    case UNLOCK_DOOR_STAR_WAITING:
        gCurrentObject->oMoveAngleYaw += gCurrentObject->oUnlockDoorStarYawVel; // Apply yaw velocity
        if (++gCurrentObject->oUnlockDoorStarTimer == 30)
        {
            SetSound(SOUND_MENU_STARSOUND, &gCurrentObject->header.gfx.unk54); // Play final sound
            obj_hide(); // Hide the object
            gCurrentObject->oUnlockDoorStarTimer = 0;
            gCurrentObject->oUnlockDoorStarState++; // Sets state to UNLOCK_DOOR_STAR_SPAWNING_PARTICLES
        }
        break;
    case UNLOCK_DOOR_STAR_SPAWNING_PARTICLES:
        // Spawn two particles, opposite sides of the star.
        beh_unlock_door_star_spawn_particle(0);
        beh_unlock_door_star_spawn_particle(0x8000);
        if (gCurrentObject->oUnlockDoorStarTimer++ == 20)
        {
            gCurrentObject->oUnlockDoorStarTimer = 0;
            gCurrentObject->oUnlockDoorStarState++; // Sets state to UNLOCK_DOOR_STAR_DONE
        }
        break;
    case UNLOCK_DOOR_STAR_DONE: // The object stays loaded for an additional 50 frames so that the sound doesn't immediately stop.
        if (gCurrentObject->oUnlockDoorStarTimer++ == 50)
            mark_object_for_deletion(gCurrentObject);
        break;
    }
    // Checks if the angle has cycled back to 0.
    // This means that the code will execute when the star completes a full revolution.
    if (prevYaw > (s16)gCurrentObject->oMoveAngleYaw)
        SetSound(SOUND_GENERAL_SHORTSTAR, &gCurrentObject->header.gfx.unk54); // Play a sound every time the star spins once
}

static Gfx *func_802769E0(struct Struct802769E0 *a, s16 b)
{
    Gfx *sp2C;
    Gfx *sp28 = NULL;

    if (b == 255)
    {
        a->unk2 = (a->unk2 & 0xFF) | 0x100;
        sp28 = alloc_display_list(2 * sizeof(*sp28));
        sp2C = sp28;
    }
    else
    {
        a->unk2 = (a->unk2 & 0xFF) | 0x500;
        sp28 = alloc_display_list(3 * sizeof(*sp28));
        sp2C = sp28;
        gDPSetAlphaCompare(sp2C++, G_AC_DITHER);
    }
    gDPSetEnvColor(sp2C++, 255, 255, 255, b);
    gSPEndDisplayList(sp2C);
    return sp28;
}

Gfx *Geo18_802770A4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    UNUSED u8 unused1[4];
    Gfx *sp28 = NULL;
    struct Struct802769E0 *sp24 = (struct Struct802769E0 *)b;
    struct Struct8033A040 *sp20 = &D_8033A040[sp24->unk18];
    s16 sp1E;
    UNUSED u8 unused2[4];

    if (a == 1)
    {
        sp1E = (sp20->unk8 & 0x100) ? (sp20->unk8 & 0xFF) : 255;
        sp28 = func_802769E0(sp24, sp1E);
    }
    return sp28;
}

Gfx *GeoSwitchCase80277150(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *sp4 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp0 = &D_8033A040[sp4->unk1C];

    if (a == 1)
        sp4->unk1E = ((sp0->unk0 & 0x200) == 0);
    return NULL;
}

Gfx *GeoSwitchCase802771BC(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *spC = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp8 = &D_8033A040[spC->unk1C];
    s16 sp6;

    if (a == 1)
    {
        if (sp8->unk5 == 0)
        {
            sp6 = ((spC->unk1C * 32 + gAreaUpdateCounter) >> 1) & 0x1F;
            if (sp6 < 7)
                spC->unk1E = D_8032CDF0[sp6];
            else
                spC->unk1E = 0;
        }
        else
        {
            spC->unk1E = sp8->unk5 - 1;
        }
    }
    return NULL;
}

Gfx *Geo18_80277294(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277294 *sp24 = (struct Struct80277294 *)b;
    struct Struct8033A040 *sp20 = &D_8033A040[sp24->unk18];
    int sp1C = sp20->unk0;

    if (a == 1)
    {
        struct Struct80277294_2 *sp18 = (struct Struct80277294_2 *)b->next;

        if (sp1C != 0x00840452 && sp1C != 0x00840454 && sp1C != 0x04000440 && sp1C != 0x20810446)
            vec3s_copy(sp20->unkC, D_80385FDC);
        sp18->unk18 = sp20->unkC[1];
        sp18->unk1A = sp20->unkC[2];
        sp18->unk1C = sp20->unkC[0];
    }
    return NULL;
}

Gfx *Geo18_802773A4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct802773A4 *sp2C = (struct Struct802773A4 *)b;
    struct Struct8033A040 *sp28 = &D_8033A040[sp2C->unk18];
    int sp24 = sp28->unk0;

    if (a == 1)
    {
        struct Struct802773A4_2 *sp20 = (struct Struct802773A4_2 *)b->next;
        u8 *sp1C = (u8 *)D_8032CF9C->unk18;

        if (*sp1C == 6)
        {
            sp20->unk18[0] = D_8033B1B0->unk16[1];
            sp20->unk18[2] = D_8033B1B0->unk16[0];
        }
        else if (sp24 & 0x20000000)
        {
            sp20->unk18[0] = sp28->unk12[1];
            sp20->unk18[1] = sp28->unk12[2];
            sp20->unk18[2] = sp28->unk12[0];
        }
        else
        {
            vec3s_set(sp28->unk12, 0, 0, 0);
            vec3s_set(sp20->unk18, 0, 0, 0);
        }
    }
    return NULL;
}

Gfx *GeoSwitchCase802774F4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *sp4 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp0 = &D_8033A040[0];

    if (a == 1)
    {
        if (sp0->unk6 == 0)
        {
            sp4->unk1E = ((sp0->unk0 & 0x10000000) != 0);
        }
        else
        {
            if (sp4->unk1C == 0)
                sp4->unk1E = (sp0->unk6 < 5) ? sp0->unk6 : 1;
            else
                sp4->unk1E = (sp0->unk6 < 2) ? sp0->unk6 : 0;
        }
    }
    return NULL;
}

Gfx *Geo18_802775CC(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct802775CC *spC = (struct Struct802775CC *)b;
    struct Struct80277150 *sp8 = (struct Struct80277150 *)b->next;
    struct Struct8033A040 *sp4 = &D_8033A040[0];

    if (a == 1)
    {
        sp8->unk18 = 1.0f;
        if (spC->unk18 == sp4->unkB >> 6)
        {
            if (D_8032CE0C != gAreaUpdateCounter && (sp4->unkB & 0x3F) > 0)
            {
                sp4->unkB--;
                D_8032CE0C = gAreaUpdateCounter;
            }
            sp8->unk18 = D_8032CDF8[spC->unk18 * 6 + (sp4->unkB & 0x3F)] / 10.0f;
        }
    }
    return NULL;
}

Gfx *GeoSwitchCase802776D8(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *sp4 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp0 = &D_8033A040[sp4->unk1C];

    if (a == 1)
        sp4->unk1E = sp0->unk8 >> 8;
    return NULL;
}

Gfx *GeoSwitchCase80277740(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct GraphNode *spC = b->next;
    struct Struct80277150 *sp8 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp4 = &D_8033A040[sp8->unk1C];

    if (a == 1)
    {
        sp8->unk1E = sp4->unk4 & 1;
        while (spC != b)
        {
            if (spC->type == 21)
            {
                if (sp4->unk4 & 2)
                    spC->flags |= 1;
                else
                    spC->flags &= ~1;
            }
            spC = spC->next;
        }
    }
    return NULL;
}

Gfx *Geo18_80277824(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    s16 spE;
    struct Struct80277824 *sp8 = (struct Struct80277824 *)b;

    if (a == 1)
    {
        struct Struct80277824_2 *sp4 = (struct Struct80277824_2 *)b->next;

        if (D_8033A040[sp8->unk18 >> 1].unk7 == 0)
            spE = (coss((gAreaUpdateCounter & 0xF) << 12) + 1.0f) * 4096.0f;
        else
            spE = (coss((gAreaUpdateCounter & 7) << 13) + 1.0f) * 6144.0f;
        if (!(sp8->unk18 & 1))
            sp4->unk18 = -spE;
        else
            sp4->unk18 = spE;
    }
    return NULL;
}

Gfx *Geo1C_8027795C(int a, struct GraphNode *b, Mat4 *c)
{
    struct Struct8027795C *sp2C = (struct Struct8027795C *)b;
    Mat4 *sp28 = c;
    struct MarioState *sp24 = &gMarioStates[sp2C->unk18];

    if (a == 1)
    {
        sp2C->unk1C = 0;
        if (sp24->heldObj != NULL)
        {
            sp2C->unk1C = sp24->heldObj;
            switch (sp24->unk98->unk0A)
            {
            case 1:
                if (sp24->action & ACT_FLAG_THROWING)
                    vec3s_set(sp2C->unk20, 50, 0, 0);
                else
                    vec3s_set(sp2C->unk20, 50, 0, 110);
                break;
            case 2:
                vec3s_set(sp2C->unk20, 145, -173, 180);
                break;
            case 3:
                vec3s_set(sp2C->unk20, 80, -270, 1260);
                break;
            }
        }
    }
    else if (a == 5)
    {
        func_8037A550(sp24->unk98->unk18, *sp28, D_8032CF9C->unk34);
    }
    return NULL;
}

Gfx *Geo18_80277B14(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    float sp34;
    struct Object *sp30 = gMarioStates->marioObj;

    switch (a)
    {
    case 0:
        init_graph_node_object(NULL, &D_80339FE0, NULL, D_80385FD0, D_80385FDC, D_80385FE4);
        break;
    case 3:
        func_8037C044(b, &D_80339FE0.node);
        break;
    case 2:
        func_8037C0BC(&D_80339FE0.node);
        break;
    case 1:
        if (sp30->header.gfx.pos[0] > 1700.0f)
        {
            // TODO: Is this a geo layout copy or a graph node copy?
            D_80339FE0.asGraphNode = sp30->header.gfx.asGraphNode;
            D_80339FE0.unk18 = sp30->header.gfx.unk18;
            vec3s_copy(D_80339FE0.angle, sp30->header.gfx.angle);
            vec3f_copy(D_80339FE0.pos, sp30->header.gfx.pos);
            vec3f_copy(D_80339FE0.scale, sp30->header.gfx.scale);
            // FIXME: why does this set unk38, an inline struct, to a ptr to another one? wrong
            // GraphNode types again?
            D_80339FE0.unk38 = *(struct GraphNodeObject_sub *)&sp30->header.gfx.unk38.animID;
            sp34 = 4331.53 - D_80339FE0.pos[0];
            D_80339FE0.pos[0] = sp34 + 4331.53;
            D_80339FE0.angle[1] = -D_80339FE0.angle[1];
            D_80339FE0.scale[0] *= -1.0f;
            // FIXME: Why doesn't this match?
            //D_80339FE0.node.flags |= 1;
            ((s16 *)&D_80339FE0)[1] |= 1;
        }
        else
        {
            // FIXME: Why doesn't this match?
            //D_80339FE0.node.flags &= ~1;
            ((s16 *)&D_80339FE0)[1] &= ~1;
        }
        break;
    }
    return NULL;
}

Gfx *Geo18_80277D6C(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277D6C *sp34 = (struct Struct80277D6C *)b;
    Gfx *sp30 = NULL;

    if (a == 1 && D_8032CFA0 == &D_80339FE0)
    {
        sp30 = alloc_display_list(3 * sizeof(*sp30));

        if (sp34->unk18 == 0)
        {
            gSPClearGeometryMode(&sp30[0], G_CULL_BACK);
            gSPSetGeometryMode(&sp30[1], G_CULL_FRONT);
            gSPEndDisplayList(&sp30[2]);
        }
        else
        {
            gSPClearGeometryMode(&sp30[0], G_CULL_FRONT);
            gSPSetGeometryMode(&sp30[1], G_CULL_BACK);
            gSPEndDisplayList(&sp30[2]);
        }
        sp34->node.flags = (sp34->node.flags & 0xFF) | 0x100;
    }
    return sp30;
}
