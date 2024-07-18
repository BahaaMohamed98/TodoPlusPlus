#ifndef HELPERS_HPP
#define HELPERS_HPP

inline void clearScreen() {
#ifdef _WIN32 // For Windows
    system("cls");
#else // for linux and macOS
    system("clear");
#endif
}

#endif //HELPERS_HPP
