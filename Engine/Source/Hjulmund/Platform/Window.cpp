#include "Hjulmund/Platform/Window.hpp"

#include <algorithm>
#include <limits>
#include <utility>

namespace Hjulmund::Platform {
namespace {

[[nodiscard]] int ClampToEventDimension(const std::uint32_t value) noexcept
{
    constexpr auto maxValue = static_cast<std::uint32_t>(std::numeric_limits<int>::max());
    return static_cast<int>(std::min(value, maxValue));
}

} // namespace

HeadlessWindow::HeadlessWindow(WindowDesc desc)
    : desc_(std::move(desc))
{
}

void HeadlessWindow::PollEvents(Core::EventQueue& events)
{
    if (resizeEventPending_) {
        resizeEventPending_ = false;
        events.Push(Core::WindowResizeEvent { ClampToEventDimension(desc_.width), ClampToEventDimension(desc_.height) });
    }

    if (closeEventPending_) {
        closeEventPending_ = false;
        events.Push(Core::WindowCloseEvent {});
    }
}

void HeadlessWindow::RequestClose() noexcept
{
    if (!shouldClose_) {
        closeEventPending_ = true;
    }
    shouldClose_ = true;
}

void HeadlessWindow::Resize(const std::uint32_t width, const std::uint32_t height)
{
    desc_.width = width;
    desc_.height = height;
    resizeEventPending_ = true;
}

std::unique_ptr<IWindow> CreateHeadlessWindow(WindowDesc desc)
{
    return std::make_unique<HeadlessWindow>(std::move(desc));
}

} // namespace Hjulmund::Platform
