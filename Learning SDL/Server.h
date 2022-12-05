#pragma once

#include "TCPConnection.h"

class Server : public TCPConnection
{

public:

	bool Listen();

	void Close();

private:

	TCPsocket m_listenSocket;
	TCPsocket m_clientSocket;

};