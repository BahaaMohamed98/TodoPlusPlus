cmake_minimum_required(VERSION 3.28)
project(ToDo)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDo src/main.cpp
        src/Task.cpp
        src/TodoList.cpp
        src/Menu.cpp
        src/FileIo.cpp
        src/Manager.cpp
        src/include/Manager.hpp
        src/Input.cpp
)

target_compile_options(ToDo PRIVATE -static)
target_compile_options(ToDo PRIVATE -static-libgcc)
target_compile_options(ToDo PRIVATE -static-libstdc++)

target_include_directories(ToDo PRIVATE src/include)
target_include_directories(ToDo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tasks)
