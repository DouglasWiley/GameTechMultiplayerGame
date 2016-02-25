#ifndef __Physics_h_
#define __Physics_h_

#include "btBulletDynamicsCommon.h"
#include <map>
#include <vector>
#include <string>

class Physics{
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
	std::vector<btCollisionShape *> collisionShapes;
	std::map<std::string, btRigidBody *> physicsAccessors;
public:
	void initObjects();
	btDiscreteDynamicsWorld* getDynamicsWorld();
	std::vector<btCollisionShape *> getCollisionShapes();
};

#endif