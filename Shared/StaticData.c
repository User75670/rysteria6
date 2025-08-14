// Copyright (C) 2024 Paul Johnson
// Copyright (C) 2024-2025 Maxim Nesterov

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Shared/StaticData.h>

#include <math.h>
#include <stdio.h>

#include <Shared/Utilities.h>

// clang-format off
struct rr_petal_base_stat_scale const offensive[rr_rarity_id_max] = {
    {1.0, 1.0},
    {1.7, 2.0},
    {2.9, 4.0},
    {5.0, 8.0},
    {8.5,  16},
    {14.5, 48},
    {24.6,144},
    {42.0,432},
    {124.0,1242}
};

struct rr_petal_base_stat_scale const defensive[rr_rarity_id_max] = {
    {1.0, 1.0},
    {2.0, 1.7},
    {4.0, 2.9},
    {8.0, 5.0},
    {16,  8.5},
    {48, 14.5},
    {144,24.6},
    {432,42.0},
    {1242,124.0}
};

struct rr_petal_data RR_PETAL_DATA[rr_petal_id_max] = {
//   id                     min_rarity              scale        dmg      hp   clump   cd 2cd  count
    {rr_petal_id_none,      rr_rarity_id_common,    offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_basic,     rr_rarity_id_common,    offensive, 10.0f,  15.0f,   0.0f,  50,  0, {1,2,2,3,3,4,4,5,5}},
    {rr_petal_id_pellet,    rr_rarity_id_common,    offensive, 10.0f,   5.0f,   0.0f,  13,  0, {1,2,3,4,4,5,6,6,6}},
    {rr_petal_id_fossil,    rr_rarity_id_common,    offensive,  5.0f, 100.0f,   0.0f, 100,  0, {1,1,1,1,1,1,1,1,2}},
    {rr_petal_id_stinger,   rr_rarity_id_common,    offensive, 65.0f,   3.0f,  10.0f, 150,  0, {1,1,1,1,1,3,5,5,6}},
    {rr_petal_id_berry,     rr_rarity_id_rare,      offensive,  5.0f,   5.0f,  12.0f,  13,  0, {1,1,1,1,1,2,3,3,3}},
    {rr_petal_id_shell,     rr_rarity_id_rare,      offensive, 30.0f,  16.0f,   0.0f,  50, 13, {1,1,1,1,1,2,3,3,4}},
    {rr_petal_id_peas,      rr_rarity_id_rare,      offensive, 22.0f,  12.0f,   8.0f,  13, 12, {4,4,4,4,4,4,5,5,5}},
    {rr_petal_id_leaf,      rr_rarity_id_unusual,   offensive,  9.0f,   8.0f,   8.0f,  38,  0, {1,1,1,1,1,2,2,2,3}},
    {rr_petal_id_egg,       rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25,100, {1,4,3,3,2,2,2,1,1}},
    {rr_petal_id_magnet,    rr_rarity_id_unusual,   defensive,  2.0f,  25.0f,   0.0f,  38,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_uranium,   rr_rarity_id_rare,      offensive,  3.0f,  40.0f,   0.0f,  25, 25, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_feather,   rr_rarity_id_common,    defensive,  1.0f,   3.0f,   0.0f,  25,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_azalea,    rr_rarity_id_common,    defensive,  5.0f,  15.0f,  10.0f,  25, 50, {1,1,1,1,1,1,3,3,4}},
    {rr_petal_id_bone,      rr_rarity_id_common,    defensive,  2.5f,  25.0f,   0.0f,  68,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_web,       rr_rarity_id_rare,      defensive,  5.0f,   5.0f,   0.0f,  50, 13, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_seed,      rr_rarity_id_legendary, defensive,  1.0f,  75.0f,   0.0f,  63,  1, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_gravel,    rr_rarity_id_unusual,   offensive,  9.0f,  20.0f,   0.0f,  20, 10, {1,2,2,2,3,3,4,4,5}},
    {rr_petal_id_club,      rr_rarity_id_common,    defensive,  8.0f, 600.0f,   0.0f, 250,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_crest,     rr_rarity_id_rare,      offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_droplet,   rr_rarity_id_common,    offensive, 15.0f,   5.0f,   0.0f,  37,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_beak,      rr_rarity_id_unusual,   defensive,  5.0f,   5.0f,   0.0f,  55,  0, {1,1,1,1,1,1,1,1,2}},
    {rr_petal_id_lightning, rr_rarity_id_unusual,   offensive,  10.0f,   1.0f,   0.0f, 63,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_third_eye, rr_rarity_id_legendary, offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_nest,      rr_rarity_id_legendary, defensive,  0.0f,  25.0f,   0.0f,  1,   0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_fireball,  rr_rarity_id_unusual,   offensive,260.0f,   1.0f,   0.0f, 600,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_meat,      rr_rarity_id_common,    offensive,  0.0f,1600.0f,   0.0f, 188, 13, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_bubble,    rr_rarity_id_common,    defensive,  1.0f,  25.0f,   0.0f, 200,  3, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_meteor,    rr_rarity_id_unusual,   defensive,  0.0f,   0.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_mandible,  rr_rarity_id_common,    offensive,  5.0f,  10.0f,   0.0f,  75,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_wax,       rr_rarity_id_unusual,   offensive, 10.0f,  10.0f,  10.0f,  38,  0, {2,2,2,2,2,2,2,2,2}},
    {rr_petal_id_sand,      rr_rarity_id_common,    offensive, 15.0f,  10.0f,  10.0f,  37,  0, {4,4,4,4,4,4,4,4,5}},
    {rr_petal_id_mint,      rr_rarity_id_unusual,   offensive,  5.0f,  10.0f,  10.0f,  50, 25, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_dako_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25, 75, {1,6,6,5,5,4,4,3,2}},
    {rr_petal_id_pter_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25, 88, {1,5,5,4,4,3,3,2,1}},
    {rr_petal_id_pachy_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25,88,{1,5,4,4,3,3,2,1,1}},
    {rr_petal_id_quetz_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25,100,{1,4,3,3,2,2,2,1,1}},
    {rr_petal_id_trice_egg,  rr_rarity_id_unusual,   defensive,  1.0f,  75.0f,  10.0f,  25,88,{1,5,4,4,3,3,2,1,1}},
    {rr_petal_id_obliterator,rr_rarity_id_common,    offensive,  1000000000.0f, 1000000000.0f,   0.0f, 0,  0, {1,1,1,1,1,1,1,1,1}},
};    

char const *RR_PETAL_NAMES[rr_petal_id_max] = {
    "Secret",   "Petal",     "Pellet",    "Fossil", "Stinger",  "Berry",   "Shell",
    "Peas",     "Leaf",      "T-rex Egg",       "Magnet", "Uranium",  "Feather", "Azalea",
    "Bone",     "Web",       "Seed",      "Gravel", "Club",     "Crest",   "Droplet",
    "Beak",     "Lightning", "Third Eye", "Nest",   "Fireball", "Meat",    "Bubble",
    "Meteor",   "Mandible",  "Wax",       "Sand",   "Mint",   "Dako Egg", "Pter Egg",
    "Pachy Egg", "Quetz Egg", "Trice Egg", "Obliterator"
};

