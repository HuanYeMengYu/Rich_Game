# include "utils.h"

extern Map map;

int main(){
    init_map(&map);
    display_map(map);
    
    return 0;
}
