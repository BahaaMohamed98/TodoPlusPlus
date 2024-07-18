#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "TodoList.hpp"
#include "FileIo.hpp"
#include "Menu.hpp"

class Manager {
    TodoList todoList;
    FileIO fileManager;
    Menu menu;
    int lastID;
    bool showSubtasks;

public:
    Manager();
    ~Manager();
    void loadTasks();
    bool logic();
    void start();
    void printToDoList();
};

#endif //MANAGER_HPP