char const *RR_PETAL_DESCRIPTIONS[rr_petal_id_max] = {
    0,
    "It's just a petal",
    "Low damage, but there's lots",
    "It came from a dino",
    "Ow that hurts",
    "Gives your other petals more energy",
    "Poor snail",
    "Splits in 4. Or maybe 5 if you're a pro",
    "Heals you gradually",
    "Spawns a pet dinosaur to protect you",
    "Increases loot pickup radius. Stacks diminishingly",
    "Does damage to the owner and enemies in a large range",
    "It's so light it increases your movement speed. Stacks diminishingly",
    "It heals you",
    "Gives the player armor. Stacks diminishingly",
    "It slows everything down",
    "What does this one do",
    "Tiny rocks that stay on the ground and trip dinos",
    "Heavy and sturdy",
    "Increases your maximum vision range. Does not stack",
    "This mysterious petal reverses your petal rotation",
    "Stuns mobs and prevents them from moving",
    "A stunning display",
    "Your petals hate it and want to move further away. Stacks diminishingly",
    "Home sweet home",
    "Nice ball bro",
    "Meat meta",
    "Pop and you're gone",
    "Spawns a pet meteor to protect you",
    "Does more damage if target hp is below 50%",
    "Made by the bees",
    "Very fine",
    "Remember to feed your pets",
    "Oh this one spawns dakotaraptors.",
    "Who thought you could get pet pteranodons.",
    "Spawns another type of pet dinosaur to protect you. Cool.",
    "Interesting type of egg.",
    "I thought they aren't aggresive...",
    "Obliterate anything."
};
/*
{"accounts":["dc04d57b-2a96-4dcf-869e-8811c2e2932e","2880b2b3-80f5-431d-96ac-f06312623e3c","37f74b2b-b0c1-4958-bfd0-10a3b3d4e726","7ad9a194-6688-4f99-97ef-6a80e1891831","954e097b-e18f-4ab0-b68a-83ba8e2b8ac5","8e7c1fee-7c7c-4fb3-895a-f0def01b8830","b8005579-4128-4a47-9b22-bf0652b87221","2d7fec44-08d4-4139-9fd5-7a42f867e0de","9b935373-2965-406a-91ca-e4490cb5470d","1375c106-371f-45f8-8798-3ca5b72826f1","b2376a01-6146-4f69-ab7a-d69e764f95c8","9449ab83-e6d0-422b-a816-52ef460f36ea","cbf7a88d-769f-40ba-84ca-6bbcaeb8eb94","23519a46-7959-4b78-9943-20f570d0209c","d103fbaf-d37b-4b2b-998a-371e19c31308","366bdfc2-85f5-4f3f-bdf2-6454a1c60324","2ad5f3bf-6bde-4255-b5a2-0b14484a5f91","3476f490-a806-4a1a-9de4-cf4a1664fdad","05ca718a-0d19-4805-b6ea-a6cf718834c0","cd8759e7-1e40-4d20-a855-572d600dee02"],"links":[],"8e7c1fee-7c7c-4fb3-895a-f0def01b8830":{"password":"7d1dc484f1b799c71a491f9dcf79f186218a52db42f09107c96e59074cd5f9fd18276e360a06d649aa75fb9a33bb70ad12e05bc204b3e038176c116c17893281","username":"8e7c1fee-7c7c-4fb3-895a-f0def01b8830","xp":34063374,"petals":{"1:1":2,"2:0":13,"2:1":124,"2:2":9,"2:3":4,"2:4":1,"2:5":1,"3:0":125,"3:1":154,"3:2":246,"3:3":4,"3:4":3,"3:5":4,"4:0":99,"4:1":87,"4:2":512,"4:3":21,"4:4":4,"5:2":21,"5:3":7,"5:4":3,"6:2":138,"6:3":39,"6:4":4,"6:5":4,"7:2":26,"7:3":85,"7:4":2,"8:1":44,"8:2":46,"8:3":17,"8:4":3,"8:5":2,"9:1":73,"9:2":41,"9:3":1,"9:4":3,"9:5":1,"10:1":4,"10:2":9,"10:3":5,"10:4":5,"11:2":39,"11:3":17,"12:0":53,"12:1":84,"12:2":170,"12:3":3,"12:4":5,"13:0":18,"13:1":15,"13:2":5,"13:3":3,"13:4":1,"13:5":1,"14:0":1,"14:1":2,"14:2":15,"14:3":12,"15:2":124,"15:3":4,"15:4":3,"17:1":6,"17:2":5,"17:3":9,"17:4":2,"18:0":4,"18:1":6,"18:2":7,"18:3":9,"18:4":4,"19:2":92,"19:3":29,"19:4":2,"19:5":1,"20:0":18,"20:1":85,"20:2":111,"20:3":105,"20:4":4,"21:1":293,"21:2":4,"21:3":4,"21:4":3,"21:5":10,"22:1":69,"22:2":71,"22:3":61,"22:4":4,"23:4":3,"24:4":3,"25:2":25,"25:3":20,"25:4":3,"26:0":81,"26:1":53,"26:2":726,"26:3":477,"26:4":4,"27:0":3,"27:1":13,"27:2":5,"27:3":8,"27:4":5,"28:2":15,"28:3":22,"28:4":4,"29:1":1,"29:2":4,"29:3":8,"30:1":2,"30:2":4,"30:3":2,"31:1":12,"31:2":304,"31:3":37,"31:4":4,"31:5":1,"32:1":1,"32:2":84,"32:3":17,"32:4":4,"33:1":4,"33:2":84,"33:3":4,"33:4":2,"33:5":1,"34:1":129,"34:2":4,"34:3":2,"34:4":2,"34:5":5,"35:1":24,"35:2":36,"35:3":1,"35:4":2,"36:1":53,"36:2":76,"36:3":29,"36:4":3,"36:5":2},"failed_crafts":{"2:1":1,"2:2":2,"2:4":4,"3:0":1,"3:3":4,"3:4":31,"4:3":13,"4:4":15,"5:3":17,"5:4":4,"6:2":2,"6:3":9,"6:4":1,"7:3":1,"8:1":2,"8:3":12,"8:4":17,"9:1":2,"9:2":2,"9:3":12,"10:3":8,"10:4":1,"11:3":2,"12:0":1,"12:1":3,"12:2":13,"12:4":37,"13:0":1,"13:1":2,"13:2":4,"15:3":14,"15:4":11,"18:2":1,"19:2":3,"19:3":5,"21:2":2,"21:3":11,"21:4":22,"21:5":35,"22:4":2,"24:4":16,"25:3":11,"25:4":3,"26:4":5,"28:3":4,"28:4":4,"31:3":25,"31:4":6,"32:3":35,"32:4":17,"33:2":5,"33:3":7,"33:4":2,"34:1":2,"34:3":7,"34:4":11,"35:3":1,"35:4":3,"36:3":22,"36:4":11},"mob_gallery":{"0:0":81,"0:1":104,"0:2":37,"0:3":40,"0:4":469,"0:5":11,"0:6":1,"1:2":266,"1:3":45,"1:4":1291,"1:5":19,"2:0":16,"2:1":29,"2:2":348,"2:3":416,"2:4":3,"2:5":1,"2:6":1,"3:2":8,"3:3":8,"3:4":1,"4:0":1,"4:1":164,"4:2":183,"4:3":5341,"4:4":4557,"4:5":211,"4:6":2,"5:0":88,"5:1":117,"5:2":41,"5:3":1116,"5:4":1981,"5:5":9,"6:0":78,"6:1":142,"6:2":67,"6:3":9,"6:4":152,"6:5":9,"7:0":64,"7:1":87,"7:2":21,"7:3":254,"7:4":128,"7:5":4,"8:2":22,"8:3":14,"8:4":11,"8:5":4,"9:0":2,"9:2":4,"9:3":97,"9:4":56,"10:0":2,"10:2":139,"10:3":113,"10:4":91,"10:5":47,"10:6":5,"11:0":29,"11:1":78,"11:2":14,"11:3":1,"11:4":35,"11:5":1,"12:2":4,"12:3":8,"12:4":10,"13:2":2,"13:3":63,"13:4":39,"14:3":10,"14:4":51,"15:3":9,"15:4":2,"17:2":6,"17:3":83,"17:4":566,"18:3":40,"18:4":97,"19:2":3,"19:3":18,"19:4":1150},"checkpoint":1},"b8005579-4128-4a47-9b22-bf0652b87221":{"password":"cc060f9faaa55a633c1f9f1a48b89cdb61dba566d2daa1787ffc2dcc28044f86aab091d63191b0f5ae7e9168de792c6aacf29878286dd1bb075f007ca3ead74b","username":"b8005579-4128-4a47-9b22-bf0652b87221","xp":629536,"petals":{"1:0":10,"2:0":14,"2:1":32,"2:2":28,"2:3":4,"3:0":33,"3:1":24,"3:2":6,"4:0":22,"4:1":25,"4:2":15,"5:2":1,"6:2":4,"6:3":4,"6:4":2,"7:2":5,"7:3":4,"8:1":78,"8:2":4,"8:3":5,"8:4":1,"9:1":22,"9:2":20,"9:3":2,"10:1":1,"10:2":1,"10:3":2,"10:4":1,"11:3":2,"12:0":13,"12:1":22,"12:2":41,"12:3":1,"13:0":8,"13:1":82,"13:2":2,"13:3":5,"13:4":2,"14:0":1,"14:1":1,"17:1":32,"17:2":34,"17:3":1,"18:0":2,"18:1":8,"18:2":46,"18:3":12,"19:2":42,"19:3":4,"20:0":6,"20:1":1,"20:2":2,"21:1":42,"21:2":3,"21:3":2,"21:4":2,"22:1":2,"24:4":1,"25:3":3,"25:4":1,"26:0":18,"26:1":27,"26:2":9,"27:0":1,"27:1":14,"27:2":48,"27:3":4,"28:2":1,"28:3":1,"28:4":3,"33:1":21,"33:2":33,"33:3":1,"34:1":67,"34:2":6,"34:3":2,"34:4":2,"35:1":7,"36:1":11,"36:2":3},"failed_crafts":{"6:2":1,"6:3":1,"6:4":3,"8:1":6,"8:2":2,"8:3":7,"13:3":4,"21:2":1,"21:3":2,"21:4":8,"34:2":8,"34:3":20,"34:4":3},"mob_gallery":{"0:0":13,"0:1":7,"0:2":3,"0:3":2,"1:0":3,"1:1":1,"1:2":42,"1:3":32,"2:0":2,"2:1":3,"2:2":226,"2:3":319,"3:2":8,"3:3":5,"4:0":3,"4:1":20,"4:2":24,"4:3":777,"4:4":1025,"5:0":24,"5:1":14,"5:2":10,"5:3":59,"6:0":32,"6:1":13,"6:2":8,"7:0":18,"7:1":3,"7:2":1,"7:3":3,"8:2":5,"8:3":66,"9:0":1,"9:2":1,"9:3":14,"9:4":12,"10:0":5,"10:1":3,"10:2":25,"10:3":1,"11:0":10,"11:1":5,"11:2":4,"15:3":1},"checkpoint":2},"dc04d57b-2a96-4dcf-869e-8811c2e2932e":{"password":"95a194ded1348ace4101e9ea0d7a47a529b5acbadaef983796b14e8fbf5851a47312ef8b126735f52ae6401349c9baff17eae3533f765573e503114680d4f504","username":"dc04d57b-2a96-4dcf-869e-8811c2e2932e","xp":0,"petals":{"1:0":10,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{},"checkpoint":0},"954e097b-e18f-4ab0-b68a-83ba8e2b8ac5":{"password":"2789284520d7e4fc0a87284e680f52eaf6cd4e9e30ba311389e719cb6429b8b7d8d58be6890aedfd4c7e5f5b244d7c2b3d10b4bdf5a084a659bf5398517bde1b","username":"954e097b-e18f-4ab0-b68a-83ba8e2b8ac5","xp":35058,"petals":{"1:1":2,"2:0":2,"2:1":2,"2:2":3,"2:3":5,"3:0":8,"3:1":6,"4:0":9,"4:1":9,"6:2":40,"6:3":62,"6:4":2,"7:2":2,"7:3":1,"8:1":6,"8:2":4,"8:3":2,"9:1":4,"9:2":6,"10:1":1,"10:2":1,"10:3":2,"11:3":2,"12:0":2,"12:1":18,"12:2":2,"12:3":8,"13:0":1,"13:1":2,"13:2":4,"13:3":1,"19:2":1,"19:3":3,"20:0":2,"20:1":16,"20:2":19,"20:3":1,"21:1":16,"21:2":54,"21:3":78,"21:4":3,"25:2":1,"25:3":2,"26:0":8,"26:1":3,"28:3":1,"28:4":2,"33:1":5,"33:2":4,"33:3":2,"34:1":32,"34:2":54,"34:3":64,"34:4":1,"35:1":1,"36:1":1},"failed_crafts":{"2:3":3,"6:3":3,"8:1":2,"12:2":4,"12:3":3,"13:2":5,"13:3":1,"19:2":2,"19:3":3,"21:2":4,"21:3":10,"33:1":1,"33:2":3,"33:3":3,"34:3":6},"mob_gallery":{"0:0":7,"0:1":13,"0:2":1,"1:2":29,"2:0":1,"2:1":4,"2:2":2,"2:3":18,"3:2":3,"3:3":1,"4:1":12,"4:2":19,"4:3":170,"4:4":75,"5:0":4,"5:1":10,"5:2":2,"5:3":134,"6:0":21,"6:1":29,"6:2":6,"7:0":2,"7:1":8,"7:3":42,"8:2":3,"9:3":4,"9:4":1,"10:0":1,"10:1":1,"10:2":10,"11:1":9,"11:2":2},"checkpoint":1},"2d7fec44-08d4-4139-9fd5-7a42f867e0de":{"password":"eda4419a0c4a9b0b4ae0dbc072ca12dbd99bc2fed7c7e35c83bd98e76cef954e167fe3ff6ef72ec5690b28b41b1db5b3d7463f18c0c08197f25bf3937cc7cbc2","username":"2d7fec44-08d4-4139-9fd5-7a42f867e0de","xp":9341005,"petals":{"1:1":2,"2:0":38,"2:1":9,"2:2":7,"2:3":4,"2:4":2,"3:0":75,"3:1":75,"3:2":9,"4:0":78,"4:1":61,"4:2":18,"4:3":4,"4:4":1,"5:2":2,"6:2":125,"6:3":143,"6:4":5,"6:5":1,"7:2":12,"7:3":2,"7:4":3,"8:1":13,"8:2":3,"8:3":3,"8:4":3,"9:1":27,"9:2":7,"9:3":1,"10:1":8,"10:2":37,"10:3":12,"10:4":3,"11:2":17,"11:3":9,"12:0":43,"12:1":129,"12:2":5,"12:3":1,"12:4":3,"13:0":24,"13:1":6,"13:2":2,"13:3":4,"13:4":3,"14:1":1,"15:2":3,"15:3":1,"15:4":3,"17:1":19,"17:2":4,"17:3":1,"18:0":2,"18:1":4,"18:2":6,"18:3":3,"19:2":21,"19:3":5,"19:4":3,"20:0":10,"20:1":89,"20:2":4,"20:3":4,"21:1":100,"21:2":111,"21:3":189,"21:4":16,"21:5":3,"22:1":7,"22:2":2,"23:4":1,"24:4":4,"25:1":1,"25:2":26,"25:3":10,"25:4":2,"26:0":64,"26:1":37,"26:2":7,"27:1":11,"27:2":2,"27:3":3,"28:1":1,"28:2":14,"28:3":13,"28:4":4,"29:1":3,"29:2":5,"29:3":3,"30:1":1,"30:2":4,"30:3":2,"31:0":1,"31:1":23,"31:2":2,"31:3":4,"31:4":2,"32:1":4,"32:2":15,"32:4":2,"33:1":10,"33:3":4,"33:4":1,"34:1":50,"34:2":125,"34:3":160,"34:4":4,"34:5":1,"35:1":17,"35:2":2,"36:1":5,"36:2":2},"failed_crafts":{"2:1":2,"2:2":1,"2:3":10,"3:2":3,"4:3":3,"6:2":4,"6:4":17,"7:2":11,"7:3":24,"8:2":2,"9:2":5,"10:2":5,"10:3":21,"10:4":2,"11:2":7,"11:3":11,"12:2":2,"12:3":8,"13:0":1,"13:1":3,"13:2":1,"13:3":24,"15:2":8,"15:4":9,"17:2":4,"18:2":7,"18:3":1,"19:2":7,"19:3":11,"20:2":3,"20:3":5,"21:2":2,"21:3":3,"21:4":12,"24:4":2,"25:3":21,"25:4":5,"27:2":1,"28:3":23,"28:4":9,"31:2":6,"31:3":7,"31:4":8,"32:2":2,"32:4":13,"33:3":20,"34:4":29},"mob_gallery":{"0:0":19,"0:1":34,"0:2":18,"1:2":169,"1:3":16,"2:0":8,"2:1":24,"2:2":764,"2:3":1023,"3:2":22,"3:3":20,"4:1":67,"4:2":118,"4:3":3598,"4:4":3232,"5:0":29,"5:1":52,"5:2":30,"5:3":1203,"6:0":24,"6:1":58,"6:2":45,"7:0":6,"7:1":29,"7:2":12,"7:3":263,"8:2":7,"8:3":37,"9:2":2,"9:3":66,"9:4":53,"10:2":88,"10:3":1,"11:0":9,"11:1":21,"11:2":6,"12:3":16,"12:4":3,"13:3":44,"13:4":11,"14:2":1,"14:3":30,"14:4":18,"15:3":13,"15:4":1,"17:2":4,"17:3":58,"17:4":325,"18:3":58,"18:4":24,"19:2":2,"19:3":25,"19:4":629},"checkpoint":1},"9b935373-2965-406a-91ca-e4490cb5470d":{"password":"501e93f4b171213e53cbaf7bb3d386b61d23b8f805a5e31a1f08376cab986a7eca5986cc907e32a85af9e505b59c2b006eb983c2885a0612b8bcb97cba81ea74","username":"9b935373-2965-406a-91ca-e4490cb5470d","xp":0,"petals":{"1:0":10,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{},"checkpoint":0},"1375c106-371f-45f8-8798-3ca5b72826f1":{"password":"a730100aecfbf6bab3e3ac6248b3c02aac332d151dd79834ea8f8b9abafeca6496f9ecdad7fdf5b92bc55df841cd1c87fd55ed3c138978cab8452014c6da36d8","username":"1375c106-371f-45f8-8798-3ca5b72826f1","xp":0,"petals":{"1:0":10,"3:0":4,"8:1":1,"10:1":1,"12:0":1,"12:1":1,"13:1":1,"35:1":1},"failed_crafts":{},"mob_gallery":{"0:0":5,"0:1":1,"2:0":1,"2:1":1,"5:0":5,"5:1":1,"6:0":3,"6:1":2,"7:0":1,"11:0":2},"checkpoint":0},"b2376a01-6146-4f69-ab7a-d69e764f95c8":{"password":"f1882571b39b1cd38e1591903a68d3cd14dd1456648b3c817e81b712741c5c96938d03615d770df43762038b0b3ea597498ea967977223d5d8922fc67e7edc3d","username":"b2376a01-6146-4f69-ab7a-d69e764f95c8","xp":192229,"petals":{"1:0":10,"2:0":9,"2:1":340,"2:2":2,"2:3":3,"2:4":1,"3:0":16,"3:1":11,"4:0":11,"4:1":7,"4:2":1,"5:2":1,"6:2":130,"6:3":155,"6:4":5,"7:2":4,"7:3":2,"8:1":3,"8:2":3,"8:3":2,"8:4":1,"9:1":14,"9:2":1,"10:1":1,"10:3":4,"10:4":1,"11:3":3,"12:0":13,"12:1":167,"12:2":1,"12:3":6,"13:0":28,"13:1":2,"13:3":2,"13:4":1,"17:1":2,"17:2":1,"18:1":1,"18:2":1,"19:2":1,"19:3":2,"19:4":1,"20:0":5,"20:1":63,"20:2":4,"20:3":4,"21:1":27,"21:2":118,"21:3":209,"21:4":10,"25:1":1,"25:3":5,"26:0":6,"26:1":4,"26:2":2,"27:0":2,"27:1":2,"28:1":1,"28:3":4,"28:4":1,"33:1":168,"33:2":2,"33:3":4,"33:4":2,"34:1":52,"34:2":130,"34:3":173,"34:4":2,"35:1":6,"36:1":3},"failed_crafts":{"2:3":9,"3:0":1,"7:2":5,"7:3":2,"8:1":1,"8:3":4,"12:2":8,"12:3":34,"13:1":2,"13:3":13,"19:2":3,"19:3":3,"20:2":7,"20:3":1,"33:3":10},"mob_gallery":{"0:0":7,"0:1":6,"0:2":1,"1:2":26,"1:3":3,"2:0":3,"2:1":4,"2:2":474,"2:3":528,"3:2":17,"3:3":8,"4:1":15,"4:2":16,"4:3":142,"4:4":174,"5:0":9,"5:1":12,"5:2":2,"5:3":667,"6:0":19,"6:1":18,"6:2":9,"7:0":2,"7:1":8,"7:2":9,"7:3":173,"8:2":2,"8:3":2,"9:1":1,"9:3":4,"9:4":2,"10:2":10,"11:0":4,"11:1":3},"checkpoint":1},"9449ab83-e6d0-422b-a816-52ef460f36ea":{"password":"894ac4db927eccd727f8918dc33b4d81956b36e13566af2228117ba6849fc310c98beb0bacff00c67845c6a1a8085f36d88c7856ce0cdf8a6d97975fb2b65776","username":"9449ab83-e6d0-422b-a816-52ef460f36ea","xp":0,"petals":{"1:0":10,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{},"checkpoint":0},"cbf7a88d-769f-40ba-84ca-6bbcaeb8eb94":{"password":"763759a5a400063d868ddee02b8d0a8a43ba1161a17278601aad84cd750146c86f9d0ef7f894bf4e3e982446cc611a65c24f8157b6d938493a893dffae0138ba","username":"cbf7a88d-769f-40ba-84ca-6bbcaeb8eb94","xp":0,"petals":{"1:0":10,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{},"checkpoint":0},"23519a46-7959-4b78-9943-20f570d0209c":{"password":"50477b5f85e19c1b1139ccc56adbc9f1c8c79fb6fba0391d90734e075cec3c03927f440f56f555cf339b14ed4f3512060ebd1c71a84631d910b3d734a4ca426f","username":"23519a46-7959-4b78-9943-20f570d0209c","xp":5101154,"petals":{"1:0":10,"2:0":20,"2:1":222,"2:2":234,"2:3":4,"2:4":2,"3:0":54,"3:1":63,"3:2":50,"3:3":4,"4:0":41,"4:1":70,"4:2":83,"4:3":4,"4:4":2,"5:2":6,"6:2":87,"6:3":3,"6:4":1,"6:5":1,"7:2":43,"7:3":19,"7:4":4,"8:1":177,"8:2":305,"8:3":47,"8:4":4,"9:1":58,"9:2":37,"9:3":2,"10:1":7,"10:2":24,"10:3":18,"10:4":2,"11:2":15,"11:3":1,"11:4":1,"12:0":17,"12:1":106,"12:2":297,"12:3":36,"13:0":8,"13:1":137,"13:2":326,"13:3":3,"13:5":1,"14:0":5,"14:1":8,"15:2":74,"15:3":1,"15:4":2,"17:1":8,"17:2":4,"17:3":1,"18:1":4,"18:2":8,"18:3":2,"19:2":1,"19:3":2,"19:4":2,"20:0":4,"20:1":21,"20:2":16,"20:3":1,"21:1":71,"21:2":473,"21:3":141,"21:4":15,"21:5":1,"22:1":26,"22:2":16,"22:3":9,"23:4":1,"24:4":4,"25:2":10,"25:3":35,"25:4":4,"26:0":30,"26:1":48,"26:2":14,"26:3":1,"27:0":3,"27:1":4,"27:2":10,"28:2":5,"28:3":17,"28:4":7,"29:1":3,"29:2":3,"29:3":4,"30:1":7,"30:2":14,"30:3":2,"31:1":22,"31:2":152,"31:4":4,"32:1":2,"32:2":42,"32:3":22,"32:4":4,"33:1":42,"33:2":4,"33:3":4,"34:1":179,"34:2":489,"34:3":119,"34:4":4,"34:5":1,"35:1":11,"35:2":10,"36:1":26,"36:2":22,"36:3":3},"failed_crafts":{"2:3":10,"3:3":9,"4:3":8,"6:3":2,"7:2":1,"7:3":14,"7:4":1,"8:2":1,"8:3":15,"10:3":12,"11:3":3,"12:2":2,"13:2":2,"15:3":1,"15:4":3,"19:3":5,"21:1":6,"21:2":2,"21:3":17,"21:4":9,"24:4":1,"25:4":1,"28:4":2,"31:4":5,"32:3":13,"32:4":8,"33:2":7,"33:3":18,"34:2":1,"34:3":1,"36:3":7},"mob_gallery":{"0:0":7,"0:1":32,"0:2":22,"0:3":23,"1:2":87,"1:3":74,"1:4":1,"2:0":3,"2:1":8,"2:2":1578,"2:3":2775,"3:2":40,"3:3":66,"3:4":1,"4:1":22,"4:2":64,"4:3":1420,"4:4":1747,"5:0":12,"5:1":33,"5:2":33,"5:3":454,"6:0":32,"6:1":43,"6:2":19,"6:3":14,"7:0":8,"7:1":14,"7:2":9,"7:3":54,"8:2":14,"8:3":20,"9:1":1,"9:3":23,"9:4":32,"10:2":50,"10:3":38,"10:4":25,"11:0":8,"11:1":14,"11:2":12,"11:3":12,"12:2":1,"12:3":11,"12:4":7,"13:2":1,"13:3":63,"13:4":20,"14:3":13,"14:4":32,"15:3":22,"15:4":2,"17:2":3,"17:3":79,"17:4":269,"18:3":52,"18:4":38,"19:2":1,"19:3":18,"19:4":575},"checkpoint":1},"d103fbaf-d37b-4b2b-998a-371e19c31308":{"password":"3e80776141e086532981f7bc2933a0dcf15749511b1756727ab5027a500519bd5c758f8963db533274e92c876253b63761f8fef8d43764cc4209007826518fb9","username":"d103fbaf-d37b-4b2b-998a-371e19c31308","xp":297002,"petals":{"1:1":2,"2:0":6,"2:1":61,"2:2":3,"2:3":1,"3:0":17,"3:1":6,"3:2":4,"3:3":1,"4:0":6,"4:1":3,"7:2":38,"7:3":3,"7:4":2,"8:1":989,"8:2":3,"8:3":89,"8:4":5,"9:1":6,"9:2":3,"10:1":1,"10:3":2,"11:2":1,"12:0":8,"12:1":38,"12:2":3,"12:3":4,"12:4":1,"13:0":43,"13:1":750,"13:2":463,"13:3":434,"13:4":1,"14:0":2,"17:1":5,"18:1":1,"18:2":3,"19:2":4,"19:3":4,"20:0":2,"20:1":14,"20:2":3,"20:3":1,"21:1":7,"21:2":6,"21:3":17,"22:1":2,"22:2":11,"22:3":8,"25:3":2,"26:0":2,"26:1":3,"27:0":1,"27:1":1,"27:2":3,"28:3":2,"33:2":4,"33:3":4,"34:1":7,"34:2":1,"35:1":1,"36:1":3,"36:2":3,"36:3":18},"failed_crafts":{"2:2":7,"2:3":4,"3:3":7,"7:2":5,"7:3":6,"8:1":5,"8:2":14,"8:3":15,"12:2":2,"12:3":2,"13:3":4,"13:4":1,"19:2":3,"19:3":4,"20:2":1,"33:2":2,"33:3":3},"mob_gallery":{"0:0":10,"0:1":20,"0:2":3,"1:2":28,"1:3":7,"2:0":2,"2:1":12,"2:2":1607,"2:3":2705,"3:2":36,"3:3":71,"3:4":1,"4:1":25,"4:2":12,"5:0":10,"5:1":16,"5:2":9,"5:3":129,"6:0":30,"6:1":24,"6:2":1,"7:0":3,"7:1":9,"7:2":1,"7:3":38,"8:2":4,"8:3":9,"9:1":1,"9:3":1,"9:4":1,"10:2":19,"10:4":24,"11:0":3,"11:1":12,"11:2":1},"checkpoint":1},"366bdfc2-85f5-4f3f-bdf2-6454a1c60324":{"password":"5f31e974c383cbd5a2a0fc006239ed1c50a318423a3c15109d10f7840f26ac8ccece92c9c998810c4593e0f35f4ef2158d43f63274202265b611679133c6bdc2","username":"366bdfc2-85f5-4f3f-bdf2-6454a1c60324","xp":0,"petals":{"1:0":10,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{},"checkpoint":0},"2ad5f3bf-6bde-4255-b5a2-0b14484a5f91":{"password":"b6803e9c6d0f9c8f3f31d3bf6a484e5253fb5c9550c195866a02eff939db514b3c3cfa98adb8a10d64c09cafd034c77a5d57f27aa25bfe7f8bef289cbba3927d","username":"2ad5f3bf-6bde-4255-b5a2-0b14484a5f91","xp":0,"petals":{"1:0":10,"2:0":1,"3:0":4,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{"0:0":46,"0:1":3,"2:0":8,"4:1":2,"5:0":48,"5:1":4,"6:0":31,"6:1":1,"7:0":25,"7:1":3,"11:0":15,"11:1":2},"checkpoint":0},"3476f490-a806-4a1a-9de4-cf4a1664fdad":{"password":"ab365faa0ad0df456eed487e9a173b3d7b5c73f2bba2d0b708be0ea9e62f593b9ce3e228d4a08e1dbc752be75edf9b0e3c99fbd87a847e4774b4d312e49929b4","username":"3476f490-a806-4a1a-9de4-cf4a1664fdad","xp":0,"petals":{"1:0":10,"8:1":1,"10:1":1,"12:0":1},"failed_crafts":{},"mob_gallery":{},"checkpoint":0},"05ca718a-0d19-4805-b6ea-a6cf718834c0":{"password":"4b39b01db3c12613b86f63a55467c3a7ca5232420837a2232ca2fcb50be06deafc96cc2eec1583c77cc805b3004bd605ab99f9b8d4305896d90b02c7ec0b9138","username":"05ca718a-0d19-4805-b6ea-a6cf718834c0","xp":335,"petals":{"1:1":2,"2:0":9,"2:1":4,"3:0":21,"3:1":21,"3:2":4,"4:0":13,"4:1":6,"4:2":3,"6:2":3,"7:2":1,"8:1":6,"8:2":3,"9:1":7,"9:2":4,"10:1":1,"12:0":18,"12:1":5,"13:0":7,"13:1":4,"13:2":1,"14:0":2,"17:1":5,"17:2":4,"18:0":3,"18:1":2,"18:2":4,"18:3":1,"20:0":3,"20:1":1,"21:1":16,"21:2":7,"22:1":2,"26:0":15,"26:1":11,"26:2":1,"27:0":1,"27:1":5,"27:2":4,"33:1":3,"34:1":8,"34:2":6,"35:1":4,"35:2":1,"36:1":7,"36:2":3},"failed_crafts":{"2:1":2,"3:1":2,"4:1":3,"4:2":1,"9:1":1,"13:1":1,"21:2":1,"33:1":1,"34:1":2,"35:1":1},"mob_gallery":{"0:0":32,"0:1":27,"0:2":7,"1:2":43,"1:3":4,"2:0":8,"2:1":10,"2:2":9,"3:2":1,"4:1":50,"4:2":39,"4:3":3,"5:0":31,"5:1":30,"5:2":5,"6:0":41,"6:1":55,"6:2":9,"7:0":13,"7:1":5,"7:2":1,"8:2":8,"8:3":5,"9:0":2,"10:2":39,"11:0":13,"11:1":7,"11:2":2},"checkpoint":0},"cd8759e7-1e40-4d20-a855-572d600dee02":{"password":"f620af659566f325213a293137295deffa12f42567096f70dced35be0e5d3d056a65dfee2ab728cb85c4cb4698054bf685acfbd8d5630e7ae2a03e2b3f4dafc8","username":"cd8759e7-1e40-4d20-a855-572d600dee02","xp":0,"petals":{"1:0":10,"2:0":5,"3:0":10,"3:1":1,"8:1":2,"10:1":1,"12:0":3,"12:1":2,"13:0":4,"13:1":2,"33:1":1,"34:1":1,"35:1":2},"failed_crafts":{},"mob_gallery":{"0:0":36,"0:1":5,"2:0":9,"2:1":4,"4:1":2,"5:0":14,"5:1":5,"6:0":23,"6:1":8,"7:0":6,"9:0":1,"11:0":9},"checkpoint":0}}
*/
struct rr_mob_data RR_MOB_DATA[rr_mob_id_max] = {
//   id                                     min_rarity  max_rarity              hp dmg    rad  ai_passive_rarity    ai_neutral_rarity    ai_aggro_rarity       loot
    {rr_mob_id_triceratops,        rr_rarity_id_common, rr_rarity_id_omega,  45, 15, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_leaf,    0.15},{rr_petal_id_fossil,    0.05}, {rr_petal_id_trice_egg, 0.07}}},
    {rr_mob_id_trex,               rr_rarity_id_rare, rr_rarity_id_omega,  40, 25, 32.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_unusual, {{rr_petal_id_stinger, 0.04},{rr_petal_id_egg,       0.06},{rr_petal_id_meat,      0.02}}},
    {rr_mob_id_fern,               rr_rarity_id_common, rr_rarity_id_omega,  10,  5, 24.0f, rr_rarity_id_max,    rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_leaf,     0.1},{rr_petal_id_azalea,    0.25}}},
    {rr_mob_id_tree,               rr_rarity_id_rare, rr_rarity_id_omega, 100,  5, 64.0f, rr_rarity_id_common, rr_rarity_id_max, rr_rarity_id_max,  {{rr_petal_id_leaf,     2.5},{rr_petal_id_peas,       2.5},{rr_petal_id_seed,      0.05}}}, // :trol:
    {rr_mob_id_pteranodon,         rr_rarity_id_unusual, rr_rarity_id_omega,  40, 15, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_rare,    {{rr_petal_id_shell,   0.05},{rr_petal_id_beak,      0.15},{rr_petal_id_pter_egg,  0.07}, {rr_petal_id_nest,      0.01}}},
    {rr_mob_id_dakotaraptor,       rr_rarity_id_common, rr_rarity_id_omega,  35, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_epic,    {{rr_petal_id_crest,    0.1},{rr_petal_id_feather,    0.1},{rr_petal_id_pellet,    0.05},{rr_petal_id_dako_egg,    0.08}}},
    {rr_mob_id_pachycephalosaurus, rr_rarity_id_common, rr_rarity_id_omega,  35, 20, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_common,  {{rr_petal_id_fossil,   0.1},{rr_petal_id_berry,      0.1},{rr_petal_id_web,       0.05}, {rr_petal_id_pachy_egg, 0.07}}},
    {rr_mob_id_ornithomimus,       rr_rarity_id_common, rr_rarity_id_omega,  25, 10, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_feather,  0.1},{rr_petal_id_droplet,   0.05},{rr_petal_id_pellet,     0.1}}},
    {rr_mob_id_ankylosaurus,       rr_rarity_id_rare, rr_rarity_id_omega,  50, 10, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_club,    0.15},{rr_petal_id_gravel,    0.05},{rr_petal_id_bubble,     0.1}}},
    {rr_mob_id_meteor,             rr_rarity_id_common, rr_rarity_id_omega, 100, 10, 32.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_magnet,   0.5},{rr_petal_id_uranium,   0.05},{rr_petal_id_fireball,   1.0},{rr_petal_id_meteor, 2.0}}},
    {rr_mob_id_quetzalcoatlus,     rr_rarity_id_rare, rr_rarity_id_omega,  65, 20, 28.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_common,  {{rr_petal_id_beak,    0.05},{rr_petal_id_fossil,     0.1},{rr_petal_id_lightning, 0.01}, {rr_petal_id_quetz_egg, 0.06}}},
    {rr_mob_id_edmontosaurus,      rr_rarity_id_common, rr_rarity_id_omega,  50, 15, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_bone,    0.01},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_ant,                rr_rarity_id_common, rr_rarity_id_omega,  10, 10, 20.0f, rr_rarity_id_common, rr_rarity_id_legendary,    rr_rarity_id_max,     {{rr_petal_id_pellet,   0.1},{rr_petal_id_leaf,       0.1},{rr_petal_id_mandible,  0.05}}},
    {rr_mob_id_hornet,             rr_rarity_id_common, rr_rarity_id_omega,  28, 25, 25.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_epic,     {{rr_petal_id_stinger,  0.1},{rr_petal_id_crest,     0.05}}},
    {rr_mob_id_dragonfly,          rr_rarity_id_common, rr_rarity_id_omega,  20, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_unusual,rr_rarity_id_legendary,{{rr_petal_id_pellet,   0.05}, {rr_petal_id_mint, 0.08}, {rr_petal_id_bubble, 0.1}}},
    {rr_mob_id_honeybee,           rr_rarity_id_common, rr_rarity_id_omega,  12, 25, 22.0f, rr_rarity_id_common, rr_rarity_id_rare,    rr_rarity_id_max,     {{rr_petal_id_wax,     0.05},{rr_petal_id_stinger,   0.05}}},
    {rr_mob_id_beehive,            rr_rarity_id_common, rr_rarity_id_omega,  200,  0, 45.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_wax,     0.05},{rr_petal_id_azalea,    0.05}}},
    {rr_mob_id_spider,             rr_rarity_id_common, rr_rarity_id_omega,  20, 25, 18.0f, rr_rarity_id_common, rr_rarity_id_common,   rr_rarity_id_rare,     {{rr_petal_id_web,      0.1},{rr_petal_id_berry, 0.1},{rr_petal_id_third_eye, 0.01}}},
    {rr_mob_id_house_centipede,    rr_rarity_id_common, rr_rarity_id_omega,  25, 10, 23.0f, rr_rarity_id_common, rr_rarity_id_unusual, rr_rarity_id_legendary,     {{rr_petal_id_peas,     0.1},{rr_petal_id_sand,      0.05}}},
    {rr_mob_id_lanternfly,         rr_rarity_id_common, rr_rarity_id_omega,  20, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_common,    rr_rarity_id_legendary,     {{rr_petal_id_mint,     0.1},{rr_petal_id_sand,      0.05}}},
};

