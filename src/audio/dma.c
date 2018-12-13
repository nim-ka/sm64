#include <ultra64.h>

#include "sm64.h"
#include "dma.h"
#include "dac.h"
#include "interface_1.h"

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

void BlockDmaCopy(u32 devAddr, void *vAddr, u32 nbytes)
{
    osInvalDCache(vAddr, (s32)nbytes);
    osPiStartDma(&D_80226520, OS_MESG_PRI_HIGH, OS_READ, devAddr, vAddr, nbytes, &D_80226500);
    osRecvMesg(&D_80226500, NULL, OS_MESG_BLOCK);
}

void func_80317034(u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *queue, OSIoMesg *mesg)
{
    osInvalDCache(vAddr, (s32)nbytes);
    osPiStartDma(mesg, OS_MESG_PRI_NORMAL, OS_READ, devAddr, vAddr, nbytes, queue);
}

void func_803170A0(u32 *devAddr, u8 **vAddr, s32 *size, OSMesgQueue *queue, OSIoMesg *mesg)
{
    s32 transfer = (*size < 0x1000 ? *size : 0x1000);
    *size -= transfer;
    osInvalDCache(*vAddr, transfer);
    osPiStartDma(mesg, OS_MESG_PRI_NORMAL, OS_READ, *devAddr, *vAddr, transfer, queue);
    *devAddr += transfer;
    *vAddr += transfer;
}

void func_8031715C()
{
    // (uses too much stack if declared as '(void)')
    u32 i;

    for (i = 0; i < D_80226B3C; i++)
    {
        struct Unk16 *temp = D_80226538 + i;
        if (temp->unkE != 0)
        {
            temp->unkE--;
            if (temp->unkE == 0)
            {
                temp->unkD = D_80226D4A;
                D_80226B48[D_80226D4A++] = (u8)i;
            }
        }
    }

    for (i = D_80226B3C; i < D_80226B38; i++)
    {
        struct Unk16 *temp = D_80226538 + i;
        if (temp->unkE != 0)
        {
            temp->unkE--;
            if (temp->unkE == 0)
            {
                temp->unkD = D_80226D4B;
                D_80226C48[D_80226D4B++] = (u8)i;
            }
        }
    }

    D_80226B40 = 0;
}

#ifdef VERSION_JP

GLOBAL_ASM(
glabel func_80317270
/* 0D2270 80317270 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D2274 80317274 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D2278 80317278 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0D227C 8031727C AFB00038 */  sw    $s0, 0x38($sp)
/* 0D2280 80317280 00A08025 */  move  $s0, $a1
/* 0D2284 80317284 00808825 */  move  $s1, $a0
/* 0D2288 80317288 03A0F025 */  move  $fp, $sp
/* 0D228C 8031728C AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D2290 80317290 AFA60068 */  sw    $a2, 0x68($sp)
/* 0D2294 80317294 AFA7006C */  sw    $a3, 0x6c($sp)
/* 0D2298 80317298 14C0000A */  bnez  $a2, .L803172C4
/* 0D229C 8031729C 00005825 */   move  $t3, $zero
/* 0D22A0 803172A0 8FCF006C */  lw    $t7, 0x6c($fp)
/* 0D22A4 803172A4 3C188022 */  lui   $t8, %hi(D_80226B3C) # $t8, 0x8022
/* 0D22A8 803172A8 8F186B3C */  lw    $t8, %lo(D_80226B3C)($t8)
/* 0D22AC 803172AC 91E40000 */  lbu   $a0, ($t7)
/* 0D22B0 803172B0 3C068022 */  lui   $a2, %hi(D_80226538) # $a2, 0x8022
/* 0D22B4 803172B4 24C66538 */  addiu $a2, %lo(D_80226538) # addiu $a2, $a2, 0x6538
/* 0D22B8 803172B8 0098082B */  sltu  $at, $a0, $t8
/* 0D22BC 803172BC 14200052 */  bnez  $at, .L80317408
/* 0D22C0 803172C0 0004C100 */   sll   $t8, $a0, 4
.L803172C4:
/* 0D22C4 803172C4 3C048022 */  lui   $a0, %hi(D_80226B3C) # $a0, 0x8022
/* 0D22C8 803172C8 3C058022 */  lui   $a1, %hi(D_80226B38) # $a1, 0x8022
/* 0D22CC 803172CC 8CA56B38 */  lw    $a1, %lo(D_80226B38)($a1)
/* 0D22D0 803172D0 8C846B3C */  lw    $a0, %lo(D_80226B3C)($a0)
/* 0D22D4 803172D4 3C068022 */  lui   $a2, %hi(D_80226538) # $a2, 0x8022
/* 0D22D8 803172D8 24C66538 */  addiu $a2, %lo(D_80226538) # addiu $a2, $a2, 0x6538
/* 0D22DC 803172DC 0085082B */  sltu  $at, $a0, $a1
/* 0D22E0 803172E0 10200032 */  beqz  $at, .L803173AC
/* 0D22E4 803172E4 0004C900 */   sll   $t9, $a0, 4
.L803172E8:
/* 0D22E8 803172E8 00D91821 */  addu  $v1, $a2, $t9
/* 0D22EC 803172EC 8C6D0004 */  lw    $t5, 4($v1)
/* 0D22F0 803172F0 00604025 */  move  $t0, $v1
/* 0D22F4 803172F4 022D1023 */  subu  $v0, $s1, $t5
/* 0D22F8 803172F8 04420028 */  bltzl $v0, .L8031739C
/* 0D22FC 803172FC 24840001 */   addiu $a0, $a0, 1
/* 0D2300 80317300 946E000A */  lhu   $t6, 0xa($v1)
/* 0D2304 80317304 01D07823 */  subu  $t7, $t6, $s0
/* 0D2308 80317308 01E2082B */  sltu  $at, $t7, $v0
/* 0D230C 8031730C 54200023 */  bnezl $at, .L8031739C
/* 0D2310 80317310 24840001 */   addiu $a0, $a0, 1
/* 0D2314 80317314 9078000E */  lbu   $t8, 0xe($v1)
/* 0D2318 80317318 3C098022 */  lui   $t1, %hi(D_80226D49) # $t1, 0x8022
/* 0D231C 8031731C 25296D49 */  addiu $t1, %lo(D_80226D49) # addiu $t1, $t1, 0x6d49
/* 0D2320 80317320 17000014 */  bnez  $t8, .L80317374
/* 0D2324 80317324 3C198022 */   lui   $t9, %hi(D_80226D4B) # $t9, 0x8022
/* 0D2328 80317328 91250000 */  lbu   $a1, ($t1)
/* 0D232C 8031732C 93396D4B */  lbu   $t9, %lo(D_80226D4B)($t9)
/* 0D2330 80317330 53250011 */  beql  $t9, $a1, .L80317378
/* 0D2334 80317334 2418003C */   li    $t8, 60
/* 0D2338 80317338 9067000D */  lbu   $a3, 0xd($v1)
/* 0D233C 8031733C 3C0C8022 */  lui   $t4, %hi(D_80226C48) # $t4, 0x8022
/* 0D2340 80317340 258C6C48 */  addiu $t4, %lo(D_80226C48) # addiu $t4, $t4, 0x6c48
/* 0D2344 80317344 10A70009 */  beq   $a1, $a3, .L8031736C
/* 0D2348 80317348 01851021 */   addu  $v0, $t4, $a1
/* 0D234C 8031734C 904D0000 */  lbu   $t5, ($v0)
/* 0D2350 80317350 01877021 */  addu  $t6, $t4, $a3
/* 0D2354 80317354 A1CD0000 */  sb    $t5, ($t6)
/* 0D2358 80317358 90580000 */  lbu   $t8, ($v0)
/* 0D235C 8031735C 906F000D */  lbu   $t7, 0xd($v1)
/* 0D2360 80317360 0018C900 */  sll   $t9, $t8, 4
/* 0D2364 80317364 00D96821 */  addu  $t5, $a2, $t9
/* 0D2368 80317368 A1AF000D */  sb    $t7, 0xd($t5)
.L8031736C:
/* 0D236C 8031736C 24AE0001 */  addiu $t6, $a1, 1
/* 0D2370 80317370 A12E0000 */  sb    $t6, ($t1)
.L80317374:
/* 0D2374 80317374 2418003C */  li    $t8, 60
.L80317378:
/* 0D2378 80317378 A078000E */  sb    $t8, 0xe($v1)
/* 0D237C 8031737C 8FD9006C */  lw    $t9, 0x6c($fp)
/* 0D2380 80317380 A3240000 */  sb    $a0, ($t9)
/* 0D2384 80317384 8C6F0004 */  lw    $t7, 4($v1)
/* 0D2388 80317388 8C6E0000 */  lw    $t6, ($v1)
/* 0D238C 8031738C 022F6823 */  subu  $t5, $s1, $t7
/* 0D2390 80317390 10000077 */  b     .L80317570
/* 0D2394 80317394 01AE1021 */   addu  $v0, $t5, $t6
/* 0D2398 80317398 24840001 */  addiu $a0, $a0, 1
.L8031739C:
/* 0D239C 8031739C 0085082B */  sltu  $at, $a0, $a1
/* 0D23A0 803173A0 5420FFD1 */  bnezl $at, .L803172E8
/* 0D23A4 803173A4 0004C900 */   sll   $t9, $a0, 4
/* 0D23A8 803173A8 AFC80058 */  sw    $t0, 0x58($fp)
.L803173AC:
/* 0D23AC 803173AC 3C098022 */  lui   $t1, %hi(D_80226D49) # $t1, 0x8022
/* 0D23B0 803173B0 25296D49 */  addiu $t1, %lo(D_80226D49) # addiu $t1, $t1, 0x6d49
/* 0D23B4 803173B4 3C188022 */  lui   $t8, %hi(D_80226D4B) # $t8, 0x8022
/* 0D23B8 803173B8 93186D4B */  lbu   $t8, %lo(D_80226D4B)($t8)
/* 0D23BC 803173BC 91250000 */  lbu   $a1, ($t1)
/* 0D23C0 803173C0 3C068022 */  lui   $a2, %hi(D_80226538) # $a2, 0x8022
/* 0D23C4 803173C4 24C66538 */  addiu $a2, %lo(D_80226538) # addiu $a2, $a2, 0x6538
/* 0D23C8 803173C8 1305000D */  beq   $t8, $a1, .L80317400
/* 0D23CC 803173CC 8FC80058 */   lw    $t0, 0x58($fp)
/* 0D23D0 803173D0 8FD90068 */  lw    $t9, 0x68($fp)
/* 0D23D4 803173D4 3C0C8022 */  lui   $t4, %hi(D_80226C48) # $t4, 0x8022
/* 0D23D8 803173D8 258C6C48 */  addiu $t4, %lo(D_80226C48) # addiu $t4, $t4, 0x6c48
/* 0D23DC 803173DC 13200008 */  beqz  $t9, .L80317400
/* 0D23E0 803173E0 01857821 */   addu  $t7, $t4, $a1
/* 0D23E4 803173E4 91EA0000 */  lbu   $t2, ($t7)
/* 0D23E8 803173E8 24AD0001 */  addiu $t5, $a1, 1
/* 0D23EC 803173EC A12D0000 */  sb    $t5, ($t1)
/* 0D23F0 803173F0 000A7100 */  sll   $t6, $t2, 4
/* 0D23F4 803173F4 00CE4021 */  addu  $t0, $a2, $t6
/* 0D23F8 803173F8 240B0001 */  li    $t3, 1
/* 0D23FC 803173FC AFCA0048 */  sw    $t2, 0x48($fp)
.L80317400:
/* 0D2400 80317400 10000027 */  b     .L803174A0
/* 0D2404 80317404 00000000 */   nop   
.L80317408:
/* 0D2408 80317408 03064021 */  addu  $t0, $t8, $a2
/* 0D240C 8031740C 8D190004 */  lw    $t9, 4($t0)
/* 0D2410 80317410 02391823 */  subu  $v1, $s1, $t9
/* 0D2414 80317414 04600022 */  bltz  $v1, .L803174A0
/* 0D2418 80317418 00000000 */   nop   
/* 0D241C 8031741C 950F000A */  lhu   $t7, 0xa($t0)
/* 0D2420 80317420 01F06823 */  subu  $t5, $t7, $s0
/* 0D2424 80317424 01A3082B */  sltu  $at, $t5, $v1
/* 0D2428 80317428 1420001D */  bnez  $at, .L803174A0
/* 0D242C 8031742C 00000000 */   nop   
/* 0D2430 80317430 910E000E */  lbu   $t6, 0xe($t0)
/* 0D2434 80317434 3C058022 */  lui   $a1, %hi(D_80226D48) # $a1, 0x8022
/* 0D2438 80317438 24A56D48 */  addiu $a1, %lo(D_80226D48) # addiu $a1, $a1, 0x6d48
/* 0D243C 8031743C 55C00014 */  bnezl $t6, .L80317490
/* 0D2440 80317440 8D0F0000 */   lw    $t7, ($t0)
/* 0D2444 80317444 90A20000 */  lbu   $v0, ($a1)
/* 0D2448 80317448 9104000D */  lbu   $a0, 0xd($t0)
/* 0D244C 8031744C 3C078022 */  lui   $a3, %hi(D_80226B48) # $a3, 0x8022
/* 0D2450 80317450 24E76B48 */  addiu $a3, %lo(D_80226B48) # addiu $a3, $a3, 0x6b48
/* 0D2454 80317454 10440009 */  beq   $v0, $a0, .L8031747C
/* 0D2458 80317458 00E21821 */   addu  $v1, $a3, $v0
/* 0D245C 8031745C 90780000 */  lbu   $t8, ($v1)
/* 0D2460 80317460 00E4C821 */  addu  $t9, $a3, $a0
/* 0D2464 80317464 A3380000 */  sb    $t8, ($t9)
/* 0D2468 80317468 906D0000 */  lbu   $t5, ($v1)
/* 0D246C 8031746C 910F000D */  lbu   $t7, 0xd($t0)
/* 0D2470 80317470 000D7100 */  sll   $t6, $t5, 4
/* 0D2474 80317474 00CEC021 */  addu  $t8, $a2, $t6
/* 0D2478 80317478 A30F000D */  sb    $t7, 0xd($t8)
.L8031747C:
/* 0D247C 8031747C 24590001 */  addiu $t9, $v0, 1
/* 0D2480 80317480 A0B90000 */  sb    $t9, ($a1)
/* 0D2484 80317484 8D0D0004 */  lw    $t5, 4($t0)
/* 0D2488 80317488 022D1823 */  subu  $v1, $s1, $t5
/* 0D248C 8031748C 8D0F0000 */  lw    $t7, ($t0)
.L80317490:
/* 0D2490 80317490 240E0002 */  li    $t6, 2
/* 0D2494 80317494 A10E000E */  sb    $t6, 0xe($t0)
/* 0D2498 80317498 10000035 */  b     .L80317570
/* 0D249C 8031749C 006F1021 */   addu  $v0, $v1, $t7
.L803174A0:
/* 0D24A0 803174A0 1560000C */  bnez  $t3, .L803174D4
/* 0D24A4 803174A4 8FCA0048 */   lw    $t2, 0x48($fp)
/* 0D24A8 803174A8 3C058022 */  lui   $a1, %hi(D_80226D48) # $a1, 0x8022
/* 0D24AC 803174AC 24A56D48 */  addiu $a1, %lo(D_80226D48) # addiu $a1, $a1, 0x6d48
/* 0D24B0 803174B0 90A20000 */  lbu   $v0, ($a1)
/* 0D24B4 803174B4 3C078022 */  lui   $a3, %hi(D_80226B48) # $a3, 0x8022
/* 0D24B8 803174B8 24E76B48 */  addiu $a3, %lo(D_80226B48) # addiu $a3, $a3, 0x6b48
/* 0D24BC 803174BC 00E2C021 */  addu  $t8, $a3, $v0
/* 0D24C0 803174C0 930A0000 */  lbu   $t2, ($t8)
/* 0D24C4 803174C4 24590001 */  addiu $t9, $v0, 1
/* 0D24C8 803174C8 A0B90000 */  sb    $t9, ($a1)
/* 0D24CC 803174CC 000A6900 */  sll   $t5, $t2, 4
/* 0D24D0 803174D0 00CD4021 */  addu  $t0, $a2, $t5
.L803174D4:
/* 0D24D4 803174D4 9502000A */  lhu   $v0, 0xa($t0)
/* 0D24D8 803174D8 2401FFF0 */  li    $at, -16
/* 0D24DC 803174DC 3C098022 */  lui   $t1, %hi(D_80226D84) # $t1, 0x8022
/* 0D24E0 803174E0 240E0002 */  li    $t6, 2
/* 0D24E4 803174E4 02218024 */  and   $s0, $s1, $at
/* 0D24E8 803174E8 25296D84 */  addiu $t1, %lo(D_80226D84) # addiu $t1, $t1, 0x6d84
/* 0D24EC 803174EC A10E000E */  sb    $t6, 0xe($t0)
/* 0D24F0 803174F0 AD100004 */  sw    $s0, 4($t0)
/* 0D24F4 803174F4 A5020008 */  sh    $v0, 8($t0)
/* 0D24F8 803174F8 8D230000 */  lw    $v1, ($t1)
/* 0D24FC 803174FC 3C0E8022 */  lui   $t6, %hi(D_80226000) # $t6, 0x8022
/* 0D2500 80317500 25CE6000 */  addiu $t6, %lo(D_80226000) # addiu $t6, $t6, 0x6000
/* 0D2504 80317504 246F0001 */  addiu $t7, $v1, 1
/* 0D2508 80317508 AD2F0000 */  sw    $t7, ($t1)
/* 0D250C 8031750C 8D380000 */  lw    $t8, ($t1)
/* 0D2510 80317510 8D0F0000 */  lw    $t7, ($t0)
/* 0D2514 80317514 AFA20014 */  sw    $v0, 0x14($sp)
/* 0D2518 80317518 0018C880 */  sll   $t9, $t8, 2
/* 0D251C 8031751C 0338C821 */  addu  $t9, $t9, $t8
/* 0D2520 80317520 3C188022 */  lui   $t8, %hi(D_80225EE8) # $t8, 0x8022
/* 0D2524 80317524 27185EE8 */  addiu $t8, %lo(D_80225EE8) # addiu $t8, $t8, 0x5ee8
/* 0D2528 80317528 0019C880 */  sll   $t9, $t9, 2
/* 0D252C 8031752C 272DFFEC */  addiu $t5, $t9, -0x14
/* 0D2530 80317530 AFB80018 */  sw    $t8, 0x18($sp)
/* 0D2534 80317534 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0D2538 80317538 AFCA0048 */  sw    $t2, 0x48($fp)
/* 0D253C 8031753C AFC80058 */  sw    $t0, 0x58($fp)
/* 0D2540 80317540 01AE2021 */  addu  $a0, $t5, $t6
/* 0D2544 80317544 02003825 */  move  $a3, $s0
/* 0D2548 80317548 00002825 */  move  $a1, $zero
/* 0D254C 8031754C 0C0C8D4C */  jal   osPiStartDma
/* 0D2550 80317550 00003025 */   move  $a2, $zero
/* 0D2554 80317554 8FCA0048 */  lw    $t2, 0x48($fp)
/* 0D2558 80317558 8FD9006C */  lw    $t9, 0x6c($fp)
/* 0D255C 8031755C 8FC80058 */  lw    $t0, 0x58($fp)
/* 0D2560 80317560 A32A0000 */  sb    $t2, ($t9)
/* 0D2564 80317564 8D0D0000 */  lw    $t5, ($t0)
/* 0D2568 80317568 01B17021 */  addu  $t6, $t5, $s1
/* 0D256C 8031756C 01D01023 */  subu  $v0, $t6, $s0
.L80317570:
/* 0D2570 80317570 8FDF0044 */  lw    $ra, 0x44($fp)
/* 0D2574 80317574 03C0E825 */  move  $sp, $fp
/* 0D2578 80317578 8FD00038 */  lw    $s0, 0x38($fp)
/* 0D257C 8031757C 8FD1003C */  lw    $s1, 0x3c($fp)
/* 0D2580 80317580 8FDE0040 */  lw    $fp, 0x40($fp)
/* 0D2584 80317584 03E00008 */  jr    $ra
/* 0D2588 80317588 27BD0060 */   addiu $sp, $sp, 0x60
)

