# Whomp

.balign 8

whomp_seg6_texture_0601C360: # 0x0601C360
.incbin "actors/whomp/0.rgba16"

whomp_seg6_texture_0601D360: # 0x0601D360
.incbin "actors/whomp/1.rgba16"

whomp_seg6_texture_0601E360: # 0x0601D360
.incbin "actors/whomp/2.rgba16"

whomp_seg6_texture_0601EB60: # 0x0601EB60
.incbin "actors/whomp/3.rgba16"

whomp_seg6_light_0601F360: # 0x0601F360
.byte 0x4C, 0x4C, 0x4C, 0x00, 0x4C, 0x4C, 0x4C, 0x00

whomp_seg6_light_0601F368: # 0x0601F368
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

whomp_seg6_vertex_0601F378: # 0x0601F378
vertex    -52,    610,   -201,    470,    990,  0x00, 0x7E, 0x00, 0xFF
vertex    -52,    610,    202,      0,   2012,  0x00, 0x7E, 0x00, 0xFF
vertex   1559,    600,    202,      0,  -1022,  0x00, 0x7E, 0x00, 0xFF
vertex   1559,    600,   -201,      0,    320,  0x7E, 0x00, 0x00, 0xFF
vertex   1551,   -609,    202,   1980,    990,  0x7E, 0x00, 0x00, 0xFF
vertex   1551,   -609,   -201,   1980,    320,  0x7E, 0x00, 0x00, 0xFF
vertex   1559,    600,    202,      0,    990,  0x7E, 0x00, 0x00, 0xFF
vertex    -60,   -598,   -201,   1962,    320,  0x82, 0x00, 0x00, 0xFF
vertex    -52,    610,    202,    -48,    990,  0x82, 0x00, 0x00, 0xFF
vertex    -52,    610,   -201,    -48,    320,  0x82, 0x00, 0x00, 0xFF
vertex    -60,   -598,    202,   1962,    990,  0x82, 0x00, 0x00, 0xFF
vertex    -60,   -598,    202,      0,    990,  0x00, 0x82, 0x00, 0xFF
vertex    -60,   -598,   -201,    470,    990,  0x00, 0x82, 0x00, 0xFF
vertex   1551,   -609,   -201,    470,  -1022,  0x00, 0x82, 0x00, 0xFF
vertex   1551,   -609,    202,      0,  -1022,  0x00, 0x82, 0x00, 0xFF
vertex   1559,    600,   -201,    470,  -1022,  0x00, 0x7E, 0x00, 0xFF

whomp_seg6_vertex_0601F478: # 0x0601F478
vertex    -60,   -598,   -201,      0,   2012,  0x00, 0x00, 0x81, 0xFF
vertex   1559,    600,   -201,    990,      0,  0x00, 0x00, 0x81, 0xFF
vertex   1551,   -609,   -201,      0,      0,  0x00, 0x00, 0x81, 0xFF
vertex    -52,    610,   -201,    990,   2012,  0x00, 0x00, 0x81, 0xFF

whomp_seg6_vertex_0601F4B8: # 0x0601F4B8
vertex    -52,    610,    202,      0,   2012,  0x00, 0x00, 0x7F, 0xFF
vertex    -60,   -598,    202,    990,   2012,  0x00, 0x00, 0x7F, 0xFF
vertex   1551,   -609,    202,    990,      0,  0x00, 0x00, 0x7F, 0xFF
vertex   1559,    600,    202,      0,      0,  0x00, 0x00, 0x7F, 0xFF

glabel whomp_seg6_dl_0601F4F8 # 0x0601F4F8 - 0x0601F570
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601EB60
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight whomp_seg6_light_0601F368, 1
gsSPLight whomp_seg6_light_0601F360, 2
gsSPVertex whomp_seg6_vertex_0601F378, 16, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  6,  4, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7, 10,  8, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 13, 14, 0x0
gsSP1Triangle  0,  2, 15, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601F570 # 0x0601F570 - 0x0601F5A8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601C360
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSPVertex whomp_seg6_vertex_0601F478, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601F5A8 # 0x0601F5A8 - 0x0601F5E0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601D360
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x7FF, 0x100
gsSPVertex whomp_seg6_vertex_0601F4B8, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601F5E0 # 0x0601F5E0 - 0x0601F678
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPClearGeometryMode G_SHADING_SMOOTH
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601F4F8
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 252
gsSPDisplayList whomp_seg6_dl_0601F570
gsSPDisplayList whomp_seg6_dl_0601F5A8
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_SHADING_SMOOTH
gsSPEndDisplayList

