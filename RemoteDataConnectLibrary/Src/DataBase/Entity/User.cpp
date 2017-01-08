#include "User.h"
#include "User_p.h"

#include "qdebug.h"
namespace RW{
	namespace SQL{

		UserPrivate::UserPrivate(User* Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_Initials(""),
			m_MKSPassword(""),
			m_MKSUsername(""),
			m_NotifiyDesktop(false),
			m_NotifiyRemoteDesktop(false),
			m_UserName(""),
			m_Password("")
		{
		}

		UserPrivate::~UserPrivate()
		{
		}


		User::User(const User& other) : d_ptr(const_cast<UserPrivate*>(other.d_ptr))
		{

		}
		User& User::operator=(User& other) 
		{
			std::swap(d_ptr, const_cast<UserPrivate*>(other.d_ptr));
			d_ptr->setParent(this);
			return *this;
		}


		User::User(User&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		User& User::operator=(User&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}

		User::User(QObject *Parent) : Entity(Parent),
		d_ptr(new UserPrivate(this))
		{
		}


		User::~User()
		{
		}


		QString User::UserName() const
		{
			Q_D(const User);
			return d->m_UserName;
		}

		void User::SetUserName(QString Username)
		{
			Q_D(User);
			d->m_UserName = Username;
			emit UserNameChanged();
		}

		QString User::Initials() const
		{
			Q_D(const User);
			return d->m_Initials;
		}

		void User::SetInitials(QString Initials)
		{
			Q_D(User);
			d->m_Initials = Initials;
			emit InitialsChanged();
		}

		QString User::MKSUsername() const
		{
			Q_D(const User);
			return d->m_MKSUsername;
		}


		void User::SetMKSUsername(QString Username)
		{
			Q_D(User);
			d->m_MKSUsername = Username;
			emit MKSUsernameChanged();
		}

		QString User::MKSPassword() const
		{
			Q_D(const User);
			return d->m_MKSPassword;
		}

		void User::SetMKSPassword(QString Password)
		{
			Q_D(User);
			d->m_MKSPassword = Password;
			emit MKSPasswordChanged();
		}

		QString User::Password() const
		{
			Q_D(const User);
			return d->m_Password;
		}

		void User::SetPassword(QString Password)
		{
			Q_D(User);
			d->m_Password = Password;
			emit PasswordChanged();
		}

		bool User::NotifiyRemoteDesktop() const
		{
			Q_D(const User);
			return d->m_NotifiyRemoteDesktop;
		}
		void User::SetNotifiyRemoteDesktop(bool NotifiyRemoteDesktop)
		{
			Q_D(User);
			d->m_NotifiyRemoteDesktop = NotifiyRemoteDesktop;
			emit NotifiyRemoteDesktopChanged();
		}

		bool User::NotifiyDesktop() const
		{
			Q_D(const User);
			return d->m_NotifiyDesktop;
		}
		void User::SetNotifiyDesktop(bool NotifiyDesktop)
		{
			Q_D(User);
			d->m_NotifiyDesktop = NotifiyDesktop;
			emit NotifiyDesktopChanged();
		}
	}
}