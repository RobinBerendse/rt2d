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
	Point2 velocity;
	
	if (math->Distance(player, this->position) < 63) {
		velocity = this->position - player;
	}
	this->position += math->Speed(velocity, 1) * deltaTime * 50;
	this->position += math->Normalize(math->Rotate(this->position, math->Angle(this->position, player))) * deltaTime;

	// ###############################################################
	// Hit detection rand
	// ###############################################################
	int value = 35;
	if (this->position.x < value) {
		this->position.x = value;
	}
	if (this->position.x > SWIDTH - value) {
		this->position.x = SWIDTH - value;
	}
	if (this->position.y < value) {
		this->position.y = value;
	}
	if (this->position.y > SHEIGHT - value) {
		this->position.y = SHEIGHT - value;
	}
}

void MyPuck::playerpos(Point2 x) {
	player = x;
}