whomp_seg6_light_0601F678: # 0x0601F678
.byte 0x4C, 0x4C, 0x4C, 0x00, 0x4C, 0x4C, 0x4C, 0x00

whomp_seg6_light_0601F680: # 0x0601F680
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

whomp_seg6_vertex_0601F690: # 0x0601F690
vertex    290,      0,     85,    952,      0,  0xED, 0x1C, 0x7A, 0xFF
vertex    -10,     35,     13,    246,    976,  0xED, 0x6A, 0x41, 0xFF
vertex    -10,      0,     38,    672,    976,  0xED, 0xE3, 0x79, 0xFF
vertex    290,     80,     28,    952,      0,  0xED, 0x7D, 0x08, 0xFF
vertex    -10,     21,    -27,    246,    976,  0xED, 0x5E, 0xAE, 0xFF
vertex    -10,     35,     13,    672,    976,  0xED, 0x6A, 0x41, 0xFF
vertex    290,     49,    -65,      0,      0,  0xED, 0x2F, 0x8C, 0xFF
vertex    290,     49,    -65,    952,      0,  0xED, 0x2F, 0x8C, 0xFF
vertex    -10,    -20,    -27,    246,    976,  0xED, 0xD1, 0x8C, 0xFF
vertex    -10,     21,    -27,    672,    976,  0xED, 0x5E, 0xAE, 0xFF
vertex    290,    -48,    -65,      0,      0,  0xED, 0xA2, 0xAE, 0xFF
vertex    290,    -79,     28,    952,      0,  0xED, 0x95, 0x41, 0xFF
vertex    290,      0,     85,      0,      0,  0xED, 0x1C, 0x7A, 0xFF
vertex    -10,      0,     38,    246,    976,  0xED, 0xE3, 0x79, 0xFF
vertex    -10,    -34,     13,    672,    976,  0xED, 0x83, 0x08, 0xFF

whomp_seg6_vertex_0601F780: # 0x0601F780
vertex    290,    -48,    -65,    952,      0,  0xED, 0xA2, 0xAE, 0xFF
vertex    290,    -79,     28,      0,      0,  0xED, 0x95, 0x41, 0xFF
vertex    -10,    -34,     13,    246,    976,  0xED, 0x83, 0x08, 0xFF
vertex    290,      0,     85,    952,      0,  0xED, 0x1C, 0x7A, 0xFF
vertex    290,     80,     28,      0,      0,  0xED, 0x7D, 0x08, 0xFF
vertex    -10,     35,     13,    246,    976,  0xED, 0x6A, 0x41, 0xFF
vertex    -10,    -20,    -27,    672,    976,  0xED, 0xD1, 0x8C, 0xFF

glabel whomp_seg6_dl_0601F7F0 # 0x0601F7F0 - 0x0601F880
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601EB60
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight whomp_seg6_light_0601F680, 1
gsSPLight whomp_seg6_light_0601F678, 2
gsSPVertex whomp_seg6_vertex_0601F690, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  6,  4, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7, 10,  8, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 13, 14, 0x0
gsSPVertex whomp_seg6_vertex_0601F780, 7, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  0,  2,  6, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601F880 # 0x0601F880 - 0x0601F8E0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601F7F0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

whomp_seg6_light_0601F8E0: # 0x0601F8E0
.byte 0x4C, 0x4C, 0x4C, 0x00, 0x4C, 0x4C, 0x4C, 0x00

whomp_seg6_light_0601F8E8: # 0x0601F8E8
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

whomp_seg6_vertex_0601F8F8: # 0x0601F8F8
vertex    -10,      0,    -37,    246,    976,  0xED, 0x1C, 0x86, 0xFF
vertex    290,     80,    -26,    952,      0,  0xED, 0x6A, 0xBF, 0xFF
vertex    290,      0,    -84,      0,      0,  0xED, 0xE2, 0x87, 0xFF
vertex    -10,     35,    -12,    246,    976,  0xED, 0x7D, 0xF8, 0xFF
vertex    290,     49,     66,    952,      0,  0xED, 0x5E, 0x52, 0xFF
vertex    290,     80,    -26,      0,      0,  0xED, 0x6A, 0xBF, 0xFF
vertex    -10,     21,     28,    672,    976,  0xED, 0x2F, 0x74, 0xFF
vertex    -10,     21,     28,    246,    976,  0xED, 0x2F, 0x74, 0xFF
vertex    290,    -48,     66,    952,      0,  0xED, 0xD1, 0x74, 0xFF
vertex    290,     49,     66,      0,      0,  0xED, 0x5E, 0x52, 0xFF
vertex    -10,    -20,     28,    672,    976,  0xED, 0xA2, 0x52, 0xFF
vertex    -10,    -34,    -12,    246,    976,  0xED, 0x95, 0xC0, 0xFF
vertex    -10,      0,    -37,    672,    976,  0xED, 0x1C, 0x86, 0xFF
vertex    290,      0,    -84,    952,      0,  0xED, 0xE2, 0x87, 0xFF
vertex    290,    -79,    -26,      0,      0,  0xED, 0x83, 0xF9, 0xFF

