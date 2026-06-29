#pragma once

#include <iosfwd>
#include <mutex>
#include <string_view>

namespace Hjulmund::Core {

enum class LogLevel {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Critical
};

class Logger final {
public:
    explicit Logger(std::ostream& output) noexcept;

    void Log(LogLevel level, std::string_view message);

    [[nodiscard]] static std::string_view ToString(LogLevel level) noexcept;

private:
    std::ostream* output_;
    std::mutex mutex_;
};

Logger& GetDefaultLogger() noexcept;

void Log(LogLevel level, std::string_view message);
void LogTrace(std::string_view message);
void LogDebug(std::string_view message);
void LogInfo(std::string_view message);
void LogWarning(std::string_view message);
void LogError(std::string_view message);
void LogCritical(std::string_view message);

} // namespace Hjulmund::Core
