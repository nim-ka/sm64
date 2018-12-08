# Lakitu (Cameraman)

.balign 8
lakitu_seg6_texture_06000000: # 0x06000000
.incbin "actors/lakitu_cameraman/0.rgba16"

lakitu_seg6_texture_06000800: # 0x06000800
.incbin "actors/lakitu_cameraman/1.rgba16"

lakitu_seg6_texture_06001800: # 0x06001800
.incbin "actors/lakitu_cameraman/2.rgba16"

lakitu_seg6_texture_06002800: # 0x06002800
.incbin "actors/lakitu_cameraman/3.rgba16"

lakitu_seg6_texture_06003000: # 0x06003000
.incbin "actors/lakitu_cameraman/4.rgba16"

lakitu_seg6_texture_06003800: # 0x06003800
.incbin "actors/lakitu_cameraman/5.rgba16"

lakitu_seg6_light_06003A00: # 0x06003A00
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

lakitu_seg6_light_06003A08: # 0x06003A08
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_06003A18: # 0x06003A18
.byte 0x79, 0x55, 0x00, 0x00, 0x79, 0x55, 0x00, 0x00

lakitu_seg6_light_06003A20: # 0x06003A20
.byte 0xF2, 0xAB, 0x00, 0x00, 0xF2, 0xAB, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_06003A30: # 0x06003A30
vertex     91,    -25,     86,    240,    464,  0x3E, 0xD0, 0x63, 0xFF
vertex    132,    -17,     43,     34,    468,  0x71, 0xCE, 0x1A, 0xFF
vertex    137,     35,     43,      0,    980,  0x64, 0x33, 0x39, 0xFF
vertex     -2,     15,    -96,    684,    990,  0xD6, 0x33, 0x94, 0xFF
vertex     84,     28,    -96,    242,    984,  0x36, 0x2A, 0x96, 0xFF
vertex     91,    -22,    -81,    240,    474,  0x24, 0xC2, 0x98, 0xFF
vertex    137,     35,    -40,      0,    980,  0x66, 0x45, 0xE3, 0xFF
vertex    132,    -17,    -40,     34,    468,  0x6A, 0xD6, 0xCB, 0xFF
vertex     84,    -76,    -28,    310,    -14,  0x3A, 0x94, 0xE4, 0xFF
vertex     22,    -84,    -28,    612,    -10,  0xEB, 0x8F, 0xCB, 0xFF
vertex      2,    -35,    -81,    684,    480,  0xD1, 0xBF, 0x9F, 0xFF
vertex     22,    -84,     30,    612,    -10,  0xE0, 0x89, 0x1B, 0xFF
vertex     84,    -76,     30,    310,    -14,  0x30, 0x97, 0x33, 0xFF
vertex      2,    -35,     86,    684,    470,  0xEA, 0xBB, 0x67, 0xFF
vertex     84,     28,     99,    242,    984,  0x1F, 0x28, 0x74, 0xFF
vertex     -2,     15,     99,    684,    990,  0xC1, 0x34, 0x60, 0xFF

lakitu_seg6_vertex_06003B30: # 0x06003B30
vertex     -2,     15,     99,    684,    990,  0xC1, 0x34, 0x60, 0xFF
vertex    -56,      7,     43,    958,    992,  0x87, 0x10, 0x21, 0xFF
vertex    -33,    -40,     43,    884,    484,  0xA3, 0xBB, 0x31, 0xFF
vertex      2,    -35,     86,    684,    470,  0xEA, 0xBB, 0x67, 0xFF
vertex     22,    -84,     30,    612,    -10,  0xE0, 0x89, 0x1B, 0xFF
vertex    -33,    -40,    -40,    884,    484,  0xA1, 0xB1, 0xE7, 0xFF
vertex    -56,      7,    -40,    958,    992,  0x90, 0x14, 0xC9, 0xFF
vertex     22,    -84,    -28,    612,    -10,  0xEB, 0x8F, 0xCB, 0xFF
vertex      2,    -35,    -81,    684,    480,  0xD1, 0xBF, 0x9F, 0xFF
vertex     -2,     15,    -96,    684,    990,  0xD6, 0x33, 0x94, 0xFF

lakitu_seg6_vertex_06003BD0: # 0x06003BD0
vertex      0,     51,      0,      0,      0,  0xCF, 0x75, 0x00, 0xFF
vertex     68,     61,     35,      0,      0,  0x09, 0x7B, 0x1A, 0xFF
vertex     68,     61,    -33,      0,      0,  0x01, 0x7A, 0xE0, 0xFF
vertex     84,     28,    -96,      0,      0,  0x36, 0x2A, 0x96, 0xFF
vertex     -2,     15,    -96,      0,      0,  0xD6, 0x33, 0x94, 0xFF
vertex    137,     35,    -40,      0,      0,  0x66, 0x45, 0xE3, 0xFF
vertex    -56,      7,    -40,      0,      0,  0x90, 0x14, 0xC9, 0xFF
vertex     -2,     15,     99,      0,      0,  0xC1, 0x34, 0x60, 0xFF
vertex     84,     28,     99,      0,      0,  0x1F, 0x28, 0x74, 0xFF
vertex    -56,      7,     43,      0,      0,  0x87, 0x10, 0x21, 0xFF
vertex    137,     35,     43,      0,      0,  0x64, 0x33, 0x39, 0xFF

