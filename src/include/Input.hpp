#ifndef INPUT_HPP
#define INPUT_HPP

#include "helpers.hpp"
using namespace std;

class Input {
public:
    static int readInt(const int&, const int&, const std::string&);
    static std::string readTask(const std::string&);
    static int PriorityPrompt(const std::string& prompt);
    static bool deletePrompt(const std::string& prompt);
};


#endif //INPUT_HPP
