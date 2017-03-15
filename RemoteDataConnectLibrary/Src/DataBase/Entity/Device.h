#pragma once
#include "Entity.h"
namespace RW{
    namespace SQL{
        class DevicePrivate;
        class Device :
            public Entity
        {
           Q_OBJECT
           Q_PROPERTY(QString DeviceName READ DeviceName WRITE SetDeviceName NOTIFY DeviceNameChanged)
           Q_PROPERTY(QString Description READ Description WRITE SetDescription NOTIFY DescriptionChanged)
           Q_PROPERTY(QByteArray VendorID READ VendorID WRITE SetVendorID NOTIFY VendorIDChanged)
           Q_PROPERTY(QByteArray ProductID READ ProductID WRITE SetProductID NOTIFY ProductIDChanged)
           Q_PROPERTY(QByteArray Serial READ Serial WRITE SetSerial NOTIFY SerialChanged)
           Q_CLASSINFO("Version", "0.0.1")
        private:
            DevicePrivate* d_ptr;
            Q_DECLARE_PRIVATE(Device);
        public:
            explicit Device(QObject *Parent = nullptr);
            ~Device();

            Device(const Device& other);
            Device& Device::operator=(Device& other);

            Device(Device&& other);
            Device& Device::operator=(Device&& other);

            /*
            @autor Ivo Kunadt
            @brief Gibt den DeviceName des Ger�tes zur�ck
            @return Gibt den DeviceName des Ger�tes zur�ck z.b. Tiny-CAN IV-XL f�r Tiny Can
            */
            QString DeviceName();

            /*
            @autor Ivo Kunadt
            @brief Setzt den Devicenamen f�r das von der Objektintanz verwaltete Objekt.
            @param [in] DeviceName Name des Ger�tes
            */
            void SetDeviceName(QString DeviceName);

            /*
            @autor Ivo Kunadt
            @brief Gibt die Beschreibung der Ger�tes zur�ck
            @return Beschreibungstext z.b. Renesas V850 MINICUBE f�r einen MiniCube
            */
            QString Description();

            /*
            @autor Ivo Kunadt
            @brief Setzt den Beschreibungstext.
            @param [in] Beschreibungstext.
            */
            void SetDescription(QString Description);

            /*
            @autor Ivo Kunadt
            @brief Gibt die VendorID der Ger�tes zur�ck
            @return VendorID z.b. 0409
            */
            QByteArray VendorID();

            /*
            @autor Ivo Kunadt
            @brief Setzt die VendorID des Ger�tes z.b.: 0409 f�r Renesas V850 MINICUBE.
            @param [in] VendorID die mit dem Tool USBDeview ausgelesen werden kann.
            */
            void SetVendorID(QByteArray VendorID);

            /*
            @autor Ivo Kunadt
            @brief Gibt die VendorID der Ger�tes zur�ck
            @return ProductID z.b. 0078
            */
            QByteArray ProductID();

            /*
            @autor Ivo Kunadt
            @brief Setzt die ProductID des Ger�tes z.b.: 0078 f�r Renesas V850 MINICUBE.
            @param [in] ProductID die mit dem Tool USBDeview ausgelesen werden kann.
            */
            void SetProductID(QByteArray ProductID);

            /*
            @autor Ivo Kunadt
            @brief Gibt die SerienNummer der Ger�tes zur�ck
            @return SerienNummer
            */
            QByteArray Serial();

            /*
            @autor Ivo Kunadt
            @brief Setzt die SerienNummer des Ger�tes
            @param [in] SerienNummer die mit dem Tool USBDeview ausgelesen werden kann.
            */
            void SetSerial(QByteArray Serial);

        signals:
            void DeviceNameChanged();
            void DescriptionChanged();
            void VendorIDChanged();
            void ProductIDChanged();
            void SerialChanged();
        };
    }
}
