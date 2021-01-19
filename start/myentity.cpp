/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"
#include <math.h>

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
	this->sprite()->size = Point2(80, 80);
}

MyEntity::~MyEntity()
{
	//angle = (angle) * (Math.PI / 180); // Convert to radians	
}

void MyEntity::update(float deltaTime)
{
	Point2 rotated;
	Point2 center = Point2(10, 10);
	int angle = 1;
	rotated.x = cos(angle) * (puck.x - center.x) - sin(angle) * (puck.y - center.y) + center.x;
	rotated.y = sin(angle) * (puck.x - center.x) + cos(angle) * (puck.y - center.y) + center.y;
	this->position = rotated;
	//this->position.y = puck.y;
	//this->position.x = 1;
	
	// ###############################################################
	// x
	// ###############################################################
}

void MyEntity::puckpos(Point2 x) {
	puck = x;
}