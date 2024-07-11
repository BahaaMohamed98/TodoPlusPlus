#include <fstream>
#include "FileIo.hpp"

void FileIO::readFile(const std::string& fileName) {
    std::ifstream fin(fileName);

    if (!fin.is_open()) {
        std::cerr << "couldn't open file: " << fileName << '\n';
        exit(-1);
    }

    while (!fin.eof()) {
        string taskDescription, isDone, taskPriority;

        getline(fin, taskDescription, ',');
        getline(fin, isDone, ',');
        getline(fin, taskPriority, '\n');

        if (!taskDescription.empty() and !isDone.empty() and !taskPriority.empty())
            tasks.insert({taskDescription, isDone == "1", taskPriority.back() - '0'});
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

    for (auto& task : tasks)
        fout << task.getDescription() << ',' << task.isDone() << ',' << task.getPriority() << '\n';

    fout.close();
}
