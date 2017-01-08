#pragma once
#include "Entity.h"

namespace RW
{
	namespace SQL
	{
		class GeneralSettingsPrivate;
		class REMOTE_DATA_CONNECT_API GeneralSettings :
			public Entity
		{
			Q_OBJECT
			//Q_PROPERTY(QString Step MEMBER m_Step READ Step WRITE SetStep NOTIFY StepChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
			GeneralSettingsPrivate* d_ptr;
			Q_DECLARE_PRIVATE(GeneralSettings);

			GeneralSettings(const GeneralSettings& other);
			GeneralSettings& GeneralSettings::operator=(GeneralSettings& other);

			GeneralSettings(GeneralSettings&& other);
			GeneralSettings& GeneralSettings::operator=(GeneralSettings&& other);

		public:
			GeneralSettings(QObject *Parent = nullptr);
			~GeneralSettings();

		signals:
		};
	}
}
