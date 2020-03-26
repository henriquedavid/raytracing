#ifndef RAY_
#define RAY_

#include "../vec3/vec3f.h"
#include <iostream>
#include <string>

using Point3 = vec3f;
using Vector3 = vec3f;

class Ray{
    public:
        Ray (const Point3& o, const Vector3& d) : o{o}, d{d} {/* none */}

        Point3 o;   // <- origin
        Vector3 d;  // <- direction

        Point3 operator()(float t) const {
            return o + d * t;
        }
        friend ostream& operator<<(ostream& os, const Ray& r);
};

float calculate_r(float x, float y, float z){
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

float calculate_phi(float x, float y){
    return std::atan2(y,x);
}

float calculate_tetha(float x, float y, float z){
    return cos(z/sqrt(x*x + y*y + z*z));
    //return atan2(sqrt(x*x + y*y),z);
}

ostream& operator<<(ostream& os, const Ray& r){
            os << "(" << r.o.x << ", " << r.o.y << ", " << r.o.z << ") -> (" << r.d.x << ", " << r.d.y << ", " << r.d.z << ")";
            return os;

        }

#endif