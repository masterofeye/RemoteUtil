#pragma once
#include "Entity.h"
namespace RW{
	namespace SQL{

		class InstructionPrivate;
		class REMOTE_DATA_CONNECT_API Instruction :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(QString Step MEMBER m_Step READ Step WRITE SetStep NOTIFY StepChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
			InstructionPrivate* d_ptr;
			Q_DECLARE_PRIVATE(Instruction);

		public:
			Instruction(QObject *Parent = nullptr);
			~Instruction();

			Instruction(const Instruction& other);
			Instruction& Instruction::operator=(Instruction& other);

			Instruction(Instruction&& other);
			Instruction& Instruction::operator=(Instruction&& other);

			QString Step();
			void SetStep(QString Step);
			
		signals:
			void StepChanged();
		};
	}
}
