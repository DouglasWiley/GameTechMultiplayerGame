#ifndef __Paddle_h_
#define __Paddle_h_

#include "Physics.h"
#include <Ogre.h>
#include "MyMotionState.h"

#define PADDLE_SCALE 1.5f

class Paddle{

public:
	Paddle(Ogre::SceneManager*, Physics*);
	~Paddle();
    Ogre::SceneNode* getNode(){
    	return PaddleNode;
    }
    btRigidBody* getBody(){
    	return body;
    }

private:
	Ogre::SceneNode* PaddleNode;
    Ogre::Entity* PaddleEnt;
    btRigidBody* body;
    float x, y, z;
	
};

#endif