#ifndef MYMAP_H
#define MYMAP_H

#include <rt2d/entity.h>

class MyMap : public Entity
{
public:
	/// @brief Constructor
	MyMap();
	/// @brief Destructor
	virtual ~MyMap();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYMAP_H */