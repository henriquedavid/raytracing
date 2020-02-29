#ifndef FILM
#define FILM

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../vec3/vec3.h"

using namespace std;

class Film{
    public:
        vector<vector<vec3>> img;
        string type;
        int x_res;
        int y_res;
        string filename;
        string img_type;

        Film();
        Film(string type_ , int x_res_, int y_res_, string fn_, string itype_);
        
        // Fill all the image with 0;
        void fill();

        void write_image();
        int height();
        int width();
        void add(int i, int j, vec3 cor);
};

#include "film.inl"

#endif