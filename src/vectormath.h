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

    inline vec2 operator+(vec2 lhs, vec2 const& rhs ){
        return vec2(lhs.X + rhs.X, lhs.Y + rhs.Y);
    }

    inline vec2 operator-(vec2 lhs, vec2 const& rhs){
        return vec2(lhs.X - rhs.X, lhs.Y - rhs.Y);
    }

    inline vec2 operator*(vec2 lhs, float rhs) {
        return vec2(lhs.X * rhs, lhs.Y * rhs);
    }

    inline vec2 operator/(vec2 lhs, float rhs) {
        return vec2(lhs.X / rhs, lhs.Y / rhs);
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

    inline vec3 operator+(vec3 lhs, vec3 rhs ){
        return vec3(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
    }

    inline vec3 operator-(vec3 lhs, vec3 rhs){
        return vec3(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z);
    }

    inline vec3 operator*(vec3 lhs, float rhs) {
        return vec3(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs);
    }

    inline vec3 operator/(vec3 lhs, float rhs) {
        return vec3(lhs.X / rhs, lhs.Y / rhs, lhs.Z / rhs);
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

    inline vec4 operator+(vec4 lhs, vec4 rhs ){
        return vec4(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z, lhs.W + rhs.W);
    }

    inline vec4 operator-(vec4 lhs, vec4 rhs){
        return vec4(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z, lhs.W - rhs.W);
    }

    inline vec4 operator*(vec4 lhs, float rhs) {
        return vec4(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs, lhs.W * rhs);
    }

    inline vec4 operator/(vec4 lhs, float rhs) {
        return vec4(lhs.X / rhs, lhs.Y / rhs, lhs.Z / rhs, lhs.W / rhs);
    }
};

#endif //HEDRACORE_VECTOR_MATH_H
