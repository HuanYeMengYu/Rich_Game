# include "utils.h"

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;

void init_all_players(int init_money){
    init_player(QianFuren, QIANFUREN_NUMBER, init_money);
    init_player(ATubo, ATUBO_NUMBER, init_money);
    init_player(SunXiaomei, SUNXIAOMEI_NUMBER, init_money);
    init_player(JinBeibei, JINBEIBEI_NUMBER, init_money);
}
