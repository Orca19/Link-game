#pragma once

#include "entity.h"

class Wall : public Entity
{
public:
	Wall() : Entity("data/sprites/wall_texture_2.png")
	{

		this->group_id = 2;


	}

	void Update()
	{

	}
};