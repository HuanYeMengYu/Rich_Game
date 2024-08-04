# include "utils.h"

void Print_Help(){
    printf("%s\n","help       查看命令帮助");
    printf("%s\n","query      显示自家资产");
    printf("%s\n","mines      查找所有矿地的位置和点数");
    printf("%s\n","position n 查找玩家、特殊建筑、道具的位置");
    printf("%s\n","-------->  n=1/2/3/4查找玩家位置，");
    // printf("%s\n","-------->  特殊建筑查找关键词：prison,hospital,tool,gift,magic,mines");
    // printf("%s\n","-------->  道具查找关键词：block,bomb");
    printf("%s\n","-------->  特殊建筑查找关键词：tool,gift,mines");
    printf("%s\n","-------->  道具查找关键词：block");
    printf("%s\n","roll       掷骰子命令。行走1~6步，步数由随机算法产生");
    printf("%s\n","step  n    遥控骰子，n为指定的步数");
    printf("%s\n","sell  n    轮到玩家时，可出售自己的任意房产，出售价格为投资Tn为房产在地图上的绝对位置总成本的2倍。");
    printf("%s\n","block n    玩家可将路障放置到离当前位置前后10步的任何位置，表任一玩家经过路障，将被拦截。该道具一次有效，n为前后的相对距离，负数表示后方");
    //printf("%s\n","bomb  n    玩家可将炸弹放置到离当前位置前后10步的任何位置，n为前后的相对距离，负数表任一玩家经过该位置，将被炸伤，送往医院，住院三天。负数示后方");
    printf("%s\n","robot      使用该道具，可清扫前方路面上10步内的任何其他道具");
    printf("%s\n","quit       强制退出");
    printf("%s\n","dump       强制退出");
}
