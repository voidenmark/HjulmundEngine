# Hjulmund Engine

<p align="center">
  <strong>A modern, high-performance, Vulkan-powered game engine built for the next generation of interactive experiences.</strong>
</p>

<p align="center">
  <em>Designed and developed by Hjulmund.</em>
</p>

---

## Overview

Hjulmund Engine is a custom-built, modular game engine focused on performance, scalability, and long-term maintainability. It is being developed from the ground up to power future titles from Hjulmund Studios while remaining flexible enough for a wide range of real-time applications.

Rather than replicating existing engines, Hjulmund Engine emphasizes clean architecture, modern graphics technologies, and a streamlined development workflow.

---

## Vision

Create a professional-grade engine capable of powering:

* AAA-quality indie games
* Large-scale 3D worlds
* Multiplayer experiences
* Simulation software
* Interactive visualization
* Cinematic productions
* Future Hjulmund Studios projects

Every system is designed with longevity in mind, allowing the engine to evolve over many years without major architectural rewrites.

---

## Core Principles

* Performance First
* Modern Architecture
* Modular Design
* Cross-Platform
* Developer-Friendly
* Production Ready
* Maintainable Code
* Extensible Systems

---

## Planned Features

### Rendering

* Vulkan Renderer
* Physically Based Rendering (PBR)
* HDR Rendering
* Deferred Rendering
* Forward+
* Shadow Mapping
* Bloom
* SSAO
* GPU Instancing
* Environment Lighting
* Skyboxes
* Frustum Culling
* Occlusion Culling
* Level of Detail (LOD)

### Engine Core

* Memory Management
* Logging System
* Job System
* Threading
* Configuration System
* File System
* Time Management
* Event System

### Mathematics

* Vector Library
* Matrix Library
* Quaternions
* Transform System
* Bounding Volumes
* Frustum Mathematics
* Ray Casting

### Scene System

* Scene Graph
* Entity Hierarchy
* Serialization
* Prefabs

### Entity Component System

* High-performance ECS
* Archetype Storage
* Queries
* Modular Systems

### Physics

* Collision Detection
* Rigid Bodies
* Character Controller
* Triggers
* Raycasts

### Animation

* Skeletal Animation
* Blend Trees
* Animation Graph
* Future IK Support

### Audio

* 3D Audio
* Spatial Sound
* Streaming Audio

### Networking

* Multiplayer Support
* Client/Server Architecture
* Replication
* Prediction
* Interpolation

### Asset Pipeline

Supported asset formats include:

* glTF
* FBX
* OBJ
* PNG
* JPG
* WAV
* OGG

Assets will be automatically processed into optimized runtime formats.

---

# Editor

A fully integrated editor is planned, featuring:

* Scene Hierarchy
* Inspector
* Viewport
* Asset Browser
* Console
* Profiler
* Material Editor
* Animation Editor
* Node Editor
* Terrain Tools
* Lighting Controls
* Project Settings
* Packaging Tools

---

## Technology Stack

| Component       | Technology                                |
| --------------- | ----------------------------------------- |
| Language        | C++23                                     |
| Graphics API    | Vulkan                                    |
| Build System    | CMake                                     |
| Version Control | Git                                       |
| Platforms       | Windows, Linux (planned), macOS (planned) |

---

## Repository Structure

```text
HjulmundEngine/
│
├── Engine/
├── Editor/
├── Runtime/
├── Projects/
├── Tools/
├── Shaders/
├── Assets/
├── Documentation/
├── Examples/
├── Tests/
└── ThirdParty/
```

---

## Development Roadmap

### Phase 1

* Core Framework
* Window System
* Logging
* Math Library
* Vulkan Initialization
* Input
* Camera

### Phase 2

* Rendering Pipeline
* Mesh Loading
* Materials
* Textures
* Scene Management

### Phase 3

* Entity Component System
* Physics
* Audio

### Phase 4

* Editor Foundation
* Asset Browser
* Inspector
* Gizmos

### Phase 5

* Animation
* Terrain
* Particle Systems
* Post Processing

### Phase 6

* Networking
* Plugin System
* Packaging
* Optimization
* Documentation

---

## Development Philosophy

Hjulmund Engine is developed with a strict focus on quality over speed.

Every module is expected to be:

* Fully documented
* Well tested
* Loosely coupled
* Easy to maintain
* Performance conscious

Features are completed incrementally rather than added in unfinished states.

---

## Current Status

**Early Development — Phase 1 In Progress**

The architecture and core systems are actively being designed and implemented. Phase progress, completion criteria, and immediate next steps are tracked in [`Documentation/DevelopmentRoadmap.md`](Documentation/DevelopmentRoadmap.md).

The project is not yet production-ready.

---

## Contributing

Contributions are welcome once the engine reaches a stable public development phase.

Until then, the repository primarily serves as the official development home for Hjulmund Engine.

---

## License

License information will be added before the first public release.

---

## Credits

Created and maintained by **Hjulmund**.

Built with a passion for modern graphics programming, software engineering, and game development.

---

> "It's not enough to be innovative. You have to build something that lasts."
