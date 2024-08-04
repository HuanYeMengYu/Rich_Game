# include "utils.h"

// return the pointer of the player by it's number, failed return NULL
Player* get_player(int player_number){
    switch(player_number){
        case QIANFUREN_NUMBER:
            return &QianFuren;
            break;
        case ATUBO_NUMBER:
            return &ATubo;
            break;
        case SUNXIAOMEI_NUMBER:
            return &SunXiaomei;
            break;
        case JINBEIBEI_NUMBER:
            return &JinBeibei;
            break;
        default:
            return NULL;
            break;
    }
}
