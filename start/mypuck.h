#ifndef MYPUCK_H
#define MYPUCK_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyPuck : public Entity
{
public:
	/// @brief Constructor
	MyPuck();
	/// @brief Destructor
	virtual ~MyPuck();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYPUCK_H */

