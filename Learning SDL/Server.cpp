#include "Server.h"

const int port = 1234;

bool Server::CreateServer()
{
    if (SDLNet_ResolveHost(&m_IP, nullptr, port) == -1)
    {
        m_message.SetMessage("Could not create server");
        system("pause");
        return false;
    }
    
    return true;
}

bool Server::Listen()
{
    TCPsocket tempSocket = nullptr;

    tempSocket = SDLNet_TCP_Accept(m_listenSocket);

    if (!tempSocket)
    {
        m_message.SetMessage("Couldn't connect to client.");
        SDL_Delay(500);
        return false;
    }

    m_clientSocket = tempSocket;
    
    return true;
}

bool Server::Send(const std::string& message)
{
    return false;
}

bool Server::Receive(std::string& message)
{
    return false;
}

void Server::Close()
{

}