#ifndef CAM
#define CAM

#include <iostream>
#include <string>
#include "../ray/ray.h"

using namespace std;

class Camera{

    public:
        string type;
        Ray generate_ray(int x, int y);
        Ray generate_ray(float x, float y);

        Camera();
        Camera( string type_ );
};

class PerspectiveCamera : public Camera{

};

class OrthographicCamera : public Camera{

};

#include "camera.inl"

#endif