char const *RR_MOB_NAMES[rr_mob_id_max] = {
"Triceratops","T-Rex","Fern","Tree","Pteranodon","Dakotaraptor",
"Pachycephalosaurus","Ornithomimus","Ankylosaurus","Meteor",
"Quetzalcoatlus","Edmontosaurus","Ant","Hornet","Dragonfly",
"Honeybee","Beehive","Spider","House Centipede","Lanternfly"
};

uint32_t RR_MOB_DIFFICULTY_COEFFICIENTS[rr_mob_id_max] = {
    3, //tric
    4, //trex
    1, //fern
    2, //tree
    5, //pter
    5, //dako
    3, //pachy
    2, //ornith
    4, //anky
    1, //meteor
    5, //quetz
    3, //edmo
    2, //ant
    5, //hornet
    3, //dragonfly
    3, //honeybee
    7, //beehive
    4, //spider
    3, //house centipede
    3 //lanternfly
};

double RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    50,   //tric
    100,  //trex
    15,   //fern
    0.25, //tree
    75,   //pter
    50,   //dako
    25,   //pachy
    40,   //ornith
    25,   //anky
    1,    //meteor
    75,   //quetz
    25,   //edmo
};
double RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 10};

struct rr_petal_rarity_scale RR_PETAL_RARITY_SCALE[rr_rarity_id_max] = {
    {1,    240, 45 },
    {1.8,  120, 60 },
    {3.5,  60,  75 },
    {6.8,  30,  100},
    {12.5, 15,  125},
    {24.5, 7.5, 150},
    {60,   2.5, 200},
    {180,  0.5, 250},
    {500,  0.2, 350},
};