#else

GLOBAL_ASM(
glabel func_80317270
/* 0D3300 80318300 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0D3304 80318304 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D3308 80318308 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0D330C 8031830C AFB00038 */  sw    $s0, 0x38($sp)
/* 0D3310 80318310 00A08025 */  move  $s0, $a1
/* 0D3314 80318314 00808825 */  move  $s1, $a0
/* 0D3318 80318318 03A0F025 */  move  $fp, $sp
/* 0D331C 8031831C AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D3320 80318320 AFA60078 */  sw    $a2, 0x78($sp)
/* 0D3324 80318324 AFA7007C */  sw    $a3, 0x7c($sp)
/* 0D3328 80318328 14C0000A */  bnez  $a2, .L80318354
/* 0D332C 8031832C 00005025 */   move  $t2, $zero
/* 0D3330 80318330 8FCF007C */  lw    $t7, 0x7c($fp)
/* 0D3334 80318334 3C188022 */  lui   $t8, %hi(D_80226B3C) # $t8, 0x8022
/* 0D3338 80318338 8F18693C */  lw    $t8, %lo(D_80226B3C)($t8)
/* 0D333C 8031833C 91E40000 */  lbu   $a0, ($t7)
/* 0D3340 80318340 3C068022 */  lui   $a2, %hi(D_80226538) # $a2, 0x8022
/* 0D3344 80318344 24C66338 */  addiu $a2, %lo(D_80226538) # addiu $a2, $a2, 0x6338
/* 0D3348 80318348 0098082B */  sltu  $at, $a0, $t8
/* 0D334C 8031834C 14200052 */  bnez  $at, .L80318498
/* 0D3350 80318350 00046100 */   sll   $t4, $a0, 4
.L80318354:
/* 0D3354 80318354 3C048022 */  lui   $a0, %hi(D_80226B3C) # $a0, 0x8022
/* 0D3358 80318358 3C058022 */  lui   $a1, %hi(D_80226B38) # $a1, 0x8022
/* 0D335C 8031835C 8CA56938 */  lw    $a1, %lo(D_80226B38)($a1)
/* 0D3360 80318360 8C84693C */  lw    $a0, %lo(D_80226B3C)($a0)
/* 0D3364 80318364 3C068022 */  lui   $a2, %hi(D_80226538) # $a2, 0x8022
/* 0D3368 80318368 24C66338 */  addiu $a2, %lo(D_80226538) # addiu $a2, $a2, 0x6338
/* 0D336C 8031836C 0085082B */  sltu  $at, $a0, $a1
/* 0D3370 80318370 10200032 */  beqz  $at, .L8031843C
/* 0D3374 80318374 0004C900 */   sll   $t9, $a0, 4
.L80318378:
/* 0D3378 80318378 00D91821 */  addu  $v1, $a2, $t9
/* 0D337C 8031837C 8C6C0004 */  lw    $t4, 4($v1)
/* 0D3380 80318380 00604025 */  move  $t0, $v1
/* 0D3384 80318384 022C1023 */  subu  $v0, $s1, $t4
/* 0D3388 80318388 04420028 */  bltzl $v0, .L8031842C
/* 0D338C 8031838C 24840001 */   addiu $a0, $a0, 1
/* 0D3390 80318390 946D000A */  lhu   $t5, 0xa($v1)
/* 0D3394 80318394 01B07023 */  subu  $t6, $t5, $s0
/* 0D3398 80318398 01C2082B */  sltu  $at, $t6, $v0
/* 0D339C 8031839C 54200023 */  bnezl $at, .L8031842C
/* 0D33A0 803183A0 24840001 */   addiu $a0, $a0, 1
/* 0D33A4 803183A4 906F000E */  lbu   $t7, 0xe($v1)
/* 0D33A8 803183A8 3C098022 */  lui   $t1, %hi(D_80226D49) # $t1, 0x8022
/* 0D33AC 803183AC 25296B49 */  addiu $t1, %lo(D_80226D49) # addiu $t1, $t1, 0x6b49
/* 0D33B0 803183B0 15E00014 */  bnez  $t7, .L80318404
/* 0D33B4 803183B4 3C188022 */   lui   $t8, %hi(D_80226D4B) # $t8, 0x8022
/* 0D33B8 803183B8 91250000 */  lbu   $a1, ($t1)
/* 0D33BC 803183BC 93186B4B */  lbu   $t8, %lo(D_80226D4B)($t8)
/* 0D33C0 803183C0 53050011 */  beql  $t8, $a1, .L80318408
/* 0D33C4 803183C4 240C003C */   li    $t4, 60
/* 0D33C8 803183C8 9067000D */  lbu   $a3, 0xd($v1)
/* 0D33CC 803183CC 3C0B8022 */  lui   $t3, %hi(D_80226C48) # $t3, 0x8022
/* 0D33D0 803183D0 256B6A48 */  addiu $t3, %lo(D_80226C48) # addiu $t3, $t3, 0x6a48
/* 0D33D4 803183D4 10A70009 */  beq   $a1, $a3, .L803183FC
/* 0D33D8 803183D8 01651021 */   addu  $v0, $t3, $a1
/* 0D33DC 803183DC 90590000 */  lbu   $t9, ($v0)
/* 0D33E0 803183E0 01676021 */  addu  $t4, $t3, $a3
/* 0D33E4 803183E4 A1990000 */  sb    $t9, ($t4)
/* 0D33E8 803183E8 904E0000 */  lbu   $t6, ($v0)
/* 0D33EC 803183EC 906D000D */  lbu   $t5, 0xd($v1)
/* 0D33F0 803183F0 000E7900 */  sll   $t7, $t6, 4
/* 0D33F4 803183F4 00CFC021 */  addu  $t8, $a2, $t7
/* 0D33F8 803183F8 A30D000D */  sb    $t5, 0xd($t8)
.L803183FC:
/* 0D33FC 803183FC 24B90001 */  addiu $t9, $a1, 1
/* 0D3400 80318400 A1390000 */  sb    $t9, ($t1)
.L80318404:
/* 0D3404 80318404 240C003C */  li    $t4, 60
.L80318408:
/* 0D3408 80318408 A06C000E */  sb    $t4, 0xe($v1)
/* 0D340C 8031840C 8FCE007C */  lw    $t6, 0x7c($fp)
/* 0D3410 80318410 A1C40000 */  sb    $a0, ($t6)
/* 0D3414 80318414 8C6F0004 */  lw    $t7, 4($v1)
/* 0D3418 80318418 8C780000 */  lw    $t8, ($v1)
/* 0D341C 8031841C 022F6823 */  subu  $t5, $s1, $t7
/* 0D3420 80318420 1000007D */  b     .L80318618
/* 0D3424 80318424 01B81021 */   addu  $v0, $t5, $t8
/* 0D3428 80318428 24840001 */  addiu $a0, $a0, 1
.L8031842C:
/* 0D342C 8031842C 0085082B */  sltu  $at, $a0, $a1
/* 0D3430 80318430 5420FFD1 */  bnezl $at, .L80318378
/* 0D3434 80318434 0004C900 */   sll   $t9, $a0, 4
/* 0D3438 80318438 AFC80068 */  sw    $t0, 0x68($fp)
.L8031843C:
/* 0D343C 8031843C 3C098022 */  lui   $t1, %hi(D_80226D49) # $t1, 0x8022
/* 0D3440 80318440 25296B49 */  addiu $t1, %lo(D_80226D49) # addiu $t1, $t1, 0x6b49
/* 0D3444 80318444 3C198022 */  lui   $t9, %hi(D_80226D4B) # $t9, 0x8022
/* 0D3448 80318448 93396B4B */  lbu   $t9, %lo(D_80226D4B)($t9)
/* 0D344C 8031844C 91250000 */  lbu   $a1, ($t1)
/* 0D3450 80318450 3C068022 */  lui   $a2, %hi(D_80226538) # $a2, 0x8022
/* 0D3454 80318454 24C66338 */  addiu $a2, %lo(D_80226538) # addiu $a2, $a2, 0x6338
/* 0D3458 80318458 13250035 */  beq   $t9, $a1, .L80318530
/* 0D345C 8031845C 8FC80068 */   lw    $t0, 0x68($fp)
/* 0D3460 80318460 8FCC0078 */  lw    $t4, 0x78($fp)
/* 0D3464 80318464 3C0B8022 */  lui   $t3, %hi(D_80226C48) # $t3, 0x8022
/* 0D3468 80318468 256B6A48 */  addiu $t3, %lo(D_80226C48) # addiu $t3, $t3, 0x6a48
/* 0D346C 8031846C 11800030 */  beqz  $t4, .L80318530
/* 0D3470 80318470 01657021 */   addu  $t6, $t3, $a1
/* 0D3474 80318474 91CF0000 */  lbu   $t7, ($t6)
/* 0D3478 80318478 24AD0001 */  addiu $t5, $a1, 1
/* 0D347C 8031847C 240A0001 */  li    $t2, 1
/* 0D3480 80318480 AFCF0058 */  sw    $t7, 0x58($fp)
/* 0D3484 80318484 A12D0000 */  sb    $t5, ($t1)
/* 0D3488 80318488 8FD80058 */  lw    $t8, 0x58($fp)
/* 0D348C 8031848C 0018C900 */  sll   $t9, $t8, 4
/* 0D3490 80318490 10000027 */  b     .L80318530
/* 0D3494 80318494 00D94021 */   addu  $t0, $a2, $t9
.L80318498:
/* 0D3498 80318498 01864021 */  addu  $t0, $t4, $a2
/* 0D349C 8031849C 8D0E0004 */  lw    $t6, 4($t0)
/* 0D34A0 803184A0 022E1823 */  subu  $v1, $s1, $t6
/* 0D34A4 803184A4 04600022 */  bltz  $v1, .L80318530
/* 0D34A8 803184A8 00000000 */   nop   
/* 0D34AC 803184AC 950F000A */  lhu   $t7, 0xa($t0)
/* 0D34B0 803184B0 01F06823 */  subu  $t5, $t7, $s0
/* 0D34B4 803184B4 01A3082B */  sltu  $at, $t5, $v1
/* 0D34B8 803184B8 1420001D */  bnez  $at, .L80318530
/* 0D34BC 803184BC 00000000 */   nop   
/* 0D34C0 803184C0 9118000E */  lbu   $t8, 0xe($t0)
/* 0D34C4 803184C4 3C058022 */  lui   $a1, %hi(D_80226D48) # $a1, 0x8022
/* 0D34C8 803184C8 24A56B48 */  addiu $a1, %lo(D_80226D48) # addiu $a1, $a1, 0x6b48
/* 0D34CC 803184CC 57000014 */  bnezl $t8, .L80318520
/* 0D34D0 803184D0 8D0D0000 */   lw    $t5, ($t0)
/* 0D34D4 803184D4 90A20000 */  lbu   $v0, ($a1)
/* 0D34D8 803184D8 9104000D */  lbu   $a0, 0xd($t0)
/* 0D34DC 803184DC 3C078022 */  lui   $a3, %hi(D_80226B48) # $a3, 0x8022
/* 0D34E0 803184E0 24E76948 */  addiu $a3, %lo(D_80226B48) # addiu $a3, $a3, 0x6948
/* 0D34E4 803184E4 10440009 */  beq   $v0, $a0, .L8031850C
/* 0D34E8 803184E8 00E21821 */   addu  $v1, $a3, $v0
/* 0D34EC 803184EC 90790000 */  lbu   $t9, ($v1)
/* 0D34F0 803184F0 00E46021 */  addu  $t4, $a3, $a0
/* 0D34F4 803184F4 A1990000 */  sb    $t9, ($t4)
/* 0D34F8 803184F8 906F0000 */  lbu   $t7, ($v1)
/* 0D34FC 803184FC 910E000D */  lbu   $t6, 0xd($t0)
/* 0D3500 80318500 000F6900 */  sll   $t5, $t7, 4
/* 0D3504 80318504 00CDC021 */  addu  $t8, $a2, $t5
/* 0D3508 80318508 A30E000D */  sb    $t6, 0xd($t8)
.L8031850C:
/* 0D350C 8031850C 24590001 */  addiu $t9, $v0, 1
/* 0D3510 80318510 A0B90000 */  sb    $t9, ($a1)
/* 0D3514 80318514 8D0C0004 */  lw    $t4, 4($t0)
/* 0D3518 80318518 022C1823 */  subu  $v1, $s1, $t4
/* 0D351C 8031851C 8D0D0000 */  lw    $t5, ($t0)
.L80318520:
/* 0D3520 80318520 240F0002 */  li    $t7, 2
/* 0D3524 80318524 A10F000E */  sb    $t7, 0xe($t0)
/* 0D3528 80318528 1000003B */  b     .L80318618
/* 0D352C 8031852C 006D1021 */   addu  $v0, $v1, $t5
.L80318530:
/* 0D3530 80318530 1540000E */  bnez  $t2, .L8031856C
/* 0D3534 80318534 240D0002 */   li    $t5, 2
/* 0D3538 80318538 3C058022 */  lui   $a1, %hi(D_80226D48) # $a1, 0x8022
/* 0D353C 8031853C 24A56B48 */  addiu $a1, %lo(D_80226D48) # addiu $a1, $a1, 0x6b48
/* 0D3540 80318540 90A20000 */  lbu   $v0, ($a1)
/* 0D3544 80318544 3C078022 */  lui   $a3, %hi(D_80226B48) # $a3, 0x8022
/* 0D3548 80318548 24E76948 */  addiu $a3, %lo(D_80226B48) # addiu $a3, $a3, 0x6948
/* 0D354C 8031854C 00E27021 */  addu  $t6, $a3, $v0
/* 0D3550 80318550 91D80000 */  lbu   $t8, ($t6)
/* 0D3554 80318554 24590001 */  addiu $t9, $v0, 1
/* 0D3558 80318558 AFD80058 */  sw    $t8, 0x58($fp)
/* 0D355C 8031855C A0B90000 */  sb    $t9, ($a1)
/* 0D3560 80318560 8FCC0058 */  lw    $t4, 0x58($fp)
/* 0D3564 80318564 000C7900 */  sll   $t7, $t4, 4
/* 0D3568 80318568 00CF4021 */  addu  $t0, $a2, $t7
.L8031856C:
/* 0D356C 8031856C 9510000A */  lhu   $s0, 0xa($t0)
/* 0D3570 80318570 2401FFF0 */  li    $at, -16
/* 0D3574 80318574 02211024 */  and   $v0, $s1, $at
/* 0D3578 80318578 A10D000E */  sb    $t5, 0xe($t0)
/* 0D357C 8031857C AD020004 */  sw    $v0, 4($t0)
/* 0D3580 80318580 8D040000 */  lw    $a0, ($t0)
/* 0D3584 80318584 A5100008 */  sh    $s0, 8($t0)
/* 0D3588 80318588 AFC80068 */  sw    $t0, 0x68($fp)
/* 0D358C 8031858C AFC20048 */  sw    $v0, 0x48($fp)
/* 0D3590 80318590 0C0C90EC */  jal   osInvalDCache
/* 0D3594 80318594 02002825 */   move  $a1, $s0
/* 0D3598 80318598 3C038022 */  lui   $v1, %hi(D_80226D84) # $v1, 0x8022
/* 0D359C 8031859C 24636B84 */  addiu $v1, %lo(D_80226D84) # addiu $v1, $v1, 0x6b84
/* 0D35A0 803185A0 8C620000 */  lw    $v0, ($v1)
/* 0D35A4 803185A4 8FC80068 */  lw    $t0, 0x68($fp)
/* 0D35A8 803185A8 3C0F8022 */  lui   $t7, %hi(D_80226000) # $t7, 0x8022
/* 0D35AC 803185AC 244E0001 */  addiu $t6, $v0, 1
/* 0D35B0 803185B0 AC6E0000 */  sw    $t6, ($v1)
/* 0D35B4 803185B4 8C780000 */  lw    $t8, ($v1)
/* 0D35B8 803185B8 8D0D0000 */  lw    $t5, ($t0)
/* 0D35BC 803185BC 8FC70048 */  lw    $a3, 0x48($fp)
/* 0D35C0 803185C0 0018C880 */  sll   $t9, $t8, 2
/* 0D35C4 803185C4 0338C821 */  addu  $t9, $t9, $t8
/* 0D35C8 803185C8 0019C880 */  sll   $t9, $t9, 2
/* 0D35CC 803185CC 3C0E8022 */  lui   $t6, %hi(D_80225EE8) # $t6, 0x8022
/* 0D35D0 803185D0 25CE5CE8 */  addiu $t6, %lo(D_80225EE8) # addiu $t6, $t6, 0x5ce8
/* 0D35D4 803185D4 272CFFEC */  addiu $t4, $t9, -0x14
/* 0D35D8 803185D8 25EF5E00 */  addiu $t7, %lo(D_80226000) # addiu $t7, $t7, 0x5e00
/* 0D35DC 803185DC 018F2021 */  addu  $a0, $t4, $t7
/* 0D35E0 803185E0 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0D35E4 803185E4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D35E8 803185E8 00002825 */  move  $a1, $zero
/* 0D35EC 803185EC 00003025 */  move  $a2, $zero
/* 0D35F0 803185F0 0C0C9118 */  jal   osPiStartDma
/* 0D35F4 803185F4 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0D35F8 803185F8 8FD80058 */  lw    $t8, 0x58($fp)
/* 0D35FC 803185FC 8FD9007C */  lw    $t9, 0x7c($fp)
/* 0D3600 80318600 8FC80068 */  lw    $t0, 0x68($fp)
/* 0D3604 80318604 A3380000 */  sb    $t8, ($t9)
/* 0D3608 80318608 8D0C0000 */  lw    $t4, ($t0)
/* 0D360C 8031860C 8FCD0048 */  lw    $t5, 0x48($fp)
/* 0D3610 80318610 01917821 */  addu  $t7, $t4, $s1
/* 0D3614 80318614 01ED1023 */  subu  $v0, $t7, $t5
.L80318618:
/* 0D3618 80318618 8FDF0044 */  lw    $ra, 0x44($fp)
/* 0D361C 8031861C 03C0E825 */  move  $sp, $fp
/* 0D3620 80318620 8FD00038 */  lw    $s0, 0x38($fp)
/* 0D3624 80318624 8FD1003C */  lw    $s1, 0x3c($fp)
/* 0D3628 80318628 8FDE0040 */  lw    $fp, 0x40($fp)
/* 0D362C 8031862C 03E00008 */  jr    $ra
/* 0D3630 80318630 27BD0070 */   addiu $sp, $sp, 0x70
)

