#pragma once
#include "Snake.h"
#include "SFML/Graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct {
	Coordinates pos;
	sfColor color;
}Food;

void setFood(Food* food);
