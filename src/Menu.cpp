#include "Menu.hpp"

Menu::Menu()
    : options({
          "Add a task",
          "Exit"
      }),
      extraOptions({
          "Toggle task completion",
          "Change task priority",
          "Toggle subtasks visibility",
          "Remove a task",
          "Edit subtasks",
      }) {}

void Menu::printHeader() {
    std::cout << R"(
 _____         _       ____  _           ____  _
|_   _|__   __| | ___ |  _ \| |_   _ ___|  _ \| |_   _ ___
  | |/ _ \ / _` |/ _ \| |_) | | | | / __| |_) | | | | / __|
  | | (_) | (_| | (_) |  __/| | |_| \__ \  __/| | |_| \__ \
  |_|\___/ \__,_|\___/|_|   |_|\__,_|___/_|   |_|\__,_|___/

)";
}

void Menu::print(const bool& printExtra) {
    if (printExtra) {
        if (options.size() != 2 + extraOptions.size())
            options.insert(options.begin() + 1, extraOptions.begin(), extraOptions.end());
    }
    else if (options.size() != 2)
        options.erase(options.begin() + 1, options.begin() + static_cast<int>(extraOptions.size()) + 1);


    for (int i = 0; i < options.size(); ++i)
        std::cout << '[' << i + 1 << "] " << options[i] << '\n';
    std::cout << '\n';
}

int Menu::getNumberOfOptions() const {
    return static_cast<int>(options.size());
}
