# ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

// player num
# define TOTAL_PLAYER_NUM 4

// Map's size
# define CELL_NUMS 70

# define INIT_MONEY 1000

// players' number
# define NO_ONE 0
# define QIANFUREN_NUMBER 1
# define ATUBO_NUMBER 2
# define SUNXIAOMEI_NUMBER 3
# define JINBEIBEI_NUMBER 4

// the maximum number of tools a player can have
# define TOOL_MAX_NUMS 10

// start position
# define START_POSITION 0
// prison position
# define PRISON_POSITION 49
// hospital position
# define HOSPITAL_POSITION 14
// tool house position
# define TOOL_HOUSE_POSITION 28
// gift house position
# define GIFT_HOUSE_POSITION 35
// magic house position
# define MAGIC_HOUSE_POSITION 63
// rank1 start position
# define RANK1_START_POSITION 1
// rank1 end position
# define RANK1_END_POSITION 27
// rank2 start position
# define RANK2_START_POSITION 29
// rank2 end position
# define RANK2_END_POSITION 34
// rank3 start position
# define RANK3_START_POSITION 36
// rank3 end position
# define RANK3_END_POSITION 62

// gold space pisition
# define GOLD_SPACE_1_POSITION 64
# define GOLD_SPACE_2_POSITION 65
# define GOLD_SPACE_3_POSITION 66
# define GOLD_SPACE_4_POSITION 67
# define GOLD_SPACE_5_POSITION 68
# define GOLD_SPACE_6_POSITION 69

// different gold space
# define GOLD_SPACE_1_POINT 60
# define GOLD_SPACE_2_POINT 80
# define GOLD_SPACE_3_POINT 40
# define GOLD_SPACE_4_POINT 100
# define GOLD_SPACE_5_POINT 80
# define GOLD_SPACE_6_POINT 20

// tools' point
# define BLOCK_POINT 50
# define BOMB_POINT 50
# define ROBOT_POINT 30
// the lowest points
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN_TOOL_POINT MIN(MIN(BLOCK_POINT, BOMB_POINT), ROBOT_POINT)

// players' show_char
# define QIANFUREN 'Q'
# define ATUBO 'A'
# define SUNXIAOMEI 'S'
# define JINBEIBEI 'J'

// cells' show_char
# define START_SHOW_CHAR "S"
# define BLANK_SPACE_SHOW_CHAR "0"
# define HOUSE_1_SHOW_CHAR "1"
# define HOUSE_2_SHOW_CHAR "2"
# define HOUSE_3_SHOW_CHAR "3"
# define GOLD_SPACE_SHOW_CHAR "$"
# define HOSPITAL_SHOW_CHAR "H"
# define PRISON_SHOW_CHAR "P"
# define TOOL_HOUSE_SHOW_CHAR "T"
# define GIFT_HOUSE_SHOW_CHAR "G"
# define MAGIC_HOUSE_SHOW_CHAR "M"

// tool's show_char
# define BLOCK "#"
# define BOMB "@"

// gifts' number
# define BONUS_NUMBER 1
# define POINT_CARD 2
# define GOD_OF_WEALTH 3

// the tools' buying press key
# define BUY_BLOCK_PRESS_KEY '1'
# define BUY_ROBOT_PRESS_KEY '2'
# define BUY_BOMB_PRESS_KEY '3'

// the press key to exit tool house
# define TOOL_HOUSE_EXIT_PRESS_KEY_1 'F'
# define TOOL_HOUSE_EXIT_PRESS_KEY_2 'f'

// define building kind
# define START -1
# define BLANK_SPACE 0
# define HOUSE_1 1
# define HOUSE_2 2
# define HOUSE_3 3
# define TOOL_HOUSE 4
# define GIFT_HOUSE 5
# define MAGIC_HOUSE 6
# define PRISON 7
# define HOSPITAL 8
# define GOLD_SPACE 9

// rank of space
# define RANK1 1
# define RANK2 2
# define RANK3 3

typedef struct Player{
    int number;
    int alive;
    int money;
    int point;
    int block;
    int bomb;
    int robot;
    int buff;
    int _continue;
    int prison;
    int hospital;
    int de_continue;
    int position;
    int** properties;
    int property_count;
} Player;

typedef struct Cell{
    char show_char[7];
    int kind;
    int rank;
    int has_tool;
    int owner;
} Cell;

typedef struct Map{
    Cell cells[CELL_NUMS];
} Map;

int get_step_count();
void init_player(int number, int init_money);
void init_all_players(int init_money);
void destroy_player(Player player);
void init_map(Map *map);
void display_map(Map map);
void tool_hosue(Player *player);
void gift_house(Player *player);
void magic_hosue(Player *player);
void goto_hospital(Player player);
void goto_prison(Player player);
void get_gold(Player *player, int gold_space_position);

# endif
