#include "Server.h"

const int port = 1234;

bool Server::CreateServer()
{
    if (SDLNet_ResolveHost(&m_IP, nullptr, port) == -1)
    {
        std::cout << "Could not create server" << std::endl;
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
        std::cout << "Couldn't connect to client" << std::endl;
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