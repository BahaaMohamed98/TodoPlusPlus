#include <iostream>
#include "TodoList.hpp"
#include "Color.hpp"

void TodoList::loadTasks(const std::set<Task>& externalList) {
    taskList = externalList;
}

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

    if (it->isDone())
        return;

    Task temp = *it;
    temp.markDone();
    taskList.erase(it);
    taskList.insert(temp);
}

void TodoList::markIncomplete(const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);

    if (!it->isDone())
        return;

    Task temp = *it;
    temp.markUndone();
    taskList.erase(it);
    taskList.insert(temp);
}

void TodoList::print() {
    auto printTask = [](const Task& task, const int taskNumber) -> void {
        std::cout << taskNumber << ". [" << (task.isDone() ? '*' : ' ') << "] ";

        if (!task.isDone())
            std::cout << color(priorityColor[task.getPriority()]);

        std::cout << task.getDescription() << color(Color::reset) << '\n';
    };

    if (taskList.empty())
        return void(std::cout << "No tasks!\n");

    int taskNumber = 1;
    for (auto taskIter = taskList.begin(); taskIter != taskList.end(); ++taskIter, ++taskNumber) {
        printTask(*taskIter, taskNumber);

        int subTaskNumber = 1;
        const auto subTasks = taskIter->getSubTasks();
        for (auto subTaskIter = subTasks.begin(); subTaskIter != subTasks.end(); ++subTaskIter, ++subTaskNumber) {
            std::cout << '\t';
            printTask(*subTaskIter, subTaskNumber);
        }
    }
}

std::set<Task>& TodoList::getList() {
    return taskList;
}

void TodoList::changePriority(const int& priority, const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);

    if (it->getPriority() == priority)
        return;

    Task temp = *it;
    temp.setPriority(priority);
    taskList.erase(it);
    taskList.insert(temp);
}
