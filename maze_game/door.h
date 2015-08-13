#pragma once

#include "entity.h"

class Door : public Entity
{
public:
	Door() : Entity("data/sprites/door.png")
	{
		this->group_id = 4;
	}

	void Update()
	{
	}
};