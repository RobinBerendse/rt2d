/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
	this->sprite()->size = Point2(80, 80);
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{

	// ###############################################################
	// x
	// ###############################################################
}
