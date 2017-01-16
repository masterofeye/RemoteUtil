#pragma once
#include <qobject.h>
#include "SQLGlobal.h"

namespace RW{
	namespace SQL{

		class FlashHistory;
		class FlashHistoryPrivate : public QObject
		{
			Q_OBJECT
				Q_DISABLE_COPY(FlashHistoryPrivate)
				Q_DECLARE_PUBLIC(FlashHistory)
		private:
			FlashHistory * const q_ptr;
		public:
		public:
			FlashHistoryPrivate(FlashHistory *Parent);
			~FlashHistoryPrivate();
		};
	}
}