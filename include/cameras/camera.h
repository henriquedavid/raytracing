#ifndef CAM
#define CAM

#include <iostream>
#include <string>

using namespace std;

class Camera{

    public:
        int width;
        int height;
        string type;

        Camera();
        Camera( int w_, int h_ );
};

#endif