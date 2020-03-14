#ifndef VEC4_
#define VEC4_

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>
#include "./vec4.h"

using namespace std;

class vec4{
    public:
        float t;
        float b;
        float l;
        float r;

        vec4();
        vec4(string vec_);
        vec4(float t_, float r_, float b_, float l_);
        void print();
        
};

#include "vec4.inl"

#endif