glabel lakitu_seg6_dl_06003C80 # 0x06003C80 - 0x06003DB0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, lakitu_seg6_texture_06002800
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight lakitu_seg6_light_06003A08, 1
gsSPLight lakitu_seg6_light_06003A00, 2
gsSPVertex lakitu_seg6_vertex_06003A30, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  4,  7,  5, 0x0
gsSP1Triangle  5,  7,  8, 0x0
gsSP1Triangle  8,  7,  1, 0x0
gsSP1Triangle  6,  1,  7, 0x0
gsSP1Triangle  5,  8,  9, 0x0
gsSP1Triangle  5,  9, 10, 0x0
gsSP1Triangle  3,  5, 10, 0x0
gsSP1Triangle  6,  2,  1, 0x0
gsSP1Triangle  8, 11,  9, 0x0
gsSP1Triangle  8, 12, 11, 0x0
gsSP1Triangle  8,  1, 12, 0x0
gsSP1Triangle 12,  1,  0, 0x0
gsSP1Triangle 13, 11, 12, 0x0
gsSP1Triangle 13, 12,  0, 0x0
gsSP1Triangle 14, 13,  0, 0x0
gsSP1Triangle  0,  2, 14, 0x0
gsSP1Triangle 14, 15, 13, 0x0
gsSPVertex lakitu_seg6_vertex_06003B30, 10, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  3,  2,  4, 0x0
gsSP1Triangle  4,  2,  5, 0x0
gsSP1Triangle  1,  5,  2, 0x0
gsSP1Triangle  1,  6,  5, 0x0
gsSP1Triangle  4,  5,  7, 0x0
gsSP1Triangle  7,  5,  8, 0x0
gsSP1Triangle  8,  5,  6, 0x0
gsSP1Triangle  8,  6,  9, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06003DB0 # 0x06003DB0 - 0x06003E30
gsSPLight lakitu_seg6_light_06003A20, 1
gsSPLight lakitu_seg6_light_06003A18, 2
gsSPVertex lakitu_seg6_vertex_06003BD0, 11, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  2,  3,  4, 0x0
gsSP1Triangle  1,  5,  2, 0x0
gsSP1Triangle  4,  0,  2, 0x0
gsSP1Triangle  5,  3,  2, 0x0
gsSP1Triangle  4,  6,  0, 0x0
gsSP1Triangle  7,  8,  1, 0x0
gsSP1Triangle  9,  7,  0, 0x0
gsSP1Triangle  1,  0,  7, 0x0
gsSP1Triangle  8, 10,  1, 0x0
gsSP1Triangle  1, 10,  5, 0x0
gsSP1Triangle  0,  6,  9, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06003E30 # 0x06003E30 - 0x06003E98
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList lakitu_seg6_dl_06003C80
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPDisplayList lakitu_seg6_dl_06003DB0
gsSPEndDisplayList

lakitu_seg6_light_06003E98: # 0x06003E98
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

lakitu_seg6_light_06003EA0: # 0x06003EA0
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_06003EB0: # 0x06003EB0
vertex      2,     -6,     83,  -1072,    916,  0xCB, 0x25, 0x6C, 0xFF
vertex    -49,    -11,     35,   -556,    874,  0x92, 0x2E, 0x2B, 0xFF
vertex      1,    -57,     76,  -1062,    410,  0xD5, 0xE6, 0x74, 0xFF
vertex      9,     27,    -50,  -1138,   1254,  0xCE, 0x70, 0xE4, 0xFF
vertex      9,     27,     51,  -1138,   1254,  0xCE, 0x6D, 0x28, 0xFF
vertex    -49,    -11,    -36,   -556,    874,  0x98, 0x26, 0xC4, 0xFF
vertex    -49,    -73,    -25,   -552,    248,  0x8D, 0xDC, 0xDA, 0xFF
vertex    -49,    -73,     26,   -552,    248,  0x93, 0xDE, 0x36, 0xFF
vertex      0,   -140,     32,  -1046,   -414,  0xC5, 0x94, 0x1D, 0xFF
vertex      0,    -98,     73,  -1054,     -2,  0xD6, 0xC8, 0x69, 0xFF
vertex    103,    -17,    101,  -2084,    810,  0x33, 0xD1, 0x69, 0xFF
vertex     98,    -35,     81,  -2034,    626,  0x43, 0xD5, 0x62, 0xFF
vertex     97,   -100,     73,  -2022,    -18,  0x22, 0xD7, 0x73, 0xFF
vertex    101,   -142,     35,  -2058,   -434,  0x26, 0x99, 0x3D, 0xFF
vertex      2,     -6,    -82,  -1072,    916,  0xCF, 0x36, 0x99, 0xFF
vertex      1,    -57,    -75,  -1062,    410,  0xD6, 0xE6, 0x8C, 0xFF

lakitu_seg6_vertex_06003FB0: # 0x06003FB0
vertex      1,    -57,    -75,  -1062,    410,  0xD6, 0xE6, 0x8C, 0xFF
vertex     98,    -35,    -80,  -2034,    626,  0x43, 0xD5, 0x9E, 0xFF
vertex     97,   -100,    -72,  -2022,    -18,  0x1B, 0xCD, 0x90, 0xFF
vertex      0,    -98,    -72,  -1054,     -2,  0xCC, 0xD2, 0x97, 0xFF
vertex      2,     -6,    -82,  -1072,    916,  0xCF, 0x36, 0x99, 0xFF
vertex    103,    -17,   -100,  -2084,    810,  0x33, 0xD1, 0x97, 0xFF
vertex    -49,    -73,    -25,   -552,    248,  0x8D, 0xDC, 0xDA, 0xFF
vertex    148,     21,    -45,  -2528,   1194,  0x67, 0x30, 0xC9, 0xFF
vertex    104,     34,    -89,  -2094,   1332,  0x1D, 0x53, 0xA5, 0xFF
vertex    105,     51,    -39,  -2096,   1494,  0x15, 0x78, 0xE0, 0xFF
vertex      0,   -140,     32,  -1046,   -414,  0xC5, 0x94, 0x1D, 0xFF
vertex      0,   -140,    -31,  -1046,   -414,  0xD1, 0x9A, 0xC6, 0xFF
vertex    161,     16,      0,    480,    568,  0x70, 0x3A, 0x00, 0xFF
vertex    154,    -30,     28,    746,    166,  0x6D, 0xC7, 0x1E, 0xFF
vertex    154,    -30,    -27,    210,    164,  0x6E, 0xCF, 0xDC, 0xFF

