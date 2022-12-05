#pragma once

#include "TCPConnection.h"

class Server : public TCPConnection
{

public:

	bool CreateServer();
	bool Listen();

	void Close();

private:

	TCPsocket m_listenSocket;
	TCPsocket m_clientSocket;
	IPaddress m_IP;
	TCPsocket m_socket;

};