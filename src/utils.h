# ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

// Map's size
# define CELL_NUMS 70

// defines the maximum number of tools a player can have
# define TOOL_MAX_NUMS 10

// define tools' point
# define BLOCK_POINT 50
# define BOMB_POINT 50
# define ROBOT_POINT 30
// define the lowest points
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN_POINT MIN(MIN(BLOCK_POINT, BOMB_POINT), ROBOT_POINT)

// define players' show_char
# define QIANFUREN 'Q'
# define ATUBO 'A'
# define SUNXIAOMEI 'S'
# define JINBEIBEI 'J'

// define cells' show_char
# define START 'S'
# define BLANK_SPACE '0'
# define HOUSE_1 '1'
# define HOUSE_2 '2'
# define HOUSE_3 '3'
# define GOLD_SPACE '$'
# define HOSPITAL 'H'
# define PRISON 'P'
# define TOOL_HOUSE 'T'
# define GIFT_HOUSE 'G'
# define MAGIC_HOUSE 'M'

// define tool's show_char
# define BLOCK '#'
# define BOMB '@'

// define gifts' number
# define BONUS_NUMBER 1
# define POINT_CARD 2
# define GOD_OF_WEALTH 3

// define the tools' buying press key
# define BUY_BLOCK_PRESS_KEY '1'
# define BUY_ROBOT_PRESS_KEY '2'
# define BUY_BOMB_PRESS_KEY '3'

// define the press key to exit tool house
# define TOOL_HOUSE_EXIT_1 'F'
# define TOOL_HOUSE_EXIT_2 'f'

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
    int owner;
} Cell;

typedef struct Map{
    Cell cells[CELL_NUMS];
} Map;

# endif
