#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <set>
#include "Task.hpp"

class TodoList {
    std::set<Task> taskList;

public:
    void loadTasks(const std::set<Task>&);
    void addTask(const Task&);
    void removeTask(const int&);
    void toggleCompletion(const int&);
    void print(bool);
    std::set<Task>& getList();
    void changePriority(const int&, const int&);
};

#endif //TODOLIST_HPP
