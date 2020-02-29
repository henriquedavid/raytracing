#ifndef FILM
#define FILM

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Film{
    public:
        vector<vector<int>> img;
        string type;
        int x_res;
        int y_res;
        string filename;
        string img_type;

        Film();
        Film(string type_ , int x_res_, int y_res_, string fn_, string itype_);
        
        // Fill all the image with 0;
        void fill();
};

#include "film.inl"

#endif