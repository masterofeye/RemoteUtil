#pragma once

#if defined(REMOTE_DATA_CONNECT_LIBRARY_EXPORT) // inside DLL
#   define REMOTE_DATA_CONNECT_API   __declspec(dllexport)
#else // outside DLL
#   define REMOTE_DATA_CONNECT_API   __declspec(dllimport)
#endif  // XYZLIBRARY_EXPORT