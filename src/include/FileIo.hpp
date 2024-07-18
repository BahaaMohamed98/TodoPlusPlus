#ifndef FILEIO_HPP
#define FILEIO_HPP
using namespace std;

#include "TodoList.hpp"

class FileIO {
    std::set<Task> tasks;
    void readFile(const std::string& fileName);
    int lastID = 0;

public:
    std::set<Task>& getTasks(const std::string&);
    static void writeTasks(const set<Task>&, const std::string&);
    int& getLastID();
};

#endif //FILEIO_HPP
