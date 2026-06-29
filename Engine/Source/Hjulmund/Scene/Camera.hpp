#pragma once

#include "Hjulmund/Math/Matrix.hpp"

namespace Hjulmund::Scene {

class PerspectiveCamera final {
public:
    PerspectiveCamera(float verticalFovRadians, float aspectRatio, float nearPlane, float farPlane) noexcept;

    void SetProjection(float verticalFovRadians, float aspectRatio, float nearPlane, float farPlane) noexcept;
    void SetPosition(Math::Vec3 position) noexcept { position_ = position; }

    [[nodiscard]] Math::Vec3 Position() const noexcept { return position_; }
    [[nodiscard]] Math::Mat4 Projection() const noexcept;
    [[nodiscard]] Math::Mat4 View() const noexcept;
    [[nodiscard]] Math::Mat4 ViewProjection() const noexcept;

private:
    float verticalFovRadians_{};
    float aspectRatio_{};
    float nearPlane_{};
    float farPlane_{};
    Math::Vec3 position_{};
};

} // namespace Hjulmund::Scene
