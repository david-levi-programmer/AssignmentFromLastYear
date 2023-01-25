#pragma once

#include <string>
#include "TCPConnection.h"

class Server : public TCPConnection
{

public:

	bool CreateServer();
	bool Listen();
	
	bool Send(const std::string& message);
	bool Receive(std::string& message);

private:

	//TCPsocket m_listenSocket = nullptr;
	TCPsocket m_clientSocket = nullptr;
	//IPaddress m_IP;
	Message m_message;

};