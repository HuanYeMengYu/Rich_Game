# include "utils.h"

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;

void init_player(Player *player, int number, int init_money){
    switch (number)
    {
    case QIANFUREN_NUMBER:
        player->number = QIANFUREN_NUMBER;
        player->alive = 0;
        player->money = init_money;
        player->point = 0;
        player->block = 0;
        player->bomb = 0;
        player->robot = 0;
        player->buff = 0;
        player->_continue = 0;
        player->prison = 0;
        player->hospital = 0;
        player->de_continue = 0;
        player->position = 0;
        // player->properties = NULL;
        player->property_count = 0;
        break;
    case ATUBO_NUMBER:
        player->number = 2;
        player->alive = 0;
        player->money = init_money;
        player->point = 0;
        player->block = 0;
        player->bomb = 0;
        player->robot = 0;
        player->buff = 0;
        player->_continue = 0;
        player->prison = 0;
        player->hospital = 0;
        player->de_continue = 0;
        player->position = 0;
        // player->properties = NULL;
        player->property_count = 0;
        break;
    case SUNXIAOMEI_NUMBER:
        player->number = 3;
        player->alive = 0;
        player->money = init_money;
        player->point = 0;
        player->block = 0;
        player->bomb = 0;
        player->robot = 0;
        player->buff = 0;
        player->_continue = 0;
        player->prison = 0;
        player->hospital = 0;
        player->de_continue = 0;
        player->position = 0;
        // player->properties = NULL;
        player->property_count = 0;
        break;
    case JINBEIBEI_NUMBER:
        player->number = 4;
        player->alive = 0;
        player->money = init_money;
        player->point = 0;
        player->block = 0;
        player->bomb = 0;
        player->robot = 0;
        player->buff = 0;
        player->_continue = 0;
        player->prison = 0;
        player->hospital = 0;
        player->de_continue = 0;
        player->position = 0;
        // player->properties = NULL;
        player->property_count = 0;
        break;
    default:
        break;
    }
}
