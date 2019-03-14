# Metal Box

metal_box_seg8_light_08023980: # 0x08023980
.byte 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x00

metal_box_seg8_light_08023988: # 0x08023988
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

metal_box_seg8_texture_08023998: # 0x08023998
.incbin "actors/metal_box/0.rgba16"

metal_box_seg8_vertex_08024998: # 0x08024998
vertex    154,    307,   -153,    990,      0,  0x00, 0x7F, 0x00, 0xFF
vertex   -153,    307,   -153,      0,      0,  0x00, 0x7F, 0x00, 0xFF
vertex   -153,    307,    154,      0,   2012,  0x00, 0x7F, 0x00, 0xFF
vertex    154,    307,    154,    990,   2012,  0x00, 0x7F, 0x00, 0xFF
vertex   -153,      0,   -153,    990,   2012,  0x00, 0x00, 0x81, 0xFF
vertex   -153,    307,   -153,    990,      0,  0x00, 0x00, 0x81, 0xFF
vertex    154,    307,   -153,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    154,      0,   -153,      0,   2012,  0x00, 0x00, 0x81, 0xFF
vertex   -153,      0,    154,    990,   2012,  0x81, 0x00, 0x00, 0xFF
vertex   -153,    307,    154,    990,      0,  0x81, 0x00, 0x00, 0xFF
vertex   -153,    307,   -153,      0,      0,  0x81, 0x00, 0x00, 0xFF
vertex   -153,      0,   -153,      0,   2012,  0x81, 0x00, 0x00, 0xFF
vertex    154,      0,    154,    990,      0,  0x00, 0x81, 0x00, 0xFF
vertex   -153,      0,    154,      0,      0,  0x00, 0x81, 0x00, 0xFF
vertex   -153,      0,   -153,      0,   2012,  0x00, 0x81, 0x00, 0xFF
vertex    154,      0,   -153,    990,   2012,  0x00, 0x81, 0x00, 0xFF

metal_box_seg8_vertex_08024A98: # 0x08024A98
vertex    154,      0,    154,    990,   2012,  0x00, 0x00, 0x7F, 0xFF
vertex   -153,    307,    154,      0,      0,  0x00, 0x00, 0x7F, 0xFF
vertex   -153,      0,    154,      0,   2012,  0x00, 0x00, 0x7F, 0xFF
vertex    154,    307,    154,    990,      0,  0x00, 0x00, 0x7F, 0xFF
vertex    154,      0,   -153,    990,   2012,  0x7F, 0x00, 0x00, 0xFF
vertex    154,    307,   -153,    990,      0,  0x7F, 0x00, 0x00, 0xFF
vertex    154,    307,    154,    -24,    -36,  0x7F, 0x00, 0x00, 0xFF
vertex    154,      0,    154,    -24,   2008,  0x7F, 0x00, 0x00, 0xFF

glabel metal_box_seg8_dl_08024B18 # 0x08024B18 - 0x08024BB8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, metal_box_seg8_texture_08023998
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSPLight metal_box_seg8_light_08023988, 1
gsSPLight metal_box_seg8_light_08023980, 2
gsSPVertex metal_box_seg8_vertex_08024998, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 10, 11, 0x0
gsSP1Triangle 12, 13, 14, 0x0
gsSP1Triangle 12, 14, 15, 0x0
gsSPVertex metal_box_seg8_vertex_08024A98, 8, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  4,  6,  7, 0x0
gsSPEndDisplayList

glabel metal_box_seg8_dl_08024BB8 # 0x08024BB8 - 0x08024C28
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 252
gsSPDisplayList metal_box_seg8_dl_08024B18
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode1Cycle G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList

glabel metal_box_seg8_collision_08024C28 # 0x08024C28 - 0x08024CAC
# collision vertices
.hword 0x0040, 0x0008
.hword   154,   307,  -153
.hword  -153,   307,  -153
.hword  -153,   307,   154
.hword   154,   307,   154
.hword   154,     0,   154
.hword  -153,     0,   154
.hword  -153,     0,  -153
.hword   154,     0,  -153
# collision 0x00 normal
.hword 0x0000,   12
.hword    0,    1,    2
.hword    0,    2,    3
.hword    4,    5,    6
.hword    4,    6,    7
.hword    6,    1,    0
.hword    6,    0,    7
.hword    5,    1,    6
.hword    5,    2,    1
.hword    7,    0,    3
.hword    7,    3,    4
.hword    4,    2,    5
.hword    4,    3,    2
.hword 0x0041
.hword 0x0042
.word 0

binid
