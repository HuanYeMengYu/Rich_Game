# include "utils.h"

void Show_Assets(Player *player){
    printf("你拥有的金额为：%d\n",player->money);
    printf("你拥有的点数为：%d\n",player->point);
    if(player->property_count != 0){
        int total_house_num = 0;
        int total_blank_num = 0;
        int total_house1_num = 0;
        int total_house2_num = 0;
        int total_house3_num = 0;

        printf("你拥有的房产如下（0级代表拥有空地）：\n");
        int print_count = 0;
        int print_total_count = 1;
        for(int i=START_POSITION;i<CELL_NUMS;i++){
            if(player->properties[i]!=-1){
                // 计算各级房产数量
                if(map.cells[i].kind == 0){
                    total_blank_num++;
                    total_house_num++;
                }else if(map.cells[i].kind == 1){
                    total_house1_num++;
                    total_house_num++;
                }else if(map.cells[i].kind == 2){
                    total_house2_num++;
                    total_house_num++;
                }else if(map.cells[i].kind == 3){
                    total_house3_num++;
                    total_house_num++;
                }

                if(print_count == 9 || print_total_count == player->property_count){
                    printf("%d:%d级", i, player->properties[i]);
                }else{
                    printf("%d:%d级,", i, player->properties[i]);
                }
                print_count++;
                print_total_count++;
            }
            if(print_count == 10){
                print_count = 0;
                printf("\n");
            }
        }
        printf("\n");
        printf("你的总房产数：%d，空地数：%d，茅屋数：%d，洋房数：%d，摩天楼数：%d\n", 
            total_house_num, 
            total_blank_num, 
            total_house1_num, 
            total_house2_num, 
            total_house3_num
        );
        printf("你的房产总投入价格为%d元，", player_all_houses_price(player));
        printf("全部卖掉可以获得%d元\n", player_sell_all_houses_price(player));
    }
    if(player->block + player->bomb + player->robot != 0){
        printf("你拥有的道具如下:\n");
        if(player->block != 0){
            printf("%d个路障\n", player->block);
        }
        // if(player->bomb != 0){
        //     printf("%d个炸弹\n", player->bomb);
        // }
        if(player->robot != 0){
            printf("%d个机器娃娃\n", player->robot);
        }
    }
    if(player->buff == 1){
        printf("你的财神还有%d轮\n", player->_continue);
    }
    // if(player->prison == 1){
    //     printf("你还要在监狱待%d轮\n", player->de_continue);
    // }
    // else if(player->hospital == 1){
    //     printf("你还要在医院待%d轮\n", player->de_continue);
    // }
}
