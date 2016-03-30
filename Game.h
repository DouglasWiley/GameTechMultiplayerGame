#ifndef __GAME_H__
#define __GAME_H__

#include <Ogre.h>
#include "Ball.h"
#include "Paddle.h"
#include "Physics.h"
#include "Room.h"
#include "btBulletDynamicsCommon.h"
#include "CollisionCallbacks.h"
#include "MyMotionState.h"
#include "NetManager.h"
#include <sstream>

#define HOST "dung-beetle"

class Game{
protected:
	Paddle* paddle;
 	Ball* ball;
 	Room* ballRoom;

public:
	Game(){}
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn) = 0;
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time) = 0;
	virtual bool keyPressed(const OIS::KeyEvent& arg) = 0;
    virtual bool keyReleased(const OIS::KeyEvent& arg) = 0;
};


class DefaultGame : public Game{
protected:
	Physics* physicsEngine;
	MyContactResultCallback* targetCallback;
	MyCollisionCallback* paddleCallback;
	MyCollisionCallback* wallCallback;

public:
	DefaultGame();
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time);
	virtual bool keyPressed(const OIS::KeyEvent& arg);
    virtual bool keyReleased(const OIS::KeyEvent& arg);
};


class ServerGame : public DefaultGame{
	NetManager* netMgr;
	int* scorePtr;
	
public:
	ServerGame();
	void initServer();
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn);
	virtual void messageClientPlayer();
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time);
};

class ClientGame : public Game{
	NetManager* netMgr;
	int* scorePtr;
public:
	ClientGame();
	void initClient();
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time);
	virtual bool keyPressed(const OIS::KeyEvent& arg);
    virtual bool keyReleased(const OIS::KeyEvent& arg);
};
#endif