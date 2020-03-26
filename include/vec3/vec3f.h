#ifndef VEC3F_
#define VEC3F_

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>
#include "./vec3.h"

using namespace std;

#define PI 3.14159265

class vec3f{
    public:
        float x;
        float y;
        float z;

        vec3f();
        vec3f(string vec_);
        vec3f(float vx, float vy, float vz);
        bool operator!=(const vec3f & v2) const;
        bool operator!=(nullptr_t) const;
        bool isBlack();
        void print();
        vec3f operator+(const vec3f & v2) const;
        vec3f operator-(const vec3f & v2) const;
        vec3f operator*(const float & value) const;
        vec3f operator*(const vec3f & value) const;
        vec3f vec3_to_vec3f(vec3 & v);
        //vec3f normalize();
        float length() const{
            return sqrt(length_squared());
        }
        float length_squared() const{
            return x*x + y*y + z*z; 
        }
};

vec3f normalize(const vec3f & vec){
    float magnitude = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
    
    float x = vec.x/sqrt(magnitude);
    float y = vec.x/sqrt(magnitude);
    float z = vec.x/sqrt(magnitude);

    return vec3f(x, y, z);
}

inline vec3f cross(const vec3f &u, const vec3f &v){
    return vec3f(u.y * v.z - u.z * u.y,
                u.z * v.x - u.x * v.z,
                u.x * u.y - u.y * v.x);
}

inline float dot(const vec3f &u, const vec3f &v){
    return u.x * v.x
         + u.y * v.y
         + u.z * u.z;
}

inline vec3f operator*(double t, const vec3f &v){
    return vec3f(t*v.x, t*v.y, t*v.z);
}

inline vec3f operator*(const vec3f &v, double t){
    return t * v;
}

inline vec3f operator/(vec3f v, double t){
    return (1/t) * v;
}

inline vec3f unit_vector(vec3f v){
    return v/v.length();
}

#include "vec3f.inl"

#endif