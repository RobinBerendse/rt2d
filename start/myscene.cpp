/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
using namespace std;


#include <fstream>
#include <sstream>
#include "myscene.h"



MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);



	mypuck = new MyPuck();
	mypuck->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(mypuck);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
}
int MyScene::Angle(Point2 P1, Point2 P2) {
	double x = atan2(P1.y - P2.y, P1.x - P2.x);
	return x * 180 / 3.141;
}
int MyScene::Distance(Point2 P1, Point2 P2) {
	return sqrt(pow(P2.x - P1.x, 2) +pow(P2.y - P1.y, 2) * 1.0);
}

void MyScene::update(float deltaTime)
{
	//FOLLOW MOUSE
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);


	myentity->position = Point2(mouse);

	//std::cout << Distance(mouse, mypuck->position) << std::endl;
	std::cout << Angle(mouse, mypuck->position) << std::endl;

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
