#include "background.h"

inline Background::Background(){}

inline Background::Background( string type_, vec3 color_ , vec3 bl_, vec3 br_, vec3 tl_, vec3 tr_){
    type = type_;
    color = color_;
    bl = bl_;
    br = br_;
    tl = tl_;
    tr = tr_;
}

inline vec3 Background::sample( float v1, float v2 , bool cor = true){
    if(cor){
        // Return the value on color
        return color; 
    } else{
        // make interpolation
        vec3 interpolated = interpolate(v1, v2);
        return interpolated;
    }
}

inline vec3 Background::interpolate(float x, float y){
    
    float calculo_x = RGBtoFloat(bl.x)*(1-x)*(1-y) + RGBtoFloat(br.x)*x*(1-y) + RGBtoFloat(tl.x)*(1-x)*y + RGBtoFloat(tr.x)*x*y;
    float calculo_y = RGBtoFloat(bl.y)*(1-x)*(1-y) + RGBtoFloat(br.y)*x*(1-y) + RGBtoFloat(tl.y)*(1-x)*y + RGBtoFloat(tr.y)*x*y;
    float calculo_z = RGBtoFloat(bl.z)*(1-x)*(1-y) + RGBtoFloat(br.z)*x*(1-y) + RGBtoFloat(tl.z)*(1-x)*y + RGBtoFloat(tr.z)*x*y;

    std::string v = to_string(FloattoRGB(calculo_x)) + " " + to_string(FloattoRGB(calculo_y)) + " " + to_string(FloattoRGB(calculo_z));

    return vec3(v);
}

inline float Background::RGBtoFloat(int value){
    float value_ = float(value)/255.0;
    return value_;
}

inline float Background::FloattoRGB(float value){
    float value_ = float(value)*255.0;
    return value_;
}