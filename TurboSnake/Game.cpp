#include "Game.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>



game::game(sf::Font& font, sf::RenderTarget& render_target)
	: font_(font), r_target_(render_target)
{
	snake_ = new snake();
}


game::~game()
{
	delete snake_;
}

float game::field_w() const
{
	const int width = r_target_.getViewport(r_target_.getView()).width;
	return width / GRID_COLS;
}
float game::field_h() const
{
	const int height = r_target_.getViewport(r_target_.getView()).height;
	return height / GRID_ROWS;
}

void game::input(action action)
{

}

void game::tick()
{
	snake_->move();
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
