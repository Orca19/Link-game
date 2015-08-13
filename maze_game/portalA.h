#pragma once

#include "entity.h"

class PortalA : public Entity
{
public:
	PortalA() : Entity("data/sprites/portal.png")
	{

		this->group_id = 6;


	}

	void Update()
	{

	}
};