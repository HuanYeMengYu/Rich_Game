# include "utils.h"

void gift_hosue(Player *player){
    printf("欢迎光临礼品物，请选择一件您喜欢的礼品:\n");
    int gift_number = 0;
    scanf("%d", &gift_number);
    if(gift_number != BONUS_NUMBER && gift_number != POINT_CARD && gift_number != GOD_OF_WEALTH){
        printf("输入错误，放弃此次机会！\n");
        return;
    }
    switch (gift_number){
    case BONUS_NUMBER:
        printf("您获得2000元奖金！\n");
        player->money += 2000;
        break;
    case POINT_CARD:
        printf("您获得200点的点数卡！\n");
        player->point += 200;
        break;
    case GOD_OF_WEALTH:
        printf("您获得财神buff！5轮内有效\n");
        player->buff = true;
        break;
    }
}
