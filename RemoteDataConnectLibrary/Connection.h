#pragma once
#include "qobject.h"

namespace RW{
	namespace SQL{


		class Connection :
			public QObject
		{
		private:
			QString m_HostName;
			quint16 m_Port;
			QString m_DataBaseName;
			QString m_User;
			QString m_Password;
		public:
			Connection(QObject *Parent = nullptr);
			~Connection();
			void Connect();
		};

	}
}