#include "Hjulmund/Math/Vector.hpp"

#include <cassert>
#include <cmath>

int main()
{
    using Hjulmund::Math::Vec2;
    using Hjulmund::Math::Vec3;

    constexpr Vec2 a(1.0F, 2.0F);
    constexpr Vec2 b(3.0F, 4.0F);
    constexpr Vec2 c = a + b;
    static_assert(c.x == 4.0F && c.y == 6.0F);
    static_assert(a.Dot(b) == 11.0F);

    constexpr Vec3 right(1.0F, 0.0F, 0.0F);
    constexpr Vec3 up(0.0F, 1.0F, 0.0F);
    constexpr Vec3 forward = right.Cross(up);
    static_assert(forward.x == 0.0F && forward.y == 0.0F && forward.z == 1.0F);

    const Vec3 vector(2.0F, 3.0F, 6.0F);
    assert(std::abs(vector.Length() - 7.0F) < 0.0001F);

    return 0;
}
