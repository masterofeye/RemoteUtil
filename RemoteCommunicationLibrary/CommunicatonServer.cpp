#include "CommunicatonServer.h"
#include "LocalCommunicationServer.h"
#include "GlobalCommunicationServer.h"
#include "LocalCommunicationClient.h"
#include "GlobalCommunicationClient.h"
#include "Message.h"

#include <QMetaobject>
#include <QMetaMethod>


namespace RW{
	namespace COM{
		CommunicatonServer::CommunicatonServer(bool IsServer, QString LocalServerName, quint16 Port,  std::shared_ptr<spdlog::logger> Logger, QObject* Parent) : BasicCommunicationServer(Parent),
			m_ReceiverList(new QList<QObject*>()),
			m_Logger(Logger),
            m_IsServer(IsServer)
		{
            if (IsServer)
            {
                m_LocalComObj = new LocalCommunicationServer("Server", Logger, this);
                m_GlobalComObj = new GlobalCommunicationServer(1234, Logger, this);
            }
            else
            {
                m_LocalComObj = new LocalCommunicationClient("Server", Logger, this);
                m_GlobalComObj = new GlobalCommunicationClient(1234, Logger, this);
            }


			connect(m_GlobalComObj, &GlobalCommunicationServer::NewMessage, this, &CommunicatonServer::OnProcessMessage);
			connect(m_LocalComObj, &LocalCommunicationServer::NewMessage, this, &CommunicatonServer::OnProcessMessage);
            connect(this, &CommunicatonServer::SendExtMessage, (GlobalCommunicationServer*)m_GlobalComObj, &GlobalCommunicationServer::OnProcessMessage);
            connect(this, &CommunicatonServer::SendExtMessage, (LocalCommunicationServer*)m_LocalComObj, &LocalCommunicationServer::OnProcessMessage);

			m_UUID = QUuid::createUuid();
		}


		CommunicatonServer::~CommunicatonServer()
		{
			qDeleteAll(*m_ReceiverList);
			delete m_ReceiverList;
			m_ReceiverList = nullptr;
		}

		bool CommunicatonServer::Listen()
		{
			if (!m_LocalComObj->Listen())
			{
				return false;
			}

			if (!m_GlobalComObj->Listen())
			{
				return false;
			}

			return true;
		}

		void CommunicatonServer::Register(QObject* Client)
		{
			if (Client == nullptr)
			{
				m_Logger->error("Can't register Client because he is null for Object {}", Client->objectName().toStdString());
			}
			else
			{
				//Wir brauchen das MetaObjekt des Receivers um eine Liste der Methoden zu bekommen
				const QMetaObject* ClientMetaObject = Client->metaObject();
				if (ClientMetaObject == nullptr)
				{
					m_Logger->error("Meta object is null for Object {}", Client->objectName().toStdString());
					return;
				}

				//Pr¸fen ob im Receiver Objekt die OnMessage Methode existiert
				int clientMethodIndex = ClientMetaObject->indexOfSlot(QMetaObject::normalizedSignature("OnProcessMessage(Message Msg)"));
				//TODO MagicNumber
				if (clientMethodIndex == -1)
				{
					m_Logger->warn("There is no function called OnProcessMessage for Object {}", Client->metaObject()->className());
					return;
				}

				QMetaMethod clientOnProcessMessageMethod = ClientMetaObject->method(clientMethodIndex);

				const QMetaObject* ServerMetaObject = this->metaObject();
				if (ServerMetaObject == nullptr)
				{
					m_Logger->error("Meta object is null for Object {}", this->metaObject()->className());
					return;
				}

				int ServerSignalIndex = ServerMetaObject->indexOfSignal(QMetaObject::normalizedSignature("NewMessage(COM::Message Msg)"));
				//TODO MagicNumber
				if (ServerSignalIndex == -1)
				{
					m_Logger->warn("No Signal found with name NewCommand for Object {}", this->metaObject()->className());
					return;
				}

				QMetaMethod serverSignal = ServerMetaObject->method(ServerSignalIndex);

				QMetaObject::Connection connectionServerClient = QObject::connect(this, serverSignal, Client, clientOnProcessMessageMethod);
				if (((bool)connectionServerClient) == false)
				{
					m_Logger->error("Connection couldn't established for Object:{}", Client->metaObject()->className());
				}
				else
				{
					m_Logger->debug("Receiver was successfully connected to the signal. {}", Client->metaObject()->className());
				}

				int serverMethodIndex = ServerMetaObject->indexOfSlot(QMetaObject::normalizedSignature("OnProcessMessage(Message Message)"));
				if (serverMethodIndex == -1)
				{
					m_Logger->warn("There is no function called OnProcessMessage for Object {}", this->metaObject()->className());
					return;
				}

				QMetaMethod serverOnProcessMessageMethod = ServerMetaObject->method(serverMethodIndex);

				int clientSignalIndex = ClientMetaObject->indexOfSignal(QMetaObject::normalizedSignature("NewMessage(Message Message)"));
				//TODO MagicNumber
				if (clientSignalIndex == -1)
				{
					m_Logger->warn("No Signal found with name NewCommand for Object {}", this->metaObject()->className());
					return;
				}

				QMetaMethod clientSignal = ClientMetaObject->method(clientSignalIndex);

				QMetaObject::Connection connectionClientServer = QObject::connect(Client, clientSignal, this, serverOnProcessMessageMethod);
				if (((bool)connectionClientServer) == false)
				{
					m_Logger->error("Connection couldn't established for Object:{}", this->metaObject()->className());
				}
				else
				{
					m_Logger->debug("Receiver was successfully connected to the signal. {}", this->metaObject()->className());
				}

				m_ReceiverList->append(Client);
			}
		}


		void CommunicatonServer::Unregister(QObject* Receiver)
		{
			QObject::disconnect(Receiver);
			m_Logger->debug("The client {} is disconnected now", Receiver->objectName().toStdString());
		}
		void CommunicatonServer::UnregisterAll()
		{
			for each (auto var in *m_ReceiverList)
			{
				QObject::disconnect(var);
			}
			m_Logger->debug("All receivers are disconnected now");
		}

		void CommunicatonServer::OnProcessMessage(Message Msg)
		{
			QObject* obj = QObject::sender();

			//Auschlieﬂen das wir Nachrichten empfangen die von CommunicatonServer::OnProcessMessage gesendet wurden.
			if (qobject_cast<GlobalCommunicationServer*>(obj) != nullptr)
				return;
			if (qobject_cast<LocalCommunicationServer*>(obj) != nullptr)
				return;
            if (qobject_cast<LocalCommunicationClient*>(obj) != nullptr)
                return;
            if (qobject_cast<GlobalCommunicationClient*>(obj) != nullptr)
                return;

			if (Msg.IsExternal())
			{
				Msg.SetIdentifier(m_UUID.toString());
				emit SendExtMessage(Msg);
			}
			emit NewMessage(Msg);
		}

		void CommunicatonServer::OnPrepareIncomingConnection()
		{}

		void CommunicatonServer::OnExternalMessage()
		{

		}

		void CommunicatonServer::OnExternalMessage(Message Msg)
		{
			QObject* obj = QObject::sender();

			if (qobject_cast<GlobalCommunicationServer*>(obj) == nullptr || qobject_cast<LocalCommunicationServer*>(obj) == nullptr)
				return;

			emit NewMessage(Msg);
		}
	}
}