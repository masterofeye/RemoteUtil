#pragma once
#include "DataMapper.h"
#include "AllEntities.h"
#include "qsqlquery.h"
#include "qvariant.h"
#include "qdatetime.h"
#include "qdebug.h"
#include "qsqlerror.h"
#include "spdlog/spdlog.h"


namespace RW{
	namespace SQL{

		const QString Insert_RemoteWorkstation = "INSERT INTO remoteWorkstation (userID,hostname,mac,ip,powerstripeIp,powerstripeId,remoteboxComPort,remoteboxHwId,remoteboxSwVersion,state,projectID) VALUES (:user,:hostname,:mac,:ip,:powerstripeIp,:powerstripeId,:remoteboxComPort,:remoteboxHwId,:remoteboxSwVersion,:state,( SELECT idProject FROM project WHERE name=:name))";
		const QString Insert_User = "INSERT INTO user (username,password,mksUsername,mksPassword,initials,notifiyRemoteDesktop,notifiyDesktop,role ) VALUES (:username,:password,:mksUsername,:mksPassword,:initials,:notifiyRemoteDesktop,:notifiyDesktop, :role)";
		const QString Insert_ElementConfiguration = "INSERT INTO elementConfiguration (remoteWorkstationID, elementTypeID, displayName, name, groupName, function, tooltip, remoteViewRelevant, isFeature, pin) VALUES (:remoteWorkstationID, (SELECT idElementType FROM elementType WHERE type=:type),:displayName,:name,:groupName,:function,:tooltip,:remoteViewRelevant, :isFeature, :pin)";
		const QString Insert_ElementType = "INSERT INTO elementType (type) VALUES (:type)";
		const QString Insert_Instruction = "INSERT INTO instruction (step) VALUES (:step)";
		const QString Insert_Recept = "INSERT INTO recept (receptName,orderNumber,instructionID) VALUES (:receptName,:orderNumber,:instructionID)";
		const QString Insert_Product = "INSERT INTO product (productName,part,receptID) VALUES (:productName,:part,:receptID)";
		const QString Insert_LogEntry = "INSERT INTO log (date,message,loglevel,threadId,errorId,type,computerName) VALUES (:datetime,:message,:loglevel,:threadId,:errorId,:type,:computerName)";
		const QString Insert_Project = "INSERT INTO project (name) VALUES (:name)";

		const QString Update_RemoteWorkstation = "UPDATE remoteWorkstation SET userID=( SELECT idUser FROM user WHERE user=:user),hostname=:hostname,mac=:mac,ip=:ip,powerstripeIp=:powerstripeIp,powerstripeId=:powerstripeId,remoteboxComPort=:remoteboxComPort,remoteboxHwId=:remoteboxHwId,remoteboxSwVersion=:remoteboxSwVersion, state=:state, projectID=( SELECT idProject FROM project WHERE name=:name) WHERE idRemoteWorkstation=:id";
		const QString Update_User = "UPDATE user SET username=:username,password=:password,mksUsername=:mksUsername,mksPassword=:mksPassword,initials=:intitials,notifiyRemoteDesktop=:notifiyRemoteDesktop,notifiyDesktop=:notifiyDesktop, role=:role";
		const QString Update_ElementConfiguration = "UPDATE elementConfiguration SET remoteWorkstationID=:remoteWorkstationID,type=:type,displayName=:displayName,name=:name,groupName=:groupName,function=:function, tooltip=:tooltip, remoteViewRelevant=:remoteViewRelevant, isFeature=:isFeature, pin=:pin";
		const QString Update_ElementType = "UPDATE elementType SET type=:type";
		const QString Update_Instruction = "UPDATE instruction SET step=:step";
		const QString Update_Recept = "UPDATE recept SET receptName=:receptName,orderNumber=:orderNumber,instructionID=:instructionID";
		const QString Update_Product = "UPDATE product SET productName=:productName,part=:part,receptID=:receptID";
		const QString Update_LogEntry = "UPDATE log SET datetime=:datetime,message=:message,loglevel=:loglevel,threadId=:threadId,errorId=:errorId,type=:type,computerName=:computerName";
		const QString Update_Project = "UPDATE project SET name=:name";

