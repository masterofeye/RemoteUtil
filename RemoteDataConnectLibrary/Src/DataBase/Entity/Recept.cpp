#include "Recept.h"
#include "Recept_p.h"

namespace RW{
	namespace SQL{

		ReceptPrivate::ReceptPrivate(Recept *Parent) : 
			QObject(Parent),
			q_ptr(Parent),
			m_OrderNumber(0),
			m_InstructionID(nullptr),
			m_ReceptName("")
		{
		
		}

		ReceptPrivate::~ReceptPrivate()
		{}


		Recept::Recept(QObject *Parent) : Entity(Parent),
			d_ptr(new ReceptPrivate(this))
		{
		}

		Recept::~Recept()
		{
		}

		Recept::Recept(const Recept& other) : d_ptr(const_cast<ReceptPrivate*>(other.d_ptr))
		{

		}

		Recept& Recept::operator=(Recept& other)
		{
			std::swap(d_ptr, const_cast<ReceptPrivate*>(other.d_ptr));
			d_ptr->setParent(this);
			return *this;
		}


		Recept::Recept(Recept&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		Recept& Recept::operator=(Recept&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}



		Instruction* Recept::Instruction()
		{ 
			Q_D(Recept);
			return d->m_InstructionID;
		}
		void Recept::SetInstruction(RW::SQL::Instruction* ReceptID)
		{
			Q_D(Recept); 
			d->m_InstructionID = ReceptID;
			emit InstructionChanged();
		}

		quint16 Recept::OrderNumber()
		{ 
			Q_D(Recept);
			return d->m_OrderNumber; 
		}
		void Recept::SetOrderNumber(quint16 Order)
		{ 
			Q_D(Recept);
			d->m_OrderNumber = Order; 
			emit OrderNumberChanged(); 
		}

		QString Recept::ReceptName()
		{ 
			Q_D(Recept);
			return d->m_ReceptName; 
		}
		void Recept::SetReceptName(QString Order)
		{ 
			Q_D(Recept);
			d->m_ReceptName = Order; 
			emit ReceptNameChanged(); 
		}
	}
}