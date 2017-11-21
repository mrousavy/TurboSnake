#pragma once
#include <vector>
#include "Structures.h"
#include "Game.h"

#define START_LENGTH 3

class snake
{
private:
	bool grow_one_ = false;
	game& game_;

	void move_single(pointf& point, direction direction) const;
public:
	explicit snake(game& game, const size_t length = START_LENGTH);
	~snake();
	std::vector<pointf> buffer;
	direction snake_direction;

	/// \brief Move the snake in the current direction
	void move();
	/// \brief Let the snake grow one
	void grow();
};

