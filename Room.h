#ifndef __Room_h_
#define __Room_h_

#include "Physics.h"
#include <Ogre.h>
#include <time.h>

#define WALL_SIZE 1500
#define NUM_WALLS 6


class Room{

public:
	Room(Ogre::SceneManager*, Physics*);
	~Room();
	void CreateBulletWall(btVector3 originVector, btVector3 groundShape, Physics* physicsEngine);
	void CreateTarget(Ogre::SceneManager* mSceneMgr, Physics* physicsEngine, Ogre::SceneNode* wallNode);
};

#endif