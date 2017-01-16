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

namespace RW{
	namespace SQL{
		class Register
		{
		public:
			static void RegisterRWMetaTypes()
			{
				qRegisterMetaType<RW::RemoteWorkstationState>("RemoteWorkstationState");
				qRegisterMetaType<RW::RemoteWorkstationState>("RW::RemoteWorkstationState");

				qRegisterMetaType<RW::SQL::User*>("RW::SQL::User*");
				qRegisterMetaType<RW::SQL::User*>("User*");
				qRegisterMetaType<QList<RW::SQL::ElementConfiguration>*>("QList<ElementConfiguration>*");

				qRegisterMetaType<RW::SQL::Project*>("RW::SQL::Project*");
				qRegisterMetaType<RW::SQL::Project*>("Project*");
			}
		};
	}
}

