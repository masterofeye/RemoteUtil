#pragma once

#include "Entity.h"
namespace RW{
	namespace SQL{
		class ProductPrivate;
		class Recept;
		class REMOTE_DATA_CONNECT_API Product :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(QString Productname READ ProductName WRITE SetProductName NOTIFY ProductNameChanged)
			Q_CLASSINFO("Version", "0.0.1")

		private:
			ProductPrivate* d_ptr;
			Q_DECLARE_PRIVATE(Product);
		public:
			Product(QObject *Parent = nullptr);
			~Product();

			Product(const Product& other);
			Product& Product::operator=(Product& other);

			Product(Product&& other);
			Product& Product::operator = (Product&& other);

			QString ProductName();
			void SetProductName(QString Product);

			QString Part();
			void SetPart(QString Step);

			RW::SQL::Recept* Recept();
			void SetRecept(RW::SQL::Recept *ReceptID);
		signals:
			void ProductNameChanged();
			void PartChanged();
			void ReceptChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::Product)