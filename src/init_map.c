# include "utils.h"

char init_show_char[7] = {'\033', '[', '3', '7', 'm', '\0', '\0'};

void init_map(Map *map){
    // init start cell
    strncpy(map->cells[START_POSITION].show_char, init_show_char, 5);
    map->cells[START_POSITION].show_char[5] = START_SHOW_CHAR;
    strncpy(map->cells[START_POSITION].origion_char, init_show_char, 5);
    map->cells[START_POSITION].origion_char[5] = START_SHOW_CHAR;
    map->cells[START_POSITION].kind = START;
    map->cells[START_POSITION].rank = RANK0;
    map->cells[START_POSITION].has_tool = 0;
    map->cells[START_POSITION].owner = NO_ONE;

    // init hospital
    strncpy(map->cells[HOSPITAL_POSITION].show_char, init_show_char, 5);
    map->cells[HOSPITAL_POSITION].show_char[5] = PRISON_SHOW_CHAR;
    strncpy(map->cells[HOSPITAL_POSITION].origion_char, init_show_char, 5);
    map->cells[HOSPITAL_POSITION].origion_char[5] = PRISON_SHOW_CHAR;
    map->cells[HOSPITAL_POSITION].kind = PARK;
    map->cells[HOSPITAL_POSITION].rank = RANK0;
    map->cells[HOSPITAL_POSITION].has_tool = 0;
    map->cells[HOSPITAL_POSITION].owner = NO_ONE;

    // init prison
    strncpy(map->cells[PRISON_POSITION].show_char, init_show_char, 5);
    map->cells[PRISON_POSITION].show_char[5] = PRISON_SHOW_CHAR;
    strncpy(map->cells[PRISON_POSITION].origion_char, init_show_char, 5);
    map->cells[PRISON_POSITION].origion_char[5] = PRISON_SHOW_CHAR;
    map->cells[PRISON_POSITION].kind = PARK;
    map->cells[PRISON_POSITION].rank = RANK0;
    map->cells[PRISON_POSITION].has_tool = 0;
    map->cells[PRISON_POSITION].owner = NO_ONE;

    // init tool house
    strncpy(map->cells[TOOL_HOUSE_POSITION].show_char, init_show_char, 5);
    map->cells[TOOL_HOUSE_POSITION].show_char[5] = TOOL_HOUSE_SHOW_CHAR;
    strncpy(map->cells[TOOL_HOUSE_POSITION].origion_char, init_show_char, 5);
    map->cells[TOOL_HOUSE_POSITION].origion_char[5] = TOOL_HOUSE_SHOW_CHAR;
    map->cells[TOOL_HOUSE_POSITION].kind = TOOL_HOUSE;
    map->cells[TOOL_HOUSE_POSITION].rank = RANK0;
    map->cells[TOOL_HOUSE_POSITION].has_tool = 0;
    map->cells[TOOL_HOUSE_POSITION].owner = NO_ONE;

    // init gift house
    strncpy(map->cells[GIFT_HOUSE_POSITION].show_char, init_show_char, 5);
    map->cells[GIFT_HOUSE_POSITION].show_char[5] = GIFT_HOUSE_SHOW_CHAR;
    strncpy(map->cells[GIFT_HOUSE_POSITION].origion_char, init_show_char, 5);
    map->cells[GIFT_HOUSE_POSITION].origion_char[5] = GIFT_HOUSE_SHOW_CHAR;
    map->cells[GIFT_HOUSE_POSITION].kind = GIFT_HOUSE;
    map->cells[GIFT_HOUSE_POSITION].rank = RANK0;
    map->cells[GIFT_HOUSE_POSITION].has_tool = 0;
    map->cells[GIFT_HOUSE_POSITION].owner = NO_ONE;

    // init magic house
    strncpy(map->cells[MAGIC_HOUSE_POSITION].show_char, init_show_char, 5);
    map->cells[MAGIC_HOUSE_POSITION].show_char[5] = PRISON_SHOW_CHAR;
    strncpy(map->cells[MAGIC_HOUSE_POSITION].origion_char, init_show_char, 5);
    map->cells[MAGIC_HOUSE_POSITION].origion_char[5] = PRISON_SHOW_CHAR;
    map->cells[MAGIC_HOUSE_POSITION].kind = PARK;
    map->cells[MAGIC_HOUSE_POSITION].rank = RANK0;
    map->cells[MAGIC_HOUSE_POSITION].has_tool = 0;
    map->cells[MAGIC_HOUSE_POSITION].owner = NO_ONE;

    // init blank places of rank1
    for(int i=RANK1_START_POSITION;i<=RANK1_END_POSITION;i++){
        if(i==HOSPITAL_POSITION)
            continue;
        strncpy(map->cells[i].show_char, init_show_char, 5);
        map->cells[i].show_char[5] = BLANK_SPACE_SHOW_CHAR;
        strncpy(map->cells[i].origion_char, init_show_char, 5);
        map->cells[i].origion_char[5] = BLANK_SPACE_SHOW_CHAR;
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK1;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = NO_ONE;
    }

    // init blank places of rank2
    for(int i=RANK2_START_POSITION;i<=RANK2_END_POSITION;i++){
        strncpy(map->cells[i].show_char, init_show_char, 5);
        map->cells[i].show_char[5] = BLANK_SPACE_SHOW_CHAR;
        strncpy(map->cells[i].origion_char, init_show_char, 5);
        map->cells[i].origion_char[5] = BLANK_SPACE_SHOW_CHAR;
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK2;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = NO_ONE;
    }

    // init blank places of rank3
    for(int i=RANK3_START_POSITION;i<=RANK3_END_POSITION;i++){
        if(i==PRISON_POSITION)
            continue;
        strncpy(map->cells[i].show_char, init_show_char, 5);
        map->cells[i].show_char[5] = BLANK_SPACE_SHOW_CHAR;
        strncpy(map->cells[i].origion_char, init_show_char, 5);
        map->cells[i].origion_char[5] = BLANK_SPACE_SHOW_CHAR;
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK3;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = NO_ONE;
    }

    // init gold space
    strncpy(map->cells[GOLD_SPACE_1_POSITION].show_char, init_show_char, 5);
    map->cells[GOLD_SPACE_1_POSITION].show_char[5] = GOLD_SPACE_SHOW_CHAR;
    strncpy(map->cells[GOLD_SPACE_1_POSITION].origion_char, init_show_char, 5);
    map->cells[GOLD_SPACE_1_POSITION].origion_char[5] = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_1_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_1_POSITION].rank = RANK0;
    map->cells[GOLD_SPACE_1_POSITION].has_tool = 0;
    map->cells[GOLD_SPACE_1_POSITION].owner = NO_ONE;
    strncpy(map->cells[GOLD_SPACE_2_POSITION].show_char, init_show_char, 5);
    map->cells[GOLD_SPACE_2_POSITION].show_char[5] = GOLD_SPACE_SHOW_CHAR;
    strncpy(map->cells[GOLD_SPACE_2_POSITION].origion_char, init_show_char, 5);
    map->cells[GOLD_SPACE_2_POSITION].origion_char[5] = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_2_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_2_POSITION].rank = RANK0;
    map->cells[GOLD_SPACE_2_POSITION].has_tool = 0;
    map->cells[GOLD_SPACE_2_POSITION].owner = NO_ONE;
    strncpy(map->cells[GOLD_SPACE_3_POSITION].show_char, init_show_char, 5);
    map->cells[GOLD_SPACE_3_POSITION].show_char[5] = GOLD_SPACE_SHOW_CHAR;
    strncpy(map->cells[GOLD_SPACE_3_POSITION].origion_char, init_show_char, 5);
    map->cells[GOLD_SPACE_3_POSITION].origion_char[5] = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_3_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_3_POSITION].rank = RANK0;
    map->cells[GOLD_SPACE_3_POSITION].has_tool = 0;
    map->cells[GOLD_SPACE_3_POSITION].owner = NO_ONE;
    strncpy(map->cells[GOLD_SPACE_4_POSITION].show_char, init_show_char, 5);
    map->cells[GOLD_SPACE_4_POSITION].show_char[5] = GOLD_SPACE_SHOW_CHAR;
    strncpy(map->cells[GOLD_SPACE_4_POSITION].origion_char, init_show_char, 5);
    map->cells[GOLD_SPACE_4_POSITION].origion_char[5] = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_4_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_4_POSITION].rank = RANK0;
    map->cells[GOLD_SPACE_4_POSITION].has_tool = 0;
    map->cells[GOLD_SPACE_4_POSITION].owner = NO_ONE;
    strncpy(map->cells[GOLD_SPACE_5_POSITION].show_char, init_show_char, 5);
    map->cells[GOLD_SPACE_5_POSITION].show_char[5] = GOLD_SPACE_SHOW_CHAR;
    strncpy(map->cells[GOLD_SPACE_5_POSITION].origion_char, init_show_char, 5);
    map->cells[GOLD_SPACE_5_POSITION].origion_char[5] = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_5_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_5_POSITION].rank = RANK0;
    map->cells[GOLD_SPACE_5_POSITION].has_tool = 0;
    map->cells[GOLD_SPACE_5_POSITION].owner = NO_ONE;
    strncpy(map->cells[GOLD_SPACE_6_POSITION].show_char, init_show_char, 5);
    map->cells[GOLD_SPACE_6_POSITION].show_char[5] = GOLD_SPACE_SHOW_CHAR;
    strncpy(map->cells[GOLD_SPACE_6_POSITION].origion_char, init_show_char, 5);
    map->cells[GOLD_SPACE_6_POSITION].origion_char[5] = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_6_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_6_POSITION].rank = RANK0;
    map->cells[GOLD_SPACE_6_POSITION].has_tool = 0;
    map->cells[GOLD_SPACE_6_POSITION].owner = NO_ONE;
}
