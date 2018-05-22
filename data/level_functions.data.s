.include "macros.inc"

.section .data

glabel D_8032F0A0
	.incbin "bin/sm64.j.0E98A4.bin", 0x7FC, 0x4

glabel D_8032F0A4
	.incbin "bin/sm64.j.0E98A4.bin", 0x800, 0x10

glabel D_8032F0B4
	.incbin "bin/sm64.j.0E98A4.bin", 0x810, 0xC

glabel D_8032F0C0
	.incbin "bin/sm64.j.0E98A4.bin", 0x81C, 0xC

glabel D_8032F0CC
	.incbin "bin/sm64.j.0E98A4.bin", 0x828, 0x40

glabel TableMrIParticleActions
.word ActionMrIParticle0
.word ActionMrIParticle1

glabel TableMrIActions
.word ActionMrI0
.word ActionMrI1
.word ActionMrI2
.word ActionMrI3

glabel D_8032F124
# Unknown region 0EA124-0EA14C [28]
.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x02, 0x05
.byte 0x00, 0x50, 0x00, 0x96, 0x00, 0x00, 0x00, 0x00

glabel D_8032F134
.byte 0x00, 0x1E, 0xA4, 0x00, 0x28, 0x00, 0x14, 0x28
.byte 0xFC, 0x1E, 0x00, 0x00, 0x41, 0xA0, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0B, 0x0C, 0x00

glabel TableCapSwitchActions
.word ActionActivateCapSwitch0
.word ActionActivateCapSwitch1
.word ActionActivateCapSwitch2
.word ActionActivateCapSwitch3

glabel TableKingBobombActions
.word ActionKingBobomb0
.word ActionKingBobomb1
.word ActionKingBobomb2
.word ActionKingBobomb3
.word ActionKingBobomb4
.word ActionKingBobomb5
.word ActionKingBobomb6
.word ActionKingBobomb7
.word ActionKingBobomb8

glabel D_8032F180
# Unknown region 0EA180-0EA1E0 [60]
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x14, 0x50, 0x15, 0x80, 0x81
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x01, 0x0F, 0xFF, 0x50, 0x15, 0x80, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x21, 0xFF, 0x50, 0x15, 0x80, 0x81
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0F, 0x50, 0x15, 0x80, 0x81

glabel TableOpenedCannonActions
.word ActionOpenedCannon0
.word ActionOpenedCannon1
.word ActionOpenedCannon2
.word ActionOpenedCannon3
.word ActionOpenedCannon4
.word ActionOpenedCannon5
.word ActionOpenedCannon6

# Unknown region 0EA1FC-0EA238 [3C]
.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
.byte 0x41, 0x20, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x41, 0xA0, 0x00, 0x00
.byte 0x3F, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x41, 0xA0, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00
.byte 0x08, 0x00, 0x00, 0x00, 0x41, 0x20, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00

glabel TableChuckyaActions
.word ActionChuckya0
.word ActionChuckya1
.word ActionChuckya2
.word ActionChuckya3

# Unknown region 0EA248-0EA2C4 [7C]
.byte 0x00, 0x00

glabel D_8032F24A
.byte 0x00, 0x64

glabel D_8032F24C
.byte 0x07, 0x00, 0xFD, 0x30

glabel D_8032F250
.byte 0x07, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96
.byte 0x07, 0x01, 0x86, 0xB4, 0x03, 0xE8, 0x00, 0x00

glabel D_8032F260
.byte 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00
.byte 0x00, 0x50, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00

# probably a struct
glabel D_8032F270
.byte 0x02

glabel D_8032F271
.byte 0x14, 0x8E

glabel D_8032F273
.byte 0x00, 0x28, 0x05, 0x1E, 0x14, 0xFC, 0x1E, 0x00, 0x00

glabel D_8032F27C
.byte 0x43, 0xA5, 0x00, 0x00

glabel D_8032F280
.byte 0x41, 0x20, 0x00, 0x00

glabel D_8032F284
.byte 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x50, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00

glabel D_8032F294
.byte 0x00, 0x00, 0x00, 0x10
.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

glabel D_8032F2A4
.byte 0x00, 0x00

glabel D_8032F2A6
.byte 0xFF, 0x6A
.byte 0x00, 0x00, 0xFF, 0xCE, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x96, 0xFF, 0xCE, 0x00, 0x64
.byte 0xFF, 0x9C, 0x00, 0x32, 0x00, 0x32, 0x00, 0x64, 0x00, 0x64, 0x00, 0x32

