#include "Hjulmund/Core/Event.hpp"
#include "Hjulmund/Platform/Input.hpp"
#include "Hjulmund/Platform/Window.hpp"

#include <cassert>
#include <memory>
#include <variant>

int main()
{
    using namespace Hjulmund::Core;
    using namespace Hjulmund::Platform;

    EventQueue events;
    events.Push(KeyPressedEvent { 65, false });
    events.Push(MouseMovedEvent { 10.0, 20.0 });
    assert(events.Size() == 2);

    InputState input;
    const auto keyEvent = events.Pop();
    assert(keyEvent.has_value());
    input.Apply(*keyEvent);
    assert(input.IsKeyDown(65));
    assert(input.WasKeyPressed(65));

    input.BeginFrame();
    assert(input.IsKeyDown(65));
    assert(!input.WasKeyPressed(65));

    input.Apply(KeyReleasedEvent { 65 });
    assert(!input.IsKeyDown(65));
    assert(input.WasKeyReleased(65));

    events.Clear();

    const auto window = CreateHeadlessWindow(WindowDesc { "Test", 640, 480, false });
    assert(window->Title() == "Test");
    assert(window->Width() == 640);
    assert(window->Height() == 480);
    assert(!window->IsResizable());

    auto* headless = dynamic_cast<HeadlessWindow*>(window.get());
    assert(headless != nullptr);
    headless->Resize(800, 600);
    window->PollEvents(events);
    const auto resizeEvent = events.Pop();
    assert(resizeEvent.has_value());
    const auto* resize = std::get_if<WindowResizeEvent>(&*resizeEvent);
    assert(resize != nullptr);
    assert(resize->width == 800);
    assert(resize->height == 600);

    window->RequestClose();
    assert(window->ShouldClose());
    window->PollEvents(events);
    const auto closeEvent = events.Pop();
    assert(closeEvent.has_value());
    assert(std::holds_alternative<WindowCloseEvent>(*closeEvent));

    return 0;
}