lakitu_seg6_vertex_060040A0: # 0x060040A0
vertex    105,     51,     40,    864,    924,  0x15, 0x7C, 0x0F, 0xFF
vertex    148,     21,     46,    920,    620,  0x67, 0x30, 0x36, 0xFF
vertex    161,     16,      0,    480,    568,  0x70, 0x3A, 0x00, 0xFF
vertex    154,    -30,    -27,    210,    164,  0x6E, 0xCF, 0xDC, 0xFF
vertex    148,     21,    -45,     40,    620,  0x67, 0x30, 0xC9, 0xFF
vertex    154,    -30,     28,    746,    166,  0x6D, 0xC7, 0x1E, 0xFF
vertex    105,     51,    -39,    100,    924,  0x15, 0x78, 0xE0, 0xFF
vertex      9,     27,    -50,  -1138,   1254,  0xCE, 0x70, 0xE4, 0xFF
vertex    105,     51,     40,  -2096,   1494,  0x15, 0x7C, 0x0F, 0xFF
vertex    105,     51,    -39,  -2096,   1494,  0x15, 0x78, 0xE0, 0xFF
vertex      2,     -6,    -82,  -1072,    916,  0xCF, 0x36, 0x99, 0xFF
vertex    104,     34,    -89,  -2094,   1332,  0x1D, 0x53, 0xA5, 0xFF
vertex      9,     27,     51,  -1138,   1254,  0xCE, 0x6D, 0x28, 0xFF
vertex    104,     34,     90,  -2094,   1332,  0x12, 0x57, 0x5A, 0xFF
vertex    161,     16,      0,  -2654,   1148,  0x70, 0x3A, 0x00, 0xFF
vertex    148,     21,     46,  -2528,   1194,  0x67, 0x30, 0x36, 0xFF

lakitu_seg6_vertex_060041A0: # 0x060041A0
vertex      2,     -6,    -82,  -1072,    916,  0xCF, 0x36, 0x99, 0xFF
vertex    104,     34,    -89,  -2094,   1332,  0x1D, 0x53, 0xA5, 0xFF
vertex    103,    -17,   -100,  -2084,    810,  0x33, 0xD1, 0x97, 0xFF
vertex     98,    -35,    -80,  -2034,    626,  0x43, 0xD5, 0x9E, 0xFF
vertex    138,    -47,    -10,  -2428,    508,  0x68, 0xBF, 0xE0, 0xFF
vertex    148,     21,    -45,  -2528,   1194,  0x67, 0x30, 0xC9, 0xFF
vertex    154,    -30,    -27,  -2588,    680,  0x6E, 0xCF, 0xDC, 0xFF
vertex     97,   -100,    -72,  -2022,    -18,  0x1B, 0xCD, 0x90, 0xFF
vertex    135,    -98,    -38,  -2404,     -2,  0x74, 0xE5, 0xD5, 0xFF
vertex    101,   -142,    -34,  -2058,   -434,  0x34, 0x92, 0xDE, 0xFF
vertex     98,    -35,     81,  -2034,    626,  0x43, 0xD5, 0x62, 0xFF
vertex     97,   -100,     73,  -2022,    -18,  0x22, 0xD7, 0x73, 0xFF
vertex    135,    -98,     39,  -2404,     -2,  0x70, 0xD8, 0x2B, 0xFF
vertex    138,    -47,     11,  -2428,    508,  0x6F, 0xCE, 0x20, 0xFF
vertex    103,    -17,    101,  -2084,    810,  0x33, 0xD1, 0x69, 0xFF

lakitu_seg6_vertex_06004290: # 0x06004290
vertex    103,    -17,    101,  -2084,    810,  0x33, 0xD1, 0x69, 0xFF
vertex    104,     34,     90,  -2094,   1332,  0x12, 0x57, 0x5A, 0xFF
vertex      2,     -6,     83,  -1072,    916,  0xCB, 0x25, 0x6C, 0xFF
vertex    138,    -47,     11,  -2428,    508,  0x6F, 0xCE, 0x20, 0xFF
vertex    154,    -30,     28,  -2588,    680,  0x6D, 0xC7, 0x1E, 0xFF
vertex    148,     21,     46,  -2528,   1194,  0x67, 0x30, 0x36, 0xFF
vertex    101,   -142,     35,  -2058,   -434,  0x26, 0x99, 0x3D, 0xFF
vertex    135,    -98,     39,  -2404,     -2,  0x70, 0xD8, 0x2B, 0xFF
vertex     97,   -100,     73,  -2022,    -18,  0x22, 0xD7, 0x73, 0xFF
vertex    101,   -142,    -34,  -2058,   -434,  0x34, 0x92, 0xDE, 0xFF
vertex    135,    -98,    -38,  -2404,     -2,  0x74, 0xE5, 0xD5, 0xFF
vertex     98,    -35,    -80,  -2034,    626,  0x43, 0xD5, 0x9E, 0xFF
vertex    138,    -47,    -10,  -2428,    508,  0x68, 0xBF, 0xE0, 0xFF
vertex     97,   -100,    -72,  -2022,    -18,  0x1B, 0xCD, 0x90, 0xFF
vertex      9,     27,     51,  -1138,   1254,  0xCE, 0x6D, 0x28, 0xFF
vertex      0,   -140,    -31,  -1046,   -414,  0xD1, 0x9A, 0xC6, 0xFF

lakitu_seg6_vertex_06004390: # 0x06004390
vertex    101,   -142,    -34,  -2058,   -434,  0x34, 0x92, 0xDE, 0xFF
vertex      0,   -140,     32,  -1046,   -414,  0xC5, 0x94, 0x1D, 0xFF
vertex      0,   -140,    -31,  -1046,   -414,  0xD1, 0x9A, 0xC6, 0xFF
vertex    101,   -142,     35,  -2058,   -434,  0x26, 0x99, 0x3D, 0xFF
vertex    138,    -47,    -10,    370,    -88,  0x68, 0xBF, 0xE0, 0xFF
vertex    154,    -30,     28,    724,    182,  0x6D, 0xC7, 0x1E, 0xFF
vertex    138,    -47,     11,    570,    -84,  0x6F, 0xCE, 0x20, 0xFF
vertex    154,    -30,    -27,    196,    176,  0x6E, 0xCF, 0xDC, 0xFF