whomp_seg6_vertex_0601F9E8: # 0x0601F9E8
vertex    -10,    -20,     28,    246,    976,  0xED, 0xA2, 0x52, 0xFF
vertex    -10,    -34,    -12,    672,    976,  0xED, 0x95, 0xC0, 0xFF
vertex    290,    -79,    -26,    952,      0,  0xED, 0x83, 0xF9, 0xFF
vertex    -10,      0,    -37,    246,    976,  0xED, 0x1C, 0x86, 0xFF
vertex    -10,     35,    -12,    672,    976,  0xED, 0x7D, 0xF8, 0xFF
vertex    290,     80,    -26,    952,      0,  0xED, 0x6A, 0xBF, 0xFF
vertex    290,    -48,     66,      0,      0,  0xED, 0xD1, 0x74, 0xFF

glabel whomp_seg6_dl_0601FA58 # 0x0601FA58 - 0x0601FAE8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601EB60
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight whomp_seg6_light_0601F8E8, 1
gsSPLight whomp_seg6_light_0601F8E0, 2
gsSPVertex whomp_seg6_vertex_0601F8F8, 15, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  3,  6,  4, 0x0
gsSP1Triangle  7,  8,  9, 0x0
gsSP1Triangle  7, 10,  8, 0x0
gsSP1Triangle 11, 12, 13, 0x0
gsSP1Triangle 11, 13, 14, 0x0
gsSPVertex whomp_seg6_vertex_0601F9E8, 7, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  3,  4,  5, 0x0
gsSP1Triangle  0,  2,  6, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601FAE8 # 0x0601FAE8 - 0x0601FB48
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601FA58
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

whomp_seg6_vertex_0601FB48: # 0x0601FB48
vertex    -37,    -37,      0,      0,    990,  0xFF, 0xFF, 0xFF, 0xFF
vertex     38,    -37,      0,    990,    990,  0xFF, 0xFF, 0xFF, 0xFF
vertex     38,     38,      0,    990,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -37,     38,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel whomp_seg6_dl_0601FB88 # 0x0601FB88 - 0x0601FBC0
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601E360
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex whomp_seg6_vertex_0601FB48, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601FBC0 # 0x0601FBC0 - 0x0601FC30
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPClearGeometryMode G_LIGHTING
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601FB88
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList

whomp_seg6_vertex_0601FC30: # 0x0601FC30
vertex    -37,    -37,      0,      0,    990,  0xFF, 0xFF, 0xFF, 0xFF
vertex     38,    -37,      0,    990,    990,  0xFF, 0xFF, 0xFF, 0xFF
vertex     38,     38,      0,    990,      0,  0xFF, 0xFF, 0xFF, 0xFF
vertex    -37,     38,      0,      0,      0,  0xFF, 0xFF, 0xFF, 0xFF

glabel whomp_seg6_dl_0601FC70 # 0x0601FC70 - 0x0601FCA8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601E360
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPVertex whomp_seg6_vertex_0601FC30, 4, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  2,  3, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601FCA8 # 0x0601FCA8 - 0x0601FD18
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_TEXEL0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_TEXEL0
gsSPClearGeometryMode G_LIGHTING
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_CLAMP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601FC70
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPSetGeometryMode G_LIGHTING
gsSPEndDisplayList

whomp_seg6_light_0601FD18: # 0x0601FD18
.byte 0x4C, 0x4C, 0x4C, 0x00, 0x4C, 0x4C, 0x4C, 0x00

whomp_seg6_light_0601FD20: # 0x0601FD20
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

