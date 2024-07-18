#include <iostream>
#include <fstream>
#include "FileIo.hpp"

bool TaskComparator::operator()(const Task& a, const Task& b) const {
    if (a.isDone() != b.isDone())
        return !a.isDone();

    if (a.getPriority() != b.getPriority())
        return a.getPriority() < b.getPriority();

    std::string one = a.getDescription(), two = b.getDescription();
    std::transform(one.begin(), one.end(), one.begin(), ::tolower);
    std::transform(two.begin(), two.end(), two.begin(), ::tolower);
    return one <= two;
}

void FileIO::readFile(const std::string& fileName) {
    // temporary object to create the file if not already created
    std::ofstream(fileName.c_str(), ios::app);

    std::ifstream fin(fileName);

    if (!fin.is_open()) {
        std::cerr << "couldn't open file: " << fileName << '\n';
        exit(-1);
    }

    while (!fin.eof()) {
        string taskDescription, isDone, taskPriority, subTasksNumber;

        // removing the trailing new line character
        getline(fin, taskDescription, '\n');

        auto readTask = [&](const bool readSubTasksNumber = true) -> void {
            getline(fin, taskDescription, ',');
            getline(fin, isDone, ',');
            getline(fin, taskPriority, ',');
            if (readSubTasksNumber)
                getline(fin, subTasksNumber, ',');
        };

        readTask();

        if (taskDescription.empty() or isDone.empty() or taskPriority.empty())
            continue;

        Task task(taskDescription, isDone == "1", taskPriority.back() - '0');

        int size = stoi(subTasksNumber);
        for (int i = 0; i < size; ++i) {
            readTask(false);
            if (taskDescription.empty() or isDone.empty() or taskPriority.empty())
                break;
            task.insertSubtask({taskDescription, isDone == "1", taskPriority.back() - '0'});
        }

        tasks.insert(task);
    }

    fin.close();
}

std::set<Task, TaskComparator>& FileIO::getTasks(const std::string& fileName) {
    readFile(fileName);
    return tasks;
}

void FileIO::writeTasks(const set<Task, TaskComparator>& tasks, const std::string& fileName) {
    ofstream fout;
    fout.open(fileName, ios::out | ios::trunc);

    if (!fout.is_open()) {
        cerr << "failed to write to: " << fileName << '\n';
        exit(254);
    }

    auto writeTask = [&](const Task& task, bool printSize = true) {
        fout << task.getDescription() << ',' << task.isDone() << ',' << task.getPriority() << ',';
        if (printSize)
            fout << task.getSubTasks().size() << ',';
    };

    fout << '\n';
    for (auto& task : tasks) {
        writeTask(task);
        for (auto& subTask : task.getSubTasks())
            writeTask(subTask, false);
        fout << '\n';
    }

    fout.close();
}
