# include "utils.h"

// 玩家破产，移除player_number_arr，重新排序
// left_player_nums--，player_index--
void player_exit_game(int Player_number){
    for(int i=0;i<left_player_nums;i++){
        if(player_number_arr[i] == Player_number){
            if(i != TOTAL_PLAYER_NUM-1){
                for(;i<TOTAL_PLAYER_NUM-1;i++){
                    player_number_arr[i] = player_number_arr[i+1];
                }
            }
            player_number_arr[TOTAL_PLAYER_NUM-1] = 0;
            left_player_nums--;
            player_index--;
            return;
        }
    }
}
