#pragma once
#include <qobject.h>
#include "Entity.h"

namespace RW{
	namespace SQL{
        class Device;
        class DevicePrivate : public QObject
		{
			Q_OBJECT
            Q_DISABLE_COPY(DevicePrivate)
            Q_DECLARE_PUBLIC(Device)
		private:
			Device * const q_ptr;

		public:
            QString m_DeviceName;
            QString m_Description;
            QByteArray m_VendorID;
            QByteArray m_ProductID;
            QByteArray m_Serial;
		public:
            DevicePrivate(Device* QPointer);
            ~DevicePrivate();
		};


	}
}