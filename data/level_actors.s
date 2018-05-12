.include "macros.inc"

.section .mio0, "ax"

.include "levels/main_entry.s"

.align 4, 0
glabel segment2
.incbin "build/mio0/segment2.mio0"
glabel segment2_end

.align 4, 0
.global mario
mario:
.incbin "build/mio0/mario.mio0"
glabel mario_end

.align 4, 0
.global water_sparkles_mario
water_sparkles_mario:
.include "geo/water_sparkles_mario.geo.s"
glabel water_sparkles_mario_end

.align 4, 0
.global yoshiegg_owl_thwomp
yoshiegg_owl_thwomp:
.incbin "build/mio0/yoshiegg_owl_thwomp.mio0"
glabel yoshiegg_owl_thwomp_end

.align 4, 0
.global owl_thwomp_bullet_heave
owl_thwomp_bullet_heave:
.include "geo/owl_thwomp_bullet_heave.geo.s"
glabel owl_thwomp_bullet_heave_end

.align 4, 0
.global big_bully
big_bully:
.incbin "build/mio0/big_bully.mio0"
glabel big_bully_end

.align 4, 0
.global bully_blargg
bully_blargg:
.include "geo/bully_blargg.geo.s"
glabel bully_blargg_end

.align 4, 0
.global bobombs
bobombs:
.incbin "build/mio0/bobombs.mio0"
glabel bobombs_end

.align 4, 0
.global kingbobomb_bubble
kingbobomb_bubble:
.include "geo/kingbobomb_bubble.geo.s"
glabel kingbobomb_bubble_end

.align 4, 0
.global sea_creatures_texture
sea_creatures_texture:
.incbin "build/mio0/sea_creatures_texture.mio0"
glabel sea_creatures_texture_end

.align 4, 0
.global sea_creatures
sea_creatures:
.include "geo/sea_creatures.geo.s"
glabel sea_creatures_end

.align 4, 0
.global vulture_pokey
vulture_pokey:
.incbin "build/mio0/vulture_pokey.mio0"
glabel vulture_pokey_end

.align 4, 0
.global klepto_eyerock_pokey
klepto_eyerock_pokey:
.include "geo/klepto_eyerock_pokey.geo.s"
glabel klepto_eyerock_pokey_end

.align 4, 0
.global monkey
monkey:
.incbin "build/mio0/monkey.mio0"
glabel monkey_end

.align 4, 0
.global mole_monkey_fwoosh
mole_monkey_fwoosh:
.include "geo/mole_monkey_fwoosh.geo.s"
glabel mole_monkey_fwoosh_end

.align 4, 0
.global spindrift_penguin_snowman
spindrift_penguin_snowman:
.incbin "build/mio0/spindrift_penguin_snowman.mio0"
glabel spindrift_penguin_snowman_end

.align 4, 0
.global spindrift_penguin_blizzard
spindrift_penguin_blizzard:
.include "geo/spindrift_penguin_blizzard.geo.s"
glabel spindrift_penguin_blizzard_end

.align 4, 0
.global checkerboard_question
checkerboard_question:
.incbin "build/mio0/checkerboard_question.mio0"
glabel checkerboard_question_end

.align 4, 0
.global cap_switch
cap_switch:
.include "geo/cap_switch.geo.s"
glabel cap_switch_end

.align 4, 0
.global piano_books
piano_books:
.incbin "build/mio0/piano_books.mio0"
glabel piano_books_end

.align 4, 0
.global bookend_chair_piano_boo
bookend_chair_piano_boo:
.include "geo/bookend_chair_piano_boo.geo.s"
glabel bookend_chair_piano_boo_end

.align 4, 0
.global peach_toadstool
peach_toadstool:
.incbin "build/mio0/peach_toadstool.mio0"
glabel peach_toadstool_end

.align 4, 0
.global birds_peach_yoshi
birds_peach_yoshi:
.include "geo/birds_peach_yoshi.geo.s"
glabel birds_peach_yoshi_end

.align 4, 0
.global enemy
enemy:
.incbin "build/mio0/enemy.mio0"
glabel enemy_end

.align 4, 0
.global bubba_wiggler_lakitu
bubba_wiggler_lakitu:
.include "geo/bubba_wiggler_lakitu.geo.s"
glabel bubba_wiggler_lakitu_end

.align 4, 0
.global bowser
bowser:
.incbin "build/mio0/bowser.mio0"
glabel bowser_end

.align 4, 0
.global bowser_flames_bomb
bowser_flames_bomb:
.include "geo/bowser_flames_bomb.geo.s"
glabel bowser_flames_bomb_end

.align 4, 0
.global treasure_chest_fish
treasure_chest_fish:
.incbin "build/mio0/treasure_chest_fish.mio0"
glabel treasure_chest_fish_end

.align 4, 0
.global skeeter_fish_manta_chest
skeeter_fish_manta_chest:
.include "geo/skeeter_fish_manta_chest.geo.s"
glabel skeeter_fish_manta_chest_end

.align 4, 0
.global koopa_whomp
koopa_whomp:
.incbin "build/mio0/koopa_whomp.mio0"
glabel koopa_whomp_end

.align 4, 0
.global koopa_log_piranha_whomp_chomp
koopa_log_piranha_whomp_chomp:
.include "geo/koopa_log_piranha_whomp_chomp.geo.s"
glabel koopa_log_piranha_whomp_chomp_end

.align 4, 0
.global lakitu_toad
lakitu_toad:
.incbin "build/mio0/lakitu_toad.mio0"
glabel lakitu_toad_end

.align 4, 0
.global lakitu_toad_mips_boo
lakitu_toad_mips_boo:
.include "geo/lakitu_toad_mips_boo.geo.s"
glabel lakitu_toad_mips_boo_end

.align 4, 0
.global chillychief_moneybag
chillychief_moneybag:
.incbin "build/mio0/chillychief_moneybag.mio0"
glabel chillychief_moneybag_end

.align 4, 0
.global moneybag
moneybag:
.include "geo/moneybag.geo.s"
glabel moneybag_end

.align 4, 0
.global mri_swoop
mri_swoop:
.incbin "build/mio0/mri_swoop.mio0"
glabel mri_swoop_end

.align 4, 0
.global mri_swoop_snufit_dorrie_scuttlebug
mri_swoop_snufit_dorrie_scuttlebug:
.include "geo/mri_swoop_snufit_dorrie_scuttlebug.geo.s"
glabel mri_swoop_snufit_dorrie_scuttlebug_end

.align 4, 0
.global chuckya_shyguy_goomba
chuckya_shyguy_goomba:
.incbin "build/mio0/chuckya_shyguy_goomba.mio0"
glabel chuckya_shyguy_goomba_end

.align 4, 0
.global cannon_box_switch_enemies
cannon_box_switch_enemies:
.include "geo/cannon_box_switch_enemies.geo.s"
glabel cannon_box_switch_enemies_end

.align 4, 0
.global doors_trees_coins
doors_trees_coins:
.incbin "build/mio0/doors_trees_coins.mio0"
glabel doors_trees_coins_end

.align 4, 0
.global coins_pipe_doors_maps_trees
.global coins_pipe_doors_maps_trees_end
coins_pipe_doors_maps_trees:
.include "geo/coins_pipe_doors_maps_trees.geo.s"
glabel coins_pipe_doors_maps_trees_end

