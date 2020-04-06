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
    start();
    mycir->generatePostScript(cout);
    end();
    start();
    mySquare->generatePostScript(cout);
    end();
    start();
    mypoly->generatePostScript(cout);
    end();
    start();
    myRec->generatePostScript(cout);
    end();
    start();
    myTri->generatePostScript(cout);
    end();
    start();
    mySpace->generatePostScript(cout);
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