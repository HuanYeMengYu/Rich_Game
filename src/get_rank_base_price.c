# include "utils.h"

int get_rank_base_price(int rank){
    assert(rank >= RANK1 && rank <= RANK3);

    switch(rank){
        case RANK1:
            return RANK1_PRICE;
            break;
        case RANK2:
            return RANK2_PRICE;
            break;
        case RANK3:
            return RANK3_PRICE;
            break;
        // rank不在1~3，则返回-1表示获取失败
        default:
            return -1;
            break;
    }
}
