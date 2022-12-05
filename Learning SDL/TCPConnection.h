#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

class TCPConnection
{

public:

	TCPConnection();

	bool Initialize();
	bool OpenSocket();
	void CloseSocket();
	void ShutDown();

private:

	IPaddress m_IP;
	TCPsocket m_socket;

};