#include "Game.h"
#include <SFML/Graphics/Text.hpp>


float game::field() const
{
	const int width = window_.getViewport(window_.getView()).width;
	return width / GRID_ROWS;
}

game::game(sf::Font& font, sf::RenderTarget& render_target)
	: font_(font), r_target_(render_target)
{
	snake_ = new snake();
}


game::~game()
{
}

void game::input(action action)
{

}

void game::tick()
{
}

void game::update() const
{
	window_.clear(sf::Color::Black);
	const sf::IntRect view = window_.getViewport(window_.getView());

	if (paused)
	{
		// TODO: Better PAUSED Text
		sf::Text text("PAUSED - PRESS ESC TO RESUME", font_, 24);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(200, text.getCharacterSize() / 2);
		text.setPosition(view.width / 2, view.height / 10);
		window_.draw(text);
	}

	// TODO: Draw snake
	// TODO: Draw score

	window_.display();
}
