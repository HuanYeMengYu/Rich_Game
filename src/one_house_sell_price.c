# include "utils.h"

// 获取卖掉某个房屋的价格，该房屋总价 × 杠杆
int one_house_sell_price(int house_position){
    return one_house_total_price(house_position) * SELL_HOUSE_LEVEL;
}
