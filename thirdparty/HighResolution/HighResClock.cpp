#include <Windows.h>
#include "HighResClock.h"

namespace
{
	const long long g_Frequency = []() -> long long
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		return frequency.QuadPart;
	}();
}
namespace RW{
    namespace CORE{
        HighResClock::time_point HighResClock::now()
        {
            LARGE_INTEGER count;
            QueryPerformanceCounter(&count);
            return time_point(duration(count.QuadPart * static_cast<rep>(period::den) / g_Frequency));
        }

        std::chrono::milliseconds HighResClock::diffMilli(time_point start, time_point end)
        {
            return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        }

        std::chrono::nanoseconds HighResClock::diffNano(time_point start, time_point end)
        {
            return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        }
    }
}