#include "Client.h"

const std::string ipAddress = "localHost";

const int port = 1234;

bool Client::Send(const std::string& message)
{
    return false;
}

bool Client::Receive(std::string& message)
{
    return false;
}

bool Client::Connect()
{
    if (SDLNet_ResolveHost(&m_IP, ipAddress.c_str(), port) == -1)
    {
        m_message.SetMessage("Couldn't connect to server");
        return 0;
    }
}