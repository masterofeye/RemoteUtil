#pragma once
#include "stdafx.h"
#include "qobject.h"
#include "BasicCommunicationServer.h"
#include <QUuid>

namespace RW{
	namespace COM{
		class LocalCommunicationServer;
		class GlobalCommunicationServer;

		class REMOTECOMMUNICATIONLIBRARY_EXPORT CommunicatonServer :
			public BasicCommunicationServer
		{
			Q_OBJECT
		private:
			std::shared_ptr<spdlog::logger> m_Logger;
			BasicCommunicationServer* m_LocalComObj;
            BasicCommunicationServer* m_GlobalComObj;
			QList<QObject*>* m_ReceiverList;
			QUuid m_UUID;
            bool m_IsServer = true;
		public:
            CommunicatonServer(bool IsServer,QString LocalServerName = "Server", quint16 Port = 1234, std::shared_ptr<spdlog::logger> Logger = nullptr, QObject* Parent = nullptr);
			~CommunicatonServer();

			void Register(QObject* Client);
			void Unregister(QObject* Client);
			void UnregisterAll();
			bool Listen() Q_DECL_OVERRIDE;
		public slots:
			void OnPrepareIncomingConnection() Q_DECL_OVERRIDE;
			void OnProcessMessage(Message Msg) Q_DECL_OVERRIDE;
			void OnExternalMessage() Q_DECL_OVERRIDE;
			void OnExternalMessage(Message Msg);
		signals:
			void SendExtMessage(Message Msg);
		};
	}
}