		const QString Delete_RemoteWorkstattion = "DELETE FROM remoteWorkstation WHERE idRemoteWorkstation=:idRemoteWorkstation";
		const QString Delete_User = "DELETE FROM user WHERE idUser=:idUser";
		const QString Delete_ElementConfiguration = "DELETE FROM elementConfiguration WHERE idElementConfiguration=:idElementConfiguration";
		const QString Delete_ElementType = "DELETE FROM elementType WHERE idElementType=:idElementType";
		const QString Delete_Instruction = "DELETE FROM instruction WHERE idIntruction=:idIntruction";
		const QString Delete_Recept = "DELETE FROM recept WHERE idRecept=:idRecept";
		const QString Delete_Product = "DELETE FROM product WHERE idProduct=:idProduct";
		const QString Delele_LogEntry = "DELETE FROM log WHERE idLogEntry=:idLogEntry";
		const QString Delele_Project = "DELETE FROM project WHERE idProject=:idProject";

		const QString SelectById_RemoteWorkstation = "SELECT * FROM remoteWorkstation WHERE idRemoteWorkstation = :idRemoteWorkstation";
		const QString SelectById_User = "SELECT * FROM user WHERE idUser = :idUser";
		const QString SelectById_ElementConfiguration = "SELECT * FROM elementConfiguration WHERE idElementConfiguration = :idElementConfiguration";
		const QString SelectById_ElementType = "SELECT * FROM elementType WHERE idElementType = :idElementType";
		const QString SelectById_Instruction = "SELECT * FROM Instruction WHERE idInstruction = :idInstruction";
		const QString SelectById_Recept = "SELECT * FROM recept WHERE idRecept = :idRecept";
		const QString SelectById_Product = "SELECT * FROM product WHERE idProduct = :idProduct";
		const QString SelectById_LogEntry = "SELECT * FROM log WHERE idLogEntry=:idLogEntry";
		const QString SelectById_Project = "SELECT * FROM project WHERE idProject=:idProject";

		const QString SelectAll_RemoteWorkstation = "SELECT * FROM remoteWorkstation";
		const QString SelectAll_User = "SELECT * FROM user";
		const QString SelectAll_ElementConfiguration = "SELECT * FROM elementConfiguration";
		const QString SelectAll_ElementType = "SELECT * FROM elementType";
		const QString SelectAll_Instruction = "SELECT * FROM Instructio";
		const QString SelectAll_Recept = "SELECT * FROM recept";
		const QString SelectAll_Product = "SELECT * FROM product";
		const QString SelectAll_LogEntry = "SELECT * FROM log";
		const QString SelectAll_Project = "SELECT * FROM project";

		const QString Select_ElementConfigurationByRemoteWorkstationID = "SELECT el.remoteWorkstationID, t.type = type ,el.displayName,el.name,el.groupName, el.function, el.tooltip FROM elementConfiguration el join elementType t on el.elementTypeID = t.idElementType WHERE el.remoteWorkstationID = :remoteWorkstationID";
		const QString SelectLastID = "SELECT idRemoteWorkstation from remoteWorkstation ORDER BY idRemoteWorkstation DESC LIMIT 1;";
		class Entity;
		template<class T>
		class MySqlMapper :
			public DataMapper<T>
		{
		private:
			std::shared_ptr<spdlog::logger> m_logger;

		public:
			MySqlMapper(std::shared_ptr<spdlog::logger> Logger, QObject* Parent = nullptr) : DataMapper<T>(Parent),
				m_logger(Logger)
			{

				QSqlDatabase db = QSqlDatabase::database();
				if (!db.isOpen())
				{

					db = QSqlDatabase::addDatabase("QMYSQL");
					db.setHostName("localhost");
					db.setPort(3306);
					db.setDatabaseName("remoteworkstation");
					db.setUserName("remoteUser");
					db.setPassword("schleissheimer");

					//Please see the link for QT5: http://seppemagiels.com/blog/create-mysql-driver-qt5-windows => qsqlmysql.dll and libmysql.dll
					//(and libmysql.lib, if your installation of MySQL has it) are needed
					db.open();
				}

			}
			~MySqlMapper(){}

			bool Insert(const T &Data){ return false; }
			bool Update(const T &Data){ return false; }

			T FindByID(const quint64 id, bool Flag){ return new T(); }
			template<class Y> Y FindByID(const quint64 ID){
				MySqlMapper<Y> temp(this->m_logger);
				return temp.FindByID(ID, true);
			}
			QList<T> FindAll(){ QList<T> m; return std::move(m); }

		};

