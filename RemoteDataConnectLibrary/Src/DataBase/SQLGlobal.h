#pragma once
#include "..\Global.h"

namespace spdlog
{
	class logger;
}


namespace RW{
	enum class TypeOfElement
	{
		USB,
		IO,
		RELAY,
		SOUND,
		INVALID
	};

	enum class SourceType
	{
		SQL,
		XML,
		MOCK
	};
	//Q_ENUM(SourceType);


	enum class RemoteWorkstationState
	{
		ON,
		OFF,
		RESERVE,
		DEFECT
	};
}	
Q_DECLARE_METATYPE(RW::RemoteWorkstationState)
