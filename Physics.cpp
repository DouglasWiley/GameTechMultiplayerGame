#include "Physics.h"

void Physics::initObjects() {
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		overlappingPairCache = new btDbvtBroadphase();
		solver = new btSequentialImpulseConstraintSolver();
		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
}

btDiscreteDynamicsWorld* Physics::getDynamicsWorld(){
	return dynamicsWorld;
}

std::vector<btCollisionShape *> Physics::getCollisionShapes(){
	return collisionShapes;
}