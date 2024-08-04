# include "utils.h"

const char* get_player_name(int player_number){
    switch (player_number)
    {
    case QIANFUREN_NUMBER:
        return QIANFUREN_NAME;
        break;
    case ATUBO_NUMBER:
        return ATUBO_NAME;
        break;
    case SUNXIAOMEI_NUMBER:
        return SUNXIAOMEI_NAME;
        break;
    case JINBEIBEI_NUMBER:
        return JINBEIBEI_NAME;
        break;
    default:
        return NULL;
        break;
    }
}
