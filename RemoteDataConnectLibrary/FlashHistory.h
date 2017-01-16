#pragma once
#include "Entity.h"
#include "..\SQLGlobal.h"
namespace RW{
	namespace SQL{
		class REMOTE_DATA_CONNECT_API FlashHistory :
			public Entity
		{
		public:
			FlashHistory();
			~FlashHistory();
		};
	}
}