glabel TableCoinInsideBooActions
.word ActionCoinInsideBoo0
.word ActionCoinInsideBoo1

# Unknown region 0EA2CC-0EA338 [6C]
glabel D_8032F2CC
.byte 0xD0, 0x00

glabel D_8032F2CE
.byte 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xDE, 0x67, 0x21, 0x99, 0x21, 0x99, 0x21, 0x99
.byte 0xDE, 0x67, 0xDE, 0x67, 0x21, 0x99, 0xDE, 0x67

glabel D_8032F2E4
.byte 0xE0, 0x00

glabel D_8032F2E6
.byte 0x00, 0x00

.byte 0x00, 0x00, 0x00, 0x00
.byte 0x20, 0x00, 0x00, 0x00, 0xE9, 0x9A, 0x16, 0x66, 0x16, 0x66, 0x16, 0x66, 0xE9, 0x9A, 0xE9, 0x9A
.byte 0x16, 0x66, 0xE9, 0x9A

glabel D_8032F300
.byte 0x00, 0x04, 0x00, 0x00

glabel D_8032F304
.byte 0x00, 0x00, 0x00, 0x03

.byte 0x00, 0x08, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00

glabel D_8032F328
.byte 0x30, 0x04, 0xC0, 0x81, 0x30, 0x06, 0xC0, 0x81

glabel D_8032F330
.byte 0x30, 0x05, 0xC0, 0x81, 0x30, 0x07, 0xC0, 0x81

glabel TableGrindelThwompActions
.word ActionGrindelThwomp0
.word ActionGrindelThwomp1
.word ActionGrindelThwomp2
.word ActionGrindelThwomp3
.word ActionGrindelThwomp4

glabel D_8032F34C
# Unknown region 0EA34C-0EA37C [30]
.byte 0x00, 0x09, 0xFE, 0x00, 0x00, 0x80

glabel D_8032F352
.byte 0x00, 0xB0

glabel D_8032F354
.byte 0x07, 0x00

.byte 0xFA, 0xEC, 0x00, 0x09, 0xFE, 0x64
.byte 0x00, 0x67, 0x00, 0x38, 0x07, 0x02, 0x6B, 0x1C, 0x00, 0x09, 0xFE, 0x00, 0x00, 0x80, 0x00, 0x3C
.byte 0x07, 0x01, 0xD2, 0x1C, 0x00, 0x09, 0xFE, 0x00, 0x00, 0x80, 0x00, 0x40, 0x07, 0x01, 0x52, 0x88

glabel TableTumblingBridgeActions
.word ActionTumblingBridge0
.word ActionTumblingBridge1
.word ActionTumblingBridge2
.word ActionTumblingBridge3

# Unknown region 0EA38C-0EA3B8 [2C]
glabel D_8032F38C
.byte 0xFF, 0xCD

glabel D_8032F38E
.byte 0x00, 0x00

glabel D_8032F390
.byte 0x00, 0x00, 0xFE, 0x33, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0xF5, 0xCD, 0x00, 0x00, 0x00, 0x00, 0xF6, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD6
.byte 0x00, 0x00, 0x00, 0x00, 0xFF, 0xCE, 0x07, 0x99, 0x00, 0x01, 0x00, 0x00

glabel TableElevatorActions
.word ActionElevator0
.word ActionElevator1
.word ActionElevator2
.word ActionElevator3
.word ActionElevator4

glabel D_8032F3CC
# Unknown region 0EA3CC-0EA410 [44]
.byte 0x03, 0x14, 0x8E, 0x14, 0x0A, 0x05, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00
.byte 0x3F, 0xC0, 0x00, 0x00

glabel D_8032F3E0
.byte 0x00, 0x05, 0x9F, 0x00, 0x00, 0x14, 0x14, 0x00, 0xFC, 0x1E, 0x00, 0x00
.byte 0x40, 0xA0, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00

glabel D_8032F3F4
.byte 0x00, 0x02, 0xFF, 0xF8, 0x00, 0x01, 0x00, 0x04

glabel D_8032F3FC
.byte 0x00, 0x05, 0x9E, 0x00, 0x00, 0x14, 0x14, 0x00, 0xFC, 0x1E, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
.byte 0x40, 0x00, 0x00, 0x00