#endif

GLOBAL_ASM(
glabel func_8031758C
/* 0D258C 8031758C 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0D2590 80317590 AFB40034 */  sw    $s4, 0x34($sp)
/* 0D2594 80317594 3C148022 */  lui   $s4, %hi(D_80226D70) # $s4, 0x8022
/* 0D2598 80317598 26946D70 */  addiu $s4, %lo(D_80226D70) # addiu $s4, $s4, 0x6d70
/* 0D259C 8031759C AFA40048 */  sw    $a0, 0x48($sp)
/* 0D25A0 803175A0 8E840000 */  lw    $a0, ($s4)
/* 0D25A4 803175A4 AFB2002C */  sw    $s2, 0x2c($sp)
/* 0D25A8 803175A8 24120003 */  li    $s2, 3
/* 0D25AC 803175AC 00920019 */  multu $a0, $s2
/* 0D25B0 803175B0 AFB30030 */  sw    $s3, 0x30($sp)
/* 0D25B4 803175B4 3C138022 */  lui   $s3, %hi(D_80226D68) # $s3, 0x8022
/* 0D25B8 803175B8 26736D68 */  addiu $s3, %lo(D_80226D68) # addiu $s3, $s3, 0x6d68
/* 0D25BC 803175BC AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D25C0 803175C0 AFB00024 */  sw    $s0, 0x24($sp)
/* 0D25C4 803175C4 240E0510 */  li    $t6, 1296
/* 0D25C8 803175C8 03A0F025 */  move  $fp, $sp
/* 0D25CC 803175CC AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D25D0 803175D0 AFB6003C */  sw    $s6, 0x3c($sp)
/* 0D25D4 803175D4 00007812 */  mflo  $t7
/* 0D25D8 803175D8 AFB50038 */  sw    $s5, 0x38($sp)
/* 0D25DC 803175DC AFB10028 */  sw    $s1, 0x28($sp)
/* 0D25E0 803175E0 AE6E0000 */  sw    $t6, ($s3)
/* 0D25E4 803175E4 19E00022 */  blez  $t7, .L80317670
/* 0D25E8 803175E8 00008025 */   move  $s0, $zero
/* 0D25EC 803175EC 3C168022 */  lui   $s6, %hi(D_80226538) # $s6, 0x8022
/* 0D25F0 803175F0 3C158022 */  lui   $s5, %hi(D_802212C8) # $s5, 0x8022
/* 0D25F4 803175F4 3C118022 */  lui   $s1, %hi(D_80226B38) # $s1, 0x8022
/* 0D25F8 803175F8 26316B38 */  addiu $s1, %lo(D_80226B38) # addiu $s1, $s1, 0x6b38
/* 0D25FC 803175FC 26B512C8 */  addiu $s5, %lo(D_802212C8) # addiu $s5, $s5, 0x12c8
/* 0D2600 80317600 26D66538 */  addiu $s6, %lo(D_80226538) # addiu $s6, $s6, 0x6538
/* 0D2604 80317604 01C02825 */  move  $a1, $t6
.L80317608:
/* 0D2608 80317608 0C0C5808 */  jal   soundAlloc
/* 0D260C 8031760C 02A02025 */   move  $a0, $s5
/* 0D2610 80317610 8E260000 */  lw    $a2, ($s1)
/* 0D2614 80317614 0006C100 */  sll   $t8, $a2, 4
/* 0D2618 80317618 02D81821 */  addu  $v1, $s6, $t8
/* 0D261C 8031761C 14400004 */  bnez  $v0, .L80317630
/* 0D2620 80317620 AC620000 */   sw    $v0, ($v1)
/* 0D2624 80317624 00008025 */  move  $s0, $zero
/* 0D2628 80317628 10000018 */  b     .L8031768C
/* 0D262C 8031762C 8E840000 */   lw    $a0, ($s4)
.L80317630:
/* 0D2630 80317630 8E840000 */  lw    $a0, ($s4)
/* 0D2634 80317634 8E650000 */  lw    $a1, ($s3)
/* 0D2638 80317638 26100001 */  addiu $s0, $s0, 1
/* 0D263C 8031763C 00920019 */  multu $a0, $s2
/* 0D2640 80317640 24D90001 */  addiu $t9, $a2, 1
/* 0D2644 80317644 AC600004 */  sw    $zero, 4($v1)
/* 0D2648 80317648 A4600008 */  sh    $zero, 8($v1)
/* 0D264C 8031764C A060000C */  sb    $zero, 0xc($v1)
/* 0D2650 80317650 A060000E */  sb    $zero, 0xe($v1)
/* 0D2654 80317654 AE390000 */  sw    $t9, ($s1)
/* 0D2658 80317658 A465000A */  sh    $a1, 0xa($v1)
/* 0D265C 8031765C 00004012 */  mflo  $t0
/* 0D2660 80317660 0208082A */  slt   $at, $s0, $t0
/* 0D2664 80317664 1420FFE8 */  bnez  $at, .L80317608
/* 0D2668 80317668 00000000 */   nop   
/* 0D266C 8031766C 00008025 */  move  $s0, $zero
.L80317670:
/* 0D2670 80317670 3C118022 */  lui   $s1, %hi(D_80226B38) # $s1, 0x8022
/* 0D2674 80317674 26316B38 */  addiu $s1, %lo(D_80226B38) # addiu $s1, $s1, 0x6b38
/* 0D2678 80317678 3C158022 */  lui   $s5, %hi(D_802212C8) # $s5, 0x8022
/* 0D267C 8031767C 3C168022 */  lui   $s6, %hi(D_80226538) # $s6, 0x8022
/* 0D2680 80317680 26D66538 */  addiu $s6, %lo(D_80226538) # addiu $s6, $s6, 0x6538
/* 0D2684 80317684 26B512C8 */  addiu $s5, %lo(D_802212C8) # addiu $s5, $s5, 0x12c8
/* 0D2688 80317688 8E260000 */  lw    $a2, ($s1)
.L8031768C:
/* 0D268C 8031768C 10C0000D */  beqz  $a2, .L803176C4
/* 0D2690 80317690 00C02825 */   move  $a1, $a2
/* 0D2694 80317694 3C038022 */  lui   $v1, %hi(D_80226B48) # $v1, 0x8022
/* 0D2698 80317698 3C028022 */  lui   $v0, %hi(D_80226538) # $v0, 0x8022
/* 0D269C 8031769C 24426538 */  addiu $v0, %lo(D_80226538) # addiu $v0, $v0, 0x6538
/* 0D26A0 803176A0 24636B48 */  addiu $v1, %lo(D_80226B48) # addiu $v1, $v1, 0x6b48
.L803176A4:
/* 0D26A4 803176A4 A0700000 */  sb    $s0, ($v1)
/* 0D26A8 803176A8 A050000D */  sb    $s0, 0xd($v0)
/* 0D26AC 803176AC 26100001 */  addiu $s0, $s0, 1
/* 0D26B0 803176B0 0206082B */  sltu  $at, $s0, $a2
/* 0D26B4 803176B4 24630001 */  addiu $v1, $v1, 1
/* 0D26B8 803176B8 1420FFFA */  bnez  $at, .L803176A4
/* 0D26BC 803176BC 24420010 */   addiu $v0, $v0, 0x10
/* 0D26C0 803176C0 00008025 */  move  $s0, $zero
.L803176C4:
/* 0D26C4 803176C4 28C10100 */  slti  $at, $a2, 0x100
/* 0D26C8 803176C8 1020000A */  beqz  $at, .L803176F4
/* 0D26CC 803176CC 00C03825 */  or $a3, $a2, $zero
/* 0D26D0 803176D0 3C098022 */  lui   $t1, %hi(D_80226B48) # $t1, 0x8022
/* 0D26D4 803176D4 25296B48 */  addiu $t1, %lo(D_80226B48) # addiu $t1, $t1, 0x6b48
/* 0D26D8 803176D8 3C038022 */  lui   $v1, %hi(D_80226C48) # $v1, 0x8022
/* 0D26DC 803176DC 24636C48 */  addiu $v1, %lo(D_80226C48) # addiu $v1, $v1, 0x6c48
/* 0D26E0 803176E0 00E91021 */  addu  $v0, $a3, $t1
.L803176E4:
/* 0D26E4 803176E4 24420001 */  addiu $v0, $v0, 1
/* 0D26E8 803176E8 0043082B */  sltu  $at, $v0, $v1
/* 0D26EC 803176EC 1420FFFD */  bnez  $at, .L803176E4
/* 0D26F0 803176F0 A040FFFF */   sb    $zero, -1($v0)
.L803176F4:
/* 0D26F4 803176F4 3C018022 */  lui   $at, %hi(D_80226D48) # $at, 0x8022
/* 0D26F8 803176F8 A0206D48 */  sb    $zero, %lo(D_80226D48)($at)
/* 0D26FC 803176FC 3C128022 */  lui   $s2, %hi(D_80226B3C) # $s2, 0x8022
/* 0D2700 80317700 3C018022 */  lui   $at, %hi(D_80226D4A) # $at, 0x8022
/* 0D2704 80317704 26526B3C */  addiu $s2, %lo(D_80226B3C) # addiu $s2, $s2, 0x6b3c
/* 0D2708 80317708 A0266D4A */  sb    $a2, %lo(D_80226D4A)($at)
/* 0D270C 8031770C 240A05A0 */  li    $t2, 1440
/* 0D2710 80317710 AE460000 */  sw    $a2, ($s2)
/* 0D2714 80317714 1880001A */  blez  $a0, .L80317780
/* 0D2718 80317718 AE6A0000 */   sw    $t2, ($s3)
/* 0D271C 8031771C 01402825 */  move  $a1, $t2
.L80317720:
/* 0D2720 80317720 0C0C5808 */  jal   soundAlloc
/* 0D2724 80317724 02A02025 */   move  $a0, $s5
/* 0D2728 80317728 8E260000 */  lw    $a2, ($s1)
/* 0D272C 8031772C 26100001 */  addiu $s0, $s0, 1
/* 0D2730 80317730 00065900 */  sll   $t3, $a2, 4
/* 0D2734 80317734 02CB1821 */  addu  $v1, $s6, $t3
/* 0D2738 80317738 14400003 */  bnez  $v0, .L80317748
/* 0D273C 8031773C AC620000 */   sw    $v0, ($v1)
/* 0D2740 80317740 10000010 */  b     .L80317784
/* 0D2744 80317744 00C03825 */  or $a3, $a2, $zero
.L80317748:
/* 0D2748 80317748 8E8D0000 */  lw    $t5, ($s4)
/* 0D274C 8031774C 8E650000 */  lw    $a1, ($s3)
/* 0D2750 80317750 24CC0001 */  addiu $t4, $a2, 1
/* 0D2754 80317754 020D082A */  slt   $at, $s0, $t5
/* 0D2758 80317758 AC600004 */  sw    $zero, 4($v1)
/* 0D275C 8031775C A4600008 */  sh    $zero, 8($v1)
/* 0D2760 80317760 A060000C */  sb    $zero, 0xc($v1)
/* 0D2764 80317764 A060000E */  sb    $zero, 0xe($v1)
/* 0D2768 80317768 AE2C0000 */  sw    $t4, ($s1)
/* 0D276C 8031776C 1420FFEC */  bnez  $at, .L80317720
/* 0D2770 80317770 A465000A */   sh    $a1, 0xa($v1)
/* 0D2774 80317774 3C068022 */  lui   $a2, %hi(D_80226B38) # $a2, 0x8022
/* 0D2778 80317778 8CC66B38 */  lw    $a2, %lo(D_80226B38)($a2)
/* 0D277C 8031777C 00C02825 */  move  $a1, $a2
.L80317780:
/* 0D2780 80317780 00A03825 */  move  $a3, $a1
.L80317784:
/* 0D2784 80317784 8E450000 */  lw    $a1, ($s2)
/* 0D2788 80317788 03C0E825 */  move  $sp, $fp
/* 0D278C 8031778C 27BD0048 */  addiu $sp, $sp, 0x48
/* 0D2790 80317790 00A6082B */  sltu  $at, $a1, $a2
/* 0D2794 80317794 10200011 */  beqz  $at, .L803177DC
/* 0D2798 80317798 00A08025 */   move  $s0, $a1
/* 0D279C 8031779C 3C0F8022 */  lui   $t7, %hi(D_80226538) # $t7, 0x8022
/* 0D27A0 803177A0 3C188022 */  lui   $t8, %hi(D_80226C48) # $t8, 0x8022
/* 0D27A4 803177A4 27186C48 */  addiu $t8, %lo(D_80226C48) # addiu $t8, $t8, 0x6c48
/* 0D27A8 803177A8 25EF6538 */  addiu $t7, %lo(D_80226538) # addiu $t7, $t7, 0x6538
/* 0D27AC 803177AC 00107100 */  sll   $t6, $s0, 4
/* 0D27B0 803177B0 02051823 */  subu  $v1, $s0, $a1
/* 0D27B4 803177B4 00782021 */  addu  $a0, $v1, $t8
/* 0D27B8 803177B8 01CF1021 */  addu  $v0, $t6, $t7
.L803177BC:
/* 0D27BC 803177BC A0900000 */  sb    $s0, ($a0)
/* 0D27C0 803177C0 26100001 */  addiu $s0, $s0, 1
/* 0D27C4 803177C4 0206082B */  sltu  $at, $s0, $a2
/* 0D27C8 803177C8 A043000D */  sb    $v1, 0xd($v0)
/* 0D27CC 803177CC 24630001 */  addiu $v1, $v1, 1
/* 0D27D0 803177D0 24420010 */  addiu $v0, $v0, 0x10
/* 0D27D4 803177D4 1420FFF9 */  bnez  $at, .L803177BC
/* 0D27D8 803177D8 24840001 */   addiu $a0, $a0, 1
.L803177DC:
/* 0D27DC 803177DC 28E10100 */  slti  $at, $a3, 0x100
/* 0D27E0 803177E0 1020000A */  beqz  $at, .L8031780C
/* 0D27E4 803177E4 00C54023 */   subu  $t0, $a2, $a1
/* 0D27E8 803177E8 3C198022 */  lui   $t9, %hi(D_80226C48) # $t9, 0x8022
/* 0D27EC 803177EC 27396C48 */  addiu $t9, %lo(D_80226C48) # addiu $t9, $t9, 0x6c48
/* 0D27F0 803177F0 3C038022 */  lui   $v1, %hi(D_80226D48) # $v1, 0x8022
/* 0D27F4 803177F4 24636D48 */  addiu $v1, %lo(D_80226D48) # addiu $v1, $v1, 0x6d48
/* 0D27F8 803177F8 00F91021 */  addu  $v0, $a3, $t9
.L803177FC:
/* 0D27FC 803177FC 24420001 */  addiu $v0, $v0, 1
/* 0D2800 80317800 0043082B */  sltu  $at, $v0, $v1
/* 0D2804 80317804 1420FFFD */  bnez  $at, .L803177FC
/* 0D2808 80317808 A045FFFF */   sb    $a1, -1($v0)
.L8031780C:
/* 0D280C 8031780C 3C018022 */  lui   $at, %hi(D_80226D49) # $at, 0x8022
/* 0D2810 80317810 A0206D49 */  sb    $zero, %lo(D_80226D49)($at)
/* 0D2814 80317814 3C018022 */  lui   $at, %hi(D_80226D4B) # $at, 0x8022
/* 0D2818 80317818 A0286D4B */  sb    $t0, %lo(D_80226D4B)($at)
/* 0D281C 8031781C 8FDF0044 */  lw    $ra, 0x44($fp)
/* 0D2820 80317820 8FD6003C */  lw    $s6, 0x3c($fp)
/* 0D2824 80317824 8FD50038 */  lw    $s5, 0x38($fp)
/* 0D2828 80317828 8FD40034 */  lw    $s4, 0x34($fp)
/* 0D282C 8031782C 8FD30030 */  lw    $s3, 0x30($fp)
/* 0D2830 80317830 8FD2002C */  lw    $s2, 0x2c($fp)
/* 0D2834 80317834 8FD10028 */  lw    $s1, 0x28($fp)
/* 0D2838 80317838 8FD00024 */  lw    $s0, 0x24($fp)
/* 0D283C 8031783C 03E00008 */  jr    $ra
/* 0D2840 80317840 8FDE0040 */   lw    $fp, 0x40($fp)
/* 0D2844 80317844 03E00008 */  jr    $ra
/* 0D2848 80317848 00000000 */   nop   
)