whomp_seg6_vertex_0601FD30: # 0x0601FD30
vertex    174,    183,    177,   1364,    114,  0x01, 0x3E, 0x6E, 0xFF
vertex    180,    257,      2,    490,    -34,  0x46, 0x69, 0x00, 0xFF
vertex     22,    158,      2,    490,    162,  0x9B, 0x4C, 0xFF, 0xFF
vertex    -28,    -89,      2,    490,    658,  0x84, 0xE7, 0x00, 0xFF
vertex    177,    182,   -171,   -376,    116,  0xC9, 0x39, 0x9D, 0xFF
vertex    154,   -260,      3,    492,    998,  0xE9, 0x84, 0x01, 0xFF
vertex    158,   -143,    201,   1482,    768,  0x38, 0xC6, 0x61, 0xFF
vertex    161,   -152,   -190,   -470,    784,  0x71, 0xDF, 0xD3, 0xFF
vertex    161,   -152,   -190,     -2,    774,  0x71, 0xDF, 0xD3, 0xFF
vertex    174,    183,    177,    916,    104,  0x01, 0x3E, 0x6E, 0xFF
vertex    158,   -143,    201,    974,    756,  0x38, 0xC6, 0x61, 0xFF
vertex    180,    257,      2,    478,    -46,  0x46, 0x69, 0x00, 0xFF
vertex    177,    182,   -171,     44,    104,  0xC9, 0x39, 0x9D, 0xFF
vertex    154,   -260,      3,    480,    990,  0xE9, 0x84, 0x01, 0xFF

glabel whomp_seg6_dl_0601FE10 # 0x0601FE10 - 0x0601FEA8
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601EB60
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight whomp_seg6_light_0601FD20, 1
gsSPLight whomp_seg6_light_0601FD18, 2
gsSPVertex whomp_seg6_vertex_0601FD30, 14, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  2,  3,  0, 0x0
gsSP1Triangle  2,  1,  4, 0x0
gsSP1Triangle  4,  3,  2, 0x0
gsSP1Triangle  5,  6,  3, 0x0
gsSP1Triangle  3,  6,  0, 0x0
gsSP1Triangle  3,  7,  5, 0x0
gsSP1Triangle  4,  7,  3, 0x0
gsSP1Triangle  8,  9, 10, 0x0
gsSP1Triangle  8, 11,  9, 0x0
gsSP1Triangle  8, 12, 11, 0x0
gsSP1Triangle  8, 10, 13, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_0601FEA8 # 0x0601FEA8 - 0x0601FF08
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601FE10
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

whomp_seg6_light_0601FF08: # 0x0601FF08
.byte 0x4C, 0x4C, 0x4C, 0x00, 0x4C, 0x4C, 0x4C, 0x00

whomp_seg6_light_0601FF10: # 0x0601FF10
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

whomp_seg6_vertex_0601FF20: # 0x0601FF20
vertex    154,   -260,     -2,    470,    998,  0x6E, 0xC3, 0xFF, 0xFF
vertex    174,    183,   -176,   -110,    114,  0x01, 0x3E, 0x92, 0xFF
vertex    180,    257,     -1,    472,    -34,  0x46, 0x69, 0x00, 0xFF
vertex    158,   -143,   -200,   -188,    768,  0xDF, 0xC4, 0x96, 0xFF
vertex     22,    158,     -1,    472,    162,  0x9B, 0x4C, 0x01, 0xFF
vertex    -28,    -89,     -1,    472,    658,  0x84, 0xE7, 0x00, 0xFF
vertex    177,    182,    172,   1050,    116,  0x03, 0x3D, 0x6F, 0xFF
vertex    161,   -152,    191,   1112,    784,  0xE1, 0xC2, 0x6A, 0xFF

glabel whomp_seg6_dl_0601FFA0 # 0x0601FFA0 - 0x06020038
gsDPSetTextureImage G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, whomp_seg6_texture_0601EB60
gsDPLoadSync
gsDPLoadBlock 7, 0, 0, 0x3FF, 0x100
gsSPLight whomp_seg6_light_0601FF10, 1
gsSPLight whomp_seg6_light_0601FF08, 2
gsSPVertex whomp_seg6_vertex_0601FF20, 8, 0
gsSP1Triangle  0,  1,  2, 0x0
gsSP1Triangle  0,  3,  1, 0x0
gsSP1Triangle  4,  2,  1, 0x0
gsSP1Triangle  1,  5,  4, 0x0
gsSP1Triangle  1,  3,  5, 0x0
gsSP1Triangle  5,  3,  0, 0x0
gsSP1Triangle  4,  5,  6, 0x0
gsSP1Triangle  0,  7,  5, 0x0
gsSP1Triangle  5,  7,  6, 0x0
gsSP1Triangle  6,  2,  4, 0x0
gsSP1Triangle  0,  2,  6, 0x0
gsSP1Triangle  0,  6,  7, 0x0
gsSPEndDisplayList

