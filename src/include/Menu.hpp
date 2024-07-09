#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <deque>

class Menu {
    std::deque<std::string> options;
    std::deque<std::string> extraOptions;

public:
    Menu();
    void print(const bool&);
    static void printHeader();
    [[nodiscard]] int getNumberOfOptions() const;
};


#endif //MENU_HPP
