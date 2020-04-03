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








#endif // CPS2020_SHAPE_HPP

/*
 *
 */