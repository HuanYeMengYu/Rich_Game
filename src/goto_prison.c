# include "utils.h"

void goto_prison(Player *player){
    if(player->position == PRISON_POSITION){
        const char* cur_player_name = get_player_name(player->number);
        printf("%s被抓进监狱，2回合内轮空\n", cur_player_name);
        player->prison = 1;
        player->de_continue = 2;
    }
}
