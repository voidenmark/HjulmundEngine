# Hjulmund Engine Development Roadmap

This roadmap tracks planned engine phases, current completion, and concrete exit criteria. Percentages represent completed, tested, repository-backed work rather than design intent.

## Status Legend

- **Not Started**: No committed implementation exists yet.
- **In Progress**: Foundational implementation exists, but exit criteria are incomplete.
- **Complete**: Exit criteria are implemented, documented, and covered by automated tests where practical.

## Phase Summary

| Phase | Focus | Status | Completion |
| --- | --- | --- | --- |
| Phase 1 | Core, Window, Logging, Math, Vulkan initialization, Input, Camera | In Progress | 38% |
| Phase 2 | Renderer, Mesh loading, Materials, Textures, Scene | Not Started | 0% |
| Phase 3 | ECS, Physics, Audio | Not Started | 0% |
| Phase 4 | Editor, Asset Browser, Inspector, Gizmos | Not Started | 0% |
| Phase 5 | Animation, Particles, Terrain, Post Processing | Not Started | 0% |
| Phase 6 | Networking, Packaging, Plugins, Optimization | Not Started | 0% |

## Phase 1: Foundation

| Area | Status | Completion | Current Evidence | Exit Criteria |
| --- | --- | --- | --- | --- |
| Core framework | In Progress | 45% | Assertions, logging, timing, event queue, and a platform-neutral application loop exist. | Memory utilities, file system, configuration, and job system are implemented and tested. |
| Window system | In Progress | 20% | `IWindow` and `HeadlessWindow` provide deterministic lifecycle and resize/close events. | Native desktop window backend exists behind `IWindow`, supports Vulkan surface creation, and is covered by integration testing where practical. |
| Logging | In Progress | 45% | Thread-safe timestamped logger and convenience functions exist. | Source locations, categories, severity filtering, file/editor sinks, and tests are implemented. |
| Math library | In Progress | 25% | Vector and matrix primitives exist with projection and translation helpers. | Vectors, matrices, quaternions, transforms, bounds, frustum, rays, and camera math are implemented and tested. |
| Vulkan initialization | Not Started | 0% | No Vulkan code committed. | Instance, validation, surface, physical/logical device, queues, swapchain, and teardown are implemented behind renderer interfaces. |
| Input | In Progress | 35% | Keyboard, mouse button, mouse move, and scroll state transitions exist. | Input mapping, controller support, action bindings, and platform backend event translation are implemented and tested. |
| Camera | In Progress | 35% | Perspective camera exposes projection, view, and view-projection matrices. | Camera controller, projection modes, clip-space conventions, resize handling, and tests are complete. |

### Phase 1 Immediate Next Steps

1. Expand math with quaternion and transform support before camera movement and scene hierarchy work.
2. Add a sandbox executable that exercises logging, events, input, camera, and the application loop.
3. Add a native desktop window backend behind `IWindow` after the application loop is stable.
4. Begin Vulkan bootstrap only after the native window backend can provide a renderer-compatible surface hook.
5. Add memory, file system, configuration, and job-system foundations to complete the Core framework exit criteria.

## Phase 2: Rendering and Scene Runtime

Exit criteria for Phase 2:

- Renderer abstraction and Vulkan backend compile on supported platforms.
- Mesh, material, texture, and scene systems are separated by clear interfaces.
- A sandbox scene can render at least one textured mesh with camera movement.
- Renderer utility code has practical tests or validation harnesses.

## Phase 3: Gameplay Runtime Systems

Exit criteria for Phase 3:

- ECS supports components, systems, archetype storage, and queries.
- Physics backend is abstracted behind replaceable engine interfaces.
- Audio backend supports basic playback and 3D positioning.
- Runtime systems are validated with targeted tests and examples.

## Phase 4: Editor Foundation

Exit criteria for Phase 4:

- Editor launches as a separate application using engine modules.
- Scene hierarchy, inspector, viewport, asset browser, console, and gizmos exist in usable form.
- Editor/runtime boundaries are explicit and documented.

## Phase 5: Advanced Content Systems

Exit criteria for Phase 5:

- Animation, particles, terrain, and post-processing systems are implemented incrementally.
- Each system has a runtime-facing API, asset pipeline integration, and practical examples.

## Phase 6: Shipping and Extensibility

Exit criteria for Phase 6:

- Networking, packaging, plugin loading, profiling, and optimization tooling are implemented.
- Build and package workflows are documented and repeatable.
- Performance-sensitive systems have measurement points and optimization notes.

## Completion Rules

A feature can only be marked complete when it:

1. Builds in the default CMake configuration.
2. Has automated tests where practical.
3. Has public API documentation or architecture notes.
4. Respects module dependency direction.
5. Avoids placeholder behavior in production-facing paths.
