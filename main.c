#include <stdio.h>
#include <ncurses.h>
#include <time.h>

#include "src/Screen/Screen.h"
#include "src/Game/Game.h"


void delay(int milliseconds);

int main(int argc, char** argv) {
    Screen* screen = _Screen();

    initscr();
    refresh();
    clear();
    noecho();
    curs_set(false);

    Game* game = _Game(screen);

    while (!game->is_over) {
        process_input(game);
        update_state(game);
        redraw(game);
    }

    delay(1000);

    endwin();

    system("clear");

    printf("GAMEOVER\nThanks for playing\n");

    return 0;
}


void delay(int milliseconds) {
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
