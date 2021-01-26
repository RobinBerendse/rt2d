#include "mymap.h"

MyMap::MyMap() : Entity()
{
	this->addSprite("assets/map.tga");
	this->sprite()->color = BLUE;
}

MyMap::~MyMap()
{

}

void MyMap::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
}
