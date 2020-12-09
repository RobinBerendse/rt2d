#include "mypuck.h"

MyPuck::MyPuck() : Entity()
{
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
}

MyPuck::~MyPuck()
{

}

void MyPuck::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
}
