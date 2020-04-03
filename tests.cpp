#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <vector>
#include "shape.hpp"

TEST_CASE("circle created"){
    Circle checkCircle1(1)
    CHECK(checkCircle1.getHeight() == 2);
    CHECK(checkCircle1.getWidth() == 2);
}
