#include "game_state.h"
#include "main_menu.h"

#include <Windows.h>


game_state coreState;
bool quitGame = false;
float timer;
sf::Clock clock_c;
int main()
{
	srand(NULL);
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Maze Game", sf::Style::Fullscreen);

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	while (window.isOpen())
	{
		timer = clock_c.getElapsedTime().asMilliseconds();
		timer = timer;
		clock_c.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		coreState.Update();

		window.display();

		if (quitGame)
		{
			window.close();
		}

		
	}

	return 0;
}








