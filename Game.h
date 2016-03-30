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
	DefaultGame(){}
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn){

		physicsEngine = new Physics();
    	physicsEngine->initObjects();
	    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
	    ballRoom = new Room(mSceneMgr, physicsEngine);
	    paddle = new Paddle(mSceneMgr, physicsEngine);
	    ball = new Ball(mSceneMgr, physicsEngine);
	    ball->getBody()->setLinearVelocity(btVector3(200, 0, -200));
	    paddle->getNode()->createChildSceneNode(Ogre::Vector3(0, 0,0))->attachObject(mCamera);

	   	targetCallback = new MyContactResultCallback(&score, &time, &soundOn);
	    paddleCallback = new MyCollisionCallback(&time, (char*) "music/ballHittingPaddle.wav", &soundOn);
	    wallCallback = new MyCollisionCallback(&time, (char*) "music/ballHittingWall.wav", &soundOn);
	}

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time){
		btRigidBody* body =  ball->getBody();
	    physicsEngine->getDynamicsWorld()->stepSimulation(evt.timeSinceLastFrame, 60);

	    physicsEngine->getDynamicsWorld()->contactPairTest(body, ballRoom->getTargetBody(), *targetCallback);
	    physicsEngine->getDynamicsWorld()->contactPairTest(body, paddle->getBody(), *paddleCallback);

	    btRigidBody** wallBTArray = ballRoom->getWallBodyArray();
	    for(int i = 0; i < NUM_WALLS; i++){
	        physicsEngine->getDynamicsWorld()->contactPairTest(body, wallBTArray[i], *wallCallback);
	    }

	    float newx, newy, newz;
	    btRigidBody* paddleBody =  paddle->getBody();
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

	    if(time <= 0){
	    	ball->getBody()->setLinearVelocity(btVector3(0,0,0));
        	ball->getBody()->setGravity(btVector3(0,0,0));
	    }
	}

	virtual bool keyPressed(const OIS::KeyEvent& arg){
		paddle->move(arg.key);
	    return true;
	}

    virtual bool keyReleased(const OIS::KeyEvent& arg){
	   	paddle->stop(arg.key);
	    return true;
    }
};

class ServerGame : public DefaultGame{
	NetManager* netMgr;
	int* scorePtr;
public:
	ServerGame(){}
	void initServer(){
		netMgr = new NetManager();
		netMgr->initNetManager();
		netMgr->addNetworkInfo(PROTOCOL_TCP);
		netMgr->startServer();
		netMgr->acceptConnections();
		while(!(netMgr->scanForActivity()));
	}

	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn){
		initServer();
		scorePtr = &score;
		DefaultGame::createScene(mSceneMgr, mCamera, time, score, soundOn);
	}

	virtual void messageClientPlayer(){
		std::stringstream message;
		message << ((int) DefaultGame::ball->getNode()->getPosition().x) << " ";
		message << ((int) DefaultGame::ball->getNode()->getPosition().y) << " ";
		message << ((int) DefaultGame::ball->getNode()->getPosition().z) << " ";
		message << *scorePtr << " ";
		netMgr->messageClients(PROTOCOL_TCP, message.str().c_str(), message.str().size());
	}

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time){
		if(netMgr->scanForActivity()){
			std::stringstream stream;
			std::string command;
			char* message = netMgr->tcpClientData[0]->output;
			stream << message;
			stream >> command;
			int key;
			stream >> key;
			if(command == "move")
				paddle->move(key);
			if(command == "stop")
				paddle->stop(key);
		}
		DefaultGame::frameRenderingQueued(evt, time);
		messageClientPlayer();
	}
};

class ClientGame : public Game{
	NetManager* netMgr;
	int* scorePtr;
public:
	ClientGame(){}
	void initClient(){
		netMgr = new NetManager();
		netMgr->initNetManager();
		netMgr->addNetworkInfo(PROTOCOL_TCP, HOST, 0);
		netMgr->startClient();
	}
	virtual void createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn){
		initClient();
		ballRoom = new Room(mSceneMgr);
	    paddle = new Paddle(mSceneMgr);
	    ball = new Ball(mSceneMgr);
	    scorePtr = &score;
	}

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt, float& time){
		if(netMgr->scanForActivity()){
			std::stringstream stream;
			char* message = netMgr->tcpServerData.output;
			stream << message;
			int ballX;
			int ballY;
			int ballZ;
			stream >> ballX;
			stream >> ballY;
			stream >> ballZ;
			Ogre::SceneNode* ballNode = ball->getNode();
			ballNode->setPosition(ballX, ballY, ballZ);
			stream >> *scorePtr;
		}
	}

	virtual bool keyPressed(const OIS::KeyEvent& arg){
	    	std::stringstream message;
	    	message << "move " << arg.key;
	      	netMgr->messageServer(PROTOCOL_TCP, message.str().c_str(), message.str().size());
	}

    virtual bool keyReleased(const OIS::KeyEvent& arg){
    		std::stringstream message;
    		message << "stop " << arg.key;
	      	netMgr->messageServer(PROTOCOL_TCP, message.str().c_str(), message.str().size());
    }
};
#endif