glabel whomp_seg6_dl_06020038 # 0x06020038 - 0x06020098
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_TEXEL0, G_CCMUX_0, G_CCMUX_SHADE, G_CCMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD
gsSPTexture -1, -1, 0, 0, 1
gsDPTileSync
gsDPSetTile G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD
gsDPSetTileSize 0, 0, 0, 124, 124
gsSPDisplayList whomp_seg6_dl_0601FFA0
gsSPTexture -1, -1, 0, 0, 0
gsDPPipeSync
gsDPSetCombineMode G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE, G_CCMUX_0, G_CCMUX_0, G_CCMUX_0, G_CCMUX_SHADE, G_ACMUX_0, G_ACMUX_0, G_ACMUX_0, G_ACMUX_SHADE
gsSPEndDisplayList

whomp_seg6_animvalue_06020098: # 0x06020098
.hword 0x0000, 0x0005, 0x00B4, 0x0068, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0xC1F1, 0xC16F, 0xC039, 0xBEC6, 0xBD90
.hword 0xBD0E, 0xBD38, 0xBDA8, 0xBE4C, 0xBF0E, 0xBFDB, 0xC0A0, 0xC148
.hword 0xC1BE, 0xC1F1, 0x0000, 0x0000, 0x0002, 0x0005, 0x0007, 0x0008
.hword 0x0007, 0x0007, 0x0006, 0x0004, 0x0003, 0x0002, 0x0001, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0001
.hword 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0xC1F1, 0xC16F, 0xC039, 0xBEC6, 0xBD90, 0xBD0E, 0xBD38, 0xBDA8
.hword 0xBE4C, 0xBF0E, 0xBFDB, 0xC0A0, 0xC148, 0xC1BE, 0xC1F1, 0x0003
.hword 0x0003, 0x0004, 0x0004, 0x0005, 0x0006, 0x0006, 0x0007, 0x0008
.hword 0x0009, 0x000A, 0x000A, 0x000B, 0x000B, 0x000B, 0x1A13, 0x1B29
.hword 0x1E36, 0x22E6, 0x28E6, 0x2FE4, 0x378B, 0x3F8A, 0x478D, 0x4F42
.hword 0x5655, 0x5C74, 0x614B, 0x6488, 0x65D7, 0xC004, 0xC004, 0xC003
.hword 0xC003, 0xC003, 0xC002, 0xC002, 0xC001, 0xC000, 0xC000, 0xBFFF
.hword 0xBFFF, 0xBFFF, 0xBFFE, 0xBFFE, 0x0000, 0x0000, 0x0001, 0x0003
.hword 0x0006, 0x0009, 0x000D, 0x0010, 0x0014, 0x0017, 0x001A, 0x001D
.hword 0x001F, 0x0021, 0x0021, 0xE726, 0xE609, 0xE2EC, 0xDE22, 0xD801
.hword 0xD0DD, 0xC90B, 0xC0E1, 0xB8B1, 0xB0D2, 0xA998, 0xA358, 0x9E66
.hword 0x9B17, 0x99C0, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC001
.hword 0xC001, 0xC001, 0xC001, 0xC001, 0xC002, 0xC002, 0xC002, 0xC002
.hword 0xC002, 0x2022, 0x3FFF, 0xDFDE, 0x2022, 0x3FFF, 0xDFDE, 0x2022
.hword 0x3FFF, 0xDFDE, 0x2022, 0x3FFF, 0xDFDE, 0x0000, 0xFF69, 0xFDFF
.hword 0xFC4E, 0xFAE4, 0xFA4C, 0xFA7D, 0xFB01, 0xFBBF, 0xFCA2, 0xFD92
.hword 0xFE77, 0xFF3A, 0xFFC5, 0x0000, 0x4045, 0x4045, 0x4045, 0x4045
.hword 0x4045, 0x4045, 0x4045, 0x4045, 0x4045, 0x4045, 0x4045, 0x4045
.hword 0x4045, 0x4045, 0x4045, 0x0000

