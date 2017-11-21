#pragma once
#include "Structures.h"
#include "GameGrid.h"


#define DEFAULT_WIDTH 500
#define DEFAULT_HEIGHT 800


class game
{
private:
	game_grid<DEFAULT_WIDTH, DEFAULT_HEIGHT> grid_;
public:
	game();
	~game();
	void input(action action);
};

