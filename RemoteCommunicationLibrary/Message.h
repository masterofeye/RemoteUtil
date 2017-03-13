#pragma once
#include "qobject.h"
#include "MessageDescription.h"
#include <QVariant>


namespace RW{
	namespace COM{

		class Message sealed:
			public QObject
		{
			Q_OBJECT
			//Q_ENUMS(ExecutionVariant)
		public:
			enum class ExecutionVariant
			{
				SET,
				GET,
				NON
			};
		private:
			QString m_Identifier = "";
			MessageDescription m_MessageID;
			QByteArray m_Data;
			ExecutionVariant m_ExecutionVariant = ExecutionVariant::NON;
			QList<QVariant> m_ParameterListe;
			QVariant m_Result;
			bool m_Success = false;
			bool m_IsExternal = false;
		public:
			explicit Message(QObject* Parent = nullptr);

			Message(QString m_Identifier,
				MessageDescription MessageID,
				QByteArray Data, 
				ExecutionVariant ExcVariant,
				QList<QVariant> ParameterListe,
				QObject* Parent = nullptr);

			Message::Message(QString m_Identifier,
				RW::COM::MessageDescription MessageID,
				QByteArray Data,
				ExecutionVariant ExcVariant,
				QList<QVariant> ParameterListe,
				QVariant Result,
				bool Success,
				QObject* Parent);

			~Message();
			Message(const Message &obj);
			Message(Message&& other);
			Message& operator = (const Message& other);
			Message& operator = (Message&& other);


			friend QDataStream &operator <<(QDataStream &out, const RW::COM::Message &dataStruct);
			friend QDataStream &operator >>(QDataStream &in, RW::COM::Message &);

			QString Identifier(){ return m_Identifier; }
			void SetIdentifier(QString Identifier){ m_Identifier = Identifier; }

			COM::MessageDescription MessageID(){ return m_MessageID; }
			void SetMessageID(COM::MessageDescription MessageID){ m_MessageID = MessageID; }

			QByteArray Data(){ return m_Data; }
			void SetData(QByteArray Data){ m_Data = Data; }

			ExecutionVariant ExcVariant(){ return m_ExecutionVariant; };
			void SetExcVariant(ExecutionVariant ExcVariant){ m_ExecutionVariant = ExcVariant; }

			QList<QVariant> ParameterList(){ return m_ParameterListe; };
			void SetParameterList(QList<QVariant> ParamList){ m_ParameterListe = ParamList; }

			QVariant Result(){ return m_Result; };
			void SetResult(QVariant Result){ m_Result = Result; }

			bool Success(){ return m_Success; };
			void SetSuccess(bool Success){ m_Success = Success; };

			bool IsExternal(){ return m_IsExternal; };
			void SetIsExternal(bool IsExternal){ m_IsExternal = IsExternal; };
		};
	}
}
