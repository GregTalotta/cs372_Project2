/*
 *
 */

#include "Shape.hpp"

//Circle definitions
Circle::Circle(double radius){
    _height = 2 * radius;
    _width = 2 * radius;
}
double Circle::getHeight() const { return _height; }
double Circle::getWidth() const { return _width; }
void Circle::generatePostScript(std::ostream &os) const {}

//Polygon definitions
Polygon::Polygon(int numSides, double sideLength){}
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