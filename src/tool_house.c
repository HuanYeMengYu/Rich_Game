# include "utils.h"

void tool_hosue(Player *player){
    // 当前位置不是道具屋，直接退出
    if(player->position != TOOL_HOUSE_POSITION){
        return;
    }

    char ch[40] = {'\0'};   // 获取道具编号
    while (1) {
        // 剩下的点数不足以买点数最少的道具，自动退出道具屋
        if(player->point < MIN_TOOL_POINT){
            printf("玩家点数不足以买点数最少的道具，自动退出道具屋\n");
            return;
        }

        // 玩家已经拥有最大数量道具，自动退出道具屋
        if((player->block + player->bomb + player->robot) >= MAX_TOOL_NUMS){
            printf("玩家已经拥有%d个道具，自动退出道具屋\n", MAX_TOOL_NUMS);
            return;
        }

        //printf("欢迎光临道具屋，请选择您所需要的道具：1.路障 2.机器娃娃 3.炸弹\n");
        printf("欢迎光临道具屋，请选择您所需要的道具：1.路障 2.机器娃娃\n");

        fgets(ch, 40, stdin);
        if(ch[2] != '\0'){
            printf("输入长度不符合规范，请重新输入\n");
            continue;
        }

        switch (ch[0])
        {
        case TOOL_HOUSE_EXIT_PRESS_KEY_1:
            printf("退出道具屋\n");
            return;
            break;
        case TOOL_HOUSE_EXIT_PRESS_KEY_2:
            printf("退出道具屋\n");
            return;
            break;
        case BUY_BLOCK_PRESS_KEY:
            if(player->point < BLOCK_POINT){
                printf("点数不够买路障\n");
                break;
            }
            player->block++;
            printf("成功购买路障，你当前有%d个路障\n", player->block);
            player->point -= BLOCK_POINT;
            break;
        case BUY_ROBOT_PRESS_KEY:
            if(player->point < ROBOT_POINT){
                printf("点数不够买机器娃娃\n");
                break;
            }
            player->robot++;
            printf("成功购买机器娃娃，你当前有%d个机器娃娃\n", player->robot);
            player->point -= ROBOT_POINT;
            break;
        // case BUY_BOMB_PRESS_KEY:
        //     if(player->point < BOMB_POINT){
        //         printf("点数不够买炸弹\n");
        //     }
        //     player->bomb++;
        //     printf("成功购买炸弹，你当前有%d个炸弹\n", player->bomb);
        //     player->point -= BOMB_POINT;
        //     break;
        default:
            printf("输入无效，请重新输入\n");
            break;
        }
    }
}
