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
    Circle checkCircle1(1);
    CHECK(checkCircle1.getHeight() == 2);
    CHECK(checkCircle1.getWidth() == 2);
}

TEST_CASE("polygon of 5 sides created"){
    Polygon checkPolygon(5, 1);
    CHECK(checkPolygon.getHeight() == doctest::Approx((1+cos(PI/5))/(2*sin(PI/5))));
    CHECK(checkPolygon.getWidth() == doctest::Approx((sin(PI*(5-1)/2*5))/(sin(PI/5))));
}

TEST_CASE("polygon of 6 sides created"){
    Polygon checkPolygon(6, 1);
    CHECK(checkPolygon.getHeight() == doctest::Approx((cos(PI/6)/(sin(PI/6)))));
    CHECK(checkPolygon.getWidth() == doctest::Approx(1/(sin(PI/6))));
}

TEST_CASE("polygon of 8 sides created"){
    Polygon checkPolygon(8, 1);
    CHECK(checkPolygon.getHeight() == doctest::Approx((cos(PI/8))/(sin(PI/8))));
    CHECK(checkPolygon.getWidth() == doctest::Approx((cos(PI/8))/(sin(PI/8))));
}

TEST_CASE("rectangle created"){
    Rectangle checkRectangle(1,2);
    CHECK(checkRectangle.getHeight() == 2);
    CHECK(checkRectangle.getWidth() == 1);
}

TEST_CASE("spacer created"){
    Spacer checkSpacer(2,1);
    CHECK(checkSpacer.getHeight() == 1);
    CHECK(checkSpacer.getWidth()== 2);
}

TEST_CASE("square created"){
    Square checkSquare(1);
    CHECK(checkSquare.getHeight() == 1);
    CHECK(checkSquare.getWidth() == 1);
}

TEST_CASE("triangle created"){
    Triangle checkTriangle(1);
    CHECK(checkTriangle.getHeight() == doctest::Approx((1+cos(PI/3))/(2*sin(PI/3))));
    CHECK(checkTriangle.getWidth() == doctest::Approx((sin(PI*(3-1)/2*3))/(sin(PI/3))));
}