#ifdef NON_MATCHING

void func_8031784C(struct Struct_func_8031784C *mem, u8 *offset, u32 arg2, u32 arg3)
{
    // Make pointers into real pointers rather than indices
    struct SubB *subB;
    struct SubB **itSubB;
    u32 i;
    u32 memBase = (u32)mem;
    u32 offsetBase = (u32)offset;

#define INIT_SUB(sub) \
    { \
        struct SubEntry **itSubEntry = &sub; \
        if ((*itSubEntry) != 0) \
        { \
            /* Making these volatile gives correct codegen further down; it makes
             * lw/addiu/sw's happen in source order, and uses two registers...
             * It looks odd, though, so maybe they should not be volatile.
             * It might also be causing the extra register use.
             * Presumably subEntry and subEntry2 ought to have different types,
             * but that doesn't matter for codegen. */ \
            volatile struct SubEntry *subEntry, *subEntry2; \
            *itSubEntry = (void *)(memBase + (u32)(*itSubEntry)); \
            subEntry = *itSubEntry; \
            subEntry2 = *itSubEntry; \
            if (subEntry2->unk1 == 0) \
            { \
                void *a = subEntry2->unk4; \
                void *b = subEntry->unk8; \
                void *c = subEntry->unkC; \
                subEntry->unk4 = (void *) (offsetBase + (u32)a); \
                subEntry->unk8 = (void *) (memBase + (u32)b); \
                subEntry->unkC = (void *) (memBase + (u32)c); \
                subEntry->unk1 = 1; \
            } \
        } \
    }

    if (mem->header != 0)
    {
        if (arg3 != 0)
        {
            mem->header = (struct SubA **)(memBase + (u32)mem->header);
            if (arg3 != 0)
            {
                for (i = 0; i < arg3; i++)
                {
#if 0
                    // This doesn't work: Taking the address to mem->header[i]
                    // does an sll to figure out the lower loop limit.
                    volatile struct SubA *subA, *subA2;
                    struct SubA **h = &mem->header[i];
                    if (*h == 0) continue;
                    {
                        *h = (void *)(memBase + (u32)*h);
                        subA = *h;
                        subA2 = *h;
                        if (subA2->unk2 == 0)
                        {
                            void *d;
                            INIT_SUB(((struct SubA *)subA2)->unk4);
                            d = subA2->unkC;
                            subA->unk2 = 1;
                            subA->unkC = (void *) (memBase + (u32)d);
                        }
                    }
#else
                    // Neither does this: Using mem->header[i] directly
                    // deduplicates it -- subA and subA2 end up in the same
                    // register.
                    struct SubA **header = mem->header;
                    u32 h = (u32)header[i];
                    if (h != 0)
                    {
                        volatile struct SubA *subA, *subA2;
                        header[i] = (struct SubA *)(memBase + h);
                        subA = header[i];
                        subA2 = header[i];
                        if (subA->unk2 == 0)
                        {
                            void *d;
                            INIT_SUB(((struct SubA *)subA)->unk4);
                            d = subA->unkC;
                            subA2->unk2 = 1;
                            subA2->unkC = (void *) (memBase + (u32)d);
                        }
                    }
#endif
                }
            }
        }
    }

    if ((arg2 >= 1) && (arg2 >= 1) != 0)
    {
        itSubB = mem->subB;
        do
        {
            if (*itSubB)
            {
                *itSubB = (void *)(memBase + (u32)*itSubB);
                subB = *itSubB;

                if (subB->unk0 == 0)
                {
                    INIT_SUB(subB->unk8);
                    INIT_SUB(subB->unk10);
                    INIT_SUB(subB->unk18);

                    subB->unk0 = 1;
                    subB->unk4 = (void *) (memBase + (u32)subB->unk4);
                }
            }
            itSubB++;
        }
        while (itSubB != &mem->subB[arg2]);
    }
#undef INIT_SUB
}

#else

