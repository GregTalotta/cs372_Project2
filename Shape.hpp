/**
 * Factory definitions created by Chris Hartman on 3/27/20.
 */


#ifndef CPS2020_SHAPE_HPP
#define CPS2020_SHAPE_HPP
#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>

class Shape {
protected:
    double _width;     // width of bounding box
    double _height;    // height of bounding box
public:
  virtual ~Shape() = default;
  virtual double getHeight() const = 0;
  virtual double getWidth() const = 0;
  virtual void generatePostScript(std::ostream &os) const = 0;
};
class Circle: public Shape {
public:
    explicit Circle(double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        double _radius;
};
class Polygon: public Shape {
public:
    Polygon(int, double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        int _numSides;
        double _sideLength;
};
class Rectangle: public Shape {
public:
    Rectangle(double, double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};
class Spacer: public Shape {
public:
    Spacer(double, double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};

enum class Angle {R90,R180,R270};
class Rotated: public Shape{
public:
    Rotated(std::shared_ptr<Shape> &, Angle);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        std::shared_ptr<Shape>  _shape;
        Angle _rotationAngle;
};
class Scaled: public Shape{
public:
    Scaled(std::shared_ptr<Shape> &, double, double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        std::shared_ptr<Shape>  _shape;
        double _fx;
        double _fy;
};
class Layered: public Shape{
public:
    Layered(std::initializer_list<std::shared_ptr<Shape>>);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        std::vector<std::shared_ptr<Shape>> _shapes;
};
class Vertical: public Shape{
public:
    Vertical(std::initializer_list<std::shared_ptr<Shape>>);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        std::vector<std::shared_ptr<Shape>> _shapes;
};
class Horizontal: public Shape{
public:
    Horizontal(std::initializer_list<std::shared_ptr<Shape>>);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
    protected:
        std::vector<std::shared_ptr<Shape>> _shapes;
};
class Special: public Shape{
public:
    Special(/*not sure what is required*/);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};

std::shared_ptr<Shape> makeCircle(double radius);
std::shared_ptr<Shape> makePolygon(int numSides, double length) ;
std::shared_ptr<Shape> makeRectangle(double width, double height);
std::shared_ptr<Shape> makeSpacer(double width, double height);
std::shared_ptr<Shape> makeSquare(double length);
std::shared_ptr<Shape> makeTriangle(double length);
std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> & s, Angle a);
std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> & s, double sx, double sy);
std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> i);
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> i);
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i);

#endif // CPS2020_SHAPE_HPP

/*
 *
 */