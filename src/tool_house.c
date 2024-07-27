# include "utils.h"

void tool_hosue(Player *player){
    if(player->point < MIN_TOOL_POINT){
        printf("玩家点数不足以买点数最少的道具，自动退出道具屋\n");
        return;
    }

    char ch;
    while (1) {
        // if player has more than 10 tools , exit
        if((player->block + player->bomb + player->robot) > TOOL_MAX_NUMS){
            printf("玩家已经拥有%d个道具，自动退出道具屋\n", TOOL_MAX_NUMS);
            return;
        }

        ch = getchar();
        switch (ch)
        {
        case TOOL_HOUSE_EXIT_PRESS_KEY_1:
            return;
            break;
        case TOOL_HOUSE_EXIT_PRESS_KEY_2:
            return;
            break;
        case BUY_BLOCK_PRESS_KEY:
            printf("成功购买路障\n");
            player->block++;
            break;
        case BUY_ROBOT_PRESS_KEY:
            printf("成功购买机器娃娃\n");
            player->robot++;
            break;
        case BUY_BOMB_PRESS_KEY:
            printf("成功购买炸弹\n");
            player->bomb++;
            break;
        default:
            printf("输入无效，请重新输入\n");
            break;
        }
    }
}
