#include "Hjulmund/Runtime/Application.hpp"

#include "Hjulmund/Core/Assert.hpp"

#include <utility>
#include <variant>

namespace Hjulmund::Runtime {

Application::Application(ApplicationDesc desc)
    : window_(std::move(desc.window))
    , delegate_(desc.delegate)
    , maxFrames_(desc.maxFrames)
{
    HJULMUND_ASSERT(window_ != nullptr, "Application requires a valid window");
}

int Application::Run()
{
    running_ = true;
    frameCount_ = 0;

    if (delegate_ != nullptr) {
        delegate_->OnStart();
    }

    Core::Timer frameTimer;

    while (running_ && !window_->ShouldClose()) {
        input_.BeginFrame();
        window_->PollEvents(events_);
        DrainEvents();

        const Core::Timestep deltaTime(frameTimer.ElapsedSeconds());
        frameTimer.Reset();

        if (delegate_ != nullptr) {
            delegate_->OnUpdate(FrameContext { frameCount_, deltaTime, input_, *window_ });
        }

        ++frameCount_;

        if (maxFrames_.has_value() && frameCount_ >= *maxFrames_) {
            RequestStop();
        }
    }

    if (delegate_ != nullptr) {
        delegate_->OnStop();
    }

    running_ = false;
    return 0;
}

void Application::RequestStop() noexcept
{
    running_ = false;
}

void Application::DrainEvents()
{
    while (auto event = events_.Pop()) {
        input_.Apply(*event);

        if (std::holds_alternative<Core::WindowCloseEvent>(*event)) {
            RequestStop();
        }

        if (delegate_ != nullptr) {
            delegate_->OnEvent(*event);
        }
    }
}

} // namespace Hjulmund::Runtime
