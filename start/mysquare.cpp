#include "mysquare.h"

MySquare::MySquare() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
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