GLOBAL_ASM(
glabel func_8031784C
/* 0D284C 8031784C 27ADFFF0 */  addiu $t5, $sp, -0x10
/* 0D2850 80317850 ADA60018 */  sw    $a2, 0x18($t5)
/* 0D2854 80317854 8C820000 */  lw    $v0, ($a0)
/* 0D2858 80317858 01A0E825 */  move  $sp, $t5
/* 0D285C 8031785C 50400030 */  beql  $v0, $zero, .L80317920
/* 0D2860 80317860 8DB80018 */   lw    $t8, 0x18($t5)
/* 0D2864 80317864 10E0002D */  beqz  $a3, .L8031791C
/* 0D2868 80317868 00447021 */   addu  $t6, $v0, $a0
/* 0D286C 8031786C 10E0002B */  beqz  $a3, .L8031791C
/* 0D2870 80317870 AC8E0000 */   sw    $t6, ($a0)
/* 0D2874 80317874 10E00029 */  beqz  $a3, .L8031791C
/* 0D2878 80317878 00001825 */   move  $v1, $zero
/* 0D287C 8031787C 00004025 */  move  $t0, $zero
/* 0D2880 80317880 24020001 */  li    $v0, 1
.L80317884:
/* 0D2884 80317884 8C8F0000 */  lw    $t7, ($a0)
/* 0D2888 80317888 24630001 */  addiu $v1, $v1, 1
/* 0D288C 8031788C 01E84821 */  addu  $t1, $t7, $t0
/* 0D2890 80317890 8D260000 */  lw    $a2, ($t1)
/* 0D2894 80317894 10C0001F */  beqz  $a2, .L80317914
/* 0D2898 80317898 00C43021 */   addu  $a2, $a2, $a0
/* 0D289C 8031789C AD260000 */  sw    $a2, ($t1)
/* 0D28A0 803178A0 90D80002 */  lbu   $t8, 2($a2)
/* 0D28A4 803178A4 00C05025 */  move  $t2, $a2
/* 0D28A8 803178A8 1700001A */  bnez  $t8, .L80317914
/* 0D28AC 803178AC 00000000 */   nop   
/* 0D28B0 803178B0 8CD90004 */  lw    $t9, 4($a2)
/* 0D28B4 803178B4 24C90004 */  addiu $t1, $a2, 4
/* 0D28B8 803178B8 53200013 */  beql  $t9, $zero, .L80317908
/* 0D28BC 803178BC 8CC6000C */   lw    $a2, 0xc($a2)
/* 0D28C0 803178C0 8D2E0000 */  lw    $t6, ($t1)
/* 0D28C4 803178C4 01C45821 */  addu  $t3, $t6, $a0
/* 0D28C8 803178C8 AD2B0000 */  sw    $t3, ($t1)
/* 0D28CC 803178CC 916F0001 */  lbu   $t7, 1($t3)
/* 0D28D0 803178D0 01606025 */  move  $t4, $t3
/* 0D28D4 803178D4 55E0000C */  bnezl $t7, .L80317908
/* 0D28D8 803178D8 8CC6000C */   lw    $a2, 0xc($a2)
/* 0D28DC 803178DC 8D780004 */  lw    $t8, 4($t3)
/* 0D28E0 803178E0 8D990008 */  lw    $t9, 8($t4)
/* 0D28E4 803178E4 8D8E000C */  lw    $t6, 0xc($t4)
/* 0D28E8 803178E8 03055821 */  addu  $t3, $t8, $a1
/* 0D28EC 803178EC AD8B0004 */  sw    $t3, 4($t4)
/* 0D28F0 803178F0 03245821 */  addu  $t3, $t9, $a0
/* 0D28F4 803178F4 AD8B0008 */  sw    $t3, 8($t4)
/* 0D28F8 803178F8 01C45821 */  addu  $t3, $t6, $a0
/* 0D28FC 803178FC AD8B000C */  sw    $t3, 0xc($t4)
/* 0D2900 80317900 A1820001 */  sb    $v0, 1($t4)
/* 0D2904 80317904 8CC6000C */  lw    $a2, 0xc($a2)
.L80317908:
/* 0D2908 80317908 A1420002 */  sb    $v0, 2($t2)
/* 0D290C 8031790C 00867821 */  addu  $t7, $a0, $a2
/* 0D2910 80317910 AD4F000C */  sw    $t7, 0xc($t2)
.L80317914:
/* 0D2914 80317914 1467FFDB */  bne   $v1, $a3, .L80317884
/* 0D2918 80317918 25080004 */   addiu $t0, $t0, 4
.L8031791C:
/* 0D291C 8031791C 8DB80018 */  lw    $t8, 0x18($t5)
.L80317920:
/* 0D2920 80317920 24020001 */  li    $v0, 1
/* 0D2924 80317924 2F190001 */  sltiu $t9, $t8, 1
/* 0D2928 80317928 3B390001 */  xori  $t9, $t9, 1
/* 0D292C 8031792C 13200054 */  beqz  $t9, .L80317A80
/* 0D2930 80317930 00000000 */   nop   
/* 0D2934 80317934 13200052 */  beqz  $t9, .L80317A80
/* 0D2938 80317938 24830004 */   addiu $v1, $a0, 4
/* 0D293C 8031793C 00187080 */  sll   $t6, $t8, 2
/* 0D2940 80317940 01C45021 */  addu  $t2, $t6, $a0
/* 0D2944 80317944 254A0004 */  addiu $t2, $t2, 4
/* 0D2948 80317948 8C660000 */  lw    $a2, ($v1)
.L8031794C:
/* 0D294C 8031794C 10C00049 */  beqz  $a2, .L80317A74
/* 0D2950 80317950 00C47821 */   addu  $t7, $a2, $a0
/* 0D2954 80317954 AC6F0000 */  sw    $t7, ($v1)
/* 0D2958 80317958 91F90000 */  lbu   $t9, ($t7)
/* 0D295C 8031795C 01E03825 */  move  $a3, $t7
/* 0D2960 80317960 57200045 */  bnezl $t9, .L80317A78
/* 0D2964 80317964 24630004 */   addiu $v1, $v1, 4
/* 0D2968 80317968 8DF80008 */  lw    $t8, 8($t7)
/* 0D296C 8031796C 25E60008 */  addiu $a2, $t7, 8
/* 0D2970 80317970 53000013 */  beql  $t8, $zero, .L803179C0
/* 0D2974 80317974 8CEF0010 */   lw    $t7, 0x10($a3)
/* 0D2978 80317978 8CCE0000 */  lw    $t6, ($a2)
/* 0D297C 8031797C 01C44021 */  addu  $t0, $t6, $a0
/* 0D2980 80317980 ACC80000 */  sw    $t0, ($a2)
/* 0D2984 80317984 910F0001 */  lbu   $t7, 1($t0)
/* 0D2988 80317988 01004825 */  move  $t1, $t0
/* 0D298C 8031798C 55E0000C */  bnezl $t7, .L803179C0
/* 0D2990 80317990 8CEF0010 */   lw    $t7, 0x10($a3)
/* 0D2994 80317994 8D190004 */  lw    $t9, 4($t0)
/* 0D2998 80317998 8D380008 */  lw    $t8, 8($t1)
/* 0D299C 8031799C 8D2E000C */  lw    $t6, 0xc($t1)
/* 0D29A0 803179A0 03254021 */  addu  $t0, $t9, $a1
/* 0D29A4 803179A4 AD280004 */  sw    $t0, 4($t1)
/* 0D29A8 803179A8 03044021 */  addu  $t0, $t8, $a0
/* 0D29AC 803179AC AD280008 */  sw    $t0, 8($t1)
/* 0D29B0 803179B0 01C44021 */  addu  $t0, $t6, $a0
/* 0D29B4 803179B4 AD28000C */  sw    $t0, 0xc($t1)
/* 0D29B8 803179B8 A1220001 */  sb    $v0, 1($t1)
/* 0D29BC 803179BC 8CEF0010 */  lw    $t7, 0x10($a3)
.L803179C0:
/* 0D29C0 803179C0 24E60010 */  addiu $a2, $a3, 0x10
/* 0D29C4 803179C4 51E00013 */  beql  $t7, $zero, .L80317A14
/* 0D29C8 803179C8 8CF80018 */   lw    $t8, 0x18($a3)
/* 0D29CC 803179CC 8CD90000 */  lw    $t9, ($a2)
/* 0D29D0 803179D0 03244021 */  addu  $t0, $t9, $a0
/* 0D29D4 803179D4 ACC80000 */  sw    $t0, ($a2)
/* 0D29D8 803179D8 91180001 */  lbu   $t8, 1($t0)
/* 0D29DC 803179DC 01004825 */  move  $t1, $t0
/* 0D29E0 803179E0 5700000C */  bnezl $t8, .L80317A14
/* 0D29E4 803179E4 8CF80018 */   lw    $t8, 0x18($a3)
/* 0D29E8 803179E8 8D0E0004 */  lw    $t6, 4($t0)
/* 0D29EC 803179EC 8D2F0008 */  lw    $t7, 8($t1)
/* 0D29F0 803179F0 8D39000C */  lw    $t9, 0xc($t1)
/* 0D29F4 803179F4 01C54021 */  addu  $t0, $t6, $a1
/* 0D29F8 803179F8 AD280004 */  sw    $t0, 4($t1)
/* 0D29FC 803179FC 01E44021 */  addu  $t0, $t7, $a0
/* 0D2A00 80317A00 AD280008 */  sw    $t0, 8($t1)
/* 0D2A04 80317A04 03244021 */  addu  $t0, $t9, $a0
/* 0D2A08 80317A08 AD28000C */  sw    $t0, 0xc($t1)
/* 0D2A0C 80317A0C A1220001 */  sb    $v0, 1($t1)
/* 0D2A10 80317A10 8CF80018 */  lw    $t8, 0x18($a3)
.L80317A14:
/* 0D2A14 80317A14 24E60018 */  addiu $a2, $a3, 0x18
/* 0D2A18 80317A18 53000013 */  beql  $t8, $zero, .L80317A68
/* 0D2A1C 80317A1C 8CE60004 */   lw    $a2, 4($a3)
/* 0D2A20 80317A20 8CCE0000 */  lw    $t6, ($a2)
/* 0D2A24 80317A24 01C44021 */  addu  $t0, $t6, $a0
/* 0D2A28 80317A28 ACC80000 */  sw    $t0, ($a2)
/* 0D2A2C 80317A2C 910F0001 */  lbu   $t7, 1($t0)
/* 0D2A30 80317A30 01004825 */  move  $t1, $t0
/* 0D2A34 80317A34 55E0000C */  bnezl $t7, .L80317A68
/* 0D2A38 80317A38 8CE60004 */   lw    $a2, 4($a3)
/* 0D2A3C 80317A3C 8D190004 */  lw    $t9, 4($t0)
/* 0D2A40 80317A40 8D380008 */  lw    $t8, 8($t1)
/* 0D2A44 80317A44 8D2E000C */  lw    $t6, 0xc($t1)
/* 0D2A48 80317A48 03254021 */  addu  $t0, $t9, $a1
/* 0D2A4C 80317A4C AD280004 */  sw    $t0, 4($t1)
/* 0D2A50 80317A50 03044021 */  addu  $t0, $t8, $a0
/* 0D2A54 80317A54 AD280008 */  sw    $t0, 8($t1)
/* 0D2A58 80317A58 01C44021 */  addu  $t0, $t6, $a0
/* 0D2A5C 80317A5C AD28000C */  sw    $t0, 0xc($t1)
/* 0D2A60 80317A60 A1220001 */  sb    $v0, 1($t1)
/* 0D2A64 80317A64 8CE60004 */  lw    $a2, 4($a3)
.L80317A68:
/* 0D2A68 80317A68 A0E20000 */  sb    $v0, ($a3)
/* 0D2A6C 80317A6C 00867821 */  addu  $t7, $a0, $a2
/* 0D2A70 80317A70 ACEF0004 */  sw    $t7, 4($a3)
.L80317A74:
/* 0D2A74 80317A74 24630004 */  addiu $v1, $v1, 4
.L80317A78:
/* 0D2A78 80317A78 5543FFB4 */  bnel  $t2, $v1, .L8031794C
/* 0D2A7C 80317A7C 8C660000 */   lw    $a2, ($v1)
.L80317A80:
/* 0D2A80 80317A80 03E00008 */  jr    $ra
/* 0D2A84 80317A84 25BD0010 */   addiu $sp, $t5, 0x10
)

#endif

void *func_80317A88(s32 arg0, s32 arg1)
{
    UNUSED u32 pad1[4];
    u32 buf[4];
    u32 unk1, unk2;
    void *ret;
    u8 *data;
    s32 alloc;

    alloc = D_80226D50->seqArray[arg0].len + 0xf;
    alloc = ALIGN16(alloc);
    alloc -= 0x10;
    data = D_80226D50->seqArray[arg0].offset;
    ret = func_803163DC(&D_802214F8, 1, alloc, arg1, arg0);
    if (ret == 0)
    {
        return 0;
    }

    BlockDmaCopy((u32)data, buf, 0x10);
    unk1 = buf[0];
    unk2 = buf[1];
    BlockDmaCopy((u32)(data + 0x10), ret, alloc);
    func_8031784C(ret, D_80226D54->seqArray[arg0].offset, unk1, unk2);
    D_80226D60[arg0].unk1 = (u8)unk1;
    D_80226D60[arg0].unk2 = (u8)unk2;
    D_80226D60[arg0].unk4 = (void *)((u32)ret + 4);
    D_80226D60[arg0].unk8 = *(u32 *)ret;
    D_802218D0[arg0] = 2;
    return ret;
}

void *func_80317BE4(s32 arg0, s32 arg1, struct Struct_func_80317BE4 *arg2)
{
    u32 unk8, unk9;
    UNUSED u32 pad1[2];
    u32 buf[4];
    UNUSED u32 pad2;
    s32 alloc;
    void *ret;
    u8 *data;
    OSMesgQueue *mesgQueue;

    alloc = D_80226D50->seqArray[arg0].len + 0xf;
    alloc = ALIGN16(alloc);
    alloc -= 0x10;
    data = D_80226D50->seqArray[arg0].offset;
    ret = func_803163DC(D_802214F8, 1, alloc, arg1, arg0);
    if (ret == 0)
    {
        return 0;
    }

    BlockDmaCopy((u32)data, buf, 0x10);
    unk8 = buf[0];
    unk9 = buf[1];
    arg2->unk7 = (u8)arg0;
    arg2->unk8 = (u8)unk8;
    arg2->unk9 = (u8)unk9;
    // Using ioMesg.piHandle as a vAddr... similar to how undefined_syms.txt
    // defines the overlapping symbol "D_80339BEC = gDmaIoMesg + 0x14;"
    // Does OSIoMesg actually have a piHandle member??
    arg2->ioMesg.piHandle = ret;
    arg2->mem = ret;
    arg2->devAddr = (u32)(data + 0x10);
    arg2->size = alloc;
    mesgQueue = &arg2->mesgQueue;
    osCreateMesgQueue(mesgQueue, &arg2->mesg, 1);
    arg2->mesg = NULL;
    arg2->unk0b8 = 1;
    func_803170A0(&arg2->devAddr, (u8**)&arg2->ioMesg.piHandle, &arg2->size, mesgQueue, &arg2->ioMesg);
    D_802218D0[arg0] = 1;
    return ret;
}

void *func_80317D1C(s32 arg0, s32 arg1)
{
    s32 alloc;
    void *ret;
    u8 *data;

    alloc = ALIGN16(D_80226D4C->seqArray[arg0].len + 0xf);
    data = D_80226D4C->seqArray[arg0].offset;
    ret = func_803163DC(D_80221328, 1, alloc, arg1, arg0);
    if (ret == 0)
    {
        return 0;
    }
    BlockDmaCopy((u32)data, ret, alloc);
    D_80221910[arg0] = 2;
    return ret;
}

