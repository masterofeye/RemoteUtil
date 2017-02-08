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

	void Insert_IvoKunadt_Positiv()
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

	void GetUserByName_Positiv()
	{
		RW::SQL::User u;
		QVERIFY(m_Repository->GetUserByName("Kunadt", u));
		QVERIFY(u.UserName() == "Kunadt");
		QVERIFY(u.Password() == "Password");
		QVERIFY(u.Role() == RW::UserRole::Admin);
		QVERIFY(u.NotifiyDesktop() == true);
		QVERIFY(u.NotifiyRemoteDesktop() == true);
		QVERIFY(u.MKSUsername() == "uidw5301");
		QVERIFY(u.MKSPassword() == "Windows2002");
		QVERIFY(u.Initials() == "IvKu");
	}

	void GetUserByName_Negativ()
	{
		RW::SQL::User u;
		QVERIFY(!m_Repository->GetUserByName("Blub", u));
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