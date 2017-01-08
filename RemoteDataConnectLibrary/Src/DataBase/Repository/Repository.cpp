#include "Repository.h"
#include "SqlGlobal.h"

#include "AllEntities.h"

#include "DataFactory.h"
#include "DataMapper.h"
#include "spdlog\spdlog.h"

namespace RW{
	namespace SQL{
		Repository::Repository(SourceType Source, QObject* Parent) : QObject(Parent),
			m_Source(Source)
		{

		}

		Repository::Repository(SourceType Source, std::shared_ptr<spdlog::logger> Logger, QObject* Parent) : QObject(Parent),
			m_Source(Source),
			m_logger(Logger)
		{
		}

		Repository::~Repository()
		{
		}

		bool Repository::InsertRemoteWorkstation(RemoteWorkstation &R)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<RemoteWorkstation> *dm = d.GetMapper<RemoteWorkstation>(m_Source);
			res = dm->Insert(R);
			delete dm;
			return res;
		}

		bool Repository::InsertLogEntry(LogEntry &E)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
			res = dm->Insert(E);
			delete dm;
			return res;
		}

		bool Repository::InsertUser(User &U)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<User> *dm = d.GetMapper<User>(m_Source);
			res = dm->Insert(U);
			delete dm;
			return res;
		}

		bool Repository::InsertElementType(ElementType &E)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<ElementType> *dm = d.GetMapper<ElementType>(m_Source);
			res = dm->Insert(E);
			delete dm;
			return res;
		}

		bool Repository::InsertElementConfiguration(ElementConfiguration &E)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<ElementConfiguration> *dm = d.GetMapper<ElementConfiguration>(m_Source);
			res = dm->Insert(E);
			delete dm;
			return res;
		}

		bool Repository::InsertProduct(Product &P)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Product> *dm = d.GetMapper<Product>(m_Source);
			res = dm->Insert(P);
			delete dm;
			return res;
		}

		bool Repository::InsertInstruction(Instruction &I)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Instruction> *dm = d.GetMapper<Instruction>(m_Source);
			res = dm->Insert(I);
			delete dm;
			return res;
		}

		bool Repository::InsertRecept(Recept &R)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Recept> *dm = d.GetMapper<Recept>(m_Source);
			res = dm->Insert(R);
			delete dm;
			return res;
		}

		bool Repository::GetRemoteWorkstationByID(quint64 ID, RemoteWorkstation& R)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<RemoteWorkstation> *dm = d.GetMapper<RemoteWorkstation>(m_Source);
				R = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetRemoteWorkstationByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetUserByID(quint64 ID, User& U)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<User> *dm = d.GetMapper<User>(m_Source);
				U = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetUserByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetElementConfigurationByID(quint64 ID, ElementConfiguration& E)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementConfiguration> *dm = d.GetMapper<ElementConfiguration>(m_Source);
				E = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetElementConfigurationByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetElementTypeByID(quint64 ID, ElementType& E)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementType> *dm = d.GetMapper<ElementType>(m_Source);
				E = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetElementConfigurationByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetProductByID(quint64 ID, Product& P)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Product> *dm = d.GetMapper<Product>(m_Source);
				P = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetProductByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetInstructionByID(quint64 ID, Instruction& I)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Instruction> *dm = d.GetMapper<Instruction>(m_Source);
				I = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetInstructionByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetReceptByID(quint64 ID, Recept& R)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Recept> *dm = d.GetMapper<Recept>(m_Source);
				R = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetReceptByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetLogEntryByID(quint64 ID, LogEntry& L)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
				L = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLogEntryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllRemoteWorkstation(QList<RemoteWorkstation> &AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<RemoteWorkstation> *dm = d.GetMapper<RemoteWorkstation>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLogEntryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllUser(QList<User> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<User> *dm = d.GetMapper<User>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLogEntryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllElementConfiguration(QList<ElementConfiguration> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementConfiguration> *dm = d.GetMapper<ElementConfiguration>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllElementConfiguration throwed a exception");
				return false;
			}
			return true;
		}


		bool Repository::GetAllElementType(QList<ElementType> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementType> *dm = d.GetMapper<ElementType>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllElementType throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllInstruction(QList<Instruction> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Instruction> *dm = d.GetMapper<Instruction>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllInstruction throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllRecept(QList<Recept> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Recept> *dm = d.GetMapper<Recept>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllRecept throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllProduct(QList<Product> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Product> *dm = d.GetMapper<Product>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllProduct throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllLogEntry(QList<LogEntry> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllLogEntry throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetUserByName(QString Name, User& U)
		{
			QList<User> list;
			try{
				DataFactory d(m_logger);
				DataMapper<User> *dm = d.GetMapper<User>(m_Source);
				list = dm->FindAll();
				for each (auto var in list)
				{
					if (var.UserName() == Name)
						U = var;
				}

				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetUserByID throwed a exception");
				return false;
			}
			return true;
		}
	}
}