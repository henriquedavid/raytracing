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
        vec3f normalize();
        
};

#include "vec3f.inl"

#endif