#include "stdafx.h"
#include "Message.h"

#include <QDatastream>

namespace RW{
	namespace COM{
		//Message::Message() : QObject(nullptr)
		//{
		//
		//}


		Message::Message(QString Identifier,
			COM::MessageDescription MessageID,
			ExecutionVariant ExcVariant,
			QList<QVariant> ParameterListe,
			QObject* Parent) : QObject(Parent),
			m_Identifier(Identifier),
			m_MessageID(MessageID),
			m_ExecutionVariant(ExcVariant),
			m_ParameterListe(ParameterListe)
		{
		}

		Message::Message(QString Identifier, 
			COM::MessageDescription MessageID,
			ExecutionVariant ExcVariant,
			QList<QVariant> ParameterListe,
			QVariant Result,
			bool Success,
			QObject* Parent) : QObject(Parent),
			m_Identifier(Identifier),
			m_MessageID(MessageID),
			m_ExecutionVariant(ExcVariant),
			m_ParameterListe(ParameterListe),
			m_Result(Result),
			m_Success(Success)
		{
		}


		Message::~Message()
		{
		}

		Message::Message(const Message &obj)
		{
			m_ExecutionVariant = obj.m_ExecutionVariant;
			m_ParameterListe = obj.m_ParameterListe;
			m_MessageID = obj.m_MessageID;
		}

		Message& Message::operator = (const Message& other)
		{
			Message tmp(other);         // re-use copy-constructor
			*this = std::move(tmp); // re-use move-assignment
			return *this;
		}

		Message::Message(Message&& other):
		m_MessageID(other.m_MessageID),
		m_ExecutionVariant(other.m_ExecutionVariant),
		m_ParameterListe(other.m_ParameterListe)
		{
		}

		Message& Message::operator = (Message&& other)
		{
			return *this;
		}

		QDataStream &operator <<(QDataStream &out, const RW::COM::MessageDescription &dataStruct)
		{
			out.startTransaction();
			out << dataStruct;
			out.commitTransaction();
			return out;
		}

		QDataStream &operator >>(QDataStream &in, RW::COM::MessageDescription &dataStruct)
		{
			in >> dataStruct;
			return in;
		}


		QDataStream &operator <<(QDataStream &out, const RW::COM::Message::ExecutionVariant &dataStruct)
		{
			out.startTransaction();
			out << dataStruct;
			out.commitTransaction();
			return out;
		}

		QDataStream &operator >>(QDataStream &in, RW::COM::Message::ExecutionVariant &dataStruct)
		{
			in >> dataStruct;
			return in;
		}

		QDataStream &operator <<(QDataStream &out, const RW::COM::Message &dataStruct)
		{
			out.startTransaction();
			out << dataStruct.m_Identifier;
			out << dataStruct.m_MessageID;
			out << dataStruct.m_ExecutionVariant;
			out << dataStruct.m_ParameterListe;
			out << dataStruct.m_Result;
			out << dataStruct.m_Success;
			out.commitTransaction();
			return out;
		}

		QDataStream &operator >>(QDataStream &in, RW::COM::Message &dataStruct)
		{
			RW::COM::Message::ExecutionVariant var;
			RW::COM::MessageDescription id;
			QList<QVariant> parameterList;
			QVariant result;
			bool success;
			QString Identifier;

			in >> Identifier;
			in >> id;
			in >> var;
			in >> parameterList;
			in >> result;
			in >> success;

			dataStruct.m_Identifier;
			dataStruct.m_ParameterListe = parameterList;
			dataStruct.m_MessageID = id;
			dataStruct.m_Result = result;
			dataStruct.m_Success = success;
			dataStruct.m_ExecutionVariant = var;

			return in;
		}
	}
}