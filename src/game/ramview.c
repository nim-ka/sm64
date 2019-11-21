#include <ultra64.h>

#include "sm64.h"
#include "game.h"
#include "area.h"
#include "ingame_menu.h"
#include "ramview.h"

u32 sCurrRamviewPtr = 0x80000000;
u32 sCurrCursorPtr  = 0x80000000;

u8 sDisplayRamview = FALSE;

char sDataBuf[1024];

static void get_data(char *buf, u8 *ptr, s32 len) {
    s32 i;

    for (i = 0; i < len; i++) {
        sprintf(buf + i*2, "%02x", ptr[i]);
    }
}

void ramview(void) {
    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        sDisplayRamview ^= 1;
        gRenderHud = !sDisplayRamview;
    }

    if (sDisplayRamview) {
        char addrbuf[10];
        s32 i;
        u32 newCursor;

        u8 r = gPlayer1Controller->buttonDown & R_TRIG;

        u32 diff = sCurrCursorPtr - sCurrRamviewPtr;

        if (gPlayer1Controller->buttonPressed & U_JPAD) sCurrRamviewPtr += 0x100 * (r ? 0x100 : 0x001);
        if (gPlayer1Controller->buttonPressed & R_JPAD) sCurrRamviewPtr += 0x10  * (r ? 0x100 : 0x001);
        if (gPlayer1Controller->buttonPressed & D_JPAD) sCurrRamviewPtr -= 0x100 * (r ? 0x100 : 0x001);
        if (gPlayer1Controller->buttonPressed & L_JPAD) sCurrRamviewPtr -= 0x10  * (r ? 0x100 : 0x001);

        sCurrCursorPtr = sCurrRamviewPtr + diff;
        newCursor = sCurrCursorPtr;

        if (gPlayer1Controller->buttonPressed & U_CBUTTONS) newCursor -= 0x8;
        if (gPlayer1Controller->buttonPressed & R_CBUTTONS) newCursor ++;
        if (gPlayer1Controller->buttonPressed & D_CBUTTONS) newCursor += 0x8;
        if (gPlayer1Controller->buttonPressed & L_CBUTTONS) newCursor --;

        if (newCursor >= sCurrRamviewPtr && newCursor < (sCurrRamviewPtr + 0x40)) {
            sCurrCursorPtr = newCursor;
        }

        if (gPlayer1Controller->buttonPressed & A_BUTTON) (* (u8 *) sCurrCursorPtr) ++;
        if (gPlayer1Controller->buttonPressed & B_BUTTON) (* (u8 *) sCurrCursorPtr) --;

        sprintf(addrbuf, "%08x", sCurrRamviewPtr);
        print_text(50, 210, addrbuf);

        print_text(50 + (sCurrCursorPtr & 0x7) * 24, 190 - ((sCurrCursorPtr - sCurrRamviewPtr) / 8) * 20, "..");

        for (i = 0; i < 8; i ++) {
            s32 y = 190 - i*20;

            print_text_fmt_int(10, y, "%02x", i * 8);

            get_data(sDataBuf, (u8 *) sCurrRamviewPtr + i * 8, 8);
            print_text(50, y, sDataBuf);
        }
    }
}
