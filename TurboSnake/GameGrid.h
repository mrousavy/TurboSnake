#pragma once
#include <array>

/// \brief A single game field in the Snake game grid
struct field
{
	/// \brief A boolean value indicating whether this field should be painted
	bool filled = false;
	/// \brief The absolute position in pixels of this field
	point abs_pos = {0,0};
};


/// \brief A single row in the Snake game grid
template<size_t Width>
class row
{
private:
	std::array<field, Width> fields_;
public:
	/// \brief Get the nth field from this row
	field operator[](const int index)
	{
		return fields_[index];
	}
};

/// \brief The whole Snake game area/grid
template<size_t Width, size_t Height>
class game_grid
{
private:
	std::array<row<Width>, Height> rows_;
public:
	/// \brief Get the nth row from the game grid
	row<Width> operator[](const int index)
	{
		return rows_[index];
	}
};

