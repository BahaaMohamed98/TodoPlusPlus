#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>

class Task {
    std::string description;
    bool done;
    int priority;

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
};

#endif //TASK_HPP
