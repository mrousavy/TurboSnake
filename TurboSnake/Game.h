#pragma once
#include "Structures.h"
#include "GameGrid.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Snake.h"


#define GRID_ROWS 30
#define GRID_COLS 30


class game
{
private:
	game_grid<GRID_ROWS, GRID_COLS> grid_;
	sf::Font& font_;
	sf::RenderTarget& r_target_;
	
	snake* snake_;
	int ate_;	// Count of eaten food items
	point food_;	// A food item
public:
	explicit game(sf::Font& font, sf::RenderTarget& render_target);
	~game();
	/// \brief Input the given action to the snake
	void input(action action) const;
	/// \brief Perform a game tick/move the snake forwards
	void tick() const;
	/// \brief Update and Redraw the buffered game render area
	void update() const;
	/// \brief Get a game grid field width-size in pixels
	float field_w() const;
	/// \brief Get a game grid field height-size in pixels
	float field_h() const;
	/// \brief Get the direction the snake is facing
	direction direction() const;
	/// \brief Get the number of items the snake already ate
	int ate() const;

	/// \brief Pause or unpause the game
	bool paused = false;
};

