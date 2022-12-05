#include "Server.h"

bool Server::Listen()
{
    TCPsocket tempSocket = nullptr;

    tempSocket = SDLNet_TCP_Accept(m_listenSocket);

    if (!tempSocket)
    {
        SDL_Delay(500);
        return false;
    }

    m_clientSocket = tempSocket;
    
    return true;
}

void Server::Close()
{

}