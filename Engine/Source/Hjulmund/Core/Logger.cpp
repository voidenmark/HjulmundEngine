#include "Hjulmund/Core/Logger.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <ostream>

namespace Hjulmund::Core {
namespace {

void WriteTimestamp(std::ostream& output)
{
    const auto now = std::chrono::system_clock::now();
    const auto time = std::chrono::system_clock::to_time_t(now);
#if defined(_MSC_VER)
    std::tm localTime{};
    localtime_s(&localTime, &time);
    output << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
#else
    std::tm localTime{};
    localtime_r(&time, &localTime);
    output << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
#endif
}

} // namespace

Logger::Logger(std::ostream& output) noexcept
    : output_(&output)
{
}

void Logger::Log(const LogLevel level, const std::string_view message)
{
    std::scoped_lock lock(mutex_);
    WriteTimestamp(*output_);
    *output_ << " [" << ToString(level) << "] " << message << '\n';
}

std::string_view Logger::ToString(const LogLevel level) noexcept
{
    switch (level) {
    case LogLevel::Trace: return "Trace";
    case LogLevel::Debug: return "Debug";
    case LogLevel::Info: return "Info";
    case LogLevel::Warning: return "Warning";
    case LogLevel::Error: return "Error";
    case LogLevel::Critical: return "Critical";
    }

    return "Unknown";
}

Logger& GetDefaultLogger() noexcept
{
    static Logger logger(std::clog);
    return logger;
}

void Log(const LogLevel level, const std::string_view message)
{
    GetDefaultLogger().Log(level, message);
}

void LogTrace(const std::string_view message) { Log(LogLevel::Trace, message); }
void LogDebug(const std::string_view message) { Log(LogLevel::Debug, message); }
void LogInfo(const std::string_view message) { Log(LogLevel::Info, message); }
void LogWarning(const std::string_view message) { Log(LogLevel::Warning, message); }
void LogError(const std::string_view message) { Log(LogLevel::Error, message); }
void LogCritical(const std::string_view message) { Log(LogLevel::Critical, message); }

} // namespace Hjulmund::Core
