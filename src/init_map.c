# include "utils.h"

void init_map(Map *map){
    // init start cell
    map->cells[START_POSITION].show_char = START_SHOW_CHAR;
    map->cells[START_POSITION].kind = START;
    
    // init hospital
    map->cells[HOSPITAL_POSITION].show_char = HOSPITAL_SHOW_CHAR;
    map->cells[HOSPITAL_POSITION].kind = HOSPITAL;

    // init prison
    map->cells[PRISON_POSITION].show_char = PRISON_SHOW_CHAR;
    map->cells[PRISON_POSITION].kind = PRISON;

    // init tool house
    map->cells[TOOL_HOUSE_POSITION].show_char = TOOL_HOUSE_SHOW_CHAR;
    map->cells[TOOL_HOUSE_POSITION].kind = TOOL_HOUSE;

    // init gift house
    map->cells[GIFT_HOUSE_POSITION].show_char = GIFT_HOUSE_SHOW_CHAR;
    map->cells[GIFT_HOUSE_POSITION].kind = GIFT_HOUSE;

    // init magic house
    map->cells[MAGIC_HOUSE_POSITION].show_char = MAGIC_HOUSE_SHOW_CHAR;
    map->cells[MAGIC_HOUSE_POSITION].kind = MAGIC_HOUSE;

    // init blank places of rank1
    for(int i=RANK1_START_POSITION;i<=RANK1_END_POSITION;i++){
        if(i==HOSPITAL_POSITION)
            continue;
        map->cells[i].show_char = BLANK_SPACE_SHOW_CHAR;
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK1;
        map->cells[i].has_tool = 0;
    }

    // init blank places of rank2
    for(int i=RANK2_START_POSITION;i<=RANK2_END_POSITION;i++){
        map->cells[i].show_char = BLANK_SPACE_SHOW_CHAR;
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK2;
        map->cells[i].has_tool = 0;
    }

    // init blank places of rank3
    for(int i=RANK3_START_POSITION;i<=RANK3_END_POSITION;i++){
        if(i==PRISON_POSITION)
            continue;
        map->cells[i].show_char = BLANK_SPACE_SHOW_CHAR;
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK3;
        map->cells[i].has_tool = 0;
    }

    // init gold space
    map->cells[GOLD_SPACE_1_POSITION].show_char = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_1_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_2_POSITION].show_char = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_2_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_3_POSITION].show_char = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_3_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_4_POSITION].show_char = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_4_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_5_POSITION].show_char = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_5_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_6_POSITION].show_char = GOLD_SPACE_SHOW_CHAR;
    map->cells[GOLD_SPACE_6_POSITION].kind = GOLD_SPACE;
}
