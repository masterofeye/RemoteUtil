#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>

#define NAME "RemoteWorkstationTest"

class RemoteWorkstationTest : public TestSuite
{
    Q_OBJECT
private: 
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	RemoteWorkstationTest() : TestSuite(NAME, 2)
    {
		
    }
private slots :
    void initTestCase()
    {
    }

    void init()
	{
		m_logger = spdlog::get("sql");
		if (m_logger == nullptr)
			m_logger = spdlog::create<spdlog::sinks::MySqlSink>("sql");
		m_Repository = new RW::SQL::Repository(RW::SourceType::SQL, m_logger);
    }

	void Insert_A717_positiv()
    {
        bool on = true;
		RW::SQL::RemoteWorkstation t;
		RW::SQL::ElementType elementTypeCan;
		elementTypeCan.SetType(RW::TypeOfElement::USB);

		RW::SQL::ElementConfiguration elementConfigurationCAN;
		elementConfigurationCAN.SetType(&elementTypeCan);
		elementConfigurationCAN.SetName("CAN");
		elementConfigurationCAN.SetGroupName("Peripherie");
		elementConfigurationCAN.SetToolTip("HMI CAN");
		elementConfigurationCAN.SetFunction("CAN");
		elementConfigurationCAN.SetDisplayName("CAN");
		t.AddElementCfg(elementConfigurationCAN);


		RW::SQL::ElementType elementTypeKl30;
		elementTypeKl30.SetType(RW::TypeOfElement::IO);
		RW::SQL::ElementConfiguration elementConfigurationKl30;
		elementConfigurationKl30.SetType(&elementTypeKl30);
		elementConfigurationKl30.SetName("Kl30");
		elementConfigurationKl30.SetGroupName("Peripherie");
		elementConfigurationKl30.SetToolTip("Kl30");
		elementConfigurationKl30.SetFunction("Kl30");
		elementConfigurationKl30.SetDisplayName("Kl30");
		t.AddElementCfg(elementConfigurationKl30);

		t.setHostname("A717");
		t.SetIp("192.168.111.245");
		t.SetMac("00-50-56-C0-00-08");
		t.SetPowerstripeId("A213");
		t.SetPowerstripeIp("192.168.111.242");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("asfajkaljk");
		t.SetRemoteboxSwVersion("asdjhak");
		t.SetCurrentUser(nullptr);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

		RW::SQL::RemoteWorkstation ret;
		QVERIFY(m_Repository->GetRemoteWorkstationByID(1, ret));
		QVERIFY(ret.hostname() == "A717");
		QVERIFY(ret.Ip() == "192.168.111.245");
		QVERIFY(ret.Mac() == "00-50-56-C0-00-08");
		QVERIFY(ret.PowerstripeId() == "A213");
		QVERIFY(ret.PowerstripeIp() =="192.168.111.242");
		QVERIFY(ret.RemoteboxComPort() == 16);
		QVERIFY(ret.RemoteboxHwId() == "asfajkaljk");
		QVERIFY(ret.RemoteboxSwVersion() == "asdjhak");
		QVERIFY(ret.CurrentUser() == nullptr);

		RW::SQL::ElementConfiguration elementConfiguration = ret.ElementCfg()->at(0);
		QVERIFY(elementConfiguration.Name() == "CAN");
		QVERIFY(elementConfiguration.GroupName() == "Peripherie");
		QVERIFY(elementConfiguration.ToolTip() == "HMI CAN");
		QVERIFY(elementConfiguration.Function() == "CAN");
		QVERIFY(elementConfiguration.DisplayName() == "CAN");


		RW::SQL::ElementConfiguration elementConfiguration2 = ret.ElementCfg()->at(1);
		QVERIFY(elementConfiguration2.Name() == "Kl30");
		QVERIFY(elementConfiguration2.GroupName() == "Peripherie");
		QVERIFY(elementConfiguration2.ToolTip() == "Kl30");
		QVERIFY(elementConfiguration2.Function() == "Kl30");
		QVERIFY(elementConfiguration2.DisplayName() == "Kl30");
    }

	void Insert_A684_positive()
	{
		bool on = true;
		RW::SQL::RemoteWorkstation t;
		RW::SQL::ElementType elementTypeCan;
		elementTypeCan.SetType(RW::TypeOfElement::USB);

		RW::SQL::ElementConfiguration elementConfigurationCAN;
		elementConfigurationCAN.SetType(&elementTypeCan);
		elementConfigurationCAN.SetName("CAN");
		elementConfigurationCAN.SetGroupName("Peripherie");
		elementConfigurationCAN.SetToolTip("HMI CAN");
		elementConfigurationCAN.SetFunction("CAN");
		elementConfigurationCAN.SetDisplayName("CAN");
		t.AddElementCfg(elementConfigurationCAN);


		RW::SQL::ElementType elementTypeKl30;
		elementTypeKl30.SetType(RW::TypeOfElement::IO);
		RW::SQL::ElementConfiguration elementConfigurationKl30;
		elementConfigurationKl30.SetType(&elementTypeKl30);
		elementConfigurationKl30.SetName("Kl30");
		elementConfigurationKl30.SetGroupName("Peripherie");
		elementConfigurationKl30.SetToolTip("Kl30");
		elementConfigurationKl30.SetFunction("Kl30");
		elementConfigurationKl30.SetDisplayName("Kl30");
		t.AddElementCfg(elementConfigurationKl30);

		t.setHostname("A684");
		t.SetIp("192.168.111.246");
		t.SetMac("00-50-56-C0-00-09");
		t.SetPowerstripeId("A217");
		t.SetPowerstripeIp("192.168.111.249");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

		RW::SQL::RemoteWorkstation ret;
		QVERIFY(m_Repository->GetRemoteWorkstationByID(1, ret));
		
	}

	void FindAllRemortWorkstations_Positiv()
	{
		QList<RW::SQL::RemoteWorkstation> ret;
		QVERIFY(m_Repository->GetAllRemoteWorkstation(ret));
	}

    void cleanupTestCase()
    {
		delete m_Repository;
    }

	void cleanup()
	{
	}
};

static RemoteWorkstationTest instance;