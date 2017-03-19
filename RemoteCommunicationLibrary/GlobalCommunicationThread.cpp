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
				connect(m_Socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnSocketError(QAbstractSocket::SocketError)));

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
				{
					m_Logger->warn("TcpSocket don't have any data received but was triggered.");
					return;
				}

				Message msg;
				QDataStream sizeStream(m_Socket->readAll());
				sizeStream >> msg;

				emit NewMessage(msg);
			}

			
			void GlobalCommunicationThread::OnDisconnect()
			{
				QTcpSocket *socket = (QTcpSocket*)qobject_cast<QAbstractSocket*>(sender());
				if (socket) {
					m_Logger->debug("Client {} disconnected from the server.", socket->peerAddress().toString().toStdString());
					socket->deleteLater();
				}
			}

			void GlobalCommunicationThread::OnSocketError(QAbstractSocket::SocketError socketError)
			{
				switch (socketError)
				{
				case QAbstractSocket::ConnectionRefusedError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured: {}", "ConnectionRefusedError");
					break;
				case QAbstractSocket::AddressInUseError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured: {}", "AddressInUseError");
					break;
				case QAbstractSocket::TemporaryError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured: {}", "ServerNotFoundError");
					break;
				case QAbstractSocket::SocketAccessError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured: {}", "SocketAccessError");
					break;
				case QAbstractSocket::SocketResourceError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured:  {}", "SocketResourceError");
					break;
				case QAbstractSocket::SocketTimeoutError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured:  {}", "SocketTimeoutError");
					break;
				case QAbstractSocket::DatagramTooLargeError:
					m_Logger->error("A GlobalCommunicationClient socket error occoured:  {}", "DatagramTooLargeError");
					break;
				case QAbstractSocket::UnsupportedSocketOperationError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "UnsupportedSocketOperationError");
					break;
				case QAbstractSocket::UnknownSocketError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "UnknownSocketError");
					break;
				case QAbstractSocket::OperationError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "OperationError");
					break;
				case QAbstractSocket::UnfinishedSocketOperationError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "UnfinishedSocketOperationError");
					break;
				case QAbstractSocket::NetworkError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "NetworkError");
					break;
				case QAbstractSocket::HostNotFoundError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "HostNotFoundError");
					break;
				case QAbstractSocket::RemoteHostClosedError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "RemoteHostClosedError");
					break;
				case QAbstractSocket::ProxyAuthenticationRequiredError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "ProxyAuthenticationRequiredError");
					break;
				case QAbstractSocket::SslHandshakeFailedError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "SslHandshakeFailedError");
					break;
				case QAbstractSocket::ProxyConnectionRefusedError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "UnfinishedSocketOperationError");
					break;
				case QAbstractSocket::ProxyConnectionClosedError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "ProxyConnectionClosedError");
					break;
				case QAbstractSocket::ProxyConnectionTimeoutError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "ProxyConnectionTimeoutError");
					break;
				case QAbstractSocket::ProxyNotFoundError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "ProxyNotFoundError");
					break;
				case QAbstractSocket::ProxyProtocolError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "ProxyProtocolError");
					break;
				case QAbstractSocket::SslInternalError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "SslInternalError");
					break;
				case QAbstractSocket::SslInvalidUserDataError:
					m_Logger->error("A LocalCommunicationServer socket error occoured:  {}", "SslInvalidUserDataError");
					break;
				default:
					break;
				}
			}
	}
}