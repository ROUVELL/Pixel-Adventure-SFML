#include <fstream>
#include <string>

#include "SFML/Graphics.hpp"
#include "json.hpp"


std::string ROOT_DIR;

class Game
{
public:
	Game() = default;

	bool init();
	void run();

private:
	sf::RenderWindow window;

	void processEvents();
	void update();
	void draw();
};

int main()
{
	Game game;

	if (!game.init())
		return -1;

	game.run();

	return 0;
}

bool Game::init()
{
	std::fstream configFile{ "config.json" };

	if (!configFile.is_open())
		return false;

	nlohmann::json config = nlohmann::json::parse(configFile);

	if (
		!config.is_object() ||
		!config.contains("screen_width") ||
		!config.contains("screen_height") ||
		!config.contains("root_dir")
		)
		return false;

	configFile.close();

	unsigned screenWidth = static_cast<unsigned>(config.value("screen_width", 1200));
	unsigned screenHegiht = static_cast<unsigned>(config.value("screen_height", 900));

	window.create(sf::VideoMode{ screenWidth, screenHegiht }, "", sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	return true;
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