struct rr_mob_rarity_scale RR_MOB_RARITY_SCALING[rr_rarity_id_max] = {
    {1,      1,    1  },
    {2.4,    1.7,  1.2},
    {6,      2.9,  1.5}, 
    {14.4,   5,    2  },
    {40,     8.5,  2.8},
    {192,    14.5, 4  },
    {2560,   24.6, 5.5},
    {128000, 42,   7  },
    {2342000,212,   10},
};
// clang-format on

uint32_t RR_RARITY_COLORS[rr_rarity_id_max] = {
    0xff7eef6d, 0xffffe65d, 0xff4d52e3, 0xff861fde,
    0xffde1f1f, 0xff1fdbde, 0xffff2b75, 0xff2bffa3, 0xff333333};

char const *RR_RARITY_NAMES[rr_rarity_id_max] = {
    "Common",    "Unusual", "Rare",   "Epic",
    "Legendary", "Mythic",  "Exotic", "Ancient", "Omega"
};

double RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_max + 1] = {
    0, 1, 6, 10, 15, 25, 160, 1200, 250, 1000};

double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_exotic + 3] = {
    0, 1, 5, 10, 20, 80, 400, 450, 800};
double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {2.5, 4,  6,   15,
                                                            35,  50, 125, 150, 300};

static void init_game_coefficients()
{
    double sum = 1;
    double sum2 = 1;
    for (uint64_t a = 1; a < rr_rarity_id_max; ++a)
        RR_MOB_LOOT_RARITY_COEFFICIENTS[a] *=
            RR_MOB_LOOT_RARITY_COEFFICIENTS[a - 1];
    for (uint64_t a = 1; a <= rr_rarity_id_exotic + 1; ++a)
    {
        sum += (RR_DROP_RARITY_COEFFICIENTS[a + 1] =
                    RR_DROP_RARITY_COEFFICIENTS[a] /
                    RR_DROP_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_exotic + 2; ++a)
    {
        RR_DROP_RARITY_COEFFICIENTS[a] = RR_DROP_RARITY_COEFFICIENTS[a] / sum +
                                         RR_DROP_RARITY_COEFFICIENTS[a - 1];
    }
    RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_exotic + 2] = 1;
    for (uint64_t a = 1; a <= rr_rarity_id_ultimate + 1; ++a)
    {
        sum2 += (RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1] =
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a] /
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_ultimate + 2; ++a)
    {
        RR_MOB_WAVE_RARITY_COEFFICIENTS[a] =
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a] / sum2 +
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a - 1];
    }
    RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_ultimate + 2] = 1;
    for (uint64_t mob = 1; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
    }
    for (uint64_t mob = 0; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
    }
}

