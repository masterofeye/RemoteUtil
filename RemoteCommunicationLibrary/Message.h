#pragma once
#include "stdafx.h"
#include "qobject.h"
#include "MessageDescription.h"
#include <QVariant>


namespace RW{
	namespace COM{
		class REMOTECOMMUNICATIONLIBRARY_EXPORT Message:
			public QObject
		{
			Q_OBJECT
            Q_CLASSINFO("Version", "0.0.1")
			Q_PROPERTY(QString identifier READ identifier WRITE setIdentifier NOTIFY IndetifierChanged)
			Q_PROPERTY(COM::MessageDescription MessageID READ MessageID WRITE SetMessageID)
			Q_PROPERTY(ExecutionVariant ExcVariant READ ExcVariant WRITE SetExcVariant )
			Q_PROPERTY(bool Success READ Success WRITE SetSuccess)
			Q_PROPERTY(QVariant Result READ Result WRITE SetResult)
			Q_PROPERTY(QList<QVariant> ParameterList READ ParameterList WRITE SetParameterList)
			Q_PROPERTY(bool IsExternal READ IsExternal WRITE SetIsExternal)


		public:
			enum class ExecutionVariant
			{
				SET,
				GET,
				NON
			};
			Q_ENUM(ExecutionVariant)
		private:
			QString m_Identifier = "";
			MessageDescription m_MessageID;
			ExecutionVariant m_ExecutionVariant = ExecutionVariant::NON;
			QList<QVariant> m_ParameterListe;
			QVariant m_Result;
			bool m_Success = false;
			bool m_IsExternal = false;
		public:
			explicit Message(){}

			//explicit Message(QObject* Parent = nullptr);

			Message(QString m_Identifier,
				MessageDescription MessageID,
				ExecutionVariant ExcVariant,
				QList<QVariant> ParameterListe,
				QObject* Parent = nullptr);

			Message::Message(QString m_Identifier,
				RW::COM::MessageDescription MessageID,
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

			//QString Identifier() const { return m_Identifier; }
			//void SetIdentifier(QString Identifier){ m_Identifier = Identifier; }

			QString identifier() const { return m_Identifier; }
			void setIdentifier(QString Identifier){ m_Identifier = Identifier; }

			COM::MessageDescription MessageID() const { return m_MessageID; }
			void SetMessageID(COM::MessageDescription MessageID){ m_MessageID = MessageID; }

            ExecutionVariant ExcVariant() const { return m_ExecutionVariant; }
			void SetExcVariant(ExecutionVariant ExcVariant){ m_ExecutionVariant = ExcVariant; }

            QList<QVariant> ParameterList() const { return m_ParameterListe; }
			void SetParameterList(QList<QVariant> ParamList){ m_ParameterListe = ParamList; }

            QVariant Result() const { return m_Result; }
			void SetResult(QVariant Result){ m_Result = Result; }

            bool Success() const { return m_Success; }
            void SetSuccess(bool Success){ m_Success = Success; }

            bool IsExternal() const { return m_IsExternal; }
            void SetIsExternal(bool IsExternal){ m_IsExternal = IsExternal; }
		signals:
			void IndetifierChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::COM::Message)
