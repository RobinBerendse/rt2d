/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "myentity.h"
#include "mypuck.h"
#include "mysquare.h"


/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	MyPuck* mypuck;
	MySquare* mysquare;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	int Distance(Point2, Point2);
	int Angle(Point2, Point2);
	Point2 RotateRadians(Point2, int);
	Point2 Normalize(Point2);
	float Magnitude(Point2);
	Point2 Rotate(Point2, float);
	Point2 Speed(Point2, int);
	double deg2rad(double);
};

#endif /* SCENE00_H */
