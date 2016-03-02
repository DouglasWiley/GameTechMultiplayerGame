/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"
#include "btBulletDynamicsCommon.h"
#include "Physics.h"
#include "Room.h"
#include "Ball.h"
#include "Paddle.h"
#include "MyMotionState.h"
#include <sstream>
#include "SDL/SDL_mixer.h"

//---------------------------------------------------------------------------
struct MyContactResultCallback : public btCollisionWorld::ContactResultCallback
{
    MyContactResultCallback(int* scorePtr, float* timePtr, bool* soundOn) : context(scorePtr) , currentTimePtr(timePtr)
     , lastTimeSeen(*timePtr), soundOn(soundOn){
      collisionSound = Mix_LoadWAV("music/party.wav");
    }
    btScalar addSingleResult(btManifoldPoint& cp,
        const btCollisionObjectWrapper* colObj0Wrap,
        int partId0,
        int index0,
        const btCollisionObjectWrapper* colObj1Wrap,
        int partId1,
        int index1)
    {
      if(lastTimeSeen - *currentTimePtr > 1){
          (*context) += 10;
          lastTimeSeen = *currentTimePtr;
          if(*soundOn)
            Mix_PlayChannel(-1, collisionSound, 0);
        }
        // your callback code here
    }
    int* context;
    float* currentTimePtr;
    float lastTimeSeen;
    Mix_Chunk* collisionSound;
    bool* soundOn;
};

struct MyCollisionCallback : public btCollisionWorld::ContactResultCallback
{
    MyCollisionCallback(float* timePtr, char* soundName, bool* soundOn) : currentTimePtr(timePtr), lastTimeSeen(*timePtr), soundOn(soundOn){
      collisionSound = Mix_LoadWAV(soundName);
    }
    btScalar addSingleResult(btManifoldPoint& cp,
        const btCollisionObjectWrapper* colObj0Wrap,
        int partId0,
        int index0,
        const btCollisionObjectWrapper* colObj1Wrap,
        int partId1,
        int index1)
    {
      if(lastTimeSeen - *currentTimePtr > 1){
          lastTimeSeen = *currentTimePtr;
          if(*soundOn)
            Mix_PlayChannel(-1, collisionSound, 0);
        }
        // your callback code here
    }
    float* currentTimePtr;
    float lastTimeSeen;
    Mix_Chunk* collisionSound;
    bool* soundOn;
};

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);
    void setUpLighting();

private:
	Physics* physicsEngine;
  Paddle* paddle;
  Ball* ball;
  Room* ballRoom;
  int score;
  float time;
  bool soundOn;
  OgreBites::TextBox* scoreDisplay;
  OgreBites::TextBox* timerDisplay;
  OgreBites::TextBox* endDisplay;
  bool processUnbufferedInput(const Ogre::FrameEvent& evt);
  void placeIntInDisplay(OgreBites::TextBox*, const int num);
  MyContactResultCallback* targetCallback;
  MyCollisionCallback* paddleCallback;
  MyCollisionCallback* wallCallback;

protected:
    virtual void createScene(void);
    virtual void createCamera();
	  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    virtual bool keyPressed(const OIS::KeyEvent& arg);
    virtual bool keyReleased(const OIS::KeyEvent& arg);
};

//---------------------------------------------------------------------------

#endif // #ifndef __TutorialApplication_h_

//---------------------------------------------------------------------------
