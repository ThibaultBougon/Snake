#pragma once
#include "SFML/Graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#define MAPSIZE 20
#define HEIGHT 600
#define WIDTH 800



typedef struct
{
	Coordinates pos;
	struct SnakesBody* next;
	sfColor color;
}SnakesBody;

typedef struct
{
	Direction dir;
	SnakesBody* body;
}Snake;

void initSnake(Snake* snake);
SnakesBody* pushBackSnakeBody(Coordinates pos, SnakesBody* body);
int removeSnake(Snake *snake);
void move(Snake snake, int x, int y);
int moveNorth(Snake *snake);
int moveWest(Snake *snake);
int moveSouth(Snake *snake);
int moveEast(Snake *snake);
void addPartToSnake(Snake *snake);
Coordinates searchPosition(Snake* snake);