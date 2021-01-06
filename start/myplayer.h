/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyPlayer : public Entity
{
public:
	/// @brief Constructor
	MyPlayer();
	/// @brief Destructor
	virtual ~MyPlayer();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	Point2 mouse;
	void mousepos(Point2);

private:
	/* add your private declarations */
};

#endif /* MYPLAYER_H */
