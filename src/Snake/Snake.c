#include "Snake.h"


Snake* _Snake(int x, int y) {
    Snake* snake = (Snake*) malloc(sizeof(Snake));

    snake->body = _LinkedList();

    push_back(snake->body, _Block(x + 2, y));
    push_back(snake->body, _Block(x + 1, y));
    push_back(snake->body, _Block(x, y));

    snake->direction = RIGHT;

    return snake;
}

void draw_snake(Snake* snake, Screen* screen) {
    Node* aux = snake->body->head;

    draw_block(screen, aux->block, '@');
    aux = aux->next;
    
    while (aux != NULL) {
        draw_block(screen, aux->block, 'x');
        aux = aux->next;
    }
}

void move_snake(Snake* snake) {
    Block new_block = snake->body->head->block;

    switch (snake->direction) {
        case UP:
            new_block.y -= 1;        
            break;
        case DOWN:
            new_block.y += 1;
            break;
        case LEFT:
            new_block.x -= 1;
            break;
        case RIGHT:
            new_block.x += 1;
            break;
        default:
            break;
    }

    push_front(snake->body, new_block);
    snake->tail = pop_back(snake->body);
}

void change_direction(Snake* snake, enum Direction direction) {
    if (direction != get_opposite_direction(snake->direction))
        snake->direction = direction;
}

Block get_head_position(Snake* snake) {
    return snake->body->head->block;
}

Block get_next_head(Snake* snake) {
    Block head_position = get_head_position(snake);
    enum Direction current_direction = snake->direction;

    switch (current_direction) {
        case UP:
            return _Block(head_position.x, head_position.y - 1);
        case DOWN:
            return _Block(head_position.x, head_position.y + 1);
        case LEFT:
            return _Block(head_position.x - 1, head_position.y);
        case RIGHT:
            return _Block(head_position.x + 1, head_position.y);
    }
}

void restore_tail(Snake* snake) {
    push_back(snake->body, snake->tail);
}

enum Direction get_opposite_direction(enum Direction direction) {
    switch (direction) {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
    }
}
