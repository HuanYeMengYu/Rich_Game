# include "utils.h"

void init_player(Player player, int number, int init_money){
    switch (number)
    {
    case 1:
        player.number = 1;
        player.alive = true;
        player.money = init_money;
        player.point = 0;
        player.block = 0;
        player.bomb = 0;
        player.robot = 0;
        player.buff = false;
        player._continue = 0;
        player.prison = false;
        player.hospital = false;
        player.de_continue = 0;
        player.position = 0;
        
        break;
    case 2:
        player.number = 2;
        player.alive = true;
        player.money = init_money;
        player.point = 0;
        player.block = 0;
        player.bomb = 0;
        player.robot = 0;
        player.buff = false;
        player._continue = 0;
        player.prison = false;
        player.hospital = false;
        player.de_continue = 0;
        player.position = 0;

        break;
    case 3:
        player.number = 3;
        player.alive = true;
        player.money = init_money;
        player.point = 0;
        player.block = 0;
        player.bomb = 0;
        player.robot = 0;
        player.buff = false;
        player._continue = 0;
        player.prison = false;
        player.hospital = false;
        player.de_continue = 0;
        player.position = 0;
        break;
    case 4:
        player.number = 4;
        player.alive = true;
        player.money = init_money;
        player.point = 0;
        player.block = 0;
        player.bomb = 0;
        player.robot = 0;
        player.buff = false;
        player._continue = 0;
        player.prison = false;
        player.hospital = false;
        player.de_continue = 0;
        player.position = 0;

        break;
    default:
        break;
    }
}
