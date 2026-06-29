# Hjulmund Engine Architecture

Hjulmund Engine is organized as a set of independent modules that communicate through clear public interfaces. The initial repository foundation focuses on a small, testable core library before higher-level systems such as rendering, assets, scenes, and the editor are introduced.

## Module Boundaries

- **Core** owns process-wide utilities such as logging, assertions, timing, memory, files, jobs, and configuration.
- **Math** owns engine-independent numeric types and algorithms used by runtime and tooling code.
- **Rendering** will own Vulkan-specific implementation details behind renderer-facing abstractions.
- **Editor**, **Runtime**, and **Tools** should depend on engine modules rather than embedding shared systems directly.

## Dependency Direction

Dependencies should flow from higher-level applications toward lower-level modules. Core and Math must remain lightweight and avoid dependencies on rendering, editor, assets, or platform-specific systems unless a platform abstraction is intentionally introduced.

## Build Strategy

CMake is the canonical build system. Each completed module should compile as part of the default build and include automated tests where practical.

## Platform Foundation

The Platform module owns window and input abstractions. Runtime, editor, and renderer code should consume `IWindow`, `EventQueue`, and `InputState` instead of depending directly on a native windowing library. Backend-specific code can be introduced behind these interfaces without changing higher-level engine systems.

`HeadlessWindow` provides a deterministic implementation for tests, tools, servers, and CI environments that need window lifecycle semantics without opening an operating-system window.


## Runtime Application Loop

The Runtime module owns the application loop and coordinates lower-level systems such as windows, events, input, and timesteps. It depends on Core and Platform abstractions, while Core remains independent of Runtime and Platform code.
