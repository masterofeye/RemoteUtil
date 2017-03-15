#pragma once
#include "qobject.h"
#include "..\SQLGlobal.h"
#include <memory>



namespace RW{
	namespace SQL{

		class RemoteWorkstation;
		class User;
		class LogEntry;
		class ElementType;
		class Product;
		class Instruction;
		class ElementConfiguration;
		class Recept;
		class Project;
		class Device;

		/*
		@brief Schnittstelle zwischen dem Datenzugriff von Clienten und externen Datenquellen. Jeder Zugriff auf externe Datenquellen
		(File, Datenbank) muss �ber ein Repository erfolgen.
		*/
		class REMOTE_DATA_CONNECT_API Repository :
			public QObject
		{
		private:
			/*
			@brief Instanz des Loggers
			*/
			std::shared_ptr<spdlog::logger> m_logger;

			/*
			@brief Type der aktuell verwendeteten Quelle dieses Datenmappers. Wird durch den Kontruktor gesetzt.
			*/
			SourceType m_Source;
		public:
			Repository(SourceType Source, QObject* Parent = nullptr);

			Repository(SourceType Source, std::shared_ptr<spdlog::logger> Logger, QObject* Parent = nullptr);
			~Repository();

			/*
			@brief F�gt das �bergebene RemoteWorkstation Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz, der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertRemoteWorkstation(RemoteWorkstation &R);

			/*
			@brief F�gt das �bergebene User Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertUser(User &U);

			/*
			@brief F�gt das �bergebene ElementType Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertElementType(ElementType &E);

			/*
			@brief F�gt das �bergebene ElementConfiguration Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertElementConfiguration(ElementConfiguration &E);

			/*
			@brief F�gt das �bergebene Product Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertProduct(Product &P);

			/*
			@brief F�gt das �bergebene Recept Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertRecept(Recept &R);

			/*
			@brief F�gt das �bergebene Instruction Objekt der Datenbank hinzu.
			@param [in] RemoteWorkstation Instanz der Daten die an die Datenbank �bertragen werden sollen.
			*/
			bool InsertInstruction(Instruction &I);

			/*
			@brief F�gt einen LogEintray dem Repository hinzu
			@param [in] LogEntry Logeintrag mit allen wichtigen Informationen
			*/
			bool InsertLogEntry(LogEntry &E);

			bool InsertProject(Project &P);
			bool InsertDevice(Device &P);

			/*
			@brief Liefert eine Instanz zur�ck die der �bergebenen ID entspricht. 
			Diese Funktion liefert nur eine g�ltige Instanz zur�ck, wenn die Datenquelle die Datenbank ist.  
			@param [in] ID ID des Eintrags in der Tabelle
			@param [out] R Instanz der Remoteworkstation welche der ID entspricht
			*/
			bool GetRemoteWorkstationByID(quint64 ID, RemoteWorkstation& R);
			bool GetUserByID(quint64 ID, User& U);
			bool GetElementConfigurationByID(quint64 ID, ElementConfiguration& E);
			bool GetElementTypeByID(quint64 ID, ElementType& E);
			bool GetProductByID(quint64 ID, Product& P);
			bool GetInstructionByID(quint64 ID, Instruction& I);
			bool GetReceptByID(quint64 ID, Recept& R);
			bool GetLogEntryByID(quint64 ID, LogEntry& L);
			bool GetProjectByID(quint64 ID, Project& P);
			bool GetDeviceByID(quint64 ID, Device& P);

			bool GetAllRemoteWorkstation(QList<RemoteWorkstation> & AllR);
			bool GetAllUser(QList<User> & AllR);
			bool GetAllElementConfiguration(QList<ElementConfiguration> & AllR);
			bool GetAllElementType(QList<ElementType> & AllR);
			bool GetAllInstruction(QList<Instruction> & AllR);
			bool GetAllRecept(QList<Recept> & AllR);
			bool GetAllProduct(QList<Product> & AllR);
			bool GetAllLogEntry(QList<LogEntry> & AllR);
			bool GetAllProject(QList<Project> & AllR);
			bool GetAllDevice(QList<Device> & AllR);

			bool GetUserByName(QString Name, User& U);

		};
	}
}
