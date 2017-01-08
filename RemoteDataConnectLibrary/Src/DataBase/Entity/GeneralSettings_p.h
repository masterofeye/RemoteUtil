#pragma once

#include <qobject.h>
#include "SQLGlobal.h"

namespace RW
{
	namespace SQL{

		class GeneralSettings;
		class GeneralSettingsPrivate : public QObject
		{
			Q_OBJECT
				Q_DISABLE_COPY(GeneralSettingsPrivate)
				Q_DECLARE_PUBLIC(GeneralSettings)
		private:
			GeneralSettings * const q_ptr;
		public:
			quint64 m_ID;
		public:
			GeneralSettingsPrivate(GeneralSettings *Parent);
			~GeneralSettingsPrivate();
		};
	}
}