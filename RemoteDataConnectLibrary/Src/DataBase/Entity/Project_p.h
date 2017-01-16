#pragma once
#include <qobject.h>

namespace RW{
	namespace SQL{

		class Project;
		class ProjectPrivate : public QObject
		{
			Q_OBJECT
				Q_DISABLE_COPY(ProjectPrivate)
				Q_DECLARE_PUBLIC(Project)
		public:
			QString m_ProjectName;
		private:
			Project * const q_ptr;
		public:
			ProjectPrivate(Project *Parent);
			~ProjectPrivate();
		};
	}
}