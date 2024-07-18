#include "Color.hpp"

std::string color(const int& c) {
    return "\033[1;" + std::to_string(c) + "m";
}
