#include <catch2/catch_test_macros.hpp>
#include "lib.hpp"

TEST_CASE("sum works") {
    REQUIRE(sum({}) == 0);
    REQUIRE(sum({1}) == 1);
    REQUIRE(sum({1,2,3}) == 6);
}