#include "CommunicatonServer.h"
#include "LocalCommunicationServer.h"
#include "GlobalCommunicationServer.h"
#include "Message.h"

#include <QMetaobject>
#include <QMetaMethod>

namespace RW{
	namespace COM{
		CommunicatonServer::CommunicatonServer(QString LocalServerName, quint16 Port,  std::shared_ptr<spdlog::logger> Logger, QObject* Parent) : BasicCommunicationServer(Parent),
			m_LocalServer(new LocalCommunicationServer("Server", Logger, this)),
			m_GlobalServer(new GlobalCommunicationServer(1234,Logger,this)),
			m_ReceiverList(new QList<QObject*>())
		{
			connect(m_GlobalServer, &GlobalCommunicationServer::NewMessage, this, &CommunicatonServer::OnProcessMessage);
			connect(m_LocalServer, &LocalCommunicationServer::NewMessage, this, &CommunicatonServer::OnProcessMessage);
			connect(this, &CommunicatonServer::SendExtMessage, m_GlobalServer, &GlobalCommunicationServer::OnProcessMessage);
			connect(this, &CommunicatonServer::SendExtMessage, m_LocalServer, &LocalCommunicationServer::OnProcessMessage);

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
			if (!m_LocalServer->Listen())
			{
				return false;
			}

			if (!m_GlobalServer->Listen())
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
				int clientMethodIndex = ClientMetaObject->indexOfSlot(QMetaObject::normalizedSignature("OnProcessMessage(Message Message)"));
				//TODO MagicNumber
				if (clientMethodIndex == -1)
				{
					m_Logger->warn("There is no function called OnProcessMessage for Object {}", Client->objectName().toStdString());
					return;
				}

				QMetaMethod clientOnProcessMessageMethod = ClientMetaObject->method(clientMethodIndex);

				const QMetaObject* ServerMetaObject = this->metaObject();
				if (ServerMetaObject == nullptr)
				{
					m_Logger->error("Meta object is null for Object {}", this->objectName().toStdString());
					return;
				}

				int ServerSignalIndex = ServerMetaObject->indexOfSignal(QMetaObject::normalizedSignature("NewMessage(Message Message)"));
				//TODO MagicNumber
				if (ServerSignalIndex == -1)
				{
					m_Logger->warn("No Signal found with name NewCommand for Object {}", this->objectName().toStdString());
					return;
				}

				QMetaMethod serverSignal = ServerMetaObject->method(ServerSignalIndex);

				QMetaObject::Connection connectionServerClient = QObject::connect(this, serverSignal, Client, clientOnProcessMessageMethod);
				if (((bool)connectionServerClient) == false)
				{
					m_Logger->error("Connection couldn't established for Object:{}", Client->objectName().toStdString());
				}
				else
				{
					m_Logger->debug("Receiver was successfully connected to the signal. {}", Client->objectName().toStdString());
				}

				int serverMethodIndex = ServerMetaObject->indexOfSlot(QMetaObject::normalizedSignature("OnProcessMessage(Message Message)"));
				if (serverMethodIndex == -1)
				{
					m_Logger->warn("There is no function called OnProcessMessage for Object {}", this->objectName().toStdString());
					return;
				}

				QMetaMethod serverOnProcessMessageMethod = ServerMetaObject->method(serverMethodIndex);

				int clientSignalIndex = ClientMetaObject->indexOfSignal(QMetaObject::normalizedSignature("NewMessage(Message Message)"));
				//TODO MagicNumber
				if (clientSignalIndex == -1)
				{
					m_Logger->warn("No Signal found with name NewCommand for Object {}", this->objectName().toStdString());
					return;
				}

				QMetaMethod clientSignal = ClientMetaObject->method(clientSignalIndex);

				QMetaObject::Connection connectionClientServer = QObject::connect(Client, clientSignal, this, serverOnProcessMessageMethod);
				if (((bool)connectionClientServer) == false)
				{
					m_Logger->error("Connection couldn't established for Object:{}", this->objectName().toStdString());
				}
				else
				{
					m_Logger->debug("Receiver was successfully connected to the signal. {}", this->objectName().toStdString());
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