#include "Hjulmund/Core/Assert.hpp"

#include "Hjulmund/Core/Logger.hpp"

#include <cstdlib>
#include <sstream>

namespace Hjulmund::Core {

[[noreturn]] void ReportAssertionFailure(const std::string_view expression, const std::string_view file, const int line, const std::string_view message)
{
    std::ostringstream stream;
    stream << "Assertion failed: " << expression << " at " << file << ':' << line;
    if (!message.empty()) {
        stream << " (" << message << ')';
    }

    LogCritical(stream.str());
    std::abort();
}

} // namespace Hjulmund::Core
