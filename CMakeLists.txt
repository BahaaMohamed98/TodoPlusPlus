cmake_minimum_required(VERSION 3.28)
project(ToDo)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDo src/main.cpp
        src/Task.cpp
        src/TodoList.cpp
        src/Menu.cpp
        src/FileIo.cpp
        src/Manager.cpp
        src/Input.cpp
)
add_executable(test testing/test.cpp)

target_include_directories(ToDo PRIVATE src/include)
