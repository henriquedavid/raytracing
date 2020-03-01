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
        vector<vec3> i_;
        for(int j = 0 ; j < y_res; j++){
            i_.push_back(vec3("0 0 0"));
        }
        img.push_back(i_);
    } 
}

inline void Film::write_image(){
    ofstream outfile(filename);
    outfile << "P3\n";
    outfile << x_res << " " << y_res << "\n";
    outfile << "255\n";
    for(int j = y_res-1; j >= 0; j--){
        for(int i = 0; i < x_res; i++){
            outfile << img[i][j].x << " " << img[i][j].y << " " << img[i][j].z << "\n";
        }

        outfile << "\n";
    }
}

inline int Film::width(){
    return x_res;
}

inline int Film::height(){
    return y_res;
}

inline void Film::add(int i, int j, vec3 cor){
    img[i][j] = cor;
}

inline vec3 Film::get(int i, int j){
    return img[i][j];
}