#include <iostream>
#include "./include/parser/parser.cpp"
#include "./include/ray/ray.h"
#include "./include/support.cpp"

using namespace std;

int main( int argc, char** argv)
{
    {
        auto a_ = getPNGImage("play.png");
        return 0;
    }
    
    if(argc != 2){
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
            
            Ray r1 = rth.c.generate_ray(float(i)/float(j), float(j)/float(h), rth.f);
            Ray r2 = rth.c.generate_ray(i, j, rth.f);

            std::cout << "Ray 1: " << r1 << ", Ray 2: " << r2 << std::endl;

            std::cout << "Point at t=2, ray(2) = ";
            r1(2.f).print();
            std::cout << "\n\n\n" << std::endl;

            // Print out the two array

            // get background color.
            auto color = rth.b.sample(float(i) / float(w), float(j) / float(h));
            rth.f.add(i, j, color);
        }
    }

    cout << "Creating image\n";
    rth.f.write_image();
}