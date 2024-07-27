# include "utils.h"

void mingoto_prison(Player player){
    player.prison = true;
    player.position = PRISON_POSITION;
}
