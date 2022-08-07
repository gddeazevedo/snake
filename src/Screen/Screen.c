#include "Screen.h"


Screen* _Screen() {
    srand(time(NULL));
    Screen* screen = (Screen*) malloc(sizeof(Screen));

    int dim = 16;

    screen->height = dim;
    screen->width = dim * 2.5;

    return screen;
}


void init_screen(Screen* screen) {
    clear_screen(screen);
    refresh_screen(screen);
}

void render_screen(Screen* screen) {
    int x, y;
    getmaxyx(stdscr, y, x);
    screen->start_row = (y / 2) - (screen->height/ 2);
    screen->start_col = (x / 2) - (screen->width / 2);
    screen->window = newwin(screen->height, screen->width, screen->start_row, screen->start_col);

    wtimeout(screen->window, 120);
    keypad(screen->window, true); // allows us to capture arrow keys
}

void clear_screen(Screen* screen) {
    wclear(screen->window);
    box(screen->window, 0, 0);
}

void refresh_screen(Screen* screen) {
    wrefresh(screen->window);
}

void draw_block(Screen* screen, Block block, chtype ch) {
    mvwaddch(screen->window, block.y, block.x, ch);
}

chtype get_input(Screen* screen) {
    return wgetch(screen->window);
}

chtype get_char_at(Screen* screen, int x, int y) {
    return mvwinch(screen->window, y, x);
}

Block get_empty_coords(Screen* screen) {
    Block coords;
    while (mvwinch(screen->window, coords.y = rand() % screen->height, coords.x = rand() % screen->width) != ' ');
    return coords;
}