GLOBAL_ASM(
glabel func_80317DC8
/* 0D2DC8 80317DC8 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0D2DCC 80317DCC 3C0E8022 */  lui   $t6, %hi(D_80226D4C) # $t6, 0x8022
/* 0D2DD0 80317DD0 8DCE6D4C */  lw    $t6, %lo(D_80226D4C)($t6)
/* 0D2DD4 80317DD4 000478C0 */  sll   $t7, $a0, 3
/* 0D2DD8 80317DD8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D2DDC 80317DDC AFBE0038 */  sw    $fp, 0x38($sp)
/* 0D2DE0 80317DE0 AFB20034 */  sw    $s2, 0x34($sp)
/* 0D2DE4 80317DE4 AFB10030 */  sw    $s1, 0x30($sp)
/* 0D2DE8 80317DE8 AFB0002C */  sw    $s0, 0x2c($sp)
/* 0D2DEC 80317DEC 01CF1021 */  addu  $v0, $t6, $t7
/* 0D2DF0 80317DF0 8C500008 */  lw    $s0, 8($v0)
/* 0D2DF4 80317DF4 8C590004 */  lw    $t9, 4($v0)
/* 0D2DF8 80317DF8 00C08825 */  move  $s1, $a2
/* 0D2DFC 80317DFC 00809025 */  move  $s2, $a0
/* 0D2E00 80317E00 2401FFF0 */  li    $at, -16
/* 0D2E04 80317E04 2610001E */  addiu $s0, $s0, 0x1e
/* 0D2E08 80317E08 00A03825 */  move  $a3, $a1
/* 0D2E0C 80317E0C 02013024 */  and   $a2, $s0, $at
/* 0D2E10 80317E10 3C048022 */  lui   $a0, %hi(D_80221328) # $a0, 0x8022
/* 0D2E14 80317E14 03A0F025 */  move  $fp, $sp
/* 0D2E18 80317E18 00C08025 */  move  $s0, $a2
/* 0D2E1C 80317E1C 24841328 */  addiu $a0, %lo(D_80221328) # addiu $a0, $a0, 0x1328
/* 0D2E20 80317E20 24050001 */  li    $a1, 1
/* 0D2E24 80317E24 AFB20010 */  sw    $s2, 0x10($sp)
/* 0D2E28 80317E28 AFB20058 */  sw    $s2, 0x58($sp)
/* 0D2E2C 80317E2C 0C0C58F7 */  jal   func_803163DC
/* 0D2E30 80317E30 AFB9004C */   sw    $t9, 0x4c($sp)
/* 0D2E34 80317E34 14400003 */  bnez  $v0, .L80317E44
/* 0D2E38 80317E38 00409025 */   move  $s2, $v0
/* 0D2E3C 80317E3C 10000029 */  b     .L80317EE4
/* 0D2E40 80317E40 00001025 */   move  $v0, $zero
.L80317E44:
/* 0D2E44 80317E44 2A010041 */  slti  $at, $s0, 0x41
/* 0D2E48 80317E48 1020000B */  beqz  $at, .L80317E78
/* 0D2E4C 80317E4C 02402825 */   move  $a1, $s2
/* 0D2E50 80317E50 8FC4004C */  lw    $a0, 0x4c($fp)
/* 0D2E54 80317E54 02402825 */  move  $a1, $s2
/* 0D2E58 80317E58 0C0C5BEC */  jal   BlockDmaCopy
/* 0D2E5C 80317E5C 02003025 */   move  $a2, $s0
/* 0D2E60 80317E60 8FC90058 */  lw    $t1, 0x58($fp)
/* 0D2E64 80317E64 3C018022 */  lui   $at, %hi(D_80221910)
/* 0D2E68 80317E68 24080002 */  li    $t0, 2
/* 0D2E6C 80317E6C 00290821 */  addu  $at, $at, $t1
/* 0D2E70 80317E70 1000001B */  b     .L80317EE0
/* 0D2E74 80317E74 A0281910 */   sb    $t0, %lo(D_80221910)($at)
.L80317E78:
/* 0D2E78 80317E78 8FC4004C */  lw    $a0, 0x4c($fp)
/* 0D2E7C 80317E7C 0C0C5BEC */  jal   BlockDmaCopy
/* 0D2E80 80317E80 24060040 */   li    $a2, 64
/* 0D2E84 80317E84 262700D0 */  addiu $a3, $s1, 0xd0
/* 0D2E88 80317E88 00E02025 */  move  $a0, $a3
/* 0D2E8C 80317E8C AFC70044 */  sw    $a3, 0x44($fp)
/* 0D2E90 80317E90 262500E8 */  addiu $a1, $s1, 0xe8
/* 0D2E94 80317E94 0C0C859C */  jal   osCreateMesgQueue
/* 0D2E98 80317E98 24060001 */   li    $a2, 1
/* 0D2E9C 80317E9C 922B0000 */  lbu   $t3, ($s1)
/* 0D2EA0 80317EA0 8FC70044 */  lw    $a3, 0x44($fp)
/* 0D2EA4 80317EA4 AE2000E8 */  sw    $zero, 0xe8($s1)
/* 0D2EA8 80317EA8 356C0010 */  ori   $t4, $t3, 0x10
/* 0D2EAC 80317EAC A22C0000 */  sb    $t4, ($s1)
/* 0D2EB0 80317EB0 8FC4004C */  lw    $a0, 0x4c($fp)
/* 0D2EB4 80317EB4 262D00EC */  addiu $t5, $s1, 0xec
/* 0D2EB8 80317EB8 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0D2EBC 80317EBC 26450040 */  addiu $a1, $s2, 0x40
/* 0D2EC0 80317EC0 2606FFC0 */  addiu $a2, $s0, -0x40
/* 0D2EC4 80317EC4 0C0C5C0D */  jal   func_80317034
/* 0D2EC8 80317EC8 24840040 */   addiu $a0, $a0, 0x40
/* 0D2ECC 80317ECC 8FCF0058 */  lw    $t7, 0x58($fp)
/* 0D2ED0 80317ED0 3C018022 */  lui   $at, %hi(D_80221910)
/* 0D2ED4 80317ED4 240E0001 */  li    $t6, 1
/* 0D2ED8 80317ED8 002F0821 */  addu  $at, $at, $t7
/* 0D2EDC 80317EDC A02E1910 */  sb    $t6, %lo(D_80221910)($at)
.L80317EE0:
/* 0D2EE0 80317EE0 02401025 */  move  $v0, $s2
.L80317EE4:
/* 0D2EE4 80317EE4 8FDF003C */  lw    $ra, 0x3c($fp)
/* 0D2EE8 80317EE8 03C0E825 */  move  $sp, $fp
/* 0D2EEC 80317EEC 8FD0002C */  lw    $s0, 0x2c($fp)
/* 0D2EF0 80317EF0 8FD10030 */  lw    $s1, 0x30($fp)
/* 0D2EF4 80317EF4 8FD20034 */  lw    $s2, 0x34($fp)
/* 0D2EF8 80317EF8 8FDE0038 */  lw    $fp, 0x38($fp)
/* 0D2EFC 80317EFC 03E00008 */  jr    $ra
/* 0D2F00 80317F00 27BD0058 */   addiu $sp, $sp, 0x58
)

u8 func_80317F04(s32 arg0, s32 *arg1, s32 *arg2)
{
    void *temp;
    u32 v0;
    u16 offset;
    u8 i;
    u8 ret;

    *arg2 = 0;
    *arg1 = 0;
    offset = ((u16 *)D_80226D58)[arg0] + 1;
    for (i = D_80226D58[offset - 1], ret = 0; i; i--)
    {
        offset++;
        v0 = D_80226D58[offset - 1];

        if ((D_802218D0[v0] >= 2) == 1)
        {
            temp = func_8031680C(D_802214F8, 2, D_80226D58[offset - 1]);
        }
        else
        {
            temp = 0;
        }

        if (temp == 0)
        {
            (*arg2)++;
            ret = v0;
        }
        else
        {
            (*arg1)++;
        }
    }

    return ret;
}

void *func_8031804C(s32 arg0, u8 *arg1)
{
    void *ret;
    u32 v0;
    u16 offset;
    u8 i;

    offset = ((u16 *)D_80226D58)[arg0] + 1;
    for (i = D_80226D58[offset - 1]; i; i--)
    {
        offset++;
        v0 = D_80226D58[offset - 1];

        if ((D_802218D0[v0] >= 2) == 1)
        {
            ret = func_8031680C(D_802214F8, 2, D_80226D58[offset - 1]);
        }
        else
        {
            ret = 0;
        }

        if (!ret)
        {
            ret = func_80317A88(v0, 2);
        }
    }
    *arg1 = v0;
    return ret;
}

void func_80318178(u32 arg0, u8 arg1)
{
    void *cond;
    u8 temp;

    if (arg0 >= D_80226D5C)
    {
        return;
    }

    D_80333EF4 = 0x19710515;
    if (arg1 & 2)
    {
        func_8031804C(arg0, &temp);
    }

    if (arg1 & 1)
    {
        if ((D_802218D0[arg0] >= 2) == 1)
        {
            cond = func_8031680C(D_80221328, 2, arg0);
        }
        else
        {
            cond = 0;
        }

        if (!cond && func_80317D1C(arg0, 2) == 0)
        {
            D_80333EF4 = 0x76557364;
            return;
        }
    }

    D_80333EF4 = 0x76557364;
}

void func_80318280(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg2 == 0)
    {
        D_80333EF4 = 0x19710515;
    }
    func_803182E0(arg0, arg1, arg2);
    if (arg2 == 0)
    {
        D_80333EF4 = 0x76557364;
    }
}

GLOBAL_ASM(
glabel func_803182E0
/* 0D32E0 803182E0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0D32E4 803182E4 3C0F8022 */  lui   $t7, %hi(D_80226D5C) # $t7, 0x8022
/* 0D32E8 803182E8 95EF6D5C */  lhu   $t7, %lo(D_80226D5C)($t7)
/* 0D32EC 803182EC AFBE0028 */  sw    $fp, 0x28($sp)
/* 0D32F0 803182F0 03A0F025 */  move  $fp, $sp
/* 0D32F4 803182F4 00AF082B */  sltu  $at, $a1, $t7
/* 0D32F8 803182F8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D32FC 803182FC AFB00024 */  sw    $s0, 0x24($sp)
/* 0D3300 80318300 AFA40050 */  sw    $a0, 0x50($sp)
/* 0D3304 80318304 AFA50054 */  sw    $a1, 0x54($sp)
/* 0D3308 80318308 10200050 */  beqz  $at, .L8031844C
/* 0D330C 8031830C AFA60058 */   sw    $a2, 0x58($sp)
/* 0D3310 80318310 0004C880 */  sll   $t9, $a0, 2
/* 0D3314 80318314 0324C821 */  addu  $t9, $t9, $a0
/* 0D3318 80318318 3C088022 */  lui   $t0, %hi(D_80222A18) # $t0, 0x8022
/* 0D331C 8031831C 25082A18 */  addiu $t0, %lo(D_80222A18) # addiu $t0, $t0, 0x2a18
/* 0D3320 80318320 0019C980 */  sll   $t9, $t9, 6
/* 0D3324 80318324 03288021 */  addu  $s0, $t9, $t0
/* 0D3328 80318328 0C0C6B89 */  jal   func_8031AE24
/* 0D332C 8031832C 02002025 */   move  $a0, $s0
/* 0D3330 80318330 8FC90058 */  lw    $t1, 0x58($fp)
/* 0D3334 80318334 27C6003C */  addiu $a2, $fp, 0x3c
/* 0D3338 80318338 26050006 */  addiu $a1, $s0, 6
/* 0D333C 8031833C 11200019 */  beqz  $t1, .L803183A4
/* 0D3340 80318340 00000000 */   nop   
/* 0D3344 80318344 AFC0003C */  sw    $zero, 0x3c($fp)
/* 0D3348 80318348 AFC00038 */  sw    $zero, 0x38($fp)
/* 0D334C 8031834C 8FC40054 */  lw    $a0, 0x54($fp)
/* 0D3350 80318350 0C0C5FC1 */  jal   func_80317F04
/* 0D3354 80318354 27C50038 */   addiu $a1, $fp, 0x38
/* 0D3358 80318358 8FCA003C */  lw    $t2, 0x3c($fp)
/* 0D335C 8031835C 24010001 */  li    $at, 1
/* 0D3360 80318360 00402025 */  move  $a0, $v0
/* 0D3364 80318364 15410009 */  bne   $t2, $at, .L8031838C
/* 0D3368 80318368 26050006 */   addiu $a1, $s0, 6
/* 0D336C 8031836C 24050002 */  li    $a1, 2
/* 0D3370 80318370 02003025 */  move  $a2, $s0
/* 0D3374 80318374 0C0C5EF9 */  jal   func_80317BE4
/* 0D3378 80318378 AFC20034 */   sw    $v0, 0x34($fp)
/* 0D337C 8031837C 10400033 */  beqz  $v0, .L8031844C
/* 0D3380 80318380 8FC40034 */   lw    $a0, 0x34($fp)
/* 0D3384 80318384 1000000B */  b     .L803183B4
/* 0D3388 80318388 A2040006 */   sb    $a0, 6($s0)
.L8031838C:
/* 0D338C 8031838C 0C0C6013 */  jal   func_8031804C
/* 0D3390 80318390 8FC40054 */   lw    $a0, 0x54($fp)
/* 0D3394 80318394 54400008 */  bnezl $v0, .L803183B8
/* 0D3398 80318398 8FC60054 */   lw    $a2, 0x54($fp)
/* 0D339C 8031839C 1000002C */  b     .L80318450
/* 0D33A0 803183A0 8FDF002C */   lw    $ra, 0x2c($fp)
.L803183A4:
/* 0D33A4 803183A4 0C0C6013 */  jal   func_8031804C
/* 0D33A8 803183A8 8FC40054 */   lw    $a0, 0x54($fp)
/* 0D33AC 803183AC 50400028 */  beql  $v0, $zero, .L80318450
/* 0D33B0 803183B0 8FDF002C */   lw    $ra, 0x2c($fp)
.L803183B4:
/* 0D33B4 803183B4 8FC60054 */  lw    $a2, 0x54($fp)
.L803183B8:
/* 0D33B8 803183B8 3C048022 */  lui   $a0, %hi(D_80221328) # $a0, 0x8022
/* 0D33BC 803183BC 24841328 */  addiu $a0, %lo(D_80221328) # addiu $a0, $a0, 0x1328
/* 0D33C0 803183C0 24050002 */  li    $a1, 2
/* 0D33C4 803183C4 0C0C5A03 */  jal   func_8031680C
/* 0D33C8 803183C8 A2060005 */   sb    $a2, 5($s0)
/* 0D33CC 803183CC 14400014 */  bnez  $v0, .L80318420
/* 0D33D0 803183D0 00401825 */   move  $v1, $v0
/* 0D33D4 803183D4 8E0B0000 */  lw    $t3, ($s0)
/* 0D33D8 803183D8 000B68C0 */  sll   $t5, $t3, 3
/* 0D33DC 803183DC 05A2001C */  bltzl $t5, .L80318450
/* 0D33E0 803183E0 8FDF002C */   lw    $ra, 0x2c($fp)
/* 0D33E4 803183E4 8FCE0058 */  lw    $t6, 0x58($fp)
/* 0D33E8 803183E8 02003025 */  move  $a2, $s0
/* 0D33EC 803183EC 24050002 */  li    $a1, 2
/* 0D33F0 803183F0 11C00006 */  beqz  $t6, .L8031840C
/* 0D33F4 803183F4 00000000 */   nop   
/* 0D33F8 803183F8 8FC40054 */  lw    $a0, 0x54($fp)
/* 0D33FC 803183FC 0C0C5F72 */  jal   func_80317DC8
/* 0D3400 80318400 24050002 */   li    $a1, 2
/* 0D3404 80318404 10000004 */  b     .L80318418
/* 0D3408 80318408 00401825 */   move  $v1, $v0
.L8031840C:
/* 0D340C 8031840C 0C0C5F47 */  jal   func_80317D1C
/* 0D3410 80318410 8FC40054 */   lw    $a0, 0x54($fp)
/* 0D3414 80318414 00401825 */  move  $v1, $v0
.L80318418:
/* 0D3418 80318418 5040000D */  beql  $v0, $zero, .L80318450
/* 0D341C 8031841C 8FDF002C */   lw    $ra, 0x2c($fp)
.L80318420:
/* 0D3420 80318420 8FC40050 */  lw    $a0, 0x50($fp)
/* 0D3424 80318424 0C0C750B */  jal   func_8031D42C
/* 0D3428 80318428 AFC3004C */   sw    $v1, 0x4c($fp)
/* 0D342C 8031842C 8FC3004C */  lw    $v1, 0x4c($fp)
/* 0D3430 80318430 92180000 */  lbu   $t8, ($s0)
/* 0D3434 80318434 A2000084 */  sb    $zero, 0x84($s0)
/* 0D3438 80318438 A6000012 */  sh    $zero, 0x12($s0)
/* 0D343C 8031843C 37190080 */  ori   $t9, $t8, 0x80
/* 0D3440 80318440 A2190000 */  sb    $t9, ($s0)
/* 0D3444 80318444 AE030014 */  sw    $v1, 0x14($s0)
/* 0D3448 80318448 AE03006C */  sw    $v1, 0x6c($s0)
.L8031844C:
/* 0D344C 8031844C 8FDF002C */  lw    $ra, 0x2c($fp)
.L80318450:
/* 0D3450 80318450 03C0E825 */  move  $sp, $fp
/* 0D3454 80318454 8FD00024 */  lw    $s0, 0x24($fp)
/* 0D3458 80318458 8FDE0028 */  lw    $fp, 0x28($fp)
/* 0D345C 8031845C 03E00008 */  jr    $ra
/* 0D3460 80318460 27BD0050 */   addiu $sp, $sp, 0x50
)

