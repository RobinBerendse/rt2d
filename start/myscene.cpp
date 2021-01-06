using namespace std;


#include <fstream>
#include <sstream>
#include "myscene.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	myplayer = new MyPlayer();
	myplayer->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(myplayer);

	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	this->addChild(myentity);


	mypuck = new MyPuck();
	mypuck->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(mypuck);

	myEnemy = new MyEntity();
	myEnemy->position = Point2(100, SHEIGHT / 2);
	this->addChild(myEnemy);


	mysquare = new MySquare();
	mysquare->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	mysquare->scale = Point2(10.8, 6);
	this->addChild(mysquare);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(mypuck);
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete mypuck;
	delete myentity;
}

void MyScene::update(float deltaTime)
{
	if (math->Distance(myplayer->position, mypuck->position) < 63) {
		mypuck->Collision(true);
	}
	
	//Make point2 from mouse pos
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	myplayer->mousepos(mouse);
	mypuck->playerpos(myplayer->position);


	myEnemy->position.y = mypuck->position.y;
	//std::cout << Distance(mouse, mypuck->position) << std::endl;
	//std::cout << Angle(mouse, mypuck->position) << std::endl;
	//velocity = RotateRadians(mypuck->position, Angle(mouse, mypuck->position));
	
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myplayer->sprite()->color;
		myplayer->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
