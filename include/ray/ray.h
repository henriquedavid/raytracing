
#include "../vec3/vec3.h"

using Point3 = vec3;
using Vector3 = vec3;

class Ray{
    public:
        Ray (const Point3& o, const Vector3& d) : o{o}, d{d} {/* none */}

    private:
        Point3 o;   // <- origin
        Vector3 d;  // <- direction

        //Point3 operator()(float t) const { o + d * t; }
};