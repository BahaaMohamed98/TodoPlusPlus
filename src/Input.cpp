#include <Menu.hpp>
#ifndef INPUT_CPP
#define INPUT_CPP

#include <iostream>
#include <vector>
#include "Input.hpp"

// reads an integer within the given range between {start} and {end} and returns it
int Input::readInt(const int& start, const int& end, const std::string& prompt) {
    int number;
    do {
        cout << prompt << ": ";
        cin >> number;

        if (std::cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        else if (number >= start and number <= end)
            break;
        cout << "wrong input!\n";
    } while (true);
    return number;
}


//reads and returns task description
std::string Input::readTask(const std::string& prompt) {
    cout << prompt << ": ";
    std::string task;
    getline(cin, task);
    while (task.empty())
        getline(cin, task);
    return task;
}


//prompts user to choose priority and returns it
int Input::PriorityPrompt(const std::string& prompt) {
    clearScreen();
    Menu::printHeader();

    const vector<string> priorityOptions{
        "High",
        "medium",
        "low",
        "no"
    };

    for (int i = 0; i < priorityOptions.size(); ++i)
        cout << "[" << i + 1 << "] "
            << color(priorityColor[i]) << priorityOptions[i] << " priority"
            << color(reset) << "\n";
    cout << '\n';

    // reads priority number
    return readInt(1, static_cast<int>(priorityOptions.size()), prompt) - 1;
}

/*
 prompts user to confirm deletion
 returns true if the user agrees to the deletion
*/
bool Input::deletePrompt(const std::string& prompt) {
    std::string answer;
    cout << color(red) << prompt << "(y/n)? " << color(reset);
    cin >> answer;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "y" or answer == "yes")
        return true;
    return false;
}


#endif //INPUT_CPP