#ifdef NON_MATCHING

void InitAudioSystem(void)
{
    u8 buf[10]; // 0x68
    s16 len;
    u32 alloc;
    s32 i;
    s32 j;
    u64 *ptr64;
    s32 lim;
    s32 lim2;
    s32 i2;
    void *data;
    ALSeqFile **bufptr;

    D_80333EF4 = 0;

    // unrolled with default compiler options
    lim = D_80333EE8;
    for (i = 0; i < lim; i++)
    {
        D_80226E58[i] = 0;
        D_80226E98[i] = 0;
    }

    lim2 = D_80333EEC / 8;
    for (i = 0; i <= lim2 - 1; i++)
    {
        D_801CE000[i] = 0;
    }

    i2 = ((u32)D_80226EC0 - (u32)D_802211A0) >> 3;
    ptr64 = D_802211A0;
    while (i2 >= 0)
    {
        i2--;
        ptr64++;
        *ptr64 = 0;
    }

    for (i = 0; i < 3; i++)
    {
        D_80226E4C[i] = 0x00a0;
    }

    D_80226D80 = 0;
    D_80226D88 = 0;
    D_80226D8C = 0;
    D_80226D7F = 0;
    D_80226D9C = 0;
    D_80226DA0[0].unk34 = 0;
    D_80226DA0[1].unk34 = 0;
    osCreateMesgQueue(&D_80226500, D_80226518, 1);
    osCreateMesgQueue(&D_80225EE8, D_80225F00, ARRAY_COUNT(D_80225F00));
    D_80226D84 = 0;
    D_80226B38 = 0;

    func_80316108(D_80333EF0);

    for (i = 0; i < 3; i++)
    {
        D_80226E40[i] = soundAlloc(D_802212B8, 0xa00);

        // unrolled with default compiler options
        for (j = 0; j < 0x500; j++)
        {
            D_80226E40[i][j] = 0;
        }
    }

    func_80316928(D_80332190);

    bufptr = &D_80226D4C;
    *bufptr = (ALSeqFile*)buf;
    data = gMusicData;
    BlockDmaCopy((u32)data, *bufptr, 0x10);
    len = (*bufptr)->seqCount;
    alloc = ALIGN16((D_80226D5C = len) * sizeof(ALSeqData) + 4);
    D_80226D4C = soundAlloc(D_802212B8, alloc);
    BlockDmaCopy((u32)data, D_80226D4C, alloc);
    alSeqFileNew(*bufptr, data);

    bufptr = &D_80226D50;
    *bufptr = (ALSeqFile*)buf;
    data = gSoundDataADSR;
    BlockDmaCopy((u32)data, *bufptr, 0x10);
    len = (*bufptr)->seqCount;
    alloc = ALIGN16(len * sizeof(ALSeqData) + 4);
    D_80226D60 = soundAlloc(D_802212B8, len * sizeof(struct Struct_80226D60));
    D_80226D50 = soundAlloc(D_802212B8, alloc);
    BlockDmaCopy((u32)data, D_80226D50, alloc);
    alSeqFileNew(*bufptr, data);

    bufptr = &D_80226D54;
    *bufptr = (ALSeqFile*)buf;
    BlockDmaCopy((u32)data, *bufptr, 0x10);
    len = (*bufptr)->seqCount;
    alloc = ALIGN16(len * sizeof(ALSeqData) + 4);
    D_80226D54 = soundAlloc(D_802212B8, alloc);
    BlockDmaCopy((u32)gSoundDataRaw, D_80226D54, alloc);
    alSeqFileNew(*bufptr, gSoundDataRaw);

    D_80226D58 = soundAlloc(D_802212B8, 0x100);
    BlockDmaCopy((u32)gInstrumentSets, D_80226D58, 0x100);

    func_8031D4B8();
    D_80333EF4 = 0x76557364;
}

#else

