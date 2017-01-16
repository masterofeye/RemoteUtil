#include "ElementType.h"
#include "ElementType_p.h"
#include "SQLGlobal.h"
#include "qdebug.h"

namespace RW{
	namespace SQL{

		ElementTypePrivate::ElementTypePrivate(ElementType *Parent) :
			QObject(Parent),
			m_Type(RW::TypeOfElement::INVALID),
			q_ptr(Parent)
		{
		}

		ElementTypePrivate::~ElementTypePrivate()
		{
		}

		ElementType::ElementType(QObject *Parent) : Entity(Parent),
			d_ptr(new ElementTypePrivate(this))
		{
		}

		ElementType::~ElementType()
		{
		}

		ElementType::ElementType(const ElementType& other) : d_ptr(new ElementTypePrivate(this))
		{
			d_ptr->m_Type = other.d_ptr->m_Type;

		}

		ElementType& ElementType::operator=(ElementType& other)
		{
			std::swap(d_ptr, const_cast<ElementTypePrivate*>(other.d_ptr));
			return *this;
		}

		ElementType::ElementType(ElementType&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;

		}

		ElementType& ElementType::operator=(ElementType&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


		RW::TypeOfElement ElementType::Type()
		{
			Q_D(ElementType);
			return d_ptr->m_Type;
		}

		void ElementType::SetType(RW::TypeOfElement Type)
		{ 
			Q_D(ElementType);
			d_ptr->m_Type = Type;
			emit d_ptr->TypeChanged();
		}
	}
}