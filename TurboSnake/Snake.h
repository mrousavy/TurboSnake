#pragma once
#include <vector>
#include "Structures.h"

#define START_LENGTH 3

class snake
{
private:
	bool grow_one_ = false;

	static void move_single(point& point, direction direction);
public:
	explicit snake(const size_t length = START_LENGTH);
	~snake();
	/// \brief The buffer of all snake points, relative to the grid (!= pixels)
	std::vector<point> buffer;
	direction snake_direction = direction::right;

	/// \brief Move the snake in the current direction
	void move();
	/// \brief Let the snake grow one
	void grow();
};