#define offset(a, b)                                                           \
    ((x + a < 0 || y + b < 0 || x + a >= size / 2 || y + b >= size / 2)        \
         ? 0                                                                   \
         : template[(y + b) * size / 2 + x + a])
#define maze_grid(x, y) maze[(y)*size + (x)]

static void init_maze(uint32_t size, uint8_t *template,
                      struct rr_maze_grid *maze)
{
    for (int32_t y = 0; y < size / 2; ++y)
    {
        for (int32_t x = 0; x < size / 2; ++x)
        {
            uint8_t this_tile = offset(0, 0);
#ifdef RR_SERVER
            maze_grid(x * 2, y * 2).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2).difficulty = this_tile;
            maze_grid(x * 2, y * 2 + 1).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2 + 1).difficulty = this_tile;
#endif
            this_tile = this_tile != 0;
            // top left
            uint8_t top = offset(0, -1);
            uint8_t bottom = offset(0, 1);
            if (this_tile)
            {
                if (top == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2).value = 7;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2).value = 5;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2 + 1).value = 6;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 4;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
            else
            {
                if (top)
                {
                    if (offset(-1, 0) && offset(-1, -1))
                        maze_grid(x * 2, y * 2).value = 15;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) && offset(1, -1))
                        maze_grid(x * 2 + 1, y * 2).value = 13;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom)
                {
                    if (offset(-1, 0) && offset(-1, 1))
                        maze_grid(x * 2, y * 2 + 1).value = 14;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) && offset(1, 1))
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 12;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
        }
    }
}

static void print_chances(float difficulty)
{
    printf("-----Chances for %.0f-----\n", difficulty);
    uint32_t rarity_cap = rr_rarity_id_common + (difficulty + 7) / 8;
    if (rarity_cap > rr_rarity_id_ultimate + 1)
        rarity_cap = rr_rarity_id_ultimate + 1;
    uint32_t rarity = rarity_cap >= 2 ? rarity_cap - 2 : 0;
    for (; rarity <= rarity_cap; ++rarity)
    {
        float start =
            rarity == 0
                ? 0
                : pow(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity]) * 0.3,
                      pow(1.5, difficulty));
        float end =
            rarity == rarity_cap
                ? 1
                : pow(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity + 1]) *
                              0.3,
                      pow(1.5, difficulty));
        printf("%s: %.9f (1 per %.4f)\n", RR_RARITY_NAMES[rarity], end - start,
               1 / (end - start));
    }
}

