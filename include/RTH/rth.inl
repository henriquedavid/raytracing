#include "rth.h"

inline RTH::RTH(){}

inline RTH::RTH( Camera c_, Film f_, Background b_){
    c = c_;
    f = f_;
    b = b_;
}

inline void RTH::configureCamera(Camera c_){
    c = c_;
}

inline void RTH::configureFilm(Film f_){
    f = f_;
}

inline void RTH::configureBackground(Background b_){
    b = b_;
}