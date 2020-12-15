#include "mysquare.h"

MySquare::MySquare() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
}

MySquare::~MySquare()
{

}

void MySquare::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
}
