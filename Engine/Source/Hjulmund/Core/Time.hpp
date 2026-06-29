#pragma once

#include <chrono>

namespace Hjulmund::Core {

class Timer final {
public:
    using Clock = std::chrono::steady_clock;

    Timer() noexcept;

    void Reset() noexcept;

    [[nodiscard]] std::chrono::nanoseconds Elapsed() const noexcept;
    [[nodiscard]] double ElapsedSeconds() const noexcept;

private:
    Clock::time_point start_;
};

class Timestep final {
public:
    constexpr explicit Timestep(const double seconds = 0.0) noexcept
        : seconds_(seconds)
    {
    }

    [[nodiscard]] constexpr double Seconds() const noexcept { return seconds_; }
    [[nodiscard]] constexpr double Milliseconds() const noexcept { return seconds_ * 1000.0; }

private:
    double seconds_;
};

} // namespace Hjulmund::Core
