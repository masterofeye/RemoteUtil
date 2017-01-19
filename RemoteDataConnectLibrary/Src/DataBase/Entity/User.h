#pragma once
#include "Entity.h"

namespace RW{
	enum class UserRole;
	namespace SQL{


		class UserPrivate;
		class REMOTE_DATA_CONNECT_API User :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(QString UserName READ UserName WRITE SetUserName NOTIFY UserNameChanged)
			Q_PROPERTY(QString Initials READ Initials WRITE SetInitials NOTIFY InitialsChanged)
			Q_PROPERTY(QString MKSUsername READ MKSUsername WRITE SetMKSUsername NOTIFY MKSUsernameChanged)
			Q_PROPERTY(QString MKSPassword READ MKSPassword WRITE SetMKSPassword NOTIFY MKSPasswordChanged)
			Q_PROPERTY(QString Password READ Password WRITE SetPassword NOTIFY PasswordChanged)
			Q_PROPERTY(bool NotifiyRemoteDesktop READ NotifiyRemoteDesktop WRITE SetNotifiyRemoteDesktop NOTIFY NotifiyRemoteDesktopChanged)
			Q_PROPERTY(bool NotifiyDesktop READ NotifiyDesktop WRITE SetNotifiyDesktop NOTIFY NotifiyDesktopChanged)
			Q_PROPERTY(UserRole Role READ Role WRITE SetRole NOTIFY RoleChanged)
			Q_CLASSINFO("Version", "0.0.1")

		private:
			UserPrivate *d_ptr;
			Q_DECLARE_PRIVATE(User);
		public:
			User(QObject *Parent = nullptr);
			~User();

			User(const User& other);
			User& User::operator=(User& other);

			User(User&& other);
			User& User::operator=(User&& other);

			QString UserName() const;
			void SetUserName(QString UserName);

			QString Initials() const;
			void SetInitials(QString Initials);

			QString MKSUsername() const;
			void SetMKSUsername(QString Username);

			QString MKSPassword() const;
			void SetMKSPassword(QString Password);

			QString Password() const;
			void SetPassword(QString Password);

			bool NotifiyRemoteDesktop() const;
			void SetNotifiyRemoteDesktop(bool NotifiyRemoteDesktop);

			bool NotifiyDesktop() const;
			void SetNotifiyDesktop(bool NotifiyDesktop);

			UserRole Role() const;
			void SetRole(UserRole Role);

		signals:
			void UserNameChanged();
			void PasswordChanged();
			void InitialsChanged();
			void MKSUsernameChanged();
			void MKSPasswordChanged();
			void NotifiyRemoteDesktopChanged();
			void NotifiyDesktopChanged();
			void RoleChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::User)