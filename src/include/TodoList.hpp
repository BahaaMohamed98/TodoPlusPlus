#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <set>
#include "Task.hpp"
#include "helpers.hpp"

class TodoList {
    std::set<Task, TaskComparator> taskList;

public:
    void addTask(const Task&);
    void removeTask(const int&);
    void markComplete(const int&);
    void markIncomplete(const int&);
    void print();
    void assignList(const std::set<Task, TaskComparator>&);
    std::set<Task, TaskComparator>& getList();
    void changePriority(const int&, const int&);
};

#endif //TODOLIST_HPP
