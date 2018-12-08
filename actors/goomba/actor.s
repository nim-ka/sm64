# Goomba

# Unreferenced light
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

# Unreferenced light
.byte 0x2C, 0x2C, 0x2C, 0x00, 0x2C, 0x2C, 0x2C, 0x00

.byte 0xB2, 0xB2, 0xB2, 0x00, 0xB2, 0xB2, 0xB2, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

goomba_seg8_light_080194D0: # 0x080194D0
.byte 0x15, 0x0B, 0x04, 0x00, 0x15, 0x0B, 0x04, 0x00

goomba_seg8_light_080194D8: # 0x080194D8
.byte 0x54, 0x2E, 0x10, 0x00, 0x54, 0x2E, 0x10, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

goomba_seg8_light_080194E8: # 0x080194E8
.byte 0x18, 0x0D, 0x04, 0x00, 0x18, 0x0D, 0x04, 0x00

goomba_seg8_light_080194F0: # 0x080194F0
.byte 0x61, 0x34, 0x13, 0x00, 0x61, 0x34, 0x13, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

goomba_seg8_light_08019500: # 0x08019500
.byte 0x1D, 0x10, 0x08, 0x00, 0x1D, 0x10, 0x08, 0x00

goomba_seg8_light_08019508: # 0x08019508
.byte 0x77, 0x42, 0x20, 0x00, 0x77, 0x42, 0x20, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

goomba_seg8_light_08019518: # 0x08019518
.byte 0x37, 0x2D, 0x13, 0x00, 0x37, 0x2D, 0x13, 0x00

goomba_seg8_light_08019520: # 0x08019520
.byte 0xDE, 0xB4, 0x4E, 0x00, 0xDE, 0xB4, 0x4E, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

goomba_seg8_texture_08019530: # 0x08019530
.incbin "actors/goomba/0.rgba16"

goomba_seg8_texture_08019D30: # 0x08019D30
.incbin "actors/goomba/1.rgba16"

goomba_seg8_texture_0801A530: # 0x0801A530
.incbin "actors/goomba/2.rgba16"

goomba_seg8_light_0801AD30: # 0x0801AD30
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

goomba_seg8_light_0801AD38: # 0x0801AD38
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

goomba_seg8_vertex_0801AD48: # 0x0801AD48
vertex     80,     58,    105,   1124,    322,  0x22, 0x3F, 0x68, 0xFF
vertex     80,     98,     62,    858,    338,  0x1D, 0x6E, 0x36, 0xFF
vertex    -23,    109,     59,    842,   1002,  0xC7, 0x64, 0x34, 0xFF
vertex    -23,     55,    118,   -898,   1226,  0xBC, 0x29, 0x62, 0xFF
vertex    -51,    -48,     53,  -1544,   1510,  0x87, 0xEE, 0x1E, 0xFF
vertex    -23,    -54,    118,   -898,   1226,  0xC7, 0xC8, 0x62, 0xFF
vertex    -23,   -108,     75,  -1322,   1230,  0xBF, 0x9B, 0x27, 0xFF
vertex     -1,      0,    141,   -670,   1004,  0xFA, 0xF8, 0x7E, 0xFF
vertex     80,    -97,     52,  -1560,    196,  0x1C, 0x96, 0x3F, 0xFF
vertex     80,    -57,    105,  -1022,    196,  0x1D, 0xBE, 0x67, 0xFF
vertex     82,      0,    120,   -880,    168,  0x2E, 0x05, 0x76, 0xFF
vertex    -51,     49,     53,  -1544,   1510,  0x85, 0x1A, 0x10, 0xFF
vertex     80,     58,    105,  -1022,    196,  0x22, 0x3F, 0x68, 0xFF
vertex    -23,    109,     59,  -1482,   1230,  0xC7, 0x64, 0x34, 0xFF
vertex    -23,     55,    118,   1198,    978,  0xBC, 0x29, 0x62, 0xFF

goomba_seg8_vertex_0801AE38: # 0x0801AE38
vertex    -23,    109,    -58,    122,   1008,  0xBD, 0x65, 0xDC, 0xFF
vertex     -1,    130,      0,    482,    872,  0xFB, 0x7E, 0x05, 0xFF
vertex     82,    110,      0,    482,    330,  0x2D, 0x76, 0xF9, 0xFF
vertex    -23,    109,     59,    842,   1002,  0xC7, 0x64, 0x34, 0xFF
vertex     80,     98,     62,    858,    338,  0x1D, 0x6E, 0x36, 0xFF
vertex     80,     98,    -61,    108,    346,  0x19, 0x6A, 0xC1, 0xFF
vertex    -23,     55,   -117,   -232,    990,  0xD2, 0x39, 0x99, 0xFF
vertex    -23,    -54,   -117,  -3250,   1226,  0xBC, 0xDC, 0x9C, 0xFF
vertex    -51,     49,    -52,  -2604,   1510,  0x87, 0x14, 0xE3, 0xFF
vertex    -23,     55,   -117,  -3250,   1226,  0xD2, 0x39, 0x99, 0xFF
vertex    -23,    109,    -58,  -2666,   1230,  0xBD, 0x65, 0xDC, 0xFF
vertex     -1,      0,   -140,  -3478,   1004,  0xF2, 0x00, 0x82, 0xFF
vertex     82,      0,   -119,  -3268,    168,  0x29, 0x03, 0x89, 0xFF
vertex     80,     58,   -104,  -3126,    196,  0x1F, 0x40, 0x97, 0xFF
vertex    143,     65,    -68,     62,    -70,  0x4C, 0x49, 0xBB, 0xFF
vertex    156,     68,      0,    484,   -156,  0x6E, 0x3E, 0x00, 0xFF

goomba_seg8_vertex_0801AF38: # 0x0801AF38
vertex    -23,    -54,   -117,  -3250,   1226,  0xBC, 0xDC, 0x9C, 0xFF
vertex    -51,    -48,    -52,  -2604,   1510,  0x85, 0xE8, 0xF0, 0xFF
vertex    -51,     49,    -52,  -2604,   1510,  0x87, 0x14, 0xE3, 0xFF
vertex    -23,   -108,    -74,  -2826,   1230,  0xCA, 0x9C, 0xCA, 0xFF
vertex     82,      0,   -119,  -3268,    168,  0x29, 0x03, 0x89, 0xFF
vertex     80,    -57,   -104,  -3126,    196,  0x24, 0xC1, 0x99, 0xFF
vertex     -1,   -129,      0,  -2074,   1004,  0xFE, 0x82, 0xF8, 0xFF
vertex    -23,   -108,     75,  -1322,   1230,  0xBF, 0x9B, 0x27, 0xFF
vertex     80,    -97,    -51,  -2588,    196,  0x20, 0x91, 0xCE, 0xFF
vertex     82,   -109,      0,  -2074,    168,  0x2C, 0x8A, 0x05, 0xFF
vertex     80,    -97,     52,  -1560,    196,  0x1C, 0x96, 0x3F, 0xFF
vertex    -51,    -48,     53,  -1544,   1510,  0x87, 0xEE, 0x1E, 0xFF
vertex     82,    110,      0,    482,    330,  0x2D, 0x76, 0xF9, 0xFF
vertex     80,     98,     62,    858,    338,  0x1D, 0x6E, 0x36, 0xFF
vertex    143,     65,     69,    906,    -78,  0x4D, 0x51, 0x3A, 0xFF
vertex    156,     68,      0,    484,   -156,  0x6E, 0x3E, 0x00, 0xFF

goomba_seg8_vertex_0801B038: # 0x0801B038
vertex    143,     65,     69,    906,    -78,  0x4D, 0x51, 0x3A, 0xFF
vertex     80,     98,     62,    858,    338,  0x1D, 0x6E, 0x36, 0xFF
vertex     80,     58,    105,   1124,    322,  0x22, 0x3F, 0x68, 0xFF
vertex    156,      0,     74,  -1340,   -572,  0x6A, 0x04, 0x45, 0xFF
vertex     80,     58,    105,  -1022,    196,  0x22, 0x3F, 0x68, 0xFF
vertex     82,      0,    120,   -880,    168,  0x2E, 0x05, 0x76, 0xFF
vertex     80,    -57,    105,  -1022,    196,  0x1D, 0xBE, 0x67, 0xFF
vertex    143,    -64,     69,  -1380,   -440,  0x4A, 0xB4, 0x44, 0xFF
vertex     80,    -97,     52,  -1560,    196,  0x1C, 0x96, 0x3F, 0xFF
vertex    156,    -67,      0,  -2074,   -572,  0x6E, 0xC1, 0x00, 0xFF
vertex     82,   -109,      0,  -2074,    168,  0x2C, 0x8A, 0x05, 0xFF
vertex    143,    -64,    -68,  -2768,   -440,  0x4B, 0xAC, 0xC6, 0xFF
vertex     80,    -97,    -51,  -2588,    196,  0x20, 0x91, 0xCE, 0xFF
vertex     80,    -57,   -104,  -3126,    196,  0x24, 0xC1, 0x99, 0xFF
vertex    143,     65,     69,  -1380,   -440,  0x4D, 0x51, 0x3A, 0xFF
vertex    177,      0,      0,  -2074,   -774,  0x7E, 0x00, 0x00, 0xFF

