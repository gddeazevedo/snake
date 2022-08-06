#ifndef FOOD_H
#define FOOD_H

#include <stdbool.h>
#include "../Block/Block.h"
#include "../Screen/Screen.h"

typedef Block Food;

Food* _Food(int x, int y);
void draw_food(Food* food, Screen* screen);

#endif