GLOBAL_ASM(
glabel InitAudioSystem
/* 0D3464 80318464 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0D3468 80318468 3C0E8033 */  lui   $t6, %hi(D_80333EF4) # $t6, 0x8033
/* 0D346C 8031846C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D3470 80318470 AFBE0028 */  sw    $fp, 0x28($sp)
/* 0D3474 80318474 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D3478 80318478 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D347C 8031847C 25CE3EF4 */  addiu $t6, %lo(D_80333EF4) # addiu $t6, $t6, 0x3ef4
/* 0D3480 80318480 ADC00000 */  sw    $zero, ($t6)
/* 0D3484 80318484 3C058033 */  lui   $a1, %hi(D_80333EE8) # $a1, 0x8033
/* 0D3488 80318488 80A53EE8 */  lb    $a1, %lo(D_80333EE8)($a1)
/* 0D348C 8031848C 03A0F025 */  move  $fp, $sp
/* 0D3490 80318490 00002025 */  move  $a0, $zero
/* 0D3494 80318494 18A0000B */  blez  $a1, .L803184C4
/* 0D3498 80318498 3C198022 */   lui   $t9, %hi(D_80226EC0) # $t9, 0x8022
/* 0D349C 8031849C 3C028022 */  lui   $v0, %hi(D_80226E58) # $v0, 0x8022
/* 0D34A0 803184A0 3C038022 */  lui   $v1, %hi(D_80226E98) # $v1, 0x8022
/* 0D34A4 803184A4 24636E98 */  addiu $v1, %lo(D_80226E98) # addiu $v1, $v1, 0x6e98
/* 0D34A8 803184A8 24426E58 */  addiu $v0, %lo(D_80226E58) # addiu $v0, $v0, 0x6e58
.L803184AC:
/* 0D34AC 803184AC 24840001 */  addiu $a0, $a0, 1
/* 0D34B0 803184B0 24420004 */  addiu $v0, $v0, 4
/* 0D34B4 803184B4 24630002 */  addiu $v1, $v1, 2
/* 0D34B8 803184B8 AC40FFFC */  sw    $zero, -4($v0)
/* 0D34BC 803184BC 1485FFFB */  bne   $a0, $a1, .L803184AC
/* 0D34C0 803184C0 A460FFFE */   sh    $zero, -2($v1)
.L803184C4:
/* 0D34C4 803184C4 3C028033 */  lui   $v0, %hi(D_80333EEC) # $v0, 0x8033
/* 0D34C8 803184C8 8C423EEC */  lw    $v0, %lo(D_80333EEC)($v0)
/* 0D34CC 803184CC 3C0A8022 */  lui   $t2, %hi(D_802211A0) # $t2, 0x8022
/* 0D34D0 803184D0 254A11A0 */  addiu $t2, %lo(D_802211A0) # addiu $t2, $t2, 0x11a0
/* 0D34D4 803184D4 04410003 */  bgez  $v0, .L803184E4
/* 0D34D8 803184D8 000220C3 */   sra   $a0, $v0, 3
/* 0D34DC 803184DC 24410007 */  addiu $at, $v0, 7
/* 0D34E0 803184E0 000120C3 */  sra   $a0, $at, 3
.L803184E4:
/* 0D34E4 803184E4 2484FFFF */  addiu $a0, $a0, -1
/* 0D34E8 803184E8 0480000C */  bltz  $a0, .L8031851C
/* 0D34EC 803184EC 27396EC0 */   addiu $t9, %lo(D_80226EC0) # addiu $t9, $t9, 0x6ec0
/* 0D34F0 803184F0 3C0F801D */  lui   $t7, %hi(D_801CE000)
/* 0D34F4 803184F4 25E2E000 */  addiu $v0, $t7, %lo(D_801CE000)
/* 0D34F8 803184F8 0004C0C0 */  sll   $t8, $a0, 3
/* 0D34FC 803184FC 03021821 */  addu  $v1, $t8, $v0
.L80318500:
/* 0D3500 80318500 24420008 */  addiu $v0, $v0, 8
/* 0D3504 80318504 0062082B */  sltu  $at, $v1, $v0
/* 0D3508 80318508 24080000 */  li    $t0, 0
/* 0D350C 8031850C 24090000 */  li    $t1, 0
/* 0D3510 80318510 AC49FFFC */  sw    $t1, -4($v0)
/* 0D3514 80318514 1020FFFA */  beqz  $at, .L80318500
/* 0D3518 80318518 AC48FFF8 */   sw    $t0, -8($v0)
.L8031851C:
/* 0D351C 8031851C 032A1823 */  subu  $v1, $t9, $t2
/* 0D3520 80318520 000310C2 */  srl   $v0, $v1, 3
/* 0D3524 80318524 0440000A */  bltz  $v0, .L80318550
/* 0D3528 80318528 3C048022 */   lui   $a0, %hi(D_80226E52) # $a0, 0x8022
/* 0D352C 8031852C 3C038022 */  lui   $v1, %hi(D_802211A0 - 8) # $v1, 0x8022
/* 0D3530 80318530 24631198 */  addiu $v1, %lo(D_802211A0 - 8) # addiu $v1, $v1, 0x1198
.L80318534:
/* 0D3534 80318534 2442FFFF */  addiu $v0, $v0, -1
/* 0D3538 80318538 240C0000 */  li    $t4, 0
/* 0D353C 8031853C 240D0000 */  li    $t5, 0
/* 0D3540 80318540 24630008 */  addiu $v1, $v1, 8
/* 0D3544 80318544 AC6D0004 */  sw    $t5, 4($v1)
/* 0D3548 80318548 0441FFFA */  bgez  $v0, .L80318534
/* 0D354C 8031854C AC6C0000 */   sw    $t4, ($v1)
.L80318550:
/* 0D3550 80318550 3C028022 */  lui   $v0, %hi(D_80226E4C) # $v0, 0x8022
/* 0D3554 80318554 24426E4C */  addiu $v0, %lo(D_80226E4C) # addiu $v0, $v0, 0x6e4c
/* 0D3558 80318558 24846E52 */  addiu $a0, %lo(D_80226E52) # addiu $a0, $a0, 0x6e52
/* 0D355C 8031855C 240300A0 */  li    $v1, 160
.L80318560:
/* 0D3560 80318560 24420002 */  addiu $v0, $v0, 2
/* 0D3564 80318564 0044082B */  sltu  $at, $v0, $a0
/* 0D3568 80318568 1420FFFD */  bnez  $at, .L80318560
/* 0D356C 8031856C A443FFFE */   sh    $v1, -2($v0)
/* 0D3570 80318570 3C0E8022 */  lui   $t6, %hi(D_80226D80) # $t6, 0x8022
/* 0D3574 80318574 25CE6D80 */  addiu $t6, %lo(D_80226D80) # addiu $t6, $t6, 0x6d80
/* 0D3578 80318578 ADC00000 */  sw    $zero, ($t6)
/* 0D357C 8031857C 3C018022 */  lui   $at, %hi(D_80226D88) # $at, 0x8022
/* 0D3580 80318580 AC206D88 */  sw    $zero, %lo(D_80226D88)($at)
/* 0D3584 80318584 3C018022 */  lui   $at, %hi(D_80226D8C) # $at, 0x8022
/* 0D3588 80318588 AC206D8C */  sw    $zero, %lo(D_80226D8C)($at)
/* 0D358C 8031858C 3C018022 */  lui   $at, %hi(D_80226D7F) # $at, 0x8022
/* 0D3590 80318590 A0206D7F */  sb    $zero, %lo(D_80226D7F)($at)
/* 0D3594 80318594 3C028022 */  lui   $v0, %hi(D_80226DA0) # $v0, 0x8022
/* 0D3598 80318598 3C018022 */  lui   $at, %hi(D_80226D9C) # $at, 0x8022
/* 0D359C 8031859C 24426DA0 */  addiu $v0, %lo(D_80226DA0) # addiu $v0, $v0, 0x6da0
/* 0D35A0 803185A0 AC206D9C */  sw    $zero, %lo(D_80226D9C)($at)
/* 0D35A4 803185A4 3C048022 */  lui   $a0, %hi(D_80226500) # $a0, 0x8022
/* 0D35A8 803185A8 3C058022 */  lui   $a1, %hi(D_80226518) # $a1, 0x8022
/* 0D35AC 803185AC AC400034 */  sw    $zero, 0x34($v0)
/* 0D35B0 803185B0 AC400084 */  sw    $zero, 0x84($v0)
/* 0D35B4 803185B4 24A56518 */  addiu $a1, %lo(D_80226518) # addiu $a1, $a1, 0x6518
/* 0D35B8 803185B8 24846500 */  addiu $a0, %lo(D_80226500) # addiu $a0, $a0, 0x6500
/* 0D35BC 803185BC 0C0C859C */  jal   osCreateMesgQueue
/* 0D35C0 803185C0 24060001 */   li    $a2, 1
/* 0D35C4 803185C4 3C048022 */  lui   $a0, %hi(D_80225EE8) # $a0, 0x8022
/* 0D35C8 803185C8 3C058022 */  lui   $a1, %hi(D_80225F00) # $a1, 0x8022
/* 0D35CC 803185CC 24A55F00 */  addiu $a1, %lo(D_80225F00) # addiu $a1, $a1, 0x5f00
/* 0D35D0 803185D0 24845EE8 */  addiu $a0, %lo(D_80225EE8) # addiu $a0, $a0, 0x5ee8
/* 0D35D4 803185D4 0C0C859C */  jal   osCreateMesgQueue
/* 0D35D8 803185D8 24060040 */   li    $a2, 64
/* 0D35DC 803185DC 3C188022 */  lui   $t8, %hi(D_80226D84) # $t8, 0x8022
/* 0D35E0 803185E0 27186D84 */  addiu $t8, %lo(D_80226D84) # addiu $t8, $t8, 0x6d84
/* 0D35E4 803185E4 AF000000 */  sw    $zero, ($t8)
/* 0D35E8 803185E8 3C018022 */  lui   $at, %hi(D_80226B38) # $at, 0x8022
/* 0D35EC 803185EC 3C048033 */  lui   $a0, %hi(D_80333EF0) # $a0, 0x8033
/* 0D35F0 803185F0 AC206B38 */  sw    $zero, %lo(D_80226B38)($at)
/* 0D35F4 803185F4 0C0C5842 */  jal   func_80316108
/* 0D35F8 803185F8 8C843EF0 */   lw    $a0, %lo(D_80333EF0)($a0)
/* 0D35FC 803185FC 3C068022 */  lui   $a2, %hi(D_80226E40) # $a2, 0x8022
/* 0D3600 80318600 3C118022 */  lui   $s1, %hi(D_802212B8) # $s1, 0x8022
/* 0D3604 80318604 263112B8 */  addiu $s1, %lo(D_802212B8) # addiu $s1, $s1, 0x12b8
/* 0D3608 80318608 24C66E40 */  addiu $a2, %lo(D_80226E40) # addiu $a2, $a2, 0x6e40
/* 0D360C 8031860C 24100A00 */  li    $s0, 2560
/* 0D3610 80318610 02202025 */  move  $a0, $s1
.L80318614:
/* 0D3614 80318614 24050A00 */  li    $a1, 2560
/* 0D3618 80318618 0C0C5808 */  jal   soundAlloc
/* 0D361C 8031861C AFC6003C */   sw    $a2, 0x3c($fp)
/* 0D3620 80318620 8FC6003C */  lw    $a2, 0x3c($fp)
/* 0D3624 80318624 3C098022 */  lui   $t1, %hi(D_80226E4C) # $t1, 0x8022
/* 0D3628 80318628 00001825 */  move  $v1, $zero
/* 0D362C 8031862C ACC20000 */  sw    $v0, ($a2)
.L80318630:
/* 0D3630 80318630 8CCF0000 */  lw    $t7, ($a2)
/* 0D3634 80318634 01E34021 */  addu  $t0, $t7, $v1
/* 0D3638 80318638 24630002 */  addiu $v1, $v1, 2
/* 0D363C 8031863C 1470FFFC */  bne   $v1, $s0, .L80318630
/* 0D3640 80318640 A5000000 */   sh    $zero, ($t0)
/* 0D3644 80318644 24C60004 */  addiu $a2, $a2, 4
/* 0D3648 80318648 25296E4C */  addiu $t1, %lo(D_80226E4C) # addiu $t1, $t1, 0x6e4c
/* 0D364C 8031864C 54C9FFF1 */  bnel  $a2, $t1, .L80318614
/* 0D3650 80318650 02202025 */   move  $a0, $s1
/* 0D3654 80318654 3C048033 */  lui   $a0, %hi(D_80332190) # $a0, 0x8033
/* 0D3658 80318658 0C0C5A4A */  jal   func_80316928
/* 0D365C 8031865C 24842190 */   addiu $a0, %lo(D_80332190) # addiu $a0, $a0, 0x2190
/* 0D3660 80318660 3C028022 */  lui   $v0, %hi(D_80226D4C) # $v0, 0x8022
/* 0D3664 80318664 24426D4C */  addiu $v0, %lo(D_80226D4C) # addiu $v0, $v0, 0x6d4c
/* 0D3668 80318668 27C50068 */  addiu $a1, $fp, 0x68
/* 0D366C 8031866C 3C040074 */  lui   $a0, %hi(gMusicData) # $a0, 0x74
/* 0D3670 80318670 AC450000 */  sw    $a1, ($v0)
/* 0D3674 80318674 24845F80 */  addiu $a0, %lo(gMusicData) # addiu $a0, $a0, 0x5f80
/* 0D3678 80318678 0C0C5BEC */  jal   BlockDmaCopy
/* 0D367C 8031867C 24060010 */   li    $a2, 16
/* 0D3680 80318680 3C0A8022 */  lui   $t2, %hi(D_80226D4C) # $t2, 0x8022
/* 0D3684 80318684 8D4A6D4C */  lw    $t2, %lo(D_80226D4C)($t2)
/* 0D3688 80318688 3C028022 */  lui   $v0, %hi(D_80226D5C) # $v0, 0x8022
/* 0D368C 8031868C 2401FFF0 */  li    $at, -16
/* 0D3690 80318690 854B0002 */  lh    $t3, 2($t2)
/* 0D3694 80318694 24426D5C */  addiu $v0, %lo(D_80226D5C) # addiu $v0, $v0, 0x6d5c
/* 0D3698 80318698 02202025 */  move  $a0, $s1
/* 0D369C 8031869C 3170FFFF */  andi  $s0, $t3, 0xffff
/* 0D36A0 803186A0 001060C0 */  sll   $t4, $s0, 3
/* 0D36A4 803186A4 25900013 */  addiu $s0, $t4, 0x13
/* 0D36A8 803186A8 02012824 */  and   $a1, $s0, $at
/* 0D36AC 803186AC 00A08025 */  move  $s0, $a1
/* 0D36B0 803186B0 0C0C5808 */  jal   soundAlloc
/* 0D36B4 803186B4 A44B0000 */   sh    $t3, ($v0)
/* 0D36B8 803186B8 3C038022 */  lui   $v1, %hi(D_80226D4C) # $v1, 0x8022
/* 0D36BC 803186BC 24636D4C */  addiu $v1, %lo(D_80226D4C) # addiu $v1, $v1, 0x6d4c
/* 0D36C0 803186C0 3C040074 */  lui   $a0, %hi(gMusicData) # $a0, 0x74
/* 0D36C4 803186C4 AC620000 */  sw    $v0, ($v1)
/* 0D36C8 803186C8 24845F80 */  addiu $a0, %lo(gMusicData) # addiu $a0, $a0, 0x5f80
/* 0D36CC 803186CC 00402825 */  move  $a1, $v0
/* 0D36D0 803186D0 0C0C5BEC */  jal   BlockDmaCopy
/* 0D36D4 803186D4 02003025 */   move  $a2, $s0
/* 0D36D8 803186D8 3C048022 */  lui   $a0, %hi(D_80226D4C) # $a0, 0x8022
/* 0D36DC 803186DC 3C050074 */  lui   $a1, %hi(gMusicData) # $a1, 0x74
/* 0D36E0 803186E0 24A55F80 */  addiu $a1, %lo(gMusicData) # addiu $a1, $a1, 0x5f80
/* 0D36E4 803186E4 0C0C936A */  jal   alSeqFileNew
/* 0D36E8 803186E8 8C846D4C */   lw    $a0, %lo(D_80226D4C)($a0)
/* 0D36EC 803186EC 3C028022 */  lui   $v0, %hi(D_80226D50) # $v0, 0x8022
/* 0D36F0 803186F0 24426D50 */  addiu $v0, %lo(D_80226D50) # addiu $v0, $v0, 0x6d50
/* 0D36F4 803186F4 27C50068 */  addiu $a1, $fp, 0x68
/* 0D36F8 803186F8 3C040058 */  lui   $a0, %hi(gSoundDataADSR) # $a0, 0x58
/* 0D36FC 803186FC AC450000 */  sw    $a1, ($v0)
/* 0D3700 80318700 24849140 */  addiu $a0, %lo(gSoundDataADSR) # addiu $a0, $a0, -0x6ec0
/* 0D3704 80318704 0C0C5BEC */  jal   BlockDmaCopy
/* 0D3708 80318708 24060010 */   li    $a2, 16
/* 0D370C 8031870C 3C188022 */  lui   $t8, %hi(D_80226D50) # $t8, 0x8022
/* 0D3710 80318710 8F186D50 */  lw    $t8, %lo(D_80226D50)($t8)
/* 0D3714 80318714 2401FFF0 */  li    $at, -16
/* 0D3718 80318718 02202025 */  move  $a0, $s1
/* 0D371C 8031871C 87020002 */  lh    $v0, 2($t8)
/* 0D3720 80318720 000280C0 */  sll   $s0, $v0, 3
/* 0D3724 80318724 26100013 */  addiu $s0, $s0, 0x13
/* 0D3728 80318728 00022880 */  sll   $a1, $v0, 2
/* 0D372C 8031872C 02017824 */  and   $t7, $s0, $at
/* 0D3730 80318730 00A22823 */  subu  $a1, $a1, $v0
/* 0D3734 80318734 01E08025 */  move  $s0, $t7
/* 0D3738 80318738 0C0C5808 */  jal   soundAlloc
/* 0D373C 8031873C 00052880 */   sll   $a1, $a1, 2
/* 0D3740 80318740 3C018022 */  lui   $at, %hi(D_80226D60) # $at, 0x8022
/* 0D3744 80318744 AC226D60 */  sw    $v0, %lo(D_80226D60)($at)
/* 0D3748 80318748 02202025 */  move  $a0, $s1
/* 0D374C 8031874C 0C0C5808 */  jal   soundAlloc
/* 0D3750 80318750 02002825 */   move  $a1, $s0
/* 0D3754 80318754 3C038022 */  lui   $v1, %hi(D_80226D50) # $v1, 0x8022
/* 0D3758 80318758 24636D50 */  addiu $v1, %lo(D_80226D50) # addiu $v1, $v1, 0x6d50
/* 0D375C 8031875C 3C040058 */  lui   $a0, %hi(gSoundDataADSR) # $a0, 0x58
/* 0D3760 80318760 AC620000 */  sw    $v0, ($v1)
/* 0D3764 80318764 24849140 */  addiu $a0, %lo(gSoundDataADSR) # addiu $a0, $a0, -0x6ec0
/* 0D3768 80318768 00402825 */  move  $a1, $v0
/* 0D376C 8031876C 0C0C5BEC */  jal   BlockDmaCopy
/* 0D3770 80318770 02003025 */   move  $a2, $s0
/* 0D3774 80318774 3C048022 */  lui   $a0, %hi(D_80226D50) # $a0, 0x8022
/* 0D3778 80318778 3C050058 */  lui   $a1, %hi(gSoundDataADSR) # $a1, 0x58
/* 0D377C 8031877C 24A59140 */  addiu $a1, %lo(gSoundDataADSR) # addiu $a1, $a1, -0x6ec0
/* 0D3780 80318780 0C0C936A */  jal   alSeqFileNew
/* 0D3784 80318784 8C846D50 */   lw    $a0, %lo(D_80226D50)($a0)
/* 0D3788 80318788 3C028022 */  lui   $v0, %hi(D_80226D54) # $v0, 0x8022
/* 0D378C 8031878C 24426D54 */  addiu $v0, %lo(D_80226D54) # addiu $v0, $v0, 0x6d54
/* 0D3790 80318790 27C50068 */  addiu $a1, $fp, 0x68
/* 0D3794 80318794 3C040058 */  lui   $a0, %hi(gSoundDataADSR) # $a0, 0x58
/* 0D3798 80318798 AC450000 */  sw    $a1, ($v0)
/* 0D379C 8031879C 24849140 */  addiu $a0, %lo(gSoundDataADSR) # addiu $a0, $a0, -0x6ec0
/* 0D37A0 803187A0 0C0C5BEC */  jal   BlockDmaCopy
/* 0D37A4 803187A4 24060010 */   li    $a2, 16
/* 0D37A8 803187A8 3C098022 */  lui   $t1, %hi(D_80226D54) # $t1, 0x8022
/* 0D37AC 803187AC 8D296D54 */  lw    $t1, %lo(D_80226D54)($t1)
/* 0D37B0 803187B0 2401FFF0 */  li    $at, -16
/* 0D37B4 803187B4 02202025 */  move  $a0, $s1
/* 0D37B8 803187B8 85300002 */  lh    $s0, 2($t1)
/* 0D37BC 803187BC 0010C8C0 */  sll   $t9, $s0, 3
/* 0D37C0 803187C0 03208025 */  move  $s0, $t9
/* 0D37C4 803187C4 26100013 */  addiu $s0, $s0, 0x13
/* 0D37C8 803187C8 02012824 */  and   $a1, $s0, $at
/* 0D37CC 803187CC 0C0C5808 */  jal   soundAlloc
/* 0D37D0 803187D0 00A08025 */   move  $s0, $a1
/* 0D37D4 803187D4 3C038022 */  lui   $v1, %hi(D_80226D54) # $v1, 0x8022
/* 0D37D8 803187D8 24636D54 */  addiu $v1, %lo(D_80226D54) # addiu $v1, $v1, 0x6d54
/* 0D37DC 803187DC 3C040059 */  lui   $a0, %hi(gSoundDataRaw) # $a0, 0x59
/* 0D37E0 803187E0 AC620000 */  sw    $v0, ($v1)
/* 0D37E4 803187E4 24840200 */  addiu $a0, %lo(gSoundDataRaw) # addiu $a0, $a0, 0x200
/* 0D37E8 803187E8 00402825 */  move  $a1, $v0
/* 0D37EC 803187EC 0C0C5BEC */  jal   BlockDmaCopy
/* 0D37F0 803187F0 02003025 */   move  $a2, $s0
/* 0D37F4 803187F4 3C048022 */  lui   $a0, %hi(D_80226D54) # $a0, 0x8022
/* 0D37F8 803187F8 3C050059 */  lui   $a1, %hi(gSoundDataRaw) # $a1, 0x59
/* 0D37FC 803187FC 24A50200 */  addiu $a1, %lo(gSoundDataRaw) # addiu $a1, $a1, 0x200
/* 0D3800 80318800 0C0C936A */  jal   alSeqFileNew
/* 0D3804 80318804 8C846D54 */   lw    $a0, %lo(D_80226D54)($a0)
/* 0D3808 80318808 02202025 */  move  $a0, $s1
/* 0D380C 8031880C 0C0C5808 */  jal   soundAlloc
/* 0D3810 80318810 24050100 */   li    $a1, 256
/* 0D3814 80318814 3C038022 */  lui   $v1, %hi(D_80226D58) # $v1, 0x8022
/* 0D3818 80318818 24636D58 */  addiu $v1, %lo(D_80226D58) # addiu $v1, $v1, 0x6d58
/* 0D381C 8031881C 3C040076 */  lui   $a0, %hi(gInstrumentSets) # $a0, 0x76
/* 0D3820 80318820 AC620000 */  sw    $v0, ($v1)
/* 0D3824 80318824 24841B40 */  addiu $a0, %lo(gInstrumentSets) # addiu $a0, $a0, 0x1b40
/* 0D3828 80318828 00402825 */  move  $a1, $v0
/* 0D382C 8031882C 0C0C5BEC */  jal   BlockDmaCopy
/* 0D3830 80318830 24060100 */   li    $a2, 256
/* 0D3834 80318834 0C0C752E */  jal   func_8031D4B8
/* 0D3838 80318838 00000000 */   nop   
/* 0D383C 8031883C 3C0B7655 */  lui   $t3, (0x76557364 >> 16) # lui $t3, 0x7655
/* 0D3840 80318840 3C0C8033 */  lui   $t4, %hi(D_80333EF4) # $t4, 0x8033
/* 0D3844 80318844 258C3EF4 */  addiu $t4, %lo(D_80333EF4) # addiu $t4, $t4, 0x3ef4
/* 0D3848 80318848 356B7364 */  ori   $t3, (0x76557364 & 0xFFFF) # ori $t3, $t3, 0x7364
/* 0D384C 8031884C AD8B0000 */  sw    $t3, ($t4)
/* 0D3850 80318850 8FDF002C */  lw    $ra, 0x2c($fp)
/* 0D3854 80318854 8FD10024 */  lw    $s1, 0x24($fp)
/* 0D3858 80318858 8FD00020 */  lw    $s0, 0x20($fp)
/* 0D385C 8031885C 03C0E825 */  move  $sp, $fp
/* 0D3860 80318860 8FDE0028 */  lw    $fp, 0x28($fp)
/* 0D3864 80318864 03E00008 */  jr    $ra
/* 0D3868 80318868 27BD0098 */   addiu $sp, $sp, 0x98
)

#endif