glabel TableLittleCageActions
.word ActionLittleCage0
.word ActionLittleCage1
.word ActionLittleCage2
.word ActionLittleCage3

glabel D_8032F420
# Unknown region 0EA420-0EA488 [68]
.byte 0x3F, 0xF3, 0x33, 0x33, 0x40, 0x19, 0x99, 0x9A, 0x40, 0x80, 0x00, 0x00, 0x40, 0x99, 0x99, 0x9A

glabel D_8032F430
.byte 0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x01, 0x03, 0x00, 0x5A, 0x00, 0x50, 0x00, 0x50, 0x00, 0x46

glabel D_8032F440
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xDC, 0x01, 0x2C, 0x00, 0xDC, 0x01, 0x2C

glabel D_8032F450
.byte 0x00, 0x00, 0x02, 0x00, 0x14, 0x00, 0x01, 0x00, 0x00, 0x96, 0x00, 0xC8, 0x00, 0x96, 0x00, 0xC8

glabel D_8032F460
.byte 0x00, 0x1E

glabel D_8032F462
.byte 0x00, 0x00, 0x00, 0x2A, 0x00, 0x01, 0x00, 0x34, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01
.byte 0x00, 0x4A, 0x00, 0x00, 0x00, 0x56, 0x00, 0x01, 0x00, 0x60, 0x00, 0x00, 0x00, 0x6C, 0x00, 0x01
.byte 0x00, 0x76, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00

glabel TableHeaveHoActions
.word ActionHeaveHo0
.word ActionHeaveHo1
.word ActionHeaveHo2
.word ActionHeaveHo3

glabel D_8032F498
# Unknown region 0EA498-0EA4A8 [10]
.byte 0x00, 0x00, 0x00, 0x02, 0x14, 0x00, 0x01, 0x05, 0x00, 0x96, 0x00, 0xFA, 0x00, 0x96, 0x00, 0xFA

glabel TableJumpingBoxActions
.word ActionJumpingBox0
.word ActionJumpingBox1

glabel D_8032F4B0
# Unknown region 0EA4B0-0EA4C0 [10]
.byte 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x01, 0x2C, 0x00, 0x00, 0x00, 0x00

glabel TableBetaBooKeyInsideActions
.word ActionBetaBooKeyInside0
.word ActionBetaBooKeyInside1
.word ActionBetaBooKeyInside2

glabel D_8032F4CC
# Unknown region 0EA4CC-0EA4DC [10]
.byte 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x64, 0x00, 0xA0, 0x00, 0x64

glabel TableBulletBillActions
.word ActionBulletBill0
.word ActionBulletBill1
.word ActionBulletBill2
.word ActionBulletBill3
.word ActionBulletBill4

glabel TableBowserTailAnchorActions
.word ActionBowserTailAnchor0
.word ActionBowserTailAnchor1
.word ActionBowserTailAnchor2

# Unknown region 0EA4FC-0EA568 [6C]
glabel D_8032F4FC
.byte 0x07, 0x08, 0x09, 0x0C, 0x0D, 0x0E, 0x0F, 0x04, 0x03, 0x10, 0x11, 0x13, 0x03, 0x03, 0x03, 0x03

glabel D_8032F50C
.byte 0x00, 0x3C, 0x00, 0x00

glabel D_8032F510
.byte 0x00, 0x32, 0x00, 0x00

glabel D_8032F514
.byte 0x18, 0x2A, 0x3C, 0xFF

glabel D_8032F518
.byte 0x00, 0x77
.byte 0x00, 0x78
.byte 0x00, 0x79

glabel D_8032F51E
.byte 0x00, 0x00

glabel D_8032F520
.byte 0x00, 0x01

glabel D_8032F522
.byte 0x00, 0x0A

glabel D_8032F524
.byte 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A
.byte 0xFF, 0xFF, 0xFF, 0xF6, 0x00, 0x72, 0x00, 0x01, 0xFF, 0xEC, 0x00, 0x86, 0xFF, 0xFF, 0x00, 0x14
.byte 0x00, 0x9A, 0x00, 0x01, 0x00, 0x28, 0x00, 0xA4, 0xFF, 0xFF, 0xFF, 0xD8, 0x00, 0xAE, 0x00, 0x01
.byte 0xFF, 0xB0, 0x00, 0xB3, 0xFF, 0xFF, 0x00, 0x50, 0x00, 0xB8, 0x00, 0x01, 0x00, 0xA0, 0x00, 0xBA
.byte 0xFF, 0xFF, 0xFF, 0x60, 0x00, 0xBA, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00

