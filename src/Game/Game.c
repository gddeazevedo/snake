#include "Game.h"


Game* _Game(Screen* screen) {
    Game* game = (Game*) malloc(sizeof(Game));
    
    game->screen = screen;
    game->is_over = false;
    game->snake = _Snake(screen->width / 2, screen->height / 2);

    game->food = _Food(5, 5);

    render_screen(screen);
    init_screen(screen);

    return game;
}

void redraw(Game* game) {
    refresh_screen(game->screen);
}

void process_input(Game* game) {
    chtype input = get_input(game->screen);

    switch (input) {
        case KEY_UP:
        case 'w':
            change_direction(game->snake, UP);
            break;
        case KEY_DOWN:
        case 's':
            change_direction(game->snake, DOWN);
            break;
        case KEY_LEFT:
        case 'a':
            change_direction(game->snake, LEFT);
            break;
        case KEY_RIGHT:
        case 'd':
            change_direction(game->snake, RIGHT);
            break;
        case 'p':
            while (get_input(game->screen) != 'p');
        default:
            break;
    }
}

void update_state(Game* game){
    Block next_head = get_next_head(game->snake);


    if (game->food != NULL) {
        chtype char_at = get_char_at(game->screen, next_head.x, next_head.y);

        switch (char_at) {
            case '$':
                draw_block(game->screen, *game->food, ' ');
                restore_tail(game->snake);
                game->food = NULL;
                break;
            case ' ':
                move_snake(game->snake);
                int empty_row = game->snake->tail.y;
                int empty_col = game->snake->tail.x;
                draw_block(game->screen, _Block(empty_col, empty_row), ' ');
                break;
            default:
                game->is_over = true;
                return;
        }
    }

    if (game->food == NULL) {
        Block empty_coords = get_empty_coords(game->screen);
        game->food = _Food(empty_coords.x, empty_coords.y);
    }

    draw_snake(game->snake, game->screen);
    draw_food(game->food, game->screen);
}

void restart(Game* game) {
    game->is_over = false;
    game->snake = _Snake(game->screen->width / 2, game->screen->height / 2);
    game->food = _Food(5, 5);
    render_screen(game->screen);
    init_screen(game->screen);
}
