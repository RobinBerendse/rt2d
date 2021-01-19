/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myplayer.h"

//Point2 mouse;

MyPlayer::MyPlayer() : Entity()
{
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
	this->sprite()->size = Point2(80, 80);
}

MyPlayer::~MyPlayer()
{

}

void MyPlayer::update(float deltaTime)
{
	if (mouse.x > 650) {
		this->position.x = mouse.x;
	}
	this->position.y = mouse.y;

	
}
void MyPlayer::mousepos(Point2 x) {
	mouse = x;
}