double RR_BASE_CRAFT_CHANCES[rr_rarity_id_max - 1] = {0.65,  0.4,  0.3, 0.1,
                                                      0.05, 0.03, 0.02, 0.01};
double RR_CRAFT_CHANCES[rr_rarity_id_max - 1];

static double from_prd_base(double C)
{
    double pProcOnN = 0;
    double pProcByN = 0;
    double sumNpProcOnN = 0;

    double maxFails = ceil(1 / C);
    for (uint32_t N = 1; N <= maxFails; ++N)
    {
        pProcOnN = fmin(1, N * C) * (1 - pProcByN);
        pProcByN += pProcOnN;
        sumNpProcOnN += N * pProcOnN;
    }
    return (1 / sumNpProcOnN);
}

static double get_prd_base(double p)
{
    if (p == 0)
        return 0;
    double Cupper = p;
    double Clower = 0;
    double Cmid = p / 2;
    double p1 = 0;
    double p2 = 1;
    while (1)
    {
        Cmid = (Cupper + Clower) / 2;
        p1 = from_prd_base(Cmid);
        if (fabs(p1 - p2) <= 0)
            break;

        if (p1 > p)
            Cupper = Cmid;
        else
            Clower = Cmid;
        p2 = p1;
    }
    return Cmid;
}

#define init(MAZE)                                                             \
    init_maze(sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid),         \
              &RR_MAZE_TEMPLATE_##MAZE[0][0], &RR_MAZE_##MAZE[0][0]);

void rr_static_data_init()
{
    for (uint32_t r = 0; r < rr_rarity_id_max - 1; ++r)
        RR_CRAFT_CHANCES[r] = get_prd_base(RR_BASE_CRAFT_CHANCES[r]);
    init_game_coefficients();
    init(HELL_CREEK);
    init(BURROW);
#ifdef RR_SERVER
    print_chances(1);  // c
    print_chances(4);  // C
    print_chances(8);  // u
    print_chances(12); // U
    print_chances(16); // r
    print_chances(20); // R
    print_chances(24); // e
    print_chances(28); // E
    print_chances(32); // l
    print_chances(36); // L
    print_chances(40); // m
    print_chances(44); // M
    print_chances(48); // x
    print_chances(52); // X
    print_chances(56); // a
    print_chances(60); // A
    print_chances(66); // o
    print_chances(72); // O

#endif
}

double xp_to_reach_level(uint32_t level)
{
    if (level <= 60)
        return (level + 5) * pow(1.175, level);
    double base = (level + 5) * pow(1.175, 60);
    for (uint32_t i = 60; i < level; ++i)
        base *= rr_fclamp(1.18 - 0.0075 * (i - 60), 1.1, 1.18);
    return base;
}

uint32_t level_from_xp(double xp)
{
    uint32_t level = 1;
    while (xp >= xp_to_reach_level(level + 1))
        xp -= xp_to_reach_level(++level);
    return level;
}

#ifdef RR_SERVER
#define _ 0
#define c 1
#define C 4
#define u 8
#define U 12
#define r 16
#define R 20
#define e 24
#define E 28
#define l 32
#define L 36
#define m 40
#define M 44
#define x 48
#define X 52
#define a 56
#define A 60
#define o 66
#define O 72
#else
#define _ 0
#define c 1
#define C 1
#define u 1
#define U 1
#define r 1
#define R 1
#define e 1
#define E 1
#define l 1
#define L 1
#define m 1
#define M 1
#define x 1
#define X 1
#define a 1
#define A 1
#define o 1
#define O 1
#endif
// 1 laza 1 lleaf 1 lmagnet 1 lmeteor 4 efeather 2 ldako egg 1 lcrest 4 lshell 5 lpter egg 5 lbeak
#define RR_DEFINE_MAZE(name, size)                                             \
    struct rr_maze_grid RR_MAZE_##name[size][size];                            \
    uint8_t RR_MAZE_TEMPLATE_##name[size / 2][size / 2]
