#include <stdio.h>
#include <string>
#include "main_menu.h"
#include "main_game.h"
#include "winning_screen.h"
#include "mainCharacter.h"
#include "wall.h"
#include "key.h"
#include "door.h"
#include "door1.h"
#include "portalA.h"
#include "portalB.h"
#include "exit_door.h"
#include <Windows.h>
#include <iostream>
int lvl_check;

const int H = 11;
const int W = 11;
std::string testLevel[H] = {
	"22222222222",
	"21200020002",
	"20202020202",
	"20002020262",
	"22222020222",
	"20002020002",
	"20202020222",
	"20252000272",
	"20222222202",
	"20000000002",
	"22222222222"
};
const int h = 21;
const int w = 21;
std::string testLevel1[h] = {
	"222222222222222222222",
	"210020000000200000005",
	"222022202220222022202",
	"202020002020002020002",
	"202020222022202022202",
	"200020200000202090202",
	"202220202222202020202",
	"200000200000202020202",
	"222222202220202020222",
	"200003200020202020002",
	"202222222020202022202",
	"202000000020002000202",
	"202022222222222222202",
	"202000200000000000202",
	"202220222022222220202",
	"202000200020000000202",
	"202022202220222222202",
	"202020002000200000002",
	"202020222022702222202",
	"262000200000002000002",
	"222222222222222222222"
};



const int h2 = 41;
const int w2 = 41;
std::string testLevel2[h2] = {
	"22222222222222222222222222222222222222222",
	"21000000002000000000000000000000000000202",
	"26202222202222202222222022222023222222202",
	"20200000200000202000200020000000200722502",
	"20202220222220202020202222222222222022202",
	"20200020000020200020202000000000002000202",
	"20222222222020222220202022222222202022202",
	"20000000200020200020202000002020002000402",
	"22222220202220202020202222202020222022222",
	"20000020002020232020202000202020002000002",
	"22202222222020222020202020202022202222202",
	"20002000000020002020202020002000202000202",
	"20222022202222202020202022222220202020222",
	"20200020200000002000200000000000200020002",
	"20202220222222222222202222222220222222202",
	"20202000200020000000202000002000200000002",
	"20202020202020222220222022202222202222202",
	"20002020002000200000200020000000002000202",
	"20222022202222202222202222222222222020202",
	"20200020202000200000002000002000200020002",
	"20202220202020202222202022202020202222222",
	"20200020202320002000202000200020200020002",
	"20222020202222222020222220222220222020202",
	"20002000200000000020000000200020002020202",
	"22202022222022222220222222202022202022202",
	"20002020002000200020200000202000202000202",
	"20222220202222202020222220202020202220202",
	"20000020200000002020200020002020202020002",
	"22222020202222222020202022202020202022202",
	"20002020202000202020002000202020202000002",
	"20222020222020202022222220222022202222222",
	"20000020000020202020000020002000200000002",
	"20222220222220202022202022202020222222202",
	"20200000200020202000202000002020000020002",
	"20222220202020202220222022222220222220202",
	"20000020202020200020002020000000200000202",
	"22222022202020202222202020202222202222202",
	"20032000202000200000202000202000200000202",
	"20222220202222202220202222222020222220202",
	"20000000002000000020000000000020000000232",
	"22222222222222222222222222222222222222222",
};
bool portA = false;
bool portB = false;
bool won = false;

void UpdateCollisions(Entity* entityA, Entity* entityB)
{
	const float n = 2;
	Entity *tmp = new Entity;
	//tmp->setPosition(entityA->getPosition().x + 16, entityA->getPosition().y + 16);

	if (entityA->Group() == 1 && entityB->Group() == 2)
	{
		entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
	}

	if (entityA->Group() == 1 && entityB->Group() == 5)
	{
		entityA->setOrigin(16, 16);
		entityA->setPosition(entityB->getPosition().x + 16, entityB->getPosition().y + 16);

		won = true;
	}


	if (entityA->Group() == 1 && entityB->Group() == 3)
	{
		entityB->SetActive(0);
		((mainCharacter*)entityA)->AddKey();
	}
	if (entityA->Group() == 1 && entityB->Group() == 4)
	{

		mainCharacter* character = ((mainCharacter*)entityA);

		if (character->KeyCount() == 5)
		{
			entityB->SetActive(0);
			((mainCharacter*)entityA)->RemoveKey();
		}
		else
		{
			entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
		}

	}

	if (entityA->Group() == 1 && entityB->Group() == 9)
	{
		mainCharacter* character = ((mainCharacter*)entityA);


		if (character->KeyCount() > 0)
		{
			entityB->SetActive(0);
			((mainCharacter*)entityA)->RemoveKey();
		}
		else
		{
			entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
		}
	}

	if (entityA->Group() == 1 && entityB->Group() == 6)
	{
		portA = true;

	}
	if (entityA->Group() == 1 && entityB->Group() == 7)
	{
		portB = true;

	}



}

