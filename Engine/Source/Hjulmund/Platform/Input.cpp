#include "Hjulmund/Platform/Input.hpp"

namespace Hjulmund::Platform {

void InputState::BeginFrame() noexcept
{
    keysPressed_.fill(false);
    keysReleased_.fill(false);
    mouseButtonsPressed_.fill(false);
    mouseButtonsReleased_.fill(false);
    mouseDeltaX_ = 0.0;
    mouseDeltaY_ = 0.0;
    scrollDeltaX_ = 0.0;
    scrollDeltaY_ = 0.0;
}

void InputState::Apply(const Core::Event& event) noexcept
{
    if (const auto* keyPressed = std::get_if<Core::KeyPressedEvent>(&event); keyPressed != nullptr && IsValidKey(keyPressed->key)) {
        const auto index = static_cast<std::size_t>(keyPressed->key);
        keysPressed_[index] = !keysDown_[index] || keyPressed->repeat;
        keysDown_[index] = true;
        return;
    }

    if (const auto* keyReleased = std::get_if<Core::KeyReleasedEvent>(&event); keyReleased != nullptr && IsValidKey(keyReleased->key)) {
        const auto index = static_cast<std::size_t>(keyReleased->key);
        keysDown_[index] = false;
        keysReleased_[index] = true;
        return;
    }

    if (const auto* pressed = std::get_if<Core::MouseButtonPressedEvent>(&event); pressed != nullptr && IsValidMouseButton(pressed->button)) {
        const auto index = static_cast<std::size_t>(pressed->button);
        mouseButtonsPressed_[index] = !mouseButtonsDown_[index];
        mouseButtonsDown_[index] = true;
        return;
    }

    if (const auto* released = std::get_if<Core::MouseButtonReleasedEvent>(&event); released != nullptr && IsValidMouseButton(released->button)) {
        const auto index = static_cast<std::size_t>(released->button);
        mouseButtonsDown_[index] = false;
        mouseButtonsReleased_[index] = true;
        return;
    }

    if (const auto* moved = std::get_if<Core::MouseMovedEvent>(&event); moved != nullptr) {
        if (hasMousePosition_) {
            mouseDeltaX_ += moved->x - mouseX_;
            mouseDeltaY_ += moved->y - mouseY_;
        }
        mouseX_ = moved->x;
        mouseY_ = moved->y;
        hasMousePosition_ = true;
        return;
    }

    if (const auto* scrolled = std::get_if<Core::MouseScrolledEvent>(&event); scrolled != nullptr) {
        scrollDeltaX_ += scrolled->xOffset;
        scrollDeltaY_ += scrolled->yOffset;
    }
}

bool InputState::IsKeyDown(const int key) const noexcept { return IsValidKey(key) && keysDown_[static_cast<std::size_t>(key)]; }
bool InputState::WasKeyPressed(const int key) const noexcept { return IsValidKey(key) && keysPressed_[static_cast<std::size_t>(key)]; }
bool InputState::WasKeyReleased(const int key) const noexcept { return IsValidKey(key) && keysReleased_[static_cast<std::size_t>(key)]; }
bool InputState::IsMouseButtonDown(const int button) const noexcept { return IsValidMouseButton(button) && mouseButtonsDown_[static_cast<std::size_t>(button)]; }
bool InputState::WasMouseButtonPressed(const int button) const noexcept { return IsValidMouseButton(button) && mouseButtonsPressed_[static_cast<std::size_t>(button)]; }
bool InputState::WasMouseButtonReleased(const int button) const noexcept { return IsValidMouseButton(button) && mouseButtonsReleased_[static_cast<std::size_t>(button)]; }

bool InputState::IsValidKey(const int key) noexcept { return key >= 0 && static_cast<std::size_t>(key) < MaxKeys; }
bool InputState::IsValidMouseButton(const int button) noexcept { return button >= 0 && static_cast<std::size_t>(button) < MaxMouseButtons; }

} // namespace Hjulmund::Platform
