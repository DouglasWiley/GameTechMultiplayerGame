#ifndef __Ball_h_
#define __Ball_h_

#include "Physics.h"
#include <Ogre.h>
#include "MyMotionState.h"

#define BALL_SCALE 0.5f

class Ball{
Ogre::SceneNode* ballNode;
btRigidBody* body;

public:
	Ball(Ogre::SceneManager*);
	Ball(Ogre::SceneManager*, Physics*);
	~Ball();
	
	void initOgreEntity(Ogre::SceneManager*);
	void initBulletBody(Physics*);
	Ogre::SceneNode* getNode();
	btRigidBody* getBody();
};

#endif