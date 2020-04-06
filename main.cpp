//main.cpp

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
using std::cout;
using std::cos;
using std::sin;
#include "Shape.hpp"

int main()
{
    std::ofstream fout("snowman.ps");

    auto snowMan = makeSpecial(7.0);
    auto snowmidget = makeSpecial(0.75);
    auto rotate = makeRotatedShape(snowmidget, Angle::R180);
    auto vert = makeVerticalShape({snowmidget,rotate});
    newPage(fout, 1, 1);
    snowMan->generatePostScript(fout);
    movePosition(fout, 1, 2);
    vert->generatePostScript(fout);
    endPage(fout);
    fout.close();
    cout << "Shape drawn successfully :)\n";
    return 0;
}