# include "utils.h"

void destroy_player(Player player){
    if(!player.properties)
        return;
    for(int i=0;i<player.property_count;i++){
        free(player.properties[i]);
    }
    free(player.properties);
}