// clang-format off
RR_DEFINE_MAZE(HELL_CREEK, 80) = {
//                     11  13  15  17  19  21  23  25  27  29  31  33  35  37  39
// 1 2 3 4 5 6 7 8 9 10  12  14  16  18  20  22  24  26  28  30  32  34  36  38
/*
{c,c,_,_,R,R,e,e,e,R,R,_,_,U,r,r,r,r,R,R,R,R,R,e,e,e,e,e,E,E,E,E,E,E,E,l,l,l,l,l}, // 0
{c,c,_,_,_,r,_,_,_,r,_,_,U,U,r,r,r,r,_,R,R,R,_,e,e,e,_,_,E,E,E,_,_,E,E,l,l,l,l,l}, // 1
{c,_,_,_,_,r,r,r,r,r,_,U,U,_,r,r,_,_,_,_,_,R,e,_,e,e,e,e,_,E,E,E,_,_,E,_,_,_,_,l}, // 2
{c,c,c,c,_,_,U,U,U,_,_,U,U,U,r,_,e,e,e,e,e,_,e,_,_,e,e,e,e,_,E,l,l,_,_,_,L,L,_,l}, // 3
{c,c,c,c,_,_,_,U,_,U,U,U,_,_,r,_,e,_,E,_,e,_,e,e,_,_,e,e,e,e,_,l,l,l,_,L,L,L,_,l}, // 4
{C,C,C,C,_,U,U,U,U,U,_,_,_,r,r,_,e,_,E,_,e,_,_,E,E,_,_,E,E,E,E,_,l,l,l,L,L,L,_,l}, // 5
{C,C,_,u,u,U,U,U,U,U,_,r,r,r,_,_,e,e,e,e,e,_,_,_,E,E,_,_,_,_,E,_,_,_,_,_,_,_,_,l}, // 6
{C,_,_,u,u,_,_,_,_,_,_,r,r,_,_,e,e,_,_,_,e,e,_,L,_,l,l,l,l,_,E,E,_,X,X,X,X,X,_,l}, // 7
{C,_,u,u,_,R,R,R,R,R,r,r,_,_,R,R,_,_,l,_,_,E,_,L,L,_,_,l,_,_,E,E,_,X,x,x,_,_,_,l}, // 8
{u,u,u,_,R,R,R,R,R,R,r,_,_,_,R,R,_,l,l,l,_,E,_,_,L,l,l,l,l,_,E,E,_,X,x,x,x,_,_,L}, // 9
{u,u,_,R,R,_,_,R,R,_,_,_,_,R,R,R,_,_,E,_,_,E,E,_,_,_,_,_,_,_,_,l,_,a,_,_,x,x,_,L}, // 10
{u,_,R,R,_,e,_,_,R,R,R,R,R,R,R,_,_,_,e,_,_,_,E,_,_,_,_,L,L,_,l,l,_,a,_,_,_,x,_,L}, // 11
{_,R,R,_,e,e,e,_,_,R,R,_,_,_,R,_,_,e,e,e,_,_,E,E,l,_,l,L,_,_,l,l,_,a,_,_,x,x,_,L}, // 12
{e,e,e,e,e,e,e,_,_,R,R,R,R,R,R,R,e,e,e,e,e,E,E,E,l,l,l,_,_,l,l,l,_,a,A,_,x,_,L,L}, // 13
{E,_,_,e,e,e,e,_,e,e,_,R,R,_,R,_,_,e,e,e,_,_,E,_,l,l,_,_,l,l,l,_,_,_,_,x,x,_,L,L}, // 14
{E,E,_,_,e,e,_,_,e,e,_,_,R,R,R,_,_,_,e,_,_,_,E,E,l,_,_,L,L,L,_,_,_,x,x,x,_,L,L,_}, // 15
{E,E,_,E,E,E,E,_,e,e,e,_,_,R,R,R,_,e,e,e,_,E,E,E,_,_,L,L,L,_,_,x,x,x,_,_,m,m,_,_}, // 16
{l,l,_,E,_,E,E,_,E,E,_,_,_,R,R,_,_,_,E,_,_,_,E,E,_,L,L,L,_,_,x,x,_,_,m,m,m,_,_,X}, // 17
{l,l,_,E,_,_,E,_,E,E,E,_,_,R,_,e,e,E,E,E,E,E,_,E,_,_,L,L,_,x,x,_,_,M,M,m,_,_,X,X}, // 18
{l,l,_,E,E,E,E,_,_,l,l,_,R,R,_,e,e,_,_,_,l,l,_,E,E,_,L,L,_,x,x,_,M,M,M,_,_,_,_,x}, // 19
{l,l,_,l,l,l,l,_,l,l,_,_,R,_,e,e,_,_,x,_,_,l,l,_,E,_,_,L,_,_,x,_,M,M,M,_,x,x,x,x}, // 20
{L,L,_,l,l,_,l,_,l,l,_,e,e,e,e,_,_,m,L,c,_,_,l,l,l,l,_,L,L,_,x,_,_,_,_,_,x,x,x,M}, // 21
{L,L,_,_,l,_,l,_,L,_,_,e,e,e,_,_,e,l,_,r,E,_,_,l,l,l,_,_,L,_,x,x,x,_,_,x,x,_,_,M}, // 22
{L,L,_,L,L,L,L,_,L,_,E,e,e,_,_,r,L,_,_,_,C,e,_,_,l,l,L,_,L,_,_,_,x,x,x,x,_,_,M,M}, // 23
{L,L,_,L,L,L,L,_,L,_,E,E,_,_,R,E,_,_,_,_,_,l,m,_,_,L,L,_,L,L,L,_,_,x,x,_,_,M,M,M}, // 24
{L,L,_,m,_,_,m,_,_,_,_,_,_,M,C,_,_,M,M,M,_,_,M,U,_,_,_,_,L,_,_,_,_,_,_,_,_,_,_,M}, // 25
{L,L,_,m,m,m,m,_,m,m,_,_,l,U,_,_,M,M,M,M,M,_,_,R,u,_,_,_,m,m,m,m,_,m,m,m,_,m,m,M}, // 26
{m,m,_,_,m,_,_,_,m,m,m,r,L,M,M,M,M,_,M,_,M,M,M,M,E,c,_,_,m,m,m,m,m,m,_,m,m,m,m,M}, // 27
{m,m,_,m,m,m,m,m,m,_,R,E,_,M,M,M,_,x,x,x,_,M,M,M,_,e,M,_,_,_,m,_,_,_,_,_,_,_,_,M}, // 28
{m,m,_,m,_,_,m,m,_,u,C,_,_,_,M,M,M,_,M,_,M,M,M,_,_,_,C,L,_,_,m,_,M,M,M,_,M,M,M,M}, // 29
{m,m,_,m,m,m,m,_,c,M,_,_,_,M,M,M,M,M,M,M,M,M,M,M,_,_,_,m,M,_,m,_,x,_,M,_,x,_,_,_}, // 30
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,x,_,m,_,_,_,M,_,x,_,X,X}, // 31
{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,_,x,_,m,M,M,M,M,_,x,x,_,X}, // 32
{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,_,_,_,_,_,x,_,X}, // 33
{x,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,a,_,a,a,a,a,_,x,x,X}, // 34
{X,X,_,X,X,X,X,X,_,X,X,X,X,X,_,X,X,X,X,X,_,X,X,X,X,X,_,X,X,_,a,a,a,a,a,a,_,_,_,_}, // 35
{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,_,a,_,_,a,_,a,_,A,A,A}, // 36
{X,_,_,_,_,_,X,X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,_,_,_,_,_,_,X,_,a,a,a,a,_,a,_,A,_,A}, // 37
{X,_,X,X,X,_,_,_,_,a,a,a,a,a,_,a,a,A,A,A,_,X,_,_,a,a,_,X,X,X,X,X,_,_,_,A,A,A,A,A}, // 38
{X,X,X,_,X,a,a,a,a,a,_,a,_,a,a,a,_,A,A,A,_,X,X,X,a,a,_,X,X,X,X,X,_,A,A,A,A,A,A,A}, // 39
*/
// /*
{l,l,l,l,_,_,_,e,e,e,R,R,R,R,R,_,e,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}, // 0
{l,_,_,l,_,e,e,e,_,_,_,_,_,_,R,_,e,_,_,c,c,c,_,_,_,_,_,_,_,_,_,_,_,_,_,E,E,e,_,_}, // 1
{E,_,L,l,_,e,_,e,_,e,_,R,R,R,R,R,R,_,c,c,c,c,c,_,_,C,_,_,_,r,r,U,U,_,_,_,_,e,_,_}, // 2
{E,_,_,_,_,e,_,e,e,e,_,R,_,_,R,_,_,_,_,c,c,c,c,c,C,C,C,C,_,_,U,U,U,U,U,e,e,e,e,e}, // 3
{E,E,E,E,_,_,_,e,_,_,_,e,_,R,R,_,e,e,_,_,c,c,c,_,_,C,C,_,_,_,_,U,U,U,_,e,_,_,_,e}, // 4
{E,E,_,E,E,E,e,e,e,e,_,e,_,r,R,R,e,_,_,_,_,c,_,_,_,u,u,_,u,_,_,U,U,U,_,e,E,E,_,e}, // 5
{_,l,_,_,_,_,_,_,_,_,_,_,_,r,R,R,e,e,e,E,_,_,_,u,u,u,u,u,u,u,U,U,U,U,_,_,_,_,_,e}, // 6
{_,l,l,l,l,l,l,l,_,_,_,_,r,r,r,_,_,_,_,_,_,u,u,u,u,u,u,u,u,u,_,U,U,U,U,e,e,e,e,e}, // 7
{_,l,_,_,_,l,l,l,_,_,_,r,r,r,_,_,_,U,U,_,_,u,_,_,u,u,u,_,_,_,_,_,_,_,r,_,_,_,_,_}, // 8
{_,l,_,l,_,l,l,_,_,l,_,r,r,r,_,_,_,_,U,_,U,U,_,_,u,u,u,u,_,_,_,_,r,_,r,r,r,r,r,r}, // 9
{_,l,l,l,_,_,l,_,l,l,_,_,r,r,r,_,U,U,U,U,U,U,_,_,_,_,u,_,_,_,_,_,r,r,r,r,_,r,r,_}, // 10
{_,l,_,_,_,_,_,_,l,l,l,_,_,r,r,U,U,U,_,_,_,U,_,_,_,r,r,_,_,R,_,R,R,R,R,_,_,_,_,_}, // 11
{_,l,l,l,l,l,l,l,l,_,_,_,_,_,_,_,e,e,_,_,e,e,e,_,_,r,r,_,_,R,R,R,_,R,R,R,R,R,R,_}, // 12
{_,_,l,l,l,l,l,_,_,_,l,l,_,_,_,_,_,e,_,_,_,e,e,e,_,R,_,_,_,_,_,R,R,R,_,_,R,R,_,_}, // 13
{_,_,L,L,_,l,l,l,l,l,l,l,l,_,_,_,_,_,_,_,_,_,e,_,_,R,R,_,_,_,_,_,_,_,_,_,_,R,_,_}, // 14
{_,_,L,L,_,_,_,L,_,_,_,l,_,_,_,_,o,_,_,_,_,_,_,_,_,_,_,_,_,_,_,E,E,e,e,e,e,e,_,_}, // 15
{_,_,L,L,L,_,L,L,L,L,l,l,_,_,_,o,o,o,_,_,_,_,_,_,_,_,_,_,E,E,E,E,E,e,e,e,e,e,e,_}, // 16
{m,m,L,_,L,L,L,L,_,_,_,_,_,O,O,O,o,o,o,o,A,_,_,_,_,_,_,_,E,E,E,E,_,e,e,e,_,_,e,_}, // 17
{m,m,m,_,_,_,_,_,_,_,_,_,O,O,O,_,o,o,o,o,A,A,_,_,_,A,_,l,l,E,E,E,_,_,e,e,e,e,e,_}, // 18
{_,m,m,m,m,_,_,_,_,_,_,_,_,O,O,_,_,_,_,_,A,A,A,_,A,A,_,l,l,l,_,l,l,_,_,_,_,e,e,_}, // 19
{_,m,m,m,_,_,_,_,_,m,m,m,_,_,_,_,m,m,m,_,A,A,A,A,A,_,_,_,l,l,l,l,l,l,_,_,_,e,e,_}, // 20
{m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,A,A,A,A,A,_,l,l,l,_,_,_,_,_,_,_,_,_,_}, // 21
{m,_,m,m,m,m,_,_,_,m,m,m,_,_,_,_,m,m,m,_,_,_,_,A,_,_,_,L,l,l,_,L,L,_,_,m,m,_,_,_}, // 22
{_,_,_,m,m,m,_,_,_,_,_,_,_,x,x,_,_,_,_,_,_,a,a,a,a,_,_,L,L,L,L,L,L,_,m,m,m,m,m,_}, // 23
{_,_,_,m,m,M,M,_,_,_,_,_,_,x,x,_,_,_,_,_,a,a,_,_,a,a,_,_,L,L,L,L,L,m,m,_,_,_,m,_}, // 24
{R,U,_,_,_,M,M,_,M,M,_,_,_,x,_,_,_,_,_,_,a,a,a,a,a,a,a,_,_,_,_,_,_,m,m,_,m,m,m,_}, // 25
{_,M,E,c,M,M,M,M,M,_,_,M,_,x,_,x,_,_,_,_,a,a,a,_,X,_,_,_,_,_,_,_,_,_,m,m,m,m,_,_},// 26
{_,r,C,u,_,_,_,M,M,M,M,M,M,x,x,x,x,x,x,_,a,_,X,_,X,X,X,_,_,_,_,_,_,_,M,_,_,_,_,_}, // 27
{_,m,_,L,e,x,_,_,M,M,M,M,_,x,x,_,_,x,x,_,_,_,X,X,X,_,X,_,_,M,M,_,M,_,M,_,M,M,M,M}, // 28
{c,u,l,r,E,_,_,_,_,M,M,_,_,x,_,_,_,x,_,_,_,X,X,_,X,_,X,_,_,M,M,M,M,M,M,M,M,M,M,_}, // 29
{_,_,_,_,M,_,_,_,_,_,_,_,_,_,_,_,x,x,x,_,X,X,_,_,X,X,X,_,_,x,M,M,M,_,_,_,_,M,_,_}, // 30
{_,_,L,C,e,r,_,_,_,_,X,X,x,x,_,_,x,x,x,X,X,X,X,X,X,X,_,_,x,x,x,x,_,_,a,_,_,_,_,a}, // 31
{_,_,M,_,_,_,_,_,_,X,X,X,x,x,x,_,x,_,_,_,_,_,_,_,_,_,_,x,x,_,_,_,_,a,a,_,a,a,a,a}, // 32
{_,_,M,M,M,M,M,M,_,_,X,_,x,x,x,_,x,_,c,c,c,c,c,_,x,x,x,x,_,_,a,a,a,a,a,a,a,a,a,a}, // 33
{_,_,M,M,_,_,_,M,M,_,_,_,x,x,_,_,x,_,c,c,c,c,c,_,x,_,_,_,_,X,X,_,a,a,a,a,a,a,_,a}, // 34
{_,_,M,_,_,_,_,_,M,_,_,_,_,x,_,_,x,_,c,c,c,c,c,_,x,_,X,X,X,X,_,_,_,_,_,A,_,_,_,A}, // 35
{_,_,M,M,_,_,_,M,M,_,x,x,x,x,x,x,x,_,_,_,_,_,_,_,X,X,X,X,_,_,_,_,_,o,_,A,A,A,A,A}, // 36
{_,_,_,M,M,_,M,M,_,_,x,_,_,_,_,_,_,_,X,X,X,X,_,_,X,X,X,_,_,_,O,o,o,o,_,_,A,A,A,_}, // 37
{O,O,_,_,M,M,M,_,_,_,X,X,X,X,X,_,X,X,X,X,_,_,_,X,X,X,_,_,O,O,O,o,o,o,o,A,A,A,_,_}, // 38
{O,O,_,_,_,_,_,_,_,X,X,_,X,X,X,X,X,X,X,X,X,X,X,X,X,_,_,_,_,O,O,_,o,o,o,A,A,_,_,_}, // 39
// */
/*
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}, // 0
{x,x,_,_,_,_,_,x,x,x,x,_,_,x,x,x,x,x,M,M,M,M,M,M,M,_,_,_,m,m,m,m,m,m,m,m,m,m,_,_}, // 1
{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,M,M,_,M,M,M,M,M,_,_,m,m,m,m,m,_,_,m,_,m,_,_}, // 2
{_,_,_,x,_,_,_,x,x,_,x,_,_,_,_,x,x,x,x,_,_,M,_,M,M,M,_,m,m,_,_,_,_,_,_,m,m,m,_,_}, // 3
{_,_,_,x,_,X,_,_,x,_,x,_,x,x,x,x,x,x,x,_,_,M,_,_,_,M,M,m,m,m,m,_,_,_,m,m,m,_,_,_}, // 4
{_,_,_,x,_,X,X,_,_,_,x,_,_,x,_,_,_,_,_,_,_,M,M,M,M,M,M,m,m,m,m,m,m,m,m,_,m,m,m,_}, // 5
{_,x,x,x,x,X,X,X,_,_,x,x,x,x,x,_,u,r,_,_,M,M,_,_,M,M,M,m,m,_,_,_,m,m,m,m,m,m,m,_}, // 6
{_,x,x,x,_,_,_,_,_,_,_,_,_,_,_,_,U,R,e,_,M,M,_,_,M,_,_,_,_,_,_,_,m,_,_,m,m,m,m,_}, // 7
{_,_,x,x,x,_,a,a,a,a,a,a,a,a,_,M,c,_,l,L,c,R,_,_,M,_,M,M,M,_,m,m,m,_,_,_,_,m,m,_}, // 8
{_,_,x,x,x,_,a,a,_,_,_,_,a,a,_,_,l,_,E,C,_,_,_,_,M,M,M,M,M,m,m,_,_,_,_,_,m,m,m,_}, // 9
{_,_,x,x,x,_,a,a,a,a,a,a,a,a,_,_,L,m,e,U,x,_,_,M,M,_,M,M,M,_,_,_,_,_,_,_,m,m,m,m}, // 10
{_,_,x,x,x,_,a,a,a,a,_,_,_,a,_,_,_,_,M,_,_,_,M,M,M,_,_,_,_,_,L,L,L,L,L,_,_,m,m,m}, // 11
{_,_,_,_,X,_,a,a,a,a,_,A,A,a,_,M,M,M,M,_,x,x,M,M,M,_,_,_,m,m,L,_,L,L,L,_,L,L,_,_}, // 12
{_,_,_,_,X,_,A,A,_,a,_,_,_,a,_,M,M,_,_,_,x,x,x,M,M,_,_,_,m,m,L,L,L,_,L,L,L,L,L,L}, // 13
{_,X,X,_,X,_,_,_,_,a,_,_,_,a,_,M,M,M,_,x,x,x,x,_,_,_,_,_,_,_,_,_,_,_,_,_,L,_,L,L}, // 14
{_,X,X,_,X,X,X,X,X,a,a,a,a,a,_,_,_,_,_,x,x,x,x,_,a,a,a,a,a,_,_,_,_,_,_,_,L,L,L,L}, // 15
{_,X,X,_,_,_,X,X,_,_,_,_,_,_,_,_,x,x,x,x,x,x,x,_,a,a,_,a,a,_,_,_,_,_,_,_,_,L,L,L}, // 16
{_,X,X,X,X,X,X,_,_,X,X,X,X,X,_,x,x,_,_,_,_,_,_,_,a,a,_,a,_,_,_,_,l,l,l,_,_,l,l,l}, // 17
{_,_,_,_,_,_,X,_,_,_,X,_,X,X,X,X,_,_,_,_,_,_,a,a,a,a,_,a,_,L,L,l,l,l,l,l,_,l,l,l}, // 18
{X,X,X,a,a,_,X,_,_,_,X,X,X,_,_,X,_,X,X,X,_,_,a,a,a,a,_,a,_,L,L,L,L,_,l,l,l,l,l,l}, // 19
{X,X,X,_,_,_,X,_,_,_,_,_,X,X,X,X,X,X,X,X,X,X,X,_,_,_,_,a,_,_,_,_,_,_,_,_,_,l,_,l}, // 20
{X,X,X,X,X,X,X,_,_,_,_,_,_,_,_,X,X,_,_,_,X,X,X,_,A,A,A,a,_,_,_,_,_,_,_,l,l,l,l,l}, // 21
{a,_,X,X,X,_,_,_,r,r,r,r,_,_,_,X,X,_,X,_,X,X,X,_,A,A,A,_,_,_,E,E,E,_,_,l,l,l,l,_}, // 22
{a,_,X,X,X,_,R,R,r,_,r,r,_,_,_,X,X,X,X,X,X,_,_,_,_,_,_,_,_,E,E,E,E,_,_,l,l,_,l,l}, // 23
{_,_,X,X,X,_,_,_,_,_,_,U,_,_,_,_,_,_,_,_,_,_,_,e,e,e,e,E,E,E,E,E,l,l,l,l,l,_,l,l}, // 24
{X,X,X,_,X,X,X,X,a,a,_,U,U,U,U,_,e,e,e,e,e,e,_,e,e,_,e,_,_,E,E,E,l,l,l,l,_,_,l,_}, // 25
{X,_,_,_,X,_,X,X,a,a,_,U,U,_,U,U,e,_,e,_,_,e,e,e,e,e,e,_,E,E,E,_,_,_,_,l,_,_,L,_}, // 26
{X,X,_,x,x,_,X,_,a,a,_,u,u,_,U,U,_,_,e,E,_,_,R,R,_,_,_,_,E,_,_,_,l,l,l,l,_,L,L,_}, // 27
{_,x,x,x,x,X,X,_,a,_,_,u,u,u,u,U,U,_,_,_,_,R,R,R,R,R,_,l,l,l,_,l,l,_,_,_,_,L,L,_}, // 28
{_,x,x,_,_,_,_,_,a,a,_,u,u,u,u,u,U,U,U,r,r,r,r,r,_,R,_,l,_,l,_,l,l,_,L,L,L,L,L,L}, // 29
{_,x,x,x,x,x,_,A,A,_,_,u,_,C,u,u,_,U,U,U,r,r,r,r,_,R,_,_,_,_,_,l,_,_,L,L,L,L,_,m}, // 30
{_,_,_,_,x,x,_,A,A,_,C,C,_,C,u,u,u,U,U,U,U,_,r,r,R,R,_,l,l,l,l,l,_,_,_,_,_,m,_,m}, // 31
{M,M,M,M,M,M,_,_,_,_,C,C,C,C,u,u,u,_,_,_,U,_,_,_,_,_,_,l,_,_,_,l,_,M,M,M,_,m,_,m}, // 32
{M,M,_,_,_,M,_,c,c,c,c,c,_,u,u,u,u,_,e,e,e,_,_,_,l,l,l,l,_,l,l,l,_,M,_,x,_,m,_,m}, // 33
{M,_,_,m,_,M,_,c,c,_,c,c,_,u,u,u,u,_,e,e,e,_,_,_,l,_,_,l,_,l,_,l,_,M,_,_,_,m,_,m}, // 34
{m,m,m,m,_,_,_,_,_,_,_,_,_,u,_,_,U,_,_,_,_,_,_,_,l,_,L,l,_,l,_,l,_,m,m,m,m,m,_,M}, // 35
{_,_,_,m,_,l,l,l,_,e,e,e,_,e,_,_,U,U,U,r,r,r,r,_,l,l,l,l,_,l,l,l,_,_,_,_,_,_,_,M}, // 36
{m,m,m,m,_,l,l,l,_,e,e,e,e,e,_,_,_,_,_,_,_,_,r,_,_,_,_,_,_,_,_,l,_,_,X,X,_,_,_,M}, // 37
{L,_,_,_,_,l,_,l,_,_,_,_,_,_,_,e,e,e,_,R,R,R,R,R,e,e,e,_,L,L,_,l,_,_,X,X,x,x,_,M}, // 38
{L,L,L,L,L,L,_,l,l,E,E,E,E,e,e,e,_,e,e,R,_,_,_,R,e,e,e,_,L,L,l,l,_,_,X,X,_,x,x,x}, // 39
*/
};
// clang-format on
RR_DEFINE_MAZE(BURROW, 4) = {{1, 1}, {0, 1}};

