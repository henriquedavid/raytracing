#include "camera.h"

inline Camera::Camera()
{
    type = "orthographic";
}

inline Camera::Camera(string type_)
{
    type = type_;
}

/**
 * Mapping Pixels to Screen Space
 * 
 * pos1  - corresponds to the left/bottom informed about the specification
 * pos2  - corresponds to the right/top informed about the specification
 * value - value on the image on the image space we want to find correspondent to the return value on screen value
 * n     - the horizontal and vertical number of pixels of the image we want to create
*/
inline float Camera::mappingPixelsToScreenSpace(float pos1, float pos2, float value, float n)
{
    return pos1 + (pos2 - pos1) * (value + 0.5) / n;
}

inline Ray Camera::generate_ray(float x, float y, Film &f)
{

    float u_ = mappingPixelsToScreenSpace(screen_window.l, screen_window.r, x, f.x_res);
    float v_ = mappingPixelsToScreenSpace(screen_window.b, screen_window.t, y, f.y_res);

    if (type == "orthografic")
    {
        // Note that this representation is the same ass e + x*u + y*v for this project
        vec3f origin(e + (u * u_) + (v * v_));
        Ray r{origin, w};
        return r;
    }
    else
    {
        // Note that this representation is the same ass e + x*u + y*v for this project
        float fd = 1;
        vec3f direc((w * fd) + (u * u_) + (v * v_));
        Ray r{e, direc};
        return r;
    }
}

inline Ray PerspectiveCamera::generate_ray(float x, float y, Film &f)
{
    float u_ = mappingPixelsToScreenSpace(screen_window.l, screen_window.r, x, f.x_res);
    float v_ = mappingPixelsToScreenSpace(screen_window.b, screen_window.t, y, f.y_res);

    cout << "CAMERA PERSPECT" << endl;

    float fd = 1;
    vec3f direc((w * fd) + (u * u_) + (v * v_));
    Ray r{e, direc};
    return r;
}