#include "myparticle.h"
#include <stdlib.h>


MyParticle::MyParticle() : Entity()
{
	math = new MyMath;

	this->addSprite("assets/particle.tga");
	this->sprite()->color = RED;

	int num1 = rand() % 360 + -180;
	int num2 = rand() % 360 + -180;
	Direction = Point2(num1, num2);
	Direction = math->Normalize(Direction);

	int color = rand() % 5 + 1;

	if(color == 1){ this->sprite()->color = RED; }
	if(color == 2){ this->sprite()->color = BLUE; }
	if(color == 3){ this->sprite()->color = YELLOW; }
	if(color == 4){ this->sprite()->color = GREEN; }
	if(color == 5){ this->sprite()->color = WHITE; }

	int size = rand() % 3 + 1;
	if (size == 1) { this->scale = Point2(1 ,1); }
	if (size == 2) { this->scale = Point2(1.5, 1.5); }
	if (size == 3) { this->scale = Point2(2, 2); }
}

MyParticle::~MyParticle()
{
	delete math;
}

void MyParticle::update(float deltaTime)
{
	this->position += Direction * 0.5 * deltaTime;

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