whomp_seg6_animindex_06020240: # 0x06020240
.hword 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0003, 0x0001, 0x0000, 0x000F, 0x00B5
.hword 0x000F, 0x00C4, 0x0001, 0x00B2, 0x0001, 0x00B3, 0x0001, 0x00B4
.hword 0x0001, 0x0000, 0x000F, 0x0004, 0x000F, 0x0013, 0x0001, 0x00AF
.hword 0x0001, 0x00B0, 0x0001, 0x00B1, 0x000F, 0x0022, 0x000F, 0x0031
.hword 0x000F, 0x0040, 0x0001, 0x00AC, 0x0001, 0x00AD, 0x0001, 0x00AE
.hword 0x000F, 0x004F, 0x000F, 0x005E, 0x000F, 0x006D, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x00A9, 0x0001, 0x00AA
.hword 0x0001, 0x00AB, 0x000F, 0x007C, 0x000F, 0x008B, 0x000F, 0x009A
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000

whomp_seg6_anim_060202DC: # 0x060202DC
.hword 1
.hword 0
.hword 0
.hword 0
.hword 0x0F
.hword 0x0C
.word whomp_seg6_animvalue_06020098
.word whomp_seg6_animindex_06020240
.word 0

whomp_seg6_animvalue_060202F4: # 0x060202F4
.hword 0x0000, 0x0005, 0x00B2, 0x00B4, 0x00BA, 0x00C2, 0x00CB, 0x00D5
.hword 0x00DF, 0x00E7, 0x00EC, 0x00EE, 0x00ED, 0x00E9, 0x00E4, 0x00DD
.hword 0x00D5, 0x00CD, 0x00C5, 0x00BE, 0x00B7, 0x00B2, 0x00AF, 0x00AD
.hword 0x00AD, 0x00AF, 0x00B2, 0x00BA, 0x00C6, 0x00D3, 0x00E0, 0x00EC
.hword 0x00F5, 0x00F8, 0x00F8, 0x00F5, 0x00EE, 0x00E2, 0x00D3, 0x00C3
.hword 0x00B7, 0x00B2, 0x00B2, 0x00B2, 0x00B2, 0x00B2, 0x00B2, 0x00B2
.hword 0x00B2, 0x00B2, 0x00B2, 0x00B2, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0xFFFF, 0xFFFB, 0xFFF8, 0xFFF9, 0x0000, 0x0012, 0x002E, 0x004C
.hword 0x0064, 0x0071, 0x006E, 0x005F, 0x004B, 0x0037, 0x0027, 0x001C
.hword 0x0011, 0x0008, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0xFFEE, 0xFFCA, 0xFFAE, 0xFFB7, 0x0000, 0x00AB
.hword 0x01A6, 0x02BE, 0x03BF, 0x0477, 0x04ED, 0x0544, 0x056F, 0x0564
.hword 0x0516, 0x0445, 0x02F9, 0x0193, 0x0075, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1EE, 0xC1E9, 0xC1E4, 0xC1E6
.hword 0xC1F1, 0xC210, 0xC23E, 0xC26F, 0xC296, 0xC2A5, 0xC293, 0xC269
.hword 0xC235, 0xC205, 0xC1E6, 0xC1DB, 0xC1DD, 0xC1E5, 0xC1ED, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0x0000, 0xFFFE, 0xFFF8, 0xFFEF, 0xFFE5, 0xFFDA
.hword 0xFFCF, 0xFFC7, 0xFFC0, 0xFFBE, 0xFFC0, 0xFFC4, 0xFFCA, 0xFFD1
.hword 0xFFDA, 0xFFE3, 0xFFEC, 0xFFF4, 0xFFFB, 0x0000, 0x0002, 0x0003
.hword 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFD2, 0xFF56, 0xFEA2
.hword 0xFDCC, 0xFCEB, 0xFC16, 0xFB62, 0xFAE5, 0xFAB7, 0xFAD4, 0xFB27
.hword 0xFBA2, 0xFC3D, 0xFCEB, 0xFDA2, 0xFE57, 0xFF00, 0xFF91, 0x0000
.hword 0x0039, 0x0040, 0x002B, 0x000E, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC1F1, 0xC1F3
.hword 0xC1F6, 0xC1FB, 0xC201, 0xC208, 0xC20E, 0xC213, 0xC217, 0xC218
.hword 0xC217, 0xC215, 0xC211, 0xC20D, 0xC208, 0xC203, 0xC1FD, 0xC1F9
.hword 0xC1F4, 0xC1F1, 0xC1F0, 0xC1EF, 0xC1F0, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1, 0xC1F1
.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003
.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003
.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0005
.hword 0x0007, 0x0009, 0x000A, 0x0007, 0x0003, 0x0003, 0x0003, 0x0003
.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003
.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0001, 0x0000, 0x0000, 0x0000
.hword 0x0002, 0x0003, 0x1A13, 0x1A10, 0x1A07, 0x19FA, 0x19EA, 0x19D7
.hword 0x19C3, 0x19AE, 0x199B, 0x1988, 0x1979, 0x196D, 0x1967, 0x1966
.hword 0x196B, 0x1979, 0x1990, 0x19B0, 0x19DB, 0x1A13, 0x1B9D, 0x1E2C
.hword 0x1F5F, 0x1C09, 0x18B3, 0x1B51, 0x1E3E, 0x1C5A, 0x1A13, 0x1B30
.hword 0x1C85, 0x1B5A, 0x1A13, 0x19EB, 0x19E2, 0x19ED, 0x1A05, 0x1A21
.hword 0x1A39, 0x1A44, 0x1A3A, 0x1A13, 0x1894, 0x17A1, 0x1AEB, 0x1D8F
.hword 0x19D8, 0x15E9, 0x17C6, 0x1A13, 0xC004, 0xC004, 0xC004, 0xC004
.hword 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004
.hword 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004
.hword 0xC004, 0xC004, 0xC004, 0xC003, 0xC003, 0xC004, 0xC005, 0xC005
.hword 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004
.hword 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004, 0xC004
.hword 0xC004, 0xC004, 0xC003, 0xC003, 0xC003, 0xC004, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
.hword 0x0000, 0x0000, 0x0001, 0x0003, 0x0003, 0x0003, 0x0004, 0x0006
.hword 0x0006, 0x0005, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF
.hword 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0002
.hword 0x0006, 0x0007, 0x0008, 0x0009, 0x0008, 0x0005, 0x0001, 0x0000
.hword 0xE726, 0xE729, 0xE730, 0xE73C, 0xE74A, 0xE75B, 0xE76D, 0xE77F
.hword 0xE791, 0xE7A1, 0xE7AE, 0xE7B9, 0xE7BF, 0xE7C0, 0xE7BA, 0xE7AE
.hword 0xE79A, 0xE77E, 0xE757, 0xE726, 0xE4F0, 0xE2AB, 0xE423, 0xE5D0
.hword 0xE44F, 0xE2FD, 0xE529, 0xE7A0, 0xE7A8, 0xE726, 0xE725, 0xE731
.hword 0xE747, 0xE761, 0xE77C, 0xE792, 0xE79F, 0xE7A0, 0xE78F, 0xE768
.hword 0xE726, 0xE509, 0xE313, 0xE53C, 0xE724, 0xE3F7, 0xE10B, 0xE2A1
.hword 0xE591, 0xE726, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000
.hword 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000
.hword 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xBFFF
.hword 0xBFFF, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000
.hword 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000
.hword 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC001, 0xC000
.hword 0xBFFF, 0xBFFF, 0xC000, 0xC000, 0x2022, 0x3FFF, 0xDFDE, 0x2022
.hword 0x3FFF, 0xDFDE, 0x2022, 0x3FFF, 0xDFDE, 0x2022, 0x3FFF, 0xDFDE
.hword 0xF2F7, 0xF33E, 0xF401, 0xF52A, 0xF69E, 0xF846, 0xFA08, 0xFBCC
.hword 0xFD7A, 0xFEF9, 0x005C, 0x01C7, 0x0337, 0x04AA, 0x061D, 0x078D
.hword 0x08F9, 0x0A5E, 0x0BBA, 0x0D09, 0x0DF4, 0x0E61, 0x0E74, 0x0E3D
.hword 0x0E3A, 0x0E20, 0x0D09, 0x0AA9, 0x07A0, 0x0462, 0x0167, 0xFF27
.hword 0xFD67, 0xFBA9, 0xF9F7, 0xF85C, 0xF6E3, 0xF596, 0xF481, 0xF3AD
.hword 0xF326, 0xF2F7, 0xF2F7, 0xF2F6, 0xF2F5, 0xF2F5, 0xF2F5, 0xF2F6
.hword 0xF2F7, 0xF2F7, 0x0015, 0x0015, 0x0014, 0x0012, 0x000F, 0x000C
.hword 0x000A, 0x0007, 0x0004, 0x0001, 0x0000, 0x0002, 0x0004, 0x0007
.hword 0x000A, 0x000A, 0x0008, 0x0003, 0xFFFA, 0xFFEB, 0xFF70, 0xFF25
.hword 0x0027, 0x0119, 0x00E4, 0x0051, 0xFFEB, 0xFFD6, 0xFFD8, 0xFFE7
.hword 0xFFF8, 0x0001, 0x0004, 0x0007, 0x000A, 0x000C, 0x000F, 0x0011
.hword 0x0013, 0x0014, 0x0015, 0x0015, 0xFFA6, 0xFF50, 0x0022, 0x00EE
.hword 0x00C7, 0x0056, 0x0015, 0x0015, 0x4041, 0x4016, 0x3FA3, 0x3EFD
.hword 0x3E37, 0x3D67, 0x3CA2, 0x3BFB, 0x3B88, 0x3B5D, 0x3B78, 0x3BC1
.hword 0x3C2F, 0x3CB9, 0x3D56, 0x3DFD, 0x3EA4, 0x3F43, 0x3FCF, 0x4041
.hword 0x402D, 0x3FEA, 0x401C, 0x4054, 0x402C, 0x3FF4, 0x4041, 0x4160
.hword 0x42F3, 0x4494, 0x45DB, 0x465F, 0x4633, 0x45BC, 0x450C, 0x4438
.hword 0x4350, 0x4268, 0x4193, 0x40E4, 0x406D, 0x4041, 0x4066, 0x4083
.hword 0x403D, 0x3FF9, 0x4006, 0x402C, 0x4041, 0x4041

