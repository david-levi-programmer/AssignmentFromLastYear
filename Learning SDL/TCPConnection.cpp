#include "TCPConnection.h"

bool TCPConnection::Initialize()
{
    if (SDLNet_Init() == -1)
    {
        std::cout << "Networking sub-system did not initialize properly." << std::endl;
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
        std::cout << "Could not open listening socket" <<  std::endl;
        system("pause");
        return false;
    }

    return true;
}

void TCPConnection::CloseSocket()
{
    SDLNet_TCP_Close(m_socket);
}

void TCPConnection::ShutDown()
{
    SDLNet_Quit();
}