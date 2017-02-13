#pragma once
#include "Entity.h"
#include <qdatetime.h>

namespace RW
{
	namespace SQL
	{
		class LogEntryPrivate;
		class REMOTE_DATA_CONNECT_API LogEntry :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(QDateTime LogTime READ Date WRITE SetDate NOTIFY DateChanged)
			Q_PROPERTY(QString Message READ Message WRITE SetMessage NOTIFY MessageChanged)
			Q_PROPERTY(QString LogLevel READ LogLevel WRITE SetLogLevel NOTIFY LogLevelChanged)
			Q_PROPERTY(quint16 ThreadID READ ThreadID WRITE SetThreadID NOTIFY ThreadIDChanged)
			Q_PROPERTY(quint64 ErrorID READ ErrorID WRITE SetErrorID NOTIFY ErrorIDChanged)
			Q_PROPERTY(QString Type READ Type WRITE SetType NOTIFY TypeChanged)
			Q_PROPERTY(QString ComputerNameRW READ ComputerNameRW WRITE SetComputerNameRW NOTIFY ComputerNameRWChanged)
			Q_CLASSINFO("Version", "0.0.1")

		private:
			LogEntryPrivate *d_ptr;
			Q_DECLARE_PRIVATE(LogEntry);
		public:
			LogEntry(QObject *Parent = nullptr);
			~LogEntry();

			LogEntry(const LogEntry& other);
			LogEntry& LogEntry::operator=(LogEntry& other);

			LogEntry(LogEntry&& other);
			LogEntry& LogEntry::operator=(LogEntry&& other);

			QDateTime Date();
			void SetDate(QDateTime);

			QString Message();
			void SetMessage(QString);

			QString LogLevel();
			void SetLogLevel(QString Level);

			quint16 ThreadID();
			void SetThreadID(quint16 ThreadID);

			quint64 ErrorID();
			void SetErrorID(quint64 ErrorID);

			QString Type();
			void SetType(QString Type);

			QString ComputerNameRW();
			/*
			@brief Setzt den Computernamen für das aktuelle LogEntry Objekt. Der Underscore ist wichtig
			um die Methode von der Win32API zu unterscheiden.
			@param ComputerName aktueller Computername
			@return void
			*/
			void SetComputerNameRW(QString ComputerName);

		signals: 
			void DateChanged();
			void MessageChanged();
			void LogLevelChanged();
			void ThreadIDChanged();
			void ErrorIDChanged();
			void TypeChanged();
			void ComputerNameRWChanged();
		};

	}
}
Q_DECLARE_METATYPE(RW::SQL::LogEntry)