#include "Game.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>



game::game(sf::Font& font, sf::RenderTarget& render_target)
	: font_(font), r_target_(render_target),
	food_(rand() % GRID_COLS, rand() % GRID_ROWS), ate_(0)
{
	snake_ = new snake();
}


game::~game()
{
	delete snake_;
}

float game::field_w() const
{
	const float width = r_target_.getViewport(r_target_.getView()).width;
	return width / GRID_COLS;
}
float game::field_h() const
{
	const float height = r_target_.getViewport(r_target_.getView()).height;
	return height / GRID_ROWS;
}

unsigned game::ate() const
{
	return ate_;
}

direction game::direction() const
{
	return snake_->snake_direction;
}

void game::input(const action action) const
{
	switch (action)
	{
		case action::left:
			if (snake_->snake_direction != direction::right)
				snake_->snake_direction = direction::left;
			break;
		case action::up:
			if (snake_->snake_direction != direction::down)
				snake_->snake_direction = direction::up;
			break;
		case action::right:
			if (snake_->snake_direction != direction::left)
				snake_->snake_direction = direction::right;
			break;
		case action::down:
			if (snake_->snake_direction != direction::up)
				snake_->snake_direction = direction::down;
			break;
		case action::boost:
			snake_->snake_direction = direction::down;
	}
}

void game::tick()
{
	snake_->move();

	point& head = snake_->buffer.at(0);
	if(head == food_)
	{
		ate_++;
		snake_->grow();
		food_.x = rand() % GRID_COLS;
		food_.y = rand() % GRID_ROWS;
	}
}

void game::update() const
{
	r_target_.clear(sf::Color::Black);
	const sf::IntRect view = r_target_.getViewport(r_target_.getView());

	if (paused)
	{
		// TODO: Better PAUSED Text
		sf::Text text("PAUSED - PRESS ESC TO RESUME", font_, 24);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(200, text.getCharacterSize() / 2);
		text.setPosition(view.width / 2, view.height / 10);
		r_target_.draw(text);
	}

	const float size_w = field_w();
	const float size_h = field_h();

	// Draw Snake
	for (const point& p : snake_->buffer)
	{
		sf::RectangleShape rectangle({ size_w, size_h });
		rectangle.setPosition(p.x * size_w, p.y * size_h);
		if (p == snake_->buffer.at(0)) rectangle.setFillColor(sf::Color::Red);
		r_target_.draw(rectangle);
	}
	// Draw food
	{
		sf::RectangleShape rectangle({ size_w, size_h });
		rectangle.setPosition(food_.x * size_w, food_.y * size_h);
		r_target_.draw(rectangle);
	}


	// Draw horizontal lines for grid
	for (int r = 0; r < GRID_ROWS; r++)
	{
		sf::Vertex h_line[] =
		{
			sf::Vertex(sf::Vector2f(r * size_h, 0)),
			sf::Vertex(sf::Vector2f(r * size_h, GRID_COLS * size_w))
		};
		r_target_.draw(h_line, 2, sf::Lines);
	}
	// Draw vertical lines for grid
	for (int c = 0; c < GRID_COLS; c++)
	{
		sf::Vertex v_line[] =
		{
			sf::Vertex(sf::Vector2f(0, c * size_h)),
			sf::Vertex(sf::Vector2f(GRID_ROWS * size_h, c * size_h))
		};

		r_target_.draw(v_line, 2, sf::Lines);
	}

	// TODO: Draw score

}
