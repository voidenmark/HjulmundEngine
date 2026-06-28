#include "Hjulmund/Core/Time.hpp"

namespace Hjulmund::Core {

Timer::Timer() noexcept
    : start_(Clock::now())
{
}

void Timer::Reset() noexcept
{
    start_ = Clock::now();
}

std::chrono::nanoseconds Timer::Elapsed() const noexcept
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - start_);
}

double Timer::ElapsedSeconds() const noexcept
{
    return std::chrono::duration<double>(Elapsed()).count();
}

} // namespace Hjulmund::Core