glabel lakitu_seg6_dl_06004410 # 0x06004410 - 0x06004680
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, lakitu_seg6_texture_06003000
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight lakitu_seg6_light_06003EA0, 1
gsSPLight lakitu_seg6_light_06003E98, 2
gsSPVertex lakitu_seg6_vertex_06003EB0, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  1,  4, 0x0
gsSP1Triangle  3,  5,  1, 0x0
gsSP1Triangle  1,  6,  7, 0x0
gsSP1Triangle  1,  5,  6, 0x0
gsSP1Triangle  1,  0,  4, 0x0
gsSP1Triangle  1,  7,  2, 0x0
gsSP1Triangle  8,  7,  6, 0x0
gsSP1Triangle  9,  7,  8, 0x0
gsSP1Triangle  2,  7,  9, 0x0
gsSP1Triangle 10,  0,  2, 0x0
gsSP1Triangle  2, 11, 10, 0x0
gsSP1Triangle  2, 12, 11, 0x0
gsSP1Triangle  2,  9, 12, 0x0
gsSP1Triangle  9, 13, 12, 0x0
gsSP1Triangle  9,  8, 13, 0x0
gsSP1Triangle 14,  5,  3, 0x0
gsSP1Triangle  5, 15,  6, 0x0
gsSP1Triangle  5, 14, 15, 0x0
gsSPVertex lakitu_seg6_vertex_06003FB0, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  0,  4,  5, 0x0
gsSP1Triangle  6,  0,  3, 0x0
gsSP1Triangle  0,  5,  1, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle 10,  6, 11, 0x0
gsSP1Triangle 11,  6,  3, 0x0
gsSP1Triangle  2, 11,  3, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPVertex lakitu_seg6_vertex_060040A0, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  2, 0x0
gsSP1Triangle  2,  1,  5, 0x0
gsSP1Triangle  4,  6,  2, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle 10,  9, 11, 0x0
gsSP1Triangle 10,  7,  9, 0x0
gsSP1Triangle  7, 12,  8, 0x0
gsSP1Triangle 13,  8, 12, 0x0
gsSP1Triangle  9,  8, 14, 0x0
gsSP1Triangle 15,  8, 13, 0x0
gsSPVertex lakitu_seg6_vertex_060041A0, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  2,  4, 0x0
gsSP1Triangle  5,  6,  2, 0x0
gsSP1Triangle  2,  6,  4, 0x0
gsSP1Triangle  5,  2,  1, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 10, 12, 13, 0x0
gsSP1Triangle 14, 10, 13, 0x0
gsSPVertex lakitu_seg6_vertex_06004290, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  0, 0x0
gsSP1Triangle  1,  0,  5, 0x0
gsSP1Triangle  0,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10,  7, 0x0
gsSP1Triangle  3,  7, 10, 0x0
gsSP1Triangle  9,  7,  6, 0x0
gsSP1Triangle 11, 12, 10, 0x0
gsSP1Triangle 10, 13, 11, 0x0
gsSP1Triangle  3, 10, 12, 0x0
gsSP1Triangle  1, 14,  2, 0x0
gsSP1Triangle 13,  9, 15, 0x0
gsSPVertex lakitu_seg6_vertex_06004390, 8, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  7,  5, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06004680 # 0x06004680 - 0x060046E0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList lakitu_seg6_dl_06004410
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

lakitu_seg6_light_060046E0: # 0x060046E0
.byte 0x79, 0x55, 0x00, 0x00, 0x79, 0x55, 0x00, 0x00

lakitu_seg6_light_060046E8: # 0x060046E8
.byte 0xF2, 0xAB, 0x00, 0x00, 0xF2, 0xAB, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_060046F8: # 0x060046F8
vertex     99,     30,     33,      0,      0,  0x06, 0x5E, 0x54, 0xFF
vertex    102,      0,     33,      0,      0,  0x21, 0xD1, 0x70, 0xFF
vertex    140,     20,      2,      0,      0,  0x73, 0xFB, 0x35, 0xFF
vertex     99,     30,    -28,      0,      0,  0xFA, 0x4F, 0x9E, 0xFF
vertex    102,      0,    -28,      0,      0,  0x1B, 0xB7, 0x9D, 0xFF
vertex     30,     -5,    -20,      0,      0,  0xDF, 0xCE, 0x91, 0xFF
vertex    104,    -15,      2,      0,      0,  0x31, 0x8C, 0x07, 0xFF
vertex     33,    -17,      0,      0,      0,  0xEC, 0x84, 0xEF, 0xFF
vertex    137,     20,    -12,      0,      0,  0x64, 0xFB, 0xB3, 0xFF
vertex     30,     -5,     25,      0,      0,  0xE3, 0xAF, 0x5D, 0xFF
vertex     -5,      0,      2,      0,      0,  0x83, 0xEE, 0xFE, 0xFF
vertex     28,     15,    -20,      0,      0,  0xC9, 0x34, 0x9B, 0xFF
vertex     28,     15,     25,      0,      0,  0xD1, 0x29, 0x6E, 0xFF
vertex     25,     28,      2,      0,      0,  0xCE, 0x74, 0x00, 0xFF
vertex    119,     45,      0,      0,      0,  0x35, 0x72, 0xF9, 0xFF

glabel lakitu_seg6_dl_060047E8 # 0x060047E8 - 0x060048D8
gsSPLight lakitu_seg6_light_060046E8, 1
gsSPLight lakitu_seg6_light_060046E0, 2
gsSPVertex lakitu_seg6_vertex_060046F8, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  4,  7,  5, 0x0
gsSP1Triangle  6,  4,  8, 0x0
gsSP1Triangle  3,  8,  4, 0x0
gsSP1Triangle  9,  7,  6, 0x0
gsSP1Triangle 10,  7,  9, 0x0
gsSP1Triangle  5,  7, 10, 0x0
gsSP1Triangle  3,  5, 11, 0x0
gsSP1Triangle  5, 10, 11, 0x0
gsSP1Triangle  1,  6,  2, 0x0
gsSP1Triangle  2,  6,  8, 0x0
gsSP1Triangle  9,  6,  1, 0x0
gsSP1Triangle  1, 12,  9, 0x0
gsSP1Triangle 12, 10,  9, 0x0
gsSP1Triangle  1,  0, 12, 0x0
gsSP1Triangle 11, 13,  3, 0x0
gsSP1Triangle 14,  0,  2, 0x0
gsSP1Triangle 14,  2,  8, 0x0
gsSP1Triangle  3, 14,  8, 0x0
gsSP1Triangle 13,  0,  3, 0x0
gsSP1Triangle  3,  0, 14, 0x0
gsSP1Triangle  0, 13, 12, 0x0
gsSP1Triangle 10, 13, 11, 0x0
gsSP1Triangle 12, 13, 10, 0x0
gsSPEndDisplayList

