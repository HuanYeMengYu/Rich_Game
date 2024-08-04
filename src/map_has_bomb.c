#include "utils.h"

bool map_has_bomb(){
    for(int i=START_POSITION;i<CELL_NUMS;i++){
        if(map.cells[i].has_tool == BOMB){
            return true;
        }
    }
    return false;
}
