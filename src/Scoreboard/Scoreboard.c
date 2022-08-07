#include "Scoreboard.h"


Scoreboard* _Scoreboard(int width, int x, int y) {
    Scoreboard* board = (Scoreboard*) malloc(sizeof(Scoreboard));
    board->score_win = newwin(1, width, y, x);
    return board;
}


void init_scoreboard(Scoreboard* board, int init_score) {
    clear_scoreboard(board);
    mvwprintw(board->score_win, 0, 0, "Score:");
    update_scoreboard(board, init_score);
    refresh_scorebboard(board);
}

void update_scoreboard(Scoreboard* board, int score) {
    mvwprintw(board->score_win, 0, board->score_win->_maxx - 10, "%11llu", score);
}


void clear_scoreboard(Scoreboard* board) {
    wclear(board->score_win);
}

void refresh_scorebboard(Scoreboard* board) {
    wrefresh(board->score_win);
}
