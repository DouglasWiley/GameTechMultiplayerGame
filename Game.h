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
#include <string>
#include "OISKeyboard.h"

#define HOST "baby-ruth"

class Game{
protected:
	Paddle* paddle;
 	Ball* ball;
 	Room* ballRoom;

public:
	Game(){}
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn){}
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
    virtual void contactTests();
};


class ServerGame : public DefaultGame{
	NetManager* netMgr;

	MyContactResultCallback* p1Callback;
	MyContactResultCallback* p2Callback;
	Paddle* paddle2; //client paddle
	int* score1ptr;
	int* score2ptr;

public:
	ServerGame() {};
	bool initServer(OIS::Keyboard* keyboard);
	void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score1, int& score2, bool& soundOn);
	virtual void messageClientPlayer();
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time);
	virtual void contactTests();
};

class ClientGame : public Game{
	NetManager* netMgr;
	int* score1ptr;
	int* score2ptr;
	Paddle* serverPaddle;

public:
	ClientGame() {};
	~ClientGame();
	bool initClient();
	bool connectToHost(std::string);
	void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score1, int& score2, bool& soundOn);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time);
	virtual bool keyPressed(const OIS::KeyEvent& arg);
    virtual bool keyReleased(const OIS::KeyEvent& arg);
};
#endif