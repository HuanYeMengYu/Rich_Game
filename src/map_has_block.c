#include "utils.h"

bool map_has_block(){
    for(int i=START_POSITION;i<CELL_NUMS;i++){
        if(map.cells[i].has_tool == BLOCK){
            return true;
        }
    }
    return false;
}
