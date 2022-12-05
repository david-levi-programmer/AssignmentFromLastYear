#pragma once

#include <string>
#include "TCPConnection.h"
#include "Message.h"

class Server : public TCPConnection
{

public:

	bool CreateServer();
	bool Listen();
	bool Send(const std::string& message);
	bool Receive(std::string& message);
	void Close();

private:

	TCPsocket m_listenSocket;
	TCPsocket m_clientSocket;
	IPaddress m_IP;
	TCPsocket m_socket;
	Message m_message;

};