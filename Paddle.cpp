#include "Paddle.h"



Paddle::Paddle(Ogre::SceneManager* mSceneMgr, Physics* physicsEngine){
    x = 0;
    y = 500;
    z = -200;
	btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
    PaddleNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(x, y, z));
    PaddleEnt = mSceneMgr->createEntity("cube.mesh");
    PaddleNode->attachObject(PaddleEnt);
    PaddleNode->scale(PADDLE_SCALE, PADDLE_SCALE, PADDLE_SCALE*.1f);
    btCollisionShape *newRigidShape = new btBoxShape(btVector3(PADDLE_SCALE*50, PADDLE_SCALE*50, PADDLE_SCALE*5));
    physicsEngine->getCollisionShapes().push_back(newRigidShape);
 
    //set the initial position and transform. For this demo, we set the tranform to be none
    btTransform startTransform;
    startTransform.setIdentity();

    btScalar mass = 10000;
    btVector3 localInertia(0,0,0);
 
    startTransform.setOrigin(btVector3(x, y, z));
    newRigidShape->calculateLocalInertia(mass, localInertia);
    MyMotionState* motionState = new MyMotionState(startTransform, PaddleNode);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, newRigidShape, localInertia);
    body = new btRigidBody(rbInfo);
    body->setRestitution(1.5);


    dynamicsWorld->addRigidBody(body);
    body->setGravity(btVector3(0,0,0));
    body->setAngularFactor(btVector3(0,0,0));
}
Paddle::~Paddle(){
	
}