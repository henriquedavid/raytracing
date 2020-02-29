#include "background.h"

inline Background::Background(){}

inline Background::Background( string type_, vec3 color_ ){
    type = type_;
    color = color_;
    color.print();
}

inline vec3 Background::sample( float v1, float v2 ){
    if(!color.isBlack()){
        // Return the value on color
        return color; 
    } else{
        // Realiza a interpolação
        return color;
    }
}