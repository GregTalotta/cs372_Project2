#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <vector>
#include <cmath>
using std::cos;
using std::sin;
#include "Shape.hpp"

const double PI = 3.14159;

TEST_CASE("circle created"){
    std::shared_ptr<Shape> checkCircle1 = makeCircle(1);
    CHECK(checkCircle1->getHeight() == 2);
    CHECK(checkCircle1->getWidth() == 2);
}

TEST_CASE("polygon of 5 sides created"){
    std::shared_ptr<Shape> checkPolygon = makePolygon(5,1);
    CHECK(checkPolygon->getHeight() == doctest::Approx((1+cos(PI/5))/(2*sin(PI/5))));
    CHECK(checkPolygon->getWidth() == doctest::Approx((sin(PI*(5-1)/2*5))/(sin(PI/5))));
}

TEST_CASE("polygon of 6 sides created"){
    std::shared_ptr<Shape> checkPolygon = makePolygon(6,1);
    CHECK(checkPolygon->getHeight() == doctest::Approx((cos(PI/6)/(sin(PI/6)))));
    CHECK(checkPolygon->getWidth() == doctest::Approx(1/(sin(PI/6))));
}

TEST_CASE("polygon of 8 sides created"){
    std::shared_ptr<Shape> checkPolygon = makePolygon(8,1);
    CHECK(checkPolygon->getHeight() == doctest::Approx((cos(PI/8))/(sin(PI/8))));
    CHECK(checkPolygon->getWidth() == doctest::Approx((cos(PI/8))/(sin(PI/8))));
}

TEST_CASE("rectangle created"){
    std::shared_ptr<Shape> checkRectangle = makeRectangle(1,2);
    CHECK(checkRectangle->getHeight() == doctest::Approx(2));
    CHECK(checkRectangle->getWidth() == doctest::Approx(1));
}

TEST_CASE("spacer created"){
    std::shared_ptr<Shape> checkSpacer = makeSpacer(2,1);
    CHECK(checkSpacer->getHeight() == doctest::Approx(1));
    CHECK(checkSpacer->getWidth()== doctest::Approx(2));
}

TEST_CASE("square created"){
    std::shared_ptr<Shape> checkSquare = makeSquare(1.0);
    CHECK(checkSquare->getHeight() == doctest::Approx(1));
    CHECK(checkSquare->getWidth() == doctest::Approx(1));
}

TEST_CASE("triangle created"){
    std::shared_ptr<Shape> checkTriangle = makeTriangle(1);
    CHECK(checkTriangle->getHeight() == doctest::Approx((1+cos(PI/3))/(2*sin(PI/3))));
    CHECK(checkTriangle->getWidth() == doctest::Approx((sin(PI*(3-1)/2*3))/(sin(PI/3))));
}