goomba_seg8_vertex_0801B138: # 0x0801B138
vertex    156,      0,     74,  -1340,   -572,  0x6A, 0x04, 0x45, 0xFF
vertex    156,     68,      0,  -2074,   -572,  0x6E, 0x3E, 0x00, 0xFF
vertex    143,     65,     69,  -1380,   -440,  0x4D, 0x51, 0x3A, 0xFF
vertex    177,      0,      0,  -2074,   -774,  0x7E, 0x00, 0x00, 0xFF
vertex    156,      0,    -73,  -2808,   -572,  0x6A, 0xFC, 0xBB, 0xFF
vertex     80,    -57,   -104,  -3126,    196,  0x24, 0xC1, 0x99, 0xFF
vertex     82,      0,   -119,  -3268,    168,  0x29, 0x03, 0x89, 0xFF
vertex     80,     58,   -104,  -3126,    196,  0x1F, 0x40, 0x97, 0xFF
vertex    143,     65,    -68,  -2768,   -440,  0x4C, 0x49, 0xBB, 0xFF
vertex    143,    -64,    -68,  -2768,   -440,  0x4B, 0xAC, 0xC6, 0xFF
vertex    156,    -67,      0,  -2074,   -572,  0x6E, 0xC1, 0x00, 0xFF
vertex     82,   -109,      0,  -2074,    168,  0x2C, 0x8A, 0x05, 0xFF
vertex     80,    -97,    -51,  -2588,    196,  0x20, 0x91, 0xCE, 0xFF
vertex    -51,     49,     53,  -1544,   1510,  0x85, 0x1A, 0x10, 0xFF
vertex    -23,    109,    -58,  -2666,   1230,  0xBD, 0x65, 0xDC, 0xFF
vertex    -51,     49,    -52,  -2604,   1510,  0x87, 0x14, 0xE3, 0xFF

goomba_seg8_vertex_0801B238: # 0x0801B238
vertex    143,     65,    -68,     62,    -70,  0x4C, 0x49, 0xBB, 0xFF
vertex     80,     98,    -61,    108,    346,  0x19, 0x6A, 0xC1, 0xFF
vertex     82,    110,      0,    482,    330,  0x2D, 0x76, 0xF9, 0xFF
vertex    -51,     49,     53,  -1544,   1510,  0x85, 0x1A, 0x10, 0xFF
vertex    -51,    -48,    -52,  -2604,   1510,  0x85, 0xE8, 0xF0, 0xFF
vertex    -51,    -48,     53,  -1544,   1510,  0x87, 0xEE, 0x1E, 0xFF
vertex    -51,     49,    -52,  -2604,   1510,  0x87, 0x14, 0xE3, 0xFF
vertex    -23,     55,   -117,   -232,    990,  0xD2, 0x39, 0x99, 0xFF
vertex     80,     58,   -104,   -156,    336,  0x1F, 0x40, 0x97, 0xFF
vertex    -23,    109,     59,  -1482,   1230,  0xC7, 0x64, 0x34, 0xFF
vertex    -23,    109,    -58,  -2666,   1230,  0xBD, 0x65, 0xDC, 0xFF

glabel goomba_seg8_dl_0801B2E8 # 0x0801B2E8 - 0x0801B560
gsSPLight goomba_seg8_light_0801AD38, 1
gsSPLight goomba_seg8_light_0801AD30, 2
gsSPVertex goomba_seg8_vertex_0801AD48, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  5,  4, 0x0
gsSP1Triangle  5,  7,  3, 0x0
gsSP1Triangle  5,  6,  8, 0x0
gsSP1Triangle  5,  8,  9, 0x0
gsSP1Triangle  7,  5,  9, 0x0
gsSP1Triangle  3,  7, 10, 0x0
gsSP1Triangle  7,  9, 10, 0x0
gsSP1Triangle  3, 11,  4, 0x0
gsSP1Triangle  3, 10, 12, 0x0
gsSP1Triangle  3, 13, 11, 0x0
gsSP1Triangle  0,  2, 14, 0x0
gsSPVertex goomba_seg8_vertex_0801AE38, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  1,  0, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  1,  4,  2, 0x0
gsSP1Triangle  0,  2,  5, 0x0
gsSP1Triangle  6,  0,  5, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle 10,  9,  8, 0x0
gsSP1Triangle  9, 11,  7, 0x0
gsSP1Triangle 12,  9, 13, 0x0
gsSP1Triangle 12, 11,  9, 0x0
gsSP1Triangle  7, 11, 12, 0x0
gsSP1Triangle 14,  2, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801AF38, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  0,  4,  5, 0x0
gsSP1Triangle  5,  3,  0, 0x0
gsSP1Triangle  3,  6,  7, 0x0
gsSP1Triangle  1,  3,  7, 0x0
gsSP1Triangle  5,  8,  3, 0x0
gsSP1Triangle  6,  3,  8, 0x0
gsSP1Triangle  7,  6,  9, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle  7,  9, 10, 0x0
gsSP1Triangle  1,  7, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801B038, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  5,  6,  7, 0x0
gsSP1Triangle  5,  7,  3, 0x0
gsSP1Triangle  6,  8,  7, 0x0
gsSP1Triangle  9,  3,  7, 0x0
gsSP1Triangle  7, 10,  9, 0x0
gsSP1Triangle  7,  8, 10, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle  3, 14,  4, 0x0
gsSP1Triangle  9, 15,  3, 0x0
gsSPVertex goomba_seg8_vertex_0801B138, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  4, 0x0
gsSP1Triangle  1,  4,  8, 0x0
gsSP1Triangle  4,  9,  5, 0x0
gsSP1Triangle  4, 10,  9, 0x0
gsSP1Triangle  1,  3,  4, 0x0
gsSP1Triangle  4,  3, 10, 0x0
gsSP1Triangle 11,  9, 10, 0x0
gsSP1Triangle 11, 12,  9, 0x0
gsSP1Triangle 13, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801B238, 11, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  6,  4, 0x0
gsSP1Triangle  7,  1,  8, 0x0
gsSP1Triangle  8,  1,  0, 0x0
gsSP1Triangle  3,  9, 10, 0x0
gsSPEndDisplayList

glabel goomba_seg8_dl_0801B560 # 0x0801B560 - 0x0801B5A0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPEndDisplayList

glabel goomba_seg8_dl_0801B5A0 # 0x0801B5A0 - 0x0801B5C8
gsSPDisplayList goomba_seg8_dl_0801B2E8
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

glabel goomba_seg8_dl_0801B5C8 # 0x0801B5C8 - 0x0801B5F0
gsSPDisplayList goomba_seg8_dl_0801B560
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, goomba_seg8_texture_08019D30
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPBranchList goomba_seg8_dl_0801B5A0

glabel goomba_seg8_dl_0801B5F0 # 0x0801B5F0 - 0x0801B618
gsSPDisplayList goomba_seg8_dl_0801B560
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, goomba_seg8_texture_0801A530
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPBranchList goomba_seg8_dl_0801B5A0

goomba_seg8_vertex_0801B618: # 0x0801B618
vertex     18,     18,      0,    990,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -18,     18,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -18,    -18,      0,      0,    990,  0xFF, 0xFF, 0xFF, 0xFF
vertex     18,    -18,      0,    990,    990,  0xFF, 0xFF, 0xFF, 0xFF

glabel goomba_seg8_dl_0801B658 # 0x0801B658 - 0x0801B690
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, goomba_seg8_texture_08019530
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex goomba_seg8_vertex_0801B618, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel goomba_seg8_dl_0801B690 # 0x0801B690 - 0x0801B700
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPClearGeometryMode G_LIGHTING
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList goomba_seg8_dl_0801B658
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList

goomba_seg8_vertex_0801B700: # 0x0801B700
vertex     90,     14,    -14,      0,      0,  0x6C, 0xDF, 0xC8, 0x00
vertex     90,     14,     29,      0,      0,  0x6C, 0xDF, 0x38, 0x00
vertex     85,     -4,     29,      0,      0,  0x5D, 0xB8, 0x2D, 0x00
vertex     85,     -4,    -14,      0,      0,  0x5D, 0xB8, 0xD3, 0xFF
vertex    -30,     14,     21,      0,      0,  0x95, 0xD4, 0x33, 0xFF
vertex    -30,     14,     -7,      0,      0,  0x95, 0xD4, 0xCD, 0xFF
vertex    -25,      0,     -4,      0,      0,  0xAD, 0xA9, 0xDA, 0xFF
vertex    -25,      0,     19,      0,      0,  0xAD, 0xA9, 0x26, 0xFF
vertex     66,    -17,    -14,      0,      0,  0x1E, 0x88, 0xE5, 0xFF
vertex     66,    -17,     29,      0,      0,  0x1E, 0x88, 0x1B, 0xFF
vertex      4,    -12,     26,      0,      0,  0xE1, 0x87, 0x16, 0xFF
vertex      4,    -12,    -11,      0,      0,  0xE1, 0x87, 0xEA, 0xFF
vertex     60,     14,     51,      0,      0,  0x1F, 0xE1, 0x76, 0xFF
vertex      0,     11,     45,      0,      0,  0xD3, 0xDA, 0x6F, 0xFF
vertex      2,     -6,     39,      0,      0,  0xD5, 0xAC, 0x54, 0xFF
vertex     60,    -12,     44,      0,      0,  0x20, 0xB2, 0x5E, 0xFF

