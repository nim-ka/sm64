#include <ultra64.h>
#include <stdarg.h>
#include "sm64.h"
#include "../libultra.h"

#include "gd_types.h"
#include "dynlists/dynlists.h"
#include "gd_tex_dl.h"

#include "mario_head_6.h"
#include "gd_main.h"
#include "debug_memory.h"
#include "game_over_1.h"
#include "game_over_2.h"
#include "mario_head_1.h"
#include "mario_head_4.h"
#include "profiler_utils.h"
#include "skin_fns.h"
#include "matrix_fns.h"
#include "half_6.h"

// types and defines
typedef s32 intptr_t;
typedef u32 uintptr_t;

#define MAX_GD_DLS 1000
#define OS_MESG_SI_COMPLETE 0x33333333
#define DEG_PER_RAD 57.29577950560105
#define RAD_PER_DEG (1.0 / DEG_PER_RAD)

#define GD_VIRTUAL_TO_PHYSICAL(addr) ((uintptr_t)(addr) & 0x0FFFFFFF)
#define GD_LOWER_24(addr) ((uintptr_t)(addr) & 0x00FFFFFF)
#define GD_LOWER_29(addr) (((uintptr_t) (addr)) & 0x1FFFFFFF)
#define ALIGN(VAL_, ALIGNMENT_) (((VAL_) + ((ALIGNMENT_) - 1)) & ~((ALIGNMENT_) - 1))
#define ABS(val) (((val) < 0 ? (-(val)) : (val)))
#define SQ(n) ((n) * (n))
#define MTX_INTPART_PACK(w1, w2)  (((w1) & 0xFFFF0000) | (((w2) >> 16) & 0xFFFF))
#define MTX_FRACPART_PACK(w1, w2) ((((w1) << 16) & 0xFFFF0000) | ((w2) & 0xFFFF))
#define LOOKAT_PACK(c) ((int) MIN(((c) * (128.0)),127.0) & 0xff)
// For fill cycle mode color packing
#define FILL_RGBA5551(r,g,b,a) ((GPACK_RGBA5551((r),(g),(b),(a)) << 16) | (GPACK_RGBA5551((r),(g),(b),(a))))

// structs
struct GdDisplayList {
    /* Vertices */
    /*0x00*/ s32 curVtxIdx;
    /*0x04*/ s32 totalVtx;
    /*0x08*/ Vtx *vtx;
    /* Matrices */
    /*0x0C*/ s32 curMtxIdx;
    /*0x10*/ s32 totalMtx;
    /*0x14*/ Mtx *mtx;
    /* Lights */
    /*0x18*/ s32 curLightIdx;
    /*0x1C*/ s32 totalLights;  
    /*0x20*/ Lights4 *light; 
    /* Gfx-es */
    /*0x24*/ s32 curGfxIdx;
    /*0x28*/ s32 totalGfx;
    /*0x2C*/ Gfx *gfx; // active position in DL
    /*0x30*/ Gfx **dlptr; // pointer to list/array of display lists?
    /* Viewports */
    /*0x34*/ s32 curVpIdx;
    /*0x38*/ s32 totalVp;
    /*0x3C*/ Vp *vp;
    /* GD DL Info */
    /*0x40*/ u32 unk40; // dl id? 
    /*0x44*/ u32 unk44; // number
    /*0x48*/ u8 pad48[4];
    /*0x4C*/ struct GdDisplayList *unk4C; // parent? 
}; /* sizeof = 0x50 */
// accessor macros for gd dl
#define DL_CURRENT_VTX(dl) ((dl)->vtx[(dl)->curVtxIdx])
#define DL_CURRENT_MTX(dl) ((dl)->mtx[(dl)->curMtxIdx])
#define DL_CURRENT_LIGHT(dl) ((dl)->light[(dl)->curLightIdx])
#define DL_LIGHT_IDX(dl, idx) ((dl)->unk20[(idx)])
#define DL_CURRENT_GFX(dl) ((dl)->gfx[(dl)->curGfxIdx])
#define DL_CURRENT_VP(dl) ((dl)->vp[(dl)->curVpIdx])

union UnkInternal {
    s32 w;
    struct {s8 b0, b1, b2, b3; } bytes;
};

struct Unk801BB1B8 {
    union UnkInternal u0, u4, u8;
}; // sizeof = 0x0C bytes

enum DynListBankFlag {
    TABLE_END = -1,
    STD_LIST_BANK = 3
};

struct DynListBankInfo {
    /* 0x00 */ enum DynListBankFlag flag;
    /* 0x04 */ struct DynList *list;
};

// bss
static OSContStatus D_801BAE60[4];
static OSContPad D_801BAE70[4];
static OSContPad sPrevFrameCont[4];            // @ 801BAE88
static u8 D_801BAEA0;
static struct ObjGadget *sTimerGadgets[GD_NUM_TIMERS]; // @ 801BAEA8
static u32 D_801BAF28;                         // RAM addr offset?
static s16 D_801BAF30[13][8];                  // [[s16; 8]; 13]? vert indices?
static u32 unref_801bb000[3];
static u8 *sMemBlockPoolBase;                  // @ 801BB00C
static u32 sAllocMemory;                       // @ 801BB010; malloc-ed bytes
static u32 unref_801bb014;
static s32 D_801BB018;
static s32 D_801BB01C;
static void *D_801BB020[0x10];                 // texture pointers
static s32 D_801BB060[0x10];                   // gd_dl indices
static s16 D_801BB0A0[2];                      // texture coordinates ?
static s32 D_801BB0A4;                         // gd_dl index
static struct ObjGroup *D_801BB0A8;            // yoshi scene group?
static s32 D_801BB0AC;                         // unused DL number
static struct ObjGroup *D_801BB0B0;            // mario head group?
static s32 D_801BB0B4;                         //second offset into D_801BAF30
static struct ObjGroup *D_801BB0B8;            // car group?
static s32 D_801BB0BC;                         // Vtx len in GD Dl and in the lower bank (AF30)
static struct ObjView *D_801BB0C0;             // yoshi scene view?
static s32 D_801BB0C4;                         //first offset into D_801BAF30
static struct ObjView *D_801BB0C8;             // mario scene view?
static s32 D_801BB0CC;                         // Vtx start in GD Dl
static struct ObjView *D_801BB0D0;             // mario scene view?
static s32 D_801BB0D4;                         // bool check for yoshi scene to X?
static s32 D_801BB0D8;                         // bool check for mario head scene to X?
static u32 unref_801bb0dc;
static s32 D_801BB0E0;
static u32 unref_801bb0e4;
static struct MyVec3f D_801BB0E8;
static u32 unref_801bb0f8[2];
static Mtx sIdnMtx;                            // @ 801BB100
static Mat4 sInitIdnMat4;                      // @ 801BB140
static s8 D_801BB180[3];                       // normals ?
static s16 D_801BB184;
static s32 D_801BB188;
static struct GdColour sAmbScaleColour;        // @ 801BB190
static struct GdColour sLightScaleColours[2];  // @ 801BB1A0
static struct Unk801BB1B8 D_801BB1B8[2];
static s32 D_801BB1D0;
static Hilite D_801BB1D8[600];
static struct MyVec3f D_801BD758;
static struct MyVec3f D_801BD768;              // had to migrate earlier
static u32 D_801BD774;
/* static */ struct ObjHeader *D_801BD778[9];  // d_obj ptr storage? menu? (fix non-matching)
static struct ObjView *D_801BD7A0[2];
static struct GdDisplayList *sStaticDl;        // @ 801BD7A8
static struct GdDisplayList *sDynDlSet1[2];    // @ 801BD7B0
static struct GdDisplayList *sGdDlStash;       // @ 801BD7B8
static struct GdDisplayList *D_801BD7C0[2];
static struct GdDisplayList *D_801BD7C8[3][2]; // I guess? 801BD7C8 -> 801BD7E0?
static struct GdDisplayList * sGdDLArray[MAX_GD_DLS]; // @ 801BD7E0
static s32 sHalfBufLen;                        // @ 801BE780
static s32 sHalfBufPosition;                   // @ 801BE784
static s16 *sHalfBuf;                          // @ 801BE788
static LookAt D_801BE790[2];
static LookAt D_801BE7D0[3];
static OSMesgQueue D_801BE830;                 //controller msg queue
static OSMesg D_801BE848[10];
static u32 unref_801be870[16];
static OSMesgQueue D_801BE8B0;
static OSMesgQueue sGdDMAQueue;                // @ 801BE8C8
static u32 unref_801be8e0[25];
static OSMesg sGdMesgBuf[1];                   // @ 801BE944
static u32 unref_801be948[13];
static OSMesg D_801BE97C;                      // msg buf for D_801BE8B0 queue
/* There seems to be overlapping symbols:
 * OSIoMesg D_801BE980 @ 801BE980
 * struct ObjView *D_801BE994 @ 801BE994
 * The `ObjView *` overlaps a pointer to an `OSPiHandle` in the OSIoMesg structure. 
 * If anyone has a better guess (or wants to dig deep into the `OSPiHandle` struct 
 * to expose some internal interface), feel free to get rid of this union
 */
static union HackType {
    OSIoMesg D_801BE980;
    struct BssHack {
        u8 pad[0x14];
        struct ObjView *view;
    } D_801BE994;
} sGdBssOverlap;

// data
static u32 unref_801a8670 = 0;
static s32 D_801A8674 = 0;
static u32 unref_801a8678 = 0;
static s32 D_801A867C = 0;
static s32 D_801A8680 = 0;
static f32 sTracked1FrameTime = 0.0f;             // @ 801A8684
static f32 sDynamicsTime = 0.0f;                  // @ 801A8688
static f32 sDLGenTime = 0.0f;                     // @ 801A868C
static f32 sRCPTime = 0.0f;                       // @ 801A8690
static f32 sTimeScaleFactor = 1.0f;               // @ D_801A8694
static u32 sMemBlockPoolSize = 1;                 // @ 801A8698
static s32 sMemBlockPoolUsed = 0;                 // @ 801A869C
static s32 D_801A86A0 = 0;
static struct GdTimer *D_801A86A4 = NULL;         // timer for dlgen, dynamics, or rcp
static struct GdTimer *D_801A86A8 = NULL;         // timer for dlgen, dynamics, or rcp
static struct GdTimer *D_801A86AC = NULL;         // timer for dlgen, dynamics, or rcp
s32 gGdFrameBuf = 0;                              // @ 801A86B0
static u32 unref_801a86B4 = 0;
static struct ObjShape *sHandShape = NULL;        // @ 801A86B8
static s32 D_801A86BC = 1;
static s32 D_801A86C0 = 0;                        // gd_dl id for something?
static u32 unref_801a86C4 = 10;
static s32 sMtxParameters = (G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH); // @ 801A86C8;
static struct MyVec3f D_801A86CC = { 1.0f, 1.0f, 1.0f };
static struct ObjView *D_801A86D8 = NULL;         // current view? pointer to mscene view in game...
static struct ObjView *sScreenView2 = NULL;       // @ 801A86DC
static struct ObjView *D_801A86E0 = NULL;
/* static */ struct ObjView *sHandView = NULL;    // @ 801A86E4 (fix nonmatching for static)
/* static */ struct ObjView *sMenuView = NULL;    // @ 801A86E8 (fix nonmatching for static)
/* static */ u32 sItemsInMenu = 0;                // @ 801A86EC (fix nonmatching for static)
static s32 D_801A86F0 = 0;                        // frame buffer idx into D_801BD7A0?
static s32 D_801A86F4 = 0;                        // timing activate / z press counter?
static u32 unref_801a86F8 = 0;
static struct GdDisplayList *sCurrentGdDl = NULL; // @ 801A86FC
static u32 sGdDlCount = 0;                        // @ 801A8700
static struct DynListBankInfo D_801A8704[] = {
    { STD_LIST_BANK, dynlist_04000000 },
    { STD_LIST_BANK, dynlist_04000650 },
    { STD_LIST_BANK, dynlist_04004F90 },
    { TABLE_END, NULL }
};
/*  It doesn't really make sense for this DL command to be here,
 * unless all of goddard's texture data were also in C... 
 * So, to avoid that, throw a stray gsSPEndDisplayList here */ 
static u64 strayDlEndCmd = 0xB800000000000000; // @ 801A8728

// linker (ROM addresses)
extern u8 _gd_dynlistsSegmentRomStart[];
extern u8 _gd_dynlistsSegmentRomEnd[];

// forward declarations
u32 func_8019EC08(void *addr, UNUSED s32); // returns GdDisplayList id?
void gd_setup_cursor(struct ObjGroup *);
void func_801A2844(void);
void func_801A4C0C(void);
void func_801A5168(struct ObjView *);
void func_801A1A00(void);
void func_801A2388(s32);
void func_801A3370(f32, f32, f32);
void gd_put_sprite(u16 *, s32, s32, s32, s32);


u32 get_alloc_mem_amt(void)
{
    return sAllocMemory;
}

s32 gd_get_ostime(void)
{
    return osGetTime();
}

f32 get_time_scale(void)
{
    return sTimeScaleFactor;
}

void dump_disp_list(void)
{
    gd_printf("%d\n", sCurrentGdDl->unk40);
    gd_printf("Vtx=%d/%d, Mtx=%d/%d, Light=%d/%d, Gfx=%d/%d\n", 
        sCurrentGdDl->curVtxIdx,   sCurrentGdDl->totalVtx, 
        sCurrentGdDl->curMtxIdx,   sCurrentGdDl->totalMtx, 
        sCurrentGdDl->curLightIdx, sCurrentGdDl->totalLights, 
        sCurrentGdDl->curGfxIdx,   sCurrentGdDl->totalGfx
    );
}

Gfx *next_gfx(void)
{
    if (sCurrentGdDl->curGfxIdx >= sCurrentGdDl->totalGfx)
    {
        dump_disp_list();
        fatal_printf("Gfx list overflow");
    }

    return &sCurrentGdDl->gfx[sCurrentGdDl->curGfxIdx++];
}

Lights4 *next_light(void)
{
    if (sCurrentGdDl->curLightIdx >= sCurrentGdDl->totalLights)
    {
        dump_disp_list();
        fatal_printf("Light list overflow");
    }

    return &sCurrentGdDl->light[sCurrentGdDl->curLightIdx++];
}

Mtx *next_mtx(void)
{
    if (sCurrentGdDl->curMtxIdx >= sCurrentGdDl->totalMtx)
    {
        dump_disp_list();
        fatal_printf("Mtx list overflow");
    }

    return &sCurrentGdDl->mtx[sCurrentGdDl->curMtxIdx++];
}

Vtx *next_vtx(void)
{
    if (sCurrentGdDl->curVtxIdx >= sCurrentGdDl->totalVtx)
    {
        dump_disp_list();
        fatal_printf("Vtx list overflow");
    }

    return &sCurrentGdDl->vtx[sCurrentGdDl->curVtxIdx++];
}

/* 249A20 -> 249AAC */
Vp *next_vp(void)
{
    if (sCurrentGdDl->curVpIdx >= sCurrentGdDl->totalVp)
    {
        dump_disp_list();
        fatal_printf("Vp list overflow");
    }

    return &sCurrentGdDl->vp[sCurrentGdDl->curVpIdx++];
}

/* 249AAC -> 249AEC */
f64 gd_sin_d(f64 x)
{
    return (f64) sinf((f32) x);
}

/* 249AEC -> 249B2C */
f64 gd_cos_d(f64 x)
{
    return (f64) cosf((f32) x);
}

/* 249B2C -> 249BA4 */
f64 gd_sqrt_d(f64 x)
{
    if (x < 1.0e-7) { return 0.0; }
    return (f64) sqrtf((f32) x);
}

/* 249BA4 -> 249BCC */
f64 Unknown8019B3D4(UNUSED f64 x)
{
    return 0.0;
}

