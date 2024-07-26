# ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

# define CELL_NUMS 70

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
    
} Cell;


typedef struct Map{
    Cell cells[CELL_NUMS];
} Map;

# endif
