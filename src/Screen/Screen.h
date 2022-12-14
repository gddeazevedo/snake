#ifndef SETTINGS_H
#define SETTINGS_H


#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include "../Block/Block.h"


typedef struct {
    WINDOW* window;
    int height;
    int width;
    int start_row;
    int start_col;
} Screen;


Screen* _Screen();
void render_menu();
void init_screen(Screen* screen);
void render_screen(Screen* screen);
void clear_screen(Screen* screen);
void refresh_screen(Screen* screen);
chtype get_input(Screen* screen);
void draw_block(Screen* screen, Block block, chtype ch);
Block get_empty_coords(Screen* screen);
chtype get_char_at(Screen* screen, int x, int y);

#endif