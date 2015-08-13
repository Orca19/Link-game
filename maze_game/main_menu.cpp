#include "main_menu.h"
#include <stdio.h>
#include "main_game.h"


main_menu::main_menu()
{
}

void main_menu::Initialize(sf::RenderWindow* window)
{

	cam_menu.setCenter(window->getSize().x / 2, window->getSize().y / 2);
	this->font.loadFromFile("data/fonts/Quaaludes-Regular.ttf");

	this->bback.loadFromFile("data/sprites/1.png");
	this->bg.setTexture(bback);
	this->bg.setScale(2, 2);


	this->main_menu_tk1.openFromFile("data/sound/main_menu_tk1.ogg");
	this->sb.loadFromFile("data/sound/1.wav");
	this->start_button.setBuffer(sb);
	this->qb.loadFromFile("data/sound/2.wav");
	this->event_button.setBuffer(qb);
	this->event_button.setVolume(5);

	main_menu_tk1.play();
	main_menu_tk1.setLoop(true);


	this->logo = sf::Text("Link", font, 100U);
	this->logo.setOrigin(this->logo.getGlobalBounds().width / 2, 0);
	this->logo.setPosition(window->getSize().x / 2, 0);



	this->play = sf::Text("PLAY", font, 64U);
	this->play.setOrigin(this->play.getGlobalBounds().width / 2, 0);
	this->play.setPosition(window->getSize().x / 2, window->getSize().y / 3);

	this->quit = sf::Text("QUIT", font, 64U);
	this->quit.setOrigin(this->quit.getGlobalBounds().width / 2, 0);
	this->quit.setPosition(window->getSize().x / 2, window->getSize().y / 3 + this->play.getGlobalBounds().height * 1.5f);
	this->selected = 0;



}
void main_menu::Update(sf::RenderWindow* window)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !down)
	{
		this->selected -= 1;
		this->event_button.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !up)
	{
		this->selected -= 1;
		this->event_button.play();
	}
	if (this->selected < 0)
	{
		this->selected = 1;
		this->event_button.play();

	}
	if (this->selected > 1)
	{
		this->selected = 0;
		this->event_button.play();

	}


	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{

		switch (this->selected)
		{
		case 0:

			start_button.play();

			coreState.SetState(new main_game());

			break;
		case 1:


			quitGame = true;
			break;
		}
	}



}
void main_menu::Render(sf::RenderWindow* window)
{

	this->logo.setColor(sf::Color(7, 156, 226));


	this->play.setColor(sf::Color(7, 156, 226));
	this->quit.setColor(sf::Color(7, 156, 226));



	switch (this->selected)
	{
	case 0:

		this->play.setColor(sf::Color(255, 143, 55));

		break;
	case 1:


		this->quit.setColor(sf::Color(255, 143, 55));
		break;
	}
	cam_menu.setSize(1920, 1080);
	window->setView(cam_menu);

	window->draw(this->bg);

	window->draw(this->logo);

	window->draw(this->play);

	window->draw(this->quit);






}
void main_menu::Destroy(sf::RenderWindow* window)
{
	main_menu_tk1.stop();
	main_menu_tk1.~Music();
	font.~Font();

}

