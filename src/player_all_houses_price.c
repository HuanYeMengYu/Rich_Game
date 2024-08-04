# include "utils.h"

// 获取一个玩家所有房产的总投入价格
int player_all_houses_price(Player *player){
    int total_house_price = 0;
    for(int i=START_POSITION;i<CELL_NUMS;i++){
        if(player->properties[i] != -1){
            total_house_price += one_house_total_price(i);
        }
    }
    return total_house_price;
}