#define MAZE_ENTRY(MAZE, GRID_SIZE)                                            \
    (sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid)), GRID_SIZE,      \
        &RR_MAZE_##MAZE[0][0]

struct rr_maze_declaration RR_MAZES[rr_biome_id_max] = {
    {MAZE_ENTRY(HELL_CREEK, 1024), 14, {
        // trigger x, trigger y, trigger w, trigger h, spawn x, spawn y, level
        // {0,  0,  3, 3, 1,  1,  1},   // 0
        // {6,  4,  3, 3, 7,  5,  20},  // 1
        // {16, 0,  5, 2, 18, 0,  40},  // 2
        // {5,  8,  5, 2, 7,  9,  60},  // 3
        // {17, 12, 3, 3, 18, 13, 80},  // 4
        // {16, 5,  5, 2, 18, 13, 80},  // 5
        // {12, 19, 3, 3, 18, 13, 80},  // 6
        // {28, 0,  3, 2, 29, 1,  60},  // 7
        // {38, 13, 2, 2, 38, 14, 80},  // 8
        // {26, 16, 2, 3, 26, 17, 80},  // 9
        // {3,  28, 3, 1, 4,  28, 80}, // 10
        // {38, 20, 2, 2, 39, 21, 100}, // 11
        // {0,  33, 1, 2, 0,  33, 100}, // 12

        {18,  1, 4, 4, 19,  2,  1},   // 0
        {24,  6, 4, 2, 25, 6, 20},  // 1
        {12, 7, 3, 1, 13, 7, 40},  // 2
        {0, 5, 3, 1, 1, 5, 60},  // 3
        {2, 15, 2, 2, 2, 16, 80},  // 4
        {12,27, 1, 1, 12, 27, 100},  // 5
        {15,39, 1, 1, 15, 39, 120},  // 6

        {34, 8, 1, 1, 34, 8, 20},  // 7
        {37, 14, 1, 1, 37,14,40},  // 8
        {27, 18, 5, 3, 29,20,60},  // 9
        {34, 26, 2, 2, 34,26,80}, // 10
        {28, 31, 2, 2, 28,31,100}, // 11
        {24, 26, 1, 1, 24,26,120}, // 12

        {18, 33, 5, 3, 20,34, 1}, // 13

    }},
    {MAZE_ENTRY(HELL_CREEK, 1024), 0},
    {MAZE_ENTRY(BURROW, 512), 0},
};

uint8_t RR_GLOBAL_BIOME = rr_biome_id_hell_creek;
#undef _
#undef c
#undef C
#undef u
#undef U
#undef r
#undef R
#undef e
#undef E
#undef l
#undef L
#undef m
#undef M
#undef x
#undef X
#undef a
#undef A
#undef o
#undef O