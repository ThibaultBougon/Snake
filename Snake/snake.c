#include "snake.h"
#include "log.h"
//#include "game.h"

void initSnake(Snake* snake) {
	snake->dir = north;
	Coordinates initPos;
	initPos.x = MAPSIZE / 2;
	initPos.y = MAPSIZE / 2;
	snake->body = NULL;
	

	for (int i = 0; i < 3; ++i) {
		initPos.y = (MAPSIZE / 2)+i;
		snake->body = pushBackSnakeBody(initPos, snake->body);
	}
}

 SnakesBody* pushBackSnakeBody(Coordinates pos, SnakesBody *body) {
	SnakesBody *newPart = malloc(sizeof(*newPart));
	if (!newPart) {
		addLog(LOG_ERR, "add part not allocated");
		return 1;
	}
	newPart->pos = pos;
	newPart->next = NULL;

	if (!body) {
		newPart->color = sfColor_fromRGB(255, 0, 0);
		return newPart;
	}
	newPart->color = sfColor_fromRGB(255, 255, 0);


	SnakesBody *buff;
	buff = body;
	while (buff->next)
		buff = buff->next;
	buff->next = newPart;
	return body;
}

int removeSnake(Snake *snake) {
	if (!snake->body)
		return 0;
	while (snake->body->next)
	{
		SnakesBody *del = snake->body;
		snake->body = snake->body->next;
		free(del);
	}
	free(snake->body);
	return 0;
}

void move(Snake snake, int x, int y) {
	int actualX = 0;
	int actualY = 0;
	int buffX = snake.body->pos.x;
	int buffY = snake.body->pos.y;

	snake.body->pos.x += x;
	snake.body->pos.y += y;
	snake.body = snake.body->next;
	while (snake.body) {
		actualX = snake.body->pos.x;
		actualY = snake.body->pos.y;
		snake.body->pos.x = buffX;
		snake.body->pos.y = buffY;
		snake.body = snake.body->next;
		buffX = actualX;
		buffY = actualY;
	}
}

int moveNorth(Snake *snake) {
	if (snake->dir == south)
		return 0;
	move(*snake, 0, -1);
	snake->dir = north;
	return 1;
}

int moveWest(Snake *snake) {
	if (snake->dir == east)
		return 0;
	move(*snake, -1, 0);
	snake->dir = west;
	return 1;
}

int moveSouth(Snake *snake) {
	if (snake->dir == north)
		return 0;
	move(*snake, 0, 1);
	snake->dir = south;
	return 1;
}

int moveEast(Snake*snake) {
	if (snake->dir == west)
		return 0;
	move(*snake, 1, 0);
	snake->dir = east;
	return 1;
}

void addPartToSnake(Snake* snake) {
	Coordinates pos = searchPosition(snake);
	snake->body =  pushBackSnakeBody(pos, snake->body);
}

Coordinates searchPosition(Snake* snake) {
	SnakesBody* previous = NULL;
	SnakesBody* actual = snake->body;

	while (actual->next)
	{
		previous = actual;
		actual = actual->next;
	}
	Coordinates pos;
	pos.x = previous->pos.x - actual->pos.x;
	pos.y = previous->pos.y - actual->pos.y;
	return pos;
}