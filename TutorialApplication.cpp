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


bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    // Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    mTrayMgr->frameRenderingQueued(evt);

    physicsEngine->getDynamicsWorld()->stepSimulation(evt.timeSinceLastFrame, 60);

    float newx, newy, newz;
    btRigidBody* body =  ball->getBody();
    btVector3 vel = body->getLinearVelocity();
    float maxSpeed = 600; 
    float minSpeed = 200; 
    newx=vel.x();
    newy=vel.y();
    newz=vel.z();
    if (vel.z()<0)
        newz=-400;
    else if (vel.z()>0)
        newz=400;
    if (vel.x()<-maxSpeed)
        newx=-maxSpeed;
    else if (vel.x()>maxSpeed)
        newx=maxSpeed;
    if (vel.y()<-maxSpeed)
        newy=-maxSpeed;
    else if (vel.y()>maxSpeed)
        newy=maxSpeed;
    body->setLinearVelocity(btVector3(newx, newy, newz));

    if (!mTrayMgr->isDialogVisible())
    {
        mCameraMan->frameRenderingQueued(evt);   // If dialog isn't up, then update the camera
        if (mDetailsPanel->isVisible())          // If details panel is visible, then update its contents
        {
            mDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(mCamera->getDerivedPosition().x));
            mDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(mCamera->getDerivedPosition().y));
            mDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(mCamera->getDerivedPosition().z));
            mDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().w));
            mDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().x));
            mDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().y));
            mDetailsPanel->setParamValue(7, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().z));
        }
    }

    

    if(time <= 0){
        if(!endDisplay){
            endDisplay = mTrayMgr->createTextBox(OgreBites::TL_CENTER, "End Display", ("GAME OVER"), 1920, 1080);
        }
        scoreDisplay->hide();
        timerDisplay->hide();
        paddle->getBody()->setLinearVelocity(btVector3(0,0,0));
        ball->getBody()->setLinearVelocity(btVector3(0,0,0));
        ball->getBody()->setGravity(btVector3(0,0,0));
    }
    else{
        std::ostringstream convert;
        convert << score;
        scoreDisplay->setText(convert.str());

        time -= evt.timeSinceLastFrame;
        std::ostringstream convert2;
        convert2 << ((int) time);
        timerDisplay->setText(convert2.str());
    }

    return true;
}
//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    score = 0;
    time = 10;
    endDisplay = 0;
    setUpLighting();
    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
    Room* ballRoom = new Room(mSceneMgr, physicsEngine);
    paddle = new Paddle(mSceneMgr, physicsEngine);
    ball = new Ball(mSceneMgr, physicsEngine);
    ball->getBody()->setLinearVelocity(btVector3(200, 0, -200));
    paddle->getNode()->createChildSceneNode(Ogre::Vector3(0, 0,0))->attachObject(mCamera);
    //Setup Score
    scoreDisplay = mTrayMgr->createTextBox(OgreBites::TL_TOPLEFT, "Score", ("Score"), 100, 100);
    std::ostringstream convert;
    convert << score;
    scoreDisplay->setText(convert.str());

    timerDisplay = mTrayMgr->createTextBox(OgreBites::TL_TOPLEFT, "Timer", ("Time Left:"), 100, 100);
    std::ostringstream convert2;
    convert2 << time;
    timerDisplay->setText(convert2.str());

}

void TutorialApplication::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(-750, 750, -750));
    mCamera->lookAt(Ogre::Vector3(750, -750, 750));
    mCamera->setNearClipDistance(5);
    mCamera->setFarClipDistance(4000);
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

void TutorialApplication::setUpLighting()
{
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
    Ogre::Light* rLight = mSceneMgr->createLight( "rLight" );
    Ogre::Light* gLight = mSceneMgr->createLight( "gLight" );
    Ogre::Light* bLight = mSceneMgr->createLight( "bLight" );
    rLight->setType(Ogre::Light::LT_POINT);
    rLight->setPosition(0,400,0);
    rLight->setDiffuseColour(1,0,0);
    rLight->setSpecularColour(1,0,0);
    gLight->setType(Ogre::Light::LT_POINT);
    gLight->setPosition(-350,-250,0);
    gLight->setDiffuseColour(0,1,0);
    gLight->setSpecularColour(0,1,0);
    bLight->setType(Ogre::Light::LT_POINT);
    bLight->setPosition(350,-250,0);
    bLight->setDiffuseColour(0,0,1);
    bLight->setSpecularColour(0,0,1);
}



bool TutorialApplication::processUnbufferedInput(const Ogre::FrameEvent& fe){
    return true;
}

bool TutorialApplication::keyPressed( const OIS::KeyEvent &arg )
{


    if (mTrayMgr->isDialogVisible()) return true;   // don't process any more keys if dialog is up

    /*if (arg.key == OIS::KC_F)   // toggle visibility of advanced frame stats
    {
        mTrayMgr->toggleAdvancedFrameStats();
    }
    else */
    else if (arg.key == OIS::KC_S)
    {
        btRigidBody* body =  paddle->getBody();
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(vel.x(), -400, vel.z()));
    }
    else if (arg.key == OIS::KC_W)
    {
        btRigidBody* body =  paddle->getBody();
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(vel.x(), 400, vel.z()));
    }
    else if (arg.key == OIS::KC_A)
    {
    btRigidBody* body =  paddle->getBody();
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(400, vel.y(), vel.z()));
    }
    else if (arg.key == OIS::KC_D)
    {
        btRigidBody* body =  paddle->getBody();
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(-400, vel.y(), vel.z()));
    }
    else if (arg.key == OIS::KC_G)   // toggle visibility of even rarer debugging details
    {
        if (mDetailsPanel->getTrayLocation() == OgreBites::TL_NONE)
        {
            mTrayMgr->moveWidgetToTray(mDetailsPanel, OgreBites::TL_TOPRIGHT, 0);
            mDetailsPanel->show();
        }
        else
        {
            mTrayMgr->removeWidgetFromTray(mDetailsPanel);
            mDetailsPanel->hide();
        }
    }
    else if(arg.key == OIS::KC_F5)   // refresh all textures
    {
        Ogre::TextureManager::getSingleton().reloadAll();
    }
    else if (arg.key == OIS::KC_ESCAPE)
    {
        mShutDown = true;
    }

    //mCameraMan->injectKeyDown(arg);
    return true;
}

bool TutorialApplication::keyReleased( const OIS::KeyEvent &arg )
{   
    if (arg.key == OIS::KC_W || arg.key == OIS::KC_S)
    {
       btRigidBody* body =  paddle->getBody();
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(vel.x(), 1, vel.z()));
    }
    else if (arg.key == OIS::KC_A||arg.key == OIS::KC_D)
    {
        btRigidBody* body =  paddle->getBody();
       btVector3 vel = body->getLinearVelocity();
       body->setLinearVelocity(btVector3(1, vel.y(), vel.z()));
    }
    return true;
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
