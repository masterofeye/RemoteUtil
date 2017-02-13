#include "LogEntry.h"
#include "LogEntry_p.h"
#include "qdebug.h"

namespace RW{
	namespace SQL{

		LogEntryPrivate::LogEntryPrivate(LogEntry* Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_ComputerName(""),
			m_Date(QDateTime::currentDateTime()),
			m_ErrorID(0),
			m_LogLevel(""),
			m_Message(""),
			m_ThreadID(0),
			m_Type("")
		{

		}

		LogEntryPrivate::~LogEntryPrivate()
		{
		}

		LogEntry::LogEntry(QObject *Parent) : Entity(Parent),
			d_ptr(new LogEntryPrivate(this))
		{
		}


		LogEntry::~LogEntry()
		{
		}

		LogEntry::LogEntry(const LogEntry& other)
		{
			if (&other != nullptr)
			{
				d_ptr = new LogEntryPrivate(this);
				d_ptr->m_Date = other.d_ptr->m_Date;
				d_ptr->m_ThreadID = other.d_ptr->m_ThreadID;
				d_ptr->m_ErrorID = other.d_ptr->m_ErrorID;
				d_ptr->m_LogLevel = other.d_ptr->m_LogLevel;
				d_ptr->m_ComputerName = other.d_ptr->m_ComputerName;
				d_ptr->m_Message = other.d_ptr->m_Message;
				d_ptr->m_Type = other.d_ptr->m_Type;
			}
		}

		LogEntry& LogEntry::operator=(LogEntry& other)
		{
			if (&other != nullptr)
			{
				d_ptr = new LogEntryPrivate(this);
				d_ptr->m_Date = other.d_ptr->m_Date;
				d_ptr->m_ThreadID = other.d_ptr->m_ThreadID;
				d_ptr->m_ErrorID = other.d_ptr->m_ErrorID;
				d_ptr->m_LogLevel = other.d_ptr->m_LogLevel;
				d_ptr->m_ComputerName = other.d_ptr->m_ComputerName;
				d_ptr->m_Message = other.d_ptr->m_Message;
				d_ptr->m_Type = other.d_ptr->m_Type;
			}
			return *this;
		}


		LogEntry::LogEntry(LogEntry&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		LogEntry& LogEntry::operator = (LogEntry&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}



		QDateTime LogEntry::Date()
		{
			Q_D(LogEntry);
			return d->m_Date;
		}

		void LogEntry::SetDate(QDateTime Date)
		{
			Q_D(LogEntry);
			d->m_Date = Date;
			emit DateChanged();
		}

		QString LogEntry::Message()
		{
			Q_D(LogEntry);
			return d->m_Message;
		}

		void LogEntry::SetMessage(QString Message)
		{
			Q_D(LogEntry);
			d->m_Message = Message;
			emit MessageChanged();
		}


		QString LogEntry::LogLevel()
		{
			Q_D(LogEntry);
			return d->m_LogLevel;
		}
		void LogEntry::SetLogLevel(QString Level)
		{
			Q_D(LogEntry);
			d->m_LogLevel = Level;
			emit LogLevelChanged();
		}

		quint16 LogEntry::ThreadID()
		{
			Q_D(LogEntry);
			return d->m_ThreadID;
		}
		void LogEntry::SetThreadID(quint16 ThreadID)
		{
			Q_D(LogEntry);
			d->m_ThreadID = ThreadID;
			emit ThreadIDChanged();
		}

		quint64 LogEntry::ErrorID()
		{
			Q_D(LogEntry);
			return d->m_ErrorID;
		}
		void LogEntry::SetErrorID(quint64 ErrorID)
		{
			Q_D(LogEntry);
			d->m_ErrorID;
			emit ErrorIDChanged();
		}

		QString LogEntry::Type()
		{
			Q_D(LogEntry);
			return d->m_Type;
		}
		void LogEntry::SetType(QString Type)
		{
			Q_D(LogEntry);
			d->m_Type = Type;
			emit TypeChanged();
		}

		QString LogEntry::ComputerNameRW()
		{
			Q_D(LogEntry);
			return d->m_ComputerName;
		}


		void LogEntry::SetComputerNameRW(QString ComputerName)
		{
			Q_D(LogEntry);
			d->m_ComputerName = ComputerName;
			emit ComputerNameRWChanged();
		}
	}
}