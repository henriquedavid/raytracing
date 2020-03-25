#ifndef BG
#define BG

#include <iostream>
#include <string>
#include <vector>

#include "../vec3/vec3.h"
//#include "../support.cpp"

using namespace std;

class Background{
    public:
        string type;
        string mapping;
        string filename;
        vector<vector<vec3>> image;
        int image_width;
        int image_height;
        vec3 color;
        vec3 bl;
        vec3 br;
        vec3 tl;
        vec3 tr;


        Background();
        Background(string type, vec3 color, vec3 bl_, vec3 br_, vec3 tl_, vec3 tr_, vector<vector<vec3>> image, int img_height, int img_width);
        vec3 sample(float v1, float v2);
        vec3 sample(float v1, float v2, Ray & ray_);
        vec3 interpolate(float v1, float v2);
        float RGBtoFloat(int value);
        float FloattoRGB(float value);

};

#include "background.inl"

#endif