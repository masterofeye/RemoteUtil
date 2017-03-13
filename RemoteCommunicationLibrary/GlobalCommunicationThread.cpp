#include "stdafx.h"
#include "GlobalCommunicationThread.h"
#include <qhostaddress.h>
#include <qdatastream>

namespace RW{
	namespace COM{
		GlobalCommunicationThread::GlobalCommunicationThread(QTcpSocket* ID, std::shared_ptr<spdlog::logger> Logger, QObject *parent) :
			QThread(parent),
			m_Logger(Logger),
			m_Socket(ID)
			{
			}


			GlobalCommunicationThread::~GlobalCommunicationThread()
			{
			}

			void GlobalCommunicationThread::run()
			{
				//m_Socket = new QTcpSocket();

				//// set the ID
				//if (!m_Socket->setSocketDescriptor(m_SocketDescriptor))
				//{
				//	// something's wrong, we just emit a signal
				//	emit error(m_Socket->error());
				//	return;
				//}

				// connect socket and signal
				// note - Qt::DirectConnection is used because it's multithreaded
				//        This makes the slot to be invoked immediately, when the signal is emitted.

				connect(m_Socket, SIGNAL(readyRead()), this, SLOT(OnExternalMessage()), Qt::DirectConnection);
				connect(m_Socket, SIGNAL(disconnected()), this, SLOT(OnDisconnect()));


				// We'll have multiple clients, we want to know which is which
				m_Logger->debug("Client connected to GlobalServer {}",m_Socket->localAddress().toString().toStdString());

				// make this thread a loop,
				// thread will stay alive so that signal/slot to function properly
				// not dropped out in the middle when thread dies

				exec();
			}


			void GlobalCommunicationThread::OnProcessMessage(Message Msg)
			{
				QByteArray arr;
				QDataStream dataStream(&arr, QIODevice::OpenModeFlag::WriteOnly);
				dataStream << Msg;
				quint64 size = m_Socket->write(arr);
				if (size < arr.size())
					m_Logger->warn("Uncomplete message was send to {}", Msg.Identifier().toStdString());

				if (!m_Socket->flush())
					m_Logger->error("Message couldn't send to {}", Msg.Identifier().toStdString());
			}

			void GlobalCommunicationThread::OnExternalMessage()
			{
				if (m_Socket->bytesAvailable() <= 0)
					return;

				Message msg;
				QDataStream sizeStream(m_Socket->readAll());
				sizeStream >> msg;

				emit NewMessage(msg);
			}

			
			void GlobalCommunicationThread::OnDisconnect()
			{
				if (qobject_cast<QAbstractSocket*>(sender())) {
					sender()->deleteLater();
				}
			}
	}
}