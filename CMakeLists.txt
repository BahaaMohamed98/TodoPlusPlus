cmake_minimum_required(VERSION 3.28)
project(ToDo)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDo main.cpp
        Task.cpp
        TodoList.cpp
        Menu.cpp
        FileIo.cpp
        Manager.cpp
        include/Manager.hpp
        Input.cpp
        include/Input.hpp
        include/helpers.hpp)
add_executable(test testing/test.cpp)

target_include_directories(ToDo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ToDo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tasks)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tasks)
