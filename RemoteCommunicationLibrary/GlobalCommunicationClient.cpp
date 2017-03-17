#include "stdafx.h"
#include "GlobalCommunicationClient.h"

namespace RW{
    namespace COM{
        GlobalCommunicationClient::GlobalCommunicationClient(quint16 Port, std::shared_ptr<spdlog::logger> Logger, QObject* Parent) : BasicCommunicationServer(Parent),
            m_Logger(Logger),
            m_Port(Port)
        {
        }

        bool GlobalCommunicationClient::Listen()
        {
            return true;
        }

        GlobalCommunicationClient::~GlobalCommunicationClient()
        {
        }

        void GlobalCommunicationClient::OnDisconnected()
        {

        }

        void GlobalCommunicationClient::OnPrepareIncomingConnection()
        {

        }

        void GlobalCommunicationClient::OnProcessMessage(Message Msg)
        {

        }

        void GlobalCommunicationClient::OnExternalMessage()
        {

        }

        void GlobalCommunicationClient::OnExternalMessage(Message Msg)
        {
        }

        void GlobalCommunicationClient::OnSocketError(QAbstractSocket::SocketError socketError)
        {

        }
    }
}