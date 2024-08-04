# include "utils.h"

void move(Player *player, int step){
    // 修改原cell显示
    char temp[7] = {'\0'};
    if(QianFuren.position == player->position && QianFuren.number!=player->number){
        strncpy(temp, "\033[31m", 5);
        temp[5] = 'Q';
        strncpy(map.cells[player->position].show_char, temp, 6);
        
    }else if(ATubo.position == player->position && ATubo.number!=player->number){
        strncpy(temp, "\033[32m", 5);
        temp[5] = 'A';
        strncpy(map.cells[player->position].show_char, temp, 6);
        //  strncpy(map.cells[player->position].show_char, map.cells[player->position].origion_char, 6);
    }else if(SunXiaomei.position == player->position && SunXiaomei.number!=player->number){
        strncpy(temp, "\033[34m", 5);
        temp[5] = 'S';
        strncpy(map.cells[player->position].show_char, temp, 6);
        //  strncpy(map.cells[player->position].show_char, map.cells[player->position].origion_char, 6);
    }else if(JinBeibei.position == player->position && JinBeibei.number!=player->number){
        strncpy(temp, "\033[33m", 5);
        temp[5] = 'J';
        strncpy(map.cells[player->position].show_char, temp, 6);
        // strncpy(map.cells[player->position].show_char, map.cells[player->position].origion_char, 6);
    }else{
        // origin_char赋值给show_char，用来显示次房产被该玩家拥有
        // 需要在买房、升级处更新origin_char
        strncpy(map.cells[player->position].show_char, map.cells[player->position].origion_char, 6);
    }

   
    // 路障？炸弹？监狱？
    player->position = (player->position + step) % CELL_NUMS;

    // 目标cell修改显示
    switch (player->number)
    {
    case QIANFUREN_NUMBER:
        strncpy(map.cells[player->position].show_char, "\033[31mQ", 7);
        break;
    case ATUBO_NUMBER:
        strncpy(map.cells[player->position].show_char, "\033[32mA", 7);
        break;
    case SUNXIAOMEI_NUMBER:
        strncpy(map.cells[player->position].show_char, "\033[34mS", 7);
        break;
    case JINBEIBEI_NUMBER:
        strncpy(map.cells[player->position].show_char, "\033[33mJ", 7);
        break;
    default:
        break;
    }
}
