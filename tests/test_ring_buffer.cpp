#include <catch2/catch_test_macros.hpp>
#include "ring_buffer.hpp"
#include <string>

TEST_CASE("RingBuffer basic push/pop") {
    RingBuffer<int, 3> rb;
    REQUIRE(rb.empty());
    REQUIRE(rb.push(1));
    REQUIRE(rb.push(2));
    REQUIRE(rb.push(3));
    REQUIRE(rb.full());
    REQUIRE_FALSE(rb.push(4));

    auto a = rb.pop(); REQUIRE(a && *a == 1);
    auto b = rb.pop(); REQUIRE(b && *b == 2);
    auto c = rb.pop(); REQUIRE(c && *c == 3);
    REQUIRE(rb.empty());
    REQUIRE_FALSE(rb.pop().has_value());
}

TEST_CASE("RingBuffer wraparound and peek") {
    RingBuffer<std::string, 2> rb;
    REQUIRE(rb.push("A"));
    REQUIRE(rb.push("B"));
    REQUIRE(rb.full());
    REQUIRE(std::string(*rb.peek()) == "A");
    REQUIRE(rb.pop().value() == "A");
    REQUIRE(rb.push("C"));
    REQUIRE(rb.full());
    REQUIRE(rb.pop().value() == "B");
    REQUIRE(rb.pop().value() == "C");
    REQUIRE(rb.empty());
}