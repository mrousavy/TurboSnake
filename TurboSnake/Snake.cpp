#include "Snake.h"



snake::snake(game& game, const size_t length = START_LENGTH)
	: game_(game), buffer(length), snake_direction()
{
	buffer.push_back({ 5,3 });
	buffer.push_back({ 4,3 });
	buffer.push_back({ 3,3 });
}


snake::~snake()
{
}

void snake::move_single(point& point, const direction direction) const
{
	switch (direction)
	{
		case direction::up:
			point.y -= game_.field();
			break;
		case direction::right:
			point.x += game_.field();
			break;
		case direction::down:
			point.y += game_.field();
			break;
		case direction::left:
			point.x -= game_.field();
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
	move_single(buffer.back(), snake_direction);

	// Loop from tail to element before head
	for(int i = 0; i < buffer.size() - 1; i++)
	{
		point& current = buffer.at(i);
		point& next = buffer.at(i + 1);

		direction target_direction = direction::right;
		if (next.x > current.x)
			target_direction = direction::right;
		else if (next.x < current.x)
			target_direction = direction::left;
		else if (next.y > current.y)
			target_direction = direction::up;
		else if (next.y < current.y)
			target_direction = direction::down;

		move_single(buffer.at(i), target_direction);
	}
}

void snake::grow()
{
	grow_one_ = true;
}