goomba_seg8_vertex_0801B800: # 0x0801B800
vertex      0,     11,    -30,      0,      0,  0xD3, 0xDA, 0x91, 0xFF
vertex     60,     14,    -37,      0,      0,  0x1F, 0xE1, 0x8A, 0x00
vertex     60,    -12,    -30,      0,      0,  0x20, 0xB2, 0xA2, 0x00
vertex      2,     -6,    -25,      0,      0,  0xD5, 0xAC, 0xAC, 0xFF
vertex      4,    -12,    -11,      0,      0,  0xE1, 0x87, 0xEA, 0xFF
vertex    -25,      0,     -4,      0,      0,  0xAD, 0xA9, 0xDA, 0xFF
vertex      2,     -6,     39,      0,      0,  0xD5, 0xAC, 0x54, 0xFF
vertex    -25,      0,     19,      0,      0,  0xAD, 0xA9, 0x26, 0xFF
vertex      4,    -12,     26,      0,      0,  0xE1, 0x87, 0x16, 0xFF
vertex     66,    -17,     29,      0,      0,  0x1E, 0x88, 0x1B, 0xFF
vertex     85,     -4,     29,      0,      0,  0x5D, 0xB8, 0x2D, 0xFF
vertex     60,    -12,     44,      0,      0,  0x20, 0xB2, 0x5E, 0xFF
vertex     85,     -4,    -14,      0,      0,  0x5D, 0xB8, 0xD3, 0xFF
vertex     66,    -17,    -14,      0,      0,  0x1E, 0x88, 0xE5, 0xFF
vertex    -30,     14,     -7,      0,      0,  0x95, 0xD4, 0xCD, 0xFF

goomba_seg8_vertex_0801B8F0: # 0x0801B8F0
vertex      0,     11,     45,      0,      0,  0xD3, 0xDA, 0x6F, 0xFF
vertex    -30,     14,     21,      0,      0,  0x95, 0xD4, 0x33, 0x00
vertex    -25,      0,     19,      0,      0,  0xAD, 0xA9, 0x26, 0x00
vertex      2,     -6,     39,      0,      0,  0xD5, 0xAC, 0x54, 0xFF
vertex     60,    -12,     44,      0,      0,  0x20, 0xB2, 0x5E, 0xFF
vertex     85,     -4,     29,      0,      0,  0x5D, 0xB8, 0x2D, 0xFF
vertex     90,     14,     29,      0,      0,  0x6C, 0xDF, 0x38, 0xFF
vertex     60,     14,     51,      0,      0,  0x1F, 0xE1, 0x76, 0xFF
vertex     66,    -17,    -14,      0,      0,  0x1E, 0x88, 0xE5, 0xFF
vertex     85,     -4,    -14,      0,      0,  0x5D, 0xB8, 0xD3, 0xFF
vertex     66,    -17,     29,      0,      0,  0x1E, 0x88, 0x1B, 0xFF
vertex     60,     14,    -37,      0,      0,  0x1F, 0xE1, 0x8A, 0xFF
vertex     90,     14,    -14,      0,      0,  0x6C, 0xDF, 0xC8, 0xFF
vertex     60,    -12,    -30,      0,      0,  0x20, 0xB2, 0xA2, 0xFF

goomba_seg8_vertex_0801B9D0: # 0x0801B9D0
vertex    -30,     14,     -7,      0,      0,  0x09, 0x7E, 0x00, 0xFF
vertex    -30,     14,     21,      0,      0,  0x09, 0x7E, 0x00, 0x00
vertex      0,     11,     45,      0,      0,  0x02, 0x7F, 0x00, 0x00
vertex      0,     11,    -30,      0,      0,  0x02, 0x7F, 0x00, 0xFF
vertex     60,     14,     51,      0,      0,  0xFE, 0x7F, 0x00, 0xFF
vertex     90,     14,     29,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex     90,     14,    -14,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex     60,     14,    -37,      0,      0,  0xFE, 0x7F, 0x00, 0xFF

goomba_seg8_vertex_0801BA50: # 0x0801BA50
vertex      0,     11,     30,      0,      0,  0x02, 0x7F, 0x00, 0x00
vertex     60,     14,     37,      0,      0,  0xFE, 0x7F, 0x00, 0x00
vertex     60,     14,    -51,      0,      0,  0xFE, 0x7F, 0x00, 0x00
vertex      0,     11,    -45,      0,      0,  0x02, 0x7F, 0x00, 0xFF
vertex     90,     14,     14,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex     90,     14,    -29,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex    -30,     14,    -21,      0,      0,  0x09, 0x7E, 0x00, 0xFF
vertex    -30,     14,      7,      0,      0,  0x09, 0x7E, 0x00, 0xFF
vertex     60,    -12,     30,      0,      0,  0x20, 0xB2, 0x5E, 0xFF
vertex     85,     -4,     14,      0,      0,  0x5D, 0xB8, 0x2D, 0xFF
vertex     90,     14,     14,      0,      0,  0x6C, 0xDF, 0x38, 0xFF
vertex     60,     14,     37,      0,      0,  0x1F, 0xE1, 0x76, 0xFF
vertex     66,    -17,    -29,      0,      0,  0x1E, 0x88, 0xE5, 0xFF
vertex     85,     -4,    -29,      0,      0,  0x5D, 0xB8, 0xD3, 0xFF
vertex     66,    -17,     14,      0,      0,  0x1E, 0x88, 0x1B, 0xFF

goomba_seg8_vertex_0801BB40: # 0x0801BB40
vertex     60,     14,    -51,      0,      0,  0x1F, 0xE1, 0x8A, 0xFF
vertex     90,     14,    -29,      0,      0,  0x6C, 0xDF, 0xC8, 0x00
vertex     85,     -4,    -29,      0,      0,  0x5D, 0xB8, 0xD3, 0x00
vertex     60,    -12,    -44,      0,      0,  0x20, 0xB2, 0xA2, 0xFF
vertex      2,     -6,    -39,      0,      0,  0xD5, 0xAC, 0xAC, 0xFF
vertex    -25,      0,    -19,      0,      0,  0xAD, 0xA9, 0xDA, 0xFF
vertex    -30,     14,    -21,      0,      0,  0x95, 0xD4, 0xCD, 0xFF
vertex      0,     11,    -45,      0,      0,  0xD3, 0xDA, 0x91, 0xFF
vertex      4,    -12,     11,      0,      0,  0xE1, 0x87, 0x16, 0xFF
vertex    -25,      0,      4,      0,      0,  0xAD, 0xA9, 0x26, 0xFF
vertex      4,    -12,    -26,      0,      0,  0xE1, 0x87, 0xEA, 0xFF
vertex      0,     11,     30,      0,      0,  0xD3, 0xDA, 0x6F, 0xFF
vertex    -30,     14,      7,      0,      0,  0x95, 0xD4, 0x33, 0xFF
vertex      2,     -6,     25,      0,      0,  0xD5, 0xAC, 0x54, 0xFF
vertex     66,    -17,     14,      0,      0,  0x1E, 0x88, 0x1B, 0xFF
vertex     60,    -12,     30,      0,      0,  0x20, 0xB2, 0x5E, 0xFF

goomba_seg8_vertex_0801BC40: # 0x0801BC40
vertex     60,    -12,    -44,      0,      0,  0x20, 0xB2, 0xA2, 0xFF
vertex     66,    -17,    -29,      0,      0,  0x1E, 0x88, 0xE5, 0x00
vertex      4,    -12,    -26,      0,      0,  0xE1, 0x87, 0xEA, 0x00
vertex      2,     -6,    -39,      0,      0,  0xD5, 0xAC, 0xAC, 0xFF
vertex     66,    -17,     14,      0,      0,  0x1E, 0x88, 0x1B, 0xFF
vertex     85,     -4,     14,      0,      0,  0x5D, 0xB8, 0x2D, 0xFF
vertex     60,    -12,     30,      0,      0,  0x20, 0xB2, 0x5E, 0xFF
vertex     85,     -4,    -29,      0,      0,  0x5D, 0xB8, 0xD3, 0xFF
vertex    -25,      0,    -19,      0,      0,  0xAD, 0xA9, 0xDA, 0xFF
vertex      2,     -6,     25,      0,      0,  0xD5, 0xAC, 0x54, 0xFF
vertex    -25,      0,      4,      0,      0,  0xAD, 0xA9, 0x26, 0xFF
vertex      4,    -12,     11,      0,      0,  0xE1, 0x87, 0x16, 0xFF
vertex     60,     14,     37,      0,      0,  0x1F, 0xE1, 0x76, 0xFF
vertex      0,     11,     30,      0,      0,  0xD3, 0xDA, 0x6F, 0xFF
vertex      0,     11,    -45,      0,      0,  0xD3, 0xDA, 0x91, 0xFF
vertex     60,     14,    -51,      0,      0,  0x1F, 0xE1, 0x8A, 0xFF

