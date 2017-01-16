#pragma once
#include <QtTest/QtTest>
#include "TestSuite.hpp"
#include "RemoteDataConnectLibrary.h"
#include <spdlog\spdlog.h>
#include "Constants.h"

#define NAME "ProjectTest"



class ProjectTest : public TestSuite
{
    Q_OBJECT
private: 
	RW::SQL::Repository *m_Repository;
	std::shared_ptr<spdlog::logger> m_logger;
public:
	ProjectTest() : TestSuite(NAME, 0)
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
		RW::SQL::Project tp;
		tp.SetProjectname(BR213IC_HL_MY16);
		QVERIFY(m_Repository->InsertProject(tp));

		RW::SQL::Project ret;
		QVERIFY(m_Repository->GetProjectByID(1, ret));
		QVERIFY(ret.Projectname() == BR213IC_HL_MY16);

		RW::SQL::Project t;
		t.SetProjectname(BR213IC_HL_MY17);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR213IC_HL_MY18);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR213IC_EL_MY16);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR213IC_EL_MY17);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR213IC_EL_MY18);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR213IC_EL205MY18);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR463IC_EL_MY17);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR463IC_HL_MY17);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(VS30IC_SW_HL);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(VS30IC_SW_LL_ML);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR205IC);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR222IC);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR447IC);
		QVERIFY(m_Repository->InsertProject(t));

		t.SetProjectname(BR470IC);
		QVERIFY(m_Repository->InsertProject(t));
    }

	void GetAllProjects_Positiv()
	{
		QList<RW::SQL::Project> p;
		QVERIFY(m_Repository->GetAllProject(p));
		QString test = p[0].Projectname();
		QList < RW::SQL::Project*> projectListStar;
		for (int i = 0; i < p.count(); i++)
		{
			projectListStar.append(&p[i]);
		}
		


		RW::SQL::Project* sda = projectListStar.at(0);
		sda->Projectname();
		qDebug() << projectListStar.at(0)->Projectname();
	}


	/**
	@brief Fügt ein weitere ElementType hinzu aber mit 
	*/
	void Insert_Unique_ElementType_Negative()
	{
	}



    void cleanupTestCase()
    {
		delete m_Repository;
    }

	void cleanup()
	{
	}


};

static ProjectTest instance;