		template<> bool MySqlMapper<LogEntry>::Insert(const LogEntry &Data)
		{
			LogEntry d(Data);

			QSqlQuery query;
			query.prepare(Insert_LogEntry);
			query.bindValue(":datetime", d.Date());
			query.bindValue(":message", d.Message());
			query.bindValue(":loglevel", d.LogLevel());
			query.bindValue(":threadId", d.ThreadID());
			query.bindValue(":errorId", d.ErrorID());
			query.bindValue(":type", d.Type());
			query.bindValue(":computerName", d.ComputerName());

			bool res = query.exec();
			if (!res)
			{
				qDebug() << query.lastError().text();
			}
			return res;
		}


		template<> bool MySqlMapper<RemoteWorkstation>::Insert(const RemoteWorkstation &Data)
		{
			RemoteWorkstation d(Data);

			QSqlQuery query;
			quint64 id;
			query.prepare(Insert_RemoteWorkstation);
			if (d.CurrentUser() == nullptr)
				query.bindValue(":user", QVariant(QVariant::UserType));
			else
				query.bindValue(":user", d.CurrentUser()->ID());
			query.bindValue(":hostname", d.Hostname());
			query.bindValue(":mac", d.Mac());
			query.bindValue(":ip", d.Ip());
			query.bindValue(":powerstripeIp", d.PowerstripeIp());
			query.bindValue(":powerstripeId", d.PowerstripeId());
			query.bindValue(":remoteboxComPort", d.RemoteboxComPort());
			query.bindValue(":remoteboxHwId", d.RemoteboxHwId());
			query.bindValue(":remoteboxSwVersion", d.RemoteboxSwVersion());
			query.bindValue(":state",(int) d.State());
			if (d.AssignedProject() == nullptr)
			{
				m_logger->error("Project entry can't be NULL!");
				return false;
			}
			else
				query.bindValue(":name", d.AssignedProject()->Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl remoteWorkstation insert failed. Error: {}", query.lastError().text().toStdString());
			}
			else
			{
				bool res = query.exec(SelectLastID);
				while (query.next()) {
					id = query.value(0).toInt();
				}

				for each (auto var in d.ElementCfg())
				{
					QSqlQuery query;
					query.prepare(Insert_ElementConfiguration);
					query.bindValue(":remoteWorkstationID", id);
					query.bindValue(":type", (int)var->Type()->Type());
					query.bindValue(":displayName", var->DisplayName());
					query.bindValue(":name", var->Name());
					query.bindValue(":groupName", var->GroupName());
					query.bindValue(":function", var->Function());
					query.bindValue(":tooltip", var->ToolTip());
					query.bindValue(":remoteViewRelevant", var->RemoteViewRelevant());
					query.bindValue(":isFeature", var->IsFeature());
					query.bindValue(":pin", var->Pin());

					res = query.exec();
					if (!res)
					{
						m_logger->error("Tbl elementConfiguration insert failed. Error: {}", query.lastError().text().toStdString());
					}
				}
			}
			return res;
		}

