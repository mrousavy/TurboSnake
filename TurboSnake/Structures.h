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