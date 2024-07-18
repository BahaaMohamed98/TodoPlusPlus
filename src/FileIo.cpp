#include <iostream>
#include <fstream>
#include "FileIo.hpp"

void FileIO::readFile(const std::string& fileName) {
    // temporary object to create the file if not already created
    std::ofstream(fileName.c_str(), ios::app);

    std::ifstream fin(fileName);

    if (!fin.is_open()) {
        std::cerr << "couldn't open file: " << fileName << '\n';
        exit(-1);
    }

    while (!fin.eof()) {
        string id, taskDescription, isDone, taskPriority, subtasksCount;
        int id_;

        auto makeTask = [&]() {
            id_ = stoi(id);
            return Task(taskDescription, isDone == "1", stoi(taskPriority), id_);
        };

        auto readTask = [&]() {
            getline(fin, id, ',');
            getline(fin, taskDescription, ',');
            getline(fin, isDone, ',');
            getline(fin, taskPriority, ',');
            getline(fin, subtasksCount, '\n');
        };

        auto emptyInput = [&]() {
            return id.empty() or taskDescription.empty() or isDone.empty() or taskPriority.empty();
        };

        // reading and making the parent task
        readTask();
        if (emptyInput())
            continue;
        auto task = makeTask();

        // reading subtasks

        int subtasksCount_ = stoi(subtasksCount);
        for (int i = 0; i < subtasksCount_; ++i) {
            readTask();
            task.insertSubtask(makeTask());
        }

        tasks.insert(task);
        lastID = max(lastID, id_);
    }

    fin.close();
}

std::set<Task>& FileIO::getTasks(const std::string& fileName) {
    readFile(fileName);
    return tasks;
}

void FileIO::writeTasks(const set<Task>& tasks, const std::string& fileName) {
    ofstream fout;
    fout.open(fileName, ios::out | ios::trunc);

    if (!fout.is_open()) {
        cerr << "failed to write to: " << fileName << '\n';
        exit(-1);
    }

    int newID = 0;
    auto writeTask = [&](const Task& task) -> void {
        fout << ++newID << ',' << task.getDescription() << ',' << task.isDone() << ','
                << task.getPriority() << ',' << task.getSubTasks().size() << '\n';
    };

    for (auto& task : tasks) {
        writeTask(task);
        for (auto& subTask : task.getSubTasks())
            writeTask(subTask);
    }

    fout.close();
}

int& FileIO::getLastID() {
    return lastID;
}
