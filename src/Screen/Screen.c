#include "Screen.h"


int difficultty;


Screen* _Screen() {
    srand(time(NULL));
    Screen* screen = (Screen*) malloc(sizeof(Screen));

    int dim = 20;

    while (true) {
        system("clear");
        printf("\n\nEscolha uma dificuldade:\n");
        printf("(1) Díficil\n");
        printf("(2) Médio\n");
        printf("(3) Fácil\n");

        scanf("%d", &difficultty);

        if (difficultty == 1) {
            dim = 10;
            break;
        } else if (difficultty == 2) {
            dim = 15;
            break;
        } else if (difficultty == 3) {
            dim = 20;
            break;
        }
    }

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
    screen->window = newwin(screen->height, screen->width, (y / 2) - (screen->height/ 2), (x / 2) - (screen->width / 2));
    
    if (difficultty == 1) {
        wtimeout(screen->window, HARD);
    } else if (difficultty == 2) {
        wtimeout(screen->window, NORMAL);
    } else {
        wtimeout(screen->window, EASY);
    }
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
