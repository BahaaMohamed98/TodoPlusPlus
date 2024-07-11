#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "TodoList.hpp"
#include "FileIo.hpp"
#include "Menu.hpp"
#include "Input.hpp"

class Manager {
    TodoList todoList;
    FileIO fileManager;
    Menu menu;

public:
    Manager();
    ~Manager();
    bool logic();
    void start();
    void printToDoList();
};

#endif //MANAGER_HPP
