#include "RemoteWorkstation.h"
#include "RemoteWorkstation_p.h"


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
			m_ElementConfiguration(new QList<ElementConfiguration>())
		{
		}

		RemoteWorkstationPrivate::~RemoteWorkstationPrivate()
		{
			if (m_ElementConfiguration != nullptr)
			{
				//qDeleteAll(m_ElementConfiguration);
				delete m_ElementConfiguration;
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


		RemoteWorkstation::RemoteWorkstation(const RemoteWorkstation &R) :
			d_ptr(const_cast<RemoteWorkstationPrivate*>(R.d_ptr))
		{
			d_ptr->setParent(this);
		}

		RemoteWorkstation& RemoteWorkstation::operator=(const RemoteWorkstation &R)
		{
			d_ptr->setParent(this);
			std::swap(d_ptr, const_cast<RemoteWorkstationPrivate*>(R.d_ptr));
			return *this;
		}

		RemoteWorkstation::~RemoteWorkstation()
		{
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

		QString RemoteWorkstation::hostname() const
		{ 
			Q_D(const RemoteWorkstation);
			return d->m_Hostname;
		}
		
		void RemoteWorkstation::setHostname(QString Hostname)
		{ 
			Q_D(RemoteWorkstation);
			d->m_Hostname = Hostname;
			emit hostnameChanged();
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
	}
}
