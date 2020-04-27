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

    auto head = makeCircle(0.5);
    auto body = makeCircle(1.0);
    auto arm = makeRectangle(2.0, 0.2);
    auto booty = makeCircle(2.0);
    auto mid = makeHorizontalShape({ arm,body,arm });
    auto snowMan = makeVerticalShape({ booty,mid,head});

    fout << "%! \n288 288 translate\n";
    snowMan->generatePostScript(fout);
    movePosition(fout, 1, 2);
    vert->generatePostScript(fout);
    endPage(fout);
    fout.close();
    cout << "Shape drawn successfully :)\n";
    return 0;
}