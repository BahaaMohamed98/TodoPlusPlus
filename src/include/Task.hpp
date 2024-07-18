#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <set>

class Task;

class Task {
    std::string description;
    bool done{};
    int priority{};
    std::set<Task> subTasks;
    int id{};

public:
    Task(std::string, const bool&, const int&, const int&);
    [[nodiscard]] bool isDone() const;
    [[nodiscard]] std::string getDescription() const;
    void markDone();
    void markUndone();
    bool operator<(const Task& other) const;
    [[nodiscard]] int getPriority() const;
    void setPriority(const int&);
    [[nodiscard]] std::set<Task> getSubTasks() const;
    void insertSubtask(const Task&);
    [[nodiscard]] int getID() const;
};

#endif //TASK_HPP
