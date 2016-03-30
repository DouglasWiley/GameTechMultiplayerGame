#ifndef __Paddle_h_
#define __Paddle_h_

#include "Physics.h"
#include <Ogre.h>
#include "OIS.h"
#include "MyMotionState.h"

#define PADDLE_SCALE 4.0f
#define DEFAULT_X 0
#define DEFAULT_Y 750
#define DEFAULT_Z 0

class Paddle{

public:
    Paddle(Ogre::SceneManager*, int nx = DEFAULT_X, int ny = DEFAULT_Y, int nz = DEFAULT_Z);
	Paddle(Ogre::SceneManager*, Physics*, float nx = DEFAULT_X, float ny = DEFAULT_Y, float nz = DEFAULT_Z);
	~Paddle();
    void initOgreEntity(Ogre::SceneManager*);
    void initBulletBody(Physics*);
    void move(int);
    void stop(int);
    Ogre::SceneNode* getNode();
    btRigidBody* getBody();

private:
	Ogre::SceneNode* PaddleNode;
    Ogre::Entity* PaddleEnt;
    btRigidBody* body;
    float x, y, z;	
};

#endif
