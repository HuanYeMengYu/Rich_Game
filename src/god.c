# include "utils.h"

// 财神爷还有几回合降临
int god_incoming_round;
// 财神爷效果还剩下几轮
int cur_god_round;

void GameGodComing() {
    static int pos2;

    // 财神爷不存在，但是还不可以降临
    if (god_incoming_round > 0) {
        printf("财神爷还有%d回合降临\n", god_incoming_round);
        god_incoming_round--;
        return;
    }
    // 财神不存在，并且已经可以开始随机降临
    else if(god_incoming_round == 0&&cur_god_round==0){
        int pos;
        srand(time(NULL));
        while(1){
            pos = rand() % 70;
            // 判断随机生成的位置上是否有玩家存在
            int has_player = 0;
            if(QianFuren.position == pos){
                has_player = 1;
            }else if(ATubo.position == pos){
                has_player = 1;
            }else if(SunXiaomei.position == pos){
                has_player = 1;
            }else if(JinBeibei.position == pos){
                has_player = 1;
            }
            // 随机生成位置上有道具或玩家，则重新生成随机位置
            if(map.cells[pos].has_tool == 0 && has_player==0){
                // 随机生成位置上是特殊建筑，则重新生成随机位置
                if(map.cells[pos].kind != GIFT_HOUSE && map.cells[pos].kind != TOOL_HOUSE && map.cells[pos].kind != PARK){
                    map.cells[pos].has_tool = BOMB;

                    cur_god_round = 5 ; // 如果财神出现就应该重置当前财神在地图上的保留轮数
                    printf("财神降临于%d,还将持续%d玩家回合!\n",pos,cur_god_round);
                    pos2 = pos;
                    strncpy(map.cells[pos].origion_char, map.cells[pos].show_char, 7);
                    strncpy(map.cells[pos].show_char, "\033[37mF", 7);
                    display_map(&map);
                    break;
                }
                else {
                    continue;
                }
            }
            else{
                continue;
            }
        }
        return;
    }
    // 财神效果递减，如果消失，则重新生成随机数，10~17回合后再次降临
    else if(cur_god_round>0){
        cur_god_round--;
        if(cur_god_round==0){
            //重新赋值一个10以内的整数
            printf("财神消失\n");

            map.cells[pos2].has_tool = 0;
            
            srand((unsigned) time(NULL));
            god_incoming_round = rand() % 8 + 10;
            //god_incoming_round = rand()%3 + 5;
            strncpy(map.cells[pos2].show_char, map.cells[pos2].origion_char, 7);
            display_map(&map);
        }
        return;
    }
}