glabel TableBowserActions
.word ActionBowser0
.word ActionBowser1
.word ActionBowser2
.word ActionBowser3
.word ActionBowser4
.word ActionBowser5
.word ActionBowser6
.word ActionBowser7
.word ActionBowser8
.word ActionBowser9
.word ActionBowser10
.word ActionBowser11
.word ActionBowser12
.word ActionBowser13
.word ActionBowser14
.word ActionBowser15
.word ActionBowser16
.word ActionBowser17
.word ActionBowser18
.word ActionBowser19

# Unknown region 0EA5B8-0EA71C [164]
glabel D_8032F5B8
    .incbin "bin/sm64.j.0EA5B8.bin", 0x0, 0xD8

glabel D_8032F690
    .incbin "bin/sm64.j.0EA5B8.bin", 0xD8, 0x4

glabel D_8032F694
    .incbin "bin/sm64.j.0EA5B8.bin", 0xDC, 0x4

glabel D_8032F698
    .incbin "bin/sm64.j.0EA5B8.bin", 0xE0, 0x4

glabel D_8032F69C
    .incbin "bin/sm64.j.0EA5B8.bin", 0xE4, 0x2

glabel D_8032F69E
    .incbin "bin/sm64.j.0EA5B8.bin", 0xE6, 0x2

glabel D_8032F6A0
    .incbin "bin/sm64.j.0EA5B8.bin", 0xE8, 0x7C

glabel TableFallingBowserPlatformActions
.word ActionFallingBowserPlatform0
.word ActionFallingBowserPlatform1
.word ActionFallingBowserPlatform2

# Unknown region 0EA728-0EA840 [118]
glabel D_8032F728
	.incbin "bin/sm64.j.0EA728.bin", 0x0, 0x10

glabel D_8032F738
	.incbin "bin/sm64.j.0EA728.bin", 0x10, 0x10

glabel D_8032F748
	.incbin "bin/sm64.j.0EA728.bin", 0x20, 0xC

glabel D_8032F754
	.incbin "bin/sm64.j.0EA728.bin", 0x2C, 0x10

glabel D_8032F764
	.incbin "bin/sm64.j.0EA728.bin", 0x3C, 0x18

glabel D_8032F77C
	.incbin "bin/sm64.j.0EA728.bin", 0x54, 0x5C

glabel D_8032F7D8
	.incbin "bin/sm64.j.0EA728.bin", 0xB0, 0x68

glabel TableUkikiOpenCageActions
.word ActionUkikiOpenCage0
.word ActionUkikiOpenCage1
.word ActionUkikiOpenCage2
.word ActionUkikiOpenCage3
.word ActionUkikiOpenCage4
.word ActionUkikiOpenCage5
.word ActionUkikiOpenCage6
.word ActionUkikiOpenCage7

# Unknown region 0EA860-0EA8D0 [70]
glabel D_8032F860
.byte 0x00, 0x02, 0x00, 0x1E, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xDC, 0x03, 0x84, 0x00, 0x1E
.byte 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0xFF, 0xE2, 0x00, 0x02, 0x00, 0x1E, 0xC0, 0x00, 0x00, 0x00
.byte 0x00, 0x01, 0x00, 0xDC, 0x03, 0x84, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0xFF, 0xE2
.byte 0x00, 0x03, 0x00, 0x00

glabel D_8032F894
.byte 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xDB
.byte 0x03, 0x84, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0xFF, 0xE2, 0x00, 0x02, 0x00, 0x1E
.byte 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xDB, 0x03, 0x84, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x1E
.byte 0x00, 0x00, 0xFF, 0xE2, 0x00, 0x03, 0x00, 0x00

glabel D_8032F8C8
.word D_8032F860
.word D_8032F894

glabel TableRotatingCwFireBarsActions
.word ActionRotatingCwFireBars0
.word ActionRotatingCwFireBars1
.word ActionRotatingCwFireBars2
.word ActionRotatingCwFireBars3

# Unknown region 0EA8E0-0EA978 [98]
glabel D_8032F8E0
    .incbin "bin/sm64.j.0EA8E0.bin", 0x0, 0x10
