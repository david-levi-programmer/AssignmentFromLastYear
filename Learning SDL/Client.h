#pragma once

#include "TCPConnection.h"
#include "Message.h"

class Client : public TCPConnection
{

public:
	
	bool Send(const std::string& message);
	bool Receive(std::string& message);
	bool Connect();

private:

	TCPsocket m_clientSocket = nullptr;

};