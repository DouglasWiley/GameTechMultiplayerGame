#include "Game.h"

DefaultGame::DefaultGame(){

}

void DefaultGame::createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score, bool& soundOn){

	physicsEngine = new Physics();
	physicsEngine->initObjects();
    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
    ballRoom = new Room(mSceneMgr, physicsEngine);
    ballRoom->createTarget(mSceneMgr, physicsEngine);
    paddle = new Paddle(mSceneMgr, physicsEngine);
    ball = new Ball(mSceneMgr, physicsEngine);
    ball->getBody()->setLinearVelocity(btVector3(200, 0, -200));
    paddle->getNode()->createChildSceneNode(Ogre::Vector3(0, 0,0))->attachObject(mCamera);

   	targetCallback = new MyContactResultCallback(&score, &time, &soundOn);
    paddleCallback = new MyCollisionCallback(&time, (char*) "music/ballHittingPaddle.wav", &soundOn);
    wallCallback = new MyCollisionCallback(&time, (char*) "music/ballHittingWall.wav", &soundOn);
}

bool DefaultGame::frameRenderingQueued(const Ogre::FrameEvent& evt, float& time){
	physicsEngine->getDynamicsWorld()->stepSimulation(evt.timeSinceLastFrame, 60);
	contactTests();
	btRigidBody* body =  ball->getBody();
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
    return true;
}

bool DefaultGame::keyPressed(const OIS::KeyEvent& arg){
	paddle->move(arg.key);
    return true;
}

bool DefaultGame::keyReleased(const OIS::KeyEvent& arg){
   	paddle->stop(arg.key);
    return true;
}

void DefaultGame::contactTests(){
	btRigidBody* body =  ball->getBody();
	physicsEngine->getDynamicsWorld()->contactPairTest(body, ballRoom->getTargetBody(), *targetCallback);
    physicsEngine->getDynamicsWorld()->contactPairTest(body, paddle->getBody(), *paddleCallback);
    btRigidBody** wallBTArray = ballRoom->getWallBodyArray();
    for(int i = 0; i < NUM_WALLS; i++){
        physicsEngine->getDynamicsWorld()->contactPairTest(body, wallBTArray[i], *wallCallback);
    }
}

bool ServerGame::initServer(OIS::Keyboard* keyboard){
	netMgr = new NetManager();
	netMgr->initNetManager();
	netMgr->addNetworkInfo(PROTOCOL_TCP);
	netMgr->startServer();
	netMgr->acceptConnections();
	while(!(netMgr->scanForActivity())){
        keyboard->capture();
        if(keyboard->isKeyDown(OIS::KC_ESCAPE))
            return false;
    }
    return true;
}

void ServerGame::createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score1, int& score2, bool& soundOn){
	time = 60;
	score1ptr = &score1;
	score2ptr = &score2;
	physicsEngine = new Physics();
	physicsEngine->initObjects();
    btDiscreteDynamicsWorld* dynamicsWorld = physicsEngine->getDynamicsWorld();
    ballRoom = new Room(mSceneMgr, physicsEngine);
    paddle = new Paddle(mSceneMgr, physicsEngine, 0, 750, -375);
    paddle2 = new Paddle(mSceneMgr, physicsEngine, 0, 750, 375);
    ball = new Ball(mSceneMgr, physicsEngine);
    ball->getBody()->setLinearVelocity(btVector3(200, 0, -200));
    //mSceneMgr->createChildSceneNode(Ogre::Vector3(0, 0,0))->attachObject(mCamera);
    mCamera->setPosition(Ogre::Vector3(0, 2000, -2000));
    mCamera->lookAt(Ogre::Vector3(0,650,0));
   	p1Callback = new MyContactResultCallback(&score1, &time, &soundOn);
   	p2Callback = new MyContactResultCallback(&score2, &time, &soundOn);
    paddleCallback = new MyCollisionCallback(&time, (char*) "music/ballHittingPaddle.wav", &soundOn);
    wallCallback = new MyCollisionCallback(&time, (char*) "music/ballHittingWall.wav", &soundOn);
}

void ServerGame::messageClientPlayer(){
	std::stringstream message;
	message << ((int) ball->getNode()->getPosition().x) << " ";
	message << ((int) ball->getNode()->getPosition().y) << " ";
	message << ((int) ball->getNode()->getPosition().z) << " ";

	message << ((int) paddle->getNode()->getPosition().x) << " ";
	message << ((int) paddle->getNode()->getPosition().y) << " ";

	message << ((int) paddle2->getNode()->getPosition().x) << " ";
	message << ((int) paddle2->getNode()->getPosition().y) << " ";

	message << *score1ptr << " " << *score2ptr << " ";

	//add sounds
	netMgr->messageClients(PROTOCOL_TCP, message.str().c_str(), message.str().size());
}

