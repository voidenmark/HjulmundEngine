#pragma once

#include <string_view>

namespace Hjulmund::Core {

[[noreturn]] void ReportAssertionFailure(std::string_view expression, std::string_view file, int line, std::string_view message);

} // namespace Hjulmund::Core

#define HJULMUND_ASSERT(expression, message) \
    do { \
        if (!(expression)) { \
            ::Hjulmund::Core::ReportAssertionFailure(#expression, __FILE__, __LINE__, message); \
        } \
    } while (false)
