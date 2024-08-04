# ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>
# include <string.h>
# include <ctype.h>
# include <assert.h>

// player name
# define QIANFUREN_NAME "钱夫人"
# define ATUBO_NAME "阿土伯"
# define SUNXIAOMEI_NAME "孙小美"
# define JINBEIBEI_NAME "金贝贝"

// player num
# define TOTAL_PLAYER_NUM 40

// map's size
# define CELL_NUMS 70

// money range
# define DEFAULT_MONEY 10000
# define LEAST_MONEY 1000
# define MOST_MONEY 50000

// players' number
# define NO_ONE 0
# define QIANFUREN_NUMBER 1
# define ATUBO_NUMBER 2
# define SUNXIAOMEI_NUMBER 3
# define JINBEIBEI_NUMBER 4

// the maximum number of tools a player can have
# define MAX_TOOL_NUMS 10

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
# define QIANFUREN_SHOW_CHAR 'Q'
# define ATUBO_SHOW_CHAR 'A'
# define SUNXIAOMEI_SHOW_CHAR 'S'
# define JINBEIBEI_SHOW_CHAR 'J'

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
# define BLOCK_SHOW_CHAR '#'
# define BOMB_SHOW_CHAR '@'

# define CELL_DONT_HAVE_TOOL 0
# define BLOCK 1
# define BOMB 2
# define ROBOT 3

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
# define PARK 10

# define DONT_HAVE -1

// rank of space
# define RANK0 0    // specail building
# define RANK1 1    // rank 1 space/house
# define RANK2 2    // rank 2 space/house
# define RANK3 3    // rank 3 space/house

// basic price of different ranks
# define RANK1_PRICE 200
# define RANK2_PRICE 500
# define RANK3_PRICE 300

// player living
# define ALIVE 1
# define DEATH 0

// house selling level
# define SELL_HOUSE_LEVEL 2

// search position key word
# define PLAYER1_KEY_WORD "1"
# define PLAYER2_KEY_WORD "2"
# define PLAYER3_KEY_WORD "3"
# define PLAYER4_KEY_WORD "4"
# define PRISION_KEY_WORD "prison"
# define HOSPITAL_KEY_WORD "hospital"
# define TOOL_HOUSE_KEY_WORD "tool"
# define GIFT_HOSUE_KEY_WORD "gift"
# define MAGIC_HOUSE_KEY_WORD "magic"
# define MINES_KEY_WORD "mines"
# define BLOCK_KEY_WORD "block"
# define BOMB_KEY_WORD "bomb"

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
    int properties[CELL_NUMS];
    int property_count;
} Player;

typedef struct Cell{
    char show_char[7];
    char origion_char[7];
    int kind;
    int rank;
    int has_tool;   // 0--no tolls, 1--block, 2--bomb
    int owner;
} Cell;

typedef struct Map{
    Cell cells[CELL_NUMS];
} Map;

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;
extern char init_show_char[7];
extern int player_number;
extern int player_index;
extern int left_player_nums;
extern int player_number_arr[TOTAL_PLAYER_NUM];
extern int god_incoming_round;
extern int cur_god_round;;

extern char users[5];
extern char now_user[2];
extern Player *use_players;
extern int cur_round;

Player* get_player(int player_number);
const char* get_player_name(int player_number);
char get_player_show_char(int player_number);

void choose_players();
void sort_player_number_arr();
void update_player_number();

int scan_cmd(char* cmd_buf);
void begin_game();
int init_money();
int get_step_count();
void move(Player *player, int step);
void init_player(int number, int init_money);
void init_all_players(int init_money);
void destroy_player(Player *player);
void init_map(Map *map);
void display_map(Map *map);
void display_map(Map *map);
void tool_hosue(Player *player);
void gift_house(Player *player);
void magic_hosue(Player *player);
void goto_hospital(Player *player);
void goto_prison(Player *player);
void get_gold(Player *player);
int Get_instruction(char* keyboard_input, char *result);
void Print_Help();
void Show_Assets(Player *player);

int get_rank_base_price(int rank);
int one_house_total_price(int house_position);
int one_house_sell_price(int house_position);
int player_all_houses_price(Player *player);
int player_sell_all_houses_price(Player *player);
int sell_house(Player *player, int place);
void BuyAndRent(Player *player);
void Upgradation(Player *player,int price);
void BuyPlace(Player *player,int price);

void Bankruptcy(Player *player);

bool map_has_block();
bool map_has_bomb();

int tool_trigger(Player *player,int motion);
void Robot(Player *player);
void Block(Player *player,int n);
void Bomb(Player *player,int n);

void player_exit_game(int Player_number);
bool game_over();

void GameGodComing();

# endif
