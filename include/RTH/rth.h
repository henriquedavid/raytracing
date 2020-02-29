#ifndef RTH_
#define RTH_

#include "../cameras/camera.h"
#include "../film/film.h"
#include "../backgrounds/background.h"

class RTH{

    public:
        Camera c;
        Film f;
        Background b;

        RTH();
        RTH(Camera c_, Film f_, Background b_);
        void configureCamera(Camera c_);
        void configureFilm(Film f_);
        void configureBackground(Background b_);
};

#include "rth.inl"

#endif