whomp_seg6_animindex_06020950: # 0x06020950
.hword 0x0001, 0x0001, 0x0032, 0x0002, 0x0001, 0x0000, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0032, 0x0298, 0x0032, 0x02CA
.hword 0x0032, 0x02FC, 0x0001, 0x0295, 0x0001, 0x0296, 0x0001, 0x0297
.hword 0x0032, 0x0034, 0x0032, 0x0066, 0x0032, 0x0098, 0x0001, 0x0292
.hword 0x0001, 0x0293, 0x0001, 0x0294, 0x0032, 0x00CA, 0x0032, 0x00FC
.hword 0x0032, 0x012E, 0x0001, 0x028F, 0x0001, 0x0290, 0x0001, 0x0291
.hword 0x0032, 0x0160, 0x0032, 0x0192, 0x0032, 0x01C4, 0x0001, 0x0000
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x028C, 0x0001, 0x028D
.hword 0x0001, 0x028E, 0x0032, 0x01F6, 0x0032, 0x0228, 0x0032, 0x025A
.hword 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000

whomp_seg6_anim_060209EC: # 0x060209EC
.hword 0
.hword 0
.hword 0
.hword 0
.hword 0x32
.hword 0x0C
.word whomp_seg6_animvalue_060202F4
.word whomp_seg6_animindex_06020950
.word 0

