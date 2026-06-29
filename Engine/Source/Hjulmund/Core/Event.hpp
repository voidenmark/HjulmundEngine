#pragma once

#include <cstddef>
#include <optional>
#include <queue>
#include <variant>

namespace Hjulmund::Core {

enum class EventType {
    WindowClose,
    WindowResize,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

struct WindowCloseEvent final {};
struct WindowResizeEvent final { int width{}; int height{}; };
struct KeyPressedEvent final { int key{}; bool repeat{}; };
struct KeyReleasedEvent final { int key{}; };
struct MouseButtonPressedEvent final { int button{}; };
struct MouseButtonReleasedEvent final { int button{}; };
struct MouseMovedEvent final { double x{}; double y{}; };
struct MouseScrolledEvent final { double xOffset{}; double yOffset{}; };

using Event = std::variant<
    WindowCloseEvent,
    WindowResizeEvent,
    KeyPressedEvent,
    KeyReleasedEvent,
    MouseButtonPressedEvent,
    MouseButtonReleasedEvent,
    MouseMovedEvent,
    MouseScrolledEvent>;

[[nodiscard]] constexpr EventType GetEventType(const Event& event) noexcept
{
    return static_cast<EventType>(event.index());
}

class EventQueue final {
public:
    void Push(Event event);
    [[nodiscard]] std::optional<Event> Pop();
    [[nodiscard]] bool Empty() const noexcept;
    [[nodiscard]] std::size_t Size() const noexcept;
    void Clear() noexcept;

private:
    std::queue<Event> events_;
};

} // namespace Hjulmund::Core
