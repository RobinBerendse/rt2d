#include "myenemy.h"
#include <math.h>

MyEnemy::MyEnemy() : Entity()
{
	score = 0;

	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
	this->sprite()->size = Point2(80, 80);
}

MyEnemy::~MyEnemy()
{
	
}

void MyEnemy::update(float deltaTime)
{
	if (this->position.y < puck.y && this->position.y < 500) {
		this->position.y += 200 * deltaTime;
	}
	if (this->position.y > puck.y && this->position.y > 200) {
		this->position.y -= 200 * deltaTime;
	}
}

void MyEnemy::puckpos(Point2 x) {
	puck = x;
}