goomba_seg8_vertex_0801BD40: # 0x0801BD40
vertex    -25,      0,    -19,      0,      0,  0xAD, 0xA9, 0xDA, 0xFF
vertex    -25,      0,      4,      0,      0,  0xAD, 0xA9, 0x26, 0x00
vertex    -30,     14,      7,      0,      0,  0x95, 0xD4, 0x33, 0x00
vertex    -30,     14,    -21,      0,      0,  0x95, 0xD4, 0xCD, 0xFF
vertex     85,     -4,     14,      0,      0,  0x5D, 0xB8, 0x2D, 0xFF
vertex     85,     -4,    -29,      0,      0,  0x5D, 0xB8, 0xD3, 0xFF
vertex     90,     14,    -29,      0,      0,  0x6C, 0xDF, 0xC8, 0xFF
vertex     90,     14,     14,      0,      0,  0x6C, 0xDF, 0x38, 0xFF

goomba_seg8_vertex_0801BDC0: # 0x0801BDC0
vertex    -24,    108,    -74,      0,      0,  0xBD, 0x62, 0xD6, 0x00
vertex     -1,    128,      0,      0,      0,  0xF3, 0x7E, 0x00, 0x00
vertex     81,    109,      0,      0,      0,  0x2A, 0x77, 0x00, 0x00
vertex     79,     97,    -51,      0,      0,  0x22, 0x6C, 0xC8, 0xFF
vertex    -24,   -108,     58,      0,      0,  0xBC, 0x9D, 0x28, 0xFF
vertex     -1,   -128,      0,      0,      0,  0xEF, 0x83, 0x00, 0xFF
vertex     81,   -109,      0,      0,      0,  0x28, 0x88, 0x00, 0xFF
vertex     79,    -97,     61,      0,      0,  0x20, 0x95, 0x3A, 0xFF
vertex    155,     67,      0,      0,      0,  0x63, 0x4F, 0x00, 0xFF
vertex    175,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    155,      0,    -73,      0,      0,  0x65, 0x00, 0xB4, 0xFF
vertex    142,     64,    -68,      0,      0,  0x4D, 0x4B, 0xBE, 0xFF
vertex    -51,    -49,    -52,      0,      0,  0x87, 0xE6, 0xE8, 0xFF
vertex    -51,    -49,     52,      0,      0,  0x87, 0xE6, 0x18, 0xFF
vertex    -51,     49,     52,      0,      0,  0x86, 0x17, 0x19, 0xFF
vertex    -51,     49,    -52,      0,      0,  0x86, 0x17, 0xE7, 0xFF

goomba_seg8_vertex_0801BEC0: # 0x0801BEC0
vertex    -23,     55,    117,      0,      0,  0xBB, 0x2A, 0x61, 0xFF
vertex     -1,      0,    139,      0,      0,  0xED, 0x00, 0x7D, 0x00
vertex     81,      0,    118,      0,      0,  0x2C, 0x00, 0x77, 0x00
vertex     79,     57,    104,      0,      0,  0x23, 0x43, 0x65, 0xFF
vertex    -23,    -55,   -117,      0,      0,  0xBA, 0xD3, 0xA1, 0xFF
vertex     -1,      0,   -139,      0,      0,  0xED, 0x00, 0x83, 0xFF
vertex     81,      0,   -118,      0,      0,  0x2C, 0x00, 0x89, 0xFF
vertex     79,    -57,   -104,      0,      0,  0x21, 0xBF, 0x99, 0xFF
vertex    -24,   -108,    -58,      0,      0,  0xBC, 0x9D, 0xD8, 0xFF
vertex    -51,    -49,    -52,      0,      0,  0x87, 0xE6, 0xE8, 0xFF
vertex    142,    -64,    -68,      0,      0,  0x4F, 0xB8, 0xBD, 0xFF
vertex     79,    -97,    -61,      0,      0,  0x20, 0x95, 0xC6, 0xFF
vertex     79,    -57,    104,      0,      0,  0x21, 0xBF, 0x67, 0xFF
vertex     79,    -97,     61,      0,      0,  0x20, 0x95, 0x3A, 0xFF
vertex    142,    -64,     68,      0,      0,  0x4F, 0xB8, 0x43, 0xFF

goomba_seg8_vertex_0801BFB0: # 0x0801BFB0
vertex    -24,   -108,     58,      0,      0,  0xBC, 0x9D, 0x28, 0xFF
vertex    -23,    -55,    117,      0,      0,  0xBA, 0xD3, 0x5F, 0x00
vertex    -51,    -49,     52,      0,      0,  0x87, 0xE6, 0x18, 0x00
vertex    -23,     55,    117,      0,      0,  0xBB, 0x2A, 0x61, 0xFF
vertex    -24,    108,     74,      0,      0,  0xBD, 0x62, 0x2A, 0xFF
vertex    -51,     49,     52,      0,      0,  0x86, 0x17, 0x19, 0xFF
vertex    142,     64,     68,      0,      0,  0x4D, 0x4B, 0x42, 0xFF
vertex     79,     97,     51,      0,      0,  0x22, 0x6C, 0x38, 0xFF
vertex     79,     57,    104,      0,      0,  0x23, 0x43, 0x65, 0xFF
vertex     79,     57,   -104,      0,      0,  0x23, 0x43, 0x9B, 0xFF
vertex     79,     97,    -51,      0,      0,  0x22, 0x6C, 0xC8, 0xFF
vertex    142,     64,    -68,      0,      0,  0x4D, 0x4B, 0xBE, 0xFF
vertex    -24,    108,    -74,      0,      0,  0xBD, 0x62, 0xD6, 0xFF
vertex    -23,     55,   -117,      0,      0,  0xBB, 0x2A, 0x9F, 0xFF
vertex    -51,     49,    -52,      0,      0,  0x86, 0x17, 0xE7, 0xFF

goomba_seg8_vertex_0801C0A0: # 0x0801C0A0
vertex    -23,    -55,   -117,      0,      0,  0xBA, 0xD3, 0xA1, 0xFF
vertex    -51,    -49,    -52,      0,      0,  0x87, 0xE6, 0xE8, 0x00
vertex    -51,     49,    -52,      0,      0,  0x86, 0x17, 0xE7, 0x00
vertex    -23,     55,   -117,      0,      0,  0xBB, 0x2A, 0x9F, 0xFF
vertex    155,      0,     73,      0,      0,  0x65, 0x00, 0x4C, 0xFF
vertex    142,     64,     68,      0,      0,  0x4D, 0x4B, 0x42, 0xFF
vertex     79,     57,    104,      0,      0,  0x23, 0x43, 0x65, 0xFF
vertex     81,      0,    118,      0,      0,  0x2C, 0x00, 0x77, 0xFF
vertex    155,      0,    -73,      0,      0,  0x65, 0x00, 0xB4, 0xFF
vertex    142,    -64,    -68,      0,      0,  0x4F, 0xB8, 0xBD, 0xFF
vertex     79,    -57,   -104,      0,      0,  0x21, 0xBF, 0x99, 0xFF
vertex     81,      0,   -118,      0,      0,  0x2C, 0x00, 0x89, 0xFF
vertex    -24,   -108,    -58,      0,      0,  0xBC, 0x9D, 0xD8, 0xFF
vertex    -24,   -108,     58,      0,      0,  0xBC, 0x9D, 0x28, 0xFF
vertex    -51,    -49,     52,      0,      0,  0x87, 0xE6, 0x18, 0xFF
vertex     79,    -97,    -61,      0,      0,  0x20, 0x95, 0xC6, 0xFF

goomba_seg8_vertex_0801C1A0: # 0x0801C1A0
vertex    142,    -64,     68,      0,      0,  0x4F, 0xB8, 0x43, 0xFF
vertex     79,    -97,     61,      0,      0,  0x20, 0x95, 0x3A, 0x00
vertex     81,   -109,      0,      0,      0,  0x28, 0x88, 0x00, 0x00
vertex    155,    -67,      0,      0,      0,  0x63, 0xB2, 0x00, 0xFF
vertex    -23,    -55,    117,      0,      0,  0xBA, 0xD3, 0x5F, 0xFF
vertex    -24,   -108,     58,      0,      0,  0xBC, 0x9D, 0x28, 0xFF
vertex     79,    -57,    104,      0,      0,  0x21, 0xBF, 0x67, 0xFF
vertex    -51,     49,     52,      0,      0,  0x86, 0x17, 0x19, 0xFF
vertex    -24,    108,     74,      0,      0,  0xBD, 0x62, 0x2A, 0xFF
vertex    -24,    108,    -74,      0,      0,  0xBD, 0x62, 0xD6, 0xFF
vertex    -51,     49,    -52,      0,      0,  0x86, 0x17, 0xE7, 0xFF
vertex     79,     57,    104,      0,      0,  0x23, 0x43, 0x65, 0xFF
vertex     79,     97,     51,      0,      0,  0x22, 0x6C, 0x38, 0xFF
vertex    -23,     55,    117,      0,      0,  0xBB, 0x2A, 0x61, 0xFF

