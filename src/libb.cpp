#include "lib.hpp"

int sum(const std::vector<int>& v) {
    int s = 0;
    for (int x : v) s += x;
    return s;
}