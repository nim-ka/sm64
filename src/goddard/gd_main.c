#include <ultra64.h>

#include "sm64.h"
#include "gd_main.h"
#include "debug_memory.h"
#include "mario_head_1.h"
#include "profiler_utils.h"
#include "mario_head_6.h"

/* This file was spilt out of debug_memory.asm based on rodata.
 * The rodata for functions after this "__main__" function have string literals following 
 * float literal, which implies that this is its own file
 */

// data
s32 gGdMoveScene = TRUE; // @ 801A8050
static s32 sUnref801A8054 = TRUE;
f32 D_801A8058 = -600.0f;
s32 D_801A805C = TRUE;
static s32 sUnrefScnWidth = 320;
static s32 sUnrefScnHeight = 240;

// bss
struct GdControl gGdCtrl;     // @ 801B9920; processed controller info
struct GdControl gGdCtrlPrev; // @ 801B9A18; previous frame's controller info

/* @ 225DA0 for 0x110 */
u32 __main__(void)
{
    UNUSED u32 pad1C;

    gd_printf("%x, %x\n", (u32) &D_801A8058, (u32) &gGdMoveScene);
    add_to_stacktrace("main");
    gd_init();

    gGdCtrl.unk88 = 0.46799f;
    gGdCtrl.unkA0 = -34.0f;
    gGdCtrl.unkAC = 34.0f;
    gGdCtrl.unk00 = 2;
    gGdCtrl.newStartPress = FALSE;
    gGdCtrl.prevFrame = &gGdCtrlPrev;

    add_to_stacktrace("main - make_scene");
    //TODO: rename to "make_scene"?; called function does nothing, though
    func_8017E20C();
    imout();
    
    gd_init_controllers();
    print_all_memtrackers();

    start_timer("dlgen");
    stop_timer("dlgen");
    mem_stats();

    while (TRUE)
        func_801A520C();
    
    imout();
    return 0;
}
