#include "include/Input.hpp"


int Input::readInt(const int& start, const int& end, const std::string& prompt) {
    int number;
    do {
        cout << prompt << "(" << start << "-" << end << "): ";
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

std::string Input::readTask(const std::string& prompt) {
    cout << prompt << ": ";
    std::string task;
    getline(cin, task);
    while (task.empty())
        getline(cin, task);
    return task;
}
