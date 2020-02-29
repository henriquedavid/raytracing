#include "film.h"

inline Film::Film(){
    type="image";
    x_res = 500;
    y_res = 500;
    filename="out.ppm";
    img_type = "ppm";
    fill();
}

inline Film::Film(string type_ , int x_res_, int y_res_, string fn_, string itype_){
    type = type_;
    x_res = x_res_;
    y_res = y_res_;
    filename = fn_;
    img_type = itype_;
    fill();
}

inline void Film::fill(){
    for(int i = 0 ; i < x_res; i++){
        vector<int> i_;
        for(int j = 0 ; j < y_res; j++){
            i_.push_back(0);
        }
        img.push_back(i_);
    } 
}