lakitu_seg6_light_060048D8: # 0x060048D8
.byte 0x79, 0x55, 0x00, 0x00, 0x79, 0x55, 0x00, 0x00

lakitu_seg6_light_060048E0: # 0x060048E0
.byte 0xF2, 0xAB, 0x00, 0x00, 0xF2, 0xAB, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_060048F0: # 0x060048F0
vertex     30,     -5,    -22,      0,      0,  0xE3, 0xB1, 0xA2, 0xFF
vertex     -5,      0,      0,      0,      0,  0x83, 0xEE, 0x00, 0xFF
vertex     28,     15,    -22,      0,      0,  0xD1, 0x29, 0x92, 0xFF
vertex     30,     -5,     22,      0,      0,  0xDF, 0xCB, 0x6E, 0xFF
vertex    102,      0,     30,      0,      0,  0x1B, 0xB6, 0x63, 0xFF
vertex     99,     30,     30,      0,      0,  0xFA, 0x4F, 0x62, 0xFF
vertex     28,     15,     22,      0,      0,  0xC9, 0x34, 0x65, 0xFF
vertex     33,    -17,      0,      0,      0,  0xEC, 0x84, 0x0D, 0xFF
vertex    104,    -15,      0,      0,      0,  0x31, 0x8C, 0xF8, 0xFF
vertex    137,     20,     15,      0,      0,  0x64, 0xFB, 0x4D, 0xFF
vertex    140,     20,      0,      0,      0,  0x73, 0xFB, 0xCB, 0xFF
vertex    102,      0,    -30,      0,      0,  0x21, 0xD1, 0x90, 0xFF
vertex     99,     30,    -30,      0,      0,  0x06, 0x5E, 0xAC, 0xFF
vertex    119,     45,      2,      0,      0,  0x35, 0x72, 0x07, 0xFF
vertex     25,     28,      0,      0,      0,  0xCE, 0x74, 0x00, 0xFF

glabel lakitu_seg6_dl_060049E0 # 0x060049E0 - 0x06004AD0
gsSPLight lakitu_seg6_light_060048E0, 1
gsSPLight lakitu_seg6_light_060048D8, 2
gsSPVertex lakitu_seg6_vertex_060048F0, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  3,  5, 0x0
gsSP1Triangle  3,  7,  4, 0x0
gsSP1Triangle  6,  1,  3, 0x0
gsSP1Triangle  1,  7,  3, 0x0
gsSP1Triangle  8,  7,  0, 0x0
gsSP1Triangle  7,  8,  4, 0x0
gsSP1Triangle  0,  7,  1, 0x0
gsSP1Triangle  9,  4,  8, 0x0
gsSP1Triangle  4,  9,  5, 0x0
gsSP1Triangle 10,  8, 11, 0x0
gsSP1Triangle  9,  8, 10, 0x0
gsSP1Triangle 11,  8,  0, 0x0
gsSP1Triangle  0,  2, 11, 0x0
gsSP1Triangle  2, 12, 11, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 13, 12,  5, 0x0
gsSP1Triangle  9, 10, 13, 0x0
gsSP1Triangle  9, 13,  5, 0x0
gsSP1Triangle 10, 12, 13, 0x0
gsSP1Triangle  1, 14,  2, 0x0
gsSP1Triangle  2, 14, 12, 0x0
gsSP1Triangle  6, 14,  1, 0x0
gsSP1Triangle  5, 14,  6, 0x0
gsSP1Triangle  5, 12, 14, 0x0
gsSPEndDisplayList

lakitu_seg6_light_06004AD0: # 0x06004AD0
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

lakitu_seg6_light_06004AD8: # 0x06004AD8
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_06004AE8: # 0x06004AE8
vertex    150,    -30,      0,    992,    994,  0x7E, 0xF5, 0x09, 0xFF
vertex    136,   -116,     82,   2012,      0,  0x7E, 0xF5, 0x09, 0xFF
vertex    142,   -116,      0,    992,    -26,  0x7E, 0xF5, 0x09, 0xFF
vertex    142,   -116,      0,    992,    -26,  0x7E, 0xF5, 0xF9, 0xFF
vertex    145,    -30,    -81,      0,    990,  0x7E, 0xF5, 0xF9, 0xFF
vertex    150,    -30,      0,    992,    994,  0x7E, 0xF5, 0xF9, 0xFF
vertex    142,   -116,      0,    992,    -26,  0x7D, 0xF3, 0xF7, 0xFF
vertex    136,   -116,    -81,      0,      0,  0x7D, 0xF3, 0xF7, 0xFF
vertex    145,    -30,    -81,      0,    990,  0x7D, 0xF3, 0xF7, 0xFF
vertex    150,    -30,      0,    992,    994,  0x7E, 0xF3, 0x07, 0xFF
vertex    145,    -30,     82,   2012,    990,  0x7E, 0xF3, 0x07, 0xFF
vertex    136,   -116,     82,   2012,      0,  0x7E, 0xF3, 0x07, 0xFF

glabel lakitu_seg6_dl_06004BA8 # 0x06004BA8 - 0x06004BE8
gsSPLight lakitu_seg6_light_06004AD8, 1
gsSPLight lakitu_seg6_light_06004AD0, 2
gsSPVertex lakitu_seg6_vertex_06004AE8, 12, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06004BE8 # 0x06004BE8 - 0x06004C30
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_SHADE, G_ACMUX_0, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_TEXEL0, G_ACMUX_0, G_ACMUX_SHADE, G_ACMUX_0
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 252, 124
gsSPEndDisplayList

glabel lakitu_seg6_dl_06004C30 # 0x06004C30 - 0x06004C60
gsSPDisplayList lakitu_seg6_dl_06004BA8
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList

