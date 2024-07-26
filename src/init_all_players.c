# include "utils.h"

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;

void init_all_players(int init_money){
    init_player((int)QIANFUREN_NUMBER, init_money);
    init_player((int)ATUBO_NUMBER, init_money);
    init_player((int)SUNXIAOMEI_NUMBER, init_money);
    init_player((int)JINBEIBEI_NUMBER, init_money);
}
