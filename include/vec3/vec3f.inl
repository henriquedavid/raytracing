#include "vec3f.h"

inline vec3f::vec3f()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

inline vec3f::vec3f(string vec_)
{
    std::istringstream iss(vec_);
    std::vector<std::string> splited((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    float x_;
    std::istringstream(splited[0]) >> x_;
    float y_;
    std::istringstream(splited[1]) >> y_;
    float z_;
    std::istringstream(splited[2]) >> z_;

    x = x_/255;
    y = y_/255;
    z = z_/255;
}

inline bool vec3f::operator!=(const vec3f &v2) const
{
    if ((x != v2.x) && (y != v2.y) && (z != v2.z))
    {
        return true;
    }
    else
    {
        return false;
    }
}

inline bool vec3f::isBlack(){
    if(x == 0.0 && y == 0.0 && z == 0.0)
        return true;
    else
    {
        return false;
    }
    
}

inline void vec3f::print(){
    std::cout << "COR = (" << x << ", " << y << ", " << z << ");\n"; 
}

inline vec3f operator+(const vec3f & v2){
    float v_x = x + v2.x;
    float v_y = y + v2.y;
    float v_z = z + v2.z;

    return vec3(v_x, v_y, v_z);
}

inline vec3f operator*(const float & value){
    float v_x = x * value;
    float v_y = y * value;
    float v_z = z * value;

    return vec3(v_x, v_y, v_z);
}

inline vec3f vec3_to_vec3f(vec3 & v){
    return vec3f((v.x/255), (v.y/255), (v.z/255));
}

/*
 * The ideia here is to normalize the vector using
 * u = v/||v|| <- normalize formula
 */
inline vec3f normalize(const vec3f & v){
    float sqr_x = v.x * v.x;
    float sqr_y = v.y * v.y;
    float sqr_z = v.z * v.z;

    float root = sqrt( sqr_x + sqr_y + sqr_z);

    float r_x = v.x / root;
    float r_y = v.y / root;
    float r_z = v.z / root;

    return vec3f(r_x, r_y, r_z);
}