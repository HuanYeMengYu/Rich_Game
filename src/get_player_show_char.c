#include "utils.h"

// 获取角色的打印字符
char get_player_show_char(int player_number){
    assert(player_number >= QIANFUREN_NUMBER && player_number <= JINBEIBEI_NUMBER);

    switch(player_number){
        case QIANFUREN_NUMBER:
            return QIANFUREN_SHOW_CHAR;
            break;
        case ATUBO_NUMBER:
            return ATUBO_SHOW_CHAR;
            break;
        case SUNXIAOMEI_NUMBER:
            return SUNXIAOMEI_SHOW_CHAR;
            break;
        case JINBEIBEI_NUMBER:
            return JINBEIBEI_SHOW_CHAR;
            break;
        default:
            return '\0';
            break;
    }
}
