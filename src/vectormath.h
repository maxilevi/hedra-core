/*
 * Created by Maximiliano Levi on 17/09/2019.
 */

#ifndef HEDRACORE_VECTOR_MATH_H
#define HEDRACORE_VECTOR_MATH_H

#include <cmath>

struct vec2 {
    float X;
    float Y;

    vec2() : X(0), Y(0){
    }

    vec2(float X, float Y) : X(X), Y(Y){
    }

    inline vec2 operator+(const vec2& p2){
        return vec2(X + p2.X, Y + p2.Y);
    }

    inline vec2 operator-(const vec2& p2){
        return vec2(X - p2.X, Y - p2.Y);
    }

    inline vec2 operator*(const float& scalar) {
        return vec2(X * scalar, Y * scalar);
    }

    inline vec2 operator/(const float& scalar) {
        return vec2(X / scalar, Y / scalar);
    }

    inline float lengthSquared(){
        return X*X + Y*Y;
    }
};

struct vec3 {
    float X;
    float Y;
    float Z;

    vec3() : X(0), Y(0), Z(0){
    }

    vec3(float X, float Y, float Z) : X(X), Y(Y), Z(Z){
    }

    inline vec3 operator+(const vec3& p2){
        return vec3(X + p2.X, Y + p2.Y, Z + p2.Z);
    }

    inline vec3 operator-(const vec3& p2){
        return vec3(X - p2.X, Y - p2.Y, Z - p2.Z);
    }

    inline vec3 operator*(const float& rhs) {
        return vec3(X * rhs, Y * rhs, Z * rhs);
    }

    inline vec3 operator/(const float& rhs) {
        return vec3(X / rhs, Y / rhs, Z / rhs);
    }

    inline float length(){
        return sqrt(X*X + Y*Y + Z*Z);
    }

    inline vec2 xz(){
        return vec2(X,Z);
    }
};

struct vec4 {
    float X;
    float Y;
    float Z;
    float W;

    vec4() : X(0), Y(0), Z(0), W(0){
    }

    vec4(vec3 vector, float w) : X(vector.X), Y(vector.Y), Z(vector.Z), W(w){
    }

    vec4(float X, float Y, float Z, float W) : X(X), Y(Y), Z(Z), W(W){
    }

    inline float length(){
        return sqrt(X*X + Y*Y + Z*Z + W*W);
    }

    inline vec3 xyz(){
        return vec3(X,Y,Z);
    }

    inline vec4 operator+(const vec4& p2){
        return vec4(X + p2.X, Y + p2.Y, Z + p2.Z, W + p2.W);
    }

    inline vec4 operator-(const vec4& p2){
        return vec4(X - p2.X, Y - p2.Y, Z - p2.Z, W - p2.W);
    }

    inline vec4 operator*(const float& rhs) {
        return vec4(X * rhs, Y * rhs, Z * rhs, W * rhs);
    }

    inline vec4 operator/(const float& rhs) {
        return vec4(X / rhs, Y / rhs, Z / rhs, W / rhs);
    }
};

#endif //HEDRACORE_VECTOR_MATH_H
