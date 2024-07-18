#include "Manager.hpp"
#include "Input.hpp"
#include "Color.hpp"
#include "helpers.hpp"

Manager::Manager(): showSubtasks(true) {
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

    printToDoList();

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
        todoList.toggleCompletion(
            Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1);
        break;
    case 3:
        todoList.changePriority(
            Input::PriorityPrompt("Enter priority number"),
            Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1
        );
        break;
    case 4:
        showSubtasks = !showSubtasks;
        break;
    case 5:
    {
        const int chosenTask{
            Input::readInt(1, static_cast<int>(todoList.getList().size()), "Enter task number") - 1
        };
        if (Input::deletePrompt("Are you sure you want to delete this task"))
            todoList.removeTask(chosenTask);
        break;
    }
    default:
        break;
    }
    return true;
}

void Manager::start() {
    do {
        printToDoList();
        menu.print(!todoList.getList().empty());
    } while (logic());

    clearScreen();
    cout << "FREE PALESTINE\n\n";
}

void Manager::printToDoList() {
    clearScreen();
    Menu::printHeader();
    todoList.print(showSubtasks);
    cout << '\n';
}
