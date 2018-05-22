#ifndef _LEVEL_FUNCTIONS_H
#define _LEVEL_FUNCTIONS_H

#include "types.h"

extern s16 D_8035FEF2;
extern s16 D_8035FEF4;
extern s16 D_8035FEEC;
extern s16 D_8035FEE6;
extern s16 D_8035FEE0;

extern u32 D_8033C110;
extern struct Object D_8033C118[];
extern struct Struct80278464 *D_8035FE0C;
extern u32 D_8033BF00;
extern s16 D_8035FEEE;
extern s16 D_8035FEF0;
extern s16 D_8035FDF8;
// extern ? D_80336610;
extern void **gLoadedGeoLayouts;
extern struct Object *D_8035FDE0;
// extern ? D_8032F0B4;
// extern ? D_8035FF00;
// extern ? TableMrIParticleActions;
// extern ? D_8032F124;
// extern ? TableMrIActions;
// extern ? D_8032F134;
// extern ? TableCapSwitchActions;
// extern ? D_803366B0;
// extern ? TableKingBobombActions;
// extern ? D_8032F180;
// extern ? D_8035FEEA;
// extern ? TableOpenedCannonActions;
// extern ? D_803366B4;
// extern ? D_803366BC;
// extern ? D_803366C4;
// extern ? TableChuckyaActions;
// extern ? D_803366C8;
// extern ? D_8032F260;
// extern ? D_8032F273;
// extern ? D_8032F271;
// extern ? D_8032F270;
// extern ? D_8032F284;
// extern ? D_8032F294;
// extern ? TableCoinInsideBooActions;
// extern ? D_8035FEE4;
// extern ? TableGrindelThwompActions;
// extern ? D_8032F34C;
// extern ? TableTumblingBridgeActions;
// extern ? TableElevatorActions;
// extern ? D_8032F3CC;
// extern ? D_8032F3E0;
// extern ? D_8032F3F4;
// extern ? D_8032F3FC;
// extern ? TableLittleCageActions;
// extern ? D_8032F420;
// extern ? D_8032F430;
// extern ? D_8032F440;
// extern ? D_8032F450;
// extern ? D_07018528;
// extern ? TableHeaveHoActions;
// extern ? D_8032F498;
// extern ? TableJumpingBoxActions;
// extern ? D_8032F4B0;
// extern ? D_8035FF10;
// extern ? TableBetaBooKeyInsideActions;
// extern ? D_8032F4CC;
// extern ? TableBulletBillActions;
// extern ? TableBowserTailAnchorActions;
// extern ? D_060576FC;
// extern ? D_8032F50C;
// extern ? D_8032F510;
// extern ? D_803366D0;
// extern ? D_8032F514;
// extern ? TableBowserActions;
// extern ? D_8032F5B8;
// extern ? TableFallingBowserPlatformActions;
// extern ? D_8032F738;
// extern ? D_8032F728;
// extern ? D_8032F754;
// extern ? D_8035FFAC;
// extern ? D_0707768C;
// extern ? D_070775B4;
extern s32 D_8035FE18[2];
// extern ? D_8035FEE8;
// extern ? D_8032F77C;
// extern ? TableUkikiOpenCageActions;
// extern ? D_8032F7D8;
// extern ? D_803366D8;
// extern ? D_803366E4;
// extern ? D_803366F0;
// extern ? TableRotatingCwFireBarsActions;
// extern ? D_8032F8E0;
// extern ? TableToxBoxActions;
// extern ? D_8032F998;
// extern ? TablePiranhaPlantActions;
// extern ? D_8032FB4C;
// extern ? TableBowserPuzzlePieceActions;
// extern ? TableTuxiesMotherActions;
// extern ? TableSmallPenguinActions;
// extern ? D_0301C2B0;
// extern ? D_0600E264;
// extern ? TableFishActions;
// extern ? TableFishGroupActions;
// extern ? TableBirdChirpChirpActions;
// extern ? TableCheepCheepActions;
// extern ? D_8032FC30;
// extern ? D_8032FC40;
// extern ? TableExclamationBoxActions;
// extern ? D_8032FCD8;
// extern ? D_8032FCE8;
// extern ? D_803366FC;
// extern ? D_8032FCF8;
// extern ? TableTweesterActions;
// extern ? D_8032FD24;
// extern ? TableBooActions;
// extern ? D_8032FD14;
// extern ? TableBooGivingStarActions;
// extern ? TableBooWithCageActions;
// extern ? D_8032FD74;
// extern ? TableWhompActions;
// extern ? D_8032FDAC;
// extern ? D_8032FDF4;
// extern ? D_8032FE3C;
// extern ? D_8032FE4C;
// extern ? D_80336704;
// extern ? D_8033670C;

