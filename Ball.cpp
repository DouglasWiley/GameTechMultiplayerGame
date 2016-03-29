#include "Ball.h"

Ball::Ball(Ogre::SceneManager* mSceneMgr): body(NULL){
    initOgreEntity(mSceneMgr);
}

Ball::Ball(Ogre::SceneManager* mSceneMgr, Physics* physicsEngine){
    initOgreEntity(mSceneMgr);
    initBulletBody(physicsEngine);
}

Ball::~Ball(){
	
}

void Ball::initOgreEntity(Ogre::SceneManager* mSceneMgr){
    Ogre::Entity* ballEnt;
    Ogre::Vector3 direction;
    Ogre::Real speed;

    ballNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, 500, 0));
    ballEnt = mSceneMgr->createEntity("sphere.mesh");
    ballNode->attachObject(ballEnt);
    ballNode->scale(BALL_SCALE, BALL_SCALE, BALL_SCALE);
    ballEnt->setCastShadows(true);
}

void Ball::initBulletBody(Physics* physicsEngine){
    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
    btCollisionShape *newRigidShape = new btSphereShape(BALL_SCALE*100);
    physicsEngine->getCollisionShapes().push_back(newRigidShape);
 
    //set the initial position and transform. For this demo, we set the tranform to be none
    btTransform startTransform;
    startTransform.setIdentity();

    btScalar mass = 0.8f;
    btVector3 localInertia(0,0,0);
 
    startTransform.setOrigin(btVector3(0,500,0));
    newRigidShape->calculateLocalInertia(mass, localInertia);
    MyMotionState* motionState = new MyMotionState(startTransform, ballNode);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, newRigidShape, localInertia);
    body = new btRigidBody(rbInfo);
    body->setRestitution(1.8);
    dynamicsWorld->addRigidBody(body);
    body->setGravity(btVector3(0,-200,0));
}

Ogre::SceneNode* Ball::getNode(){
    return ballNode;
}

btRigidBody* Ball::getBody(){
    return body;
}