/* 249BCC -> 24A19C */
#define BUFSIZE 0x100
void gd_printf(const char *format, ...)
{
    int i;              // 15c
    UNUSED u32 pad158;
    char c;             // 157
    char f;             // 156
    UNUSED u32 pad150;
    char buf[BUFSIZE];  // 50
    char *csr = buf;    // 4c
    char spec[8];       // 44; goddard specifier string
    UNUSED u32 pad40;
    union PrintVal val; // 38;
    va_list args;       // 34

    *csr = '\0';
    va_start(args, format);
    while ((c = *format++))
    { // L8019B45C
        switch (c) 
        {
        case '%':
            f = *format++;
            i = 0;

            // handle float precision formatter (N.Mf)
            if (f >= '0' && f <= '9')
            {
                for (i = 0; i < 3; i++)
                { // L8019B4CC
                    if ((f >= '0' && f <= '9') || f == '.')
                    {
                        spec[i] = f;
                    }
                    else
                    { // L8019B510
                        break;
                    }
                    // L8019B518
                    f = *format++;
                }
            }
            // L8019B548
            spec[i] = f;
            i++;
            spec[i] = '\0';

            switch ((c = spec[0]))
            {
            case 'd':
                val.i = va_arg(args, int);
                csr = sprint_val_withspecifiers(csr, val, spec);
                break;
            case 'x':
                val.i = va_arg(args, unsigned int);
                csr = sprint_val_withspecifiers(csr, val, spec);
                break;
            case '%':
                *csr = '%';
                csr++;
                *csr = '\0';
                break;
                break; //! needed to match
            case 'f':
                val.f = (f32) va_arg(args, double);
                csr = sprint_val_withspecifiers(csr, val, spec);
                break;
            case 's':
                csr = gd_strcat(csr, va_arg(args, char *));
                break;
            case 'c':
                *csr = va_arg(args, int); //! should be char
                csr++;
                *csr = '\0';
                break;
            default:
                if (spec[3] == 'f')
                {
                    val.f = (f32) va_arg(args, double);
                    csr = sprint_val_withspecifiers(csr, val, spec);
                }
                // L8019B8BC
                break;
            }
            // L8019B8C4
            break;
        case '\\':
            *csr = '\\';
            csr++;
            *csr = '\0';
            break;
        case '\n':
            *csr = '\n';
            csr++;
            *csr = '\0';
            break;
        default:
            *csr = c;
            csr++;
            *csr = '\0';
            break;
        }
        // L8019B960 loop
    }
    va_end(args);
    // L8019B980
    *csr = '\0';
    if ((intptr_t)csr - (intptr_t)buf >= BUFSIZE - 1)
    {
        fatal_printf("printf too long");
    }
}
#undef BUFSIZE

/* 24A19C -> 24A1D4 */
void gd_exit(UNUSED s32 code)
{
    gd_printf("exit\n");
    while (TRUE) {}
}

/* 24A1D4 -> 24A220; orig name: func_8019BA04 */
void gd_free(void *ptr)
{
    sAllocMemory -= gd_free_mem(ptr);
}

/* 24A220 -> 24A318 */
void *gd_allocblock(u32 size)
{
    void *block; // 1c

    size = ALIGN(size, 8);
    if ((sMemBlockPoolUsed + size) > sMemBlockPoolSize)
    {
        gd_printf("gd_allocblock(): Failed request: %dk (%d bytes)\n",
            size / 1024,
            size
        );
        gd_printf("gd_allocblock(): Heap usage: %dk (%d bytes) \n",
            sMemBlockPoolUsed / 1024,
            sMemBlockPoolUsed
        );
        print_all_memtrackers();
        mem_stats();
        fatal_printf("exit");
    }
    //L8019BAF0
    block = sMemBlockPoolBase + sMemBlockPoolUsed;
    sMemBlockPoolUsed += size;
    return block;
}

/* 24A318 -> 24A3E8 */
void *gd_malloc(u32 size, u8 perm)
{
    void *ptr; // 1c
    size = ALIGN(size, 8);
    ptr = gd_request_mem(size, perm);

    if (ptr == NULL)
    {
        gd_printf("gd_malloc(): Failed request: %dk (%d bytes)\n",
            size / 1024,
            size
        );
        gd_printf("gd_malloc(): Heap usage: %dk (%d bytes) \n",
            sAllocMemory / 1024,
            sAllocMemory
        );
        print_all_memtrackers();
        mem_stats();
        return NULL;
    }

    sAllocMemory += size;

    return ptr;
}

/* 24A3E8 -> 24A420; orig name: func_8019BC18 */
void *gd_malloc_perm(u32 size)
{
    return gd_malloc(size, PERM_G_MEM_BLOCK);
}

/* 24A420 -> 24A458; orig name: func_8019BC50 */
void *gd_malloc_temp(u32 size)
{
    return gd_malloc(size, TEMP_G_MEM_BLOCK);
}

/* 24A458 -> 24A4A4 */
void *Unknown8019BC88(u32 size, u32 count)
{
    return gd_malloc_perm(size * count);
}

/* 24A4A4 -> 24A4DC */
void *Unknown8019BCD4(u32 size)
{
    return gd_malloc_perm(size);
}

/* 24A4DC -> 24A598 */
void func_8019BD0C(s32 a0, s32 a1)
{
    Gfx *dl; // 1c

    if (a1 != 0)
    {
        dl = sGdDLArray[a0]->dlptr[a1 - 1];
    }
    else
    {
        dl = sGdDLArray[a0]->gfx;
    }
    gSPDisplayList(next_gfx(), GD_VIRTUAL_TO_PHYSICAL(dl));

}

/* 24A598 -> 24A610 */
// TODO: id? goto to dl?
void func_8019BDC8(s32 a0)
{
    Gfx *dl; // 24
    UNUSED u32 pad[2];

    dl = sGdDLArray[a0]->gfx;
    gSPDisplayList(next_gfx(), GD_VIRTUAL_TO_PHYSICAL(dl));
}

/* 24A610 -> 24A640 */
Gfx *Unknown8019BE40(s32 id)
{
    return sGdDLArray[id]->gfx;
}

/* 24A640 -> 24A8D0; orig name: func_8019BE70 */
void setup_stars(void)
{
    gShapeRedStar = make_shape(0, "redstar");
    gShapeRedStar->unk48[0] = func_8019EC08(NULL, 0);
    gShapeRedStar->unk48[1] = gShapeRedStar->unk48[0];
    sGdDLArray[gShapeRedStar->unk48[0]]->dlptr = redStarDlArray;
    sGdDLArray[gShapeRedStar->unk48[1]]->dlptr = redStarDlArray;

    gShapeSilverStar = make_shape(0, "silverstar");
    gShapeSilverStar->unk48[0] = func_8019EC08(NULL, 0);
    gShapeSilverStar->unk48[1] = gShapeSilverStar->unk48[0];
    sGdDLArray[gShapeSilverStar->unk48[0]]->dlptr = silverStarDlArray;
    sGdDLArray[gShapeSilverStar->unk48[1]]->dlptr = silverStarDlArray;

    // TODO: what way should we name these? based on goddard's name, or on what they do/actually are?
    gShapeSilSpark = make_shape(0, "sspark");
    gShapeSilSpark->unk48[0] = func_8019EC08(NULL, 0);
    gShapeSilSpark->unk48[1] = gShapeSilSpark->unk48[0];
    sGdDLArray[gShapeSilSpark->unk48[0]]->dlptr = redSparkleDlArray;
    sGdDLArray[gShapeSilSpark->unk48[1]]->dlptr = redSparkleDlArray;

    gShapeRedSpark = make_shape(0, "rspark");
    gShapeRedSpark->unk48[0] = func_8019EC08(NULL, 0);
    gShapeRedSpark->unk48[1] = gShapeRedSpark->unk48[0];
    sGdDLArray[gShapeRedSpark->unk48[0]]->dlptr = silverSparkleDlArray;
    sGdDLArray[gShapeRedSpark->unk48[1]]->dlptr = silverSparkleDlArray;
}

/* 24A8D0 -> 24AA40 */
void setup_timers(void)
{
    start_timer("updateshaders");
    stop_timer("updateshaders");
    start_timer("childpos");
    stop_timer("childpos");
    start_timer("netupd");
    stop_timer("netupd");
    start_timer("drawshape2d");
    stop_timer("drawshape2d");

    start_timer("drawshape");
    start_timer("drawobj");
    start_timer("drawscene");
    start_timer("camsearch");
    start_timer("move_animators");
    start_timer("move_nets");
    stop_timer("move_animators");
    stop_timer("move_nets");
    stop_timer("drawshape");
    stop_timer("drawobj");
    stop_timer("drawscene");
    stop_timer("camsearch");

    start_timer("move_bones");
    stop_timer("move_bones");
    start_timer("move_skin");
    stop_timer("move_skin");
    start_timer("draw1");
    stop_timer("draw1");
    start_timer("dynamics");
    stop_timer("dynamics");
}

/* 24AA40 -> 24AA58 */
void Unknown8019C270(u8 *buf)
{
    gGdStreamBuffer = buf;
}

/* 24AA58 -> 24AAA8 */
void Unknown8019C288(s32 a0, s32 a1)
{
    struct GdControl *sp4 = &D_801B9920;

    sp4->unk7C = (f32) a0;
    sp4->unk80 = (f32) (a1 / 2);
}

/* 24AAA8 -> 24AAE0; orig name: func_8019C2D8 */
void gd_add_to_heap(void *addr, u32 size)
{
    //TODO: is this `1` for permanance special?
    gd_add_mem_to_heap(size, (uintptr_t) addr, 1);
}

/* 24AAE0 -> 24AB7C */
void gdm_init(void *blockpool, u32 size)
{
    UNUSED u32 pad;

    add_to_stacktrace("gdm_init");
    // Align downwards?
    size = (size - 8) & ~7;
    // Align to next double word boundry?
    blockpool = (void *)(((uintptr_t)blockpool + 8) & ~7);
    sMemBlockPoolBase = blockpool;
    sMemBlockPoolSize = size;
    sMemBlockPoolUsed = 0;
    sAllocMemory = 0;
    init_mem_block_lists();
    func_801780A0();
    imout();
}

/* self */ void func_8019E75C(void);

/* 24AB7C -> 24AC18 */
void gdm_setup(void)
{
    UNUSED u32 pad;

    add_to_stacktrace("gdm_setup");
    D_801BB0A8 = NULL;
    D_801BB0B0 = NULL;
    D_801BB0D4 = FALSE;
    D_801BB0D8 = FALSE;
    D_801BB0A4 = 0;
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osCreateMesgQueue(&sGdDMAQueue, sGdMesgBuf, ARRAY_COUNT(sGdMesgBuf));
    gd_init();
    load_shapes2();
    func_8019E75C();
    setup_stars();
    imout();
}

/* 24AC18 -> 24AC2C */
void Unknown8019C448(UNUSED u32 a0)
{
}

/* 24AC2C -> 24AC80; not called; orig name: Unknown8019C45C */
void print_gdm_stats(void)
{
    stop_memtracker("total");
    gd_printf("\ngdm stats:\n");
    print_all_memtrackers();
    mem_stats();
    start_memtracker("total");
}

/* 24AC80 -> 24AD14; orig name: func_8019C4B0 */
struct ObjView *make_view_withgrp(char *name, struct ObjGroup *grp)
{
    struct ObjView *view;            // 2c
    UNUSED struct ObjGroup *viewgrp; // 28
    // TODO: 0x00040000 is an unknown object type, or am I wrong with the field?
    view = make_view(name, 
        OBJ_TYPE_LIGHTS|OBJ_TYPE_SHAPES|0x40000, 
        1, 0, 0,
        320, 240,
        grp
    );
    viewgrp = make_group(2, grp, view);
    view->unk2C = D_801B9BB8;

    return view;
}

/* 24AD14 -> 24AEB8 */
void gdm_maketestdl(s32 id)
{
    UNUSED u32 pad[3];

    add_to_stacktrace("gdm_maketestdl");
    switch (id)
    {
        case 0:
            D_801BB0C0 = make_view_withgrp("yoshi_scene", D_801BB0A8);
            break;
        case 1: // reset gadgets in group?
            func_801814F4(D_801BB0A8);
            break;
        case 2: // normal mario head
            if (D_801BB0B0 == NULL)
            {
                func_8019A378(Proc8019A068);
                D_801BB0B0 = gMarioFaceGrp;
                gd_setup_cursor(NULL);
            }
            D_801BB0C8 = make_view_withgrp("mscene", D_801BB0B0);
            break;
        case 3: // game over mario head
            if (D_801BB0B0 == NULL)
            {
                func_8019A378(Proc80199FA0);
                D_801BB0B0 = gMarioFaceGrp;
                gd_setup_cursor(NULL);
            }
            D_801BB0C8 = make_view_withgrp("mscene", D_801BB0B0);
            break;
        case 4:
            D_801BB0D0 = make_view_withgrp("car_scene", D_801BB0B8);
            break;
        case 5:
            func_801814F4(D_801BB0B8);
            break;
        default:
            fatal_printf("gdm_maketestdl(): unknown dl");
    }
    imout();
}

/* 24AEB8 -> 24AED0 */
void set_time_scale(f32 factor)
{
    sTimeScaleFactor = factor;
}

/* 24AED0 -> 24AF04 */
void Unknown8019C840(void)
{
    gd_printf("\n");
    print_all_timers();
}

/* 24AF04 -> 24AFC0 */
void Proc8019C734(void)
{
    func_801780EC();
    if (D_801BB0D4)
    {
        apply_to_obj_types_in_group(
            OBJ_TYPE_NETS,
            Proc801933FC,
            D_801BB0A8
        );
    }
    if (D_801BB0D8)
    {
        apply_to_obj_types_in_group(
            OBJ_TYPE_NETS,
            Proc801933FC,
            D_801BB0B0
        );
    }
    D_801BB0D4 = FALSE;
    D_801BB0D8 = FALSE;
    gGdFrameBuf ^= 1;
    func_8019E75C();
    func_801A2844();
    func_801A4C0C();
}

/* 24AFC0 -> 24B058; orig name: func_8019C7F0 */
void gd_copy_p1_contpad(OSContPad *p1cont)
{
    unsigned int i;                         // 24
    u8 *contdata = (u8 *)p1cont;            // 20
    u8 *gd_contdata = (u8 *)&D_801BAE70[0]; // 1c

    for (i = 0; i < sizeof(OSContPad); i++)
    {
        gd_contdata[i] = contdata[i];
    }

    if (p1cont->button & Z_TRIG)
    {
        print_all_timers();
    }
}

/* 24B058 -> 24B088 */
s32 func_8019C888(void)
{
    return func_801780C0();
}

/* 24B088 -> 24B418 */
void *gdm_gettestdl(s32 id)
{
    struct ObjHeader *sp34;
    struct GdDisplayList *sp30;
    UNUSED u32 pad28[2];
    struct MyVec3f sp1C;
    
    start_timer("dlgen");
    sp1C.x = sp1C.y = sp1C.z = 0.0f;
    sp30 = NULL;

    switch (id)
    {
        case 0:
            if (D_801BB0C0 == NULL)
            {
                fatal_printf("gdm_gettestdl(): DL number %d undefined", id);
            }
            apply_to_obj_types_in_group(
                OBJ_TYPE_VIEWS,
                update_view,
                D_801BB0C0
            );
            sp34 = d_use_obj("yoshi_scene");
            sp30 = sGdDLArray[((struct ObjView *)sp34)->unk70];
            D_801BB0D4 = TRUE;
            break;
        case 1:
            if (D_801BB0A8 == NULL)
            {
                fatal_printf("gdm_gettestdl(): DL number %d undefined", id);
            }
            sp34 = d_use_obj("yoshi_sh_l1");
            sp30 = sGdDLArray[((struct ObjShape *)sp34)->unk48[gGdFrameBuf]];
            D_801BB0D4 = TRUE;
            break;
        case 2:
        case 3:
            setup_timers();
            func_801A5168(D_801BB0C8);
            if (sHandView != NULL)
            {
                func_801A5168(sHandView);
            }
            sCurrentGdDl = D_801BD7C0[gGdFrameBuf];
            gSPEndDisplayList(next_gfx());
            sp30 = sCurrentGdDl;
            D_801BB0D8 = TRUE;
            break;
        case 4:
            if (D_801BB0D0 == NULL)
            {
                fatal_printf("gdm_gettestdl(): DL number %d undefined", id);
            }
            apply_to_obj_types_in_group(
                OBJ_TYPE_VIEWS,
                update_view,
                D_801BB0D0
            );
            sp34 = d_use_obj("car_scene");
            sp30 = sGdDLArray[((struct ObjView *)sp34)->unk70];
            D_801BB0E0 = TRUE;
            break;
        case 5:
            D_801A86D8 = sScreenView2;
            set_gd_mtx_parameters(6);
            sp34 = d_use_obj("testnet2");
            D_801BB0A4 = gd_startdisplist(8);

            if (D_801BB0A4 == 0)
            {
                fatal_printf("no memory for car DL\n");
            }
            apply_obj_draw_fn(sp34);
            gd_end_dl();
            sp30 = sGdDLArray[D_801BB0A4];
            D_801BB0E0 = TRUE;
            break;
        default:
            fatal_printf("gdm_gettestdl(): %d out of range", id);
    }

    if (sp30 == NULL)
    {
        fatal_printf("no display list");
    }
    stop_timer("dlgen");
    return (void *)osVirtualToPhysical(sp30->gfx);
}

