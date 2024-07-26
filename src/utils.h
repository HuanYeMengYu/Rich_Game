# ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

// Map's size
# define CELL_NUMS 70

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
# define START_SHOW_CHAR 'S'
# define BLANK_SPACE_SHOW_CHAR '0'
# define HOUSE_1_SHOW_CHAR '1'
# define HOUSE_2_SHOW_CHAR '2'
# define HOUSE_3_SHOW_CHAR '3'
# define GOLD_SPACE_SHOW_CHAR '$'
# define HOSPITAL_SHOW_CHAR 'H'
# define PRISON_SHOW_CHAR 'P'
# define TOOL_HOUSE_SHOW_CHAR 'T'
# define GIFT_HOUSE_SHOW_CHAR 'G'
# define MAGIC_HOUSE_SHOW_CHAR 'M'

// tool's show_char
# define BLOCK '#'
# define BOMB '@'

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
    bool alive;
    int money;
    int point;
    int block;
    int bomb;
    int robot;
    bool buff;
    int _continue;
    bool prison;
    bool hospital;
    int de_continue;
    int position;
} Player;

typedef struct Cell{
    char show_char;
    int kind;
    int rank;
    int has_tool;
    char owner;     // owner = 'N' , means owner is None
} Cell;

typedef struct Map{
    Cell cells[CELL_NUMS];
} Map;

# endif
