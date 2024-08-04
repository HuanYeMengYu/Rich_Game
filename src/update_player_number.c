# include "utils.h"

// 每掷一次骰子，更新全局变量player_number
void update_player_number(){
    // 游戏结束，直接退出
    if(left_player_nums == 1){
        player_number = player_number_arr[0];
        return;
    }

    if(player_index == left_player_nums - 1){
        player_index = 0;
        GameGodComing();
        cur_round++;
    }else{
        player_index++;
    }
    player_number = player_number_arr[player_index];
}
