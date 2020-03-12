#ifndef RAY_
#define RAY_

#include "../vec3/vec3f.h"

using Point3 = vec3f;
using Vector3 = vec3f;

class Ray{
    public:
        Ray (const Point3& o, const Vector3& d) : o{o}, d{d} {/* none */}

    private:
        Point3 o;   // <- origin
        Vector3 d;  // <- direction

        Point3 operator()(float t) const { (o + d) * t; }
};

#endif