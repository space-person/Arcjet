#pragma once

#ifdef AJ_PLATFORM_WINDOWS
	#ifdef AJ_BUILD_DLL
		#define ARCJET_API __declspec(dllexport)
	#else
		#define ARCJET_API __declspec(dllimport)
	#endif
#else
	#error Arcjet only supports Windows !
#endif
