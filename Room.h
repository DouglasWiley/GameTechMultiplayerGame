#ifndef __Room_h_
#define __Room_h_

#include "Physics.h"
#include <Ogre.h>
#include <time.h>

#define WALL_SIZE 1500
#define NUM_WALLS 6


class Room{
private:
	btRigidBody* targetBody;
	btRigidBody** wallBodyArray;
	Ogre::SceneNode* targetWall;

public:
	Room(Ogre::SceneManager*);
	Room(Ogre::SceneManager*, Physics*);
	~Room();
	void initOgreEntity(Ogre::SceneManager*);
	void initBulletBody(Physics*);
	void createTargetEntity(Ogre::SceneManager*, Ogre::SceneNode*);
	void createTargetBody(Physics*);
	void createTarget(Ogre::SceneManager*, Physics*);
	btRigidBody* CreateBulletWall(btVector3 originVector, btVector3 groundShape, Physics* physicsEngine);
	btRigidBody* getTargetBody() { return targetBody; };
	btRigidBody** getWallBodyArray() { return wallBodyArray; }
};

#endif