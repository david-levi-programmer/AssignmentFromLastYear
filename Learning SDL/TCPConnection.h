#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "Message.h"

class TCPConnection
{

public:

	TCPConnection() {}

	bool Initialize();
	bool OpenSocket();
	void CloseSocket();
	void ShutDown();

	TCPsocket m_socket;
	IPaddress m_IP;
	Message m_message;

};