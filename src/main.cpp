#include "SFML/Graphics.hpp"


class Game
{
public:
	Game();

	void run();

private:
	sf::RenderWindow window;

	void processEvents();
	void update();
	void draw();
};

int main()
{
	Game().run();

	return 0;
}

Game::Game()
{
	window.create(sf::VideoMode{ 1200, 900 }, "", sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		draw();
	}
}

void Game::processEvents()
{
	static sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
			break;

		default:
			break;
		}
	}
}

void Game::update()
{
}

void Game::draw()
{
	window.clear();



	window.display();
}
