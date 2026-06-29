#pragma once

#include "Hjulmund/Core/Event.hpp"

#include <array>
#include <cstddef>

namespace Hjulmund::Platform {

class InputState final {
public:
    static constexpr std::size_t MaxKeys = 512;
    static constexpr std::size_t MaxMouseButtons = 16;

    void BeginFrame() noexcept;
    void Apply(const Core::Event& event) noexcept;

    [[nodiscard]] bool IsKeyDown(int key) const noexcept;
    [[nodiscard]] bool WasKeyPressed(int key) const noexcept;
    [[nodiscard]] bool WasKeyReleased(int key) const noexcept;

    [[nodiscard]] bool IsMouseButtonDown(int button) const noexcept;
    [[nodiscard]] bool WasMouseButtonPressed(int button) const noexcept;
    [[nodiscard]] bool WasMouseButtonReleased(int button) const noexcept;

    [[nodiscard]] double MouseX() const noexcept { return mouseX_; }
    [[nodiscard]] double MouseY() const noexcept { return mouseY_; }
    [[nodiscard]] double MouseDeltaX() const noexcept { return mouseDeltaX_; }
    [[nodiscard]] double MouseDeltaY() const noexcept { return mouseDeltaY_; }
    [[nodiscard]] double ScrollDeltaX() const noexcept { return scrollDeltaX_; }
    [[nodiscard]] double ScrollDeltaY() const noexcept { return scrollDeltaY_; }

private:
    [[nodiscard]] static bool IsValidKey(int key) noexcept;
    [[nodiscard]] static bool IsValidMouseButton(int button) noexcept;

    std::array<bool, MaxKeys> keysDown_{};
    std::array<bool, MaxKeys> keysPressed_{};
    std::array<bool, MaxKeys> keysReleased_{};
    std::array<bool, MaxMouseButtons> mouseButtonsDown_{};
    std::array<bool, MaxMouseButtons> mouseButtonsPressed_{};
    std::array<bool, MaxMouseButtons> mouseButtonsReleased_{};
    double mouseX_{};
    double mouseY_{};
    double mouseDeltaX_{};
    double mouseDeltaY_{};
    double scrollDeltaX_{};
    double scrollDeltaY_{};
    bool hasMousePosition_{};
};

} // namespace Hjulmund::Platform
