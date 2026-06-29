#include "Hjulmund/Runtime/Application.hpp"

#include <cassert>
#include <cstdint>
#include <optional>
#include <utility>
#include <variant>

namespace {

class CountingDelegate final : public Hjulmund::Runtime::IApplicationDelegate {
public:
    void OnStart() override { ++starts; }
    void OnEvent(const Hjulmund::Core::Event& event) override
    {
        ++events;
        if (std::holds_alternative<Hjulmund::Core::WindowCloseEvent>(event)) {
            sawClose = true;
        }
    }
    void OnUpdate(const Hjulmund::Runtime::FrameContext& context) override
    {
        ++updates;
        lastFrameIndex = context.frameIndex;
        assert(context.deltaTime.Seconds() >= 0.0);
        assert(context.window.Width() == 320);
    }
    void OnStop() override { ++stops; }

    int starts{};
    int events{};
    int updates{};
    int stops{};
    bool sawClose{};
    std::uint64_t lastFrameIndex{};
};

} // namespace

int main()
{
    using namespace Hjulmund::Platform;
    using namespace Hjulmund::Runtime;

    CountingDelegate delegate;
    Application app(ApplicationDesc {
        CreateHeadlessWindow(WindowDesc { "Application Test", 320, 180, false }),
        &delegate,
        3U,
    });

    const int exitCode = app.Run();
    assert(exitCode == 0);
    assert(!app.IsRunning());
    assert(app.FrameCount() == 3);
    assert(delegate.starts == 1);
    assert(delegate.updates == 3);
    assert(delegate.stops == 1);
    assert(delegate.lastFrameIndex == 2);

    auto closeWindow = CreateHeadlessWindow(WindowDesc { "Close Test", 320, 180, false });
    closeWindow->RequestClose();
    CountingDelegate closeDelegate;
    Application closeApp(ApplicationDesc { std::move(closeWindow), &closeDelegate, std::nullopt });
    assert(closeApp.Run() == 0);
    assert(closeApp.FrameCount() == 0);
    assert(closeDelegate.starts == 1);
    assert(closeDelegate.updates == 0);
    assert(closeDelegate.stops == 1);

    return 0;
}
