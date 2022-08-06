#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>
#include "../LinkedList/LinkedList.h"
#include "../Screen/Screen.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    LinkedList* body;
    Block tail;
    enum Direction direction;
} Snake;

enum Direction get_opposite_direction(enum Direction direction);
Snake* _Snake(int x, int y);
void draw_snake(Snake* snake, Screen* screen);
void move_snake(Snake* snake);
void change_direction(Snake* snake, enum Direction direction);
Block get_head_position(Snake* snake);
Block get_next_head(Snake* snake);
void restore_tail(Snake* snake);


#endif
