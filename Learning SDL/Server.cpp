#include "Server.h"

const int port = 1234;

bool Server::CreateServer()
{
    if (SDLNet_ResolveHost(&m_IP, nullptr, port) == -1)
    {
        m_message.SetMessage("Could not create server");
        std::cout << "Could not create server" << std::endl;
        system("pause");
        return false;
    }
    
    return true;
}

bool Server::Listen()
{
    m_clientSocket = SDLNet_TCP_Accept(m_socket);

    while (!m_clientSocket)
    {
        m_message.SetMessage("Wating for client...");
        std::cout << "." << std::endl;
        SDL_Delay(500);
    }

    if (m_clientSocket)
    {
        m_message.SetMessage("Client connected");
        std::cout << "Client connected" << std::endl;
        return true;
    }
}

bool Server::Send(const std::string& message)
{
    return false;
}

bool Server::Receive(std::string& message)
{
    return false;
}