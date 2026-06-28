#include "Hjulmund/Core/Logger.hpp"

#include <cassert>
#include <sstream>
#include <string>

int main()
{
    using namespace Hjulmund::Core;

    assert(Logger::ToString(LogLevel::Trace) == "Trace");
    assert(Logger::ToString(LogLevel::Critical) == "Critical");

    std::ostringstream output;
    Logger logger(output);
    logger.Log(LogLevel::Info, "engine online");

    const std::string text = output.str();
    assert(text.find("[Info]") != std::string::npos);
    assert(text.find("engine online") != std::string::npos);

    return 0;
}
