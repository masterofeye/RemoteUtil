#pragma once
#include <qobject.h>
#include "SQLGlobal.h"

namespace RW{
	namespace SQL{

		class User;
		class UserPrivate: public QObject
		{
			Q_OBJECT
			Q_DISABLE_COPY(UserPrivate)
			Q_DECLARE_PUBLIC(User)
		public: 
			QString m_UserName;
			QString m_Initials;
			QString m_MKSUsername;
			QString m_MKSPassword;
			QString m_Password;
			bool m_NotifiyRemoteDesktop;
			bool m_NotifiyDesktop;
			UserRole m_Role;
		private:
			User * const q_ptr;
		public:
			UserPrivate(User *Parent);
			~UserPrivate();

		};
	}
}