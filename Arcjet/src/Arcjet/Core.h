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

#ifdef AJ_ENABLE_ASSERTS
	#define AJ_ASSERT(x, ...) { if(!(x)) { AJ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AJ_CORE_ASSERT(x, ...) { if(!(x)) { AJ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AJ_ASSERT(x, ...)
	#define AJ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define AJ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)