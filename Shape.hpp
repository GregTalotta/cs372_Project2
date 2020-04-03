/*
 * Factory definitions created by Chris Hartman on 3/27/20.
 */


#ifndef CPS2020_SHAPE_HPP
#define CPS2020_SHAPE_HPP
#include <iostream>
#include <initializer_list>
#include <memory>

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
};
class Polygon: public Shape {
public:
    Polygon(int, double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
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
class Square: public Shape {
public:
    explicit Square(double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};
class Triangle: public Shape{
public:
    explicit Triangle(double);
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
};
class Scaled: public Shape{
public:
    Scaled(std::shared_ptr<Shape> &, double, double);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};
class Layered: public Shape{
public:
    Layered(std::initializer_list<std::shared_ptr<Shape>>);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};
class Vertical: public Shape{
public:
    Vertical(std::initializer_list<std::shared_ptr<Shape>>);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};
class Horizontal: public Shape{
public:
    Horizontal(std::initializer_list<std::shared_ptr<Shape>>);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};
class Special: public Shape{
public:
    Special(/*not sure what is required*/);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream &os) const override;
};

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








#endif // CPS2020_SHAPE_HPP

/*
 *
 */