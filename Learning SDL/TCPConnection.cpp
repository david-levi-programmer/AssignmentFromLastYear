#include "TCPConnection.h"

const int port = 1234;

TCPConnection::TCPConnection()
{

}

bool TCPConnection::Initialize()
{
    //Don't know if it's okay to have more than one SDL_Init call in the project
    /*if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL did not initialize properly." << std::endl;
        system("pause");
        return false;
    }*/

    if (SDLNet_Init() == -1)
    {
        std::cout << "Networking sub-system did not initialize properly." << std::endl;
        system("pause");
        return false;
    }

    //setup with specific port number
    //as host, we use nullptr
    if (SDLNet_ResolveHost(&m_IP, nullptr, port) == -1)
    {
        std::cout << "Could not create server" << std::endl;
        system("pause");
        return false;
    }

    return true;
}

bool TCPConnection::OpenSocket()
{
    m_socket = SDLNet_TCP_Open(&m_IP);

    if (!m_socket)
    {
        std::cout << "Could not open listening socket" << std::endl << std::endl;
        system("pause");
        return false;
    }

    return true;
}

void TCPConnection::CloseSocket()
{

}

void TCPConnection::ShutDown()
{

}