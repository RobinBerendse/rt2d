#include "mypuck.h"

MyPuck::MyPuck(int x) : Entity()
{
	math = new MyMath;

	speed = x;
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
}

MyPuck::~MyPuck()
{
	delete math;
}

void MyPuck::update(float deltaTime)
{
	this->position += Direction * speed * deltaTime;
	// ###############################################################
	// Hit detection rand
	// ###############################################################
	int value = 43;
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
void MyPuck::Collision(Point2 object) {
	Point2 Difference = math->Subtract(this->position, object);
	Direction = math->Normalize(Difference);
	speed += 1;
	speed = math->Limit(speed, 25);
}