goomba_seg8_vertex_0801C280: # 0x0801C280
vertex    142,     64,    -68,      0,      0,  0x4D, 0x4B, 0xBE, 0xFF
vertex     79,     97,    -51,      0,      0,  0x22, 0x6C, 0xC8, 0x00
vertex     81,    109,      0,      0,      0,  0x2A, 0x77, 0x00, 0x00
vertex    155,     67,      0,      0,      0,  0x63, 0x4F, 0x00, 0xFF
vertex    -23,     55,   -117,      0,      0,  0xBB, 0x2A, 0x9F, 0xFF
vertex    -24,    108,    -74,      0,      0,  0xBD, 0x62, 0xD6, 0xFF
vertex     79,     57,   -104,      0,      0,  0x23, 0x43, 0x9B, 0xFF
vertex     -1,   -128,      0,      0,      0,  0xEF, 0x83, 0x00, 0xFF
vertex    -24,   -108,    -58,      0,      0,  0xBC, 0x9D, 0xD8, 0xFF
vertex     79,    -97,    -61,      0,      0,  0x20, 0x95, 0xC6, 0xFF
vertex     81,   -109,      0,      0,      0,  0x28, 0x88, 0x00, 0xFF
vertex     -1,    128,      0,      0,      0,  0xF3, 0x7E, 0x00, 0xFF
vertex    -24,    108,     74,      0,      0,  0xBD, 0x62, 0x2A, 0xFF
vertex     79,     97,     51,      0,      0,  0x22, 0x6C, 0x38, 0xFF

goomba_seg8_vertex_0801C360: # 0x0801C360
vertex     81,      0,    118,      0,      0,  0x2C, 0x00, 0x77, 0xFF
vertex     -1,      0,    139,      0,      0,  0xED, 0x00, 0x7D, 0x00
vertex    -23,    -55,    117,      0,      0,  0xBA, 0xD3, 0x5F, 0x00
vertex     79,    -57,    104,      0,      0,  0x21, 0xBF, 0x67, 0xFF
vertex     -1,      0,   -139,      0,      0,  0xED, 0x00, 0x83, 0xFF
vertex    -23,     55,   -117,      0,      0,  0xBB, 0x2A, 0x9F, 0xFF
vertex     79,     57,   -104,      0,      0,  0x23, 0x43, 0x9B, 0xFF
vertex     81,      0,   -118,      0,      0,  0x2C, 0x00, 0x89, 0xFF
vertex    155,      0,    -73,      0,      0,  0x65, 0x00, 0xB4, 0xFF
vertex    175,      0,      0,      0,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    155,    -67,      0,      0,      0,  0x63, 0xB2, 0x00, 0xFF
vertex    142,    -64,    -68,      0,      0,  0x4F, 0xB8, 0xBD, 0xFF
vertex    155,      0,     73,      0,      0,  0x65, 0x00, 0x4C, 0xFF
vertex    142,    -64,     68,      0,      0,  0x4F, 0xB8, 0x43, 0xFF
vertex    155,     67,      0,      0,      0,  0x63, 0x4F, 0x00, 0xFF
vertex    142,     64,     68,      0,      0,  0x4D, 0x4B, 0x42, 0xFF

goomba_seg8_vertex_0801C460: # 0x0801C460
vertex     81,    109,      0,      0,      0,  0x2A, 0x77, 0x00, 0xFF
vertex     79,     97,     51,      0,      0,  0x22, 0x6C, 0x38, 0x00
vertex    142,     64,     68,      0,      0,  0x4D, 0x4B, 0x42, 0x00
vertex    155,     67,      0,      0,      0,  0x63, 0x4F, 0x00, 0xFF
vertex     81,      0,    118,      0,      0,  0x2C, 0x00, 0x77, 0xFF
vertex     79,    -57,    104,      0,      0,  0x21, 0xBF, 0x67, 0xFF
vertex    142,    -64,     68,      0,      0,  0x4F, 0xB8, 0x43, 0xFF
vertex    155,      0,     73,      0,      0,  0x65, 0x00, 0x4C, 0xFF
vertex     81,      0,   -118,      0,      0,  0x2C, 0x00, 0x89, 0xFF
vertex     79,     57,   -104,      0,      0,  0x23, 0x43, 0x9B, 0xFF
vertex    142,     64,    -68,      0,      0,  0x4D, 0x4B, 0xBE, 0xFF
vertex    155,      0,    -73,      0,      0,  0x65, 0x00, 0xB4, 0xFF
vertex     81,   -109,      0,      0,      0,  0x28, 0x88, 0x00, 0xFF
vertex     79,    -97,    -61,      0,      0,  0x20, 0x95, 0xC6, 0xFF
vertex    142,    -64,    -68,      0,      0,  0x4F, 0xB8, 0xBD, 0xFF
vertex    155,    -67,      0,      0,      0,  0x63, 0xB2, 0x00, 0xFF

goomba_seg8_vertex_0801C560: # 0x0801C560
vertex    -24,    108,     74,      0,      0,  0xBD, 0x62, 0x2A, 0xFF
vertex     -1,    128,      0,      0,      0,  0xF3, 0x7E, 0x00, 0x00
vertex    -24,    108,    -74,      0,      0,  0xBD, 0x62, 0xD6, 0x00
vertex    -23,    -55,    117,      0,      0,  0xBA, 0xD3, 0x5F, 0xFF
vertex     -1,      0,    139,      0,      0,  0xED, 0x00, 0x7D, 0xFF
vertex    -23,     55,    117,      0,      0,  0xBB, 0x2A, 0x61, 0xFF
vertex    -24,   -108,    -58,      0,      0,  0xBC, 0x9D, 0xD8, 0xFF
vertex     -1,   -128,      0,      0,      0,  0xEF, 0x83, 0x00, 0xFF
vertex    -24,   -108,     58,      0,      0,  0xBC, 0x9D, 0x28, 0xFF
vertex    -23,     55,   -117,      0,      0,  0xBB, 0x2A, 0x9F, 0xFF
vertex     -1,      0,   -139,      0,      0,  0xED, 0x00, 0x83, 0xFF
vertex    -23,    -55,   -117,      0,      0,  0xBA, 0xD3, 0xA1, 0xFF

goomba_seg8_vertex_0801C620: # 0x0801C620
vertex     48,     47,      0,      0,      0,  0x5A, 0x59, 0x00, 0x00
vertex     48,     38,     27,      0,      0,  0x5A, 0x48, 0x34, 0x00
vertex     65,     14,     10,      0,      0,  0x77, 0x23, 0x19, 0x00
vertex     65,     17,      0,      0,      0,  0x77, 0x2B, 0x00, 0xFF
vertex     18,     64,      0,      0,      0,  0x21, 0x7A, 0x00, 0xFF
vertex     18,     52,     38,      0,      0,  0x21, 0x63, 0x48, 0xFF
vertex    -16,     64,      0,      0,      0,  0xDF, 0x7A, 0x00, 0xFF
vertex    -16,     52,     38,      0,      0,  0xDF, 0x63, 0x48, 0xFF
vertex    -46,     47,      0,      0,      0,  0xA6, 0x59, 0x00, 0xFF
vertex    -46,     38,     27,      0,      0,  0xA6, 0x48, 0x34, 0xFF
vertex    -63,     17,      0,      0,      0,  0x89, 0x2B, 0x00, 0xFF
vertex    -63,     14,     10,      0,      0,  0x89, 0x23, 0x19, 0xFF
vertex     48,     14,     45,      0,      0,  0x5A, 0x1B, 0x55, 0xFF
vertex     65,      5,     16,      0,      0,  0x77, 0x0D, 0x29, 0xFF
vertex     18,     20,     61,      0,      0,  0x21, 0x25, 0x74, 0xFF
vertex    -16,     20,     61,      0,      0,  0xDF, 0x25, 0x74, 0xFF

goomba_seg8_vertex_0801C720: # 0x0801C720
vertex    -46,     38,     27,      0,      0,  0xA6, 0x48, 0x34, 0xFF
vertex    -46,     14,     45,      0,      0,  0xA6, 0x1B, 0x55, 0x00
vertex    -16,     20,     61,      0,      0,  0xDF, 0x25, 0x74, 0x00
vertex    -16,     52,     38,      0,      0,  0xDF, 0x63, 0x48, 0xFF
vertex    -63,     14,     10,      0,      0,  0x89, 0x23, 0x19, 0xFF
vertex    -63,      5,     16,      0,      0,  0x89, 0x0D, 0x29, 0xFF
vertex     48,     14,     45,      0,      0,  0x5A, 0x1B, 0x55, 0xFF
vertex     48,    -14,     45,      0,      0,  0x5A, 0xE5, 0x55, 0xFF
vertex     65,     -5,     16,      0,      0,  0x77, 0xF3, 0x29, 0xFF
vertex     65,      5,     16,      0,      0,  0x77, 0x0D, 0x29, 0xFF
vertex     18,     20,     61,      0,      0,  0x21, 0x25, 0x74, 0xFF
vertex     18,    -20,     61,      0,      0,  0x21, 0xDB, 0x74, 0xFF
vertex    -16,    -20,     61,      0,      0,  0xDF, 0xDB, 0x74, 0xFF
vertex    -46,    -14,     45,      0,      0,  0xA6, 0xE5, 0x55, 0xFF
vertex    -63,     -5,     16,      0,      0,  0x89, 0xF3, 0x29, 0xFF

