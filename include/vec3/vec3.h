#ifndef VEC3_
#define VEC3_

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class vec3{
    public:
        int x;
        int y;
        int z;

        vec3();
        vec3(string vec_);
        bool operator!=(const vec3 & v2) const;
        bool operator!=(nullptr_t) const;
        bool isBlack();
        void print();
};

#include "vec3.inl"

#endif