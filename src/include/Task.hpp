#ifndef TASK_HPP
#define TASK_HPP

#include <set>
#include "helpers.hpp"

class Task;

struct TaskComparator {
    bool operator()(const Task&, const Task&) const;
};

class Task {
    std::string description;
    bool done;
    int priority;
    std::set<Task, TaskComparator> subTasks;

public:
    Task();
    Task(std::string, const bool&, const int&);
    [[nodiscard]] bool isDone() const;
    [[nodiscard]] std::string getDescription() const;
    void markDone();
    void markUndone();
    bool operator==(const Task& other) const;
    [[nodiscard]] int getPriority() const;
    void setPriority(const int&);
    [[nodiscard]] std::set<Task, TaskComparator> getSubTasks() const;
    void insertSubtask(const Task&);
};

#endif //TASK_HPP
