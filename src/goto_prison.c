# include "utils.h"

void goto_prison(Player *player){
    player->prison = true;
    player->position = PRISON_POSITION;
}
