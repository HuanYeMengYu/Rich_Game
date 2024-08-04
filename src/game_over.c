# include "utils.h"

bool game_over(){
    if(left_player_nums == 1){
        printf("游戏结束，%s获胜\n", get_player_name(player_number));
        return true;
    }else{
        return false;
    }
}