glabel D_8032F8F0
	.incbin "bin/sm64.j.0EA8E0.bin", 0x10, 0x34
glabel D_8032F924
	.incbin "bin/sm64.j.0EA8E0.bin", 0x44, 0x24
glabel D_8032F948
	.incbin "bin/sm64.j.0EA8E0.bin", 0x68, 0x24

glabel D_8032F96C
	.word D_8032F8F0
	.word D_8032F924
	.word D_8032F948

glabel TableToxBoxActions
.word ActionToxBox0
.word ActionToxBox1
.word ActionToxBox2
.word ActionToxBox3
.word ActionToxBox4
.word ActionToxBox5
.word ActionToxBox6
.word ActionToxBox7

glabel D_8032F998
# Unknown region 0EA998-0EA9A0 [8]
.byte 0x0C, 0x1C, 0x32, 0x40, 0xFF, 0x00, 0x00, 0x00

glabel TablePiranhaPlantActions
.word ActionPiranhaPlant20
.word ActionPiranhaPlant21
.word ActionPiranhaPlant22
.word ActionPiranhaPlant23
.word ActionPiranhaPlant24
.word ActionPiranhaPlant25
.word ActionPiranhaPlant26
.word ActionPiranhaPlant27
.word ActionPiranhaPlant28

# Unknown region 0EA9C4-0EABBC [1F8]
glabel D_8032F9C4
	.incbin "bin/sm64.j.0EA9C4.bin", 0x0, 0x1C
glabel D_8032F9E0
	.incbin "bin/sm64.j.0EA9C4.bin", 0x1C, 0x1C
glabel D_8032F9FC
	.incbin "bin/sm64.j.0EA9C4.bin", 0x38, 0x1C
glabel D_8032FA18
	.incbin "bin/sm64.j.0EA9C4.bin", 0x54, 0x1C
glabel D_8032FA34
	.incbin "bin/sm64.j.0EA9C4.bin", 0x70, 0x1C
glabel D_8032FA50
	.incbin "bin/sm64.j.0EA9C4.bin", 0x8C, 0x1C
glabel D_8032FA6C
	.incbin "bin/sm64.j.0EA9C4.bin", 0xA8, 0x1C
glabel D_8032FA88
	.incbin "bin/sm64.j.0EA9C4.bin", 0xC4, 0x1C
glabel D_8032FAA4
	.incbin "bin/sm64.j.0EA9C4.bin", 0xE0, 0x1C
glabel D_8032FAC0
	.incbin "bin/sm64.j.0EA9C4.bin", 0xFC, 0x1C
glabel D_8032FADC
	.incbin "bin/sm64.j.0EA9C4.bin", 0x118, 0x1C
glabel D_8032FAF8
	.incbin "bin/sm64.j.0EA9C4.bin", 0x134, 0x1C
glabel D_8032FB14
	.incbin "bin/sm64.j.0EA9C4.bin", 0x150, 0x1C
glabel D_8032FB30
	.incbin "bin/sm64.j.0EA9C4.bin", 0x16C, 0x1C

glabel D_8032FB4C
    .word 0x43FBF101, D_8032F9C4
	.word 0x4405F100, D_8032F9E0
	.word 0x45F1FB00, D_8032FADC
	.word 0x46FBFB00, D_8032FAF8
	.word 0x4705FB00, D_8032F9FC
	.word 0x480FFB00, D_8032FA18
	.word 0x49F10500, D_8032FAC0
	.word 0x4AFB0500, D_8032FAA4
	.word 0x4B050500, D_8032FA50
	.word 0x4C0F0500, D_8032FA34
	.word 0x4DF10F00, D_8032FB14
	.word 0x4EFB0F00, D_8032FA88
	.word 0x4F050F00, D_8032FA6C
	.word 0x500F0F00, D_8032FB30

glabel TableBowserPuzzlePieceActions
.word ActionBowserPuzzlePiece0
.word ActionBowserPuzzlePiece1
.word ActionBowserPuzzlePiece2
.word ActionBowserPuzzlePiece3
.word ActionBowserPuzzlePiece4
.word ActionBowserPuzzlePiece5
.word ActionBowserPuzzlePiece6

glabel TableTuxiesMotherActions
.word ActionTuxiesMother0
.word ActionTuxiesMother1
.word ActionTuxiesMother2

