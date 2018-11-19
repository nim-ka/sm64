#ifndef OBJECT_HELPERS_H
#define OBJECT_HELPERS_H

#include "types.h"

// used for chain chomp and wiggler
struct ChainSegment
{
    f32 posX;
    f32 posY;
    f32 posZ;
    s16 pitch;
    s16 yaw;
    s16 roll;
};

struct struct8029E388 {
    s16 unk00;
    s16 unk02;
    void *unk04;
    s16 unk08;
    s16 unk0A;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

struct struct802A1230 {
    /*0x00*/ s16 unk00;
    /*0x02*/ s16 unk02;
};

struct Struct802A272C {
    Vec3f vecF;
    Vec3s vecS;
};

struct Struct802A2B04 {
    s8 unk0;
    s8 unk1;
    u8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    f32 unkC;
    f32 unk10;
};

#define TIME_STOP_UNKNOWN_0       (1 << 0)
#define TIME_STOP_ENABLED         (1 << 1)
#define TIME_STOP_UNKNOWN_2       (1 << 2)
#define TIME_STOP_MARIO_AND_DOORS (1 << 3)
#define TIME_STOP_ALL_OBJECTS     (1 << 4)
#define TIME_STOP_UNKNOWN_5       (1 << 5)
#define TIME_STOP_ACTIVE          (1 << 6)

extern s16 D_8035FEF2;
extern s16 D_8035FEF4;
extern s16 D_8035FEEC;
extern s16 D_8035FEE6;
extern s16 gMarioCurrentRoom;

extern struct MemoryPool *D_8035FE0C;
extern u32 gUpdatedObjectCount;
extern s16 gNumRoomedObjectsInMarioRoom;
extern s16 gNumRoomedObjectsNotInMarioRoom;
extern s16 gPostUpdateObjCount;
// extern ? D_80336610;
extern struct GraphNode **gLoadedGraphNodes;
// extern ? sLevelsWithRooms;
// extern ? sGrabReleaseState;
// extern ? TableMrIParticleActions;
// extern ? D_8032F124;
// extern ? TableMrIActions;
// extern ? D_8032F134;
// extern ? TableCapSwitchActions;
// extern ? D_803366B0;
// extern ? TableKingBobombActions;
// extern ? TableKingBobombSoundStates;
// extern ? gMarioShotFromCannon;
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
// extern ? wdw_seg7_collision_07018528;
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
extern s32 gWaterLevels[20];
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
extern void func_8029D558(Mat4, struct Object *);
void apply_object_scale_to_matrix(struct Object *, Mat4, Mat4);
// extern ? func_8029D704(?);
void set_object_held_state(struct Object *, void *);
extern f32 lateral_dist_between_objects(struct Object *, struct Object *);
extern f32 dist_between_objects(struct Object *, struct Object *);
// extern ? obj_forward_vel_approach_upward(?);
// extern ? approach_f32_signed(?);
// extern ? approach_f32_symmetric(?);
extern s16 approach_s16_symmetric(s16 arg0, s16 arg1, s16 arg2);
extern s32 obj_rotate_yaw_toward(s16, s16);
extern s16 angle_to_object(struct Object *, struct Object *);
extern s16 obj_turn_toward_object(struct Object *, struct Object *, s16, s16);
// extern ? set_object_parent_relative_pos(?);
// extern ? set_object_pos(?);
// extern ? set_object_angle(?);
extern struct Object *func_8029E230(struct Object *, s16, u32, void *, s16, s16, s16, s16, s16, s16);
extern struct Object *func_8029E2A8(struct Object *sp20, u32 sp24, void *sp28, s16 sp2E, s16 sp32, s16 sp36, s16 sp3A, s16 sp3E, s16 sp42);
// extern ? Unknown8029E330(?);
extern struct Object *func_8029E388(struct Object *, struct struct8029E388 *);
extern struct Object *spawn_object_at_origin(struct Object *, u32, u32, void *);
extern struct Object *spawn_object(struct Object *, s32, void *);
// extern ? try_to_spawn_object(?);
extern struct Object *spawn_object_with_scale(struct Object *, s32, void *, f32);
// extern ? build_object_transform_relative_to_parent(?);
extern struct Object* spawn_object_relative(s16, s16, s16, s16, struct Object *, s32, void *);
extern struct Object *spawn_object_relative_with_scale(s16, s16, s16, s16, f32, struct Object *, s32, void *);
// extern ? obj_move_using_vel(?);
// extern ? func_8029E94C(?);
extern void copy_object_pos_and_angle(struct Object *, struct Object *);
void copy_object_pos(struct Object *a0, struct Object *a1);
// extern ? copy_object_angle(?);
// extern ? func_8029EA0C(?);
// extern ? Unknown8029EA34(?);
extern void linear_mtxf_mul_vec3f(f32 [4][4], Vec3f, Vec3f);
extern void linear_mtxf_transpose_mul_vec3f(f32 [4][4], Vec3f, Vec3f);
// extern ? apply_scale_to_object_transform(?);
void copy_object_scale(struct Object *toObj, struct Object *fromObj);
extern void scale_object_xyz(struct Object* obj, f32 xScale, f32 yScale, f32 zScale);
extern void scale_object(struct Object *, float);
extern void obj_scale(float);
extern void func_8029ED38(s32);
extern void func_8029ED98(u32, f32);
extern void SetObjAnimation(s32 arg0);
void func_8029EE20(struct Object *a0, u32 *a1, u32 a2);
// extern ? obj_enable_rendering_and_become_tangible(?);
extern void obj_enable_rendering(void);
// extern ? obj_disable_rendering_and_become_intangible(?);
extern void obj_disable_rendering(void);
extern void obj_unhide(void);
extern void obj_hide(void);
extern void obj_set_pos_relative(struct Object *MarioObj, f32, f32, f32);
// extern ? obj_set_pos_relative_to_parent(?);
extern void obj_enable_rendering_2(void);
// extern ? obj_unused_init_on_floor(?);
extern void func_8029F170(struct Object *);
u32 get_object_list_from_behavior(u32 *a0);
extern struct Object *obj_nearest_object_with_behavior(void *);
// extern ? obj_dist_to_nearest_object_with_behavior(?);
extern struct Object *obj_find_nearest_object_with_behavior(void *, f32 *);
extern struct Object *find_unimportant_object(void);
// extern ? count_unimportant_objects(?);
// extern ? count_objects_with_behavior(?);
// extern ? obj_find_nearby_held_actor(?);
// extern ? obj_reset_timer_and_subaction(?);
// extern ? obj_change_action(?);
// extern ? func_8029F684(?);
void func_8029F6F0(void);
extern void func_8029F728(void);
extern s32 func_8029F788(void);
extern s32 func_8029F828(void);
extern int obj_check_anim_frame(int);
extern s32 func_8029F8D4(s32, s32);
// extern ? Unknown8029F930(?);
s32 mario_is_in_air_action(void);
// extern ? mario_is_dive_sliding(?);
// extern ? func_8029FA1C(?);
// extern ? func_8029FA5C(?);
// extern ? obj_move_after_thrown_or_dropped(?);
// extern ? obj_get_thrown_or_placed(?);
extern void obj_get_dropped(void);
extern void obj_set_model(s32);
// extern ? mario_set_flag(?);
// extern ? obj_clear_interact_status_flag(?);
extern void DeactivateObject(struct Object *);
// extern ? func_8029FE00(?);
extern void obj_become_intangible(void);
extern void obj_become_tangible(void);
// extern ? make_object_tangible(?);
void obj_update_floor_height(void);
// extern ? obj_update_floor_height_and_get_floor(?);
// extern ? apply_drag_to_value(?);
// extern ? obj_apply_drag_xz(?);
// extern ? obj_move_xz(?);
// extern ? obj_move_update_underwater_flags(?);
// extern ? obj_move_update_ground_air_flags(?);
// extern ? obj_move_y_and_get_water_level(?);
// extern ? obj_move_y(?);
// extern ? clear_move_flag(?);
// extern ? obj_unused_resolve_wall_collisions(?);
extern s16 abs_angle_diff(s16, s16);
extern void obj_move_xz_using_fvel(void);
extern void obj_move_y_with_terminal_vel(void);
// extern ? obj_compute_vel_xz(?);
// extern ? func_802A0BF4(?);
extern s32 are_objects_collided(struct Object *, struct Object *);
// extern ? obj_set_behavior(?);
// extern ? set_object_behavior(?);
extern s32 obj_has_behavior(u32 *);
// extern ? object_has_behavior(?);
// extern ? obj_lateral_dist_from_mario_to_home(?);
extern f32 obj_lateral_dist_to_home(void);
// extern ? obj_outside_home_square(?);
// extern ? obj_outside_home_rectangle(?);
extern void obj_set_pos_to_home(void);
// extern ? obj_set_pos_to_home_and_stop(?);
extern void obj_shake_y(f32);
// extern ? func_802A11B4(?);
// extern ? Unknown802A11E4(?);
void func_802A1230(struct Object *a0);
// extern ? obj_set_hitbox_radius_and_height(?);
// extern ? func_802A1274(?);
// extern ? spawn_object_loot_coins(?);
// extern ? spawn_object_loot_blue_coins(?);
extern void spawn_object_loot_yellow_coins(struct Object *, s32, f32);
// extern ? obj_spawn_loot_coin_at_mario_pos(?);
// extern ? obj_abs_y_dist_to_home(?);
// extern ? Unknown802A1548(?);
// extern ? obj_detect_steep_floor(?);
// extern ? obj_resolve_wall_collisions(?);
// extern ? obj_update_floor(?);
// extern ? obj_update_floor_and_resolve_wall_collisions(?);
extern void obj_update_floor_and_walls(void);
extern void obj_move_standard(s16);
// extern ? obj_within_12k_bounds(?);
void obj_move_using_vel_and_gravity(void);
void obj_move_xz_using_fvel_and_gravity(void);
// extern ? set_object_pos_relative(?);
s16 obj_angle_to_home(void);
// extern ? func_802A2008(?);
// extern ? translate_object_local(?);
extern void build_object_transform_from_pos_and_angle(struct Object *, s16, s16);
extern void func_802A2270(struct Object *);
extern void build_object_transform_relative_to_parent(struct Object *);
// extern ? Unknown802A2380(?);
// extern ? obj_rotate_move_angle_using_vel(?);
// extern ? obj_rotate_face_angle_using_vel(?);
// extern ? obj_set_face_angle_to_move_angle(?);
extern s32 obj_follow_path(UNUSED s32);
extern void chain_segment_init(struct ChainSegment *);
extern f32 random_f32_around_zero(f32);
// extern ? scale_object_random(?);
extern void translate_object_xyz_random(struct Object *, f32);
extern void translate_object_xz_random(struct Object *, f32);
// extern ? func_802A297C(?);
void func_802A2A38(void);
void func_802A2B04(struct Struct802A2B04 *sp28);
extern s16 obj_reflect_move_angle_off_wall(void);

#endif /* OBJECT_HELPERS_H */
