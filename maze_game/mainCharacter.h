#pragma once

#include "entity.h"

class mainCharacter : public Entity
{
public:
	mainCharacter() : Entity("data/sprites/character.png")
	{
		this->group_id = 1;
		this->keyCount = 0;
	}

	void Update()
	{
		const int v = 4;
		this->velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)*v) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)*v);
		this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)*v) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)*v);

		while (this->getPosition().x <= 0)
		{
			this->move(sf::Vector2f(1, 0));
		}
		while (this->getPosition().x + this->getGlobalBounds().width >= 9999)
		{
			this->move(sf::Vector2f(-1, 0));
		}
		while (this->getPosition().y <= 0)
		{
			this->move(sf::Vector2f(0, 1));
		}
		while (this->getPosition().y + this->getGlobalBounds().height >= 9999)
		{
			this->move(sf::Vector2f(0, -1));
		}

		Entity::Update();
	}

	void AddKey()
	{
		this->keyCount += 1;
	}

	void RemoveKey()
	{
		this->keyCount -= 1;
	}

	int KeyCount()
	{
		return this->keyCount;
	}


	void SetInitialPosition(float x, float y)
	{
		this->initialPosition = sf::Vector2f(x, y);
	}

	sf::Vector2f GetInitialPosition()
	{
		return this->initialPosition;
	}

private:
	sf::Vector2f initialPosition;
	int keyCount;
};