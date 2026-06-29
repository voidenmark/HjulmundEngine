#pragma once

#include "Hjulmund/Core/Event.hpp"

#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

namespace Hjulmund::Platform {

struct WindowDesc final {
    std::string title = "Hjulmund Engine";
    std::uint32_t width = 1280;
    std::uint32_t height = 720;
    bool resizable = true;
};

class IWindow {
public:
    virtual ~IWindow() = default;

    virtual void PollEvents(Core::EventQueue& events) = 0;
    virtual void RequestClose() noexcept = 0;

    [[nodiscard]] virtual bool ShouldClose() const noexcept = 0;
    [[nodiscard]] virtual std::string_view Title() const noexcept = 0;
    [[nodiscard]] virtual std::uint32_t Width() const noexcept = 0;
    [[nodiscard]] virtual std::uint32_t Height() const noexcept = 0;
    [[nodiscard]] virtual bool IsResizable() const noexcept = 0;
};

class HeadlessWindow final : public IWindow {
public:
    explicit HeadlessWindow(WindowDesc desc);

    void PollEvents(Core::EventQueue& events) override;
    void RequestClose() noexcept override;
    void Resize(std::uint32_t width, std::uint32_t height);

    [[nodiscard]] bool ShouldClose() const noexcept override { return shouldClose_; }
    [[nodiscard]] std::string_view Title() const noexcept override { return desc_.title; }
    [[nodiscard]] std::uint32_t Width() const noexcept override { return desc_.width; }
    [[nodiscard]] std::uint32_t Height() const noexcept override { return desc_.height; }
    [[nodiscard]] bool IsResizable() const noexcept override { return desc_.resizable; }

private:
    WindowDesc desc_;
    bool shouldClose_{};
    bool closeEventPending_{};
    bool resizeEventPending_{};
};

[[nodiscard]] std::unique_ptr<IWindow> CreateHeadlessWindow(WindowDesc desc);

} // namespace Hjulmund::Platform
