#include <openthread/udp.h>

void handleUdpReceive(void *aContext, otMessage *aMessage, const otMessageInfo *aMessageInfo)
{
	uint8_t buffer[1500];
	int length = otMessageRead(aMessage, otMessageGetOffset(aMessage), buffer, sizeof(buffer));

	// Process the received data here
}

void setupUdpReceiver(otInstance *aInstance)
{
	otUdpSocket socket;
	otSockAddr sockaddr;

	memset(&sockaddr, 0, sizeof(sockaddr));
	sockaddr.mPort = 1234; // Set the port to listen on

	otUdpOpen(aInstance, &socket, handleUdpReceive, NULL);
	otUdpBind(&socket, &sockaddr);
}

//esperar feedback da equipe HAL para alteracoes

