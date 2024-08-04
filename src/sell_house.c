#include "utils.h"

// 0售卖失败，1售卖成功
int sell_house(Player *player, int place){
    int price[4]={0,RANK1_PRICE,RANK2_PRICE,RANK3_PRICE};
    if(place<0||place>70){
        printf("选择的地块不在地图上！\n");
        return 0;
    }
    if(map.cells[place].owner!=player->number){
        printf("该地块不属于你！\n");
        return 0;
    }else{
            // 产权数-1
            player->property_count--;
            // 计算出售价格
            int add = add = one_house_sell_price(place);
            // 改变产权属性
            player->properties[place] = DONT_HAVE;
            printf("位于%d处的房产售卖成功，资金增加%d，之前资金%d，当前资金%d\n",place,add,player->money,player->money+add);
            player->money += add;
            strncpy(map.cells[place].show_char, "\033[37m0", 7);
            map.cells[place].kind = BLANK_SPACE;
            return 1;
    }
}
