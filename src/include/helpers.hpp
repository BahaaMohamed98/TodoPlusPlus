#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <algorithm>
#include <string>
#include <map>
#include "Task.hpp"

struct TaskComparator {
    bool operator()(const Task& a, const Task& b) const {
        if (a.isDone() != b.isDone())
            return !a.isDone();

        if (a.getPriority() != b.getPriority())
            return a.getPriority() < b.getPriority();

        std::string one = a.getDescription(), two = b.getDescription();
        std::transform(one.begin(), one.end(), one.begin(), ::tolower);
        std::transform(two.begin(), two.end(), two.begin(), ::tolower);
        return one <= two;
    }
};

inline void clearScreen() {
#ifdef _WIN32 // For Windows
    system("cls");
#else // for linux and macOS
    system("clear");
#endif
}

enum Priority {
    High = 0, medium, low, no_priority,
};

enum Color {
    red = 31, yellow = 33, green = 32, reset = 0
};

inline std::map<int, Color> priorityColor{
    {High, red}, {medium, yellow}, {low, green}, {no_priority, reset}
};

inline std::string color(const int& c) {
    return "\033[1;" + std::to_string(c) + "m";
}

#endif //HELPERS_HPP
