/*
 *
 */

#include "Shape.hpp"
#include <cmath>
using std::cos;
using std::sin;
const double PI = 3.14159;

//Circle definitions
Circle::Circle(double radius){
    _height = 2 * radius;
    _width = 2 * radius;
}
double Circle::getHeight() const { return _height; }
double Circle::getWidth() const { return _width; }
void Circle::generatePostScript(std::ostream &os) const {}

//Polygon definitions
Polygon::Polygon(int numSides, double sideLength){
    if (numSides % 2 != 0){
        _height = sideLength*(1+cos(PI/numSides))/(2*sin(PI/numSides));
        _width = sideLength*sin(PI*(numSides-1)/2*numSides)/(sin(PI/numSides));
    }
    else if(numSides % 4 == 0){
        _height = sideLength*(cos(PI/numSides))/(sin(PI/numSides));
        _width = sideLength*cos(PI/numSides)/(sin(PI/numSides));
    }
    else {
        _height = sideLength*(cos(PI/numSides))/(sin(PI/numSides));
        _width = sideLength/(sin(PI/numSides));
    }
}
double Polygon::getHeight() const { return _height; }
double Polygon::getWidth() const { return _width; }
void Polygon::generatePostScript(std::ostream &os) const {}

//Rectangle definitions
Rectangle::Rectangle(double width, double height) {
    _height = height;
    _width = width;
}
double Rectangle::getHeight() const { return _height; }
double Rectangle::getWidth() const { return _width; }
void Rectangle::generatePostScript(std::ostream &os) const {}

//Spacer definitions
Spacer::Spacer(double width, double height){
    _height = height;
    _width = width;}
double Spacer::getHeight() const { return _height; }
double Spacer::getWidth() const { return _width; }
void Spacer::generatePostScript(std::ostream &os) const {}

//Square definitions
Square::Square(double sideLength){
    _height = sideLength;
    _width = sideLength;}
double Square::getHeight() const { return _height; }
double Square::getWidth() const { return _width; }
void Square::generatePostScript(std::ostream &os) const {}

//Triangle definitions
Triangle::Triangle(double sideLength){}
double Triangle::getHeight() const { return _height; }
double Triangle::getWidth() const { return _width; }
void Triangle::generatePostScript(std::ostream &os) const {}

//Rotated definitions
Rotated::Rotated(std::shared_ptr<Shape> & shape, Angle rotationAngle) {}
double Rotated::getHeight() const { return _height; }
double Rotated::getWidth() const { return _width; }
void Rotated::generatePostScript(std::ostream &os) const {}

//Scaled definitions
Scaled::Scaled(std::shared_ptr<Shape> & shape, double fx, double fy){}
double Scaled::getHeight() const { return _height; }
double Scaled::getWidth() const { return _width; }
void Scaled::generatePostScript(std::ostream &os) const {}

//Layered definitions
Layered::Layered(std::initializer_list<std::shared_ptr<Shape>> shapes){}
double Layered::getHeight() const { return _height; }
double Layered::getWidth() const { return _width; }
void Layered::generatePostScript(std::ostream &os) const {}

//Vertical definitions
Vertical::Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes){}
double Vertical::getHeight() const { return _height; }
double Vertical::getWidth() const { return _width; }
void Vertical::generatePostScript(std::ostream &os) const {}

//Horizontal definitions
Horizontal::Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes){}
double Horizontal::getHeight() const { return _height; }
double Horizontal::getWidth() const { return _width; }
void Horizontal::generatePostScript(std::ostream &os) const {}

//Special definitions
Special::Special(/*not sure what is required*/){}
double Special::getHeight() const { return _height; }
double Special::getWidth() const { return _width; }
void Special::generatePostScript(std::ostream &os) const {}

/**********************makeShape functions**********************/
std::shared_ptr<Shape> makeCircle(double radius) {return std::make_shared<Circle>(Circle(radius));}
std::shared_ptr<Shape> makePolygon(int numSides, double length) {return std::make_shared<Polygon>(Polygon(numSides, length));}
std::shared_ptr<Shape> makeRectangle(double width, double height) {return std::make_shared<Rectangle>(Rectangle(width, height));}
std::shared_ptr<Shape> makeSpacer(double width, double height) {return std::make_shared<Spacer>(Spacer(width, height));}
std::shared_ptr<Shape> makeSquare(double length) {return std::make_shared<Polygon>(Polygon(4, length));}
std::shared_ptr<Shape> makeTriangle(double length) {return std::make_shared<Polygon>(Polygon(3, length));}
std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> & s, Angle a) {return std::make_shared<Rotated>(Rotated(s, a));}
std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> & s, double sx, double sy) {return std::make_shared<Scaled>(Scaled(s, sx, sy));}
std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> i) {return std::make_shared<Layered>(Layered(i));}
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> i) {return std::make_shared<Vertical>(Vertical(i));}
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i) {return std::make_shared<Horizontal>(Horizontal(i));}