/* 24B418 -> 24B4CC; not called */
void gdm_getpos(s32 id, struct MyVec3f *dst)
{
    struct ObjHeader *dobj; // 1c
    switch (id)
    {
        case 5:
            set_gd_mtx_parameters(6);
            dobj = d_use_obj("testnet2");
            dst->x = ((struct ObjNet *)dobj)->unk14.x;
            dst->y = ((struct ObjNet *)dobj)->unk14.y;
            dst->z = ((struct ObjNet *)dobj)->unk14.z;
            break;
        default:
            fatal_printf("gdm_getpos(): %d out of range", id);
    }
    return;
}

/* 24B4CC -> 24B5A8 */
void func_8019CCFC(f32 *x, f32 *y)
{
    struct ObjView *view = D_801A86D8;

    if (*x < 0.0f)
    {
        *x = 0.0f;
    }
    else if (*x > view->unk54.x)
    {
        *x = view->unk54.x;
    }

    if (*y < 0.0f)
    {
        *y = 0.0f;
    }
    else if (*y > view->unk54.y)
    {
        *y = view->unk54.y;
    }
}

/* 24B5A8 -> 24B5D4; orig name: func_8019CDD8 */
void fatal_no_dl_mem(void)
{
    fatal_printf("Out of DL mem\n");
}

/* 24B5D4 -> 24B6AC */
struct GdDisplayList *alloc_displaylist(u32 id)
{
    struct GdDisplayList *gdDl;

    gdDl = gd_malloc_perm(sizeof(struct GdDisplayList));
    if (gdDl == NULL)
    {
        fatal_no_dl_mem();
    }
    
    gdDl->unk44 = sGdDlCount++;
    if (sGdDlCount >= MAX_GD_DLS)
    {
        fatal_printf("alloc_displaylist() too many display lists %d (MAX %d)", 
            sGdDlCount + 1, 
            MAX_GD_DLS
        );
    }
    sGdDLArray[gdDl->unk44] = gdDl;
    gdDl->unk40 = id;
    return gdDl;
}

/* 24B6AC -> 24B7A0; orig name: func_8019CEDC */
void cpy_remaining_gddl(struct GdDisplayList *dst, struct GdDisplayList *src)
{
    dst->vtx = &DL_CURRENT_VTX(src); //&src->unk8[src->unk0];
    dst->mtx = &DL_CURRENT_MTX(src);
    dst->light = &DL_CURRENT_LIGHT(src);
    dst->gfx = &DL_CURRENT_GFX(src);
    dst->vp = &DL_CURRENT_VP(src);
    dst->totalVtx = src->totalVtx - src->curVtxIdx;
    dst->totalMtx = src->totalMtx - src->curMtxIdx;
    dst->totalLights = src->totalLights - src->curLightIdx;
    dst->totalGfx = src->totalGfx - src->curGfxIdx;
    dst->totalVp = src->totalVp - src->curVpIdx;
    dst->curVtxIdx = 0;
    dst->curMtxIdx = 0;
    dst->curLightIdx = 0;
    dst->curGfxIdx = 0;
    dst->curVpIdx = 0;
}

/* 24B7A0 -> 24B7F8; orig name: func_8019CFD0 */
struct GdDisplayList *create_child_gdl(s32 id, struct GdDisplayList *srcDl)
{
    struct GdDisplayList *newDl;

    newDl = alloc_displaylist(id);
    newDl->unk4C = srcDl;
    cpy_remaining_gddl(newDl, srcDl);
    //! no return, despite return value being used
}

/* 24B7F8 -> 24BA48; orig name: func_8019D028 */
struct GdDisplayList *new_gd_dl(s32 id, s32 gfxs, s32 verts, s32 mtxs, s32 lights, s32 vps)
{
    struct GdDisplayList *dl; // 24

    dl = alloc_displaylist(id);
    dl->unk4C = NULL;
    if (verts == 0) { verts = 1; }
    dl->curVtxIdx = 0;
    dl->totalVtx = verts;
    if ((dl->vtx = gd_malloc_perm(verts * sizeof(Vtx))) == NULL)
    {
        fatal_no_dl_mem();
    }

    if (mtxs == 0) { mtxs = 1; }
    dl->curMtxIdx = 0;
    dl->totalMtx = mtxs;
    if ((dl->mtx = gd_malloc_perm(mtxs * sizeof(Mtx))) == NULL)
    {
        fatal_no_dl_mem();
    }

    if (lights == 0) { lights = 1; }
    dl->curLightIdx = 0;
    dl->totalLights = lights;
    if ((dl->light = gd_malloc_perm(lights * sizeof(Lights4))) == NULL)
    {
        fatal_no_dl_mem();
    }

    if (gfxs == 0) { gfxs = 1; }
    dl->curGfxIdx = 0;
    dl->totalGfx = gfxs;
    if ((dl->gfx = gd_malloc_perm(gfxs * sizeof(Gfx))) == NULL)
    {
        fatal_no_dl_mem();
    }

    if (vps == 0) { vps = 1; }
    dl->curVpIdx = 0;
    dl->totalVp = vps;
    if ((dl->vp = gd_malloc_perm(vps * sizeof(Vp))) == NULL)
    {
        fatal_no_dl_mem();
    }

    dl->dlptr = NULL;
    return dl;
}

/* 24BA48 -> 24BABC; not called */
void gd_init_RSP(void)
{
    gSPDisplayList(next_gfx(), osVirtualToPhysical(&marioHeadDl801B5170));
    gDPPipeSync(next_gfx());
}

/* 24BABC -> 24BB30; not called */
void gd_init_RDP(void)
{
    gSPDisplayList(next_gfx(), osVirtualToPhysical(&marioHeadDl801B5188));
    gDPPipeSync(next_gfx());
}

/* 24BB30 -> 24BED8; orig name: func_8019D360 */
void gd_draw_rect(f32 ulx, f32 uly, f32 lrx, f32 lry)
{
    func_8019CCFC(&ulx, &uly);
    func_8019CCFC(&lrx, &lry);

    if (lrx > ulx && lry > uly)
    {
        gDPFillRectangle(
            next_gfx(),
            (u32) (D_801A86D8->unk3C.x + ulx),
            (u32) (uly + D_801A86D8->unk3C.y),
            (u32) (D_801A86D8->unk3C.x + lrx),
            (u32) (lry + D_801A86D8->unk3C.y)
        );
    }
    // L8019D678
    gDPPipeSync(next_gfx());
    gDPSetCycleType(next_gfx(), G_CYC_1CYCLE);
    // upper 0 0 4 4 =   
    // lower 2 4 7 8 = G_RM_AA_ZB_OPA_SURF2?
    // TODO: update mode1, mode2 with constants
    gDPSetRenderMode(next_gfx(), 0x0044 << 16, 0x2478);
}

/* 24BED8 -> 24CAC8; orig name: func_8019D708 */
void gd_draw_border_rect(f32 ulx, f32 uly, f32 lrx, f32 lry)
{
    func_8019CCFC(&ulx, &uly);
    func_8019CCFC(&lrx, &lry);

    if (lrx > ulx && lry > uly)
    {
        gDPFillRectangle(
            next_gfx(),
            (u32) (D_801A86D8->unk3C.x + ulx),
            (u32) (uly + D_801A86D8->unk3C.y),
            (u32) (D_801A86D8->unk3C.x + ulx + 5.0f),
            (u32) (lry + D_801A86D8->unk3C.y)
        );
        gDPFillRectangle(
            next_gfx(),
            (u32) (D_801A86D8->unk3C.x + lrx - 5.0f),
            (u32) (uly + D_801A86D8->unk3C.y),
            (u32) (D_801A86D8->unk3C.x + lrx),
            (u32) (lry + D_801A86D8->unk3C.y)
        );
        gDPFillRectangle(
            next_gfx(),
            (u32) (D_801A86D8->unk3C.x + ulx),
            (u32) (uly + D_801A86D8->unk3C.y),
            (u32) (D_801A86D8->unk3C.x + lrx),
            (u32) (uly + D_801A86D8->unk3C.y + 5.0f)
        );
        gDPFillRectangle(
            next_gfx(),
            (u32) (D_801A86D8->unk3C.x + ulx),
            (u32) (lry + D_801A86D8->unk3C.y - 5.0f),
            (u32) (D_801A86D8->unk3C.x + lrx),
            (u32) (lry + D_801A86D8->unk3C.y)
        );
    }
    // L8019E268
    gDPPipeSync(next_gfx());
    gDPSetCycleType(next_gfx(), G_CYC_1CYCLE);
    // TODO: update mode1, mode2 with constants
    gDPSetRenderMode(next_gfx(), 0x0044 << 16, 0x2478);
}

/* 24CAC8 -> 24CDB4; orig name: func_8019E2F8 */
void gd_set_fill(struct GdColour *colour)
{
    u8 r, g, b;

    r = colour->r * 255.0f;
    g = colour->g * 255.0f;
    b = colour->b * 255.0f;

    gDPPipeSync(next_gfx());
    gDPSetCycleType(next_gfx(), G_CYC_FILL);
    // TODO: update mode1, mode2 with constants
    gDPSetRenderMode(next_gfx(), 0x0F0A << 16, 0x4000);
    gDPSetFillColor(next_gfx(), FILL_RGBA5551(r,g,b,1));
}

/* 24CDB4 -> 24CE10; orig name: func_8019E5E4 */
void gd_set_view_zbuf(void)
{
    gDPSetDepthImage(
        next_gfx(),
        GD_LOWER_24(D_801A86D8->unk88->unk8C)
    ); 
}

/* 24CE10 -> 24CF2C; orig name: func_8019E640 */
void gd_set_view_framebuf(void)
{
    gDPSetColorImage(
        next_gfx(),
        G_IM_FMT_RGBA,
        G_IM_SIZ_16b,
        D_801A86D8->unk88->unk54.x,
        GD_LOWER_24(D_801A86D8->unk88->unk90[gGdFrameBuf])
    );
}

/* 24CF2C -> 24CFCC */
void func_8019E75C(void)
{
    D_801BD7C0[gGdFrameBuf]->curGfxIdx = 0;
    sCurrentGdDl = sDynDlSet1[gGdFrameBuf];
    sCurrentGdDl->curVtxIdx = 0;
    sCurrentGdDl->curMtxIdx = 0;
    sCurrentGdDl->curLightIdx = 0;
    sCurrentGdDl->curGfxIdx = 0;
    sCurrentGdDl->curVpIdx = 0;
}

/* 24CFCC -> 24D044 */
void func_8019E7FC(s32 id)
{
    sCurrentGdDl = sGdDLArray[id];
    sCurrentGdDl->curVtxIdx = 0;
    sCurrentGdDl->curMtxIdx = 0;
    sCurrentGdDl->curLightIdx = 0;
    sCurrentGdDl->curGfxIdx = 0;
    sCurrentGdDl->curVpIdx = 0;
}

/* 24D044 -> 24D064; orig name: func_8019E874 */
void stash_current_gddl(void)
{
    sGdDlStash = sCurrentGdDl;
}

/* 24D064 -> 24D084; orig name: func_8019E894 */
void pop_gddl_stash(void)
{
    sCurrentGdDl = sGdDlStash;
}

/* 24D084 -> 24D1D4 */
s32 gd_startdisplist(s32 memarea)
{
    D_801BB018 = 0;
    D_801BB01C = 1;

    switch (memarea)
    {
        case 7:
            sCurrentGdDl = create_child_gdl(0, sStaticDl);
            break;
        case 8:
            if (D_801A86D8->unk20 > 2)
            {
                fatal_printf("gd_startdisplist(): Too many views to display");
            }

            sCurrentGdDl = D_801BD7C8[D_801A86D8->unk20][gGdFrameBuf];
            cpy_remaining_gddl(sCurrentGdDl, sCurrentGdDl->unk4C);
            break;
        default:
            fatal_printf("gd_startdisplist(): Unknown memory area");
            break;
    }
    gDPPipeSync(next_gfx());

    return sCurrentGdDl->unk44;
}

/* 24D1D4 -> 24D23C */
void gd_enddisplist(void)
{
    gDPPipeSync(next_gfx());
    gSPEndDisplayList(next_gfx());
}

/* 24D23C -> 24D39C; orig name: func_8019EA6C */
s32 gd_end_dl(void)
{
    s32 curDlIdx = 0; // 24

    gDPPipeSync(next_gfx());
    gSPEndDisplayList(next_gfx());
    if (sCurrentGdDl->unk4C != NULL)
    {
        sCurrentGdDl->unk4C->curVtxIdx = (sCurrentGdDl->unk4C->curVtxIdx + sCurrentGdDl->curVtxIdx);
        sCurrentGdDl->unk4C->curMtxIdx = (sCurrentGdDl->unk4C->curMtxIdx + sCurrentGdDl->curMtxIdx);
        sCurrentGdDl->unk4C->curLightIdx = (sCurrentGdDl->unk4C->curLightIdx + sCurrentGdDl->curLightIdx);
        sCurrentGdDl->unk4C->curGfxIdx = (sCurrentGdDl->unk4C->curGfxIdx + sCurrentGdDl->curGfxIdx);
        sCurrentGdDl->unk4C->curVpIdx = (sCurrentGdDl->unk4C->curVpIdx + sCurrentGdDl->curVpIdx);
    }
    curDlIdx = sCurrentGdDl->curGfxIdx;
    return curDlIdx;
}

/* 24D39C -> 24D3D8 */
void Unknown8019EBCC(s32 id, uintptr_t arg1)
{
    sGdDLArray[id]->gfx = (Gfx *)(GD_LOWER_24(arg1) + D_801BAF28);
}

/* 24D3D8 -> 24D458 */
u32 func_8019EC08(void *addr, UNUSED s32 arg1)
{
    struct GdDisplayList *gddl;

    gddl = new_gd_dl(0, 0, 0, 0, 0, 0);
    gddl->gfx = (Gfx *)(GD_LOWER_24((uintptr_t)addr) + D_801BAF28);
    return gddl->unk44;
}

/* 24D458 -> 24D4C4 */
u32 Unknown8019EC88(void *addr, UNUSED s32 arg1)
{
    struct GdDisplayList *gddl;

    gddl = new_gd_dl(0, 0, 0, 0, 0, 0);
    gddl->gfx = addr;
    return gddl->unk44;
}

/* 24D4C4 -> 24D63C; orig name: func_8019ECF4 */
void mat4_to_Mtx(const Mat4 *src, Mtx *dst)
{
    int i; // 14
    int j; // 10
    s32 w1;
    s32 w2;
    s32 *mtxInt = (s32 *)dst->m[0]; // int part
    s32 *mtxFrc = (s32 *)dst->m[2]; // frac part

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 2; j++)
        {
            w1 = (s32) ((*src)[i][j * 2] * 65536.0f);
            w2 = (s32) ((*src)[i][j * 2 + 1] * 65536.0f);
            *mtxInt = MTX_INTPART_PACK(w1, w2);
            mtxInt++;
            *mtxFrc = MTX_FRACPART_PACK(w1, w2);
            mtxFrc++;
        }
    }
}

/* 24D63C -> 24D6E4; orig name: func_8019EE6C */
void add_mat4_to_dl(Mat4 *mtx)
{
    mat4_to_Mtx(mtx, &DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&DL_CURRENT_MTX(sCurrentGdDl)),
        sMtxParameters
    );
    next_mtx();
}

/* 24D6E4 -> 24D790; orig name: func_8019EF14 */
void add_mat4_load_to_dl(Mat4 *mtx)
{
    mat4_to_Mtx(mtx, &DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&DL_CURRENT_MTX(sCurrentGdDl)),
        sMtxParameters | G_MTX_LOAD
    );
    next_mtx();
}

/* 24D790 -> 24D7FC */
void Unknown8019EFC0(void)
{
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&sIdnMtx),
        sMtxParameters | G_MTX_LOAD
    );
}

/* 24D7FC -> 24D868; orig name: func_8019F02C */
void push_idn_mtx_cur_gddl(void)
{
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&sIdnMtx),
        sMtxParameters | G_MTX_PUSH
    );
}

/* 24D868 -> 24D8B4; orig name: func_8019F098 */
void pop_mtx_gddl(void)
{
    gSPPopMatrix(next_gfx(), sMtxParameters);
}

/* 24D8B4 -> 24D96C; orig name: func_8019F0E4 */
void translate_mtx_gddl(f32 x, f32 y, f32 z)
{
    guTranslate(&DL_CURRENT_MTX(sCurrentGdDl), x, y, z);
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&DL_CURRENT_MTX(sCurrentGdDl)),
        sMtxParameters
    );
    next_mtx();
}

