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

	mypuck = new MyPuck(3);
	this->addChild(mypuck);

	myEnemy = new MyEntity();
	myEnemy->position = Point2(100, SHEIGHT / 2);
	this->addChild(myEnemy);

	mysquare = new MySquare();
	mysquare->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	mysquare->scale = Point2(10.8, 6);
	this->addChild(mysquare);

	puckspawner();
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(mypuck);

	// delete from the heap (there was a 'new' in the constructor)
	delete mypuck;
}

void MyScene::update(float deltaTime)
{
	if (math->Distance(myplayer->position, mypuck->position) < 63) {
		mypuck->Collision(myplayer->position);
	}
	if (math->Distance(myEnemy->position, mypuck->position) < 63) {
		mypuck->Collision(myEnemy->position);
	}
	
	//Make point2 from mouse pos
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	myplayer->mousepos(mouse);
	myEnemy->puckpos(mypuck->position);
	
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

	//GOALS
	if (mypuck->position.x > SWIDTH - 45) {
		int height = SHEIGHT / 2;
		if (mypuck->position.y > height - 80) {
			if (mypuck->position.y < height + 80) {
				//std::cout << mypuck->position << "\n";
				delete mypuck;
				mypuck = new MyPuck(3);
				this->addChild(mypuck);
				puckspawner();
			}
		}
	}
}

void MyScene::puckspawner() {
	spawnpoint = !spawnpoint;
	if (spawnpoint) {
		mypuck->position = Point2(800, 150);
	}
	else {
		mypuck->position = Point2(800, 550);
	}
}
