#include "Snake.h"



snake::snake(const size_t length)
	: buffer(), snake_direction()
{
	for (int i = 3; i < length + 3; i++)
	{
		buffer.push_back({ i,3 });
	}
}


snake::~snake()
{
}

void snake::move_single(point& point, const direction direction)
{
	switch (direction)
	{
		case direction::up:
			point.y--;
			break;
		case direction::right:
			point.x++;
			break;
		case direction::down:
			point.y++;
			break;
		case direction::left:
			point.x--;
			break;
	}
}


void snake::move()
{
	if (grow_one_)
	{
		const point& last = buffer.back(); // The last element (Snake's tail)
		buffer.push_back(last);
		grow_one_ = false;
	}

	// Move head
	move_single(buffer.at(0), snake_direction);

	// Loop from element before head to tail
	for (int i = 1; i < buffer.size(); i++)
	{
		point& current = buffer.at(i);
		point& next = buffer.at(i - 1);

		if (next.x > current.x)
			move_single(buffer.at(i), direction::right);
		else if (next.x < current.x)
			move_single(buffer.at(i), direction::left);
		else if (next.y > current.y)
			move_single(buffer.at(i), direction::down);
		else if (next.y < current.y)
			move_single(buffer.at(i), direction::up);

	}
}

void snake::grow()
{
	grow_one_ = true;
}
