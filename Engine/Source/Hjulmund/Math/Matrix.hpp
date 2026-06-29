#pragma once

#include "Hjulmund/Math/Vector.hpp"

#include <array>
#include <cmath>
#include <cstddef>

namespace Hjulmund::Math {

struct Mat4 final {
    std::array<float, 16> values{};

    [[nodiscard]] static constexpr Mat4 Identity() noexcept
    {
        return Mat4 { { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F } };
    }

    [[nodiscard]] constexpr float& operator()(std::size_t row, std::size_t column) noexcept { return values[(column * 4U) + row]; }
    [[nodiscard]] constexpr float operator()(std::size_t row, std::size_t column) const noexcept { return values[(column * 4U) + row]; }
};

[[nodiscard]] constexpr Mat4 operator*(const Mat4& left, const Mat4& right) noexcept
{
    Mat4 result{};
    for (std::size_t column = 0; column < 4; ++column) {
        for (std::size_t row = 0; row < 4; ++row) {
            result(row, column) = left(row, 0) * right(0, column)
                + left(row, 1) * right(1, column)
                + left(row, 2) * right(2, column)
                + left(row, 3) * right(3, column);
        }
    }
    return result;
}

[[nodiscard]] inline Mat4 Perspective(const float verticalFovRadians, const float aspectRatio, const float nearPlane, const float farPlane) noexcept
{
    const float f = 1.0F / std::tan(verticalFovRadians * 0.5F);
    Mat4 result{};
    result(0, 0) = f / aspectRatio;
    result(1, 1) = f;
    result(2, 2) = farPlane / (nearPlane - farPlane);
    result(2, 3) = (farPlane * nearPlane) / (nearPlane - farPlane);
    result(3, 2) = -1.0F;
    return result;
}

[[nodiscard]] inline Mat4 Translation(const Vec3 translation) noexcept
{
    Mat4 result = Mat4::Identity();
    result(0, 3) = translation.x;
    result(1, 3) = translation.y;
    result(2, 3) = translation.z;
    return result;
}

[[nodiscard]] inline float Radians(const float degrees) noexcept
{
    return degrees * 0.01745329251994329576923690768489F;
}

} // namespace Hjulmund::Math
