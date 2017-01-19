#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>

#define NAME "ElementConfigurationTest"

class ElementConfigurationTest : public TestSuite
{
    Q_OBJECT
private: 
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	ElementConfigurationTest() : TestSuite(NAME,3)
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

	void Insert_Unique_ElementType_Positive()
    {
        bool on = true;
		RW::SQL::ElementConfiguration t;
		RW::SQL::ElementType elementType;
		elementType.SetType(RW::TypeOfElement::USB);
		t.SetType(&elementType);
		t.SetName("CAN");
		t.SetGroupName("Peripherie");
		t.SetToolTip("HMI CAN");
		t.SetFunction("CAN");
		t.SetDisplayName("CAN");
		QVERIFY(m_Repository->InsertElementConfiguration(t));

		RW::SQL::ElementConfiguration ret;
		QVERIFY(m_Repository->GetElementConfigurationByID(1, ret));
		QVERIFY(ret.Type()->Type() == elementType.Type());
		QVERIFY(ret.Name() == "CAN");
		QVERIFY(ret.GroupName() == "Peripherie");
		QVERIFY(ret.ToolTip() == "HMI CAN");
		QVERIFY(ret.Function() == "CAN");
		QVERIFY(ret.DisplayName() == "CAN");
    }


    void cleanupTestCase()
    {
		delete m_Repository;
    }

	void cleanup()
	{
	}
};

static ElementConfigurationTest instance;