#ifndef CAM
#define CAM

#include <iostream>
#include <string>

using namespace std;

class Camera{

    public:
        string type;

        Camera();
        Camera( string type_ );
};

#include "camera.inl"

#endif