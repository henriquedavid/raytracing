#ifndef BG
#define BG

#include <iostream>
#include <string>

#include "../vec3/vec3.h"

using namespace std;

class Background{
    public:
        string type;
        string mapping;
        string filename;
        vec3 color;
        vec3 bl;
        vec3 br;
        vec3 tl;
        vec3 tr;


        Background();
        Background(string type, vec3 color);
        vec3 sample(float v1, float v2);
};

#include "background.inl"

#endif