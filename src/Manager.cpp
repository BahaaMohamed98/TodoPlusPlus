#include "Manager.hpp"

Manager::Manager() {
    todoList.assignList(fileManager.getTasks("../tasks/tasks.csv"));
}

Manager::~Manager() {
    FileIO::writeTasks(todoList.getList(), "../tasks/tasks.csv");
}

bool Manager::logic() {
    const int readInt = Input::readInt(1, menu.getNumberOfOptions(), "Enter operaion number");

    if (readInt == menu.getNumberOfOptions()) // exit
        return false;

    switch (readInt) {
        case 1:
            todoList.addTask({Input::readTask("Enter task description"), false});
            break;
        case 2:
            todoList.markComplete(
                Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1);
            break;
        case 3:
            todoList.markIncomplete(
                Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1);
            break;
        case 4:
            todoList.removeTask(Input::readInt(1, static_cast<int>(todoList.getList().size()),
                                               "Enter task number") - 1);
            break;
        default:
            break;
    }
    return true;
}

void Manager::start() {
    do {
        clearScreen();
        Menu::printHeader();
        todoList.print();
        cout << '\n';
        menu.print(!todoList.getList().empty());
    } while (logic());
}

void Manager::printToDoList() {
    cout << "Todo: \n";
    todoList.print();
    cout << '\n';
}
