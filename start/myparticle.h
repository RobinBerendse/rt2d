#ifndef MYPARTICLE_H
#define MYPARTICLE_H

#include <rt2d/entity.h>
#include "mymath.h"

class MyParticle : public Entity
{
public:
	/// @brief Constructor
	MyParticle();
	/// @brief Destructor
	virtual ~MyParticle();

	MyMath* math;
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	Point2 Direction;
};

#endif /* MYPARTICLE_H */