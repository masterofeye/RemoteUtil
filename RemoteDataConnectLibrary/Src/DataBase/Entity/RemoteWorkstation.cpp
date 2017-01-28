#include "RemoteWorkstation.h"
#include "RemoteWorkstation_p.h"
#include "User.h"
#include "ElementConfiguration.h"
#include "Project.h"

namespace RW{
	namespace SQL{

		RemoteWorkstationPrivate::RemoteWorkstationPrivate(RemoteWorkstation *Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_Hostname(""),
			m_Mac(""),
			m_Ip(""),
			m_User(nullptr),
			m_powerstripeIp(""),
			m_powerstripeId(""),
			m_remoteboxComPort(0),
			m_remoteboxHwId(""),
			m_remoteboxSwVersion(""),
			m_State(RW::RemoteWorkstationState::OFF),
			m_ElementConfiguration(new QList<ElementConfiguration>()),
			m_Project(nullptr)
		{
		}

		RemoteWorkstationPrivate::~RemoteWorkstationPrivate()
		{
			if (m_ElementConfiguration != nullptr)
			{
				//qDeleteAll(m_ElementConfiguration);
				m_ElementConfiguration->clear();
				delete m_ElementConfiguration;
				m_ElementConfiguration = nullptr;
			}
		}

		RemoteWorkstation::RemoteWorkstation(Entity *Parent) : Entity(Parent),
			d_ptr(new RemoteWorkstationPrivate(this))
		{
		}

		RemoteWorkstation::RemoteWorkstation(RemoteWorkstation &&R) : d_ptr(R.d_ptr)
		{
			d_ptr->setParent(this);
			R.d_ptr = nullptr;
		}

		RemoteWorkstation& RemoteWorkstation::operator=(RemoteWorkstation &&R)
		{
			std::swap(d_ptr, R.d_ptr);
			d_ptr->setParent(this);
			delete R.d_ptr;
			R.d_ptr = nullptr;
			return *this;
		}


		RemoteWorkstation::RemoteWorkstation(const RemoteWorkstation &R)
		{
			if (&R != nullptr)
			{
				d_ptr = new RemoteWorkstationPrivate(this);
				d_ptr->m_Hostname = R.d_ptr->m_Hostname;
				d_ptr->m_Mac = R.d_ptr->m_Mac;
				d_ptr->m_Ip = R.d_ptr->m_Ip;
				if (R.d_ptr->m_User != nullptr)
				{
					if (d_ptr->m_User == nullptr)
					{
						d_ptr->m_User = new User(*R.d_ptr->m_User);
					}
					else
					{
						*d_ptr->m_User = *R.d_ptr->m_User;
					}
				}
				d_ptr->m_powerstripeIp = R.d_ptr->m_powerstripeIp;
				d_ptr->m_powerstripeId = R.d_ptr->m_powerstripeId;
				d_ptr->m_remoteboxComPort = R.d_ptr->m_remoteboxComPort;
				d_ptr->m_remoteboxHwId = R.d_ptr->m_remoteboxHwId;
				d_ptr->m_remoteboxSwVersion = R.d_ptr->m_remoteboxSwVersion;
				d_ptr->m_State = R.d_ptr->m_State;
				if (R.d_ptr->m_Project != nullptr)
				{
					if (d_ptr->m_Project == nullptr)
					{
						d_ptr->m_Project = new Project(*R.d_ptr->m_Project);
					}
					else
					{
						*d_ptr->m_Project = *R.d_ptr->m_Project;
					}
				}
				*d_ptr->m_ElementConfiguration = *R.d_ptr->m_ElementConfiguration;
			}
		}

		RemoteWorkstation& RemoteWorkstation::operator=(const RemoteWorkstation &R)
		{
			if (&R != nullptr)
			{
				d_ptr = new RemoteWorkstationPrivate(this);
				d_ptr->m_Hostname = R.d_ptr->m_Hostname;
				d_ptr->m_Mac = R.d_ptr->m_Mac;
				d_ptr->m_Ip = R.d_ptr->m_Ip;
				d_ptr->m_User = R.d_ptr->m_User;
				d_ptr->m_powerstripeIp = R.d_ptr->m_powerstripeIp;
				d_ptr->m_powerstripeId = R.d_ptr->m_powerstripeId;
				d_ptr->m_remoteboxComPort = R.d_ptr->m_remoteboxComPort;
				d_ptr->m_remoteboxHwId = R.d_ptr->m_remoteboxHwId;
				d_ptr->m_remoteboxSwVersion = R.d_ptr->m_remoteboxSwVersion;
				d_ptr->m_State = R.d_ptr->m_State;
				d_ptr->m_ElementConfiguration = R.d_ptr->m_ElementConfiguration;
			}
			return *this;
		}

		RemoteWorkstation::~RemoteWorkstation()
		{
			qDebug() << "Delete " << this;
		}

		QList<ElementConfiguration> *RemoteWorkstation::ElementCfg() const
		{ 
			Q_D(const RemoteWorkstation);
			return const_cast<QList<ElementConfiguration>*>(d->m_ElementConfiguration);
		}

		void RemoteWorkstation::SetElementCfg(QList<ElementConfiguration> *ElementCfg)
		{
			Q_D(RemoteWorkstation);
			d->m_ElementConfiguration = ElementCfg;
			emit ElementCfgChanged();
		}

		void RemoteWorkstation::AddElementCfg(ElementConfiguration& ElementCfg)
		{
			Q_D(RemoteWorkstation);
			d->m_ElementConfiguration->append(ElementCfg);
			emit ElementCfgChanged();
		}


		User* RemoteWorkstation::CurrentUser() const
		{ 
			Q_D(const RemoteWorkstation);
			return const_cast<User*>(d->m_User);
		}

		void RemoteWorkstation::SetCurrentUser(User *CurrentUser)
		{
			Q_D(RemoteWorkstation);
			if (CurrentUser != nullptr)
			{
				CurrentUser->setParent(d);
				d->m_User = CurrentUser;
				emit CurrentUserChanged();
			}
		}

		Project* RemoteWorkstation::AssignedProject() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_Project ;
		}