glabel lakitu_seg6_dl_06004C60 # 0x06004C60 - 0x06004C88
gsSPDisplayList lakitu_seg6_dl_06004BE8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, lakitu_seg6_texture_06000800
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x080
gsSPBranchList lakitu_seg6_dl_06004C30

glabel lakitu_seg6_dl_06004C88 # 0x06004C88 - 0x06004CB0
gsSPDisplayList lakitu_seg6_dl_06004BE8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, lakitu_seg6_texture_06001800
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x080
gsSPBranchList lakitu_seg6_dl_06004C30

lakitu_seg6_light_06004CB0: # 0x06004CB0
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

lakitu_seg6_light_06004CB8: # 0x06004CB8
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_06004CC8: # 0x06004CC8
.byte 0x0C, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0x00

lakitu_seg6_light_06004CD0: # 0x06004CD0
.byte 0x19, 0x19, 0x19, 0x00, 0x19, 0x19, 0x19, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_06004CE0: # 0x06004CE0
.byte 0x19, 0x22, 0x20, 0x00, 0x19, 0x22, 0x20, 0x00

lakitu_seg6_light_06004CE8: # 0x06004CE8
.byte 0x32, 0x44, 0x40, 0x00, 0x32, 0x44, 0x40, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_06004CF8: # 0x06004CF8
.byte 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00

lakitu_seg6_light_06004D00: # 0x06004D00
.byte 0x30, 0x30, 0x30, 0x00, 0x30, 0x30, 0x30, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_06004D10: # 0x06004D10
vertex     79,   -113,    -34,      0,    480,  0x00, 0x81, 0x00, 0xFF
vertex      7,   -113,     37,    480,      0,  0x00, 0x81, 0x00, 0xFF
vertex      7,   -113,    -34,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     79,   -113,     37,    480,    480,  0x00, 0x81, 0x00, 0xFF

lakitu_seg6_vertex_06004D50: # 0x06004D50
vertex     20,    -58,    -21,      0,      0,  0x00, 0x39, 0x8F, 0xFF
vertex     66,    -58,    -21,      0,      0,  0x00, 0x39, 0x8F, 0xFF
vertex     43,   -113,    -49,      0,      0,  0x00, 0x39, 0x8F, 0xFF
vertex     20,    -58,    -21,      0,      0,  0xD2, 0x25, 0x90, 0xFF
vertex     43,   -113,    -49,      0,      0,  0xD2, 0x25, 0x90, 0xFF
vertex      7,   -113,    -34,      0,      0,  0xD2, 0x25, 0x90, 0xFF
vertex     20,    -58,    -21,      0,      0,  0x90, 0x25, 0xD3, 0xFF
vertex      7,   -113,    -34,      0,      0,  0x90, 0x25, 0xD3, 0xFF
vertex     -7,   -113,      1,      0,      0,  0x90, 0x25, 0xD3, 0xFF
vertex     20,    -58,    -21,      0,      0,  0x8E, 0x37, 0x00, 0xFF
vertex     -7,   -113,      1,      0,      0,  0x8E, 0x37, 0x00, 0xFF
vertex     20,    -58,     24,      0,      0,  0x8E, 0x37, 0x00, 0xFF
vertex     79,   -113,    -34,      0,      0,  0x2E, 0x25, 0x90, 0xFF
vertex     43,   -113,    -49,      0,      0,  0x2E, 0x25, 0x90, 0xFF
vertex     66,    -58,    -21,      0,      0,  0x2E, 0x25, 0x90, 0xFF

lakitu_seg6_vertex_06004E40: # 0x06004E40
vertex     66,    -58,    -21,      0,      0,  0x71, 0x39, 0x00, 0xFF
vertex     66,    -58,     24,      0,      0,  0x71, 0x39, 0x00, 0xFF
vertex     94,   -113,      1,      0,      0,  0x71, 0x39, 0x00, 0xFF
vertex     66,    -58,    -21,      0,      0,  0x6F, 0x25, 0xD1, 0xFF
vertex     94,   -113,      1,      0,      0,  0x6F, 0x25, 0xD1, 0xFF
vertex     79,   -113,    -34,      0,      0,  0x6F, 0x25, 0xD1, 0xFF
vertex     94,   -113,      1,      0,      0,  0x70, 0x25, 0x2E, 0xFF
vertex     66,    -58,     24,      0,      0,  0x70, 0x25, 0x2E, 0xFF
vertex     79,   -113,     37,      0,      0,  0x70, 0x25, 0x2E, 0xFF
vertex     79,   -113,     37,      0,      0,  0x2E, 0x25, 0x70, 0xFF
vertex     66,    -58,     24,      0,      0,  0x2E, 0x25, 0x70, 0xFF
vertex     43,   -113,     52,      0,      0,  0x2E, 0x25, 0x70, 0xFF
vertex     66,    -58,     24,      0,      0,  0x00, 0x39, 0x71, 0xFF
vertex     20,    -58,     24,      0,      0,  0x00, 0x39, 0x71, 0xFF
vertex     43,   -113,     52,      0,      0,  0x00, 0x39, 0x71, 0xFF

lakitu_seg6_vertex_06004F30: # 0x06004F30
vertex     43,   -113,     52,      0,      0,  0xD2, 0x25, 0x70, 0xFF
vertex     20,    -58,     24,      0,      0,  0xD2, 0x25, 0x70, 0xFF
vertex      7,   -113,     37,      0,      0,  0xD2, 0x25, 0x70, 0xFF
vertex     -7,   -113,      1,      0,      0,  0x8F, 0x25, 0x2C, 0xFF
vertex      7,   -113,     37,      0,      0,  0x8F, 0x25, 0x2C, 0xFF
vertex     20,    -58,     24,      0,      0,  0x8F, 0x25, 0x2C, 0xFF

