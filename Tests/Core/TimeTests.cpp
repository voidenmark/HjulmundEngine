#include "Hjulmund/Core/Time.hpp"

#include <cassert>
#include <thread>

int main()
{
    using namespace Hjulmund::Core;

    const Timestep step(1.5);
    assert(step.Seconds() == 1.5);
    assert(step.Milliseconds() == 1500.0);

    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    assert(timer.Elapsed().count() > 0);
    assert(timer.ElapsedSeconds() > 0.0);

    timer.Reset();
    assert(timer.ElapsedSeconds() >= 0.0);

    return 0;
}
