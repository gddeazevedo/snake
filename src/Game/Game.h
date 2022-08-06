#ifndef GAME_H
#define GAME_H


#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../Screen/Screen.h"
#include "../Block/Block.h"
#include "../Food/Food.h"
#include "../Snake/Snake.h"


typedef struct {
    Screen* screen;
    Food* food;
    Snake* snake;
    bool is_over;
} Game;

Game* _Game(Screen* screen);
void redraw(Game* game);
void process_input(Game* game);
void update_state(Game* game);
void restart(Game* game);



#endif