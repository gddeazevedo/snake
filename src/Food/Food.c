#include "Food.h"


Food* _Food(int x, int y) {
    Food* food = (Food*) malloc(sizeof(Food));
    food->x = x;
    food->y = y;
    return food;
}

void draw_food(Food* food, Screen* screen) {
    draw_block(screen, *food, '$');
}