glabel TableSmallPenguinActions
.word ActionSmallPenguin0
.word ActionSmallPenguin1
.word ActionSmallPenguin2
.word ActionSmallPenguin3
.word ActionSmallPenguin4
.word ActionSmallPenguin5

glabel TableFishActions
.word ActionFish0
.word ActionFish1
.word ActionFish2

glabel TableFishGroupActions
.word ActionFishGroup0
.word ActionFishGroup1
.word ActionFishGroup2

glabel TableBirdChirpChirpActions
.word ActionBirdChirpChirp0
.word ActionBirdChirpChirp1
.word ActionBirdChirpChirp2
.word ActionBirdChirpChirp3

glabel TableCheepCheepActions
.word ActionCheepCheep0
.word ActionCheepCheep1
.word ActionCheepCheep2

# Unknown region 0EAC30-0EACC0 [90]
glabel D_8032FC30
	.incbin "bin/sm64.j.0EAC30.bin", 0x0, 0x10

glabel D_8032FC40
	.incbin "bin/sm64.j.0EAC30.bin", 0x10, 0x80

glabel TableExclamationBoxActions
.word ActionExclamationBox0
.word ActionExclamationBox1
.word ActionExclamationBox2
.word ActionExclamationBox3
.word ActionExclamationBox4
.word ActionExclamationBox5

glabel D_8032FCD8
# Unknown region 0EACD8-0EAD08 [30]
.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00, 0x82, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00

glabel D_8032FCE8
.byte 0x01, 0x40, 0x00, 0x38

glabel D_8032FCEC
.byte 0x07, 0x01, 0x14, 0x74, 0x01, 0x9A, 0x00, 0x3C, 0x07, 0x02, 0xB6, 0x5C

glabel D_8032FCF8
.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xDC, 0x0F, 0xA0, 0x00, 0x00, 0x00, 0x00

glabel TableTweesterActions
.word ActionTweester0
.word ActionTweester1
.word ActionTweester2

glabel D_8032FD14
# Unknown region 0EAD14-0EAD38 [24]
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x8C, 0x00, 0x50, 0x00, 0x28, 0x00, 0x3C

glabel D_8032FD24
.byte 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0xD2, 0x00, 0x6E, 0x00, 0xD2, 0xFF, 0x2E, 0x00, 0x46
.byte 0xFF, 0x2E, 0x00, 0x00

glabel TableBooActions
.word ActionBoo0
.word ActionBoo1
.word ActionBoo2
.word ActionBoo3
.word ActionBoo4
.word ActionBoo5

glabel TableBooGivingStarActions
.word ActionBooGivingStar0
.word ActionBooGivingStar1
.word ActionBooGivingStar2
.word ActionBooGivingStar3
.word ActionBooGivingStar4

glabel TableBooWithCageActions
.word ActionBooWithCage0
.word ActionBooWithCage1
.word ActionBooWithCage2
.word ActionBooWithCage3

glabel D_8032FD74
# Unknown region 0EAD74-0EAD84 [10]
.byte 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x01, 0x03, 0x00, 0x82, 0x00, 0x46, 0x00, 0x5A, 0x00, 0x3C

glabel TableWhompActions
.word ActionWhomp0
.word ActionWhomp1
.word ActionWhomp2
.word ActionWhomp3
.word ActionWhomp4
.word ActionWhomp5
.word ActionWhomp6
.word ActionWhomp7
.word ActionWhomp8
.word ActionWhomp9

# Unknown region 0EADAC-0EFA50 [4CA4]
glabel D_8032FDAC
	.incbin "bin/sm64.j.0EADAC.bin", 0x0, 0x24

glabel D_8032FDD0
	.incbin "bin/sm64.j.0EADAC.bin", 0x24, 0x24

glabel D_8032FDF4
	.incbin "bin/sm64.j.0EADAC.bin", 0x48, 0x24

glabel D_8032FE18
	.incbin "bin/sm64.j.0EADAC.bin", 0x6C, 0x24

glabel D_8032FE3C
	.incbin "bin/sm64.j.0EADAC.bin", 0x90, 0x10

glabel D_8032FE4C
	.incbin "bin/sm64.j.0EADAC.bin", 0xA0, 0x8

glabel D_8032FE54
	.incbin "bin/sm64.j.0EADAC.bin", 0xA8, 0x6C