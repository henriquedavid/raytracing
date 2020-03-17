#include <iostream>
#include <string>
#include <vector>
#include "../lib/lodepng/lodepng.h"

using namespace std;

vector<unsigned char> getPNGImage( const * char filename ){
    vector<unsigned char> png;
    vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    unsigned error = lodepng::load_file(png, filename);
    if(!error) error =  lodepng::decode(image, width, height, png);

    if(error) cout << "decode error " <<  error << endl;

    return image;
}