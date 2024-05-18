#ifndef _MATHHELPER_H
#define _MATHHELPER_H

#include <math.h>

#define PI 3.1415
#define DEG_TO_RAD PI / 180.0f

struct Vector2 {

    float x;
    float y;

    Vector2(float _x = 0.0f, float _y = 0.0f)
        : x(_x), y(_y) {}

    float MagnitudeSqr() {

        return x*x, y*y;
    }

    float Magnitude() {

        return (float)sqrt(x*x + y*y);
    }

    Vector2 Normalized() {

        float mag = Magnitude();

        return Vector2(x/mag, y/mag);
    }

    Vector2& operator += (const Vector2& rhs) {

        x += rhs.x;
        y += rhs.y;

        return *this;
    }

    Vector2& operator -= (const Vector2& rhs) {

        x -= rhs.x;
        y -= rhs.y;

        return *this;
    }
};

inline Vector2 operator + (const Vector2& lhs, const Vector2& rhs) {

    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator - (const Vector2& lhs, const Vector2& rhs) {

    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator * (const Vector2& lhs, const float& rhs) {

    return Vector2(lhs.x * rhs, lhs.y * rhs);
}


// This function allows engine to rotate point by specific angle based on reference position and angle
inline Vector2 RotateVector(const Vector2& vec, float angle) {

    float radAngle = (float)(angle*DEG_TO_RAD);

    return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)),
                   (float)(vec.x * sin(radAngle) - vec.y * cos(radAngle)));
}


// This function allows to calculate object's position based on time if start and end position is given
inline Vector2 Lerp(Vector2& start, Vector2& end, float time) {
    if(time <= 0.0f)
        return start;

    if(time >= 1.0f)
        return end;

    Vector2 dir = (end - start).Normalized();
    float magnitude = (end - start).Magnitude();

    return start + dir * magnitude * time;
}


const Vector2 vec2_zero = {0.0f, 0.0f};
const Vector2 vec2_one = {1.0f, 1.0f};
const Vector2 vec2_up = {0.0f, 1.0f};
const Vector2 vec2_right = {1.0f, 0.0f};
const Vector2 vec2_left = {-1.0f, 0.0f};

#endif