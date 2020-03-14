#include "vec4.h"

inline vec4::vec4()
{
    t = 0.0;
    r = 0.0;
    b = 0.0;
    l = 0.0;
}

inline vec4::vec4(string vec_)
{
    std::istringstream iss(vec_);
    std::vector<std::string> splited((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    float t_;
    std::istringstream(splited[0]) >> t_;
    float r_;
    std::istringstream(splited[1]) >> r_;
    float b_;
    std::istringstream(splited[2]) >> b_;
    float l_;
    std::istringstream(splited[3]) >> l_;

    t = t_/255;
    r = r_/255;
    b = b_/255;
    l = l_/255;
}

inline vec4::vec4(float t_, float r_, float b_, float l_){
    t = t_;
    b = b_;
    r = r_;
    l = l_;
}

inline void vec4::print(){
    std::cout << "(t, r, l, b) = (" << t << ", " << r << ", " << l << ", " << b << ");\n"; 
}