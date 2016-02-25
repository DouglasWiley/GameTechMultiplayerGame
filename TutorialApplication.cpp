/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"

class MyMotionState : public btMotionState {
public:
    MyMotionState(const btTransform &initialpos, Ogre::SceneNode *node) {
        mVisibleobj = node;
        mPos1 = initialpos;
    }
    virtual ~MyMotionState() {    }
    void setNode(Ogre::SceneNode *node) {
        mVisibleobj = node;
    }
    virtual void getWorldTransform(btTransform &worldTrans) const {
        worldTrans = mPos1;
    }
    virtual void setWorldTransform(const btTransform &worldTrans) {
        if(NULL == mVisibleobj) return; // silently return before we set a node
        btQuaternion rot = worldTrans.getRotation();
        mVisibleobj->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
        btVector3 pos = worldTrans.getOrigin();
        // TODO **** XXX need to fix this up such that it renders properly since this doesnt know the scale of the node
        // also the getCube function returns a cube that isnt centered on Z
        mVisibleobj->setPosition(pos.x(), pos.y()+5, pos.z()-5);
    }
protected:
    Ogre::SceneNode *mVisibleobj;
    btTransform mPos1;
};
//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
    this->physicsEngine = new Physics();
    this->physicsEngine->initObjects();
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane(
    "ground",
    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    plane, 
    1500, 1500, 20, 20, 
    true, 
    1, 5, 5, 
    Ogre::Vector3::UNIT_Z);

    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setMaterialName("Examples/Rockwall");


    btTransform groundTransform;
    groundTransform.setIdentity();
    groundTransform.setOrigin(btVector3(0, -2, 0));
 
    btScalar groundMass(0.); //the mass is 0, because the ground is immovable (static)
    btVector3 localGroundInertia(0, 0, 0);
    btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(1500.),btScalar(1.),btScalar(1500.)));
    btDefaultMotionState *groundMotionState = new btDefaultMotionState(groundTransform);
 
    groundShape->calculateLocalInertia(groundMass, localGroundInertia);
 
    btRigidBody::btRigidBodyConstructionInfo groundRBInfo(groundMass, groundMotionState, groundShape, localGroundInertia);
    btRigidBody *groundBody = new btRigidBody(groundRBInfo);
 
    //add the body to the dynamics world
    btDiscreteDynamicsWorld* dynamicsWorld = this->physicsEngine->getDynamicsWorld();
    dynamicsWorld->addRigidBody(groundBody);
    Ogre::SceneNode* ballNode;
    Ogre::Entity* ballEnt;
    Ogre::Vector3 direction;
    Ogre::Real speed;

    ballNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0, 200, 0));
    ballEnt = mSceneMgr->createEntity("sphere.mesh");
    ballNode->attachObject(ballEnt);
    btCollisionShape *newRigidShape = new btSphereShape(100);
    this->physicsEngine->getCollisionShapes().push_back(newRigidShape);
 
    //set the initial position and transform. For this demo, we set the tranform to be none
    btTransform startTransform;
    startTransform.setIdentity();

    btScalar mass = 0.1f;
    btVector3 localInertia(0,0,0);
 
    startTransform.setOrigin(btVector3(0,250,0));
    newRigidShape->calculateLocalInertia(mass, localInertia);
    MyMotionState* motionState = new MyMotionState(startTransform, ballNode);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, newRigidShape, localInertia);
    btRigidBody *body = new btRigidBody(rbInfo);
    dynamicsWorld->addRigidBody(body);
    dynamicsWorld->setGravity(btVector3(0,-10,0));
 

}

void TutorialApplication::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(-25, 90, 30));
    mCamera->lookAt(Ogre::Vector3(0, 30, 0));
    mCamera->setNearClipDistance(5);
    mCamera->setFarClipDistance(1000);
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}
//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
