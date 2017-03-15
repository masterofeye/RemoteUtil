#include "Device.h"
#include "Device_p.h"


namespace RW{
    namespace SQL{

        DevicePrivate::DevicePrivate(Device* Parent) :
            QObject(Parent),
            q_ptr(Parent)
        {
        }

        DevicePrivate::~DevicePrivate()
        {
        }


        Device::Device(QObject *Parent) : Entity(Parent),
            d_ptr(new DevicePrivate(this))
        {
        }

        Device::~Device()
        {
        }

        Device::Device(const Device& other)
        {
			if (&other != nullptr)
			{
				d_ptr = new DevicePrivate(this);
				d_ptr->m_Description = other.d_ptr->m_Description;
				d_ptr->m_DeviceName = other.d_ptr->m_DeviceName;
				d_ptr->m_ProductID = other.d_ptr->m_ProductID;
				d_ptr->m_VendorID = other.d_ptr->m_VendorID;
				d_ptr->m_Serial = other.d_ptr->m_Serial;
			}
        }

        Device& Device::operator=(Device& other)
        {
           if (&other != nullptr)
            {
				d_ptr = new DevicePrivate(this);
				d_ptr->m_Description = other.d_ptr->m_Description;
				d_ptr->m_DeviceName = other.d_ptr->m_DeviceName;
				d_ptr->m_ProductID = other.d_ptr->m_ProductID;
				d_ptr->m_VendorID = other.d_ptr->m_VendorID;
				d_ptr->m_Serial = other.d_ptr->m_Serial;
            }
            return *this;
        }


        Device::Device(Device&& other) : d_ptr(other.d_ptr)
        {
            d_ptr->setParent(this);
            other.d_ptr = nullptr;

        }
        Device& Device::operator=(Device&& other)
        {
            std::swap(d_ptr, other.d_ptr);
            d_ptr->setParent(this);
            delete other.d_ptr;
            other.d_ptr = nullptr;
            return *this;
        }


        QString Device::DeviceName()
        {
            Q_D(const Device);
            return d->m_DeviceName;
        }

        void Device::SetDeviceName(QString DeviceName)
        {
            Q_D(Device);
            d->m_DeviceName = DeviceName;
            emit DeviceNameChanged();
        }

        QString Device::Description()
        {
            Q_D(const Device);
            return d->m_Description;
        }

        void Device::SetDescription(QString Description)
        {
            Q_D(Device);
            d->m_Description = Description;
            emit DeviceNameChanged();
        }

        QByteArray Device::VendorID()
        {
            Q_D(const Device);
            return d->m_VendorID;
        }

        void Device::SetVendorID(QByteArray VendorID)
        {
            Q_D(Device);
            d->m_VendorID = VendorID;
            emit VendorIDChanged();
        }

        QByteArray Device::ProductID()
        {
            Q_D(const Device);
            return d->m_ProductID;
        }

        void Device::SetProductID(QByteArray ProductID)
        {
            Q_D(Device);
            d->m_ProductID = ProductID;
            emit ProductIDChanged();
        }

        QByteArray Device::Serial()
        {
            Q_D(const Device);
            return d->m_Serial;
        }

        void Device::SetSerial(QByteArray Serial)
        {
            Q_D(Device);
            d->m_Serial = Serial;
            emit SerialChanged();
        }
    }
}