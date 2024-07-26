# include "utils.h"

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;

void begin_game(){
    printf("设置玩家初始资金,范围1000-50000(默认10000)或者输入回车跳过:");
    int init_money = 0;
    scanf("%d", &init_money);

    if(init_money=='\n'){
        init_money = 1000;
    }

    init_all_players(init_money);

    printf("请选择2~4位不重复玩家,输入编号即可(1.钱夫人;2.阿土伯;3.孙小美;4.金贝贝),可自由排序:");
    char scan_players[TOTAL_PLAYER_NUM+1] = {'\0'};
    scanf("%s", scan_players);
    for(int i=0;i<=TOTAL_PLAYER_NUM-1;i++){
        if(scan_players[i] == '\0')
            break;
        int player_number = (int)(scan_players[i] - '0');
        switch (player_number)
        {
        case 1:
            QianFuren.alive = 1;
            break;
        case 2:
            ATubo.alive = 1;
            break;
        case 3:
            SunXiaomei.alive = 1;
            break;
        case 4:
            JinBeibei.alive = 1;
            break;
        default:
            break;
        }
    }
}
