#include "Instruction.h"
#include "Instruction_p.h"

namespace RW{
	namespace SQL{

		InstructionPrivate::InstructionPrivate(Instruction* QPointer):
			q_ptr(QPointer),
			m_Step("")
		{
		
		}
		
		InstructionPrivate::~InstructionPrivate(){}


		Instruction::Instruction(QObject *Parent) : Entity(Parent),
			d_ptr(new InstructionPrivate(this))
		{
		}


		Instruction::~Instruction()
		{
		}

		Instruction::Instruction(const Instruction& other) : d_ptr(const_cast<InstructionPrivate*>(other.d_ptr))
		{

		}

		Instruction& Instruction::operator=(Instruction& other)
		{
			std::swap(d_ptr, const_cast<InstructionPrivate*>(other.d_ptr));
			d_ptr->setParent(this);
			return *this;
		}


		Instruction::Instruction(Instruction&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		Instruction& Instruction::operator = (Instruction&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}

		QString Instruction::Step()
		{
			Q_D(Instruction);
			return d->m_Step;
		}

		void Instruction::SetStep(QString Step)
		{ 
			Q_D(Instruction);
			d->m_Step = Step; 
		}
	}
}
