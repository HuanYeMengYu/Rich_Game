# include "utils.h"

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;

void init_player(int number, int init_money){
    switch (number)
    {
    case QIANFUREN_NUMBER:
        QianFuren.number = QIANFUREN_NUMBER;
        QianFuren.alive = 0;
        QianFuren.money = init_money;
        QianFuren.point = 0;
        QianFuren.block = 0;
        QianFuren.bomb = 0;
        QianFuren.robot = 0;
        QianFuren.buff = 0;
        QianFuren._continue = 0;
        QianFuren.prison = 0;
        QianFuren.hospital = 0;
        QianFuren.de_continue = 0;
        QianFuren.position = 0;
        QianFuren.properties = NULL;
        QianFuren.property_count = 0;
        break;
    case ATUBO_NUMBER:
        ATubo.number = QIANFUREN_NUMBER;
        ATubo.alive = 0;
        ATubo.money = init_money;
        ATubo.point = 0;
        ATubo.block = 0;
        ATubo.bomb = 0;
        ATubo.robot = 0;
        ATubo.buff = 0;
        ATubo._continue = 0;
        ATubo.prison = 0;
        ATubo.hospital = 0;
        ATubo.de_continue = 0;
        ATubo.position = 0;
        ATubo.properties = NULL;
        ATubo.property_count = 0;
        break;
    case SUNXIAOMEI_NUMBER:
        SunXiaomei.number = SUNXIAOMEI_NUMBER;
        SunXiaomei.alive = 0;
        SunXiaomei.money = init_money;
        SunXiaomei.point = 0;
        SunXiaomei.block = 0;
        SunXiaomei.bomb = 0;
        SunXiaomei.robot = 0;
        SunXiaomei.buff = 0;
        SunXiaomei._continue = 0;
        SunXiaomei.prison = 0;
        SunXiaomei.hospital = 0;
        SunXiaomei.de_continue = 0;
        SunXiaomei.position = 0;
        SunXiaomei.properties = NULL;
        SunXiaomei.property_count = 0;
        break;
    case JINBEIBEI_NUMBER:
        JinBeibei.number = JINBEIBEI_NUMBER;
        JinBeibei.alive = 0;
        JinBeibei.money = init_money;
        JinBeibei.point = 0;
        JinBeibei.block = 0;
        JinBeibei.bomb = 0;
        JinBeibei.robot = 0;
        SunXiaomei.buff = 0;
        JinBeibei._continue = 0;
        JinBeibei.prison = 0;
        JinBeibei.hospital = 0;
        JinBeibei.de_continue = 0;
        JinBeibei.position = 0;
        JinBeibei.properties = NULL;
        JinBeibei.property_count = 0;
        break;
    default:
        break;
    }
}
