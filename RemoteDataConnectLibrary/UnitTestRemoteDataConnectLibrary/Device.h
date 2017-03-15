#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>

#define NAME "Devicetest"

class DevicetTest : public TestSuite
{
	Q_OBJECT
private:
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	DevicetTest() : TestSuite(NAME, 1)
	{

	}
	private slots :
		void initTestCase()
	{
		m_logger = spdlog::get("sql");
		if (m_logger == nullptr)
			m_logger = spdlog::create<spdlog::sinks::MySqlSink>("sql");
		m_Repository = new RW::SQL::Repository(RW::SourceType::SQL, m_logger);
	}

	void init()
	{
	}

	void Insert_Unique_Device_Positive()
	{
		bool on = true;
		RW::SQL::Device d;
		d.SetDescription("Renesas V850 MINICUBE");
		const QByteArray vendor = QByteArrayLiteral("\x00\x04\x00\x09");
		d.SetVendorID(vendor);
		const QByteArray product = QByteArrayLiteral("\x00\x00\x7\x08");
		d.SetProductID(product);
		d.SetSerial("");
		d.SetDeviceName("");

		RW::SQL::Device out;
		bool test = m_Repository->InsertDevice(d);
		QVERIFY(m_Repository->InsertDevice(d));
		QVERIFY(m_Repository->GetDeviceByID(1, out));

		QVERIFY(out.DeviceName() == "");
	}

	void cleanupTestCase()
	{
		delete m_Repository;
	}

	void cleanup()
	{
	}
};

static DevicetTest instance;