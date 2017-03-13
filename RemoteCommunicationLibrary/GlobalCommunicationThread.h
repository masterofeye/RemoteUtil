#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QThread>

#include "Message.h"

namespace RW{
	namespace COM{
		class GlobalCommunicationThread :
			public QThread
		{
			Q_OBJECT
		private:
			std::shared_ptr<spdlog::logger> m_Logger;
			QTcpSocket* m_Socket;
		public:
			GlobalCommunicationThread(QTcpSocket* ID, std::shared_ptr<spdlog::logger> Logger, QObject *parent = nullptr);
			~GlobalCommunicationThread();
			void run();
		public slots:
			void OnDisconnect();
			void OnProcessMessage(Message Msg);
			void OnExternalMessage();
		signals:
			void error(QTcpSocket::SocketError socketerror);
			void NewMessage(Message Msg);
		};
	}
}