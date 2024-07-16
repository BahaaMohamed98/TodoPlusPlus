#include "Task.hpp"
#include "helpers.hpp"

Task::Task(): done(false), priority(Priority::no_priority) {}

Task::Task(std::string p_taskDescription, const bool& isDone, const int& priority)
    : description(std::move(p_taskDescription)), done(isDone), priority(priority) {}

void Task::markDone() {
    done = true;
}

void Task::markUndone() {
    done = false;
}

bool Task::operator==(const Task& other) const {
    return done == other.isDone() and description == other.description;
}

int Task::getPriority() const {
    return priority;
}

void Task::setPriority(const int& priority) {
    this->priority = priority;
}

std::set<Task, TaskComparator> Task::getSubTasks() const {
    return subTasks;
}

void Task::insertSubtask(const Task& subTask) {
    subTasks.insert(subTask);
}

bool Task::isDone() const {
    return done;
}

std::string Task::getDescription() const {
    return description;
}
