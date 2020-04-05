#ifndef CAM
#define CAM

#include <iostream>
#include <string>
#include "../vec3/vec3f.h"
#include "../ray/ray.h"
#include "../film/film.h"
#include "../vec3/vec4.h"

using namespace std;

class Camera{

    public:
        string type;
        vec3f u;
        vec3f v;
        vec3f w;
        vec3f e;
        vec4 screen_window;

        Ray generate_ray(float x, float y, Film & f);

        Camera();
        Camera( string type_ );
        float mappingPixelsToScreenSpace(float pos1, float pos2, float value, float n);
};

class PerspectiveCamera : public Camera{
    public:

        float fovy;

        PerspectiveCamera(){}
        PerspectiveCamera(float fovy_) : fovy(fovy_){}
        Ray generate_ray(float x, float y, Film & f);

};

class OrthographicCamera : public Camera{
    public:

        OrthographicCamera(){}
};

#include "camera.inl"

#endif