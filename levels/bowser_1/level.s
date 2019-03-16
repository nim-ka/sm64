# generated by n64split
.section .rodata
.include "macros.inc"
.include "ultra64/gbi.inc"
.include "special_presets.inc"

bowser_1_seg7_texture_07000000: # 0x07000000 - 0x07000002
.incbin "levels/bowser_1/0.rgba16"

bowser_1_seg7_texture_07001000: # 0x07001000 - 0x07001002
.incbin "levels/bowser_1/1.rgba16"

bowser_1_seg7_texture_07001800: # 0x07001800 - 0x07001802
.incbin "levels/bowser_1/2.rgba16"

bowser_1_seg7_light_07002000: # 0x07002000 - 0x07002008
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

bowser_1_seg7_light_07002008: # 0x07002008 - 0x07002018
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

bowser_1_seg7_vertex_07002018: # 0x07002018 - 0x07002108
vertex  -1535,    307,      0,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,      0,   1502,  -2712,  0x00, 0x7F, 0x00, 0xFF
vertex  -1085,    307,  -1085,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex   1086,    307,  -1085,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,  -1535,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex  -1085,    307,   1086,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex  -1535,    307,      0,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex   1086,    307,  -1085,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex   1536,    307,      0,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,  -1535,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex  -1085,    307,  -1085,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex   1086,    307,   1086,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,   1536,      0,    990,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,   1536,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex  -1085,    307,   1086,      0,    990,  0x00, 0x7F, 0x00, 0xFF

bowser_1_seg7_vertex_07002108: # 0x07002108 - 0x07002138
vertex   1536,    307,      0,   3034,    990,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,      0,   1502,  -2712,  0x00, 0x7F, 0x00, 0xFF
vertex   1086,    307,   1086,      0,    990,  0x00, 0x7F, 0x00, 0xFF

bowser_1_seg7_vertex_07002138: # 0x07002138 - 0x07002228
vertex   1086,    307,  -1085,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex   2172,    307,  -2171,      0,    990,  0x3E, 0x49, 0xAE, 0xFF
vertex      0,    307,  -3071,   4056,    990,  0xF5, 0x5C, 0xAB, 0xFF
vertex  -3071,    307,      0,   4056,    990,  0xB8, 0x68, 0x09, 0xFF
vertex  -1535,    307,      0,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -1085,    307,  -1085,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -2171,    307,  -2171,      0,    990,  0xBB, 0x5C, 0xCC, 0xFF
vertex  -3071,    307,      0,      0,    990,  0xB8, 0x68, 0x09, 0xFF
vertex  -1085,    307,   1086,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -1535,    307,      0,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -2171,    307,   2172,   4056,    990,  0xCC, 0x5C, 0x45, 0xFF
vertex      0,    307,  -1535,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -2171,    307,  -2171,   4056,    990,  0xBB, 0x5C, 0xCC, 0xFF
vertex  -1085,    307,  -1085,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,  -3071,      0,    990,  0xF5, 0x5C, 0xAB, 0xFF

bowser_1_seg7_vertex_07002228: # 0x07002228 - 0x07002318
vertex   2172,    307,   2172,      0,    990,  0x45, 0x5C, 0x34, 0xFF
vertex   3072,    307,      0,   4056,    990,  0x55, 0x5C, 0xF5, 0xFF
vertex   1536,    307,      0,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex   1086,    307,  -1085,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,  -3071,   4056,    990,  0xF5, 0x5C, 0xAB, 0xFF
vertex      0,    307,  -1535,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -2171,    307,   2172,      0,    990,  0xCC, 0x5C, 0x45, 0xFF
vertex      0,    307,   3072,   4056,    990,  0x0B, 0x5C, 0x55, 0xFF
vertex      0,    307,   1536,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex  -1085,    307,   1086,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,   3072,      0,    990,  0x0B, 0x5C, 0x55, 0xFF
vertex   1086,    307,   1086,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex      0,    307,   1536,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex   2172,    307,   2172,   4056,    990,  0x45, 0x5C, 0x34, 0xFF
vertex   1086,    307,   1086,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF

bowser_1_seg7_vertex_07002318: # 0x07002318 - 0x07002358
vertex   3072,    307,      0,      0,    990,  0x55, 0x5C, 0xF5, 0xFF
vertex   1086,    307,  -1085,   3034,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex   1536,    307,      0,    990,  -1478,  0x00, 0x7F, 0x00, 0xFF
vertex   2172,    307,  -2171,   4056,    990,  0x3E, 0x49, 0xAE, 0xFF