lakitu_seg6_vertex_06004F90: # 0x06004F90
vertex     -4,     46,    -40,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex     -4,    -58,     43,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex     -4,     46,     43,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    100,     46,     43,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex    100,     46,    -40,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex     -4,     46,    -40,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex     -4,     46,     43,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex     -4,    -58,    -40,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex    100,     46,    -40,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex     -4,    -58,    -40,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex     -4,     46,    -40,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    100,    -58,     43,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex     -4,     46,     43,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex     -4,    -58,     43,      0,      0,  0x00, 0x00, 0x7F, 0xFF

lakitu_seg6_vertex_06005070: # 0x06005070
vertex    100,    -58,    -40,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex    100,    -58,     43,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     -4,    -58,     43,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     -4,    -58,    -40,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex    100,    -58,     43,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    100,     46,     43,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex     -4,     46,     43,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    100,     46,    -40,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    100,    -58,    -40,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex     -4,    -58,    -40,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    100,     46,     43,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    100,    -58,    -40,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    100,     46,    -40,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    100,    -58,     43,      0,      0,  0x7F, 0x00, 0x00, 0xFF

lakitu_seg6_vertex_06005150: # 0x06005150
vertex      7,   -113,    -34,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex      7,   -113,     37,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     -7,   -113,      1,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     43,   -113,    -49,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     79,   -113,    -34,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     94,   -113,      1,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     79,   -113,     37,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex     43,   -113,     52,      0,      0,  0x00, 0x81, 0x00, 0xFF

glabel lakitu_seg6_dl_060051D0 # 0x060051D0 - 0x06005218
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, lakitu_seg6_texture_06003800
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x0FF, 0x200
gsSPLight lakitu_seg6_light_06004CB8, 1
gsSPLight lakitu_seg6_light_06004CB0, 2
gsSPVertex lakitu_seg6_vertex_06004D10, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06005218 # 0x06005218 - 0x06005360
gsSPLight lakitu_seg6_light_06004CD0, 1
gsSPLight lakitu_seg6_light_06004CC8, 2
gsSPVertex lakitu_seg6_vertex_06004D50, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPVertex lakitu_seg6_vertex_06004E40, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPVertex lakitu_seg6_vertex_06004F30, 6, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSPLight lakitu_seg6_light_06004CE8, 1
gsSPLight lakitu_seg6_light_06004CE0, 2
gsSPVertex lakitu_seg6_vertex_06004F90, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  5,  6, 0x0
gsSP1Triangle  0,  7,  1, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSPVertex lakitu_seg6_vertex_06005070, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSP1Triangle 10, 13, 11, 0x0
gsSPLight lakitu_seg6_light_06004D00, 1
gsSPLight lakitu_seg6_light_06004CF8, 2
gsSPVertex lakitu_seg6_vertex_06005150, 8, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  4, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  7,  1,  6, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06005360 # 0x06005360 - 0x060053D8
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 4, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 60, 60
gsSPDisplayList lakitu_seg6_dl_060051D0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPDisplayList lakitu_seg6_dl_06005218
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList

# unreferenced light?
.byte 0x33, 0x1F, 0x0C, 0x00, 0x33, 0x1F, 0x0C, 0x00
.byte 0xCC, 0x7F, 0x33, 0x00, 0xCC, 0x7F, 0x33, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_060053F0: # 0x060053F0
.byte 0x29, 0x13, 0x06, 0x00, 0x29, 0x13, 0x06, 0x00

lakitu_seg6_light_060053F8: # 0x060053F8
.byte 0xA5, 0x4F, 0x1B, 0x00, 0xA5, 0x4F, 0x1B, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# unreferenced light?
.byte 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00
.byte 0x19, 0x19, 0x19, 0x00, 0x19, 0x19, 0x19, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# unreferenced light?
.byte 0x2C, 0x2C, 0x2C, 0x00, 0x2C, 0x2C, 0x2C, 0x00
.byte 0xB2, 0xB2, 0xB2, 0x00, 0xB2, 0xB2, 0xB2, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_06005438: # 0x06005438
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_light_06005440: # 0x06005440
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# unreferenced light?
.byte 0x0D, 0x2C, 0x0B, 0x00, 0x0D, 0x2C, 0x0B, 0x00
.byte 0x34, 0xB2, 0x2C, 0x00, 0x34, 0xB2, 0x2C, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

lakitu_seg6_vertex_06005468: # 0x06005468
vertex    103,     40,     28,      0,      0,  0xB1, 0x5E, 0x1C, 0x00
vertex    115,     46,     39,      0,      0,  0xB1, 0x5E, 0x1C, 0x00
vertex    111,     46,     30,      0,      0,  0xB1, 0x5E, 0x1C, 0x00
vertex    115,     46,     39,      0,      0,  0xCE, 0xB9, 0x5B, 0xFF
vertex    103,     40,     28,      0,      0,  0xCE, 0xB9, 0x5B, 0xFF
vertex    345,   -234,    -54,      0,      0,  0xCE, 0xB9, 0x5B, 0xFF
vertex    115,     51,     23,      0,      0,  0xB1, 0x5E, 0x1C, 0xFF
vertex    103,     40,     28,      0,      0,  0xD2, 0xFB, 0x8B, 0xFF
vertex    115,     51,     23,      0,      0,  0xD2, 0xFB, 0x8B, 0xFF
vertex    345,   -234,    -54,      0,      0,  0xD2, 0xFB, 0x8B, 0xFF
vertex    115,     51,     23,      0,      0,  0x64, 0x49, 0x18, 0xFF
vertex    115,     46,     39,      0,      0,  0x64, 0x49, 0x18, 0xFF
vertex    345,   -234,    -54,      0,      0,  0x64, 0x49, 0x18, 0xFF

lakitu_seg6_vertex_06005538: # 0x06005538
vertex    189,      1,      1,      0,      0,  0xFF, 0x7F, 0x00, 0x00
vertex    189,      1,     -2,      0,      0,  0xFF, 0x7F, 0x00, 0x00
vertex     -3,      0,      0,      0,      0,  0xFF, 0x7F, 0x00, 0x00

lakitu_seg6_vertex_06005568: # 0x06005568
vertex     -3,      0,      0,      0,      0,  0x01, 0x81, 0x00, 0x00
vertex    189,      2,     -2,      0,      0,  0x01, 0x81, 0x00, 0x00
vertex    189,      2,      1,      0,      0,  0x01, 0x81, 0x00, 0x00

