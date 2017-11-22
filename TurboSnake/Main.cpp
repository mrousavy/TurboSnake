#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include "Game.h"
#include "Structures.h"


#define GAME_VERSION "1.0"
#define DEFAULT_WIDTH 500
#define DEFAULT_HEIGHT 500
#define DEFAULT_GAME_SPEED 250


/// \brief Set the window's title to "TurboSnake - HxW"
void set_title(sf::RenderWindow& window, const int height, const int width)
{
	const std::string title = "TurboSnake - " + std::to_string(height) + "x" + std::to_string(width);
	window.setTitle(title);
}


/// \brief Print info about Snake, OpenGL and SFML
void print_info(sf::RenderWindow& window)
{
	const sf::ContextSettings& settings = window.getSettings();
	std::cout << "TurboSnake version:   " << GAME_VERSION << std::endl;
	std::cout << "SFML version:         " << SFML_VERSION_MAJOR << "." << SFML_VERSION_MAJOR << SFML_VERSION_PATCH << std::endl;
	std::cout << "OpenGL version:       " << settings.majorVersion << "." << settings.minorVersion << std::endl;
}

/// \brief Load the Snake window icon from file
void load_icon(sf::RenderWindow& window)
{
	//sf::Uint8 pixels[100];

	//window.setIcon(10, 10, pixels);
}


/// \brief The actual game loop (tick) of Snake
void game_loop(game* game)
{
	sf::Time tick_time = sf::milliseconds(DEFAULT_GAME_SPEED); // Time of a tick

	while (true)
	{
		game->tick();

		sleep(tick_time);
	}
}


/// \brief Handle user key input
void handle_key(const sf::Keyboard::Key key, game& game)
{
	switch (key)
	{
		case sf::Keyboard::Key::Left:
		case sf::Keyboard::Key::A:
			game.input(action::left);
			break;
		case sf::Keyboard::Key::Up:
		case sf::Keyboard::Key::W:
			game.input(action::up);
			break;
		case sf::Keyboard::Key::Right:
		case sf::Keyboard::Key::D:
			game.input(action::right);
			break;
		case sf::Keyboard::Key::Down:
		case sf::Keyboard::Key::S:
			game.input(action::down);
			break;
		case sf::Keyboard::Key::Space:
		case sf::Keyboard::Key::LShift:
			game.input(action::boost);
			break;
		case sf::Keyboard::Key::Escape:
			game.paused = !game.paused; // Toggle game pause state
		default: break;
	}
}


/// \brief Actual main game loop updating the window
int main(int argv, char** argc)
{
	srand(static_cast<unsigned>(time(nullptr)));
	sf::RenderWindow window(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "Loading..");
	window.setFramerateLimit(60);

	sf::Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		std::cout << "Could not load font arial.ttf!" << std::endl;
	}

	game game(font, window);
	set_title(window, DEFAULT_HEIGHT, DEFAULT_WIDTH);
	print_info(window);
	load_icon(window);

	sf::Thread thread(&game_loop, &game);			// Launch a parellel worker which ticks every 700ms
	thread.launch();

	while (window.isOpen())							// Main game loop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:				// Handle User input for window closing
					window.close();
					thread.terminate();
					break;
				case sf::Event::LostFocus:			// Handle User input for pausing/resuming
					game.paused = true;
					break;
				case sf::Event::GainedFocus:		// Handle User input for pausing/resuming
					game.paused = false;
					break;
				case sf::Event::Resized:
					set_title(window, event.size.height, event.size.width);
					if (event.size.width != event.size.height)	// Auto resize to keep 16:9 aspect ratio
						window.setSize({ event.size.height, event.size.height });
				case sf::Event::KeyPressed:			// Handle User input for block moving
					handle_key(event.key.code, game);
				default:
					break;
			}
		}

		game.update(); // Finally, let the game handle this frame update and draw all blocks
		window.display();
	}

	return 0;
}