bool ServerGame::frameRenderingQueued(const Ogre::FrameEvent& evt, float& time){
	if(netMgr->scanForActivity()){
		std::stringstream stream;
		std::string command;
		char* message = netMgr->tcpClientData[0]->output;
		stream << message;
		stream >> command;
		int key;
		stream >> key;
		if(command == "move")
			paddle2->move(key);
		if(command == "stop")
			paddle2->stop(key);
	}

	DefaultGame::frameRenderingQueued(evt, time);
	messageClientPlayer();
	return true;
}

void ServerGame::contactTests(){
	btRigidBody* body =  ball->getBody();
	physicsEngine->getDynamicsWorld()->contactPairTest(body, ballRoom->getWallBodyArray()[5], *p1Callback);
    physicsEngine->getDynamicsWorld()->contactPairTest(body, ballRoom->getWallBodyArray()[4], *p2Callback);
    physicsEngine->getDynamicsWorld()->contactPairTest(body, paddle->getBody(), *paddleCallback);
    physicsEngine->getDynamicsWorld()->contactPairTest(body, paddle2->getBody(), *paddleCallback);

    btRigidBody** wallBTArray = ballRoom->getWallBodyArray();
    for(int i = 0; i < NUM_WALLS; i++){
        physicsEngine->getDynamicsWorld()->contactPairTest(body, wallBTArray[i], *wallCallback);
    }
 }

ClientGame::~ClientGame(){
    delete netMgr;
}

bool ClientGame::initClient(){
	netMgr = new NetManager();
	netMgr->initNetManager();
    netMgr->addNetworkInfo(PROTOCOL_TCP);
    return true;
}

bool ClientGame::connectToHost(std::string hostname){
    netMgr->setHost(hostname.c_str());
    return netMgr->startClient();
}

void ClientGame::createScene(Ogre::SceneManager* mSceneMgr, Ogre::Camera* mCamera, float& time, int& score1, int& score2, bool& soundOn){
	ballRoom = new Room(mSceneMgr);
    paddle = new Paddle(mSceneMgr, 0, 750, 375);
    serverPaddle = new Paddle(mSceneMgr, 0, 750, -375);
    ball = new Ball(mSceneMgr);
    //paddle->getNode()->createChildSceneNode(Ogre::Vector3(0, 0, 3000))->attachObject(mCamera);
    mCamera->setPosition(Ogre::Vector3(0, 2000, 2000));
    mCamera->lookAt(Ogre::Vector3(0,650,0));

    score1ptr = &score1;
    score2ptr = &score2;
}

bool ClientGame::frameRenderingQueued(const Ogre::FrameEvent& evt, float& time){
	if(netMgr->scanForActivity()){
		std::stringstream stream;
		char* message = netMgr->tcpServerData.output;
		stream << message;

		Ogre::Vector3 ballVec;
		stream >> ballVec.x;
		stream >> ballVec.y;
		stream >> ballVec.z;
		ball->getNode()->setPosition(ballVec);

		// Move P1 or the server paddle
		Ogre::SceneNode* paddleNode = serverPaddle->getNode();
		Ogre::Vector3 paddleVec;
		stream >> paddleVec.x;
		stream >> paddleVec.y;
		paddleVec.z = ((int) paddleNode->getPosition().z);
		paddleNode->setPosition(paddleVec);

		// Move P2 or the client paddle
		paddleNode = paddle->getNode();
		stream >> paddleVec.x;
		stream >> paddleVec.y;
		paddleVec.z = ((int) paddleNode->getPosition().z);
		paddleNode->setPosition(paddleVec);

		stream >> *score1ptr;
		stream >> *score2ptr;
	}
	return true;
}

bool ClientGame::keyPressed(const OIS::KeyEvent& arg){
    	std::stringstream message;
    	if(arg.key == OIS::KC_A){
        	message << "move " << OIS::KC_D;
    	}
    	else if(arg.key == OIS::KC_D){
        	message << "move " << OIS::KC_A;
    	}
    	else
    		message << "move " << arg.key;

      	netMgr->messageServer(PROTOCOL_TCP, message.str().c_str(), message.str().size());
}

bool ClientGame::keyReleased(const OIS::KeyEvent& arg){
		std::stringstream message;
		if(arg.key == OIS::KC_A){
        	message << "stop " << OIS::KC_D;
    	}
    	else if(arg.key == OIS::KC_D){
        	message << "stop " << OIS::KC_A;
    	}
    	else
    		message << "stop " << arg.key;
      	netMgr->messageServer(PROTOCOL_TCP, message.str().c_str(), message.str().size());
}
