#pragma once

#include "Hjulmund/Core/Event.hpp"
#include "Hjulmund/Core/Time.hpp"
#include "Hjulmund/Platform/Input.hpp"
#include "Hjulmund/Platform/Window.hpp"

#include <cstdint>
#include <memory>
#include <optional>

namespace Hjulmund::Runtime {

struct FrameContext final {
    std::uint64_t frameIndex{};
    Core::Timestep deltaTime{};
    Platform::InputState& input;
    Platform::IWindow& window;
};

class IApplicationDelegate {
public:
    virtual ~IApplicationDelegate() = default;

    virtual void OnStart() {}
    virtual void OnEvent(const Core::Event& event) { (void)event; }
    virtual void OnUpdate(const FrameContext& context) { (void)context; }
    virtual void OnStop() {}
};

struct ApplicationDesc final {
    std::unique_ptr<Platform::IWindow> window;
    IApplicationDelegate* delegate{};
    std::optional<std::uint64_t> maxFrames{};
};

class Application final {
public:
    explicit Application(ApplicationDesc desc);

    int Run();
    void RequestStop() noexcept;

    [[nodiscard]] bool IsRunning() const noexcept { return running_; }
    [[nodiscard]] std::uint64_t FrameCount() const noexcept { return frameCount_; }
    [[nodiscard]] Platform::IWindow& Window() noexcept { return *window_; }
    [[nodiscard]] const Platform::IWindow& Window() const noexcept { return *window_; }
    [[nodiscard]] Platform::InputState& Input() noexcept { return input_; }
    [[nodiscard]] const Platform::InputState& Input() const noexcept { return input_; }

private:
    void DrainEvents();

    std::unique_ptr<Platform::IWindow> window_;
    IApplicationDelegate* delegate_{};
    std::optional<std::uint64_t> maxFrames_{};
    Core::EventQueue events_{};
    Platform::InputState input_{};
    bool running_{};
    std::uint64_t frameCount_{};
};

} // namespace Hjulmund::Runtime
