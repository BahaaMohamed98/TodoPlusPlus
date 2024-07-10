# Todo App

A simple console-based todo application written in C++ that allows users to manage their tasks efficiently.

## Features

- Add tasks
- Mark tasks as complete or incomplete
- Remove tasks
- Assign priorities to tasks (Low, Medium, High)
- Display tasks with priority colors

## Preview

<p align="center">
   <img align="center" alt="todo app preview" src="assets/preview.gif">
</p>

## Getting Started

### Prerequisites

- g++ compiler (or any other C++ compiler)
- CMake (version 3.28 or higher)

### Building the Project

#### Using CMake

Run CMake and build:

```sh
   cmake ..
   make
```

#### Using g++

1. Compile the source files directly:

```sh
   g++ -std=c++17 -o build/ToDo src/*.cpp
   cd build
   ./ToDo
```

### Running pre-built binaries

#### On Linux

```sh
  cd build
  ./ToDo
```

#### On Windows

```sh
  cd build
  .\ToDo.exe
```

### Tasks File

Ensure you have a tasks.csv file in the tasks/ directory. The application reads from and writes to this file.

## Usage

1. Run the application using one of the methods described above.
2. Follow the on-screen instructions to add, complete, change priority, or remove tasks.

## Code Structure

- **src/main.cpp:** Entry point of the application.
- **src/Manager.cpp:** Manages the main application logic.
- **src/TodoList.cpp:** Handles task operations.
- **src/Task.cpp:** Represents individual tasks.
- **src/FileIo.cpp:** Manages file input/output operations.
- **src/Input.cpp:** Handles user input.
- **src/Menu.cpp:** Manages the display of menu options.
- tasks: Task CSV file
- build: Build directory