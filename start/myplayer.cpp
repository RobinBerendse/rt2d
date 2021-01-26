#include "myplayer.h"


MyPlayer::MyPlayer() : Entity()
{
	score = 0;

	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
	this->sprite()->size = Point2(80, 80);
}

MyPlayer::~MyPlayer()
{

}

void MyPlayer::update(float deltaTime)
{
	if (mouse.x > 690) {
		this->position.x = mouse.x;
	}
	this->position.y = mouse.y;

	
}
void MyPlayer::mousepos(Point2 x) {
	mouse = x;
}