#include "winning_screen.h"
#include "main_menu.h"

winning_screen::winning_screen()
{
}

void winning_screen::Initialize(sf::RenderWindow* window)
{
	this->bback.loadFromFile("data/sprites/1.png");
	this->bg.setTexture(bback);
	this->bg.setScale(2, 2);

	this->cake.loadFromFile("data/sprites/wincake.png");
	this->win_cake.setTexture(cake);
	this->win_cake.setOrigin(this->win_cake.getGlobalBounds().width / 2, 0);
	this->win_cake.setPosition(window->getSize().x / 2, window->getSize().y / 2 - 300);



	cam_win.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
	cam_win.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	cam_win.zoom(1.0f);
	this->font.loadFromFile("data/fonts/Quaaludes-Regular.ttf");

	this->winner = sf::Text("You Win", font, 64U);
	this->winner.setOrigin(this->winner.getGlobalBounds().width / 2, 0);
	this->winner.setPosition(window->getSize().x / 2, window->getSize().y / 4 - 200);
	this->winner.setColor(sf::Color(255, 143, 55));

	this->winm.openFromFile("data/sound/winm.ogg");
	winm.setVolume(50);
	winm.play();
	winm.setLoop(true);
}
void winning_screen::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.SetState(new main_menu());
	}
}
void winning_screen::Render(sf::RenderWindow* window)
{
	window->clear();
	window->draw(bg);
	window->draw(win_cake);
	window->setView(cam_win);
	window->draw(this->winner);

}
void winning_screen::Destroy(sf::RenderWindow* window)
{
	winm.stop();
	winm.~Music();
}