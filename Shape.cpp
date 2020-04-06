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
    _radius = radius;
    _height = 2 * radius;
    _width = 2 * radius;
}
double Circle::getHeight() const { return _height; }
double Circle::getWidth() const { return _width; }
void Circle::generatePostScript(std::ostream &os) const {
    os << "\nnewpath \n" << 72 * _radius << " " << 72 * _radius << " " <<  72 * _radius <<" 0 360 arc closepath \nstroke";
}

//Polygon definitions
Polygon::Polygon(int numSides, double sideLength){
    if (numSides % 2 != 0){
        _height = sideLength*(1+cos(PI/numSides))/(2*sin(PI/numSides));  
        _width = (sideLength*sin(PI*(numSides-1)/(2*numSides)))/sin(PI/numSides);
    }
    else if(numSides % 4 == 0){
        _height = (sideLength*(cos(PI/numSides)))/sin(PI/numSides); 
        _width = ((sideLength*cos(PI/numSides))/sin(PI/numSides));
    }
    else {
        _height = (sideLength*cos(PI/numSides)/sin(PI/numSides)); 
        _width = (sideLength/sin(PI/numSides));
    }
    _numSides = numSides;
    _sideLength = sideLength;
}
double Polygon::getHeight() const { return _height; }
double Polygon::getWidth() const { return _width; }
void Polygon::generatePostScript(std::ostream &os) const {
    os << "\nnewpath\n";
    os << ((int) (72*((_width - _sideLength)/2))) <<" 0 moveto \n";
    for(int i = 0; i < _numSides; ++i )
    {
        os <<  72*_sideLength << " 0 rlineto\n"
            << (360 / _numSides) << " rotate\n";
    }
    os << "stroke";
}

//Rectangle definitions
Rectangle::Rectangle(double width, double height) {
    _height = height;
    _width = width;
}
double Rectangle::getHeight() const { return _height; }
double Rectangle::getWidth() const { return _width; }
void Rectangle::generatePostScript(std::ostream &os) const {
    os << "\nnewpath \n0 0 moveto \n" << 72*_width << " 0 lineto\n"  
        << 72*_width << " " << 72*_height << " lineto \n" 
        << "0 " << 72*_height << " lineto \nclosepath \nstroke";
}

//Spacer definitions
Spacer::Spacer(double width, double height){
    _height = height;
    _width = width;}
double Spacer::getHeight() const { return _height; }
double Spacer::getWidth() const { return _width; }
void Spacer::generatePostScript(std::ostream &os) const {
    os << "\nnewpath \n0 0 moveto \n" << 72*_width << " 0 lineto\n"  
        << 72*_width << " " << 72*_height << " lineto \n" 
        << "0 " << 72*_height << " lineto \nclosepath";
}

//Rotated definitions
Rotated::Rotated(std::shared_ptr<Shape> & shape, Angle rotationAngle) {
    if (rotationAngle == Angle::R90 || rotationAngle == Angle::R270){
        _height = shape->getWidth();
        _width = shape->getHeight();
    }
    else{
        _height = shape->getHeight();
        _width = shape->getWidth();
    }
    _shape = shape;
    _rotationAngle = rotationAngle;
}
double Rotated::getHeight() const { return _height; }
double Rotated::getWidth() const { return _width; }
void Rotated::generatePostScript(std::ostream &os) const {
    if(_rotationAngle == Angle::R90)
    {
        os << "90 rotate \n";
    }
    else if(_rotationAngle == Angle::R180)
    {
        os << "180 rotate \n";
    }
    else
    {
        os << "270 rotate \n";
    }
    _shape->generatePostScript(os);
}

//Scaled definitions
Scaled::Scaled(std::shared_ptr<Shape> & shape, double fx, double fy){
    _height = shape->getHeight() * fy;
    _width = shape->getWidth() * fx;
    _shape = shape;
    _fx = fx;
    _fy = fy;
}
double Scaled::getHeight() const { return _height; }
double Scaled::getWidth() const { return _width; }
void Scaled::generatePostScript(std::ostream &os) const {
    os <<"\n"<< _fx << " " << _fy << " scale\n";
    _shape->generatePostScript(os);
    os <<"\n"<< 1/_fx << " " << 1/_fy << " scale\n";
}

//Layered definitions
Layered::Layered(std::initializer_list<std::shared_ptr<Shape>> shapes){
    double maxHeight = 0.0;
    double maxWidth = 0.0;
    for (auto &v : shapes){
        if (maxWidth < v->getWidth()) 
        { 
            maxWidth = v->getWidth();
        }
        if (maxHeight < v->getHeight()) 
        { 
            maxHeight = v->getHeight(); 
        }
    }
    for (auto v : shapes){
        _shapes.push_back(v);
    }
    _height = maxHeight;
    _width = maxWidth;
}
double Layered::getHeight() const { return _height; }
double Layered::getWidth() const { return _width; }
void Layered::generatePostScript(std::ostream &os) const {
    for (auto v : _shapes){
        os << "\ngsave\n" << (int)(-72*(v->getWidth()/2)) << " " << (int)(-72*(v->getHeight()/2)) << " translate\n";
        v->generatePostScript(os);
        os << "\ngrestore\n";
    }
}

//Vertical definitions
Vertical::Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes){
    double totalHeight = 0.0;
    double totalWidth = 0.0;
    for (auto v : shapes){
        totalHeight += v->getHeight();
        if (totalWidth < v->getWidth()) { totalWidth = v->getWidth(); }
    }
    for (auto v : shapes){
        _shapes.push_back(v);
    }
    _height = totalHeight;
    _width = totalWidth;
}
double Vertical::getHeight() const { return _height; }
double Vertical::getWidth() const { return _width; }
void Vertical::generatePostScript(std::ostream &os) const {
    int shift = 0;
    for (auto v : _shapes){
        os << "\ngsave\n" << (int)(-72*(v->getWidth()/2)+((72*_width)/2)) << " " << shift << " translate\n";
        v->generatePostScript(os);
        os << "\ngrestore\n";
        shift += 72*(v->getHeight());
    }
}

//Horizontal definitions
Horizontal::Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes){
    double totalHeight = 0.0;
    double totalWidth = 0.0;
    for (auto v : shapes){
        totalWidth += v->getWidth();
        if (totalHeight < v->getHeight()) { totalHeight = v->getHeight(); }
    }
    for (auto v : shapes){
        _shapes.push_back(v);
    }
    _height = totalHeight;
    _width = totalWidth;
}
double Horizontal::getHeight() const { return _height; }
double Horizontal::getWidth() const { return _width; }
void Horizontal::generatePostScript(std::ostream &os) const {
    int shift = 0;
    for (auto v : _shapes){
        
        os << "\ngsave\n" << shift << " " << (int)((-72*(v->getHeight()/2))+ ((72*_height)/2)) << " translate\n";
        v->generatePostScript(os);
        os << "\ngrestore\n";
        shift += 72*(v->getWidth());
    }
}

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
std::shared_ptr<Shape> makeSquare(double length) {return std::make_shared<Rectangle>(Rectangle(length, length));}
std::shared_ptr<Shape> makeTriangle(double length) {return std::make_shared<Polygon>(Polygon(3, length));}
std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> & s, Angle a) {return std::make_shared<Rotated>(Rotated(s, a));}
std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> & s, double sx, double sy) {return std::make_shared<Scaled>(Scaled(s, sx, sy));}
std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> i) {return std::make_shared<Layered>(Layered(i));}
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> i) {return std::make_shared<Vertical>(Vertical(i));}
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i) {return std::make_shared<Horizontal>(Horizontal(i));}