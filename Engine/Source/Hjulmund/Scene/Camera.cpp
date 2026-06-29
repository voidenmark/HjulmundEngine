#include "Hjulmund/Scene/Camera.hpp"

namespace Hjulmund::Scene {

PerspectiveCamera::PerspectiveCamera(const float verticalFovRadians, const float aspectRatio, const float nearPlane, const float farPlane) noexcept
{
    SetProjection(verticalFovRadians, aspectRatio, nearPlane, farPlane);
}

void PerspectiveCamera::SetProjection(const float verticalFovRadians, const float aspectRatio, const float nearPlane, const float farPlane) noexcept
{
    verticalFovRadians_ = verticalFovRadians;
    aspectRatio_ = aspectRatio;
    nearPlane_ = nearPlane;
    farPlane_ = farPlane;
}

Math::Mat4 PerspectiveCamera::Projection() const noexcept
{
    return Math::Perspective(verticalFovRadians_, aspectRatio_, nearPlane_, farPlane_);
}

Math::Mat4 PerspectiveCamera::View() const noexcept
{
    return Math::Translation(position_ * -1.0F);
}

Math::Mat4 PerspectiveCamera::ViewProjection() const noexcept
{
    return Projection() * View();
}

} // namespace Hjulmund::Scene
