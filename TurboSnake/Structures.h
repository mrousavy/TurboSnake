#pragma once

/// \brief An integer point in a coordinate system
struct point
{
	int x, y;
	point(const int x, const int y) : x(x), y(y) {}
};

/// \brief A floating point point in a coordinate system
struct pointf
{
	float x, y;
	pointf(const float x, const float y) : x(x), y(y) {}
};

/// \brief An action that can happen in the game
enum class action
{
	left,	// Steer the Snake to the left  (L-Arr/A)
	right,	// Steer the Snake to the right (R-Arr/D)
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