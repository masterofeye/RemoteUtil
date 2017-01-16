#pragma once
#include "Entity.h"
#include "qdebug.h"

namespace RW{
	enum class RemoteWorkstationState;

	namespace SQL{
		class RemoteWorkstationPrivate;
		class ElementConfiguration;
		class User;
		class Project;

		class REMOTE_DATA_CONNECT_API RemoteWorkstation :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(QList<ElementConfiguration>* ElementCfg READ ElementCfg WRITE SetElementCfg NOTIFY ElementCfgChanged)
			Q_PROPERTY(User* CurrentUser READ CurrentUser WRITE SetCurrentUser NOTIFY CurrentUserChanged)
			Q_PROPERTY(Project* AssignedProject READ AssignedProject WRITE setAssignedProject NOTIFY ProjectChanged)
			Q_PROPERTY(QString Hostname READ Hostname WRITE SetHostname NOTIFY HostnameChanged)
			Q_PROPERTY(QString Mac READ Mac WRITE SetMac NOTIFY MacChanged)
			Q_PROPERTY(QString Ip READ Ip WRITE SetIp NOTIFY IpChanged)
			Q_PROPERTY(QString PowerstripeIp READ PowerstripeIp WRITE SetPowerstripeIp NOTIFY PowerstripeIpChanged)
			Q_PROPERTY(QString PowerstripeId READ PowerstripeId WRITE SetPowerstripeId NOTIFY PowerstripeIdChanged)
			Q_PROPERTY(quint8 RemoteboxComPort READ RemoteboxComPort WRITE SetRemoteboxComPort NOTIFY RemoteboxComPortChanged)
			Q_PROPERTY(QString RemoteboxHwId READ RemoteboxHwId WRITE SetRemoteboxHwId NOTIFY RemoteboxHwIdChanged)
			Q_PROPERTY(QString RemoteboxSwVersion READ RemoteboxSwVersion WRITE SetRemoteboxSwVersion NOTIFY RemoteboxSwVersionChanged)
			Q_PROPERTY(RemoteWorkstationState State READ State WRITE SetState NOTIFY StateChanged)


			Q_CLASSINFO("Version", "0.0.1")
		private:
			RemoteWorkstationPrivate* d_ptr;
			Q_DECLARE_PRIVATE(RemoteWorkstation);
		public:
			RemoteWorkstation(Entity *Parent = nullptr);
			~RemoteWorkstation();
			 
			RemoteWorkstation(const RemoteWorkstation &R);
			RemoteWorkstation& operator=(const RemoteWorkstation &R);

			RemoteWorkstation(RemoteWorkstation &&R);
			RemoteWorkstation& operator=( RemoteWorkstation &&R);

			QList<ElementConfiguration>* ElementCfg() const;
			void SetElementCfg(QList<ElementConfiguration>* ElementCfg);
			void AddElementCfg(ElementConfiguration& ElementCfg);
			
			User* CurrentUser() const;
			void SetCurrentUser(User *CurrentUser);

			QString Hostname() const;
			void SetHostname(QString Hostname);

			QString Mac() const;
			void SetMac(QString Mac);

			QString Ip() const;
			void SetIp(QString Ip);

			QString PowerstripeIp() const;
			void SetPowerstripeIp(QString PowerstripIp);

			QString PowerstripeId() const;
			void SetPowerstripeId(QString PowerstripId);

			quint8 RemoteboxComPort() const;
			void SetRemoteboxComPort(quint8 RemoteboxComPort);

			QString RemoteboxHwId() const;
			void SetRemoteboxHwId(QString RemoteboxHwId);
			
			QString RemoteboxSwVersion() const;
			void  SetRemoteboxSwVersion(QString RemoteboxSwVersion);

			RemoteWorkstationState State() const;
			void SetState(RemoteWorkstationState State);

			Project* RemoteWorkstation::AssignedProject() const;
			void RemoteWorkstation::setAssignedProject(Project* Project);
		signals:
			void ElementCfgChanged();
			void CurrentUserChanged();
			void HostnameChanged();
			void MacChanged();
			void IpChanged();
			void PowerstripeIpChanged();
			void PowerstripeIdChanged();
			void RemoteboxComPortChanged();
			void RemoteboxHwIdChanged();
			void RemoteboxSwVersionChanged();
			void StateChanged();
			void ProjectChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::RemoteWorkstation)
Q_DECLARE_METATYPE(QList<RW::SQL::ElementConfiguration>*)
