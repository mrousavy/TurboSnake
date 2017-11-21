#pragma once
#include "Structures.h"
#include "GameGrid.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>


#define DEFAULT_WIDTH 500
#define DEFAULT_HEIGHT 800


class game
{
private:
	game_grid<DEFAULT_WIDTH, DEFAULT_HEIGHT> grid_;
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

