#ifndef MYENEMY_H
#define MYENEMY_H

#include <rt2d/entity.h>

class MyEnemy : public Entity
{
public:
	/// @brief Constructor
	MyEnemy();
	/// @brief Destructor
	virtual ~MyEnemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Point2 puck;
	void puckpos(Point2);

	int score;

private:
	/* add your private declarations */
};

#endif /* MYENEMY_H */
