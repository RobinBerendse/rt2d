#include "mypuck.h"

MyPuck::MyPuck() : Entity()
{
	Direction = Point2(0, 0);
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
}

MyPuck::~MyPuck()
{

}

void MyPuck::update(float deltaTime)
{
	
	this->position += Direction * 10 * deltaTime;
	//this->position += math->Speed(velocity, 1) * deltaTime * 50;
	//this->position += math->Normalize(math->Rotate(this->position, math->Angle(this->position, player))) * deltaTime;

	// ###############################################################
	// Hit detection rand
	// ###############################################################
	int value = 35;
	if (this->position.x < value) {
		Direction.x = -Direction.x;
		this->position.x = value;
	}
	if (this->position.x > SWIDTH - value) {
		Direction.x = -Direction.x;
		this->position.x = SWIDTH - value;
	}
	if (this->position.y < value) {
		Direction.y = -Direction.y;
		this->position.y = value;
	}
	if (this->position.y > SHEIGHT - value) {
		Direction.y = -Direction.y;
		this->position.y = SHEIGHT - value;
	}
}
void MyPuck::Collision(bool x) {
	Point2 Difference = math->Subtract(this->position, player);
	Direction = math->Normalize(Difference);
}

void MyPuck::playerpos(Point2 x) {
	player = x;
}
