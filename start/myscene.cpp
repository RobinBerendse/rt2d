/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
using namespace std;


#include <fstream>
#include <sstream>
#include "myscene.h"
#include <cmath>


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	this->addChild(myentity);


	mypuck = new MyPuck();
	mypuck->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(mypuck);


	mysquare = new MySquare();
	mysquare->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	mysquare->scale = Point2(10.8, 6);
	this->addChild(mysquare);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(mypuck);
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete mypuck;
	delete myentity;
}
float MyScene::Magnitude(Point2 P1) {
	return sqrt((P1.x * P1.x) + (P1.y * P1.y));
}
Point2 MyScene::Normalize(Point2 P1) {
	float length = Magnitude(P1);
	P1.x / length;
	P1.y / length;
	return P1;
}
Point2 MyScene::Rotate(Point2 v, float degrees) {
	float xsin = sin(deg2rad(degrees));
	float xcos = cos(deg2rad(degrees));

	float tx = v.x;
	float ty = v.y;
	v.x = (xcos * tx) - (xsin * ty);
	v.y = (xsin * tx) + (xcos * ty);
	return v;
}
double MyScene::deg2rad(double degrees) {
	return degrees * 4.0 * atan(1.0) / 180.0;
}
int MyScene::Angle(Point2 P1, Point2 P2) {
	double x = atan2(P1.y - P2.y, P1.x - P2.x);
	return x * 180 / 3.141;
}
Point2 MyScene::RotateRadians(Point2 P1, int rot) {
	double ca = cos(rot);
	double sa = sin(rot);
	Point2 result = Point2(ca * P1.x - sa * P1.y, sa * P1.x + ca * P1.y);
	return result;
}
int MyScene::Distance(Point2 P1, Point2 P2) {
	return sqrt(pow(P2.x - P1.x, 2) +pow(P2.y - P1.y, 2) * 1.0);
}
Point2 MyScene::Speed(Point2 P1, int speed) {
	Point2 result = Point2(P1.x * speed, P1.y * speed);
	return result;
}
void MyScene::update(float deltaTime)
{
	//FOLLOW MOUSE
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);
	myentity->position = Point2(mouse);

	//std::cout << Distance(mouse, mypuck->position) << std::endl;
	//std::cout << Angle(mouse, mypuck->position) << std::endl;
	//velocity = RotateRadians(mypuck->position, Angle(mouse, mypuck->position));
	Point2 velocity;

	if (Distance(myentity->position, mypuck->position) < 63) {
		velocity = mypuck->position - myentity->position;
	}
	mypuck->position += Speed(velocity, 1) * deltaTime * 50;
	mypuck->position += Normalize(Rotate(mypuck->position, Angle(mypuck->position, myentity->position))) * deltaTime;
	
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
