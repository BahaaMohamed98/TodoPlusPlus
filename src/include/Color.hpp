#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <map>
#include "Priority.hpp"

enum Color {
    reset = 0, red = 31, green, yellow
};

inline std::map<int, Color> priorityColor{
    {High, red}, {medium, yellow}, {low, green}, {no_priority, reset}
};

std::string color(const int& c);

#endif //COLOR_HPP
