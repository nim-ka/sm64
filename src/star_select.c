#include <ultra64.h>

#include "sm64.h"
#include "game.h"
#include "memory.h"
#include "rendering.h"
#include "save_file.h"

#include "text_strings.h"

/*static*/ extern struct Object *sStarSelectIcons[];

static s8 sSelectedStar = 0;
static s8 D_801A8014 = 0;
static s32 D_801A8018 = 0;

void BehStarActSelectorLoop(void)
{
    switch (gCurrentObject->unkF4)
    {
    case 0:
        gCurrentObject->unk108 -= 0.1;
        if (gCurrentObject->unk108 < 1.0)
            gCurrentObject->unk108 = 1.0;
        gCurrentObject->faceAngle[1] = 0;
        break;
    case 1:
        gCurrentObject->unk108 += 0.1;
        if (gCurrentObject->unk108 > 1.3)
            gCurrentObject->unk108 = 1.3;
        gCurrentObject->faceAngle[1] += 0x800;
        break;
    case 2:
        gCurrentObject->faceAngle[1] += 0x800;
        break;
    }

    ScaleObject(gCurrentObject->unk108);
    gCurrentObject->unkF8++;
}

void func_80176934(u8 stars)
{
    if (stars & (1 << 6))
    {
        sStarSelectIcons[6] = func_8029E230(gCurrentObject, 0, 122, D_1300300C, 370, 24, -300, 0, 0, 0);
        sStarSelectIcons[6]->unk108 = 0.8;
        sStarSelectIcons[6]->unkF4 = 2;
    }
}

void BehActSelectorInit(void)
{
    s16 sp5E = 0;
    int sp34[10];
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum -1);

    D_801B9912 = 0;
    while (sp5E != D_801B9911)
    {
        if (stars & (1 << D_801B9912))
        {
            sp34[D_801B9912] = 122;
            sp5E++;
        }
        else
        {
            sp34[D_801B9912] = 121;
            if (D_801B9913 == 0)
            {
                D_801B9913 = D_801B9912 + 1;
                D_801A8014 = D_801B9912;
            }
        }
        D_801B9912++;
    }

    if (D_801B9912 == D_801B9911 && D_801B9912 != 6)
    {
        sp34[D_801B9912] = 121;
        D_801B9913 = D_801B9912 + 1;
        D_801A8014 = D_801B9912;
        D_801B9912++;
    }
    
    if (D_801B9911 == 6)
        D_801B9913 = D_801B9912;
    if (D_801B9911 == 0)
        D_801B9913 = 1;

    for (sp5E = 0; sp5E < D_801B9912; sp5E++)
    {
        sStarSelectIcons[sp5E] = func_8029E230(gCurrentObject, 0, sp34[sp5E], D_1300300C, 0x4B + D_801B9912 * -75 + sp5E * 152, 248, -300, 0, 0, 0);
        sStarSelectIcons[sp5E]->unk108 = 1.0f;
    }

    func_80176934(stars);
}

void BehActSelectorLoop(void)
{
    s8 i;
    u8 sp1E;
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum -1);

    if (D_801B9911 != 6)
    {
        sSelectedStar = 0;
        func_802D7924(2, &D_801A8014, 0, D_801B9911);
        sp1E = D_801A8014;
        for (i = 0; i < D_801B9912; i++)
        {
            if ((stars & (1 << i)) || i + 1 == D_801B9913)
            {
                if (sp1E == 0)
                {
                    sSelectedStar = i;
                    break;
                }
                sp1E--;
            }
        }
    }
    else
    {
        func_802D7924(2, &D_801A8014, 0, D_801B9912 - 1);
        sSelectedStar = D_801A8014;
    }

    for (i = 0; i < D_801B9912; i++)
    {
        if (sSelectedStar == i)
            sStarSelectIcons[i]->unkF4 = 1;
        else
            sStarSelectIcons[i]->unkF4 = 0;
    }
}

void ShowSomeNum(void)
{
    char buffer[4];

    func_802D6590(1, 158.0f, 81.0f, 0.0f);

    gSPDisplayList(gDisplayListHead++, mm7_f3d_00F228);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, seg2_f3d_00ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    Int2Str(gCurrCourseNum, buffer);
    if (gCurrCourseNum < 10)
        PutString(2, 152, 158, buffer);
    else
        PutString(2, 143, 158, buffer);

    gSPDisplayList(gDisplayListHead++, seg2_f3d_00ED68);
}

void func_80177004(void)
{
    char sp60[] = {TEXT_MYSCORE};
    char sp5C[] = {TEXT_0};
    u32 *sp58 = (u32 *)segmented_to_virtual(seg2_level_name_table);
    u32 sp54 = (u32) segmented_to_virtual((void *) sp58[gCurrCourseNum - 1]);
    u32 *sp50 = (u32 *)segmented_to_virtual(seg2_act_name_table);
    u32 sp4C;
    s16 sp4A;
    s16 sp48;
    s8 sp47;

    func_802D68A4();

    gSPDisplayList(gDisplayListHead++, seg2_f3d_00ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    ShowCoins(1, gCurrSaveFileNum - 1, gCurrCourseNum - 1, 155, 106);

    gSPDisplayList(gDisplayListHead++, seg2_f3d_00ED68);
    gSPDisplayList(gDisplayListHead++, seg2_f3d_00EE68);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    if (save_file_get_course_coin_score(gCurrSaveFileNum - 1, gCurrCourseNum - 1) != 0)
        PrintGenericText(102, 118, sp60);

    sp4A = func_802D7B3C(160, sp54 + 3, 10.0f);
    PrintGenericText(sp4A, 33, sp54 + 3);

    gSPDisplayList(gDisplayListHead++, seg2_f3d_00EEF0);

    ShowSomeNum();

    gSPDisplayList(gDisplayListHead++, mm7_f3d_00D108);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    if (D_801B9912 != 0)
    {
        sp4C = (u32) segmented_to_virtual((void *) (sp50[(gCurrCourseNum - 1) * 6 + sSelectedStar]));
        sp48 = func_802D7B3C(158, sp4C, 8.0f);
        PrintRegularText(sp48, 81, sp4C);
    }

    for (sp47 = 1; sp47 <= D_801B9912; sp47++)
    {
        sp5C[0] = sp47;
        PrintRegularText(sp47 * 34 - D_801B9912 * 17 + 0x8B, 38, sp5C);
    }

    gSPDisplayList(gDisplayListHead++, mm7_f3d_00D160);
}

int Geo18_80177518(s16 a, UNUSED int b)
{
    if (a == 1)
        func_80177004();
    return 0;
}

void LevelProc_80177560(UNUSED int a, UNUSED int b)
{
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

    D_801B9910 = 0;
    D_801B9913 = 0;
    D_801B9912 = 0;
    D_801A8018 = 0;
    D_801B9911 = save_file_get_course_star_count(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

    if (stars & 0x40)
        D_801B9911--;
}

int LevelProc_80177610(UNUSED int a, UNUSED int b)
{
    if (D_801A8018 >= 11)
    {
        if ((gPlayer2Controller->buttonPressed & A_BUTTON)
         || (gPlayer2Controller->buttonPressed & START_BUTTON)
         || (gPlayer2Controller->buttonPressed & B_BUTTON))
        {
            SetSound(0x701EFF81, D_803320E0);
            if (D_801B9913 > sSelectedStar)
                D_801B9910 = sSelectedStar + 1;
            else
                D_801B9910 = D_801B9913;
            D_80330534 = sSelectedStar + 1;
        }
    }
    func_8027ABB4();
    D_801A8018++;
    return D_801B9910;
}
