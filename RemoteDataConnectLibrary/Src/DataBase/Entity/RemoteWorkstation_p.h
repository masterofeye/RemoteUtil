#pragma once
#include <qobject.h>

#include "SQLGlobal.h"
#include "Product.h"

namespace RW{
	namespace SQL{

		class Project;
		class RemoteWorkstation;
		class ElementConfiguration;
		class User;
		class RemoteWorkstationPrivate : public QObject
		{
			Q_OBJECT
			Q_DISABLE_COPY(RemoteWorkstationPrivate)
			Q_DECLARE_PUBLIC(RemoteWorkstation)
		private:
			RemoteWorkstation * const q_ptr;
		public:
			RemoteWorkstationPrivate(RemoteWorkstation *Parent);
			~RemoteWorkstationPrivate();

			QList<ElementConfiguration*> m_ElementConfiguration;
			User* m_User;
			Project* m_Project;
			QString m_Hostname;
			/*
			@brief
			*/
			QString m_Mac;
			/*
			@todo QHostAdress verwenden
			*/
			QString m_Ip;
			/*
			@todo QHostAdress verwenden
			*/
			QString m_powerstripeIp;
			QString m_powerstripeId;
			quint8  m_remoteboxComPort;
			QString m_remoteboxHwId;
			QString m_remoteboxSwVersion;

			RemoteWorkstationState m_State;

		};
	}
}
