#include "camera.h"

inline Camera::Camera(){
    type="orthographic";
}

inline Camera::Camera( string type_ ){
    type = type_;
}