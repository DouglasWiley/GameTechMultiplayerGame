#include "NetManager.h"
#include <stdio.h>

int main(int argc, char** argv){
	NetManager* manager = new NetManager();
	manager->initNetManager();
	manager->addNetworkInfo(PROTOCOL_TCP);
	manager->startServer();
	manager->acceptConnections();
	while(!(manager->scanForActivity()));
	if(manager->getClients())
		manager->messageClients(PROTOCOL_TCP, "hello!", 7);
	while(1);
	manager->stopServer(PROTOCOL_TCP);
	return 0;
}