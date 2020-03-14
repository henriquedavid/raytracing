#include <iostream>
#include "../vec3/vec3f.h"
#include <cmath>

vec3f normalize(const vec3f & vec){
    float magnitude = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
    
    std::cout << "Magnitude = " << magnitude << std::endl;

    
    float x = vec.x/sqrt(magnitude);
    float y = vec.x/sqrt(magnitude);
    float z = vec.x/sqrt(magnitude);

    return vec3f(x, y, z);
}