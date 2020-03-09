#include <iostream>
#include "./include/parser/parser.cpp"

using namespace std;

int main( int argc, char** argv)
{

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

            // get background color.
            auto color = rth.b.sample(float(i) / float(w), float(j) / float(h));
            rth.f.add(i, j, color);
        }
    }

    rth.f.write_image();
}