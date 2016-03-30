#include "Paddle.h"

Paddle::Paddle(Ogre::SceneManager* mSceneMgr, int nx, int ny, int nz): body(NULL), x(nx), y(ny), z(nz){
    initOgreEntity(mSceneMgr);
}

Paddle::Paddle(Ogre::SceneManager* mSceneMgr, Physics* physicsEngine, float nx, float ny, float nz): x(nx), y(ny), z(nz){
    initOgreEntity(mSceneMgr);
    initBulletBody(physicsEngine);
}

Paddle::~Paddle(){
	
}

void Paddle::initOgreEntity(Ogre::SceneManager* mSceneMgr){
    PaddleNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(x, y, z));
    PaddleEnt = mSceneMgr->createEntity("cube.mesh");
    PaddleNode->attachObject(PaddleEnt);
    PaddleNode->scale(PADDLE_SCALE, PADDLE_SCALE, PADDLE_SCALE*.1f);
}

void Paddle::initBulletBody(Physics* physicsEngine){
    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
   
    btCollisionShape *newRigidShape = new btBoxShape(btVector3(PADDLE_SCALE*50, PADDLE_SCALE*50, PADDLE_SCALE*5));
    physicsEngine->getCollisionShapes().push_back(newRigidShape);
 
    //set the initial position and transform. For this demo, we set the tranform to be none
    btTransform startTransform;
    startTransform.setIdentity();

    btScalar mass = 10000.0f;
    btVector3 localInertia(0,0,0);
 
    startTransform.setOrigin(btVector3(x, y, z));
    newRigidShape->calculateLocalInertia(mass, localInertia);
    MyMotionState* motionState = new MyMotionState(startTransform, PaddleNode);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, newRigidShape, localInertia);
    body = new btRigidBody(rbInfo);
    body->setRestitution(0.8);


    dynamicsWorld->addRigidBody(body);
    body->setGravity(btVector3(0,0,0));
    body->setAngularFactor(btVector3(0,0,0));
    body->forceActivationState(DISABLE_DEACTIVATION);
}

Ogre::SceneNode* Paddle::getNode(){
    return PaddleNode;
}

btRigidBody* Paddle::getBody(){
    return body;
}

void Paddle::move(int key){
    if (key == OIS::KC_S)
    {
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(vel.x(), -400, vel.z()));
    }
    else if (key == OIS::KC_W)
    {
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(vel.x(), 400, vel.z()));
    }
    else if (key == OIS::KC_A)
    {
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(400, vel.y(), vel.z()));
    }
    else if (key == OIS::KC_D)
    {
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(-400, vel.y(), vel.z()));
    }
}

void Paddle::stop(int key){
    if (key == OIS::KC_W || key == OIS::KC_S)
    {
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(vel.x(), 0, vel.z()));
    }
    else if (key == OIS::KC_A||key == OIS::KC_D)
    {
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(0, vel.y(), vel.z()));
    }
}