glabel lakitu_seg6_dl_06005598 # 0x06005598 - 0x060055E8
gsSPLight lakitu_seg6_light_060053F8, 1
gsSPLight lakitu_seg6_light_060053F0, 2
gsSPVertex lakitu_seg6_vertex_06005468, 13, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  0,  2, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  1,  6,  2, 0x0
gsSP1Triangle 10, 11, 12, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_060055E8 # 0x060055E8 - 0x06005610
gsSPLight lakitu_seg6_light_06005440, 1
gsSPLight lakitu_seg6_light_06005438, 2
gsSPVertex lakitu_seg6_vertex_06005538, 3, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSPEndDisplayList

glabel lakitu_seg6_dl_06005610 # 0x06005610 - 0x06005638
gsSPLight lakitu_seg6_light_06005440, 1
gsSPLight lakitu_seg6_light_06005438, 2
gsSPVertex lakitu_seg6_vertex_06005568, 3, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSPEndDisplayList

lakitu_seg6_animvalue_06005638: # 0x06005638
.hword 0x0000, 0x0097, 0xFFC2, 0x3FFF, 0xFC86, 0x1413, 0x89B5, 0x019A
.hword 0xF031, 0x88AD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0001, 0x0002, 0x0002, 0x0003, 0x0004, 0x0004, 0x0004
.hword 0x0005, 0x0005, 0x0005, 0x0005, 0x0005, 0x0006, 0x0006, 0x0006
.hword 0x0006, 0x0006, 0x0006, 0x0005, 0x0004, 0x0003, 0x0001, 0x0000
.hword 0xF913, 0xF9B4, 0xFA9E, 0xFBC3, 0xFD18, 0xFE8C, 0x0013, 0x01A0
.hword 0x0324, 0x0493, 0x05DD, 0x06F6, 0x07CF, 0x085C, 0x088E, 0x0863
.hword 0x07E9, 0x072A, 0x0633, 0x050E, 0x03C5, 0x0264, 0x00F6, 0xFF86
.hword 0xFE1E, 0xFCC9, 0xFB93, 0xFA86, 0xF9AD, 0xF913, 0x009A, 0x0065
.hword 0x0040, 0x002A, 0x0022, 0x0026, 0x0035, 0x004E, 0x006E, 0x0095
.hword 0x00C2, 0x00F2, 0x0124, 0x0158, 0x018B, 0x01BC, 0x01EA, 0x0214
.hword 0x0237, 0x0253, 0x0266, 0x026F, 0x026C, 0x025C, 0x023D, 0x020F
.hword 0x01CF, 0x017D, 0x0116, 0x009A, 0x05B4, 0x0586, 0x0506, 0x0442
.hword 0x0347, 0x0223, 0x00E4, 0xFF98, 0xFE4B, 0xFD0C, 0xFBE8, 0xFAED
.hword 0xFA29, 0xF9A9, 0xF97C, 0xF9A4, 0xFA14, 0xFAC1, 0xFBA1, 0xFCA7
.hword 0xFDC9, 0xFEFC, 0x0033, 0x0166, 0x0288, 0x038F, 0x046E, 0x051C
.hword 0x058C, 0x05B4, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67
.hword 0xBF67, 0xBF67, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66
.hword 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66
.hword 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67
.hword 0x05B4, 0x0586, 0x0506, 0x0442, 0x0347, 0x0223, 0x00E4, 0xFF98
.hword 0xFE4B, 0xFD0C, 0xFBE8, 0xFAED, 0xFA29, 0xF9A9, 0xF97C, 0xF9A4
.hword 0xFA14, 0xFAC1, 0xFBA1, 0xFCA7, 0xFDC9, 0xFEFC, 0x0033, 0x0166
.hword 0x0288, 0x038F, 0x046E, 0x051C, 0x058C, 0x05B4, 0xBF67, 0xBF67
.hword 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0xBF66, 0xBF66
.hword 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF66
.hword 0xBF66, 0xBF66, 0xBF66, 0xBF66, 0xBF67, 0xBF67, 0xBF67, 0xBF67
.hword 0xBF67, 0xBF67, 0xBF67, 0xBF67, 0x04DE, 0xF0D8, 0x76E8, 0x019A
.hword 0xF031, 0x88AD, 0xA2CB, 0xA2CB, 0xFFCA, 0xFE70, 0x2743, 0x274A
.hword 0x275D, 0x277B, 0x27A1, 0x27CD, 0x27FD, 0x2830, 0x2863, 0x2894
.hword 0x28C1, 0x28E8, 0x2907, 0x291C, 0x2925, 0x2920, 0x2910, 0x28F6
.hword 0x28D4, 0x28AC, 0x287F, 0x284F, 0x281F, 0x27EF, 0x27C2, 0x2799
.hword 0x2776, 0x275A, 0x2749, 0x2743, 0x5C65, 0x0000

lakitu_seg6_animindex_06005844: # 0x06005844
.hword 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0000
.hword 0x0001, 0x0003, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0104, 0x0001, 0x00E4, 0x0001, 0x00E5, 0x001E, 0x00E6
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x00E3, 0x0001, 0x0004
.hword 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x00E2, 0x0001, 0x00DF, 0x0001, 0x00E0, 0x0001, 0x00E1
.hword 0x0001, 0x00DC, 0x0001, 0x00DD, 0x0001, 0x00DE, 0x0001, 0x0000
.hword 0x001E, 0x00A0, 0x001E, 0x00BE, 0x001E, 0x000A, 0x001E, 0x0028
.hword 0x001E, 0x0046, 0x0001, 0x0000, 0x001E, 0x0064, 0x001E, 0x0082
.hword 0x0001, 0x0007, 0x0001, 0x0008, 0x0001, 0x0009

lakitu_seg6_anim_060058E0: # 0x060058E0
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x1E
.hword 0xC
.word lakitu_seg6_animvalue_06005638
.word lakitu_seg6_animindex_06005844
.word 0

glabel lakitu_seg6_anims_060058F8 # 0x060058F8
.word lakitu_seg6_anim_060058E0
.word 0

binid