main_game::main_game()
{
	this->manager = new EntityManager();
}

void main_game::LoadLevel(std::string levelData[])
{
	if (lvl_check == 0)
	{
		std::string mainCharacterName = "mainCharacter";
		this->manager->AddEntity(mainCharacterName, new mainCharacter());

		for (int y = 0; y < H; y += 1)
		{
			for (int x = 0; x < W; x += 1)
			{
				std::string name = "";
				switch (levelData[y][x])
				{
				case '1':
					name = mainCharacterName;

					break;
				case '2':
					name = "wall";
					this->manager->AddEntity(name, new Wall());
					break;
				case '5':
					name = "exit_door";
					this->manager->AddEntity(name, new ExitDoor());
					break;
				case'6':
					name = "portalA";
					this->manager->AddEntity(name, new PortalA());
					break;
				case'7':
					name = "portalB";
					this->manager->AddEntity(name, new PortalB());
					break;
				default:
					continue;
				}
				this->manager->Get(name)->setPosition(x * 32 + 800, y * 32 + 700);
			}
		}
	}
	if (lvl_check == 1)
	{
		lvl = 1;
		std::string mainCharacterName = "mainCharacter";
		this->manager->AddEntity(mainCharacterName, new mainCharacter());

		for (int y = 0; y < h; y += 1)
		{
			for (int x = 0; x < w; x += 1)
			{
				std::string name = "";
				switch (levelData[y][x])
				{
				case '1':
					name = mainCharacterName;

					break;
				case '2':
					name = "wall";
					this->manager->AddEntity(name, new Wall());
					break;
				case '5':
					name = "exit_door";
					this->manager->AddEntity(name, new ExitDoor());
					break;
				case '3':
					name = "key";
					this->manager->AddEntity(name, new Key());
					break;
				case '9':
					name = "door1";
					this->manager->AddEntity(name, new Door1());
					break;
				case'6':
					name = "portalA";
					this->manager->AddEntity(name, new PortalA());
					break;
				case'7':
					name = "portalB";
					this->manager->AddEntity(name, new PortalB());
					break;
				default:
					continue;
				}
				this->manager->Get(name)->setPosition(x * 32 + 800, y * 32 + 700);
			}
		}
	}
	if (lvl_check == 2)
	{
		lvl = 2;
		std::string mainCharacterName = "mainCharacter";
		this->manager->AddEntity(mainCharacterName, new mainCharacter());

		for (int y = 0; y < h2; y += 1)
		{
			for (int x = 0; x < w2; x += 1)
			{
				std::string name = "";
				switch (levelData[y][x])
				{
				case '1':
					name = mainCharacterName;

					break;
				case '2':
					name = "wall";
					this->manager->AddEntity(name, new Wall());
					break;
				case '5':
					name = "exit_door";
					this->manager->AddEntity(name, new ExitDoor());
					break;
				case '3':
					name = "key";
					this->manager->AddEntity(name, new Key());
					break;
				case '4':
					name = "door";
					this->manager->AddEntity(name, new Door());
					break;
				case'6':
					name = "portalA";
					this->manager->AddEntity(name, new PortalA());
					break;
				case'7':
					name = "portalB";
					this->manager->AddEntity(name, new PortalB());
					break;
				default:
					continue;
				}
				this->manager->Get(name)->setPosition(x * 32 + 800, y * 32 + 700);
			}
		}
	}



}







