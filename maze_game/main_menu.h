#pragma once

#include "game_state.h"

class main_menu : public tiny_state
{
public:
	main_menu();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	int selected;
	sf::Font font;
	sf::Text logo, play, quit, logo1;
	sf::Texture bback;
	sf::Sprite bg;

	sf::View cam_menu;


	sf::Music main_menu_tk1;
	sf::SoundBuffer sb, qb;
	sf::Sound start_button, event_button;
	int up, down;
};