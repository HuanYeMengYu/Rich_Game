# include "utils.h"

// 获取某房屋的总价（包括没人拥有的空地），1~4 × base_price
int one_house_total_price(int house_position){
    assert(house_position >= START_POSITION && house_position < CELL_NUMS);

    int base_price = get_rank_base_price(map.cells[house_position].rank);
    int level = map.cells[house_position].kind + 1;
    int total_price = base_price * level;
    return total_price;
}
