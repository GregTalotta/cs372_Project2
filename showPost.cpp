#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using std::cout;
using std::cos;
using std::sin;
#include "Shape.hpp"

void start();
void end();
int main()
{
    auto mycir = makeCircle(2.0);
    auto mySquare = makeSquare(2.0);
    auto mypoly = makePolygon(5, 1);
    auto myRec = makeRectangle(2.0, 5.0);
    auto myTri = makeTriangle(3.0);
    auto mySpace = makeSpacer(2.0, 3.0);
    auto myScale = makeScaledShape(mypoly, 2, 2);
    auto myLayered = makeLayeredShape({mycir, myScale, mySquare, mypoly, myRec, myTri, mySpace});
    start();
    myLayered->generatePostScript(cout);
    end();
    
    return 0;
}

void start(){
    cout << "%! \n288 288 translate\n";
    return;
}

void end(){
    cout << "\nshowpage \n\n\n";
    return;
}