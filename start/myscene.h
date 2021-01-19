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
#include "myplayer.h"
#include "mymath.h"


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
	bool spawnpoint;

private:
	void puckspawner();
	/// @brief the rotating square in the middle of the screen
	MyPuck* mypuck;
	MyEntity* myEnemy;
	MySquare* mysquare;
	MyPlayer* myplayer;
	MyMath* math;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
