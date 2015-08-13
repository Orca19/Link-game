#pragma once

#include "entity.h"

class ExitDoor : public Entity
{
public:
	ExitDoor() : Entity("data/sprites/exit.png")
	{
		this->group_id = 5;
	}

	void Update()
	{
	}
};