goomba_seg8_vertex_0801C810: # 0x0801C810
vertex     48,    -14,     45,      0,      0,  0x5A, 0xE5, 0x55, 0xFF
vertex     48,    -38,     27,      0,      0,  0x5A, 0xB8, 0x34, 0x00
vertex     65,    -14,     10,      0,      0,  0x77, 0xDD, 0x19, 0x00
vertex     65,     -5,     16,      0,      0,  0x77, 0xF3, 0x29, 0xFF
vertex     18,    -20,     61,      0,      0,  0x21, 0xDB, 0x74, 0xFF
vertex     18,    -52,     38,      0,      0,  0x21, 0x9D, 0x48, 0xFF
vertex    -16,    -20,     61,      0,      0,  0xDF, 0xDB, 0x74, 0xFF
vertex    -16,    -52,     38,      0,      0,  0xDF, 0x9D, 0x48, 0xFF
vertex    -46,    -14,     45,      0,      0,  0xA6, 0xE5, 0x55, 0xFF
vertex    -46,    -38,     27,      0,      0,  0xA6, 0xB8, 0x34, 0xFF
vertex    -63,     -5,     16,      0,      0,  0x89, 0xF3, 0x29, 0xFF
vertex    -63,    -14,     10,      0,      0,  0x89, 0xDD, 0x19, 0xFF
vertex     48,    -47,      0,      0,      0,  0x5A, 0xA7, 0x00, 0xFF
vertex     65,    -17,      0,      0,      0,  0x77, 0xD5, 0x00, 0xFF
vertex     18,    -64,      0,      0,      0,  0x21, 0x86, 0x00, 0xFF
vertex    -16,    -64,      0,      0,      0,  0xDF, 0x86, 0x00, 0xFF

goomba_seg8_vertex_0801C910: # 0x0801C910
vertex    -46,    -38,     27,      0,      0,  0xA6, 0xB8, 0x34, 0xFF
vertex    -46,    -47,      0,      0,      0,  0xA6, 0xA7, 0x00, 0x00
vertex    -16,    -64,      0,      0,      0,  0xDF, 0x86, 0x00, 0x00
vertex    -16,    -52,     38,      0,      0,  0xDF, 0x9D, 0x48, 0xFF
vertex    -63,    -14,     10,      0,      0,  0x89, 0xDD, 0x19, 0xFF
vertex    -63,    -17,      0,      0,      0,  0x89, 0xD5, 0x00, 0xFF
vertex     48,    -47,      0,      0,      0,  0x5A, 0xA7, 0x00, 0xFF
vertex     48,    -38,    -27,      0,      0,  0x5A, 0xB8, 0xCC, 0xFF
vertex     65,    -14,    -10,      0,      0,  0x77, 0xDD, 0xE7, 0xFF
vertex     65,    -17,      0,      0,      0,  0x77, 0xD5, 0x00, 0xFF
vertex     18,    -64,      0,      0,      0,  0x21, 0x86, 0x00, 0xFF
vertex     18,    -52,    -38,      0,      0,  0x21, 0x9D, 0xB8, 0xFF
vertex    -16,    -52,    -38,      0,      0,  0xDF, 0x9D, 0xB8, 0xFF
vertex    -46,    -38,    -27,      0,      0,  0xA6, 0xB8, 0xCC, 0xFF
vertex    -63,    -14,    -10,      0,      0,  0x89, 0xDD, 0xE7, 0xFF

goomba_seg8_vertex_0801CA00: # 0x0801CA00
vertex     48,    -38,    -27,      0,      0,  0x5A, 0xB8, 0xCC, 0xFF
vertex     48,    -14,    -45,      0,      0,  0x5A, 0xE5, 0xAB, 0x00
vertex     65,     -5,    -16,      0,      0,  0x77, 0xF3, 0xD7, 0x00
vertex     65,    -14,    -10,      0,      0,  0x77, 0xDD, 0xE7, 0xFF
vertex     18,    -52,    -38,      0,      0,  0x21, 0x9D, 0xB8, 0xFF
vertex     18,    -20,    -61,      0,      0,  0x21, 0xDB, 0x8C, 0xFF
vertex    -16,    -52,    -38,      0,      0,  0xDF, 0x9D, 0xB8, 0xFF
vertex    -16,    -20,    -61,      0,      0,  0xDF, 0xDB, 0x8C, 0xFF
vertex    -46,    -38,    -27,      0,      0,  0xA6, 0xB8, 0xCC, 0xFF
vertex    -46,    -14,    -45,      0,      0,  0xA6, 0xE5, 0xAB, 0xFF
vertex    -63,    -14,    -10,      0,      0,  0x89, 0xDD, 0xE7, 0xFF
vertex    -63,     -5,    -16,      0,      0,  0x89, 0xF3, 0xD7, 0xFF
vertex     48,     14,    -45,      0,      0,  0x5A, 0x1B, 0xAB, 0xFF
vertex     65,      5,    -16,      0,      0,  0x77, 0x0D, 0xD7, 0xFF
vertex     18,     20,    -61,      0,      0,  0x21, 0x25, 0x8C, 0xFF
vertex    -16,     20,    -61,      0,      0,  0xDF, 0x25, 0x8C, 0xFF

goomba_seg8_vertex_0801CB00: # 0x0801CB00
vertex    -46,    -14,    -45,      0,      0,  0xA6, 0xE5, 0xAB, 0xFF
vertex    -46,     14,    -45,      0,      0,  0xA6, 0x1B, 0xAB, 0x00
vertex    -16,     20,    -61,      0,      0,  0xDF, 0x25, 0x8C, 0x00
vertex    -16,    -20,    -61,      0,      0,  0xDF, 0xDB, 0x8C, 0xFF
vertex    -63,     -5,    -16,      0,      0,  0x89, 0xF3, 0xD7, 0xFF
vertex    -63,      5,    -16,      0,      0,  0x89, 0x0D, 0xD7, 0xFF
vertex     48,     14,    -45,      0,      0,  0x5A, 0x1B, 0xAB, 0xFF
vertex     48,     38,    -27,      0,      0,  0x5A, 0x48, 0xCC, 0xFF
vertex     65,     14,    -10,      0,      0,  0x77, 0x23, 0xE7, 0xFF
vertex     65,      5,    -16,      0,      0,  0x77, 0x0D, 0xD7, 0xFF
vertex     18,     20,    -61,      0,      0,  0x21, 0x25, 0x8C, 0xFF
vertex     18,     52,    -38,      0,      0,  0x21, 0x63, 0xB8, 0xFF
vertex    -16,     52,    -38,      0,      0,  0xDF, 0x63, 0xB8, 0xFF
vertex    -46,     38,    -27,      0,      0,  0xA6, 0x48, 0xCC, 0xFF
vertex    -63,     14,    -10,      0,      0,  0x89, 0x23, 0xE7, 0xFF

goomba_seg8_vertex_0801CBF0: # 0x0801CBF0
vertex     48,     38,    -27,      0,      0,  0x5A, 0x48, 0xCC, 0xFF
vertex     48,     47,      0,      0,      0,  0x5A, 0x59, 0x00, 0x00
vertex     65,     17,      0,      0,      0,  0x77, 0x2B, 0x00, 0x00
vertex     65,     14,    -10,      0,      0,  0x77, 0x23, 0xE7, 0xFF
vertex     18,     52,    -38,      0,      0,  0x21, 0x63, 0xB8, 0xFF
vertex     18,     64,      0,      0,      0,  0x21, 0x7A, 0x00, 0xFF
vertex    -16,     52,    -38,      0,      0,  0xDF, 0x63, 0xB8, 0xFF
vertex    -16,     64,      0,      0,      0,  0xDF, 0x7A, 0x00, 0xFF
vertex    -46,     38,    -27,      0,      0,  0xA6, 0x48, 0xCC, 0xFF
vertex    -46,     47,      0,      0,      0,  0xA6, 0x59, 0x00, 0xFF
vertex    -63,     14,    -10,      0,      0,  0x89, 0x23, 0xE7, 0xFF
vertex    -63,     17,      0,      0,      0,  0x89, 0x2B, 0x00, 0xFF
vertex     65,     14,     10,      0,      0,  0x77, 0x23, 0x19, 0xFF
vertex     65,      5,     16,      0,      0,  0x77, 0x0D, 0x29, 0xFF
vertex     65,     -5,     16,      0,      0,  0x77, 0xF3, 0x29, 0xFF
vertex     65,    -14,     10,      0,      0,  0x77, 0xDD, 0x19, 0xFF

