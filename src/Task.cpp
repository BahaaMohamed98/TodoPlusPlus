#include <algorithm>
#include "Task.hpp"

Task::Task(std::string p_taskDescription, const bool& isDone, const int& priority, const int& id)
    : description(std::move(p_taskDescription)), done(isDone), priority(priority), id(id) {}

void Task::markDone() {
    done = true;
}

void Task::markUndone() {
    done = false;
}

bool Task::operator<(const Task& other) const {
    std::string one = description, two = other.description;
    std::transform(one.begin(), one.end(), one.begin(), ::tolower);
    std::transform(two.begin(), two.end(), two.begin(), ::tolower);

    if (one == two)
        return false;

    if (done != other.done)
        return !done;

    if (priority != other.priority)
        return priority < other.priority;

    return one < two;
}

int Task::getPriority() const {
    return priority;
}

void Task::setPriority(const int& priority) {
    this->priority = priority;
}

std::set<Task> Task::getSubTasks() const {
    return subTasks;
}

void Task::insertSubtask(const Task& subTask) {
    subTasks.insert(subTask);
}

int Task::getID() const {
    return id;
}

bool Task::isDone() const {
    return done;
}

std::string Task::getDescription() const {
    return description;
}
