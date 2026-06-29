#pragma once

#include <cmath>
#include <cstddef>

namespace Hjulmund::Math {

template <typename T>
struct Vector2 final {
    T x{};
    T y{};

    constexpr Vector2() noexcept = default;
    constexpr Vector2(T xValue, T yValue) noexcept : x(xValue), y(yValue) {}

    [[nodiscard]] constexpr Vector2 operator+(Vector2 other) const noexcept { return { x + other.x, y + other.y }; }
    [[nodiscard]] constexpr Vector2 operator-(Vector2 other) const noexcept { return { x - other.x, y - other.y }; }
    [[nodiscard]] constexpr Vector2 operator*(T scalar) const noexcept { return { x * scalar, y * scalar }; }
    [[nodiscard]] constexpr Vector2 operator/(T scalar) const noexcept { return { x / scalar, y / scalar }; }

    constexpr Vector2& operator+=(Vector2 other) noexcept { x += other.x; y += other.y; return *this; }
    constexpr Vector2& operator-=(Vector2 other) noexcept { x -= other.x; y -= other.y; return *this; }

    [[nodiscard]] constexpr T Dot(Vector2 other) const noexcept { return x * other.x + y * other.y; }
    [[nodiscard]] T Length() const noexcept { return std::sqrt(Dot(*this)); }
};

template <typename T>
struct Vector3 final {
    T x{};
    T y{};
    T z{};

    constexpr Vector3() noexcept = default;
    constexpr Vector3(T xValue, T yValue, T zValue) noexcept : x(xValue), y(yValue), z(zValue) {}

    [[nodiscard]] constexpr Vector3 operator+(Vector3 other) const noexcept { return { x + other.x, y + other.y, z + other.z }; }
    [[nodiscard]] constexpr Vector3 operator-(Vector3 other) const noexcept { return { x - other.x, y - other.y, z - other.z }; }
    [[nodiscard]] constexpr Vector3 operator*(T scalar) const noexcept { return { x * scalar, y * scalar, z * scalar }; }
    [[nodiscard]] constexpr Vector3 operator/(T scalar) const noexcept { return { x / scalar, y / scalar, z / scalar }; }

    constexpr Vector3& operator+=(Vector3 other) noexcept { x += other.x; y += other.y; z += other.z; return *this; }
    constexpr Vector3& operator-=(Vector3 other) noexcept { x -= other.x; y -= other.y; z -= other.z; return *this; }

    [[nodiscard]] constexpr T Dot(Vector3 other) const noexcept { return x * other.x + y * other.y + z * other.z; }
    [[nodiscard]] constexpr Vector3 Cross(Vector3 other) const noexcept
    {
        return {
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x,
        };
    }
    [[nodiscard]] T Length() const noexcept { return std::sqrt(Dot(*this)); }
};

using Vec2 = Vector2<float>;
using Vec3 = Vector3<float>;

} // namespace Hjulmund::Math
