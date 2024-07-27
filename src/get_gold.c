# include "utils.h"

void get_gold(Player *player, int gold_space_position){
    switch (gold_space_position)
    {
    case GOLD_SPACE_1_POSITION:
        printf("获得%d点数\n", GOLD_SPACE_1_POINT);
        player->point += GOLD_SPACE_1_POINT;
        break;
    case GOLD_SPACE_2_POSITION:
        printf("获得%d点数\n", GOLD_SPACE_2_POINT);
        player->point += GOLD_SPACE_2_POINT;
        break;
    case GOLD_SPACE_3_POSITION:
        printf("获得%d点数\n", GOLD_SPACE_3_POINT);
        player->point += GOLD_SPACE_3_POINT;
        break;
    case GOLD_SPACE_4_POSITION:
        printf("获得%d点数\n", GOLD_SPACE_4_POINT);
        player->point += GOLD_SPACE_4_POINT;
        break;
    case GOLD_SPACE_5_POSITION:
        printf("获得%d点数\n", GOLD_SPACE_5_POINT);
        player->point += GOLD_SPACE_5_POINT;
        break;
    case GOLD_SPACE_6_POSITION:
        printf("获得%d点数\n", GOLD_SPACE_6_POINT);
        player->point += GOLD_SPACE_6_POINT;
        break;
    default:
        printf("gold_space_position有误！\n");
        break;
    }
}