glabel whomp_seg6_anims_06020A04 # 0x06020A04
.word whomp_seg6_anim_060209EC
.word whomp_seg6_anim_060202DC
# no terminator? TODO: What does the 0 at the end of these structs actually do?

glabel whomp_seg6_collision_06020A0C # 0x06020A0C - 0x06020A90
.ifdef VERSION_JP
# collision vertices
.hword 0x0040, 0x0008
.hword  -200,    50,  -100
.hword   150,    50,  -100
.hword   150,   430,  -100
.hword  -200,   430,  -100
.hword  -200,    50,    -3
.hword   150,   430,    -3
.hword   150,    50,    -3
.hword  -200,   430,    -3
# collision 0x76 fence
.hword 0x0076,   12
.hword    2,    1,    0
.hword    3,    2,    0
.hword    6,    5,    4
.hword    5,    7,    4
.hword    7,    5,    3
.hword    5,    2,    3
.hword    6,    4,    0
.hword    1,    6,    0
.hword    5,    1,    2
.hword    6,    1,    5
.hword    0,    7,    3
.hword    0,    4,    7
.hword 0x0041
.hword 0x0042
.word 0
.else
# collision vertices
.hword 0x0040, 0x0008
.hword  -150,    50,  -100
.hword   150,    50,  -100
.hword   150,   430,  -100
.hword  -150,   430,  -100
.hword  -150,    50,    -3
.hword   150,   430,    -3
.hword   150,    50,    -3
.hword  -150,   430,    -3
# collision 0x76 fence
.hword 0x0076,   12
.hword    2,    1,    0
.hword    3,    2,    0
.hword    6,    5,    4
.hword    5,    7,    4
.hword    7,    5,    3
.hword    5,    2,    3
.hword    6,    4,    0
.hword    1,    6,    0
.hword    5,    1,    2
.hword    6,    1,    5
.hword    0,    7,    3
.hword    0,    4,    7
.hword 0x0041
.hword 0x0042
.word 0
.endif

binid
