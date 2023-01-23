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
        m_message.SetMessage("Couldn't connect to host");
        std::cout << "Could not connect" << std::endl; //TODO - Remove before submitting
        return 0;
    }

    m_clientSocket = SDLNet_TCP_Open(&m_IP);

    if (!m_clientSocket)
    {
        m_message.SetMessage("Couldn't connect to server");
        std::cout << "Could not connect" << std::endl; //TODO - Remove before submitting
        system("pause");
        return 0;
    }

    std::cout << "Connected to server" << std::endl;
}