#include "Room.h"

Room::Room(Ogre::SceneManager* mSceneMgr, Physics* physicsEngine){
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane(
    "wall",
    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    plane, 
    WALL_SIZE, WALL_SIZE, 20, 20, 
    true, 
    1, 5, 5, 
    Ogre::Vector3::UNIT_Z);

    Ogre::Entity* walls[NUM_WALLS];

    for(int i = 0; i < NUM_WALLS; i++){
        walls[i] = mSceneMgr->createEntity("wall");
        walls[i]->setMaterialName("Examples/Rockwall");
    }

    //FLOOR
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(walls[0]);
    CreateBulletWall(btVector3(0, 0, 0), btVector3(btScalar(WALL_SIZE),btScalar(1.),btScalar(WALL_SIZE)),physicsEngine);

    //CEILING
    Ogre::SceneNode* sceneForManip = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, WALL_SIZE, 0));
    sceneForManip->attachObject(walls[1]);
    sceneForManip->roll(Ogre::Degree(180));
    CreateBulletWall(btVector3(0, WALL_SIZE, 0), btVector3(btScalar(WALL_SIZE),btScalar(1.),btScalar(WALL_SIZE)),physicsEngine);

    //LEFT WALL
    sceneForManip = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(-WALL_SIZE/2, WALL_SIZE/2, 0));
    sceneForManip->attachObject(walls[2]);
    sceneForManip->roll(Ogre::Degree(-90));
    CreateBulletWall(btVector3(-WALL_SIZE/2, WALL_SIZE/2, 0), btVector3(btScalar(1.),btScalar(WALL_SIZE),btScalar(WALL_SIZE)),physicsEngine);

    //RIGHT WALL
    sceneForManip = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(WALL_SIZE/2, WALL_SIZE/2, 0));
    sceneForManip->attachObject(walls[3]);
    sceneForManip->roll(Ogre::Degree(90));
    CreateBulletWall(btVector3(WALL_SIZE/2, WALL_SIZE/2, 0), btVector3(btScalar(1.),btScalar(WALL_SIZE),btScalar(WALL_SIZE)),physicsEngine);


    //BACK WALL
    sceneForManip = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, WALL_SIZE/2, -WALL_SIZE/2));
    sceneForManip->attachObject(walls[4]);
    sceneForManip->pitch(Ogre::Degree(90));
    CreateBulletWall(btVector3(0, WALL_SIZE/2, -WALL_SIZE/2), btVector3(btScalar(WALL_SIZE),btScalar(WALL_SIZE),btScalar(1.0)),physicsEngine);

    //FRONT WALL
    sceneForManip = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, WALL_SIZE/2, WALL_SIZE/2));
    sceneForManip->attachObject(walls[5]);
    sceneForManip->pitch(Ogre::Degree(-90));
    CreateBulletWall(btVector3(0, WALL_SIZE/2, WALL_SIZE/2), btVector3(btScalar(WALL_SIZE),btScalar(WALL_SIZE),btScalar(1.0)),physicsEngine);
    CreateTarget(mSceneMgr, physicsEngine, sceneForManip);
}

Room::~Room(){

}


void Room::CreateBulletWall(btVector3 originVector, btVector3 shape, Physics* physicsEngine){
    btTransform groundTransform;
    groundTransform.setIdentity();
    groundTransform.setOrigin(originVector);
    btScalar groundMass(0.); //the mass is 0, because the ground is immovable (static)
    btVector3 localGroundInertia(0, 0, 0);
    btCollisionShape* groundShape = new btBoxShape(shape);
    btDefaultMotionState *groundMotionState = new btDefaultMotionState(groundTransform); 
    groundShape->calculateLocalInertia(groundMass, localGroundInertia);
    btRigidBody::btRigidBodyConstructionInfo groundRBInfo(groundMass, groundMotionState, groundShape, localGroundInertia);
    groundRBInfo.m_restitution  = 0.5f;
    groundRBInfo.m_friction = 1.0f;
    btRigidBody *groundBody = new btRigidBody(groundRBInfo);
    //add the body to the dynamics world
    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
    dynamicsWorld->addRigidBody(groundBody);
}

void Room::CreateTarget(Ogre::SceneManager* mSceneMgr, Physics* physicsEngine, Ogre::SceneNode* wallNode){

    Ogre::Entity* targetEntity = mSceneMgr->createEntity("wall");
    srand(time(NULL));
    float xvalue = ((float) rand()/RAND_MAX)*.8f-.4f;
    float zvalue = ((float) rand()/RAND_MAX)*.8f-.4f;
    xvalue = 0.0f;
    zvalue = 0.0f;
    targetEntity->setMaterialName("Examples/10PointBlock");
    Ogre::SceneNode* targetNode = wallNode->createChildSceneNode(Ogre::Vector3(xvalue*WALL_SIZE, 1, zvalue*WALL_SIZE));
    targetNode->scale(Ogre::Vector3(0.2, 0.2, 0.2));
    targetNode->attachObject(targetEntity);
}