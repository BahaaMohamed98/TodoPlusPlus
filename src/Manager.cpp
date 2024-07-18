#include "Manager.hpp"
#include "Input.hpp"
#include "Color.hpp"

Manager::Manager() {
    loadTasks();
    lastID = fileManager.getLastID();
}

Manager::~Manager() {
    FileIO::writeTasks(todoList.getList(), "../tasks/tasks.csv");
}

void Manager::loadTasks() {
    todoList.loadTasks(fileManager.getTasks("../tasks/tasks.csv"));
}

bool Manager::logic() {
    const int chosenOption = Input::readInt(1, menu.getNumberOfOptions(), "Enter operaion number");

    if (chosenOption == menu.getNumberOfOptions()) // exit
        return false;

    clearScreen();
    Menu::printHeader();
    todoList.print();
    cout << '\n';

    switch (chosenOption) {
    case 1:
        todoList.addTask(
            {
                Input::readTask("Enter task description"),
                false,
                Priority::no_priority,
                ++lastID,
            });
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
        todoList.changePriority(
            Input::PriorityPrompt("Enter priority number"),
            Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1
        );
        break;
    case 5:
    {
        const int chosenTask{
            Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1
        };
        if (Input::deletePrompt("Are you sure you want to delete this task"))
            todoList.removeTask(chosenTask);
    }
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
