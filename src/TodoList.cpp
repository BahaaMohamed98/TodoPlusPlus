#include "TodoList.hpp"

void TodoList::addTask(const Task& task) {
    taskList.insert(task);
}

void TodoList::removeTask(const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);
    taskList.erase(it);
}

void TodoList::markComplete(const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);

    if (!it->isDone()) {
        Task temp = *it;
        temp.markDone();
        taskList.erase(it);
        taskList.insert(temp);
    }
}

void TodoList::markIncomplete(const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);
    if (it->isDone()) {
        Task temp = *it;
        temp.markUndone();
        taskList.erase(it);
        taskList.insert(temp);
    }
}

void TodoList::print() {
    if (taskList.empty())
        return void(std::cout << "No tasks!\n");
    int i = 1;
    for (auto it = taskList.begin(); it != taskList.end(); ++it, ++i) {
        std::cout << i << ". [" << (it->isDone() ? '*' : ' ') << "] ";
        if (!it->isDone())
            std::cout << color(priorityColor[it->getPriority()]);
        std::cout << it->getDescription() << color(Color::reset) << '\n';
    }
}

void TodoList::assignList(const std::set<Task, TaskComparator>& tasks) {
    taskList = tasks;
}

std::set<Task, TaskComparator>& TodoList::getList() {
    return taskList;
}

void TodoList::changePriority(const int& priority, const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);
    if (it->getPriority() != priority) {
        Task temp = *it;
        temp.setPriority(priority);
        taskList.erase(it);
        taskList.insert(temp);
    }
}
