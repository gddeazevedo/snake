#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    WINDOW* score_win;
} Scoreboard;


Scoreboard* _Scoreboard(int width, int x, int y);
void init_scoreboard(Scoreboard* board, int init_score);
void update_scoreboard(Scoreboard* board, int score);
void clear_scoreboard(Scoreboard* board);
void refresh_scorebboard(Scoreboard* board);

#endif