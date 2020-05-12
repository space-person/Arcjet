#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Arcjet
{
	class ARCJET_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

// Core log macros
#define AJ_CORE_TRACE(...)    ::Arcjet::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AJ_CORE_INFO(...)     ::Arcjet::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AJ_CORE_WARN(...)     ::Arcjet::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AJ_CORE_ERROR(...)    ::Arcjet::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AJ_CORE_FATAL(...)    ::Arcjet::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AJ_TRACE(...)         ::Arcjet::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AJ_INFO(...)          ::Arcjet::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AJ_WARN(...)          ::Arcjet::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AJ_ERROR(...)         ::Arcjet::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AJ_FATAL(...)         ::Arcjet::Log::GetCoreLogger()->fatal(__VA_ARGS__)