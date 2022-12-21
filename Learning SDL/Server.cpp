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
    //TODO - This worked in my last assignment, why not here?
    m_clientSocket = SDLNet_TCP_Accept(m_listenSocket); //this bit specifically

    if (!m_clientSocket)
    {
        m_message.SetMessage("Wating for client...");
        SDL_Delay(500);
    }
    else
    {
        m_message.SetMessage("Client connected");
    }
    
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