// extern ? Geo18_8029D890(?);
// extern ? Geo18_8029D924(?);
// extern ? GeoSwitchCase8029DB48(?);
// extern ? GeoSwitchCaseBlinking(?);
// extern ? func_8029D558(?);
// extern ? func_8029D704(?);
// extern ? DistanceFromObject(?);
extern f32 objects_calc_distance(struct Object *, struct Object *);
// extern ? func_8029DC1C(?);
// extern ? func_8029DC6C(?);
// extern ? func_8029DD18(?);
// extern ? RotateTorwardsMario(?);
// extern ? func_8029DE70(?);
extern u32 func_8029DF18(struct Object *, struct Object *);
// extern ? UnknownMove(?);
// extern ? func_8029E140(?);
// extern ? func_8029E198(?);
// extern ? func_8029E1F0(?);
extern struct Object *func_8029E230(struct Object *, s16, u32, void *, s16, s16, s16, s16, s16, s16);
// extern ? func_8029E2A8(?);
// extern ? Unknown8029E330(?);
extern void func_8029E388(struct Object *, u32);
extern struct Object *func_8029E5A4(struct Object *, u32, u32, u32);
extern struct Object *SpawnObj(struct Object *, s32, void *);
// extern ? func_8029E6A8(?);
// extern ? func_8029E73C(?);
// extern ? func_8029E7A4(?);
extern void SpawnObjAdv(int, int, int, int, struct Object *, int, void *);
// extern ? func_8029E880(?);
// extern ? Unknown8029E8F4(?);
// extern ? func_8029E94C(?);
extern void CopyObjParams(struct Object *, struct Object *);
// extern ? CopyObjPosition(?);
// extern ? CopyObjRotation(?);
// extern ? func_8029EA0C(?);
// extern ? Unknown8029EA34(?);
extern void func_8029EA84(f32 [4][4], Vec3f, Vec3f);
extern void func_8029EAF8(f32 [4][4], Vec3f, Vec3f);
// extern ? func_8029EB70(?);
// extern ? CopyObjScaling(?);
// extern ? ScaleXYZ(?);
// extern ? func_8029EC88(?);
extern void ScaleObject(float);
// extern ? SetObjAnimation(?);
// extern ? func_8029ED38(?);
// extern ? func_8029ED98(?);
// extern ? func_8029EE20(?);
// extern ? Unknown8029EE84(?);
// extern ? HideObject(?);
// extern ? Unknown8029EEC8(?);
// extern ? func_8029EEF0(?);
// extern ? func_8029EF18(?);
extern void UnHideObject(void);
// extern ? func_8029EF64(?);
// extern ? func_8029F05C(?);
// extern ? func_8029F0A4(?);
// extern ? Unknown8029F0CC(?);
extern void func_8029F170(struct Object *);
// extern ? func_8029F198(?);
// extern ? func_8029F1E0(?);
// extern ? func_8029F21C(?);
// extern ? func_8029F270(?);
extern struct Object *func_8029F3A0(void);
// extern ? Unknown8029F3EC(?);
// extern ? func_8029F460(?);
// extern ? func_8029F520(?);
// extern ? func_8029F610(?);
// extern ? func_8029F638(?);
// extern ? func_8029F684(?);
// extern ? func_8029F6F0(?);
// extern ? func_8029F728(?);
// extern ? func_8029F788(?);
// extern ? func_8029F828(?);
extern int func_8029F88C(int);
// extern ? func_8029F8D4(?);
// extern ? Unknown8029F930(?);
// extern ? func_8029F998(?);
// extern ? func_8029F9D8(?);
// extern ? func_8029FA1C(?);
// extern ? func_8029FA5C(?);
// extern ? func_8029FAB8(?);
// extern ? func_8029FC04(?);
// extern ? func_8029FCF8(?);
// extern ? SetModel(?);
// extern ? Unknown8029FD74(?);
// extern ? func_8029FD98(?);
// extern ? DeactivateObject(?);
// extern ? func_8029FE00(?);
// extern ? func_8029FE38(?);
// extern ? func_8029FE58(?);
// extern ? func_8029FE74(?);
// extern ? func_8029FE88(?);
// extern ? func_8029FED0(?);
// extern ? func_8029FF20(?);
// extern ? func_802A0020(?);
// extern ? func_802A006C(?);
// extern ? func_802A0334(?);
// extern ? func_802A0460(?);
// extern ? func_802A0608(?);
// extern ? func_802A06EC(?);
// extern ? func_802A0974(?);
// extern ? Unknown802A09C0(?);
// extern ? func_802A0A2C(?);
extern void func_802A0A90(void);
extern void func_802A0B28(void);
// extern ? PreMoveObj(?);
// extern ? func_802A0BF4(?);
// extern ? func_802A0CA8(?);
// extern ? func_802A0D10(?);
// extern ? SetObjBehavior(?);
extern s32 CheckObjBehavior(u32 *);
// extern ? CheckObjBehavior2(?);
// extern ? func_802A0E30(?);
// extern ? func_802A0EB8(?);
// extern ? Unknown802A0F30(?);
// extern ? Unknown802A0FF8(?);
// extern ? func_802A10D0(?);
// extern ? func_802A1110(?);
// extern ? func_802A1160(?);
// extern ? func_802A11B4(?);
// extern ? Unknown802A11E4(?);
// extern ? func_802A1230(?);
// extern ? func_802A124C(?);
// extern ? func_802A1274(?);
// extern ? func_802A129C(?);
// extern ? func_802A13B8(?);
// extern ? func_802A1410(?);
// extern ? func_802A1460(?);
// extern ? Unknown802A14EC(?);
// extern ? Unknown802A1548(?);
// extern ? func_802A1600(?);
// extern ? func_802A17C0(?);
// extern ? func_802A1978(?);
// extern ? func_802A1A2C(?);
// extern ? MoveRelated(?);
// extern ? MoveObj(?);
// extern ? func_802A1D28(?);
// extern ? func_802A1E0C(?);
// extern ? MoveObj2(?);
// extern ? Unknown802A1ECC(?);
// extern ? func_802A1FA0(?);
// extern ? func_802A2008(?);
// extern ? func_802A205C(?);
extern void func_802A2188(struct Object *, s32, s32);
extern void func_802A2270(struct Object *);
extern void func_802A22DC(struct Object *);
// extern ? Unknown802A2380(?);
// extern ? Unknown802A23C4(?);
// extern ? BehBreakBoxTriangleLoop(?);
// extern ? Unknown802A2474(?);
// extern ? func_802A24B4(?);
// extern ? func_802A272C(?);
// extern ? func_802A276C(?);
// extern ? func_802A27B4(?);
// extern ? func_802A2818(?);
// extern ? func_802A28E4(?);
// extern ? func_802A297C(?);
// extern ? func_802A2A38(?);
// extern ? func_802A2AC0(?);
// extern ? func_802A2B04(?);
// extern ? func_802A2CFC(?);
// extern ? func_802A2E5C(?);
extern f32 func_802A2E8C(f32);
// extern ? func_802A2ECC(?);
// extern ? func_802A2EFC(?);
// extern ? IsMarioGroundPounding(?);
// extern ? func_802A3004(?);
// extern ? func_802A3034(?);
// extern ? func_802A3070(?);
// extern ? func_802A3164(?);
// extern ? BehDustSmokeLoop(?);
// extern ? func_802A32A4(?);
// extern ? func_802A32E0(?);
// extern ? Unknown802A3380(?);
// extern ? func_802A3398(?);
// extern ? func_802A3470(?);
// extern ? IsMarioStepping(?);
// extern ? Unknown802A3598(?);
// extern ? func_802A362C(?);
// extern ? func_802A3688(?);
// extern ? func_802A36D8(?);
// extern ? Unknown802A3750(?);
// extern ? func_802A377C(?);
// extern ? func_802A37A0(?);
// extern ? func_802A38A4(?);
// extern ? func_802A3910(?);
extern void BehCommonInit(void); // 802A3978
extern void func_802A3A68(void);
// extern ? func_802A3BB8(?);
// extern ? func_802A3C98(?);
// extern ? func_802A3D4C(?);
// extern ? func_802A3D84(?);
// extern ? func_802A3DBC(?);
// extern ? Geo18_802A45E4(?);
// extern ? Unknown802A3E84(?);
// extern ? func_802A3F24(?);
// extern ? func_802A3F5C(?);
// extern ? func_802A3F80(?);
// extern ? func_802A3FA8(?);
// extern ? func_802A3FCC(?);
// extern ? func_802A3FF8(?);
// extern ? func_802A4114(?);
// extern ? func_802A4154(?);
// extern ? func_802A41B8(?);
// extern ? CreateMessageBox(?);
// extern ? func_802A472C(?);
// extern ? func_802A4780(?);
// extern ? Unknown802A485C(?);
// extern ? ShakeScreen(?);
// extern ? func_802A4964(?);
// extern ? func_802A49D4(?);
// extern ? func_802A4A50(?);
// extern ? func_802A4A70(?);
// extern ? func_802A4AB0(?);
// extern ? func_802A4AEC(?);
// extern ? func_802A4B20(?);
// extern ? func_802A4B80(?);
// extern ? Unknown802A4C34(?);
// extern ? Unknown802A4C88(?);
// extern ? func_802A4CC0(?);
// extern ? func_802A4D00(?);
// extern ? func_802A4D4C(?);
// extern ? func_802A4DB0(?);
// extern ? BehStarDoorLoop(?);
// extern ? BehPiranhaParticleLoop(?);
// extern ? ActionMrIParticle0(?);
// extern ? ActionMrIParticle1(?);
// extern ? BehMrIParticleLoop(?);
// extern ? func_802A525C(?);
// extern ? BehMrIBodyLoop(?);
// extern ? ActionMrI3(?);
// extern ? ActionMrI2(?);
// extern ? ActionMrI1(?);
// extern ? ActionMrI0(?);
// extern ? BehMrILoop(?);
// extern ? BehPoleInit(?);
// extern ? BehGiantPoleLoop(?);
// extern ? BehThiTopTrapLoop(?);
// extern ? BehThiTinyTopLoop(?);
// extern ? ActionActivateCapSwitch0(?);
// extern ? ActionActivateCapSwitch1(?);
// extern ? ActionActivateCapSwitch2(?);
// extern ? ActionActivateCapSwitch3(?);
// extern ? BehActivateCapSwitchLoop(?);
// extern ? Geo18_802A719C(?);
// extern ? BehBobombAnchorMarioLoop(?);
// extern ? ActionKingBobomb0(?);
// extern ? func_802A6AF8(?);
// extern ? ActionKingBobomb2(?);
// extern ? ActionKingBobomb3(?);
// extern ? ActionKingBobomb1(?);
// extern ? ActionKingBobomb6(?);
// extern ? ActionKingBobomb7(?);
// extern ? ActionKingBobomb8(?);
// extern ? ActionKingBobomb4(?);
// extern ? ActionKingBobomb5(?);
// extern ? func_802A7748(?);
// extern ? BehKingBobombLoop(?);
// extern ? BehBetaChestInit(?);
// extern ? BehBetaChestLoop(?);
// extern ? BehBetaChestUpperLoop(?);
// extern ? BehWaterAirBubbleInit(?);
// extern ? BehWaterAirBubbleLoop(?);
// extern ? BehBubbleWaveInit(?);
// extern ? Unknown802A7E48(?);
// extern ? BehBubbleMaybeLoop(?);
// extern ? BehSmallWaterWaveLoop(?);
// extern ? func_802A81C4(?);
// extern ? BehParticleInit(?);
// extern ? BehParticleLoop(?);
// extern ? BehSmallBubblesLoop(?);
// extern ? BehFishGroupLoop(?);
// extern ? BehWaterWavesInit(?);
// extern ? BehCannonBaseLoop(?);
// extern ? ActionOpenedCannon0(?);
// extern ? ActionOpenedCannon4(?);
// extern ? ActionOpenedCannon6(?);
// extern ? ActionOpenedCannon5(?);
// extern ? ActionOpenedCannon1(?);
// extern ? ActionOpenedCannon2(?);
// extern ? ActionOpenedCannon3(?);
// extern ? BehOpenedCannonLoop(?);
// extern ? BehCannonBarrelLoop(?);
// extern ? func_802A8D18(?);
// extern ? BehChuckyaAnchorMarioLoop(?);
// extern ? Unknown802A8EC8(?);
// extern ? func_802A9050(?);
// extern ? ActionChuckya0(?);
// extern ? ActionChuckya1(?);
// extern ? ActionChuckya3(?);
// extern ? ActionChuckya2(?);
// extern ? func_802A97B8(?);
// extern ? BehChuckyaLoop(?);
// extern ? BehBreakableWallLoop(?);
// extern ? func_802A9A0C(?);
// extern ? func_802A9B54(?);
// extern ? BehKickableBoardLoop(?);
// extern ? BehTowerDoorLoop(?);
// extern ? BehClocklikeRotationLoop(?);
// extern ? BehRotatingPlatformLoop(?);
// extern ? func_802AA0D4(?);
// extern ? BehKoopaShellUnderwaterLoop(?);
// extern ? BehWarpLoop(?);
// extern ? BehFadingWarpLoop(?);
// extern ? BehWhitePuffExplosingLoop(?);
// extern ? func_802AA618(?);
// extern ? BehUnused080CInit(?);
// extern ? func_802AA788(?);
// extern ? func_802AA7EC(?);
// extern ? func_802AA8E4(?);
// extern ? func_802AA918(?);
// extern ? BehUnused080CLoop(?);
extern void func_802AACE4(u32);
// extern ? func_802AAD54(?);
// extern ? BehTempCoinInit(?);
// extern ? BehCollectableCoinLoop(?);
// extern ? BehTempCoingLoop(?);
// extern ? BehCoinInit(?);
// extern ? BehCoinLoop(?);
// extern ? BehCoinFormationSpawnLoop(?);
// extern ? func_802AB364(?);
// extern ? BehCoinFormationInit(?);
// extern ? BehCoinFormationLoop(?);
// extern ? ActionCoinInsideBoo1(?);
// extern ? ActionCoinInsideBoo0(?);
// extern ? BehCoinInsideBooLoop(?);
// extern ? BehCoinSparklesLoop(?);
// extern ? BehGoldenCoinSparklesLoop(?);
// extern ? BehPunchTinyTriangleLoop(?);
// extern ? BehPunchTinyTriangleInit(?);
// extern ? BehWallTinyStarParticleLoop(?);
// extern ? BehTinyStarParticlesInit(?);
// extern ? BehPoundTinyStarParticleLoop(?);
// extern ? BehPoundTinyStarParticleInit(?);
// extern ? func_802AC070(?);
// extern ? func_802AC0B8(?);
// extern ? func_802AC130(?);
// extern ? func_802AC1CC(?);
// extern ? BehDoorLoop(?);
// extern ? BehDoorInit(?);
// extern ? BehStarDoorLoop2(?);
// extern ? ActionGrindelThwomp4(?);
// extern ? ActionGrindelThwomp2(?);
// extern ? ActionGrindelThwomp3(?);
// extern ? ActionGrindelThwomp1(?);
// extern ? ActionGrindelThwomp0(?);
// extern ? BehGrindelThwompLoop(?);
// extern ? BehTumblingBridgePlatformLoop(?);
// extern ? ActionTumblingBridge1(?);
// extern ? ActionTumblingBridge2(?);
// extern ? ActionTumblingBridge3(?);
// extern ? ActionTumblingBridge0(?);
// extern ? BehTumblingBridgeLoop(?);
// extern ? func_802AD01C(?);
// extern ? ActionElevator0(?);
// extern ? ActionElevator1(?);
// extern ? ActionElevator2(?);
// extern ? ActionElevator4(?);
// extern ? ActionElevator3(?);
// extern ? BehElevatorInit(?);
// extern ? BehElevatorLoop(?);
// extern ? BehWaterMistSpawnLoop(?);
// extern ? BehWaterMistLoop(?);
// extern ? func_802AD82C(?);
// extern ? BehWaterMist2Loop(?);
// extern ? BehPoundWhitePuffsInit(?);
// extern ? func_802ADA94(?);
// extern ? BehUnused0E40Init(?);
// extern ? Unknown802ADAF4(?);
// extern ? func_802ADBBC(?);
// extern ? BehGroundSnowInit(?);
// extern ? func_802ADC20(?);
// extern ? BehWindLoop(?);
// extern ? BehPiranhaParticlesSpawnLoop(?);
// extern ? BehLittleCage2Loop(?);
// extern ? ActionLittleCage0(?);
// extern ? ActionLittleCage1(?);
// extern ? ActionLittleCage2(?);
// extern ? ActionLittleCage3(?);
// extern ? BehLittleCageLoop(?);
// extern ? BehSquishablePlatformLoop(?);
// extern ? BehBifsSinkingPlatformLoop(?);
// extern ? BehDddMovingPoleLoop(?);
// extern ? BehBifsSinkingCagePlatformLoop(?);
// extern ? BehBetaMovingFlamesSpawnLoop(?);
// extern ? BehBetaMovingFlamesLoop(?);
// extern ? BehFlamethrowerFlameLoop(?);
// extern ? BehFlamethrowerLoop(?);
// extern ? BehRrRotatingPlatformFireLoop(?);
// extern ? BehBouncingFireballFlameLoop(?);
// extern ? BehBouncingFireballLoop(?);
// extern ? BehBowserShockWave(?);
// extern ? BehBlackSmokeUpwardLoop(?);
// extern ? BehBlackSmokeBowserLoop(?);
// extern ? BehBlackSmokeMarioLoop(?);
// extern ? BehFlameMarioLoop(?);
// extern ? BehMultipleCoinsLoop(?);
// extern ? BehSpindriftLoop(?);
// extern ? BehWfSolidPlatformLoop(?);
// extern ? BehWfElevatorPlatformLoop(?);
// extern ? BehWfSlidingPlatformLoop(?);
// extern ? func_802AF9A4(?);
// extern ? func_802AFAFC(?);
// extern ? BehTowerPlatformGroupLoop(?);
// extern ? BehTreeSnowOrLeafLoop(?);
// extern ? BehSnowLeafParticleSpawnInit(?);
// extern ? func_802B02FC(?);
// extern ? BehSquarishPathMovingLoop(?);
// extern ? BehPiranhaPlantWakingBubblesLoop(?);
// extern ? BehPiranhaPlantBubbleLoop(?);
// extern ? BehFloorSwitchLoop(?);
// extern ? func_802B0C54(?);
// extern ? BehPushableLoop(?);
// extern ? func_802B0E74(?);
// extern ? func_802B0F54(?);
// extern ? func_802B1138(?);
// extern ? BehHiddenObjectLoop(?);
// extern ? BehBreakableBoxLoop(?);
// extern ? Geo18_802B1BB0(?);
// extern ? BehHeaveHoThrowMarioLoop(?);
// extern ? ActionHeaveHo1(?);
// extern ? ActionHeaveHo2(?);
// extern ? ActionHeaveHo3(?);
// extern ? ActionHeaveHo0(?);
// extern ? func_802B18B4(?);
// extern ? BehHeaveHoLoop(?);
// extern ? BehCcmTouchedStarSpawnLoop(?);
// extern ? BehPoundExplodesLoop(?);
// extern ? BehBetaTrampolineSpawnLoop(?);
// extern ? BehBetaTrampolineLoop(?);
// extern ? ActionJumpingBox0(?);
// extern ? ActionJumpingBox1(?);
// extern ? func_802B1F84(?);
// extern ? BehJumpingBoxLoop(?);
// extern ? BehBooCageLoop(?);
// extern ? func_802B2328(?);
// extern ? BehBetaBooKeyOutsideLoop(?);
// extern ? ActionBetaBooKeyInside2(?);
// extern ? ActionBetaBooKeyInside1(?);
// extern ? ActionBetaBooKeyInside0(?);
// extern ? BehBetaBooKeyInsideLoop(?);
// extern ? func_802B2894(?);
// extern ? func_802B29B0(?);
// extern ? BehGrandStarLoop(?);
// extern ? BehBowserKey2Loop(?);
// extern ? BehWhitePuffSmokeInit(?);
// extern ? BehBulletBillInit(?);
// extern ? ActionBulletBill0(?);
// extern ? ActionBulletBill1(?);
// extern ? ActionBulletBill2(?);
// extern ? ActionBulletBill3(?);
// extern ? ActionBulletBill4(?);
// extern ? BehBulletBillLoop(?);
// extern ? ActionBowserTailAnchor0(?);
// extern ? ActionBowserTailAnchor1(?);
// extern ? ActionBowserTailAnchor2(?);
// extern ? BehBowserTailAnchorLoop(?);
// extern ? BehBowserFlameSpawnLoop(?);
// extern ? BehBowserBodyAnchorLoop(?);
// extern ? func_802B38B4(?);
// extern ? func_802B392C(?);
// extern ? func_802B39B8(?);
// extern ? func_802B3A30(?);
// extern ? func_802B3A98(?);
// extern ? func_802B3B0C(?);
// extern ? ActionBowser5(?);
// extern ? ActionBowser6(?);
// extern ? Unknown802B3CCC(?);
// extern ? func_802B3D24(?);
// extern ? func_802B3E44(?);
// extern ? func_802B3FDC(?);
// extern ? func_802B4124(?);
// extern ? func_802B4144(?);
// extern ? ActionBowser18(?);
// extern ? ActionBowser0(?);
// extern ? ActionBowser15(?);
// extern ? ActionBowser14(?);
// extern ? ActionBowser16(?);
// extern ? ActionBowser8(?);
// extern ? ActionBowser12(?);
// extern ? func_802B4A44(?);
// extern ? func_802B4A94(?);
// extern ? func_802B4BA4(?);
// extern ? ActionBowser13(?);
// extern ? ActionBowser17(?);
// extern ? ActionBowser10(?);
// extern ? ActionBowser9(?);
// extern ? func_802B5108(?);
// extern ? ActionBowser11(?);
// extern ? ActionBowser7(?);
// extern ? func_802B5588(?);
// extern ? ActionBowser1(?);
// extern ? func_802B5738(?);
// extern ? ActionBowser2(?);
// extern ? ActionBowser3(?);
// extern ? func_802B5C78(?);
// extern ? func_802B5D18(?);
// extern ? func_802B5DD8(?);
// extern ? func_802B5E7C(?);
// extern ? func_802B5F20(?);
// extern ? func_802B60B8(?);
// extern ? func_802B6120(?);
// extern ? func_802B6254(?);
// extern ? ActionBowser4(?);
// extern ? func_802B64E8(?);
// extern ? ActionBowser19(?);
// extern ? func_802B67C4(?);
// extern ? func_802B688C(?);
// extern ? func_802B697C(?);
// extern ? func_802B6AC0(?);
// extern ? BehBowserLoop(?);
// extern ? BehBowserInit(?);
// extern ? Geo18_802B798C(?);
// extern ? func_802B70C8(?);
// extern ? GeoSwitchCase802B7C64(?);
// extern ? Geo18_802B7D44(?);
// extern ? ActionFallingBowserPlatform0(?);
// extern ? ActionFallingBowserPlatform1(?);
// extern ? ActionFallingBowserPlatform2(?);
// extern ? BehFallingBowserPlatformLoop(?);
// extern ? func_802B7A58(?);
// extern ? func_802B7ADC(?);
// extern ? BehFlameBowserInit(?);
// extern ? BehFlameLargeBurningOutInit(?);
// extern ? func_802B7CFC(?);
// extern ? BehFlameBowserLoop(?);
// extern ? BehFlameMovingForwardGrowingInit(?);
// extern ? BehFlameMovingForwardGrowingLoop(?);
// extern ? BehFlameFloatingLandingInit(?);
// extern ? BehFlameFloatingLandingLoop(?);
// extern ? BehBlueBowserFlameInit(?);
// extern ? BehBlueBowserFlameLoop(?);
// extern ? BehFlameBouncingInit(?);
// extern ? BehFlameBouncingLoop(?);
// extern ? BehBlueFlamesGroupLoop(?);
// extern ? BehBlueFishLoop(?);
// extern ? BehTankFishGroupsLoop(?);
// extern ? func_802B8F7C(?);
// extern ? BehCheckerboardElevatorGroupInit(?);
// extern ? func_802B9120(?);
// extern ? func_802B91A0(?);
// extern ? BehCheckerboardPlatformInit(?);
// extern ? BehCheckerboardPlatformLoop(?);
// extern ? BehDddWarpLoop(?);
// extern ? func_802B95A4(?);
// extern ? func_802B97E4(?);
// extern ? BehWaterLevelPillarInit(?);
// extern ? BehWaterLevelPillarLoop(?);
// extern ? BehInvisibleObjUnderBridge(?);
// extern ? Geo18_802BA2B0(?);
// extern ? BehDoorKey1Loop(?);
// extern ? BehDoorKey2Loop(?);
// extern ? BehMoatGrillsLoop(?);
// extern ? BehRotatingClockArmLoop(?);
// extern ? func_802B9E88(?);
// extern ? func_802B9F10(?);
// extern ? Unknown802B9F6C(?);
// extern ? func_802BA000(?);
// extern ? ActionUkikiOpenCage0(?);
// extern ? ActionUkikiOpenCage7(?);
// extern ? ActionUkikiOpenCage5(?);
// extern ? ActionUkikiOpenCage6(?);
// extern ? ActionUkikiOpenCage2(?);
// extern ? ActionUkikiOpenCage1(?);
// extern ? ActionUkikiOpenCage3(?);
// extern ? ActionUkikiOpenCage4(?);
// extern ? func_802BAE40(?);
// extern ? Unknown802BAEE0(?);
// extern ? func_802BAF30(?);
// extern ? func_802BB0E4(?);
// extern ? BehUkikiOpenCageInit(?);
// extern ? BehUkikiOpenCageLoop(?);
// extern ? func_802BB414(?);
// extern ? func_802BB680(?);
// extern ? BehHorizontalMovementLoop(?);
// extern ? BehSinkWhenSteppedOnLoop(?);
// extern ? BehLllRotatingHexFlameLoop(?);
// extern ? func_802BB9F0(?);
// extern ? ActionRotatingCwFireBars0(?);
// extern ? ActionRotatingCwFireBars1(?);
// extern ? ActionRotatingCwFireBars2(?);
// extern ? ActionRotatingCwFireBars3(?);
// extern ? BehRotatingCwFireBarsLoop(?);
// extern ? BehLllWoodPieceLoop(?);
// extern ? BehFloatingWoodBridgeLoop(?);
// extern ? BehVolcanoFlamesLoop(?);
// extern ? func_802BBFDC(?);
// extern ? BehLllRotatingPlatformLoop(?);
// extern ? func_802BC390(?);
// extern ? BehLllSlowTiltingMovementLoop(?);
// extern ? BehLllSlowUpDownMovementLoop(?);
// extern ? func_802BC544(?);
// extern ? BehTiltingPlatformInit(?);
// extern ? func_802BC66C(?);
// extern ? BehTiltingPlatformLoop(?);
// extern ? func_802BCA8C(?);
// extern ? BehKoopaShellFlameLoop(?);
// extern ? func_802BCC84(?);
// extern ? func_802BCCD4(?);
// extern ? BehKoopaShellLoop(?);
// extern ? func_802BCF78(?);
// extern ? func_802BCFC4(?);
// extern ? ActionToxBox4(?);
// extern ? ActionToxBox5(?);
// extern ? ActionToxBox6(?);
// extern ? ActionToxBox7(?);
// extern ? ActionToxBox1(?);
// extern ? ActionToxBox2(?);
// extern ? ActionToxBox3(?);
// extern ? ActionToxBox0(?);
// extern ? BehToxBoxLoop(?);
// extern ? ActionPiranhaPlant20(?);
// extern ? func_802BD4A8(?);
// extern ? ActionPiranhaPlant21(?);
// extern ? ActionPiranhaPlant23(?);
// extern ? ActionPiranhaPlant25(?);
// extern ? ActionPiranhaPlant26(?);
// extern ? ActionPiranhaPlant27(?);
// extern ? ActionPiranhaPlant28(?);
// extern ? ActionPiranhaPlant22(?);
// extern ? func_802BDAD4(?);
// extern ? ActionPiranhaPlant24(?);
// extern ? BehPiranhaPlant2Loop(?);
// extern ? func_802BDC60(?);
// extern ? func_802BDD0C(?);
// extern ? BehBowserPuzzleLoop(?);
// extern ? ActionBowserPuzzlePiece0(?);
// extern ? ActionBowserPuzzlePiece1(?);
// extern ? func_802BDF2C(?);
// extern ? func_802BE014(?);
// extern ? ActionBowserPuzzlePiece2(?);
// extern ? ActionBowserPuzzlePiece3(?);
// extern ? ActionBowserPuzzlePiece4(?);
// extern ? ActionBowserPuzzlePiece5(?);
// extern ? ActionBowserPuzzlePiece6(?);
// extern ? BehBowserPuzzlePieceLoop(?);
// extern ? func_802BE2E8(?);
// extern ? func_802BE3B4(?);
// extern ? ActionTuxiesMother2(?);
// extern ? ActionTuxiesMother1(?);
// extern ? ActionTuxiesMother0(?);
// extern ? BehTuxiesMotherLoop(?);
// extern ? func_802BEA58(?);
// extern ? ActionSmallPenguin2(?);
// extern ? ActionSmallPenguin1(?);
// extern ? ActionSmallPenguin3(?);
// extern ? ActionSmallPenguin4(?);
// extern ? ActionSmallPenguin0(?);
// extern ? ActionSmallPenguin5(?);
// extern ? func_802BF048(?);
// extern ? BehSmallPenguinLoop(?);
// extern ? GeoSwitchCase802BFBAC(?);
// extern ? ActionFish0(?);
// extern ? ActionFish1(?);
// extern ? ActionFish2(?);
// extern ? BehFishLoop(?);
// extern ? func_802BF59C(?);
// extern ? ActionFishGroup1(?);
// extern ? ActionFishGroup2(?);
// extern ? ActionFishGroup0(?);
// extern ? BehFishGroup2Loop(?);
// extern ? BehWdwExpressElevatorLoop(?);
// extern ? ActionBirdChirpChirp0(?);
// extern ? ActionBirdChirpChirp1(?);
// extern ? ActionBirdChirpChirp2(?);
// extern ? ActionBirdChirpChirp3(?);
// extern ? BehBirdChirpChirpLoop(?);
// extern ? func_802C0240(?);
// extern ? ActionCheepCheep0(?);
// extern ? ActionCheepCheep1(?);
// extern ? ActionCheepCheep2(?);
// extern ? BehCheepCheepLoop(?);
// extern ? BehRotatinExclamationBoxLoop(?);
// extern ? ActionExclamationBox0(?);
// extern ? ActionExclamationBox1(?);
// extern ? ActionExclamationBox2(?);
// extern ? ActionExclamationBox3(?);
// extern ? func_802C0DF0(?);
// extern ? ActionExclamationBox4(?);
// extern ? ActionExclamationBox5(?);
// extern ? BehExclamationBoxLoop(?);
// extern ? BehPlaySound(?);
// extern ? BehBowsersSubLoop(?);
// extern ? BehSushiSharkCollisionLoop(?);
// extern ? BehSushiSharkLoop(?);
// extern ? BehSunkenShipPartLoop(?);
// extern ? BehShipPart3Loop(?);
// extern ? BehJrbSlidingBox(?);
// extern ? BehWhitePuff1Loop(?);
// extern ? BehWhitePuff2Loop(?);
// extern ? BehHiddenBlueCoinsLoop(?);
// extern ? BehBlueCoinSwitchLoop(?);
// extern ? BehBobHmcCageDoorLoop(?);
// extern ? BehOpenableGrillLoop(?);
// extern ? BehInitWaterLevelTriggerLoop(?);
// extern ? BehWaterLevelTriggerLoop(?);
// extern ? func_802C231C(?);
// extern ? ActionTweester0(?);
// extern ? ActionTweester1(?);
// extern ? ActionTweester2(?);
// extern ? BehTweesterLoop(?);
// extern ? BehTweesterSandParticleLoop(?);
// extern ? func_802C2A28(?);
// extern ? BehBooInit(?);
// extern ? func_802C2A94(?);
// extern ? func_802C2B68(?);
// extern ? BehBooGroupInit(?);
// extern ? func_802C2D7C(?);
// extern ? func_802C2EB8(?);
// extern ? func_802C3008(?);
// extern ? func_802C313C(?);
// extern ? func_802C3238(?);
// extern ? func_802C3304(?);
// extern ? func_802C3384(?);
// extern ? func_802C33D0(?);
// extern ? func_802C34B4(?);
// extern ? func_802C35C0(?);
// extern ? func_802C3738(?);
// extern ? func_802C3778(?);
// extern ? func_802C3830(?);
// extern ? ActionBoo0(?);
// extern ? ActionBoo5(?);
// extern ? ActionBoo1(?);
// extern ? ActionBoo2(?);
// extern ? ActionBoo3(?);
// extern ? ActionBoo4(?);
// extern ? BehBooLoop(?);
// extern ? ActionBooGivingStar0(?);
// extern ? ActionBooGivingStar1(?);
// extern ? ActionBooGivingStar2(?);
// extern ? func_802C41AC(?);
// extern ? func_802C41E4(?);
// extern ? func_802C4220(?);
// extern ? ActionBooGivingStar3(?);
// extern ? ActionBooGivingStar4(?);
// extern ? BehBooGivingStarLoop(?);
// extern ? ActionBooWithCage0(?);
// extern ? ActionBooWithCage1(?);
// extern ? ActionBooWithCage2(?);
// extern ? ActionBooWithCage3(?);
// extern ? BehBooWithCageInit(?);
// extern ? BehBooWithCageLoop(?);
// extern ? BehSpawnBigBooLoop(?);
// extern ? func_802C49E0(?);
// extern ? BehAnimatedTextureLoop(?);
// extern ? BehBooInCastleLoop(?);
// extern ? BehBooBossSpawnedBridgeLoop(?);
// extern ? BehBbhTiltFloorPlatformLoop(?);
// extern ? BehTumblingBookshelfLoop(?);
// extern ? func_802C50F4(?);
// extern ? BehRotatingMerryGoRoundLoop(?);
// extern ? BehStaticCheckeredPlatformLoop(?);
// extern ? BehInsideCannonLoop(?);
// extern ? BehFloorTrapInCastleLoop(?);
// extern ? BehCastleFloorTrapInit(?);
// extern ? func_802C567C(?);
// extern ? func_802C5700(?);
// extern ? func_802C57A4(?);
// extern ? func_802C57E8(?);
// extern ? func_802C5854(?);
// extern ? BehCastleFloorTrapLoop(?);
// extern ? BehClimbDetectLoop(?);
// extern ? BehPowerupSparklesLoop(?);
// extern ? func_802C5A64(?);
// extern ? BehScuttlebugLoop(?);
// extern ? BehScuttlebugSpawnLoop(?);
// extern ? func_802C61CC(?);
// extern ? ActionWhomp0(?);
// extern ? ActionWhomp7(?);
// extern ? ActionWhomp1(?);
// extern ? ActionWhomp2(?);
// extern ? ActionWhomp3(?);
// extern ? ActionWhomp4(?);
// extern ? ActionWhomp5(?);
// extern ? func_802C6954(?);
// extern ? func_802C6B28(?);
// extern ? ActionWhomp6(?);
// extern ? ActionWhomp8(?);
// extern ? ActionWhomp9(?);
// extern ? BehWhompLoop(?);
// extern ? BehWaterSplashLoop(?);
// extern ? BehWaterDropsLoop(?);
// extern ? BehSurfaceWavesLoop(?);
// extern ? BehWaterSurfaceWhiteWaveInit(?);
// extern ? BehGfxInit(?);
// extern ? BehSurfaceWaveShrinkingInit(?);
// extern ? BehWaveTrailLoop(?);
// extern ? BehWhiteWindParticleLoop(?);
// extern ? func_802C76E0(?);
// extern ? BehSnowmanWindBlowingLoop(?);
// extern ? func_802C7AD0(?);
// extern ? BehWalkingPenguinLoop(?);

#endif /* _LEVEL_FUNCTIONS_H */
