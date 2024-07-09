#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
using namespace std;

class Input {
public:
    static int readInt(const int&, const int&, const std::string&);
    static std::string readTask(const std::string&);
};


#endif //INPUT_HPP
