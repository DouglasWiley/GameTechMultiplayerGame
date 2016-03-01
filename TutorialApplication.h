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

//---------------------------------------------------------------------------

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
  int score;
  float time;
  OgreBites::TextBox* scoreDisplay;
  OgreBites::TextBox* timerDisplay;
  OgreBites::TextBox* endDisplay;
  bool processUnbufferedInput(const Ogre::FrameEvent& evt);

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
