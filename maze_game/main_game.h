#pragma once

#include "game_state.h"
#include "entity_manager.h"

class main_game : public tiny_state
{
public:
	main_game();
	void LoadLevel(std::string levelData[]);
	void LoadLevel1(std::string levelData[]);
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void DeleteLevel(std::string levelData[]);
	sf::Vector2u SizeWindow(sf::RenderWindow* window)
	{
		return window->getSize();
	}




private:
	EntityManager* manager;
	sf::View cam_lvl;
	sf::Vector2f position, position1;
	sf::Font font, font1;
	sf::Text info, info_key, info_mk, keys;
	sf::Texture bback;
	sf::Sprite bg;
	sf::Clock clock, clockA, clockB;
	sf::Time time, finish, portalA_time, portalA_ftime, portalB_time, portalB_ftime;
	sf::SoundBuffer st, fn;
	sf::Sound start, fin;
	sf::Music lvl0musc, lvl1musc, lvl2musc;

	int lvl;
	int count, cam_count, count_win;
	bool flag;
	float x, y;

};