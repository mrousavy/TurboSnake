#include "Snake.h"



snake::snake(const size_t length)
	: buffer(), snake_direction(direction::right)
{
	buffer.push_back({ 8,3 });
	buffer.push_back({ 7,3 });
	buffer.push_back({ 6,3 });
	buffer.push_back({ 5,3 });
	buffer.push_back({ 4,3 });
	buffer.push_back({ 3,3 });
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


	// Loop from element before head to tail
	for (int i = buffer.size() - 1; i > -1; i--)
	{
		if (i == 0)
		{
			// Move head
			move_single(buffer.at(0), snake_direction);
		}
		else
		{
			point& current = buffer.at(i);
			point& next = buffer.at(i - 1);

			if (next.x > current.x)
				move_single(buffer.at(i), direction::right);
			if (next.x < current.x)
				move_single(buffer.at(i), direction::left);
			if (next.y > current.y)
				move_single(buffer.at(i), direction::down);
			if (next.y < current.y)
				move_single(buffer.at(i), direction::up);

		}
	}
}

void snake::grow()
{
	grow_one_ = true;
}
