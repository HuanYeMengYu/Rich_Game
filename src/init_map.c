# include "utils.h"

void init_map(Map *map){
    // init start cell
    strncpy(map->cells[START_POSITION].show_char,strcat("\033[31m",START_SHOW_CHAR),7);
    map->cells[START_POSITION].kind = START;
    map->cells[START_POSITION].owner = NO_ONE;

    // init hospital
    strcpy(map->cells[HOSPITAL_POSITION].show_char,strcat("\033[31m",HOSPITAL_SHOW_CHAR));
    map->cells[HOSPITAL_POSITION].kind = HOSPITAL;
    map->cells[HOSPITAL_POSITION].owner = NO_ONE;

    // init prison
    strcpy(map->cells[PRISON_POSITION].show_char,strcat("\033[37m",PRISON_SHOW_CHAR));
    map->cells[PRISON_POSITION].kind = PRISON;
    map->cells[PRISON_POSITION].owner = NO_ONE;

    // init tool house
    strcpy(map->cells[TOOL_HOUSE_POSITION].show_char,strcat("\033[37m",TOOL_HOUSE_SHOW_CHAR));
    map->cells[TOOL_HOUSE_POSITION].kind = TOOL_HOUSE;
    map->cells[TOOL_HOUSE_POSITION].owner = NO_ONE;

    // init gift house
    strcpy(map->cells[GIFT_HOUSE_POSITION].show_char,strcat("\033[37m",GIFT_HOUSE_SHOW_CHAR));
    map->cells[GIFT_HOUSE_POSITION].kind = GIFT_HOUSE;
    map->cells[GIFT_HOUSE_POSITION].owner = NO_ONE;

    // init magic house
    strcpy(map->cells[MAGIC_HOUSE_POSITION].show_char,strcat("\033[37m",MAGIC_HOUSE_SHOW_CHAR));
    map->cells[MAGIC_HOUSE_POSITION].kind = MAGIC_HOUSE;
    map->cells[MAGIC_HOUSE_POSITION].owner = NO_ONE;

    // init blank places of rank1
    for(int i=RANK1_START_POSITION;i<=RANK1_END_POSITION;i++){
        if(i==HOSPITAL_POSITION)
            continue;
        strcpy(map->cells[i].show_char,strcat("\033[37m",BLANK_SPACE_SHOW_CHAR));
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK1;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = NO_ONE;
    }

    // init blank places of rank2
    for(int i=RANK2_START_POSITION;i<=RANK2_END_POSITION;i++){
        strcpy(map->cells[i].show_char,strcat("\033[37m",BLANK_SPACE_SHOW_CHAR));
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK2;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = NO_ONE;
    }

    // init blank places of rank3
    for(int i=RANK3_START_POSITION;i<=RANK3_END_POSITION;i++){
        if(i==PRISON_POSITION)
            continue;
        strcpy(map->cells[i].show_char,strcat("\033[37m",BLANK_SPACE_SHOW_CHAR));
        map->cells[i].kind = BLANK_SPACE;
        map->cells[i].rank = RANK3;
        map->cells[i].has_tool = 0;
        map->cells[i].owner = NO_ONE;
    }

    // init gold space
    strcpy(map->cells[GOLD_SPACE_1_POSITION].show_char,strcat("\033[37m",GOLD_SPACE_SHOW_CHAR));
    map->cells[GOLD_SPACE_1_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_1_POSITION].owner = NO_ONE;
    strcpy(map->cells[GOLD_SPACE_2_POSITION].show_char,strcat("\033[37m",GOLD_SPACE_SHOW_CHAR));
    map->cells[GOLD_SPACE_2_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_2_POSITION].owner = NO_ONE;
    strcpy(map->cells[GOLD_SPACE_3_POSITION].show_char,strcat("\033[37m",GOLD_SPACE_SHOW_CHAR));
    map->cells[GOLD_SPACE_3_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_3_POSITION].owner = NO_ONE;
    strcpy(map->cells[GOLD_SPACE_4_POSITION].show_char,strcat("\033[37m",GOLD_SPACE_SHOW_CHAR));
    map->cells[GOLD_SPACE_4_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_4_POSITION].owner = NO_ONE;
    strcpy(map->cells[GOLD_SPACE_5_POSITION].show_char,strcat("\033[37m",GOLD_SPACE_SHOW_CHAR));
    map->cells[GOLD_SPACE_5_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_5_POSITION].owner = NO_ONE;
    strcpy(map->cells[GOLD_SPACE_6_POSITION].show_char,strcat("\033[37m",GOLD_SPACE_SHOW_CHAR));
    map->cells[GOLD_SPACE_6_POSITION].kind = GOLD_SPACE;
    map->cells[GOLD_SPACE_6_POSITION].owner = NO_ONE;
}
