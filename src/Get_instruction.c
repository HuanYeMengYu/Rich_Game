# include "utils.h"

int Get_instruction(char* keyboard_input, char *result){
    // int c;
    // while ((c = getchar()) != '\n' && c != EOF) {}

    //小写转换
   char* temp=keyboard_input;
    while(*temp){
        *keyboard_input=tolower(*keyboard_input);
        temp++;
    }
    char* command = strtok(keyboard_input, " \t\n");
    char* argument = strtok(NULL," \t\n");

    if (strcmp(command, "roll") == 0){

        display_map(&map);//刷新地图的函数
        return 1;
    }else if (strcmp(command, "query") == 0){
        Show_Assets(get_player(player_number));//等到显示自家资产的函数
        return 0;
    }else if (strcmp(command, "help") == 0){
        Print_Help();
        printf("Executing Help command\n");//等待查看命令的函数
        return 0;
    }else if (strcmp(command, "quit") == 0||strcmp(command, "dump") == 0) {
        printf("Executing Quit command\n");//等待强制退出的函数
        display_map(&map);//刷新地图的函数
        return 2;
    }else if (strcmp(command, "sell") == 0){//以下需要根据后面的数字进行操作
                                             //等待售卖的函数
        printf("Executing Sell command\n");
        int sell_position = atoi(argument);
        switch (player_number)
        {
        case QIANFUREN_NUMBER:
            sell_house(&QianFuren, sell_position);
            break;
        case ATUBO_NUMBER:
            sell_house(&ATubo, sell_position);
            break;
        case SUNXIAOMEI_NUMBER:
            sell_house(&SunXiaomei, sell_position);
            break;
        case JINBEIBEI_NUMBER:
            sell_house(&JinBeibei, sell_position);
            break;
        default:
            break;
        }
        display_map(&map);//刷新地图的函数
        return 0;
    }else if (strcmp(command, "step") == 0){
        if(!argument){
            printf("step指令需要指定步数，请重新输入\n");
            return 0;
        }
        strcpy(result,argument);
        printf("Executing Step command\n");//等待遥控骰子的函数、刷新地图、刷新人物位置的函数
        display_map(&map);//刷新地图的函数
        return 3;
    }else if (strcmp(command, "position") == 0){
        if(strcmp(argument,PLAYER1_KEY_WORD) == 0){
            if(QianFuren.alive == 0){
                printf("钱夫人不在游戏中！\n");
            }else{
                printf("钱夫人的位置为%d\n", QianFuren.position);
            }
        }else if(strcmp(argument,PLAYER2_KEY_WORD) == 0){
            if(ATubo.alive == 0){
                printf("阿土伯不在游戏中！\n");
            }else{
                printf("阿土伯的位置为%d\n", ATubo.position);
            }
        }else if(strcmp(argument,PLAYER3_KEY_WORD) == 0){
            if(SunXiaomei.alive == 0){
                printf("孙小美不在游戏中！\n");
            }else{
                printf("孙小美的位置为%d\n", SunXiaomei.position);
            }
        }else if(strcmp(argument,PLAYER4_KEY_WORD) == 0){
            if(JinBeibei.alive == 0){
                printf("金贝贝不在游戏中！\n");
            }else{
                printf("金贝贝的位置为%d\n", JinBeibei.position);
            }
        }
        // else if(strcmp(argument,PRISION_KEY_WORD) == 0){
        //     printf("监狱的位置为%d\n", (int)PRISON_POSITION);
        // }
        // else if(strcmp(argument,HOSPITAL_KEY_WORD) == 0){
        //     printf("医院的位置为%d\n", HOSPITAL_POSITION);
        // }
        else if(strcmp(argument,TOOL_HOUSE_KEY_WORD) == 0){
            printf("道具屋的位置为%d\n", TOOL_HOUSE_POSITION);
        }else if(strcmp(argument,GIFT_HOSUE_KEY_WORD) == 0){
            printf("礼品屋的位置为%d\n", GIFT_HOUSE_POSITION);
        }
        // else if(strcmp(argument,MAGIC_HOUSE_KEY_WORD) == 0){
        //     printf("魔法屋的位置为%d\n", MAGIC_HOUSE_POSITION);
        // }
        else if(strcmp(argument,MINES_KEY_WORD) == 0){
            printf("矿地的位置为%d~%d\n", GOLD_SPACE_1_POSITION, GOLD_SPACE_6_POSITION);
        }else if(strcmp(argument,BLOCK_KEY_WORD) == 0){
            // 先判断地图上有没有路障
            if(map_has_block()){
                printf("路障的位置为：");
                for(int i=START_POSITION;i<CELL_NUMS;i++){
                    if(map.cells[i].has_tool == BLOCK){
                        printf("%d,", i);
                    }
                }
                printf("\n");
            }else{
                printf("地图上没有路障！\n");
            }
        }
        // else if(strcmp(argument,BOMB_KEY_WORD) == 0){
        //     // 先判断地图上有没有炸弹
        //     if(map_has_bomb()){
        //         printf("炸弹的位置为：");
        //         for(int i=START_POSITION;i<CELL_NUMS;i++){
        //             if(map.cells[i].has_tool == BOMB){
        //                 printf("%d,", i);
        //             }
        //         }
        //         printf("\n");
        //     }else{
        //         printf("地图上没有炸弹！\n");
        //     }
        // }
        return 0;
    }else if (strcmp(command, "mines") == 0){
        printf("矿地64：点数%d\n", GOLD_SPACE_1_POINT);
        printf("矿地65：点数%d\n", GOLD_SPACE_2_POINT);
        printf("矿地66：点数%d\n", GOLD_SPACE_3_POINT);
        printf("矿地67：点数%d\n", GOLD_SPACE_4_POINT);
        printf("矿地68：点数%d\n", GOLD_SPACE_5_POINT);
        printf("矿地69：点数%d\n", GOLD_SPACE_6_POINT);
    }else if(strcmp(command, "block") == 0){
        strcpy(result,argument);
        return 4;
    }
    // else if(strcmp(command, "bomb") == 0){
    //     strcpy(result,argument);
    //     return 5;
    // }
    else if(strcmp(command, "robot") == 0){
        return 6;
    }
    else{
        printf("Unknown command\n");
        return 0;
    }
}