void main_game::Initialize(sf::RenderWindow* window)
{



	this->st.loadFromFile("data/sound/start2.wav");
	this->start.setBuffer(st);
	fn.loadFromFile("data/sound/finish.wav");
	fin.setBuffer(fn);
	finish = sf::seconds(2);
	portalA_ftime = sf::seconds(2);
	portalB_ftime = sf::seconds(2);
	count = 0;
	cam_count = 0;
	count_win = 0;
	this->font.loadFromFile("data/fonts/Quaaludes-Regular.ttf");
	this->font1.loadFromFile("data/fonts/arial.ttf");

	this->position.x = SizeWindow(window).x / 2;
	this->position.y = SizeWindow(window).y / 2;
	cam_lvl.reset(sf::FloatRect(0, 0, SizeWindow(window).x, SizeWindow(window).y));
	cam_lvl.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	cam_lvl.zoom(0.1f);

	//бэкграунд
	this->bback.loadFromFile("data/sprites/1.png");
	this->bg.setTexture(bback);
	this->bg.setScale(4, 4);


	//найди выход 
	this->info = sf::Text("find a way out", font, 32U);
	this->info.setOrigin(this->info.getGlobalBounds().width / 2, 0);
	this->info.setPosition(980, 650);
	this->info.setColor(sf::Color(255, 143, 55));

	//используй ключ
	this->info_key = sf::Text("Use a key", font, 64U);
	this->info_key.setOrigin(this->info_key.getGlobalBounds().width / 2, 0);
	this->info_key.setPosition(1000, 625);
	this->info_key.setColor(sf::Color(255, 143, 55));

	//иногда одного ключа недостаточно
	this->info_mk = sf::Text("Sometimes one key is not enough", font, 32U);
	this->info_mk.setOrigin(this->info_mk.getGlobalBounds().width / 2, 0);
	this->info_mk.setPosition(1350, 650);
	this->info_mk.setColor(sf::Color(255, 143, 55));



	this->keys = sf::Text("0", font1, 40U);
	this->keys.setPosition(760, 690);
	this->keys.setColor(sf::Color(255, 143, 55));
	

	this->manager->SetCollisionMethod(UpdateCollisions);

	std::cout << lvl_check;
	if (lvl_check == 0)
	{
		this->lvl0musc.openFromFile("data/sound/lvl0.ogg");
		lvl0musc.setVolume(50);
		lvl0musc.play();
		lvl0musc.setLoop(true);
		this->LoadLevel(testLevel);
		lvl_check = 1;
	}
	else if (lvl_check == 1){
		this->lvl1musc.openFromFile("data/sound/lvl1.ogg");
		lvl1musc.setVolume(25);
		lvl1musc.play();
		lvl1musc.setLoop(true);
		this->LoadLevel(testLevel1);
		lvl_check = 2;
	}
	else
	{
		this->lvl1musc.openFromFile("data/sound/lvl2.ogg");
		lvl1musc.setVolume(50);
		lvl1musc.play();
		lvl1musc.setLoop(true);
		this->LoadLevel(testLevel2);
	}
	fin.play();
}
void main_game::Update(sf::RenderWindow* window)
{



	if (cam_count < 100)
	{
		this->manager->Get("mainCharacter")->setOrigin(-16, -16);
		this->manager->Get("mainCharacter")->setScale(0.5f, 0.5f);
		cam_lvl.zoom(1.022f);;
		cam_count++;
	}

	if (this->manager->Get("mainCharacter")->getPosition().x + 16 > 0)
	{
		position.x = this->manager->Get("mainCharacter")->getPosition().x + 16;
	}
	else
		position.x = 0;
	if (this->manager->Get("mainCharacter")->getPosition().y + 16 > 0)
	{
		position.y = this->manager->Get("mainCharacter")->getPosition().y + 16;
	}
	else
		position.y = 0;
	cam_lvl.setCenter(position);
	

	manager->Update_();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		lvl_check = 0;
		coreState.SetState(new main_menu());
	}
	
	if (portA)
	{

		this->manager->Get("mainCharacter")->setPosition(this->manager->Get("portalB")->getPosition().x, (this->manager->Get("portalB")->getPosition().y));
		this->manager->Get("mainCharacter")->move(0, 32);



		portB = false;
		portA = false;



	}
	if (portB)
	{

		this->manager->Get("mainCharacter")->setPosition(this->manager->Get("portalA")->getPosition().x, (this->manager->Get("portalA")->getPosition().y));

		this->manager->Get("mainCharacter")->move(0, -32);

		portB = false;
		portA = false;
	}

	if (won)
	{

		cam_lvl.setCenter(position.x - 16, position.y - 16);
		time = clock.getElapsedTime();

		this->manager->Get("mainCharacter")->scale(0.99f, 0.99f);
		
		cam_lvl.zoom(0.99f);

		if (time > finish)
		{

			fin.play();
			lvl0musc.stop();
			if (lvl == 2)
			{
				coreState.SetState(new winning_screen);

			}
			else
				coreState.SetState(new main_game);
		}
		won = false;

	}
	else
		time = clock.restart();

}
void main_game::Render(sf::RenderWindow* window)
{
	window->clear();
	this->keys.setString(std::to_string(((mainCharacter*)this->manager->Get("mainCharacter"))->KeyCount()));

	window->setVerticalSyncEnabled(true);

	window->setView(cam_lvl);
	window->draw(bg);

	if (lvl == 0)
	{

		window->draw(this->info);


	}
	if (lvl == 1)
	{
		window->draw(this->info_key);

	}
	if (lvl == 2)
	{
		window->draw(this->info_mk);

		window->draw(keys);
	}

	manager->Render(window);

}
void main_game::Destroy(sf::RenderWindow* window)
{
	time.Zero;

	window->getDefaultView();
	start.stop();
	fin.stop();
	start.~Sound();
	fin.~Sound();
	lvl0musc.stop();
	lvl1musc.stop();
	lvl2musc.stop();
	bback.~Texture();
	lvl0musc.~Music();
	lvl1musc.~Music();
	lvl2musc.~Music();
	font.~Font();
	font1.~Font();

	delete manager;
}