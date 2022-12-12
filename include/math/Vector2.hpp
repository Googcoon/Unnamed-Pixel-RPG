#pragma once

#include <cmath>

class Vector2
{
public:
    Vector2(const float x, const float y) : x(x), y(y) {}

    [[nodiscard]] float length() const { return std::sqrt(x * x + y * y); }

    Vector2 operator+(const Vector2& v2) const
    {
        return { x + v2.x, y + v2.y };
    }

    Vector2& operator+=(const Vector2& v2)
    {
        x += v2.x;
        y += v2.y;

        return *this;
    }

    Vector2 operator-(const Vector2& v2) const
    {
        return { x - v2.x, y - v2.y };
    }

    Vector2& operator-=(const Vector2& v2)
    {
        x -= v2.x;
        y -= v2.y;

        return *this;
    }

    Vector2 operator*(float scalar) const
    {
        return { x * scalar, y * scalar };
    }

    Vector2& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;

        return *this;
    }

    Vector2 operator/(const float scalar) const
    {
        return { x / scalar, y / scalar };
    }

    Vector2& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;

        return *this;
    }

    float x;
    float y;



};