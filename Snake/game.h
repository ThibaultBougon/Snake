#pragma once
#include "SFML/Graphics.h"
#include "Snake.h"
#include <stdio.h>
#include <stdlib.h>
#include "food.h"

#define MAPSIZE 20
#define HEIGHT 600
#define WIDTH 800

typedef struct {
	sfRenderWindow* window;
	Snake snake;
	Food food;
}Game;

typedef struct {
	struct Map* next;
	sfKeyCode key;
	int (*move)(Snake*);
}Map;

void game();
void initMap(sfRenderWindow* window);
sfRectangleShape* setRectPos(sfRectangleShape* rect, sfColor color, int x, int y);
void dispSnake(sfRenderWindow* window, Snake body);
void dispFood(Food food, sfRenderWindow* window);
void clear(sfRenderWindow* window, Snake snake);
void gameLoop(Game game, Map* moveMap);
int collideWithBody(Snake snake);
void printGame(Game *game);
Map* mapSet(Map* map, sfKeyCode key, void (*move)(Snake*));
void removeMap(Map* map);
void controller(Map* map, sfEvent eventKey, Game* game);

static inline int isAllowToGo(Snake snake) {
	if (snake.body->pos.x == 0 || snake.body->pos.y == 0 ||
		snake.body->pos.x == MAPSIZE - 1 || snake.body->pos.y == MAPSIZE - 1)
		return 0;
	return collideWithBody(snake);
}
