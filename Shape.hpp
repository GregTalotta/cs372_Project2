/*
 * Factory definitions created by Chris Hartman on 3/27/20.
 */


#ifndef CPS2020_SHAPE_HPP
#define CPS2020_SHAPE_HPP
#include <iostream>
#include <initializer_list>
#include <memory>

class Shape {
public:
  virtual ~Shape() = default;
  virtual double getHeight() const = 0;
  virtual double getWidth() const = 0;
  virtual void generatePostScript(std::ostream &os) const = 0;
};

std::shared_ptr<Shape> makeCircle(double radius);
/* implementation might look like this
 * {
 * return make_shared<Circle>(13.13);
 * }
*/

std::shared_ptr<Shape> makePolygon(int numSides, double length);
std::shared_ptr<Shape> makeRectangle(double width, double height);
std::shared_ptr<Shape> makeSpacer(double width, double height);
std::shared_ptr<Shape> makeSquare(double length);
std::shared_ptr<Shape> makeTriangle(double length);
enum class Angle {R90,R180,R270};
std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a);
// auto r = RotatedShape(s,Angle::R90);
std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy);
std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<Shape> i);
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<Shape> i);
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<Shape> i);








#endif // CPS2020_SHAPE_HPP

/*
 *
 */