bowser_1_seg7_vertex_07002358: # 0x07002358 - 0x07002448
vertex      0,  -2047,   3072,    990,   1996,  0xEF, 0x00, 0x7D, 0xFF
vertex      0,    307,   3072,    990,     -4,  0x0B, 0x5C, 0x55, 0xFF
vertex  -2171,    307,   2172,      0,     -8,  0xCC, 0x5C, 0x45, 0xFF
vertex   2172,  -2047,  -2171,    990,   1984,  0x65, 0x00, 0xB4, 0xFF
vertex   3072,    307,      0,      0,    -12,  0x55, 0x5C, 0xF5, 0xFF
vertex   3072,  -2047,      0,      0,   1988,  0x7D, 0x00, 0x11, 0xFF
vertex   2172,    307,  -2171,    990,    -16,  0x3E, 0x49, 0xAE, 0xFF
vertex   3072,  -2047,      0,    990,   1984,  0x7D, 0x00, 0x11, 0xFF
vertex   2172,    307,   2172,      0,    -20,  0x45, 0x5C, 0x34, 0xFF
vertex   2172,  -2047,   2172,      0,   1980,  0x4C, 0x00, 0x65, 0xFF
vertex   3072,    307,      0,    990,    -16,  0x55, 0x5C, 0xF5, 0xFF
vertex   2172,  -2047,   2172,    990,   1988,  0x4C, 0x00, 0x65, 0xFF
vertex      0,    307,   3072,      0,    -16,  0x0B, 0x5C, 0x55, 0xFF
vertex      0,  -2047,   3072,      0,   1984,  0xEF, 0x00, 0x7D, 0xFF
vertex   2172,    307,   2172,    990,    -16,  0x45, 0x5C, 0x34, 0xFF

bowser_1_seg7_vertex_07002448: # 0x07002448 - 0x07002538
vertex  -2171,  -2047,   2172,    990,   1992,  0x9B, 0x00, 0x4C, 0xFF
vertex  -2171,    307,   2172,    990,    -12,  0xCC, 0x5C, 0x45, 0xFF
vertex  -3071,    307,      0,      0,    -16,  0xB8, 0x68, 0x09, 0xFF
vertex      0,  -2047,   3072,    990,   1996,  0xEF, 0x00, 0x7D, 0xFF
vertex  -2171,    307,   2172,      0,     -8,  0xCC, 0x5C, 0x45, 0xFF
vertex  -2171,  -2047,   2172,      0,   1992,  0x9B, 0x00, 0x4C, 0xFF
vertex      0,  -2047,  -3071,    990,   1992,  0x11, 0x00, 0x83, 0xFF
vertex      0,    307,  -3071,    990,    -16,  0xF5, 0x5C, 0xAB, 0xFF
vertex   2172,    307,  -2171,      0,    -20,  0x3E, 0x49, 0xAE, 0xFF
vertex   2172,  -2047,  -2171,      0,   1988,  0x65, 0x00, 0xB4, 0xFF
vertex  -2171,  -2047,  -2171,    990,   1996,  0xB4, 0x00, 0x9B, 0xFF
vertex  -2171,    307,  -2171,    990,    -12,  0xBB, 0x5C, 0xCC, 0xFF
vertex      0,    307,  -3071,      0,    -16,  0xF5, 0x5C, 0xAB, 0xFF
vertex      0,  -2047,  -3071,      0,   1996,  0x11, 0x00, 0x83, 0xFF
vertex  -3071,  -2047,      0,      0,   1988,  0x83, 0x00, 0xEF, 0xFF

bowser_1_seg7_vertex_07002538: # 0x07002538 - 0x07002578
vertex  -3071,  -2047,      0,    990,   1996,  0x83, 0x00, 0xEF, 0xFF
vertex  -2171,    307,  -2171,      0,    -16,  0xBB, 0x5C, 0xCC, 0xFF
vertex  -2171,  -2047,  -2171,      0,   1988,  0xB4, 0x00, 0x9B, 0xFF
vertex  -3071,    307,      0,    990,     -8,  0xB8, 0x68, 0x09, 0xFF

bowser_1_seg7_dl_07002578: # 0x07002578 - 0x070025F8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, bowser_1_seg7_texture_07001800
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight bowser_1_seg7_light_07002008, 1
gsSPLight bowser_1_seg7_light_07002000, 2
gsSPVertex bowser_1_seg7_vertex_07002018, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  5,  1,  6, 0x0
gsSP1Triangle  7,  1,  8, 0x0
gsSP1Triangle  1,  9, 10, 0x0
gsSP1Triangle 11,  1, 12, 0x0
gsSP1Triangle 13,  1, 14, 0x0
gsSPVertex bowser_1_seg7_vertex_07002108, 3, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSPEndDisplayList

bowser_1_seg7_dl_070025F8: # 0x070025F8 - 0x070026B0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, bowser_1_seg7_texture_07001000
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex bowser_1_seg7_vertex_07002138, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  5,  6, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7, 10,  8, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 14, 12, 0x0
gsSPVertex bowser_1_seg7_vertex_07002228, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 10, 13, 11, 0x0
gsSP1Triangle  0,  2, 14, 0x0
gsSPVertex bowser_1_seg7_vertex_07002318, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSPEndDisplayList

