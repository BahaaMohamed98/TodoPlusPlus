#ifndef FILEIO_HPP
#define FILEIO_HPP
using namespace std;

#include "TodoList.hpp"

class FileIO {
    std::set<Task, TaskComparator> tasks;
    void readFile(const std::string& fileName);

public:
    std::set<Task, TaskComparator>& getTasks(const std::string&);
    static void writeTasks(const set<Task, TaskComparator>&, const std::string&);
};

#endif //FILEIO_HPP
