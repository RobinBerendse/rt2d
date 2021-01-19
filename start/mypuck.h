#ifndef MYPUCK_H
#define MYPUCK_H

#include <rt2d/entity.h>
#include "mymath.h"

/// @brief The MyEntity class is the Entity implementation.
class MyPuck : public Entity
{
public:
	/// @brief Constructor
	MyPuck(int);
	/// @brief Destructor
	virtual ~MyPuck();
	MyMath* math;
	Point2 Direction;
	int speed;
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void Collision(Point2);

private:
	/* add your private declarations */
};

#endif /* MYPUCK_H */

