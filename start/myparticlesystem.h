/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYPARTICLESYSTEM_H
#define MYPARTICLESYSTEM_H

#include "myentity.h"

 /// @brief The MyEntity class is the Entity implementation.
class MyParticleSystem
{
public:
	/// @brief Constructor
	MyParticleSystem();
	/// @brief Destructor
	virtual ~MyParticleSystem();

	MyEntity* particle;
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYPARTICLESYSTEM_H */
