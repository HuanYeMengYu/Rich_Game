# include "utils.h"

void gift_house(Player *player){
    if(player->position != GIFT_HOUSE_POSITION){
        return;
    }
    while (1)
    {
        /* code */
    
    
        char ch[40] = {'\0'};   // 获取道具编号
        //printf("欢迎光临礼品物，请选择一件您喜欢的礼品: 1.2000元奖金 2.200点点数卡 3.财神\n");
        printf("欢迎光临礼品物，请选择一件您喜欢的礼品: 1.2000元奖金 2.200点点数卡\n");
    
        fgets(ch, 40, stdin);
        if(ch[2] != '\0'){
            printf("输入长度不符合规范，请重新输入\n");
            continue;
        }

        int gift_number = ch[0]-'0';
        //if(gift_number != BONUS_NUMBER && gift_number != POINT_CARD && gift_number != GOD_OF_WEALTH)
        if(gift_number != BONUS_NUMBER && gift_number != POINT_CARD){
            printf("输入错误，放弃此次机会！\n");
            return;
        }
        switch (gift_number){
            case BONUS_NUMBER:
                printf("您获得2000元奖金！\n");
                player->money += 2000;
                return;
            case POINT_CARD:
                printf("您获得200点的点数卡！\n");
                player->point += 200;
                return;
            // case GOD_OF_WEALTH:
            //     printf("您获得财神buff！5轮内有效\n");
            //     player->buff = 1;
            //     player->_continue = 5;
            //     break;
            default:
                    break;
        }
    }
}
