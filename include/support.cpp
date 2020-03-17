#include <iostream>
#include <string>
#include <vector>
#include "../lib/lodepng/lodepng.h"
#include "../lib/lodepng/lodepng.cpp"

using namespace std;

vector<unsigned char> getPNGImage( const string filename ){
    vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    unsigned error = lodepng::decode(image, width, height, filename);

    if(error) cout << "decode error " <<  error << endl;

    int i = 0;

    ofstream outfile("arquivo.ppm");
    outfile << "P3\n";
    outfile << width << " " << height << "\n";
    outfile << "255\n";

    cout << "S = " << image.size() << endl;

    for(unsigned char o_ : image){
        i++;
        if(i < 3)
            outfile << (int) o_ << " ";
        if(i == 3){
            outfile << (int) o_ << "\n";
        }
        if(i == 4)
            i = 0;
    }
    //cout << "DONE\n";

    return image;
}