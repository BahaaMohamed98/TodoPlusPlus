#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <algorithm>
#include <string>
#include "Task.hpp"

struct TaskComparator {
    bool operator()(const Task& a, const Task& b) const {
        if (a.isDone() != b.isDone())
            return !a.isDone();
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

#endif //HELPERS_HPP
