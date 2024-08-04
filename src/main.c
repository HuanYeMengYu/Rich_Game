# include "utils.h"

// 玩家编号
int player_number = 1;
// 按顺序当前是第几个玩家的回合，从0开始
int player_index = 0;
// 剩余的玩家数量
int left_player_nums = 0;
// 参与游戏的玩家编号数组
int player_number_arr[TOTAL_PLAYER_NUM] = {0};

int main(int argc,char *argv[]){
    // 种下时间随机种子
    srand(time(0));
    if(argc==2)
    {
        char txt_filepath[256];
        char json_filepath[256];
        snprintf(txt_filepath, sizeof(txt_filepath), "%s\\expected_output.txt",argv[1]);
        // FILE *file;
        // if ((file = fopen(txt_filepath, "r"))) {
        //     printf("已存在%s\n",txt_filepath);
        //     fclose(file);
        // }
        // else{
            snprintf(json_filepath, sizeof(json_filepath), "%s\\expected_output.json",argv[1]);
            json_to_txt(json_filepath, txt_filepath);
        // }
        char file_path[256];
        // const char *folder = "test";
        snprintf(file_path, sizeof(file_path), "%s\\user.json",argv[1]);
        read_json(file_path);
        // read_json(argv[1]);
    }
    // 开始游戏
    begin_game();
    // 初始化地图
    if(argc!=2) 
    {
        init_map(&map);
        getchar();
    }

    int command_return_number;
    char command[20] = {'\0'};
    char result[20] = {'\0'};

    // 开局先让第一个角色走在起点，保证起点一开始就显示角色符号
    move(get_player(player_number_arr[0]), 0);
    display_map(&map);

    // 财神在10-17轮内降临
    //god_incoming_round = rand()%10 + 10;
    god_incoming_round = rand()%8 + 10;
    printf("财神爷还有%d回合降临\n", god_incoming_round);

    // 角色循环
    while(1){
        // 财神buff递减
        if(player_number == QIANFUREN_NUMBER && QianFuren.buff == 1){
            QianFuren._continue--;
            if(QianFuren._continue == 0){
                QianFuren.buff = 0;
                printf("你的财神已结束\n");
            }else{
                printf("你的财神还有%d轮\n", QianFuren._continue);
            }
        }
        if(player_number == ATUBO_NUMBER && ATubo.buff == 1){
            ATubo._continue--;
            if(ATubo._continue == 0){
                ATubo.buff = 0;
                printf("你的财神已结束\n");
            }else{
                printf("你的财神还有%d轮\n", ATubo._continue);
            }
        }
        if(player_number == SUNXIAOMEI_NUMBER && SunXiaomei.buff == 1){
            SunXiaomei._continue--;
            if(SunXiaomei._continue == 0){
                SunXiaomei.buff = 0;
                printf("你的财神已结束\n");
            }else{
                printf("你的财神还有%d轮\n", SunXiaomei._continue);
            }
        }
        if(player_number == JINBEIBEI_NUMBER && JinBeibei.buff == 1){
            JinBeibei._continue--;
            if(JinBeibei._continue == 0){
                JinBeibei.buff = 0;
                printf("你的财神已结束\n");
            }else{
                printf("你的财神还有%d轮\n", JinBeibei._continue);
            }
        }

        // // 玩家是否在监狱
        // if(player_number == QIANFUREN_NUMBER && QianFuren.prison==1){            
        //     printf("钱夫人还要在监狱待%d轮，下个玩家自动开始\n", QianFuren.de_continue);
            
        //     // 切换玩家部分
        //     update_player_number();

        //     QianFuren.de_continue--;
        //     if(QianFuren.de_continue == 0){
        //         QianFuren.prison = 0;
        //     }
        // }
        // if(player_number == ATUBO_NUMBER && ATubo.prison==1){
        //     printf("阿土伯还要在监狱待%d轮，下个玩家自动开始\n", ATubo.de_continue);

        //     // 切换玩家部分
        //     update_player_number();

        //     ATubo.de_continue--;
        //     if(ATubo.de_continue == 0){
        //         ATubo.prison = 0;
        //     }
        // }
        // if(player_number == SUNXIAOMEI_NUMBER && SunXiaomei.prison==1){
        //     printf("孙小美还要在监狱待%d轮，下个玩家自动开始\n", SunXiaomei.de_continue);

        //     // 切换玩家部分
        //     update_player_number();

        //     SunXiaomei.de_continue--;
        //     if(SunXiaomei.de_continue == 0){
        //         SunXiaomei.prison = 0;
        //     }
        // }
        // if(player_number == JINBEIBEI_NUMBER && JinBeibei.prison==1){
        //     printf("金贝贝还要在监狱待%d轮，下个玩家自动开始\n", JinBeibei.de_continue);

        //     // 切换玩家部分
        //     update_player_number();
        //     JinBeibei.de_continue--;
        //     if(JinBeibei.de_continue == 0){
        //         JinBeibei.prison = 0;
        //     }
        // }

        // // 玩家是否在医院里
        // if(player_number == QIANFUREN_NUMBER && QianFuren.hospital==1){
        //     printf("钱夫人还要在医院待%d轮，下个玩家自动开始\n", QianFuren.de_continue);
            
        //     // 切换玩家部分
        //     update_player_number();

        //     QianFuren.de_continue--;
        //     if(QianFuren.de_continue == 0){
        //         QianFuren.hospital = 0;
        //     }
        // }
        // if(player_number == ATUBO_NUMBER && ATubo.hospital==1){
        //     printf("阿土伯还要在医院待%d轮，下个玩家自动开始\n", ATubo.de_continue);
            
        //     // 切换玩家部分
        //     update_player_number();

        //     ATubo.de_continue--;
        //     if(ATubo.de_continue == 0){
        //         ATubo.hospital = 0;
        //     }
        // }
        // if(player_number == SUNXIAOMEI_NUMBER && SunXiaomei.hospital==1){
        //     printf("孙小美还要在医院待%d轮，下个玩家自动开始\n", SunXiaomei.de_continue);
            
        //     // 切换玩家部分
        //     update_player_number();

        //     SunXiaomei.de_continue--;
        //     if(SunXiaomei.de_continue == 0){
        //         SunXiaomei.hospital = 0;
        //     }
        // }
        // if(player_number == JINBEIBEI_NUMBER && JinBeibei.hospital==1){
        //     printf("金贝贝还要在医院待%d轮，下个玩家自动开始\n", JinBeibei.de_continue);
            
        //     // 切换玩家部分
        //     update_player_number();

        //     JinBeibei.de_continue--;
        //     if(JinBeibei.de_continue == 0){
        //         JinBeibei.hospital = 0;
        //     }
        // }

        // 指令循环，不用roll命令无限循环
        while(1){
            switch (player_number)
            {
            case QIANFUREN_NUMBER:
                printf("\033[31m钱夫人>\033[37m");

                break;
            case ATUBO_NUMBER:
                printf("\033[32m阿土伯>\033[37m");

                break;
            case SUNXIAOMEI_NUMBER:
                printf("\033[34m孙小美>\033[37m");

                break;
            case JINBEIBEI_NUMBER:
                printf("\033[33m金贝贝>\033[37m");

                break;
            default:
                break;
            }

            // 获取命令
            memset(command, 0, 20);
            memset(result, 0, 20);
            //gets(command);
            fgets(command, sizeof(command), stdin);
            command[strcspn(command, "\n")] = 0; 
            // scanf("%s", command);
            command_return_number = Get_instruction(command,result);
            //command_return_number = Get_instruction(command);

            // quit
            if(command_return_number == 2){
                if(argc==2)
                {
                    now_user[0] = player_number + '0';
                    int len=strlen(users);
                    for(int j=0;j<len;j++)
                    {
                        switch(users[j])
                        {
                            case '1':
                                use_players[j]=QianFuren;
                                break;
                            case '2':
                                use_players[j]=ATubo;
                                break;
                            case '3':
                                use_players[j]=SunXiaomei;
                                break;
                            case '4':
                                use_players[j]=JinBeibei;
                                break;
                        }
                    }
                    write_json(argv[1], use_players, &map, users, now_user);
                    char json_filepath[256];
                    char txt_filepath[256];
                    snprintf(json_filepath, sizeof(json_filepath), "%s\\output.json",argv[1]);
                    snprintf(txt_filepath, sizeof(txt_filepath), "%s\\output.txt",argv[1]);
                    json_to_txt(json_filepath, txt_filepath);
                }
                printf("退出游戏\n");
                return 0;
            }
            // roll
            if(command_return_number == 1){
                break;
            }
            // step
            if(command_return_number == 3){
                break;
            }
            // block
            if(command_return_number == 4){
                Block(get_player(player_number),atoi(result));
                display_map(&map);
                
            }
            // bomb
            if(command_return_number == 5){
                Bomb(get_player(player_number),atoi(result));
                display_map(&map);
            }
            // robot
            if(command_return_number == 6){
                printf("调用Robot函数\n");
                Robot(get_player(player_number));
                display_map(&map);
            }
        }

        int step = 0;
        // 掷骰子部分
        if(command_return_number == 1){
            step = get_step_count();
        }else if(command_return_number == 3){   // step
            step = atoi(result);
        }
        int does_tool_trigger;
        switch (player_number)
        {
        case QIANFUREN_NUMBER:
            // 未触发道具
            does_tool_trigger = tool_trigger(&QianFuren,step);
            if(does_tool_trigger == 0){
                move(&QianFuren, step);
                display_map(&map);
                BuyAndRent(&QianFuren);
                tool_hosue(&QianFuren);
                gift_house(&QianFuren);
                //magic_hosue(&QianFuren);
                //goto_prison(&QianFuren);
                get_gold(&QianFuren);
            }else{  //触发道具
                if(does_tool_trigger == 1){
                    display_map(&map);
                    BuyAndRent(&QianFuren);
                }
                display_map(&map);
            }
            break;
        case ATUBO_NUMBER:
            // 未触发道具
            does_tool_trigger = tool_trigger(&ATubo,step);
            if(does_tool_trigger == 0){
                move(&ATubo, step);
                display_map(&map);
                BuyAndRent(&ATubo);
                tool_hosue(&ATubo);
                gift_house(&ATubo);
                //magic_hosue(&ATubo);
                //goto_prison(&ATubo);
                get_gold(&ATubo);
            }else{  //触发道具
                if(does_tool_trigger == 1){
                    display_map(&map);
                    BuyAndRent(&ATubo);
                }
                display_map(&map);
            }
            break;
        case SUNXIAOMEI_NUMBER:
            // 未触发道具
            does_tool_trigger = tool_trigger(&SunXiaomei,step);
            if(does_tool_trigger == 0){
                move(&SunXiaomei, step);
                display_map(&map);
                BuyAndRent(&SunXiaomei);
                tool_hosue(&SunXiaomei);
                gift_house(&SunXiaomei);
                //magic_hosue(&SunXiaomei);
                //goto_prison(&SunXiaomei);
                get_gold(&SunXiaomei);
            }else{  //触发道具
                if(does_tool_trigger == 1){
                    display_map(&map);
                    BuyAndRent(&SunXiaomei);
                }
                display_map(&map);
            }
            break;
        case JINBEIBEI_NUMBER:
            // 未触发道具
            does_tool_trigger = tool_trigger(&JinBeibei,step);
            if(does_tool_trigger == 0){
                move(&JinBeibei, step);
                display_map(&map);
                BuyAndRent(&JinBeibei);
                tool_hosue(&JinBeibei);
                gift_house(&JinBeibei);
                //magic_hosue(&JinBeibei);
                //goto_prison(&JinBeibei);
                get_gold(&JinBeibei);
            }else{  //触发道具
                if(does_tool_trigger == 1){
                    display_map(&map);
                    BuyAndRent(&JinBeibei);
                }
                display_map(&map);
            }
            break;
        default:
            break;
        }
        display_map(&map);

        // 切换玩家部分
        update_player_number();

        // 游戏结束了吗
        if(game_over()){
            return 0;
        }
    }
    return 0;
}
