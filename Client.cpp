#include "NetManager.h"
#include <stdio.h>

int main(int argc, char** argv){
	NetManager* manager = new NetManager();
	manager->initNetManager();
	manager->addNetworkInfo(PROTOCOL_TCP, "mr-goodbar", 0);
	manager->startClient();
	while(!(manager->scanForActivity()));
	std::cout << manager->tcpServerData.output << std::endl;
	manager->stopClient(PROTOCOL_TCP);
	return 0;
}