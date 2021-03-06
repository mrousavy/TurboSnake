#pragma once

/// \brief An integer point in a coordinate system
struct point
{
	int x, y;
	point() : x(0), y(0) {}
	point(const int x, const int y) : x(x), y(y) {}

	bool operator==(const point other) const
	{
		return x == other.x && y == other.y;
	}
	bool operator!=(const point other) const
	{
		return x != other.x && y != other.y;
	}
};

/// \brief A floating point point in a coordinate system
struct pointf
{
	float x, y;
	pointf() : x(0), y(0) {}
	pointf(const float x, const float y) : x(x), y(y) {}

	bool operator==(const point other) const
	{
		return x == other.x && y == other.y;
	}
	bool operator!=(const point other) const
	{
		return x != other.x && y != other.y;
	}
};

/// \brief An action that can happen in the game
enum class action
{
	left,	// Steer the Snake to the left  (L-Arr/A)
	up,		// Steer the Snake upwards		(U-Arr/W)
	right,	// Steer the Snake to the right (R-Arr/D)
	down,	// Steer the Snake downwards	(D-Arr/S)
	boost	// Speed-up the snake			(Space)
};

/// \brief A direction the snake can face
enum class direction
{
	up,
	right,
	left,
	down
};