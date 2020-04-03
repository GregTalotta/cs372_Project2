/*
 *
 */

#include "Shape.hpp"

//Circle definitions
Circle::Circle(double radius){}
double Circle::getHeight() const { return 0; }
double Circle::getWidth() const { return 0; }
void Circle::generatePostScript(std::ostream &os) const {}

//Polygon definitions
Polygon::Polygon(int numSides, double sideLength){}
double Polygon::getHeight() const { return 0; }
double Polygon::getWidth() const {return 0;}
void Polygon::generatePostScript(std::ostream &os) const {}

//Rectangle definitions
Rectangle::Rectangle(double width, double height) {}
double Rectangle::getHeight() const {return 0;}
double Rectangle::getWidth() const {return 0;}
void Rectangle::generatePostScript(std::ostream &os) const {}

//Spacer definitions
Spacer::Spacer(double width, double height){}
double Spacer::getHeight() const {return 0;}
double Spacer::getWidth() const {return 0;}
void Spacer::generatePostScript(std::ostream &os) const {}

//Square definitions
Square::Square(double sideLength){}
double Square::getHeight() const {return 0;}
double Square::getWidth() const {return 0;}
void Square::generatePostScript(std::ostream &os) const {}

//Triangle definitions
Triangle::Triangle(double sideLength){}
double Triangle::getHeight() const {return 0;}
double Triangle::getWidth() const {return 0;}
void Triangle::generatePostScript(std::ostream &os) const {}

//Rotated definitions
Rotated::Rotated(std::shared_ptr<Shape> & shape, Angle rotationAngle) {}
double Rotated::getHeight() const {return 0;}
double Rotated::getWidth() const {return 0;}
void Rotated::generatePostScript(std::ostream &os) const {}

//Scaled definitions
Scaled::Scaled(std::shared_ptr<Shape> & shape, double fx, double fy){}
double Scaled::getHeight() const {return 0;}
double Scaled::getWidth() const {return 0;}
void Scaled::generatePostScript(std::ostream &os) const {}

//Layered definitions
Layered::Layered(std::initializer_list<std::shared_ptr<Shape>> shapes){}
double Layered::getHeight() const {return 0;}
double Layered::getWidth() const {return 0;}
void Layered::generatePostScript(std::ostream &os) const {}

//Vertical definitions
Vertical::Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes){}
double Vertical::getHeight() const {return 0;}
double Vertical::getWidth() const {return 0;}
void Vertical::generatePostScript(std::ostream &os) const {}

//Horizontal definitions
Horizontal::Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes){}
double Horizontal::getHeight() const {return 0;}
double Horizontal::getWidth() const {return 0;}
void Horizontal::generatePostScript(std::ostream &os) const {}

//Special definitions
Special::Special(/*not sure what is required*/){}
double Special::getHeight() const { return 0; }
double Special::getWidth() const { return 0; }
void Special::generatePostScript(std::ostream &os) const {}