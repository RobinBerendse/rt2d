#ifndef MYSQUARE_H
#define MYSQUARE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MySquare : public Entity
{
public:
	/// @brief Constructor
	MySquare();
	/// @brief Destructor
	virtual ~MySquare();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYSQUARE_H */