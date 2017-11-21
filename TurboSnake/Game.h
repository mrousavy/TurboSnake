#pragma once
#include "Structures.h"
#include "GameGrid.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>


#define DEFAULT_ROWS 10
#define DEFAULT_COLS 30


class game
{
private:
	game_grid<DEFAULT_ROWS, DEFAULT_COLS> grid_;
	sf::Font& font_;
	sf::RenderWindow& window_;
public:
	explicit game(sf::Font& font, sf::RenderWindow& window);
	~game();
	/// \brief Input the given action to the snake
	void input(action action);
	/// \brief Perform a game tick/move the snake forwards
	void tick();
	/// \brief Update and Redraw the game render area
	void update();

	/// \brief Pause or unpause the game
	bool paused = false;
};

