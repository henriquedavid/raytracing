#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "../lib/lodepng/lodepng.h"
#include "../lib/lodepng/lodepng.cpp"

using namespace std;

tuple<vector<unsigned char>, int, int> getPNGImage( const string filename ){
    vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    unsigned error = lodepng::decode(image, width, height, filename);

    if(error) cout << "decode error " <<  error << endl;

    return make_tuple(image, width, height);
}

