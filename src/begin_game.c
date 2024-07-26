# include "utils.h"

void begin_game(){
    printf("设置玩家初始资金，范围1000-50000（默认10000）或者输入回车跳过:");
    int init_money = 0;
    scanf("%d", &init_money);
    printf("请选择2~4位不重复玩家，输入编号即可（1、钱夫人；2、阿土伯；3、孙小美；4、金贝贝），可自由排序:");
    char players[4] = {0, 0, 0, 0};
    scanf("%s", players);
    
}
