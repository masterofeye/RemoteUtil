#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>
#include "Constants.h"

#define NAME "UserTest"



class UserTest : public TestSuite
{
    Q_OBJECT
private: 
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	UserTest() : TestSuite(NAME, 2)
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

	void Insert_IvoKunadt()
    {
		RW::SQL::User u;
		u.SetUserName("Kunadt");
		u.SetPassword("Schleissheimer");
		u.SetRole(RW::UserRole::Admin);
		u.SetNotifiyDesktop(true);
		u.SetNotifiyRemoteDesktop(true);
		u.SetMKSUsername("uidw5301");
		u.SetMKSPassword("Windows2002");
		u.SetInitials("IvKu");
		QVERIFY(m_Repository->InsertUser(u));

		RW::SQL::User ret;
		QVERIFY(m_Repository->GetUserByID(1,ret));


    }

    void cleanupTestCase()
    {
		delete m_Repository;
    }

	void cleanup()
	{
	}


};

static UserTest instance;