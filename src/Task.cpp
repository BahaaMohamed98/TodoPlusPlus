#include "Task.hpp"

Task::Task(): done(false) {}

Task::Task(std::string p_taskDescription, const bool isDone)
    : description(std::move(p_taskDescription)), done(isDone) {}

void Task::markDone() {
    done = true;
}

void Task::markUndone() {
    done = false;
}

bool Task::operator==(const Task& other) const {
    return done == other.isDone() and description == other.description;
}

bool Task::isDone() const {
    return done;
}

std::string Task::getDescription() const {
    return description;
}