bowser_1_seg7_dl_070026B0: # 0x070026B0 - 0x07002768
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, bowser_1_seg7_texture_07000000
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSPVertex bowser_1_seg7_vertex_07002358, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  6,  4, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7, 10,  8, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 14, 12, 0x0
gsSPVertex bowser_1_seg7_vertex_07002448, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 10, 12, 13, 0x0
gsSP1Triangle  0,  2, 14, 0x0
gsSPVertex bowser_1_seg7_vertex_07002538, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSPEndDisplayList

glabel bowser_1_seg7_dl_07002768 # 0x07002768 - 0x07002838
gsDPPipeSync
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, 0x00100000
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0xC8112078
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, 0x00000000
gsDPSetFogColor 10, 30, 20, 255
gsSPFogFactor 0x10AA, 0xF056 # This isn't gsSPFogPosition since there is no valid min/max pair that corresponds to 0x10AAF056
gsSPSetGeometryMode G_FOG
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_COMBINED, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_COMBINED
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList bowser_1_seg7_dl_07002578
gsSPDisplayList bowser_1_seg7_dl_070025F8
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 252
gsSPDisplayList bowser_1_seg7_dl_070026B0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsSPSetOtherMode G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, 0x00000000
gsSPSetOtherMode G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00442078
gsSPClearGeometryMode G_FOG
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

glabel bowser_1_seg7_collision_level # 0x07002838 - 0x07002AC8
# collision vertices
.hword 0x0040, 0x001D
.hword  2172,   307, -2171
.hword     0,   307, -3071
.hword  1086,   307, -1085
.hword -2171,   307, -2171
.hword     0,   307, -1535
.hword -2171,   307,  2172
.hword     0, -2047,  3072
.hword     0,   307,  3072
.hword -3071, -2047,     0
.hword -3071,   307,     0
.hword -2171, -2047,  2172
.hword -1535,   307,     0
.hword -1085,   307, -1085
.hword -1085,   307,  1086
.hword -2171, -2047, -2171
.hword     0,   307,  1536
.hword  3072,   307,     0
.hword     0, -2047, -3071
.hword  2172, -2047,  2172
.hword  3072, -2047,     0
.hword  2172,   307,  2172
.hword  2172, -2047, -2171
.hword  1536,   307,     0
.hword  1086,   307,  1086
.hword     0,   307,     0
.hword  7168, -6143, -7167
.hword -7167, -6143, -7167
.hword -7167, -6143,  7168
.hword  7168, -6143,  7168
# collision 0x00 normal
.hword 0x0000,   40
.hword    5,    6,    7
.hword    0,    1,    2
.hword    1,    3,    4
.hword    5,    7,   15
.hword    8,    9,    3
.hword   10,    9,    8
.hword   10,    5,    9
.hword    9,   11,   12
.hword    9,   13,   11
.hword    9,    5,   13
.hword    9,   12,    3
.hword    4,    3,   12
.hword    8,    3,   14
.hword   14,    3,    1
.hword    6,    5,   10
.hword    5,   15,   13
.hword    7,   20,   23
.hword    2,    1,    4
.hword   16,    0,    2
.hword   16,    2,   22
.hword   14,    1,   17
.hword   17,    1,    0
.hword   18,   20,    7
.hword   18,    7,    6
.hword    7,   23,   15
.hword   17,    0,   21
.hword   19,   20,   18
.hword   19,   16,   20
.hword   20,   22,   23
.hword   20,   16,   22
.hword   21,   16,   19
.hword   21,    0,   16
.hword   11,   24,   12
.hword   13,   24,   11
.hword    2,   24,   22
.hword   24,    2,    4
.hword   23,   24,   15
.hword   24,    4,   12
.hword   15,   24,   13
.hword   22,   24,   23
# collision 0x0A deathfloor
.hword 0x000A,    2
.hword   25,   26,   27
.hword   25,   27,   28
.hword 0x0041
# special objects 0x43
.hword 0x0043,   22 # add 22 special objects
special_object_10_byte /*preset*/ special_null_start,   /*pos*/     0, 1843,     0, /*yaw*/ 1423 # unused, probably an early way to set intial position
special_object_8_byte  /*preset*/ special_mine,         /*pos*/  2949,  589,     0
special_object_8_byte  /*preset*/ special_mine,         /*pos*/     0,  589, -2949
special_object_8_byte  /*preset*/ special_mine,         /*pos*/     0,  589,  2949
special_object_8_byte  /*preset*/ special_mine,         /*pos*/ -2949,  589,     0
special_object_8_byte  /*preset*/ special_bowser,       /*pos*/     0,  300, -1000
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/     0,  384,  3072, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -2171,  384, -2171, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/     0,  384, -3071, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -3071,  384,     0, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -2171,  384,  2172, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -2621,  384,  1086, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  2172,  384,  2172, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  3072,  384,     0, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  2172,  384, -2171, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -1085,  384,  2622, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  2622,  384,  1086, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -2621,  384, -1085, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/ -1085,  384, -2621, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  1086,  384, -2621, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  2622,  384, -1085, /*yaw*/    0
special_object_10_byte /*preset*/ special_level_geo_03, /*pos*/  1086,  384,  2622, /*yaw*/    0
.hword 0x0042

