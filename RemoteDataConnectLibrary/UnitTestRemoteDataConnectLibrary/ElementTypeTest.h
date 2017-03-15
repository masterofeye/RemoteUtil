#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>

#define NAME "ElementTypeTest"

class ElementTypeTest : public TestSuite
{
    Q_OBJECT
private: 
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	ElementTypeTest() : TestSuite(NAME,1)
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

	void Insert_Unique_ElementType_Positive()
    {
        bool on = true;
		RW::SQL::ElementType t;
		t.SetType(RW::TypeOfElement::USB);
		QVERIFY(m_Repository->InsertElementType(t));

		RW::SQL::ElementType ret;
		QVERIFY(m_Repository->GetElementTypeByID(1, ret));
		QVERIFY(ret.Type() == RW::TypeOfElement::USB);

		RW::SQL::ElementType tIO;
		tIO.SetType(RW::TypeOfElement::IO);
		QVERIFY(m_Repository->InsertElementType(tIO));

		RW::SQL::ElementType tRelay;
		tRelay.SetType(RW::TypeOfElement::RELAY);
		QVERIFY(m_Repository->InsertElementType(tRelay));

		RW::SQL::ElementType tSound;
		tSound.SetType(RW::TypeOfElement::SOUND);
		QVERIFY(m_Repository->InsertElementType(tSound));

		RW::SQL::ElementType tLVDS;
		tLVDS.SetType(RW::TypeOfElement::LVDS);
		QVERIFY(m_Repository->InsertElementType(tLVDS));

		RW::SQL::ElementType tHUD;
		tHUD.SetType(RW::TypeOfElement::HUD);
		QVERIFY(m_Repository->InsertElementType(tHUD));

    }

	/**
	@brief Fügt ein weitere ElementType hinzu aber mit 
	*/
	void Insert_Unique_ElementType_Negative()
	{
		bool on = true;
		RW::SQL::ElementType t;
		t.SetType(RW::TypeOfElement::USB);
		QVERIFY(m_Repository->InsertElementType(t));

		RW::SQL::ElementType ret;
		QVERIFY((m_Repository->GetElementTypeByID(1, ret)));
	}

    void cleanupTestCase()
    {
		delete m_Repository;
    }

	void cleanup()
	{
	}
};

static ElementTypeTest instance;