# include "utils.h"

void sort_player_number_arr(){
    for(int i=0;i<left_player_nums-1;i++){
        for(int j=i+1;j<left_player_nums;j++){
            if(player_number_arr[i] > player_number_arr[j]){
                int tmp = player_number_arr[i];
                player_number_arr[i] = player_number_arr[j];
                player_number_arr[j] = tmp;
            }
        }
    }
}
