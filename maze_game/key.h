#pragma once

#include "entity.h"

class Key : public Entity
{
public:
	Key() : Entity("data/sprites/key.png")
	{
		this->group_id = 3;
		this->setOrigin(-16, -16);
		this->setScale(0.5f, 0.5f);
	}

	void Update()
	{
	}
};