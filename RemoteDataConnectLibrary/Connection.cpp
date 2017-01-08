#include "Connection.h"
#include "qsql.h"
#include "qsqlquery.h"

namespace RW{
	namespace SQL{

		Connection::Connection(QObject *Parent) : QObject(Parent),
			m_HostName("localhost"),
			m_Port(3306),
			m_DataBaseName("remoteworkstation"),
			m_User("remoteUser"),
			m_Password("schleissheimer")
		{
		}


		Connection::~Connection()
		{
		}


		void Connection::Connect()
		{
			QSqlDatabase db = QSqlDatabase::database();
			if (!db.isOpen())
			{

				db = QSqlDatabase::addDatabase("QMYSQL");
				db.setHostName(m_HostName);
				db.setPort(m_Port);
				db.setDatabaseName(m_DataBaseName);
				db.setUserName(m_User);
				db.setPassword(m_Password);

				//Please see the link for QT5: http://seppemagiels.com/blog/create-mysql-driver-qt5-windows => qsqlmysql.dll and libmysql.dll
				//(and libmysql.lib, if your installation of MySQL has it) are needed
				db.open();
			}
		}
	}
}