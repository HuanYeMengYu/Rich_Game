# include "utils.h"

// 获取一个玩家卖掉所有房产的总价格
int player_sell_all_houses_price(Player *player){
    return player_all_houses_price(player) * SELL_HOUSE_LEVEL;
}
