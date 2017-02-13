#pragma once
#include "Entity.h"

namespace RW{
	namespace SQL{

		class ProjectPrivate;
		class REMOTE_DATA_CONNECT_API Project :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(QString Projectname READ Projectname WRITE SetProjectname NOTIFY ProjectnameChanged)
			Q_CLASSINFO("Version", "0.0.1")

		private:
			ProjectPrivate *d_ptr;
			Q_DECLARE_PRIVATE(Project);
		public:
			Project(QObject *Parent = nullptr);
			~Project();

			Project(const Project& other);
			Project& Project::operator=(Project& other);

			Project(Project&& other);
			Project& Project::operator=(Project&& other);

			QString Projectname() const;
			void SetProjectname(QString ProjectName);


		signals:
			void ProjectnameChanged();

		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::Project)