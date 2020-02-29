#ifndef BG
#define BG

#include <iostream>
#include <string>

using namespace std;

class Background{
    public:
        string type;
        string color;

        Background();
        Background(string type, string color);
};

#include "background.inl"

#endif