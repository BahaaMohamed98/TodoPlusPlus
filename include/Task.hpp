#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>

class Task {
    std::string description;
    bool done;

public:
    Task();
    Task(std::string, bool);
    [[nodiscard]] bool isDone() const;
    [[nodiscard]] std::string getDescription() const;
    void markDone();
    void markUndone();
    bool operator==(const Task &other) const;
};


#endif //TASK_HPP