/* 24D96C -> 24DA28; orig name: func_8019F19C */
void translate_load_mtx_gddl(f32 x, f32 y, f32 z)
{
    guTranslate(&DL_CURRENT_MTX(sCurrentGdDl), x, y, z);
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&DL_CURRENT_MTX(sCurrentGdDl)),
        sMtxParameters | G_MTX_LOAD
    );
    next_mtx();
}

/* 24DA28 -> 24DA94 */
void func_8019F258(f32 x, f32 y, f32 z)
{
    Mat4 mtx; // 28
    struct MyVec3f vec; // 1c

    vec.x = x;
    vec.y = y;
    vec.z = z;
    set_identity_mat4(&mtx);
    func_8019415C(&mtx, &vec);
    add_mat4_to_dl(&mtx);
}

/* 24DA94 -> 24DAE8 */
void func_8019F2C4(f32 arg0, s8 arg1)
{
    Mat4 mtx; // 18

    set_identity_mat4(&mtx);
    absrot_mat4(&mtx, arg1 - 120, -arg0);
    add_mat4_to_dl(&mtx);
}

/* 24DAE8 -> 24E1A8 */
void func_8019F318(struct ObjCamera *cam, 
    f32 arg1, f32 arg2, f32 arg3, 
    f32 arg4, f32 arg5, f32 arg6, 
    f32 arg7
)
{
    LookAt *lookat; // 5c

    arg7 *= RAD_PER_DEG;

    func_80193B68(&cam->unkE8,
        arg1, arg2, arg3,
        arg4, arg5, arg6,
        gd_sin_d((f64) arg7), gd_cos_d((f64) arg7), 0.0f
    );
    // 8019F3C8
    mat4_to_Mtx(&cam->unkE8, &DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(
        next_gfx(),
        osVirtualToPhysical(&DL_CURRENT_MTX(sCurrentGdDl)),
        G_MTX_PROJECTION
    );
    // 8019F434
    /*  col           colc          dir
        0  1  2   3   4  5  6   7   8  9  10  11
    { { 0, 0, 0}, _, {0, 0, 0}, _, {0, 0, 0}, _}
       16 17 18  19  20 21  22 23  24 25  26  27
    { { 0, 0, 0}, _, {0, 0, 0}, _, {0, 0, 0}, _}
    */
    lookat = &D_801BE7D0[gGdFrameBuf];

    lookat->l[0].l.dir[0] = LOOKAT_PACK(cam->unkE8[0][0]);
    lookat->l[0].l.dir[1] = LOOKAT_PACK(cam->unkE8[1][0]);
    lookat->l[0].l.dir[2] = LOOKAT_PACK(cam->unkE8[2][0]);
    
    lookat->l[1].l.dir[0] = LOOKAT_PACK(cam->unkE8[0][1]);
    lookat->l[1].l.dir[1] = LOOKAT_PACK(cam->unkE8[1][1]);
    lookat->l[1].l.dir[2] = LOOKAT_PACK(cam->unkE8[2][1]);
    
    lookat->l[0].l.col[0] = 0;
    lookat->l[0].l.col[1] = 0;
    lookat->l[0].l.col[2] = 0;
    lookat->l[0].l.pad1 = 0;
    lookat->l[0].l.colc[0] = 0;
    lookat->l[0].l.colc[1] = 0;
    lookat->l[0].l.colc[2] = 0;
    lookat->l[0].l.pad2 = 0;
    lookat->l[1].l.col[0] = 0;
    lookat->l[1].l.col[1] = 0x80;
    lookat->l[1].l.col[2] = 0;
    lookat->l[1].l.pad1 = 0;
    lookat->l[1].l.colc[0] = 0;
    lookat->l[1].l.colc[1] = 0x80;
    lookat->l[1].l.colc[2] = 0;
    lookat->l[1].l.pad2 = 0;
    // 8019F810
    lookat = &D_801BE790[0];
    lookat->l[0].l.dir[0] = 1;
    lookat->l[0].l.dir[1] = 0;
    lookat->l[0].l.dir[2] = 0;

    lookat->l[1].l.dir[0] = 0;
    lookat->l[1].l.dir[1] = 1;
    lookat->l[1].l.dir[2] = 0;

    lookat->l[0].l.col[0] = 0;
    lookat->l[0].l.col[1] = 0;
    lookat->l[0].l.col[2] = 0;
    lookat->l[0].l.pad1 = 0;
    lookat->l[0].l.colc[0] = 0;
    lookat->l[0].l.colc[1] = 0;
    lookat->l[0].l.colc[2] = 0;
    lookat->l[0].l.pad2 = 0;
    lookat->l[1].l.col[0] = 0;
    lookat->l[1].l.col[1] = 0x80;
    lookat->l[1].l.col[2] = 0;
    lookat->l[1].l.pad1 = 0;
    lookat->l[1].l.colc[0] = 0;
    lookat->l[1].l.colc[1] = 0x80;
    lookat->l[1].l.colc[2] = 0;
    lookat->l[1].l.pad2 = 0;

    gSPLookAt(next_gfx(), osVirtualToPhysical(&D_801BE7D0[gGdFrameBuf]));
    next_mtx();
}

/* 24E1A8 -> 24E230 */
void func_8019F9D8(s32 vtxcount)
{
    D_801A86C0 = sCurrentGdDl->curVtxIdx;
    D_801BB0B4 = 0;
    if (vtxcount != 3)
    {
        fatal_printf("cant display no tris\n");
    }
    if (D_801BB018 != 0 || D_801BB01C != 0)
    {
        ;
    }
}

/* 24E230 -> 24E6C0 */
void *func_8019FA60(f32 x, f32 y, f32 z, f32 alpha)
{
    Vtx *vtx = NULL; // 1c
    int i; // 18

    for (i = D_801BB0CC; i < (D_801BB0CC + D_801BB0BC); i++)
    { //L8019FAA0
        //! the ifs need to be separate to match...
        if (sCurrentGdDl->vtx[i].n.ob[0] == (s16) x )
        if (sCurrentGdDl->vtx[i].n.ob[1] == (s16) y )
        if (sCurrentGdDl->vtx[i].n.ob[2] == (s16) z )
        {
            //D_801BAF30 + D_801BB0B4 * 2 + D_801BB0C4 * 16 = (s16) i;
            D_801BAF30[D_801BB0C4][D_801BB0B4++] = (s16) i;
            //D_801BB0B4++;
            return NULL;
        }
        // L8019FBCC loop
    }
    //L8019FBF4
    D_801BB0BC++;
    D_801BAF30[D_801BB0C4][D_801BB0B4++] = (s16) sCurrentGdDl->curVtxIdx;
    //D_801BB0B4++;
    DL_CURRENT_VTX(sCurrentGdDl).n.ob[0] = (s16) x;
    DL_CURRENT_VTX(sCurrentGdDl).n.ob[1] = (s16) y;
    DL_CURRENT_VTX(sCurrentGdDl).n.ob[2] = (s16) z;
    DL_CURRENT_VTX(sCurrentGdDl).n.flag = 0;
    DL_CURRENT_VTX(sCurrentGdDl).n.tc[0] = D_801BB0A0[0];
    DL_CURRENT_VTX(sCurrentGdDl).n.tc[1] = D_801BB0A0[1];
    DL_CURRENT_VTX(sCurrentGdDl).n.n[0] = D_801BB180[0];
    DL_CURRENT_VTX(sCurrentGdDl).n.n[1] = D_801BB180[1];
    DL_CURRENT_VTX(sCurrentGdDl).n.n[2] = D_801BB180[2];
    DL_CURRENT_VTX(sCurrentGdDl).n.a = (u8)(alpha * 255.0f);
    
    vtx = &DL_CURRENT_VTX(sCurrentGdDl);
    next_vtx();
    return vtx;
}

/* 24E6C0 -> 24E724 */
void func_8019FEF0(void)
{
    D_801BB0C4++;
    if (D_801BB0BC >= 12)
    {
        func_801A0070();
        func_801A0038();
    }
    D_801BB018 = 0;
}

/* 24E724 -> 24E808 */
void func_8019FF54(
    f32 x1, f32 y1, f32 z1, 
    f32 x2, f32 y2, f32 z2, 
    f32 x3, f32 y3, f32 z3
)
{
    Vtx *vtx; // 24

    vtx = &DL_CURRENT_VTX(sCurrentGdDl);
    func_8019FA60(x1, y1, z1, 1.0f);
    func_8019FA60(x2, y2, z2, 1.0f);
    func_8019FA60(x3, y3, z3, 1.0f);

    gSPVertex(next_gfx(), osVirtualToPhysical(vtx), 3, 0);
    gSP1Triangle(next_gfx(), 0, 1, 2, 0);
}

/* 24E808 -> 24E840 */
void func_801A0038(void)
{
    D_801BB0BC = 0;
    D_801BB0C4 = 0;
    D_801BB0CC = sCurrentGdDl->curVtxIdx;
}

/* 24E840 -> 24E9BC */
void func_801A0070(void)
{
    UNUSED u32 pad;
    int i; // 28
    UNUSED s32 startvtx; // 24

    startvtx = D_801BB0CC;
    if (D_801BB0BC != 0)
    {
        gSPVertex(
            next_gfx(), 
            osVirtualToPhysical(&sCurrentGdDl->vtx[D_801BB0CC]), 
            D_801BB0BC,
            0
        );
        // TODO: check gSP1Triangle macro for flag shift
        for (i = 0; i < D_801BB0C4; i++)
        {
            gSP1Triangle(
                next_gfx(),
                D_801BAF30[i][0] - D_801BB0CC,
                D_801BAF30[i][1] - D_801BB0CC,
                D_801BAF30[i][2] - D_801BB0CC,
                0
            );
        }
    }
    func_801A0038();
}

/* 24E9BC -> 24EA2C */
void func_801A01EC(void)
{
    if (D_801BE8B0.validCount >= D_801BE8B0.msgCount)
    {
        osRecvMesg(&D_801BE8B0, &D_801BE97C, OS_MESG_BLOCK);
    }
    osRecvMesg(&D_801BE8B0, &D_801BE97C, OS_MESG_BLOCK);
}

/* 24EA2C -> 24EA88 */
void func_801A025C(void)
{
    gGdFrameBuf ^= 1;
    osViSwapBuffer(sScreenView2->unk88->unk90[gGdFrameBuf]);
}

/* 24EA88 -> 24EAF4 */
void func_801A02B8(f32 arg0)
{
    D_801BB184 = arg0 * 255.0f;
    func_801A1A00();
}

/* 24EAF4 -> 24EB0C */
void func_801A0324(s32 arg0)
{
    D_801BB1D0 = arg0;
}

/* 24EB0C -> 24EB24 */
void func_801A033C(s32 arg0)
{
    D_801BB188 = arg0;
}

/* 24EB24 -> 24EC18 */
s32 func_801A0354(UNUSED s32 arg0)
{
    s32 dlnum; // 24
    struct GdColour blue; // 18

    blue.r = 0.0f;
    blue.g = 0.0f;
    blue.b = 1.0f;
    dlnum = gd_startdisplist(7);
    func_801A086C(dlnum, &blue, 0x20);
    gd_end_dl();
    sCurrentGdDl->totalVtx  = sCurrentGdDl->curVtxIdx;
    sCurrentGdDl->totalMtx = sCurrentGdDl->curMtxIdx;
    sCurrentGdDl->totalLights = sCurrentGdDl->curLightIdx;
    sCurrentGdDl->totalGfx = sCurrentGdDl->curGfxIdx;
    sCurrentGdDl->totalVp = sCurrentGdDl->curVpIdx;
    return dlnum;
}

/* 24EC18 -> 24EC48 */
void func_801A0448(s32 id)
{
    func_8019BDC8(id);
}

/* 24EC48 -> 24F03C */
void func_801A0478(
    s32 idx,
    struct ObjCamera *cam,
    UNUSED struct MyVec3f *arg2,
    UNUSED struct MyVec3f *arg3,
    struct MyVec3f *arg4,
    struct GdColour *colour
)
{
    UNUSED u32 pad2[24];
    Hilite *hilite; // 4c
    struct MyVec3f sp40;
    f32 sp3C; // magnitude of sp40
    f32 sp38;
    f32 sp34;
    UNUSED u32 pad[6];

    sp38 = 32.0f; // x scale factor?
    sp34 = 32.0f; // y scale factor?
    if (idx >= 0xc8)
    {
        fatal_printf("too many hilites");
    }
    hilite = &D_801BB1D8[idx];

    gDPSetPrimColor(
        next_gfx(), 0, 0,
        (s32) (colour->r * 255.0f),
        (s32) (colour->g * 255.0f),
        (s32) (colour->b * 255.0f),
        255
    );
    sp40.z = cam->unkE8[0][2] + arg4->x;
    sp40.y = cam->unkE8[1][2] + arg4->y;
    sp40.x = cam->unkE8[2][2] + arg4->z;
    sp3C = sqrtf(SQ(sp40.z) + SQ(sp40.y) + SQ(sp40.x));
    if (sp3C > 0.1)
    {
        sp3C = 1.0 / sp3C; //! 1.0f
        sp40.z *= sp3C;
        sp40.y *= sp3C;
        sp40.x *= sp3C;

        hilite->h.x1 = (((sp40.z * cam->unkE8[0][0]) + (sp40.y * cam->unkE8[1][0]) + (sp40.x * cam->unkE8[2][0])) 
            * sp38 * 2.0f)
            + (sp38 * 4.0f);
        hilite->h.y1 = (((sp40.z * cam->unkE8[0][1]) + (sp40.y * cam->unkE8[1][1]) + (sp40.x * cam->unkE8[2][1])) 
            * sp34 * 2.0f)
            + (sp34 * 4.0f);
    }
    else
    {
        hilite->h.x1 = sp38 * 2.0f;
        hilite->h.y1 = sp34 * 2.0f;
    }
}

/* 24F03C -> 24FDB8 */
s32 func_801A086C(s32 id, struct GdColour *colour, s32 arg2)
{
    UNUSED u32 pad60[2];
    int i; // 5c
    s32 sp58 = D_801BB188; // number of lights?
    s32 sp4C[3]; // converted color array
    s32 sp40[3]; // bytes from weird struct in bss

    if (id > 0)
    {
        func_8019E7FC(id);
    }
    // L801A08B0
    // TODO: flags?
    switch (arg2)
    {
    case 0x20:
        func_801A2374(FALSE);
        func_801A2374(FALSE);
        func_801A2374(FALSE);
        func_801A2374(FALSE);
        func_801A2388(FALSE);
        func_801A2388(FALSE);
        func_801A2388(FALSE);
        func_801A2388(FALSE);
        sp58 = 2;
        break;
    case 0x01:
        func_801A2374(TRUE);
        break;
    case 0x10:
        func_801A2388(TRUE);
        if (id >= 200)
        {
            fatal_printf("too many hilites");
        }
        //! the macro does the 0xFFF mask, 
        //! but it seems goddard unnecessarily masked the parameters as well
        gDPSetTileSize(
            next_gfx(),
            0,
            D_801BB1D8[id].h.x1 & 0xFFF,
            D_801BB1D8[id].h.y1 & 0xFFF,
            (D_801BB1D8[id].h.x1 + 124) & 0xFFF,
            (D_801BB1D8[id].h.y1 + 124) & 0xFFF
        );
        break;
    case 0x04:
        break;
    default:
        func_801A2374(FALSE);
        func_801A2388(FALSE);

        DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[0] = colour->r * 255.0f;
        DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[1] = colour->g * 255.0f;
        DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[2] = colour->b * 255.0f;

        DL_CURRENT_LIGHT(sCurrentGdDl).a.l.colc[0] = DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[0];
        DL_CURRENT_LIGHT(sCurrentGdDl).a.l.colc[1] = DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[1];
        DL_CURRENT_LIGHT(sCurrentGdDl).a.l.colc[2] = DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[2];
        // 801A0D04
        DL_CURRENT_LIGHT(sCurrentGdDl).l[0].l.col[0] = 0;
        DL_CURRENT_LIGHT(sCurrentGdDl).l[0].l.col[1] = 0;
        DL_CURRENT_LIGHT(sCurrentGdDl).l[0].l.col[2] = 0;

        DL_CURRENT_LIGHT(sCurrentGdDl).l[0].l.colc[0] = 0;
        DL_CURRENT_LIGHT(sCurrentGdDl).l[0].l.colc[1] = 0;
        DL_CURRENT_LIGHT(sCurrentGdDl).l[0].l.colc[2] = 0;

        gSPNumLights(next_gfx(), NUMLIGHTS_1);
        gSPLight(
            next_gfx(),
            osVirtualToPhysical(&DL_CURRENT_LIGHT(sCurrentGdDl).l),
            LIGHT_1
        );
        gSPLight(
            next_gfx(),
            osVirtualToPhysical(&DL_CURRENT_LIGHT(sCurrentGdDl).a),
            LIGHT_2
        );
        next_light();
        if (id > 0)
        {
            gd_enddisplist();
        }
        return 0;
        break;
    }
    //L801A0EF4
    sp4C[0] = (s32) (colour->r * sAmbScaleColour.r * 255.0f);
    sp4C[1] = (s32) (colour->g * sAmbScaleColour.g * 255.0f);
    sp4C[2] = (s32) (colour->b * sAmbScaleColour.b * 255.0f);
    // 801A0FE4
    DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[0] = sp4C[0];
    DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[1] = sp4C[1];
    DL_CURRENT_LIGHT(sCurrentGdDl).a.l.col[2] = sp4C[2];
    // 801A1068
    DL_CURRENT_LIGHT(sCurrentGdDl).a.l.colc[0] = sp4C[0];
    DL_CURRENT_LIGHT(sCurrentGdDl).a.l.colc[1] = sp4C[1];
    DL_CURRENT_LIGHT(sCurrentGdDl).a.l.colc[2] = sp4C[2];
    // 801A10EC
    gSPNumLights(next_gfx(), sp58);
    for (i = 0; i < sp58; i++)
    { // L801A1134
        sp4C[0] = colour->r * sLightScaleColours[i].r * 255.0f;
        sp4C[1] = colour->g * sLightScaleColours[i].g * 255.0f;
        sp4C[2] = colour->b * sLightScaleColours[i].b * 255.0f;
        // 801A1260
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.col[0] = sp4C[0];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.col[1] = sp4C[1];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.col[2] = sp4C[2];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.colc[0] = sp4C[0];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.colc[1] = sp4C[1];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.colc[2] = sp4C[2];
        
        // 801A13B0
        sp40[0] = D_801BB1B8[i].u0.bytes.b3;
        sp40[1] = D_801BB1B8[i].u4.bytes.b3;
        sp40[2] = D_801BB1B8[i].u8.bytes.b3;
        // 801A141C
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.dir[0] = sp40[0];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.dir[1] = sp40[1];
        DL_CURRENT_LIGHT(sCurrentGdDl).l[i].l.dir[2] = sp40[2];
        // 801A14C4
        gSPLight(
            next_gfx(),
            osVirtualToPhysical(&DL_CURRENT_LIGHT(sCurrentGdDl).l[i]),
            i + 1
        );
    }
    // L801A1550
    gSPLight(
        next_gfx(),
        osVirtualToPhysical(&DL_CURRENT_LIGHT(sCurrentGdDl)),
        i + 1
    );
    next_light();
    gd_enddisplist();
    return 0;
}

/* 24FDB8 -> 24FE94 */
void func_801A15E8(struct MyVec3f *norm)
{
    D_801BB180[0] = (s8) (norm->x * 127.0f);
    D_801BB180[1] = (s8) (norm->y * 127.0f);
    D_801BB180[2] = (s8) (norm->z * 127.0f);
}

/* 24FE94 -> 24FF80 */
void func_801A16C4(struct MyVec3f *norm)
{
    D_801BB180[0] = (s8) (norm->x * 127.0f);
    D_801BB180[1] = (s8) (norm->y * 127.0f);
    D_801BB180[2] = (s8) (norm->z * 127.0f);

    //! are these stub functions?
    return; // @ 801A17A0
    return; // @ 801A17A8
}

/* 24FF80 -> 24FFDC; orig name: func_801A17B0 */
void set_gd_mtx_parameters(s32 paramType)
{
    switch (paramType)
    {
        case 5:
            sMtxParameters = G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH;
            break;
        case 6:
            sMtxParameters = G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH;
            break;
    }
}

/* 24FFDC -> 2501D0 */ 
void func_801A180C(void)
{
    Vp *vp; // 1c

    vp = &DL_CURRENT_VP(sCurrentGdDl);

    vp->vp.vscale[0] = (s16) (D_801A86D8->unk54.x * 2.0f);
    vp->vp.vscale[1] = (s16) (D_801A86D8->unk54.y * 2.0f);
    vp->vp.vscale[2] = 0x1FF;
    vp->vp.vscale[3] = 0x000;

    vp->vp.vtrans[0] = (s16) ((D_801A86D8->unk3C.x * 4.0f) + (D_801A86D8->unk54.x * 2.0f));
    vp->vp.vtrans[1] = (s16) ((D_801A86D8->unk3C.y * 4.0f) + (D_801A86D8->unk54.y * 2.0f));
    vp->vp.vtrans[2] = 0x1FF;
    vp->vp.vtrans[3] = 0x000;

    gSPViewport(next_gfx(), osVirtualToPhysical(vp));
    next_vp();
}

/* 2501D0 -> 250300 */
void func_801A1A00(void)
{
    if ((D_801A86D8->unk34 & 0x10) != 0)
    {
        if (D_801BB184 != 0xff)
        {
            gDPSetRenderMode(next_gfx(), 0x0050 << 16, 0x49d8);
        }
        else
        {
            gDPSetRenderMode(next_gfx(), 0x0044 << 16, 0x2478);
        }
    }
    else
    {
        if (D_801BB184 != 0xff)
        {
            gDPSetRenderMode(next_gfx(), 0x0050 << 16, 0x41c8);
        }
        else
        {
            gDPSetRenderMode(next_gfx(), 0x0044 << 16, 0x2478);
        }
    }
}

/* 250300 -> 250640 */
void Unknown801A1B30(void)
{
    gDPPipeSync(next_gfx());
    gd_set_view_framebuf();
    gd_set_fill(&D_801A86D8->unk7C);
    gDPFillRectangle(
        next_gfx(),
        (u32) (D_801A86D8->unk3C.x),
        (u32) (D_801A86D8->unk3C.y),
        (u32) (D_801A86D8->unk3C.x + D_801A86D8->unk54.x - 1.0f),
        (u32) (D_801A86D8->unk3C.y + D_801A86D8->unk54.y - 1.0f)
    );
    gDPPipeSync(next_gfx());
}

/* 250640 -> 250AE0 */
void Unknown801A1E70(void)
{
    gDPPipeSync(next_gfx());
    gDPSetCycleType(next_gfx(), G_CYC_FILL);
    gDPSetRenderMode(next_gfx(), 0x0F0A << 16, 0x4000);
    gd_set_view_zbuf();
    gDPSetColorImage(
        next_gfx(),
        G_IM_FMT_RGBA,
        G_IM_SIZ_16b,
        D_801A86D8->unk88->unk54.x,
        GD_LOWER_24(D_801A86D8->unk88->unk8C)
    );
    gDPSetFillColor(next_gfx(), FILL_RGBA5551(248, 248, 240, 0));
    gDPFillRectangle(
        next_gfx(),
        (u32) (D_801A86D8->unk3C.x),
        (u32) (D_801A86D8->unk3C.y),
        (u32) (D_801A86D8->unk3C.x + D_801A86D8->unk54.x - 1.0f),
        (u32) (D_801A86D8->unk3C.y + D_801A86D8->unk54.y - 1.0f)
    );
    gDPPipeSync(next_gfx());
    gd_set_view_framebuf();
}

/* 250AE0 -> 250B30; orig name: func_801A2310 */
void gd_set_one_cycle(void)
{
    gDPSetCycleType(next_gfx(), G_CYC_1CYCLE);
    func_801A1A00();
}

/* 250B30 -> 250B44 */
void Unknown801A2360(void)
{
    UNUSED u32 pad[4];
}

/* 250B44 -> 250B58 */
void func_801A2374(UNUSED s32 arg0)
{
}

/* 250B58 -> 250C18 */
void func_801A2388(s32 gotoDl)
{
    if (gotoDl)
    {
        gSPDisplayList(next_gfx(), osVirtualToPhysical(&marioHeadDl801B5100));
    }
    else
    {
        gSPTexture(next_gfx(), 0x8000, 0x8000, 0, 0, 0);
        gDPSetCombine(next_gfx(), 0xFFFFFF, 0xFFFE793C);;
    }
}

/* 250C18 -> 251014 */
void func_801A2448(struct ObjView *view)
{
    f32 ulx; // 3c
    f32 uly; // 38
    f32 lrx; // 34
    f32 lry; // 30

    if (view->unk3C.x < view->unk88->unk3C.x)
    {
        ulx = view->unk88->unk3C.x;
    }
    else
    {
        ulx = view->unk3C.x;
    }

    if (view->unk3C.x + view->unk54.x > view->unk88->unk3C.x + view->unk88->unk54.x)
    {
        lrx = view->unk88->unk3C.x + view->unk88->unk54.x;
    }
    else
    {
        lrx = view->unk3C.x + view->unk54.x;
    }

    if (view->unk3C.y < view->unk88->unk3C.y)
    {
        uly = view->unk88->unk3C.y;
    }
    else
    {
        uly = view->unk3C.y;
    }

    if (view->unk3C.y + view->unk54.y > view->unk88->unk3C.y + view->unk88->unk54.y)
    {
        lry = view->unk88->unk3C.y + view->unk88->unk54.y;
    }
    else
    {
        lry = view->unk3C.y + view->unk54.y;
    }

    if (ulx >= lrx)
    {
        ulx = lrx - 1.0f;
    }
    if (uly >= lry)
    {
        uly = lry - 1.0f;
    }

    gDPSetScissor(next_gfx(), G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
    // TODO: is there a define for all? this seems illegal
    gSPClearGeometryMode(next_gfx(), 0xFFFFFFFF);
    gSPSetGeometryMode(next_gfx(), G_LIGHTING | G_CULL_BACK | G_SHADING_SMOOTH | G_SHADE);
    if (view->unk34 & 0x10)
    {
        gSPSetGeometryMode(next_gfx(), G_ZBUFFER);
    }
    func_801A180C();
    func_801A1A00();
    gDPPipeSync(next_gfx());
}

// TODO: clean up gd_main.h
// TODO: bitfields for unkD8
/* 251014 -> 251A1C */
void func_801A2844(void)
{
    unsigned int i; // 3c
    struct GdControl *gdctrl; // 38
    OSContPad *p1cont; // 34
    OSContPad *p1contPrev; // 30
    u8 *gdCtrlBytes; // 2C
    u8 *prevGdCtrlBytes; // 28

    gdctrl = &D_801B9920;
    gdCtrlBytes = (u8 *)gdctrl;
    prevGdCtrlBytes = (u8 *)gdctrl->unkF0;

    for (i = 0; i < sizeof(struct GdControl); i++)
    {
        *prevGdCtrlBytes++ = *gdCtrlBytes++;
    }

    gdctrl->unk50 = gdctrl->unk4C = gdctrl->unk10 = gdctrl->unk14 = 0;
    
    p1cont = &D_801BAE70[0];
    p1contPrev = &sPrevFrameCont[0];
    // stick values
    gdctrl->unk7C = (f32) p1cont->stick_x;
    gdctrl->unk80 = (f32) p1cont->stick_y;
    gdctrl->unkC0 = gdctrl->unkC8;
    gdctrl->unkC4 = gdctrl->unkCC;
    gdctrl->unkC8 = (s32) p1cont->stick_x;
    gdctrl->unkCC = (s32) p1cont->stick_y;
    gdctrl->unkC0 -= gdctrl->unkC8;
    gdctrl->unkC4 -= gdctrl->unkCC;
    // button values (as bools)
    gdctrl->unk44 = (p1cont->button & L_TRIG) > 0u;
    gdctrl->unk48 = (p1cont->button & R_TRIG) > 0u;
    gdctrl->unk34 = (p1cont->button & A_BUTTON) > 0u;
    gdctrl->unk38 = (p1cont->button & B_BUTTON) > 0u;
    gdctrl->unk18 = (p1cont->button & L_CBUTTONS) > 0u;
    gdctrl->unk1C = (p1cont->button & R_CBUTTONS) > 0u;
    gdctrl->unk20 = (p1cont->button & U_CBUTTONS) > 0u;
    gdctrl->unk24 = (p1cont->button & D_CBUTTONS) > 0u;
    // but not these buttons??
    gdctrl->unk08 = p1cont->button & L_JPAD;
    gdctrl->unk0C = p1cont->button & R_JPAD;
    gdctrl->unk10 = p1cont->button & U_JPAD;
    gdctrl->unk14 = p1cont->button & D_JPAD;

    if (gdctrl->unk34 && !gdctrl->unkD8b80)
    {
        gdctrl->unkD8b10 = TRUE;
    }
    else 
    {
        gdctrl->unkD8b10 = FALSE;
    }
    // toggle if A is pressed? or is this just some seed for an rng?
    gdctrl->unkD8b80 = gdctrl->unk34;
    gdctrl->unkD8b40 = FALSE;
    gdctrl->unkD8b20 = gdctrl->unkD8b40;
    gdctrl->unkD8b02 = FALSE;
    if (gdctrl->unkD8b10)
    {
        gdctrl->unkB8 = gdctrl->unkD0;
        gdctrl->unkBC = gdctrl->unkD4;

        if (gdctrl->unkE8 - gdctrl->unkDC < 10)
        {
            gdctrl->unkD8b02 = TRUE;
        }
    }

    if (gdctrl->unkD8b80)
    {
        gdctrl->unkDC = gdctrl->unkE8;
    }
    gdctrl->unkE8++;

    if (p1cont->button & START_BUTTON && !(p1contPrev->button & START_BUTTON))
    {
        gdctrl->unk54 ^= 1;
    }

    if (p1cont->button & Z_TRIG && !(p1contPrev->button & Z_TRIG))
    {
        D_801A86F4++;
    }

    if (D_801A86F4 > D_801A86F0)
    {
        D_801A86F4 = 0;
    }
    else if (D_801A86F4 < 0)
    {
        D_801A86F4 = D_801A86F0;
    }

    if (D_801A86F4)
    {
        deactivate_timing();
    }
    else
    {
        activate_timing();
    }

    for (i = 0; ((int)i) < D_801A86F0; i++)
    {
        D_801BD7A0[i]->unk34 &= ~0x800;
    }

    if (D_801A86F4)
    {
        // TODO: check this later; guessing on the indexing...
        D_801BD7A0[D_801A86F4-1]->unk34 |= 0x800;
    }
    //deadzone checks?
    if (ABS(gdctrl->unkC8) >= 6)
    {
        gdctrl->unkD0 += gdctrl->unkC8 * 0.1; //? 0.1f
    }

    if (ABS(gdctrl->unkCC) >= 6)
    {
        gdctrl->unkD4 -= gdctrl->unkCC * 0.1; //? 0.1f
    }
    // border checks? is this for the cursor finger movement?
    if ((f32) gdctrl->unkD0 < (sScreenView2->unk88->unk3C.x + 16.0f))
    {
        gdctrl->unkD0 = (s32) (sScreenView2->unk88->unk3C.x + 16.0f);
    }

    if ((f32) gdctrl->unkD0 > (sScreenView2->unk88->unk3C.x + sScreenView2->unk88->unk54.x - 48.0f))
    {
        gdctrl->unkD0 = (s32) (sScreenView2->unk88->unk3C.x + sScreenView2->unk88->unk54.x - 48.0f);
    }

    if ((f32) gdctrl->unkD4 < (sScreenView2->unk88->unk3C.y + 16.0f))
    {
        gdctrl->unkD4 = (s32) (sScreenView2->unk88->unk3C.y + 16.0f);
    }

    if ((f32) gdctrl->unkD4 > (sScreenView2->unk88->unk3C.y + sScreenView2->unk88->unk54.y - 32.0f))
    {
        gdctrl->unkD4 = (s32) (sScreenView2->unk88->unk3C.y + sScreenView2->unk88->unk54.y - 32.0f);
    }

    for (i = 0; i < sizeof(OSContPad); i++)
    {
        ((u8 *)p1contPrev)[i] = ((u8 *)p1cont)[i];
    }
}

/* 251A1C -> 251AC4 */
void Unknown801A324C(f32 arg0)
{
    return;

    if (D_801BD768.x * D_801A86CC.x + arg0 * 2.0f > 160.0) //? 160.0f
    {
        func_801A3370(D_801BD758.x - D_801BD768.x, -20.0f, 0.0f);
        D_801BD768.x = D_801BD758.x;
    }
}

/* 251AC4 -> 251AF4 */
void Unknown801A32F4(s32 arg0)
{
    D_801BD774 = GD_LOWER_24(arg0) + D_801BAF28;
}

/* 251AF4 -> 251B40 */
void func_801A3324(f32 x, f32 y, f32 z)
{
    D_801BD768.x = x;
    D_801BD768.y = y;
    D_801BD768.z = z;
    D_801BD758.x = x;
    D_801BD758.y = y;
    D_801BD758.z = z;
}

/* 251B40 -> 251BC8 */
void func_801A3370(f32 x, f32 y, f32 z)
{
    translate_mtx_gddl(x, y, z);
    D_801BD768.x += x;
    D_801BD768.y += y;
    D_801BD768.z += z;
}

/* 251BC8 -> 251C4C */
void Unknown801A33F8(f32 x, f32 y, f32 z)
{
    translate_mtx_gddl(
        x - D_801BD768.x, 
        y - D_801BD768.y, 
        z - D_801BD768.z
    );

    D_801BD768.x = x;
    D_801BD768.y = y;
    D_801BD768.z = z;
}

/* 251C4C -> 251CB0 */
void Unknown801A347C(f32 x, f32 y, f32 z)
{
    D_801A86CC.x = x;
    D_801A86CC.y = y;
    D_801A86CC.z = z;
    func_8019F258(x, y, z);
}

/* 251CB0 -> 251D44 */
void func_801A34E0(void)
{
    if ((D_801A86D8->unk34 & 0x400) != 0)
    {
        gd_set_fill(gd_get_colour(1));
        gd_draw_border_rect(0.0f, 0.0f, (D_801A86D8->unk54.x - 1.0f), (D_801A86D8->unk54.y - 1.0f));
    }
}

/* 251D44 -> 251DAC */
void gd_shading(s32 model)
{
    switch (model)
    {
        case  9: break;
        case 10: break;
        default: fatal_printf("gd_shading(): Unknown shading model");
    }
}

/* 251DAC -> 251E18 */
s32 gd_getproperty(s32 prop, UNUSED void *arg1)
{
    s32 got = FALSE;

    switch (prop) 
    {
        case 3: got = TRUE; break;
        default: fatal_printf("gd_getproperty(): Unkown property");
    }

    return got;
}

/* 251E18 -> 2522B0 */
void gd_setproperty(s32 prop, f32 f1, f32 f2, f32 f3)
{
    UNUSED f32 sp3C = 1.0f;
    s32 sp38;

    switch (prop)
    {
    case 11:
        sp38 = (s32) f1;
        switch (sp38)
        {
            case 1: gSPSetGeometryMode(next_gfx(), G_LIGHTING);   break;
            case 0: gSPClearGeometryMode(next_gfx(), G_LIGHTING); break;
        }
        break;
    case 12:
        sAmbScaleColour.r = f1;
        sAmbScaleColour.g = f2;
        sAmbScaleColour.b = f3;
        break;
    case 15:
        D_801BB1B8[D_801BB1D0].u0.w = (s32) (f1 * 120.f);
        D_801BB1B8[D_801BB1D0].u4.w = (s32) (f2 * 120.f);
        D_801BB1B8[D_801BB1D0].u8.w = (s32) (f3 * 120.f);
        break;
    case 13:
        sLightScaleColours[D_801BB1D0].r = f1;
        sLightScaleColours[D_801BB1D0].g = f2;
        sLightScaleColours[D_801BB1D0].b = f3;
        break;
    case 16:
        sp38 = (s32) f1;
        switch (sp38)
        {
            case 1: gSPSetGeometryMode(next_gfx(), G_CULL_BACK);   break;
            case 0: gSPClearGeometryMode(next_gfx(), G_CULL_BACK); break;
        }
        break;
    case 4:
        sp38 = (s32) f1;
        switch (sp38)
        {
            case 1: break;
            case 0: break;
            default: fatal_printf("Bad GD_OVERLAY parm");
        }
        break;
    case 22:
        sp38 = (s32) f1;
        switch (sp38)
        {
            case 23: break;
            case 24: break;
            case 25: break;
            default: fatal_printf("Bad zbuf function");
        }
        //? no break?
    case 17: break;
    case 18: break;
    case 19: break;
    case 20: break;
    case 21: break;
    default:
        fatal_printf("gd_setproperty(): Unkown property");
    }
}

/* 2522B0 -> 2522C0 */
void stub_801A3AE0(void)
{
}

/* 2522C0 -> 25245C */
void func_801A3AF0(f32 l, f32 r, f32 b, f32 t, f32 n, f32 f)
{
    uintptr_t orthoMtx; // 3c
    uintptr_t rotMtx;   // 38

    {
        // G_RDPHALF_1
        Gfx *_g = next_gfx();
        _g->words.w0 = 0xb4000000;
        _g->words.w1 = 0xffff;
    }

    guOrtho(&DL_CURRENT_MTX(sCurrentGdDl), l, r, b, t, n, f, 1.0f);
    orthoMtx = GD_LOWER_29(&DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(next_gfx(), orthoMtx, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

    next_mtx();
    guRotate(&DL_CURRENT_MTX(sCurrentGdDl), 0.0f, 0.0f, 0.0f, 1.0f);
    rotMtx = GD_LOWER_29(&DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(next_gfx(), rotMtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    func_801A3324(0.0f, 0.0f, 0.0f);
    next_mtx();
}


/* 25245C -> 25262C */
void func_801A3C8C(f32 fovy, f32 aspect, f32 near, f32 far)
{
    u16 perspNorm; // 4e
    UNUSED u32 pad48;
    uintptr_t perspecMtx; // 44
    uintptr_t rotMtx; // 40
    UNUSED u32 pad3C;
    UNUSED f32 sp38 = 0.0625f;

    D_801B520C += 0.1; //? 1.0f
    guPerspective(&DL_CURRENT_MTX(sCurrentGdDl), &perspNorm, fovy, aspect, near, far, 1.0f);
    {
        // G_RDPHALF_1
        Gfx *_g = next_gfx();
        _g->words.w0 = 0xb4000000;
        _g->words.w1 = perspNorm;
    }
    perspecMtx = GD_LOWER_29(&DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(next_gfx(), perspecMtx, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    next_mtx();

    guRotate(&DL_CURRENT_MTX(sCurrentGdDl), 0.0f, 0.0f, 0.0f, 1.0f);
    rotMtx = GD_LOWER_29(&DL_CURRENT_MTX(sCurrentGdDl));
    gSPMatrix(next_gfx(), rotMtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    func_801A3324(0.0f, 0.0f, 0.0f);
    next_mtx();
}

/* 25262C -> 252AF8 */
//! No actual return
s32 func_801A3E5C(
    const char *name, struct ObjView *view, 
    UNUSED s32 ulx, UNUSED s32 uly, UNUSED s32 lrx, UNUSED s32 lry
)
{
    char buf[0x100]; // 18; memtracker name buffer

    if (view->unk34 & 0x18000 && !(view->unk34 & 0x1000))
    {
        if (view->unk34 & 0x8000)
        {
            sprintf(buf, "%s CBuf", name);
            start_memtracker(buf);
            view->unk90[0] = gd_malloc((u32) (2.0f * view->unk54.x * view->unk54.y + 64.0f), 0x20);

            if (view->unk34 & 0x8)
            {
                view->unk90[1] = gd_malloc((u32) (2.0f * view->unk54.x * view->unk54.y + 64.0f), 0x20);
            } // L801A4080
            else
            {
                view->unk90[1] = view->unk90[0];
            } // L801A4094
            view->unk90[0] = (void *) ALIGN((uintptr_t) view->unk90[0], 64);
            view->unk90[1] = (void *) ALIGN((uintptr_t) view->unk90[1], 64);
            stop_memtracker(buf);

            if (view->unk90[0] == NULL || view->unk90[1] == NULL)
            {
                fatal_printf("Not enough DRAM for colour buffers\n");
            }
            view->unk88 = view;

        } // L801A4114
        else 
        {
            view->unk88 = sScreenView2;
        } // L801A4128

        if (view->unk34 & 0x10000)
        {
            sprintf(buf, "%s ZBuf", name);
            start_memtracker(buf);
            if (view->unk34 & 0x10)
            {
                view->unk8C = gd_malloc((u32) (2.0f * view->unk54.x * view->unk54.y + 64.0f), 0x40);
                if (view->unk8C == NULL) 
                {
                    fatal_printf("Not enough DRAM for Z buffer\n");
                }
                view->unk8C = (void *) ALIGN((uintptr_t) view->unk8C, 64);
            } // L801A4284
            stop_memtracker(buf);
        } 
        else
        { // L801A4294
            view->unk8C = sScreenView2->unk8C;
        } 
        // L801A42AC
    } 
    else 
    { // L801A42B4
        view->unk88 = sScreenView2;
    }
    // L801A42C8
    view->unk70 = 0;
    view->unk74 = 0;

    if (view->unk34 & 0x100)
    {
        view->unk88 = D_801A86E0;
    }

}

/* 252AF8 -> 252BAC; orig name: _InitControllers */
void gd_init_controllers(void)
{
    OSContPad *p1cont = &sPrevFrameCont[0]; // 1c
    unsigned int i; // 18

    osCreateMesgQueue(&D_801BE830, D_801BE848, ARRAY_COUNT(D_801BE848));
    osSetEventMesg(OS_EVENT_SI, &D_801BE830, (OSMesg) OS_MESG_SI_COMPLETE);
    osContInit(&D_801BE830, &D_801BAEA0, D_801BAE60);
    osContStartReadData(&D_801BE830);

    for (i = 0; i < sizeof(OSContPad); i++)
    {
        ((u8 *)p1cont)[i] = 0;
    }
}

/* 252BAC -> 252BC0 */
void Proc801A43DC(UNUSED struct ObjHeader *obj)
{
}

/* 252BC0 -> 252BE0 */
//! no return
void *func_801A43F0(UNUSED const char *menufmt, ...)
{
}

/* 252BE0 -> 252BF0 */
void Proc801A4410(UNUSED void *arg0)
{
}

/* 252BF0 -> 252C08 */
void Proc801A4424(UNUSED void *arg0)
{
}

/* 252C08 -> 252C70 */
void func_801A4438(f32 arg0, f32 arg1, f32 arg2)
{
    D_801BB0E8.x = arg0 - (D_801A86D8->unk54.x / 2.0f);
    D_801BB0E8.y = (D_801A86D8->unk54.y / 2.0f) - arg1;
    D_801BB0E8.z = arg2;
}

/* 252C70 -> 252DB4 */
s32 gd_gentexture(void *texture, s32 fmt, s32 size, UNUSED u32 arg3, UNUSED u32 arg4)
{
    UNUSED s32 sp2C;
    UNUSED s32 sp28 = 1;
    s32 dl; // 24

    switch (fmt)
    {
        case 29: fmt = 0; break;
        case 31: fmt = 3; break;
        default: fatal_printf("gd_gentexture(): bad format");
    }

    switch (size)
    {
        case 33: 
            size = 2;
            sp2C = 16;
            break;
        default:
            fatal_printf("gd_gentexture(): bad size");
    }

    D_801BB020[++D_801A86A0] = texture;
    dl = gd_startdisplist(7);

    if (dl == 0)
    {
        fatal_printf("Cant generate DL for texture");
    }
    gd_end_dl();
    D_801BB060[D_801A86A0] = dl;

    return dl;
}

/* 252DB4 -> 252F88 */
void *Unknown801A45E4(const char *file, s32 fmt, s32 size, u32 arg3, u32 arg4)
{
    struct GdFile *txFile; // 3c
    void *texture; // 38
    u32 txSize; // 34
    unsigned int i; // 30
    u16 *txHalf; // 2C
    u8 buf[3]; // 28
    u8 alpha; // 27
    s32 dl; // 20

    txFile = gd_fopen(file, "r");
    if (txFile == NULL)
    {
        fatal_print("Cant load texture");
    }
    txSize = gd_get_file_size(txFile);
    texture = gd_malloc_perm(txSize / 3 * 2);
    if (texture == NULL)
    {
        fatal_printf("Cant allocate memory for texture");
    }
    txHalf = (u16 *)texture;
    for (i = 0; i < txSize / 3; i++)
    {
        gd_fread((s8 *)buf, 3, 1, txFile);
        alpha = 0xFF;
        *txHalf = ((buf[2] >> 3) << 11) | ((buf[1] >> 3) << 6) | ((buf[0] >> 3) << 1) | (alpha >> 7);
        txHalf++;
    }
    gd_printf("Loaded texture '%s' (%d bytes)\n", file, txSize);
    gd_fclose(txFile);
    dl = gd_gentexture(texture, fmt, size, arg3, arg4);
    gd_printf("Generated '%s' (%d) display list ok.\n", file, dl);

    return texture;
}

/* 252F88 -> 252FAC */
void Unknown801A47B8(struct ObjView *v)
{
    if (v->unk34 & 0x40)
    {
        sGdBssOverlap.D_801BE994.view = v;
    }
}

void stub_801A47DC(void)
{
}

/* 252FC4 -> 252FD8 */
void Unknown801A47F4(UNUSED u32 arg0)
{
}

/* 252FD8 -> 253018 */
void func_801A4808(void)
{
    while (D_801A8674 != 0) ;

    return;
}

/* 253018 -> 253084 */
void func_801A4848(s32 linkDl)
{
    struct GdDisplayList *curDl;

    curDl = sCurrentGdDl;
    sCurrentGdDl = D_801BD7C0[gGdFrameBuf];
    func_8019BDC8(linkDl);
    sCurrentGdDl = curDl;
}

/* 253084 -> 253094 */
void func_801A48B4(void)
{
}

/* 253094 -> 2530A8 */
void func_801A48C4(UNUSED u32 arg0)
{
}

/* 2530A8 -> 2530C0 */
void func_801A48D8(UNUSED char *s)
{
    UNUSED u32 pad2;
    UNUSED char *save = s;
    UNUSED u8 pad[0x18];
}

/* 2530C0 -> 2530D8 */
void func_801A48F0(struct ObjView *v)
{
    D_801A86D8 = v;
}
 
void stub_801A4908(void)
{
}

/* 2530E8 -> 2532D4 */
void func_801A4918(void)
{
    f32 x; //c
    f32 y; //8
    u32 ydiff; // 4

    if (sHandView == NULL || sMenuView == NULL) { return; }

    x = sHandView->unk3C.x;
    y = sHandView->unk3C.y;

    if (!(x > sMenuView->unk3C.x &&
        x < sMenuView->unk3C.x + sMenuView->unk54.x &&
        y > sMenuView->unk3C.y &&
        y < sMenuView->unk3C.y + sMenuView->unk54.y))
    { 
        return; 
    }
    ydiff = (y - sMenuView->unk3C.y) / 25.0f;

    if (ydiff < sItemsInMenu)
    {
        D_801BD778[ydiff]->unk12 |= 0x10;
    }
}


/* 2532D4 -> 2533DC */
void Unknown801A4B04(void)
{
    if (D_801A86AC != NULL)
    {
        D_801A86AC->prevScaledTotal = 20.0f;
    }
    if (D_801A86A4 != NULL)
    {
        D_801A86A4->prevScaledTotal = (f32) ((sDLGenTime * 50.0f) + 20.0f);
    }
    if (D_801A86A8 != NULL)
    {
        D_801A86A8->prevScaledTotal = (f32) ((sDLGenTime * 50.0f) + 20.0f);
    }
    sDLGenTime = get_scaled_timer_total("dlgen");
    sRCPTime = get_scaled_timer_total("rcp");
    sDynamicsTime = get_scaled_timer_total("dynamics");
}

/* 2533DC -> 253728 */
void func_801A4C0C(void)
{
    if (sHandView == NULL) { return; }

    if (D_801B9920.unkE8 - D_801B9920.unkDC < 300)
    {
        sHandView->unk34 |= 0x800;
        func_80178114(1);
    }
    else
    {
        sHandView->unk34 &= ~0x800;
        func_80178114(2);
    }

    sHandView->unk3C.x = (f32) D_801B9920.unkD0;
    sHandView->unk3C.y = (f32) D_801B9920.unkD4;

    func_8019E7FC(sHandShape->unk48[gGdFrameBuf]);

    // TODO: bitfield
    if (D_801B9920.unkD8b80)
    {
        gd_put_sprite(textureHandClosed, sHandView->unk3C.x, sHandView->unk3C.y, 0x20, 0x20);
    }
    else
    {
        gd_put_sprite(textureHandOpen, sHandView->unk3C.x, sHandView->unk3C.y, 0x20, 0x20);

    }
    gd_end_dl();

    if (sHandView->unk3C.x < sHandView->unk88->unk3C.x)
    {
        sHandView->unk3C.x = sHandView->unk88->unk3C.x;
    }
    if (sHandView->unk3C.x > (sHandView->unk88->unk3C.x + sHandView->unk88->unk54.x))
    {
        sHandView->unk3C.x = sHandView->unk88->unk3C.x + sHandView->unk88->unk54.x;
    }

    if (sHandView->unk3C.y < sHandView->unk88->unk3C.y)
    {
        sHandView->unk3C.y = sHandView->unk88->unk3C.y;
    }
    if (sHandView->unk3C.y > (sHandView->unk88->unk3C.y + sHandView->unk88->unk54.y))
    {
        sHandView->unk3C.y = sHandView->unk88->unk3C.y + sHandView->unk88->unk54.y;
    }
}

/* 253728 -> 2538E0 */
void Unknown801A4F58(void)
{
    register s16 *cbufOff; // a0
    register s16 *cbufOn; // a1
    register u16 *zbuf; // a2
    register s16 colour; //a3
    register s16 r; // t0
    register s16 g; // t1
    register s16 b; // t2
    register int i; // t3

    cbufOff = sScreenView2->unk90[gGdFrameBuf ^ 1];
    cbufOn = sScreenView2->unk90[gGdFrameBuf];
    zbuf = sScreenView2->unk8C;

    for (i = 0; i < (320 * 240); i++)
    { // L801A4FCC
        colour = cbufOff[i];
        if (colour)
        {
            r = (s16) (colour >> 11 & 0x1F);
            g = (s16) (colour >> 6 & 0x1F);
            b = (s16) (colour >> 1 & 0x1F);
            if ((r -= 1) < 0) { r = 0; }
            if ((g -= 1) < 0) { g = 0; }
            if ((b -= 1) < 0) { b = 0; }

            colour = (s16) (r << 11 | g << 6 | b << 1);
            cbufOff[i] = colour;
            cbufOn[i] = colour;
        }
        else
        { // L801A50D8
            zbuf[i] = 0xFFFC;
        }
    }
}

/* 2538E0 -> 253938 */
void Proc801A5110(struct ObjView *view)
{
    if (view->unk34 & 0x800)
    {
        apply_to_obj_types_in_group(
            OBJ_TYPE_NETS, 
            Proc801933FC, 
            view->unk28
        );
    }
}

/* 253938 -> 2539DC */
void func_801A5168(struct ObjView *view)
{
    UNUSED u32 pad;
    s32 prevFlags; // 18

    prevFlags = view->unk34;
    update_view(view);
    if (prevFlags & 0x800)
    {
        sCurrentGdDl = D_801BD7C0[gGdFrameBuf];
        if (view->unk70 != 0)
        {
            func_801A4848(view->unk70);
        }
    }
}

/* 2539DC -> 253B14 */
void func_801A520C(void)
{
    UNUSED u32 pad[2];

    start_timer("1frame");
    start_timer("cpu");
    func_801A48B4();
    func_8019E75C();
    func_801A2844();
    setup_timers();
    start_timer("dlgen");
    apply_to_obj_types_in_group(OBJ_TYPE_VIEWS, func_801A5168, gGdViewsGroup);
    stop_timer("dlgen");
    restart_timer("netupd");
    if (!D_801B9920.unk54)
    {
        apply_to_obj_types_in_group(OBJ_TYPE_VIEWS, Proc801A5110, gGdViewsGroup);
    }
    split_timer("netupd");
    split_timer("cpu");
    func_801A4808();
    restart_timer("cpu");
    func_801A025C();
    func_801A4C0C();
    func_801A4918();
    stop_timer("1frame");
    sTracked1FrameTime = get_scaled_timer_total("1frame");
    split_timer("cpu");
    func_801A01EC();
}

/* 253B14 -> 253BC4 */
void Unknown801A5344(void)
{
    if ((D_801A86D8 = sScreenView2) == NULL) { return; }

    func_8019E75C();
    sScreenView2->unk70 = gd_startdisplist(8);
    func_801A2448(sScreenView2);
    gd_set_one_cycle();
    gd_end_dl();
    func_801A4848(sScreenView2->unk70);
    func_801A48B4();
    func_801A4808();
    sScreenView2->unk70 = 0;
}

/* 253BC8 -> 2540E0 */
void gd_init(void)
{
    int i; // 34
    UNUSED u32 pad30;
    s8 *data; // 2c

    add_to_stacktrace("gd_init");
    i = (u32) (sMemBlockPoolSize - 0x3E800);
    data = gd_allocblock(i);
    gd_add_mem_to_heap(i, (uintptr_t)data, 0x10);
    D_801BB184 = (u16)0xff;
    D_801A867C = 0;
    D_801A8680 = 0;
    D_801A86A0 = 0;
    gGdFrameBuf = 0;
    D_801A86BC = 1;
    sItemsInMenu = 0;
    D_801A86F0 = 0;
    D_801A86F4 = 0;
    sGdDlCount = 0;
    D_801A8674 = 0;
    D_801BB1D0 = 0;
    sAmbScaleColour.r = 0.0f;
    sAmbScaleColour.g = 0.0f;
    sAmbScaleColour.b = 0.0f;

    for (i = 0; i < ARRAY_COUNT(sLightScaleColours); i++)
    {
        sLightScaleColours[i].r = 1.0f;
        sLightScaleColours[i].g = 0.0f;
        sLightScaleColours[i].b = 0.0f;
        D_801BB1B8[i].u0.w = 0;
        D_801BB1B8[i].u4.w = 120;
        D_801BB1B8[i].u8.w = 0;
    }
    // 801A55A8
    D_801BB188 = 2;
    set_identity_mat4(&sInitIdnMat4);
    mat4_to_Mtx(&sInitIdnMat4, &sIdnMtx);
    remove_all_memtrackers();
    null_obj_lists();
    start_memtracker("total");
    remove_all_timers();

    start_memtracker("Static DL");
    sStaticDl = new_gd_dl(0, 1900, 4000, 1, 300, 8);
    stop_memtracker("Static DL");

    start_memtracker("Dynamic DLs");
    sDynDlSet1[0] = new_gd_dl(1, 600, 10, 200, 10, 3);
    sDynDlSet1[1] = new_gd_dl(1, 600, 10, 200, 10, 3);
    stop_memtracker("Dynamic DLs");
    D_801BD7C0[0] = new_gd_dl(1, 100, 0, 0, 0, 0);
    D_801BD7C0[1] = new_gd_dl(1, 100, 0, 0, 0, 0);

    for (i = 0; i < ARRAY_COUNT(D_801BD7C8); i++)
    {
        D_801BD7C8[i][0] = create_child_gdl(1, sDynDlSet1[0]);
        D_801BD7C8[i][1] = create_child_gdl(1, sDynDlSet1[1]);
    }
    // 801A5770
    sScreenView2 = make_view("screenview2", 0x19008, 0, 0, 0, 0x140, 0xf0, 0);
    sScreenView2->unk7C.r = 0.0f;
    sScreenView2->unk7C.g = 0.0f;
    sScreenView2->unk7C.b = 0.0f;
    sScreenView2->unk88 = sScreenView2;
    sScreenView2->unk34 &= ~0x800;
    D_801A86D8 = sScreenView2;

    data = (s8 *) &D_801B9920;
    for (i = 0; (u32) i < sizeof(struct GdControl); i++)
    {
        *data++ = 0;
    }
    // 801A5868
    D_801B9920.unk88 = 1.0f;
    D_801B9920.unkA0 = -45.0f;
    D_801B9920.unkAC = 45.0f;
    D_801B9920.unk00 = 2;
    D_801B9920.unk54 = 0;
    D_801B9920.unkF0 = &D_801B9A18;
    D_801B9920.unkD0 = 160;
    D_801B9920.unkD4 = 120;
    D_801B9920.unkDC = -1000;
    D_801BB0AC = func_801A0354(4);
    imout();
}

/* 2540E0 -> 254168 */
void Unknown801A5910(char *arg0, s32 len)
{
    char buf[100]; // 4
    int i; // 0

    for (i = 0; i < len; i++)
    {
        buf[i] = arg0[len - i - 1];
    }

    for (i = 0; i < len; i++)
    {
        arg0[i] = buf[i];
    }
}

/* 254168 -> 25417C */
void func_801A5998(UNUSED s8 *arg0)
{
}

/* 25417C -> 254190 */
void func_801A59AC(UNUSED void *arg0)
{
}

/* 254190 -> 2541A4 */
void func_801A59C0(UNUSED s8 *arg0)
{
}


/* 2541A4 -> 2541D4 */
void func_801A59D4(s16 *buf, s32 len)
{
    buf[0] = 0;
    buf[1] = 0;
    sHalfBufLen = len;
    sHalfBuf = buf;
    sHalfBufPosition = 0;
}

/* 2541D4 -> 25421C */
void func_801A5A04(s16 data)
{
    sHalfBuf[sHalfBufPosition++] = data;
}

/* 25421C -> 254250 */
s32 func_801A5A4C(UNUSED s16 *arg0)
{
    return sHalfBufPosition / 3;
}

/* 254250 -> 254264 */
void Unknown801A5A80(UNUSED u32 arg0)
{
}

/* 254264 -> 254278 */
void Unknown801A5A94(UNUSED u32 arg0)
{
}

/* 254278 -> 254288 */
void stub_801A5AA8(void)
{
}

/* 254288 -> 2542B0 */
void *Unknown801A5AB8(s32 texnum)
{
    return D_801BB020[texnum];
}

/* 2542B0 -> 254328 */
void Unknown801A5AE0(s32 arg0)
{
    D_801BB018 = arg0;
    if (D_801BB01C != D_801BB018)
    {
        func_8019BDC8(D_801BB060[arg0]);
        D_801BB01C = D_801BB018;
    }
}

/* 254328 -> 2543B8 */
void func_801A5B58(f32 arg0, f32 arg1)
{
    D_801BB0A0[0] = (s16) (arg0 * 512.0f);
    D_801BB0A0[1] = (s16) (arg1 * 512.0f);
}

/* 2543B8 -> 2543F4 */
void func_801A5BE8(struct ObjView *view)
{
    D_801BD7A0[D_801A86F0++] = view;
}

/* 2543F4 -> 254450; orig name: Unknown801A5C24 */
union ObjVarVal *cvrt_val_to_kb(union ObjVarVal *dst, union ObjVarVal src)
{
    union ObjVarVal temp;

    temp.f = src.f / 1024.0; //? 1024.0f
    return (*dst = temp, dst);
}

/* 254450 -> 254560 */
void Unknown801A5C80(struct ObjGroup *parentGroup)
{
    struct ObjLabel *label; // 3c
    struct ObjGroup *debugGroup; // 38

    d_start_group("debugg");
    label = (struct ObjLabel *)d_makeobj(D_LABEL, 0);
    d_set_rel_pos(10.0f, 230.0f, 0.0f);
    d_set_parm_ptr(PARM_PTR_CHAR, gd_strdup("FT %2.2f"));
    d_add_valptr(AsDynId(0), 0, OBJ_VALUE_FLOAT, (uintptr_t) &sTracked1FrameTime);
    label->unk30 = 3;
    d_end_group("debugg");

    debugGroup = (struct ObjGroup *)d_use_obj("debugg");
    make_view("debugview", 0xa0018, 2, 0, 0, 320, 240, debugGroup);
    if (parentGroup != NULL)
    {
        addto_group(parentGroup, &debugGroup->header);
    }
}

// TODO: copy ValPtrProc type from game over 2 into gd_types
// typedef union ObjVarVal * (*SomeFunc)(union ObjVarVal *, union ObjVarVal);
// typedef union ObjVarVal * (*ValPtrProc_t)(union ObjVarVal *, union ObjVarVal);

/* 254560 -> 2547C8 */
void Unknown801A5D90(struct ObjGroup *arg0)
{
    struct ObjLabel *mtLabel; // 254
    struct ObjGroup *labelgrp; // 250
    struct ObjView *memview; // 24c
    s32 sp248; // memtracker id and/or i
    s32 sp244; // label y position?
    s32 sp240; // done checking all memtrakcers
    s32 sp23C; // memtracker label made?
    char mtStatsFmt[0x100]; // 13c
    char groupId[0x100]; // 3c
    struct MemTracker *mt; // 38

    sp240 = FALSE;
    sp248 = -1;

    while (!sp240)
    { // L801A5DBC
        sprintf(groupId, "memg%d\n", sp248);
        d_start_group(AsDynId(groupId));
        sp244 = 20;
        sp23C = FALSE;
        // L801A5DE4
        for(;;)
        {
            sp248 += 1;
            mt = get_memtracker_by_id(sp248);

            if (mt->name != NULL)
            {
                sprintf(mtStatsFmt, "%s  %%6.2fk", mt->name);
                mtLabel = (struct ObjLabel *)d_makeobj(D_LABEL, AsDynId(0));
                d_set_rel_pos(10.0f, sp244, 0.0f);
                d_set_parm_ptr(PARM_PTR_CHAR, gd_strdup(mtStatsFmt));
                d_add_valptr(AsDynId(0), 0, 2, (uintptr_t) &mt->total);
                mtLabel->unk30 = 3;
                d_add_valproc(cvrt_val_to_kb);
                sp23C = TRUE;
                sp244 += 14;
                if (sp244 > 200) { break; }
            }
            // L801A5EDC
            if (sp248 >= GD_NUM_MEM_TRACKERS)
            {
                sp240 = TRUE;
                break;
            }
        }

        // L801A5F08
        d_end_group(AsDynId(groupId));
        labelgrp = (struct ObjGroup *)d_use_obj(AsDynId(groupId));

        if (sp23C) 
        {
            memview = make_view("memview", 0xA6018, 2, 0, 10, 320, 200, labelgrp);
            memview->unk7C.r = 0.0f;
            memview->unk7C.g = 0.0f;
            memview->unk7C.b = 0.0f;
            addto_group(arg0, &labelgrp->header);
            memview->unk34 &= ~0x800;
            func_801A5BE8(memview);
        }
        // L801A5FD0
    }
    // L801A5FE0
}

/* 2547C8 -> 254AC0 */
void Unknown801A5FF8(struct ObjGroup *arg0)
{
    struct ObjView *menuview; // 3c
    UNUSED struct ObjLabel *label; // 38
    struct ObjGroup *menugrp; // 34
    UNUSED u32 pad2C[2];

    d_start_group("menug");
    D_801BD778[0] = d_makeobj(D_GADGET, "menu0");
    d_set_objheader_flag(8);
    d_set_world_pos(5.0f, 0.0f, 0.0f);
    d_set_scale(100.0f, 20.0f, 0.0f);
    d_set_type(6);
    d_set_colour_num(2);
    label = (struct ObjLabel *)d_makeobj(D_LABEL, AsDynId(0));
    d_set_rel_pos(5.0f, 18.0f, 0.0f);
    d_set_parm_ptr(PARM_PTR_CHAR, "ITEM 1");
    d_add_valptr("menu0", 0x40000, 0, (uintptr_t) NULL);

    D_801BD778[1] = d_makeobj(D_GADGET, "menu1");
    d_set_objheader_flag(8);
    d_set_world_pos(5.0f, 25.0f, 0.0f);
    d_set_scale(100.0f, 20.0f, 0.0f);
    d_set_type(6);
    d_set_colour_num(4);
    label = (struct ObjLabel *)d_makeobj(D_LABEL, AsDynId(0));
    d_set_rel_pos(5.0f, 18.0f, 0.0f);
    d_set_parm_ptr(PARM_PTR_CHAR, "ITEM 2");
    d_add_valptr("menu1", 0x40000, 0, (uintptr_t) NULL);

    D_801BD778[2] = d_makeobj(D_GADGET, "menu2");
    d_set_objheader_flag(8);
    d_set_world_pos(5.0f, 50.0f, 0.0f);
    d_set_scale(100.0f, 20.0f, 0.0f);
    d_set_type(6);
    d_set_colour_num(3);
    label = (struct ObjLabel *)d_makeobj(D_LABEL, AsDynId(0));
    d_set_rel_pos(5.0f, 18.0f, 0.0f);
    d_set_parm_ptr(PARM_PTR_CHAR, "ITEM 3");
    d_add_valptr("menu2", 0x40000, 0, (uintptr_t) NULL);
    sItemsInMenu = 3;
    d_end_group("menug");

    menugrp = (struct ObjGroup *)d_use_obj("menug");
    menuview = make_view("menuview", 0x6418, 2, 100, 20, 110, 150, menugrp);
    menuview->unk7C.r = 0.0f;
    menuview->unk7C.g = 0.0f;
    menuview->unk7C.b = 0.0f;
    addto_group(arg0, &menugrp->header);
    sMenuView = menuview;
}

// TODO: fixed point macros (10.2)?
/* 254AC0 -> 254DFC; orig name: PutSprite */
void gd_put_sprite(u16 *sprite, s32 x, s32 y, s32 wx, s32 wy)
{
    int c; // 5c
    int r; // 58

    gSPDisplayList(next_gfx(), osVirtualToPhysical(marioHeadDl801B52D8));
    for (r = 0; r < wy; r += 0x20)
    { // L801A6348
        for (c = 0; c < wx; c += 0x20)
        { // L801A6358
            // gDPLoadTextureBlock? (pkt, timg, fmt, siz, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt)
            //? texture offset has to be written like that
            gDPSetTextureImage(next_gfx(), G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (r*0x20) + sprite + c);
            gDPSetTile(next_gfx(), G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0, 
                (G_TX_NOMIRROR| G_TX_WRAP), G_TX_NOMASK, G_TX_NOLOD,
                (G_TX_NOMIRROR| G_TX_WRAP), G_TX_NOMASK, G_TX_NOLOD
            );
            gDPLoadSync(next_gfx());
            gDPLoadBlock(next_gfx(), 7, 0, 0, 1023, 256);
            gDPPipeSync(next_gfx());
            gDPSetTile(next_gfx(), G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0,
                (G_TX_NOMIRROR| G_TX_WRAP), G_TX_NOMASK, G_TX_NOLOD,
                (G_TX_NOMIRROR| G_TX_WRAP), G_TX_NOMASK, G_TX_NOLOD
            );
            gDPSetTileSize(next_gfx(), 0, 0, 0, 124, 124);
            gSPTextureRectangle(next_gfx(), 
                x << 2, (y + r) << 2, 
                (x + 0x20) << 2, (y + r + 0x20) << 2,
                0, 0, 0, 1024, 1024
            );
        }
        // L801A655C
    }
    // L801A6574
    gDPPipeSync(next_gfx());
    gDPSetCycleType(next_gfx(), G_CYC_1CYCLE);
    gDPSetRenderMode(next_gfx(), 0x0044 << 16, 0x2478);
    gSPTexture(next_gfx(), 0x8000, 0x8000, 0, 0, 0);
}

/* 254DFC -> 254F94; orig name: proc_dyn_list */
void gd_setup_cursor(struct ObjGroup *parentgrp)
{
    struct ObjView *mouseview; // 34
    struct ObjGroup *mousegrp; // 30
    UNUSED struct ObjNet *net; // 2c

    sHandShape = make_shape(0, "mouse");
    sHandShape->unk48[0] = gd_startdisplist(7);
    gd_put_sprite(textureHandOpen, 100, 100, 32, 32);
    gd_end_dl();
    sHandShape->unk48[1] = gd_startdisplist(7);
    gd_put_sprite(textureHandOpen, 100, 100, 32, 32);
    gd_end_dl();

    d_start_group("mouseg");
    net = (struct ObjNet *)d_makeobj(D_NET, AsDynId(0));
    d_set_init_pos(0.0f, 0.0f, 0.0f);
    d_set_type(3);
    d_set_shapeptrptr(&sHandShape);
    d_end_group("mouseg");

    mousegrp = (struct ObjGroup *)d_use_obj("mouseg");
    mouseview = make_view("mouseview", 0xe0018, 2, 0, 0, 32, 32, mousegrp);
    mouseview->unk34 &= ~0x800;
    sHandView = mouseview;
    if (parentgrp != NULL)
    {
        addto_group(parentgrp, &mousegrp->header);
    }
}

/* 254F94 -> 254FE4; orig name: Proc801A67C4 */
void view_proc_print_timers(struct ObjView *self)
{
    if (self->unk34 & 0x100000) { return; }

    print_all_timers();
}

/* 254FE4 -> 255600; not called; orig name: Unknown801A6814 */
void make_timer_gadgets(void)
{
    struct ObjLabel *timerLabel; // 74
    struct ObjGroup *timerg; // 70
    UNUSED u32 pad6C;
    struct ObjView *timersview; // 68
    struct ObjGadget *bar1; // 64
    struct ObjGadget *bar2; // 60
    struct ObjGadget *bar3; // 5c
    struct ObjGadget *bar4; // 58
    struct ObjGadget *bar5; // 54
    struct ObjGadget *bar6; // 50
    struct GdTimer *timer; // 4c
    int i; // 48
    char timerNameBuf[0x20]; // 28

    d_start_group("timerg");
    d_makeobj(D_GADGET, "bar1");
    d_set_objheader_flag(8);
    d_set_world_pos(20.0f, 5.0f, 0.0f);
    d_set_scale(50.0f, 5.0f, 0.0f);
    d_set_type(4);
    d_set_parm_f(2, 0);
    d_set_parm_f(3, sTimeScaleFactor);
    d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&sTimeScaleFactor);
    bar1 = (struct ObjGadget *)d_use_obj("bar1");
    bar1->unk5C = 1;

    d_makeobj(D_GADGET, "bar2");
    d_set_objheader_flag(8);
    d_set_world_pos(70.0f, 5.0f, 0.0f);
    d_set_scale(50.0f, 5.0f, 0.0f);
    d_set_type(4);
    d_set_parm_f(2, 0);
    d_set_parm_f(3, sTimeScaleFactor);
    d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&sTimeScaleFactor);
    bar2 = (struct ObjGadget *)d_use_obj("bar2");
    bar2->unk5C = 9;

    d_makeobj(D_GADGET, "bar3");
    d_set_objheader_flag(8);
    d_set_world_pos(120.0f, 5.0f, 0.0f);
    d_set_scale(50.0f, 5.0f, 0.0f);
    d_set_type(4);
    d_set_parm_f(2, 0);
    d_set_parm_f(3, sTimeScaleFactor);
    d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&sTimeScaleFactor);
    bar3 = (struct ObjGadget *)d_use_obj("bar3");
    bar3->unk5C = 1;

    d_makeobj(D_GADGET, "bar4");
    d_set_objheader_flag(8);
    d_set_world_pos(170.0f, 5.0f, 0.0f);
    d_set_scale(50.0f, 5.0f, 0.0f);
    d_set_type(4);
    d_set_parm_f(2, 0);
    d_set_parm_f(3, sTimeScaleFactor);
    d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&sTimeScaleFactor);
    bar4 = (struct ObjGadget *)d_use_obj("bar4");
    bar4->unk5C = 9;

    d_makeobj(D_GADGET, "bar5");
    d_set_objheader_flag(8);
    d_set_world_pos(220.0f, 5.0f, 0.0f);
    d_set_scale(50.0f, 5.0f, 0.0f);
    d_set_type(4);
    d_set_parm_f(2, 0);
    d_set_parm_f(3, sTimeScaleFactor);
    d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&sTimeScaleFactor);
    bar5 = (struct ObjGadget *)d_use_obj("bar5");
    bar5->unk5C = 1;

    d_makeobj(D_GADGET, "bar6");
    d_set_objheader_flag(8);
    d_set_world_pos(270.0f, 5.0f, 0.0f);
    d_set_scale(50.0f, 5.0f, 0.0f);
    d_set_type(4);
    d_set_parm_f(2, 0);
    d_set_parm_f(3, sTimeScaleFactor);
    d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&sTimeScaleFactor);
    bar6 = (struct ObjGadget *)d_use_obj("bar6");
    bar6->unk5C = 9;

    for (i = 0; i < GD_NUM_TIMERS; i++)
    { // L801A6BEC
        sprintf(timerNameBuf, "tim%d\n", i);
        timer = get_timernum(i); 
        d_makeobj(D_GADGET, timerNameBuf);
        d_set_objheader_flag(8);
        d_set_world_pos(20.0f, (f32) ((i * 15) + 15), 0.0f);
        d_set_scale(50.0f, 14.0f, 0);
        d_set_type(4);
        d_set_parm_f(2, 0.0f);
        d_set_parm_f(3, 1.0f);
        d_add_valptr(AsDynId(0), 0, 2, (uintptr_t)&timer->prevScaledTotal);
        sTimerGadgets[i] = (struct ObjGadget *)d_use_obj(timerNameBuf);
        sTimerGadgets[i]->unk5C = timer->unk1C;
        timerLabel = (struct ObjLabel *)d_makeobj(D_LABEL, AsDynId(0));
        d_set_rel_pos(5.0f, 14.0f, 0);
        d_set_parm_ptr(PARM_PTR_CHAR, (void *)timer->name);
        d_add_valptr(timerNameBuf, 0x40000, 0, (uintptr_t) NULL);
        timerLabel->unk30 = 3;
    }
    // 801A6D50
    d_end_group("timerg");
    timerg = (struct ObjGroup *)d_use_obj("timerg");
    timersview = make_view("timersview", 0xe0018, 2, 0, 10, 320, 270, timerg);
    timersview->unk7C.r = 0.0f;
    timersview->unk7C.g = 0.0f;
    timersview->unk7C.b = 0.0f;
    timersview->unk34 &= ~0x800;
    timersview->unk98 = view_proc_print_timers;
    func_801A5BE8(timersview);

    return;
}

/* 255600 -> 255614 */
void Unknown801A6E30(UNUSED u32 a0)
{
}

/* 255614 -> 255628 */
void Unknown801A6E44(UNUSED u32 a0)
{
}


/* 255628 -> 255704; orig name: func_801A6E58 */
void gd_block_dma(u32 devAddr, void *vAddr, s32 size)
{
    s32 transfer; // 2c

    do
    { // L801A6E6C
        if ((transfer = size) > 0x1000)
        {
            transfer = 0x1000;
        } 
        // L801A6E88
        osPiStartDma(&sGdBssOverlap.D_801BE980, OS_MESG_PRI_NORMAL, OS_READ, devAddr, vAddr, transfer, &sGdDMAQueue);
        osRecvMesg(&sGdDMAQueue, &D_801BE97C, OS_MESG_BLOCK);
        devAddr += transfer;
        vAddr = (void *)((uintptr_t)vAddr + transfer);
        size -= 0x1000;
    }
    while (size > 0);
}

/* 255704 -> 255988 */
struct ObjGroup *load_dynlist(struct DynList *dynlist)
{
    u32 segSize; // 4c
    u8 *allocSegSpace; // 48
    void *allocPtr; // 44
    uintptr_t dynlistSegStart; // 40
    uintptr_t dynlistSegEnd; // 3c
    s32 i; // 38
    s32 sp34; // tlbPage
    struct ObjGroup *loadedList; //30

    i = -1;

    while (D_801A8704[++i].list != NULL)
    {
        if (D_801A8704[i].list == dynlist) { break; }
    } 
    // L801A6FC0
    if (D_801A8704[i].list == NULL)
    {
        fatal_printf("load_dynlist() ptr not found in any banks");
    }

    switch (D_801A8704[i].flag)
    {
        case STD_LIST_BANK:
            dynlistSegStart = (uintptr_t)_gd_dynlistsSegmentRomStart;
            dynlistSegEnd = (uintptr_t)_gd_dynlistsSegmentRomEnd;
            break;
        default:
            fatal_printf("load_dynlist() unkown bank");
    }
    // L801A7040
    segSize = dynlistSegEnd - dynlistSegStart;
    allocSegSpace = gd_malloc_temp(segSize + 0x10000);

    if ((allocPtr = (void *)allocSegSpace) == NULL)
    {
        fatal_printf("Not enough DRAM for DATA segment \n");
    }
    // L801A7084
    allocSegSpace = (u8 *)(((uintptr_t)allocSegSpace + 0x10000) & 0xFFFF0000);
    gd_block_dma(dynlistSegStart, (void *)allocSegSpace, segSize);
    osUnmapTLBAll();

    sp34 = (segSize / 0x10000) / 2 + 1; //? has to be written this way
    if (sp34 >= 31) 
    {
        fatal_printf("load_dynlist() too many TLBs");
    }

    for (i = 0; i < sp34; i++)
    { // L801A7100
        osMapTLB(i, OS_PM_64K, 
            (void *) (0x04000000 + (i * 2 * 0x10000)),
            GD_LOWER_24(((uintptr_t) allocSegSpace) + (i * 2 * 0x10000)), 
            GD_LOWER_24(((uintptr_t) allocSegSpace) + (i * 2 * 0x10000) + 0x10000),
            -1
        );
    }
    // L801A7170
    loadedList = (struct ObjGroup *)proc_dynlist(dynlist);
    gd_free(allocPtr);
    osUnmapTLBAll();

    return loadedList;
}

/* 255988 -> 25599C */
void stub_801A71B8(UNUSED u32 a0)
{
}

/* 25599C -> 255EB0; not called */
void func_801A71CC(struct ObjNet *net)
{
    int i; // spB4
    int j; // spB0
    f32 spAC;
    f32 spA8;
    struct GdPlaneF sp90;
    UNUSED u32 pad8C;
    struct ObjZone *sp88;
    register struct Links *link; // s0 (84)
    s32 sp80; // linked planes contained in zone?
    s32 sp7C; // linked planes in net count?
    register struct Links *link1; // s1 (78)
    register struct Links *link2; // s2 (74)
    register struct Links *link3; // s3 (70)
    struct MyVec3f sp64;
    UNUSED u32 pad60;
    struct ObjPlane *plane; // 5c
    UNUSED u32 pad58;
    struct ObjZone *linkedZone; // 54
    UNUSED u32 pad50;
    struct ObjPlane *planeL2; // 4c
    UNUSED u32 pad48;
    struct ObjPlane *planeL3; // 44

    if (net->unk21C == NULL)
    {
        net->unk21C = make_group(0);
    }
    // L801A7224
    gd_print_plane("making zones for net=", &net->unkBC);

    sp64.x = (ABS(net->unkBC.vec0.x) + ABS(net->unkBC.vec1.x)) / 16.0f;
    sp64.z = (ABS(net->unkBC.vec0.z) + ABS(net->unkBC.vec1.z)) / 16.0f;
    // 801A7348

    spA8 = net->unkBC.vec0.z + sp64.z / 2.0f;
    
    for (i = 0; i < 16; i++)
    { //L801A7370
        spAC = net->unkBC.vec0.x + sp64.x / 2.0f;

        for (j = 0; j < 16; j++)
        { // L801A7398
            sp90.vec0.x = spAC - (sp64.x / 2.0f);
            sp90.vec0.y = 0.0f;
            sp90.vec0.z = spA8 - (sp64.z / 2.0f);

            sp90.vec1.x = spAC + (sp64.x / 2.0f);
            sp90.vec1.y = 0.0f;
            sp90.vec1.z = spA8 + (sp64.z / 2.0f);

            sp88 = make_zone(NULL, &sp90, NULL);
            addto_group(net->unk21C, &sp88->header);
            sp88->unk2C = make_group(0);

            spAC += sp64.x;
        }
        // 801A7488
        spA8 += sp64.z;
    }
    // 801A74B4
    

    for (link = net->unk1CC->link1C; link != NULL; link = link->next)
    { // L801A74D4
        plane = (struct ObjPlane *)link->obj;
        plane->unk18 = FALSE;
    }
    // L801A74FC

    i = 0; // acts as Zone N here... kinda
    for (link1 = net->unk21C->link1C; link1 != NULL; link1 = link1->next)
    { // L801A7520
        linkedZone = (struct ObjZone *)link1->obj;
        sp88 = linkedZone;
        sp7C = 0;
        sp80 = 0;

        for (link2 = net->unk1CC->link1C; link2 != NULL; link2 = link2->next)
        { // L801A7560
            planeL2 = (struct ObjPlane *)link2->obj;
            sp7C += 1;
            if (gd_plane_point_within(&planeL2->plane28, &sp88->unk14))
            {
                planeL2->unk18 = TRUE;
                addto_group(sp88->unk2C, &planeL2->header);
                sp80 += 1;
            }
            // L801A75C8
        }
        // L801A75D8
        if (sp80 == 0)
        {
            func_8017BED0(net->unk21C, &linkedZone->header); // stubbed fatal function?
        }
        else 
        {
            gd_printf("%d/%d planes in zone %d\n", sp80, sp7C, i++);
        }
        // L801A7628

    }
    // L801A7638
    for (link3 = net->unk1CC->link1C; link3 != NULL; link3 = link3->next)
    { // L801A7658
        planeL3 = (struct ObjPlane *)link3->obj;

        if (!planeL3->unk18)
        {
            gd_print_plane("plane=", &planeL3->plane28);
            fatal_printf("plane not in any zones\n");
        }
        // L801A769C
    }
    // L801A76AC    
}

/* 255EB0 -> 255EC0 */
void stub_801A76E0(void)
{
}