		template<> bool MySqlMapper<User>::Insert(const User &Data)
		{
			User d(Data);

			QSqlQuery query;
			query.prepare(Insert_User);
			query.bindValue(":username", d.UserName());
			query.bindValue(":password", d.Password());
			query.bindValue(":mksUsername", d.MKSUsername());
			query.bindValue(":mksPassword", d.MKSPassword());
			query.bindValue(":initials", d.Initials());
			query.bindValue(":notifiyRemoteDesktop", d.NotifiyRemoteDesktop());
			query.bindValue(":notifiyDesktop", d.NotifiyDesktop());
			query.bindValue(":role", (int)d.Role());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl user insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


		template<> bool MySqlMapper<ElementConfiguration>::Insert(const ElementConfiguration &Data)
		{
			ElementConfiguration d(Data);

			QSqlQuery query;
			query.prepare(Insert_ElementConfiguration);
			query.bindValue(":type", (int)d.Type()->Type());
			query.bindValue(":displayName", d.DisplayName());
			query.bindValue(":name", d.Name());
			query.bindValue(":groupName", d.GroupName());
			query.bindValue(":function", d.Function());
			query.bindValue(":remoteViewRelevant", d.RemoteViewRelevant());
			query.bindValue(":isFeature", d.IsFeature());
			query.bindValue(":pin", d.Pin());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl elementConfiguration insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<ElementType>::Insert(const ElementType &Data)
		{
			ElementType d = Data;

			QSqlQuery query;
			query.prepare(Insert_ElementType);
			query.bindValue(":type", (int)d.Type());

			bool res = query.exec();
			if (!res)
			{
				QString test = query.lastError().text();
				if (m_logger != nullptr)
					m_logger->debug("Tbl elementType insert failed. Error: {0}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


		template<> bool MySqlMapper<Instruction>::Insert(const Instruction &Data)
		{
			Instruction d = Data;

			QSqlQuery query;
			query.prepare(Insert_Instruction);
			query.bindValue(":step", d.Step());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl instruction insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Recept>::Insert(const Recept &Data)
		{
			Recept d = Data;

			QSqlQuery query;
			query.prepare(Insert_Recept);
			query.bindValue(":receptName", d.ReceptName());
			query.bindValue(":orderNumber", d.OrderNumber());
			query.bindValue(":instructionID", d.Instruction()->ID());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl recept insert failed. Error: " + query.lastError().text().toStdString());
			}
			return res;
		}

		template<> bool MySqlMapper<Product>::Insert(const Product &Data)
		{
			Product d = Data;

			QSqlQuery query;
			query.prepare(Insert_Product);
			query.bindValue(":productName", d.ProductName());
			query.bindValue(":part", d.Part());
			query.bindValue(":receptID", d.Recept()->ID());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl product insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Project>::Insert(const Project &Data)
		{
			Project d = Data;

			QSqlQuery query;
			query.prepare(Insert_Project);
			query.bindValue(":name", d.Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl Project insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


		template<> bool MySqlMapper<RemoteWorkstation>::Update(const RemoteWorkstation &Data)
		{
			RemoteWorkstation d = Data;
			QSqlQuery query;
			query.prepare(Update_RemoteWorkstation);
			//query.bindValue(":elementConfiguration", d.ElementCfg()->ID());
			query.bindValue(":user", d.CurrentUser()->ID());
			query.bindValue(":hostname", d.Hostname());
			query.bindValue(":mac", d.Mac());
			query.bindValue(":ip", d.Ip());
			query.bindValue(":powerstripeIp", d.PowerstripeId());
			query.bindValue(":powerstripeId", d.PowerstripeId());
			query.bindValue(":remoteboxComPort", d.RemoteboxComPort());
			query.bindValue(":remoteboxHwId", d.RemoteboxHwId());
			query.bindValue(":remoteboxSwVersion", d.RemoteboxSwVersion());
			query.bindValue(":state", (int)d.State());
			if (d.AssignedProject() == nullptr)
			{
				m_logger->error("Project entry can't be NULL!");
				return false;
			}
			else
				query.bindValue(":name", d.AssignedProject()->Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl remoteWorkstation update failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<ElementConfiguration>::Update(const ElementConfiguration &Data)
		{
			ElementConfiguration d = Data;
			QSqlQuery query;
			query.prepare(Update_ElementConfiguration);
			query.bindValue(":remoteWorkstationID", d.RemoteWorkstationID());
			query.bindValue(":type", d.Type()->ID());
			query.bindValue(":displayName", d.DisplayName());
			query.bindValue(":name", d.Name());
			query.bindValue(":groupName", d.GroupName());
			query.bindValue(":function", d.Function());
			query.bindValue(":tooltip", d.ToolTip());
			query.bindValue(":remoteViewRelevant", d.RemoteViewRelevant());
			query.bindValue(":isFeature", d.IsFeature());
			query.bindValue(":pin", d.Pin());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl elementConfiguration update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<ElementType>::Update(const ElementType &Data)
		{
			ElementType d = Data;
			QSqlQuery query;
			query.prepare(Update_ElementType);
			query.bindValue(":type", (int)d.Type());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl elementType update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Instruction>::Update(const Instruction &Data)
		{
			Instruction d = Data;
			QSqlQuery query;
			query.prepare(Update_Instruction);
			query.bindValue(":step", d.Step());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl instruction update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Project>::Update(const Project &Data)
		{
			Project d = Data;
			QSqlQuery query;
			query.prepare(Update_Project);
			query.bindValue(":name", d.Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl project update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Recept>::Update(const Recept &Data)
		{
			Recept d = Data;
			QSqlQuery query;
			query.prepare(Update_Recept);
			query.bindValue(":orderNumber", d.OrderNumber());
			query.bindValue(":receptName", d.ReceptName());
			query.bindValue(":instructionID", d.Instruction()->ID());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl instruction update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<User>::Update(const User &Data)
		{
			User d = Data;
			QSqlQuery query;
			query.prepare(Update_User);
			query.bindValue(":username", d.UserName());
			query.bindValue(":password", d.Password());
			query.bindValue(":mksUsername", d.MKSUsername());
			query.bindValue(":mksPassword", d.MKSPassword());
			query.bindValue(":initials", d.Initials());
			query.bindValue(":notifiyRemoteDesktop", d.NotifiyRemoteDesktop());
			query.bindValue(":notifiyDesktop", d.NotifiyDesktop());
			//@todo unschöner cast
			query.bindValue(":role", (int)d.Role());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl instruction update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> RemoteWorkstation MySqlMapper<RemoteWorkstation>::FindByID(const quint64 ID, bool Flag)
		{
			RemoteWorkstation d;
			QSqlQuery query;
			query.prepare(SelectById_RemoteWorkstation);
			query.bindValue(":idRemoteWorkstation", ID);
			bool res = query.exec();
			while (query.next())
			{
				d.SetID(query.value("idRemoteWorkstation").toInt());
				if (FindByID<User>(query.value("userID").toInt()).UserName() == "")
					d.SetCurrentUser(nullptr);
				else
					d.SetCurrentUser(new User(FindByID<User>(query.value("userID").toInt())));
				d.SetIp(query.value("ip").toString());
				d.SetMac(query.value("mac").toString());
				d.SetHostname(query.value("hostname").toString());
				d.SetPowerstripeId(query.value("powerstripeId").toString());
				d.SetPowerstripeIp(query.value("powerstripeIp").toString());
				d.SetRemoteboxComPort(query.value("remoteboxComPort").toInt());
				d.SetRemoteboxHwId(query.value("remoteboxHwId").toString());
				d.SetRemoteboxSwVersion(query.value("remoteboxSwVersion").toString());
				d.SetState((RW::RemoteWorkstationState)query.value("state").toInt());
				d.setAssignedProject(new Project(FindByID<Project>(query.value("projectID").toInt())));

				QSqlQuery query;
				query.prepare(Select_ElementConfigurationByRemoteWorkstationID);
				query.bindValue(":remoteWorkstationID", d.ID());
				bool res = query.exec();
				while (query.next())
				{
					ElementConfiguration el;
					el.SetType(new ElementType(FindByID<ElementType>(query.value("elementTypeID").toInt())));
					el.SetDisplayName(query.value("displayName").toString());
					el.SetName(query.value("name").toString());
					el.SetGroupName(query.value("groupName").toString());
					el.SetFunction(query.value("function").toString());
					el.SetToolTip(query.value("tooltip").toString());
					el.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
					el.SetIsFeature(query.value("isFeature").toBool());
					el.SetPin(query.value("pin").toInt());
					d.AddElementCfg(el);
				}
				if (!res)
				{
					m_logger->error("Tbl remoteWorkstation FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
				}
			}

			if (!res)
			{
				m_logger->error("Tbl remoteWorkstation FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> User MySqlMapper<User>::FindByID(const quint64 ID, bool Flag)
		{
			User d;
			QSqlQuery query;
			query.prepare(SelectById_ElementConfiguration);
			query.bindValue(":idUser", ID);
			bool res = query.exec();
			while (query.next())
			{
				d.SetUserName(query.value("username").toString());
				d.SetPassword(query.value("password").toString());
				d.SetMKSUsername(query.value("mksUsername").toString());
				d.SetMKSPassword(query.value("mksPassword").toString());
				d.SetInitials(query.value("initials").toString());
				d.SetNotifiyRemoteDesktop(query.value("notifiyRemoteDesktop").toBool());
				d.SetNotifiyDesktop(query.value("notifiyDesktop").toBool());
				//@todo unschöner cast hier
				d.SetRole((RW::UserRole)query.value("role").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl user FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}


		template<> ElementConfiguration MySqlMapper<ElementConfiguration>::FindByID(const quint64 ID, bool Flag)
		{
			ElementConfiguration d;
			QSqlQuery query;
			query.prepare(SelectById_ElementConfiguration);
			query.bindValue(":idElementConfiguration", ID);
			bool res = query.exec();
			while (query.next())
			{
				d.SetType(new ElementType(FindByID<ElementType>(query.value("elementTypeID").toInt())));
				d.SetDisplayName(query.value("displayName").toString());
				d.SetName(query.value("name").toString());
				d.SetGroupName(query.value("groupName").toString());
				d.SetFunction(query.value("function").toString());
				d.SetToolTip(query.value("tooltip").toString());
				d.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
				d.SetIsFeature(query.value("isFeature").toBool());
				d.SetPin(query.value("pin").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl elementConfiguration FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> ElementType MySqlMapper<ElementType>::FindByID(const quint64 ID, bool Flag)
		{
			ElementType d;
			QSqlQuery query;
			query.prepare(SelectById_ElementType);
			query.bindValue(":idElementType", ID);
			bool res = query.exec();
			while (query.next())
			{
				// \!todo unschöne Konvertierung
				d.SetType((TypeOfElement)query.value("type").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl elementType FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}


		template<> Instruction MySqlMapper<Instruction>::FindByID(const quint64 ID, bool Flag)
		{
			Instruction d;
			QSqlQuery query;
			query.prepare(SelectById_Instruction);
			query.bindValue(":idInstruction", ID);
			bool res = query.exec();

			while (query.next())
			{
				// \!todo unschöne Konvertierung
				d.SetStep(query.value("step").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl instruction FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Recept MySqlMapper<Recept>::FindByID(const quint64 ID, bool Flag)
		{
			Recept d;
			QSqlQuery query;
			query.prepare(SelectById_Recept);
			query.bindValue(":idRecept", ID);
			bool res = query.exec();

			while (query.next())
			{
				// \!todo unschöne Konvertierung
				d.SetOrderNumber(query.value("orderNumber").toInt());
				d.SetInstruction(new Instruction(FindByID<Instruction>(query.value("instructionID").toInt())));
				d.SetReceptName(query.value("receptName").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl recept FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Product MySqlMapper<Product>::FindByID(const quint64 ID, bool Flag)
		{
			Product d;
			QSqlQuery query;
			query.prepare(SelectById_Product);
			query.bindValue(":idProduct", ID);
			bool res = query.exec();

			while (query.next())
			{
				// \!todo unschöne Konvertierung
				d.SetProductName(query.value("productName").toString());
				d.SetRecept(new Recept(FindByID<Recept>(query.value("receptID").toInt())));
				d.SetPart(query.value("part").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl product FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Project MySqlMapper<Project>::FindByID(const quint64 ID, bool Flag)
		{
			Project d;
			QSqlQuery query;
			query.prepare(SelectById_Project);
			query.bindValue(":idProject", ID);
			bool res = query.exec();

			while (query.next())
			{
				// \!todo unschöne Konvertierung
				d.SetProjectname(query.value("name").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl project FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> LogEntry MySqlMapper<LogEntry>::FindByID(const quint64 ID, bool Flag)
		{
			LogEntry d;
			QSqlQuery query;
			query.prepare(SelectById_LogEntry);
			query.bindValue(":idLogEntry", ID);
			bool res = query.exec();

			while (query.next())
			{
				// \!todo unschöne Konvertierung
				d.SetComputerName_(query.value("setComputerName").toString());
				d.SetType(query.value("type").toString());
				d.SetDate(query.value("date").toDateTime());
				d.SetThreadID(query.value("threadId").toInt());
				d.SetMessage(query.value("message").toString());
				d.SetLogLevel(query.value("logLevel").toString());
				d.SetErrorID(query.value("threadId").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl log FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> QList<RemoteWorkstation> MySqlMapper<RemoteWorkstation>::FindAll()
		{
			QList<RemoteWorkstation> list;
			QSqlQuery query;
			query.prepare(SelectAll_RemoteWorkstation);
			bool res = query.exec();
			while (query.next())
			{
				RemoteWorkstation d;
				d.SetID(query.value("idRemoteWorkstation").toInt());
				d.SetCurrentUser(new User(FindByID<User>(query.value("userID").toInt())));
				d.SetIp(query.value("ip").toString());
				d.SetMac(query.value("mac").toString());
				d.SetHostname(query.value("hostname").toString());
				d.SetPowerstripeId(query.value("powerstripeId").toString());
				d.SetPowerstripeIp(query.value("powerstripeIp").toString());
				d.SetRemoteboxComPort(query.value("remoteboxComPort").toInt());
				d.SetRemoteboxHwId(query.value("remoteboxHwId").toString());
				d.SetRemoteboxSwVersion(query.value("remoteboxSwVersion").toString());
				d.SetState((RW::RemoteWorkstationState)query.value("state").toInt());
				d.setAssignedProject(new Project(FindByID<Project>(query.value("projectID").toInt())));

				QSqlQuery query;
				query.prepare(Select_ElementConfigurationByRemoteWorkstationID);
				query.bindValue(":remoteWorkstationID", d.ID());
				bool res = query.exec();
				while (query.next())
				{
					ElementConfiguration el;
					//Todo warum wird hier ein Pointer verwendet?!
					ElementType* elType = new ElementType();
					elType->SetType((RW::TypeOfElement)query.value("type").toInt());
					el.SetType(elType);
					el.SetDisplayName(query.value("displayName").toString());
					el.SetName(query.value("name").toString());
					el.SetGroupName(query.value("groupName").toString());
					el.SetFunction(query.value("function").toString());
					el.SetToolTip(query.value("tooltip").toString());
					el.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
					el.SetIsFeature(query.value("isFeature").toBool());
					el.SetPin(query.value("pin").toInt());
					d.AddElementCfg(el);
				}
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl remoteWorkstation FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<User> MySqlMapper<User>::FindAll()
		{
			QList<User> list;
			QSqlQuery query;
			query.prepare(SelectAll_User);
			bool res = query.exec();
			while (query.next())
			{
				User d;
				d.SetUserName(query.value("username").toString());
				d.SetPassword(query.value("password").toString());
				d.SetMKSUsername(query.value("mksUsername").toString());
				d.SetMKSPassword(query.value("mksPassword").toString());
				d.SetInitials(query.value("initials").toString());
				d.SetNotifiyRemoteDesktop(query.value("notifiyRemoteDesktop").toBool());
				d.SetNotifiyDesktop(query.value("notifiyDesktop").toBool());
				d.SetRole((RW::UserRole)query.value("role").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl elementConfiguration FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}


		template<> QList<ElementConfiguration> MySqlMapper<ElementConfiguration>::FindAll()
		{
			QList<ElementConfiguration> list;
			QSqlQuery query;
			query.prepare(SelectAll_ElementConfiguration);
			bool res = query.exec();
			while (query.next())
			{
				ElementConfiguration d;
				d.SetType(new ElementType(FindByID<ElementType>(query.value("elementTypeID").toInt())));
				d.SetDisplayName(query.value("displayName").toString());
				d.SetName(query.value("name").toString());
				d.SetGroupName(query.value("groupName").toString());
				d.SetFunction(query.value("function").toString());
				d.SetToolTip(query.value("tooltip").toString());
				d.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
				d.SetIsFeature(query.value("isFeature").toBool());
				d.SetPin(query.value("pin").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl elementConfiguration FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<ElementType> MySqlMapper<ElementType>::FindAll()
		{
			QList<ElementType> list;
			QSqlQuery query;
			query.prepare(SelectAll_ElementType);
			bool res = query.exec();
			while (query.next())
			{
				ElementType d;
				// \!todo unschöne Konvertierung
				d.SetType((TypeOfElement)query.value("type").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl elementType FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}


		template<> QList<Instruction> MySqlMapper<Instruction>::FindAll()
		{
			QList<Instruction> list;
			QSqlQuery query;
			query.prepare(SelectAll_Instruction);
			bool res = query.exec();
			while (query.next())
			{
				Instruction d;
				// \!todo unschöne Konvertierung
				d.SetStep(query.value("step").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl instruction FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}
	
		template<> QList<Recept> MySqlMapper<Recept>::FindAll()
		{
			QList<Recept> list;
			QSqlQuery query;
			query.prepare(SelectAll_Recept);
			bool res = query.exec();
			while (query.next())
			{
				Recept d;
				// \!todo unschöne Konvertierung
				d.SetOrderNumber(query.value("orderNumber").toInt());
				d.SetInstruction(new Instruction(FindByID<Instruction>(query.value("instructionID").toInt())));
				d.SetReceptName(query.value("receptName").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl recept FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<Product> MySqlMapper<Product>::FindAll()
		{
			QList<Product> list;
			QSqlQuery query;
			query.prepare(SelectAll_Product);
			bool res = query.exec();
			while (query.next())
			{
				Product d;
				// \!todo unschöne Konvertierung
				d.SetProductName(query.value("productName").toString());
				d.SetRecept(new Recept(FindByID<Recept>(query.value("receptID").toInt())));
				d.SetPart(query.value("part").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl product FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<Project> MySqlMapper<Project>::FindAll()
		{
			QList<Project> list;
			QSqlQuery query;
			query.prepare(SelectAll_Project);
			bool res = query.exec();
			while (query.next())
			{
				Project d;
				// \!todo unschöne Konvertierung
				d.SetProjectname(query.value("name").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl project FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}


		template<> QList<LogEntry> MySqlMapper<LogEntry>::FindAll()
		{
			QList<LogEntry> list;
			QSqlQuery query;
			query.prepare(SelectAll_LogEntry);
			bool res = query.exec();
			while (query.next())
			{
				LogEntry d;
				// \!todo unschöne Konvertierung
				d.SetComputerName_(query.value("setComputerName").toString());
				d.SetType(query.value("type").toString());
				d.SetDate(query.value("date").toDateTime());
				d.SetThreadID(query.value("threadId").toInt());
				d.SetMessage(query.value("message").toString());
				d.SetLogLevel(query.value("logLevel").toString());
				d.SetErrorID(query.value("threadId").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl logEntry FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}
	}
}