goomba_seg8_vertex_0801CCF0: # 0x0801CCF0
vertex     65,     17,      0,      0,      0,  0x77, 0x2B, 0x00, 0xFF
vertex     65,    -14,     10,      0,      0,  0x77, 0xDD, 0x19, 0x00
vertex     65,    -17,      0,      0,      0,  0x77, 0xD5, 0x00, 0x00
vertex     65,    -14,    -10,      0,      0,  0x77, 0xDD, 0xE7, 0xFF
vertex     65,     -5,    -16,      0,      0,  0x77, 0xF3, 0xD7, 0xFF
vertex     65,      5,    -16,      0,      0,  0x77, 0x0D, 0xD7, 0xFF
vertex     65,     14,    -10,      0,      0,  0x77, 0x23, 0xE7, 0xFF
vertex    -63,     17,      0,      0,      0,  0x89, 0x2B, 0x00, 0xFF
vertex    -63,     14,    -10,      0,      0,  0x89, 0x23, 0xE7, 0xFF
vertex    -63,      5,    -16,      0,      0,  0x89, 0x0D, 0xD7, 0xFF
vertex    -63,     -5,    -16,      0,      0,  0x89, 0xF3, 0xD7, 0xFF
vertex    -63,    -14,    -10,      0,      0,  0x89, 0xDD, 0xE7, 0xFF
vertex    -63,    -17,      0,      0,      0,  0x89, 0xD5, 0x00, 0xFF
vertex    -63,    -14,     10,      0,      0,  0x89, 0xDD, 0x19, 0xFF
vertex    -63,     -5,     16,      0,      0,  0x89, 0xF3, 0x29, 0xFF
vertex    -63,      5,     16,      0,      0,  0x89, 0x0D, 0x29, 0xFF

goomba_seg8_vertex_0801CDF0: # 0x0801CDF0
vertex    -63,     17,      0,      0,      0,  0x89, 0x2B, 0x00, 0xFF
vertex    -63,      5,     16,      0,      0,  0x89, 0x0D, 0x29, 0x00
vertex    -63,     14,     10,      0,      0,  0x89, 0x23, 0x19, 0x00

glabel goomba_seg8_dl_0801CE20 # 0x0801CE20 - 0x0801CF78
gsSPLight goomba_seg8_light_080194D8, 1
gsSPLight goomba_seg8_light_080194D0, 2
gsSPVertex goomba_seg8_vertex_0801B700, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801B800, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  3, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle  2, 12, 13, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle  6,  9, 11, 0x0
gsSP1Triangle  2, 13,  4, 0x0
gsSP1Triangle  2,  4,  3, 0x0
gsSP1Triangle  3,  5, 14, 0x0
gsSP1Triangle  3, 14,  0, 0x0
gsSP1Triangle  8,  7,  5, 0x0
gsSP1Triangle  8,  5,  4, 0x0
gsSPVertex goomba_seg8_vertex_0801B8F0, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9,  5, 0x0
gsSP1Triangle  8,  5, 10, 0x0
gsSP1Triangle 11, 12,  9, 0x0
gsSP1Triangle 11,  9, 13, 0x0
gsSPVertex goomba_seg8_vertex_0801B9D0, 8, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  2,  4,  7, 0x0
gsSP1Triangle  2,  7,  3, 0x0
gsSPEndDisplayList

glabel goomba_seg8_dl_0801CF78 # 0x0801CF78 - 0x0801D0D0
gsSPLight goomba_seg8_light_080194F0, 1
gsSPLight goomba_seg8_light_080194E8, 2
gsSPVertex goomba_seg8_vertex_0801BA50, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  1,  4,  5, 0x0
gsSP1Triangle  1,  5,  2, 0x0
gsSP1Triangle  0,  3,  6, 0x0
gsSP1Triangle  0,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 12, 13,  9, 0x0
gsSP1Triangle 12,  9, 14, 0x0
gsSPVertex goomba_seg8_vertex_0801BB40, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9,  5, 0x0
gsSP1Triangle  8,  5, 10, 0x0
gsSP1Triangle 11, 12,  9, 0x0
gsSP1Triangle 11,  9, 13, 0x0
gsSP1Triangle 13,  8, 14, 0x0
gsSP1Triangle 13, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801BC40, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  0,  7,  1, 0x0
gsSP1Triangle  2,  8,  3, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle  9,  6, 12, 0x0
gsSP1Triangle  9, 12, 13, 0x0
gsSP1Triangle  0,  3, 14, 0x0
gsSP1Triangle  0, 14, 15, 0x0
gsSP1Triangle 11,  2,  1, 0x0
gsSP1Triangle 11,  1,  4, 0x0
gsSPVertex goomba_seg8_vertex_0801BD40, 8, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSPEndDisplayList

glabel goomba_seg8_dl_0801D0D0 # 0x0801D0D0 - 0x0801D360
gsSPLight goomba_seg8_light_08019508, 1
gsSPLight goomba_seg8_light_08019500, 2
gsSPVertex goomba_seg8_vertex_0801BDC0, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801BEC0, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  4,  8,  9, 0x0
gsSP1Triangle 10, 11,  7, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSPVertex goomba_seg8_vertex_0801BFB0, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle  3,  5,  2, 0x0
gsSP1Triangle  3,  2,  1, 0x0
gsSPVertex goomba_seg8_vertex_0801C0A0, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle  1, 12, 13, 0x0
gsSP1Triangle  1, 13, 14, 0x0
gsSP1Triangle 10, 15, 12, 0x0
gsSP1Triangle 10, 12,  0, 0x0
gsSPVertex goomba_seg8_vertex_0801C1A0, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  6, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7,  9, 10, 0x0
gsSP1Triangle 11, 12,  8, 0x0
gsSP1Triangle 11,  8, 13, 0x0
gsSPVertex goomba_seg8_vertex_0801C280, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  6, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7,  9, 10, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 13,  2, 0x0
gsSPVertex goomba_seg8_vertex_0801C360, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 10,  9, 12, 0x0
gsSP1Triangle 10, 12, 13, 0x0
gsSP1Triangle 12,  9, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801C460, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801C560, 12, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  9, 10, 11, 0x0
gsSPEndDisplayList

glabel goomba_seg8_dl_0801D360 # 0x0801D360 - 0x0801D760
gsSPLight goomba_seg8_light_08019520, 1
gsSPLight goomba_seg8_light_08019518, 2
gsSPVertex goomba_seg8_vertex_0801C620, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  5, 0x0
gsSP1Triangle  6,  5,  4, 0x0
gsSP1Triangle  8,  9,  7, 0x0
gsSP1Triangle  8,  7,  6, 0x0
gsSP1Triangle 10, 11,  9, 0x0
gsSP1Triangle 10,  9,  8, 0x0
gsSP1Triangle  1, 12, 13, 0x0
gsSP1Triangle  1, 13,  2, 0x0
gsSP1Triangle  5, 14, 12, 0x0
gsSP1Triangle  5, 12,  1, 0x0
gsSP1Triangle  7, 15, 14, 0x0
gsSP1Triangle  7, 14,  5, 0x0
gsSPVertex goomba_seg8_vertex_0801C720, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle 10, 11,  7, 0x0
gsSP1Triangle 10,  7,  6, 0x0
gsSP1Triangle  2, 12, 11, 0x0
gsSP1Triangle  2, 11, 10, 0x0
gsSP1Triangle  1, 13, 12, 0x0
gsSP1Triangle  1, 12,  2, 0x0
gsSP1Triangle  5, 14, 13, 0x0
gsSP1Triangle  5, 13,  1, 0x0
gsSPVertex goomba_seg8_vertex_0801C810, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  5, 0x0
gsSP1Triangle  6,  5,  4, 0x0
gsSP1Triangle  8,  9,  7, 0x0
gsSP1Triangle  8,  7,  6, 0x0
gsSP1Triangle 10, 11,  9, 0x0
gsSP1Triangle 10,  9,  8, 0x0
gsSP1Triangle  1, 12, 13, 0x0
gsSP1Triangle  1, 13,  2, 0x0
gsSP1Triangle  5, 14, 12, 0x0
gsSP1Triangle  5, 12,  1, 0x0
gsSP1Triangle  7, 15, 14, 0x0
gsSP1Triangle  7, 14,  5, 0x0
gsSPVertex goomba_seg8_vertex_0801C910, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle 10, 11,  7, 0x0
gsSP1Triangle 10,  7,  6, 0x0
gsSP1Triangle  2, 12, 11, 0x0
gsSP1Triangle  2, 11, 10, 0x0
gsSP1Triangle  1, 13, 12, 0x0
gsSP1Triangle  1, 12,  2, 0x0
gsSP1Triangle  5, 14, 13, 0x0
gsSP1Triangle  5, 13,  1, 0x0
gsSPVertex goomba_seg8_vertex_0801CA00, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  5, 0x0
gsSP1Triangle  6,  5,  4, 0x0
gsSP1Triangle  8,  9,  7, 0x0
gsSP1Triangle  8,  7,  6, 0x0
gsSP1Triangle 10, 11,  9, 0x0
gsSP1Triangle 10,  9,  8, 0x0
gsSP1Triangle  1, 12, 13, 0x0
gsSP1Triangle  1, 13,  2, 0x0
gsSP1Triangle  5, 14, 12, 0x0
gsSP1Triangle  5, 12,  1, 0x0
gsSP1Triangle  7, 15, 14, 0x0
gsSP1Triangle  7, 14,  5, 0x0
gsSPVertex goomba_seg8_vertex_0801CB00, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  8, 0x0
gsSP1Triangle  6,  8,  9, 0x0
gsSP1Triangle 10, 11,  7, 0x0
gsSP1Triangle 10,  7,  6, 0x0
gsSP1Triangle  2, 12, 11, 0x0
gsSP1Triangle  2, 11, 10, 0x0
gsSP1Triangle  1, 13, 12, 0x0
gsSP1Triangle  1, 12,  2, 0x0
gsSP1Triangle  5, 14, 13, 0x0
gsSP1Triangle  5, 13,  1, 0x0
gsSPVertex goomba_seg8_vertex_0801CBF0, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  1, 0x0
gsSP1Triangle  4,  1,  0, 0x0
gsSP1Triangle  6,  7,  5, 0x0
gsSP1Triangle  6,  5,  4, 0x0
gsSP1Triangle  8,  9,  7, 0x0
gsSP1Triangle  8,  7,  6, 0x0
gsSP1Triangle 10, 11,  9, 0x0
gsSP1Triangle 10,  9,  8, 0x0
gsSP1Triangle  2, 12, 13, 0x0
gsSP1Triangle  2, 13, 14, 0x0
gsSP1Triangle  2, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801CCF0, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  0,  3,  4, 0x0
gsSP1Triangle  0,  4,  5, 0x0
gsSP1Triangle  0,  5,  6, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7,  9, 10, 0x0
gsSP1Triangle  7, 10, 11, 0x0
gsSP1Triangle  7, 11, 12, 0x0
gsSP1Triangle  7, 12, 13, 0x0
gsSP1Triangle  7, 13, 14, 0x0
gsSP1Triangle  7, 14, 15, 0x0
gsSPVertex goomba_seg8_vertex_0801CDF0, 3, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSPEndDisplayList

