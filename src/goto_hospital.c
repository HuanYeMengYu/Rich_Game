# include "utils.h"

void goto_hospital(Player player){
    player.hospital = true;
    player.position = HOSPITAL_POSITION;
}
