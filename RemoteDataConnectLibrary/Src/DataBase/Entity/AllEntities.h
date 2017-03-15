#pragma once
#include "RemoteWorkstation.h"
#include "ElementConfiguration.h"
#include "ElementType.h"
#include "User.h"
#include "Recept.h"
#include "Product.h"
#include "Instruction.h"
#include "LogEntry.h"
#include "GeneralSettings.h"
#include "Project.h"
#include "Device.h"

namespace RW{
	namespace SQL{
		class Register
		{
		public:
			static void RegisterRWMetaTypes()
			{
				qRegisterMetaType<RW::RemoteWorkstationState>("RemoteWorkstationState");
				qRegisterMetaType<RW::RemoteWorkstationState>("RW::RemoteWorkstationState");

				qRegisterMetaType<RW::UserRole>("RW::UserRole");
				qRegisterMetaType<RW::UserRole>("UserRole");

				qRegisterMetaType<RW::SQL::User*>("RW::SQL::User*");
				qRegisterMetaType<RW::SQL::User*>("User*");

				qRegisterMetaType<RW::SQL::LogEntry*>("RW::SQL::LogEntry*");
				qRegisterMetaType<RW::SQL::LogEntry*>("LogEntry*");

				qRegisterMetaType<RW::SQL::Device*>("RW::SQL::Device*");
				qRegisterMetaType<RW::SQL::Device*>("Device*");


                qRegisterMetaType<RW::SQL::ElementConfiguration*>("RW::SQL::ElementConfiguration*");
                qRegisterMetaType<RW::SQL::ElementConfiguration*>("ElementConfiguration*");
                qRegisterMetaType<RW::SQL::ElementConfiguration>("RW::SQL::ElementConfiguration");
                qRegisterMetaType<RW::SQL::ElementConfiguration>("ElementConfiguration");

				qRegisterMetaType<RW::SQL::Project*>("RW::SQL::Project*");
				qRegisterMetaType<RW::SQL::Project*>("Project*");
                qRegisterMetaType<RW::SQL::ElementType*>("RW::SQL::ElementType*");
				qRegisterMetaType<RW::SQL::ElementType*>("ElementType*");
			}
		};
	}
}

