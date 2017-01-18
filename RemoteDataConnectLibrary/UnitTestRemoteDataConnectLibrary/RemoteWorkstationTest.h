#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>
#include "Constants.h"

#define NAME "RemoteWorkstationTest"

class RemoteWorkstationTest : public TestSuite
{
    Q_OBJECT
private: 
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	RemoteWorkstationTest() : TestSuite(NAME, 3)
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

	void Insert_A821_positiv()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A821");
		t.SetIp("192.168.111.245");
		t.SetMac("00-50-56-C0-00-08");
		t.SetPowerstripeId("A213");
		t.SetPowerstripeIp("192.168.111.242");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("asfajkaljk");
		t.SetRemoteboxSwVersion("asdjhak");
		t.setAssignedProject(&p);
		t.SetCurrentUser(nullptr);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

		RW::SQL::RemoteWorkstation ret;
		QVERIFY(m_Repository->GetRemoteWorkstationByID(1, ret));
		QVERIFY(ret.Hostname() == "A717");
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY17);

		t.SetHostname("A684");
		t.SetIp("192.168.111.246");
		t.SetMac("00-50-56-C0-00-09");
		t.SetPowerstripeId("A217");
		t.SetPowerstripeIp("192.168.111.249");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

		RW::SQL::RemoteWorkstation ret;
		QVERIFY(m_Repository->GetRemoteWorkstationByID(1, ret));
		
	}

	void Insert_A843_positive()
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
		
		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A843");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::DEFECT);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

	}

	void Insert_A717_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY17);

		t.SetHostname("A820");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::ON);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

	}

	void Insert_A823_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY17);

		t.SetHostname("A823");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::RESERVE);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

	}

	void Insert_A795_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY17);

		t.SetHostname("A795");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));

	}

	void Insert_A822_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY16);

		t.SetHostname("A822");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A856_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A856");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A864_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A864");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A860_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A860");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::ON);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A859_positive()
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A859");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::DEFECT);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A911_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_HL_MY18);

		t.SetHostname("A911");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::ON);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A798_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_EL205MY18);

		t.SetHostname("A798");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::RESERVE);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A841_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_EL205MY18);

		t.SetHostname("A841");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A772_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_EL_MY17);

		t.SetHostname("A772");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A796_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_EL_MY17);

		t.SetHostname("A796");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A855_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(BR213IC_EL_MY17);

		t.SetHostname("A855");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A799_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(VS30IC_SW_LL_ML);

		t.SetHostname("A799");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A842_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(VS30IC_SW_LL_ML);

		t.SetHostname("A842");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A865_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(VS30IC_SW_LL_ML);

		t.SetHostname("A865");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A857_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(VS30IC_SW_HL);

		t.SetHostname("A857");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A797_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(VS30IC_SW_HL);

		t.SetHostname("A797");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
	}

	void Insert_A910_positive()
	{
		bool on = false;
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

		RW::SQL::Project p;
		p.SetProjectname(VS30IC_SW_HL);

		t.SetHostname("A910");
		t.SetIp("192.168.111.142");
		t.SetMac("00-50-56-C0-00-11");
		t.SetPowerstripeId("A224");
		t.SetPowerstripeIp("192.168.111.139");
		t.SetRemoteboxComPort(16);
		t.SetRemoteboxHwId("abcdef");
		t.SetRemoteboxSwVersion("abcdef");
		t.SetCurrentUser(nullptr);
		t.setAssignedProject(&p);
		t.SetState(RW::RemoteWorkstationState::OFF);

		QVERIFY(m_Repository->InsertRemoteWorkstation(t));
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