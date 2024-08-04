# include "utils.h"

void magic_hosue(Player *player){
    if(player->position != MAGIC_HOUSE_POSITION){
        return;
    }
    printf("玩家可以施展魔法，具体施展什么样的魔法，客户还没想好……\n");
}
