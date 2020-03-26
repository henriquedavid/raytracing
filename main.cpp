#include <iostream>
#include "./include/parser/parser.cpp"
#include "./include/ray/ray.h"

using namespace std;

int main( int argc, char** argv)
{
    
    /*if(argc != 2){
        cout << "It's necessary inform the input file.\nEX: ./main < inputfile >.xml\n";
        return 0;
    }

    cout << "Input file: " << argv[1] << endl;

    // RTH
    RTH rth;
    parse(rth, argv[1]);

    // Retrive the image dimensions in pixels.    
    auto w = rth.f.width();
    auto h = rth.f.height();

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            // Generate ray

            // cout <<  float(i)/float(w) << " e " << float(j)/float(h) << endl;
            
            Ray r1 = rth.c.generate_ray(float(i)/float(w), float(j)/float(h), rth.f);

            cout << "Pixel : [" << i << " , " << j << "], ";
            
            // get background color.
            auto color = rth.b.sample(float(i) / float(w), float(j) / float(h),  r1);
            rth.f.add(i, j, color);
        }
    }

    cout << "Creating image\n";
    rth.f.write_image();*/
}