#include "vec3.h"

inline vec3::vec3()
{
    x = 0;
    y = 0;
    z = 0;
}

inline vec3::vec3(string vec_)
{
    std::istringstream iss(vec_);
    std::vector<std::string> splited((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    int x_;
    std::istringstream(splited[0]) >> x_;
    int y_;
    std::istringstream(splited[1]) >> y_;
    int z_;
    std::istringstream(splited[2]) >> z_;

    x = x_;
    y = y_;
    z = z_;
}

inline bool vec3::operator!=(const vec3 &v2) const
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

inline bool vec3::isBlack(){
    if(x == 0 && y == 0 && z == 0)
        return true;
    else
    {
        return false;
    }
    
}

inline void vec3::print(){
    std::cout << "COR = (" << x << ", " << y << ", " << z << ");\n"; 
}
