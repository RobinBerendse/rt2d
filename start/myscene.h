#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>

#include "myenemy.h"
#include "mypuck.h"
#include "mymap.h"
#include "myplayer.h"
#include "mymath.h"
#include "myparticle.h"


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
	void MyScene::puckspawner();
	void MyScene::updateScore();
	void MyScene::spawnParticles(Point2);
	void MyScene::resetgame();
	void MyScene::goal();
	void MyScene::RemoveParticles();

	std::vector<MyParticle*> particleArray;
	MyPuck* mypuck;
	MyEnemy* myEnemy;
	MyMap* mymap;
	MyPlayer* myplayer;
	MyMath* math;
	MyParticle* myparticle;

	Timer t;

	std::vector<Text*> text;
};

#endif /* MYSCENE_H */
