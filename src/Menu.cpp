#include "Menu.hpp"

Menu::Menu()
    : options({
          "Add a task",
          "Exit"
      }),
      extraOptions({
          "Mark task as complete",
          "Mark task as incomplete",
          "Remove a task",
      }) {}

void Menu::printHeader() {
    std::cout << "Todo app.\n\n";
}

void Menu::print(const bool& printExtra) {
    if (printExtra) {
        if (options.size() != 2 + extraOptions.size())
            options.insert(options.begin() + 1, extraOptions.begin(), extraOptions.end());
    }
    else {
        if (options.size() != 2)
            options.erase(options.begin() + 1, options.begin() + static_cast<int>(extraOptions.size()) + 1);
    }

    for (int i = 0; i < options.size(); ++i)
        std::cout << '[' << i + 1 << "] " << options[i] << '\n';
    std::cout << '\n';
}

int Menu::getNumberOfOptions() const {
    return static_cast<int>(options.size());
}
