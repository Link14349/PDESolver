#ifndef VALUE_H
#define VALUE_H

#include <cmath>
#include <string>

class Value
{
public:
    Value();
};

class Number : public Value {
public:
    Number(float v = 0) : x(v) { }
    operator float() {
        return x;
    }
    Number operator+(const Number& v) const {
        return x + v.x;
    }
    Number operator-(const Number& v) const {
        return x - v.x;
    }
    Number operator*(float k) {
        return x * k;
    }
    Number& operator+=(const Number& v) {
        x += v.x;
        return *this;
    }
    Number& operator-=(const Number& v) {
        x -= v.x;
        return *this;
    }
    Number& operator*=(float k) {
        x *= k;
        return *this;
    }
    float x;
};
class Vec2 :public Value {
public:
    Vec2(float a = 0, float b = 0) : x(a), y(b) { }
    Vec2 operator+(const Vec2& v) const {
        return Vec2(x + v.x, y + v.y);
    }
    Vec2 operator-(const Vec2& v) const {
        return Vec2(x - v.x, y - v.y);
    }
    Vec2 operator*(float k) {
        return Vec2(x * k, y * k);
    }
    Vec2& operator+=(const Vec2& v) {
        x += v.x, y += v.y;
        return *this;
    }
    Vec2& operator-=(const Vec2& v) {
        x -= v.x, y -= v.y;
        return *this;
    }
    Vec2& operator*=(float k) {
        x *= k, y *= k;
        return *this;
    }
    float dot(const Vec2& v) const {
        return x * v.x + y * v.y;
    }
    float mod2() {
        return x * x + y * y;
    }
    float mod() {
        return sqrt(x * x + y * y);
    }
    operator std::string() {
        return "<" + std::to_string(x) + ", " + std::to_string(y) + ">";
    }
    float x, y;
};
class VVec2 : public Vec2 {
public:
    VVec2(float a = 0, float b = 0) : Vec2(a, b) { }
};

#endif // VALUE_H