		void RemoteWorkstation::setAssignedProject(Project* Project)
		{
			Q_D(RemoteWorkstation);
			d->m_Project = Project;
			emit ProjectChanged();
		}

		QString RemoteWorkstation::Hostname() const
		{ 
			Q_D(const RemoteWorkstation);
			return d->m_Hostname;
		}
		
		void RemoteWorkstation::SetHostname(QString Hostname)
		{ 
			Q_D(RemoteWorkstation);
			d->m_Hostname = Hostname;
			emit HostnameChanged();
		}

		QString RemoteWorkstation::Mac() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_Mac;
		}

		void RemoteWorkstation::SetMac(QString Mac)
		{ 
			Q_D(RemoteWorkstation);
			d->m_Mac = Mac;
			emit MacChanged();
		}

		QString RemoteWorkstation::Ip() const
		{ 
			Q_D(const RemoteWorkstation);
			return d->m_Ip;
		}

		void RemoteWorkstation::SetIp(QString Ip)
		{ 
			Q_D(RemoteWorkstation);
			d->m_Ip = Ip;
			emit IpChanged();
		}

		QString RemoteWorkstation::PowerstripeIp() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_powerstripeIp;
		}

		void RemoteWorkstation::SetPowerstripeIp(QString PowerstripIp)
		{
			Q_D(RemoteWorkstation);
			d->m_powerstripeIp = PowerstripIp;
			emit IpChanged();
		}

		QString RemoteWorkstation::PowerstripeId() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_powerstripeId;
		}
		void RemoteWorkstation::SetPowerstripeId(QString PowerstripId)
		{
			Q_D(RemoteWorkstation);
			d->m_powerstripeId = PowerstripId;
			emit PowerstripeIdChanged();
		}

		quint8 RemoteWorkstation::RemoteboxComPort() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_remoteboxComPort;
		}

		void RemoteWorkstation::SetRemoteboxComPort(quint8 RemoteboxComPort)
		{
			Q_D(RemoteWorkstation);
			d->m_remoteboxComPort = RemoteboxComPort;
			emit RemoteboxComPortChanged();
		}

		QString RemoteWorkstation::RemoteboxHwId() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_remoteboxHwId;
		}

		void RemoteWorkstation::SetRemoteboxHwId(QString RemoteboxHwId)
		{
			Q_D(RemoteWorkstation);
			d->m_remoteboxHwId = RemoteboxHwId;
			emit RemoteboxHwIdChanged();
		}

		QString RemoteWorkstation::RemoteboxSwVersion() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_remoteboxSwVersion;
		}

		void  RemoteWorkstation::SetRemoteboxSwVersion(QString RemoteboxSwVersion)
		{
			Q_D(RemoteWorkstation);
			d->m_remoteboxSwVersion = RemoteboxSwVersion;
			emit RemoteboxSwVersionChanged();
		}

		RemoteWorkstationState RemoteWorkstation::State() const
		{
			Q_D(const RemoteWorkstation);
			return d->m_State;
		}

		void RemoteWorkstation::SetState(RemoteWorkstationState State)
		{
			Q_D(RemoteWorkstation);
			d->m_State = State;
			emit StateChanged();
		}
	}
}
