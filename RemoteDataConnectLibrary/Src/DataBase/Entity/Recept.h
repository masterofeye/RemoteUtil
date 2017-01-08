#pragma once
#include "Entity.h"

namespace RW{
	namespace SQL{

		class ReceptPrivate;
		class Instruction;
		class REMOTE_DATA_CONNECT_API Recept :
			public Entity
		{
			Q_OBJECT
			//Q_PROPERTY(Instruction InstructionObj READ InstructionObj WRITE SetInstruction NOTIFY InstructionChanged)
			Q_PROPERTY(quint16 OrderNumber READ OrderNumber WRITE SetOrderNumber NOTIFY OrderNumberChanged)
			Q_PROPERTY(QString ReceptName READ ReceptName WRITE SetReceptName NOTIFY ReceptNameChanged)
			Q_CLASSINFO("Version", "0.0.1")

		private:
			ReceptPrivate* d_ptr;
			Q_DECLARE_PRIVATE(Recept);

		public:
			Recept(QObject *Parent = nullptr);
			~Recept();

			Recept(const Recept& other);
			Recept& Recept::operator=(Recept& other);

			Recept(Recept&& other);
			Recept& Recept::operator=(Recept&& other);

			Instruction* Instruction();
			void SetInstruction(RW::SQL::Instruction *Instruction);

			quint16 OrderNumber();
			void SetOrderNumber(quint16 Order);

			QString ReceptName();
			void SetReceptName(QString Order);

		signals:
			void OrderNumberChanged();
			void InstructionChanged();
			void ReceptNameChanged();
		};
	}
}