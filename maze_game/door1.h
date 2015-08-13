#pragma once

#include "entity.h"

class Door1 : public Entity
{
public:
	Door1() : Entity("data/sprites/door.png")
	{
		this->group_id = 9;
	}

	void Update()
	{
	}
};