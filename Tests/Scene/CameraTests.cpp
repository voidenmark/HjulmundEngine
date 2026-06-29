#include "Hjulmund/Scene/Camera.hpp"

#include <cassert>
#include <cmath>

int main()
{
    using Hjulmund::Math::Radians;
    using Hjulmund::Math::Vec3;
    using Hjulmund::Scene::PerspectiveCamera;

    PerspectiveCamera camera(Radians(60.0F), 16.0F / 9.0F, 0.1F, 1000.0F);
    camera.SetPosition(Vec3(1.0F, 2.0F, 3.0F));

    const auto view = camera.View();
    assert(std::abs(view(0, 3) + 1.0F) < 0.0001F);
    assert(std::abs(view(1, 3) + 2.0F) < 0.0001F);
    assert(std::abs(view(2, 3) + 3.0F) < 0.0001F);

    const auto projection = camera.Projection();
    assert(projection(0, 0) > 0.0F);
    assert(projection(1, 1) > 0.0F);
    assert(projection(3, 2) == -1.0F);

    const auto viewProjection = camera.ViewProjection();
    assert(viewProjection(0, 0) > 0.0F);

    return 0;
}