glabel goomba_seg8_dl_0801D760 # 0x0801D760 - 0x0801D770
gsMoveWd 0, 2, 0x80000040
gsSPEndDisplayList

goomba_seg8_animvalue_0801D770: # 0x0801D770
.hword 0x0000, 0x005A, 0x0059, 0x0057, 0x0054, 0x0051, 0x004E, 0x004B
.hword 0x0049, 0x004D, 0x0051, 0x0055, 0x0057, 0x0059, 0x005B, 0x005C
.hword 0x005B, 0x0058, 0x0055, 0x0051, 0x004E, 0x004C, 0x004A, 0x0049
.hword 0x004A, 0x004D, 0x0050, 0x0053, 0x0056, 0x0059, 0x005A, 0x3FFF
.hword 0x0000, 0x0007, 0x001B, 0x003B, 0x0063, 0x0092, 0x00C5, 0x00FA
.hword 0x012F, 0x0162, 0x0191, 0x01BA, 0x01D9, 0x01EE, 0x01F5, 0x01E5
.hword 0x01B9, 0x0179, 0x012B, 0x00D8, 0x0086, 0x003D, 0x0005, 0xFFEF
.hword 0xFFF4, 0xFFFB, 0xFFFC, 0xFFFE, 0x0000, 0x0000, 0x0000, 0xFFD2
.hword 0xFF4E, 0xFE84, 0xFD80, 0xFC50, 0xFB02, 0xF9A4, 0xF842, 0xF6EB
.hword 0xF5AC, 0xF493, 0xF3AD, 0xF308, 0xF2B2, 0xF2DD, 0xF39B, 0xF4C9
.hword 0xF643, 0xF7E5, 0xF98B, 0xFB12, 0xFC56, 0xFD4D, 0xFE0E, 0xFEA4
.hword 0xFF26, 0xFF96, 0xFFE3, 0x0000, 0x847D, 0x842C, 0x8349, 0x81EB
.hword 0x802B, 0x7E1D, 0x7BDE, 0x7983, 0x7724, 0x74D8, 0x72B8, 0x70DA
.hword 0x6F57, 0x6E45, 0x6DBE, 0x6E24, 0x6F9E, 0x71E4, 0x74AE, 0x77B4
.hword 0x7AB0, 0x7D58, 0x7F67, 0x8027, 0x7FEA, 0x800A, 0x8125, 0x82A0
.hword 0x83EE, 0x847D, 0x8001, 0x8003, 0x8006, 0x800A, 0x800E, 0x800F
.hword 0x800C, 0x8005, 0x7FED, 0x7FCB, 0x7FA7, 0x7F8D, 0x7F82, 0x7F83
.hword 0x7F91, 0x7FBA, 0x7FF1, 0x8014, 0x801A, 0x801D, 0x801D, 0x801C
.hword 0x8019, 0x8016, 0x8011, 0x800D, 0x8008, 0x8005, 0x8002, 0x8001
.hword 0x74FE, 0x7522, 0x7580, 0x760B, 0x76B1, 0x7762, 0x7810, 0x78A9
.hword 0x793D, 0x79DA, 0x7A6F, 0x7AEA, 0x7B48, 0x7B84, 0x7B88, 0x7B3C
.hword 0x7AB9, 0x7A36, 0x79BE, 0x7938, 0x78A9, 0x7816, 0x7782, 0x76F3
.hword 0x766D, 0x75F6, 0x7590, 0x7542, 0x7510, 0x74FE, 0xEBA0, 0xEC75
.hword 0xEEAC, 0xF1D6, 0xF585, 0xF94B, 0xFCBA, 0xFF64, 0x010E, 0x0203
.hword 0x0296, 0x031D, 0x0394, 0x03C2, 0x03A4, 0x0354, 0x02B8, 0x0184
.hword 0xFFBE, 0xFDAD, 0xFB66, 0xF8FF, 0xF68F, 0xF42C, 0xF1EA, 0xEFE1
.hword 0xEE25, 0xECCD, 0xEBEF, 0xEBA0, 0xC001, 0xC001, 0xF913, 0xF946
.hword 0xF9D2, 0xFAAA, 0xFBBE, 0xFCFF, 0xFE5E, 0xFFCC, 0x013A, 0x0299
.hword 0x03DA, 0x04EE, 0x05C6, 0x0652, 0x0684, 0x0658, 0x05DD, 0x051E
.hword 0x0429, 0x0308, 0x01C9, 0x0077, 0xFF20, 0xFDCF, 0xFC90, 0xFB6F
.hword 0xFA79, 0xF9BB, 0xF93F, 0xF913, 0x061C, 0x05ED, 0x0569, 0x049E
.hword 0x039B, 0x026D, 0x0123, 0xFFCC, 0xFE74, 0xFD2A, 0xFBFD, 0xFAF9
.hword 0xFA2F, 0xF9AB, 0xF97C, 0xF9A5, 0xFA19, 0xFACC, 0xFBB3, 0xFCC2
.hword 0xFDEE, 0xFF2B, 0x006D, 0x01AA, 0x02D6, 0x03E5, 0x04CC, 0x057F
.hword 0x05F3, 0x061C, 0xFC56, 0xFC76, 0xFCCF, 0xFD58, 0xFE08, 0xFED4
.hword 0xFFB4, 0x009C, 0x0185, 0x0265, 0x0331, 0x03E0, 0x046A, 0x04C3
.hword 0x04E3, 0x04C7, 0x0479, 0x03FF, 0x0363, 0x02AB, 0x01E0, 0x0109
.hword 0x002F, 0xFF59, 0xFE8E, 0xFDD6, 0xFD3A, 0xFCC0, 0xFC72, 0xFC56
.hword 0x3FFF, 0x0000

goomba_seg8_animindex_0801D9D4: # 0x0801D9D4
.hword 0x0001, 0x0000, 0x001E, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x001F, 0x0001, 0x0000, 0x001E, 0x00F4, 0x001E, 0x0112
.hword 0x0001, 0x0130, 0x001E, 0x00D6, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x00D5, 0x001E, 0x0020
.hword 0x001E, 0x003E, 0x001E, 0x005C, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x00D4, 0x001E, 0x007A, 0x001E, 0x0098, 0x001E, 0x00B6

goomba_seg8_anim_0801DA34: # 0x0801DA34
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x1E
.hword 0x07
.word goomba_seg8_animvalue_0801D770
.word goomba_seg8_animindex_0801D9D4
.word 0

glabel goomba_seg8_anims_0801DA4C # 0x0801DA4C
.word goomba_seg8_anim_0801DA34
.word 0
.word 0

binid
