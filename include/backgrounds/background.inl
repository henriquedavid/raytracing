#include "background.h"

inline Background::Background() {}

inline Background::Background(string type_, vec3 color_, vec3 bl_, vec3 br_, vec3 tl_, vec3 tr_, vector<vector<vec3>> image_, int img_height, int img_width)
{
    type = type_;
    color = color_;
    bl = bl_;
    br = br_;
    tl = tl_;
    tr = tr_;
    image = image_;
    image_height = img_height;
    image_width = img_width;
}

inline vec3 Background::sample(float v1, float v2)
{
    if (!color.isBlack())
    {
        // Return the value on color
        return color;
    }
    else
    {
        // make interpolation
        vec3 interpolated = interpolate(v1, v2);
        return interpolated;
    }
}

inline vec3 Background::sample(float v1, float v2, Ray &ray_)
{

    float t{1.0};
    vec3f point = ray_(t);
    
    cout << "Ray = [o = ";
    ray_.o.print();
    cout << ", d = ";
    ray_.d.print();

    cout << "]" << endl;

    // Esses serão os indices de uma esfera
    float phi = calculate_phi(point.x, point.y);

    if (phi < 0)
    {
        phi += 2 * PI;
    }

    float tetha = calculate_tetha(point.x, point.y, point.z) ;

    // Converte para os indexes do vetor
    //      tam_img         ->          360
    //        x             ->          phi
    // => x = tam_img * phi/360

    //cout << "Phi = " << phi << "   |   Theta = " << tetha << endl;

    unsigned x = image_width * phi / 360;
    unsigned y = image_height * tetha / 180;

    //Envia a cor
    return vec3(to_string(image[x][y].x) + " " + to_string(image[x][y].y) + " " + to_string(image[x][y].z));
}

inline vec3 Background::interpolate(float x, float y)
{

    float calculo_x = RGBtoFloat(bl.x) * (1 - x) * (1 - y) + RGBtoFloat(br.x) * x * (1 - y) + RGBtoFloat(tl.x) * (1 - x) * y + RGBtoFloat(tr.x) * x * y;
    float calculo_y = RGBtoFloat(bl.y) * (1 - x) * (1 - y) + RGBtoFloat(br.y) * x * (1 - y) + RGBtoFloat(tl.y) * (1 - x) * y + RGBtoFloat(tr.y) * x * y;
    float calculo_z = RGBtoFloat(bl.z) * (1 - x) * (1 - y) + RGBtoFloat(br.z) * x * (1 - y) + RGBtoFloat(tl.z) * (1 - x) * y + RGBtoFloat(tr.z) * x * y;

    // O RGB é representado como sendo o x (R) , y (G) e z (B)
    std::string v = to_string(FloattoRGB(calculo_x)) + " " + to_string(FloattoRGB(calculo_y)) + " " + to_string(FloattoRGB(calculo_z));

    return vec3(v);
}

inline float Background::RGBtoFloat(int value)
{
    float value_ = float(value) / 255.0;
    return value_;
}

inline float Background::FloattoRGB(float value)
{
    float value_ = float(value) * 255.0;
    return value_;
}