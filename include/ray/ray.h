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

        Point3 operator()(float t) const { (o + d) * t; }
        friend ostream& operator<<(ostream& os, const Ray& r);
};

ostream& operator<<(ostream& os, const Ray& r){
            os << "(" << r.o.x << ", " << r.o.y << ", " << r.o.z << ") -> (" << r.d.x << ", " << r.d.y << ", " << r.d.z << ")";
            return os;

        }

#endif