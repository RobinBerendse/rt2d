using namespace std;

#include <fstream>
#include <sstream>
#include "myscene.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// make text
	Text* line = new Text();
	line->scale = Point2(0.5f, 0.5f);
	line->position = Point2(50, 50);
	text.push_back(line);

	// spawn Player
	myplayer = new MyPlayer();
	myplayer->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(myplayer);

	// spawn Map
	mymap = new MyMap();
	mymap->position = Point2(1220, -303);
	mymap->scale = Point2(1.2, 1);
	this->addChild(mymap);

	// say what puck is
	mypuck = new MyPuck(3);
	this->addChild(mypuck);

	// spawn enemy
	myEnemy = new MyEnemy();
	myEnemy->position = Point2(100, SHEIGHT / 2);
	this->addChild(myEnemy);

	// spawn Puck
	puckspawner();

	// update score
	updateScore();
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(mypuck);
	this->removeChild(myEnemy);
	this->removeChild(mymap);
	this->removeChild(myplayer);
	this->removeChild(text[0]);

	// delete from the heap (there was a 'new' in the constructor)
	delete mypuck;
	delete myEnemy;
	delete mymap;
	delete myplayer;
	delete text[0];

	// delete all particles
	RemoveParticles();
}

void MyScene::update(float deltaTime)
{
	if (math->Distance(myplayer->position, mypuck->position) < 63) {
		mypuck->Collision(myplayer->position);
		spawnParticles(mypuck->position);
	}
	if (math->Distance(myEnemy->position, mypuck->position) < 63) {
		mypuck->Collision(myEnemy->position);
		spawnParticles(mypuck->position);
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
	if (t.seconds() > 0.0633f) {
		RGBAColor color = mymap->sprite()->color;
		mymap->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}

	// GOAL PLAYER
	if (mypuck->position.x > SWIDTH - 45) {
		int height = SHEIGHT / 2;
		if (mypuck->position.y > height - 90) {
			if (mypuck->position.y < height + 118) {
				myEnemy->score += 1;
				goal();
			}
		}
	}

	// GOAL ENEMY
	if (mypuck->position.x < 45) {
		int height = SHEIGHT / 2;
		if (mypuck->position.y > height - 90) {
			if (mypuck->position.y < height + 118) {
				myplayer->score += 1;
				goal();
			}
		}
	}
	// Check if particle array is over 200 spots then remove 60
	if (particleArray.size() > 200) {
		for (size_t i = 0; i < 60; i++)
		{
			this->removeChild(particleArray[0]);
			delete particleArray[0];
			particleArray.erase(particleArray.begin());
		}
	}

	if (input()->getKeyUp(KeyCode::R)) {
		resetgame();
	}
}
void MyScene::goal() {
	puckspawner();
	RemoveParticles();
	updateScore();
}
void MyScene::resetgame() {
	// Set player scores to 0.
	myplayer->score = 0;
	myEnemy->score = 0;

	// Respawn puck
	puckspawner();

	// Update score
	updateScore();

	// Remove all particles.
	RemoveParticles();
}
void MyScene::RemoveParticles() {
	// Remove all particles.
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < particleArray.size(); j++)
		{
			this->removeChild(particleArray[0]);
			delete particleArray[0];
			particleArray.erase(particleArray.begin());
		}
	}
}
void MyScene::spawnParticles(Point2 pos) 
{
	// Spawn 20 particles
	for (size_t i = 0; i < 20; i++)
	{
		myparticle = new MyParticle();
		myparticle->position = Point2(pos);
		this->addChild(myparticle);
		particleArray.push_back(myparticle);
	}
}
void MyScene::updateScore()
{
	// Check if the 10 score is reached
	if (myplayer->score >= 10 || myEnemy->score >= 10) {
		resetgame();
	}

	std::string scoretext = "Goals  Player: " + std::to_string(myplayer->score) + " | Enemy: " + std::to_string(myEnemy->score) + "             First to 10 goals, R to restart";
	text[0]->message(scoretext);
	this->addChild(text[0]);
}
void MyScene::puckspawner() 
{
	// Remove existing puck
	this->removeChild(mypuck);
	delete mypuck;

	// Make and spawn new puck
	mypuck = new MyPuck(3);
	this->addChild(mypuck);

	// Switch bool
	spawnpoint = !spawnpoint;

	// Spawn at 2 diffrent places according to the bool
	if (spawnpoint) {
		mypuck->position = Point2(800, 150);
	}
	else {
		mypuck->position = Point2(800, 550);
	}
}
