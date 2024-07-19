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

void TodoList::toggleCompletion(const int& taskNumber) {
    auto it = taskList.begin();
    std::advance(it, taskNumber);
    Task temp = *it;

    if (it->isDone())
        temp.markUndone();
    else
        temp.markDone();

    taskList.erase(it);
    taskList.insert(temp);
}

void TodoList::printTask(const Task& task, const int taskNumber, const bool printColor,
                         const bool printNumber = true) {
    if (!printNumber)
        std::cout << '-';
    else
        std::cout << taskNumber << ".";

    std::cout << " [" << (task.isDone() ? '*' : ' ') << "] ";

    if (printColor)
        std::cout << color(priorityColor[task.getPriority()]);

    std::cout << task.getDescription() << color(Color::reset) << '\n';
};

void TodoList::print(const bool printSubtasks) const {
    if (taskList.empty())
        return void(std::cout << "No tasks!\n");

    int taskNumber = 1;
    for (auto taskIter = taskList.begin(); taskIter != taskList.end(); ++taskIter, ++taskNumber) {
        printTask(*taskIter, taskNumber, !taskIter->isDone());

        if (!printSubtasks)
            continue;

        int subTaskNumber = 1;
        const auto subTasks = taskIter->getSubTasks();
        for (auto subTaskIter = subTasks.begin(); subTaskIter != subTasks.end(); ++subTaskIter, ++subTaskNumber) {
            std::cout << '\t';
            printTask(*subTaskIter, subTaskNumber, !taskIter->isDone() and !subTaskIter->isDone(), false);
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

void TodoList::printSubtasks(const int& taskNumber) {
    auto task = taskList.begin();
    advance(task, taskNumber);

    printTask(*task, 0, !task->isDone(), false);

    auto subTasks = task->getSubTasks();
    int subTaskNumber = 1;
    for (auto it = subTasks.begin(); it != subTasks.end(); ++it, ++subTaskNumber) {
        std::cout << '\t';
        printTask(*it, subTaskNumber, !task->isDone() and !it->isDone());
    }
}
