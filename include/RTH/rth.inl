#include "rth.h"

inline RTH::RTH(){}

inline RTH::RTH( Camera c_, Film f_){
    c = c_;
    f = f_;
}

inline void RTH::configureCamera(Camera c_){
    c = c_;
}

inline void RTH::configureFilm(Film f_){
    f = f_;
}