/*
 *
 */

#include "Shape.hpp"


std::shared_ptr<Shape> makeCircle(double radius){
    return std::make_shared<Circle>(Circle(radius));
}

std::shared_ptr<Shape> makePolygon(int numSides, double length){

}

std::shared_ptr<Shape> makeRectangle(double width, double height){

}

std::shared_ptr<Shape> makeSpacer(double width, double height){

}

std::shared_ptr<Shape> makeSquare(double length){

}

std::shared_ptr<Shape> makeTriangle(double length){

}

std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a){

}

std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy){

}

std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<Shape> i){

}

std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<Shape> i){

}

std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<Shape> i){

}


