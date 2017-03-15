#include "Product.h"
#include "Product_p.h"

namespace RW{
	namespace SQL{


		ProductPrivate::ProductPrivate(Product* Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_ProductName(""),
			m_Part(""),
			m_Recept(nullptr)
		{
		}

		ProductPrivate::~ProductPrivate()
		{
		}


		Product::Product(QObject *Parent) : Entity(Parent),
			d_ptr(new ProductPrivate(this))
		{
		}


		Product::~Product()
		{
		}

		Product::Product(const Product& other)
		{
			if (&other != nullptr)
			{
				d_ptr = new ProductPrivate(this);
				d_ptr->m_Part = other.d_ptr->m_Part;
				d_ptr->m_ProductName = other.d_ptr->m_ProductName;
				d_ptr->m_Recept = other.d_ptr->m_Recept;

			}
		}

		Product& Product::operator=(Product& other)
		{
			if (&other != nullptr)
			{
				d_ptr = new ProductPrivate(this);
				d_ptr->m_Part = other.d_ptr->m_Part;
				d_ptr->m_ProductName = other.d_ptr->m_ProductName;
				d_ptr->m_Recept = other.d_ptr->m_Recept;

			}
			return *this;
		}


		Product::Product(Product&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		Product& Product::operator = (Product&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


		QString Product::ProductName()
		{
			Q_D(Product);
			return d->m_ProductName; 
		}
		void Product::SetProductName(QString Product)
		{
			Q_D(Product);
			d->m_ProductName = Product; 
			emit ProductNameChanged();
		}

		QString Product::Part()
		{
			Q_D(Product);
			return d->m_Part; 
		}

		void Product::SetPart(QString Step)
		{
			Q_D(Product);
			d->m_Part = Step; 
			emit PartChanged();
		
		}

		Recept* Product::Recept()
		{
			Q_D(Product);
			return d->m_Recept; 
		}

		void Product::SetRecept(RW::SQL::Recept *ReceptID)
		{
			Q_D(Product);
			d->m_Recept = ReceptID; 
			emit ReceptChanged(); 
		}
	}
}
