# Shell C++ Practice Project

This repository is a hands-on C++ learning project where I am building my own POSIX-compliant shell. It is inspired by the ["Build Your Own Shell" Challenge](https://app.codecrafters.io/courses/shell/overview) on CodeCrafters and serves as a platform for me to practice and strengthen my C++ skills.

The project aims to implement a functional shell that can:
- Parse and interpret shell commands.
- Run external programs and built-in commands like `cd`, `pwd`, `echo`, and more.
- Provide a simple REPL interface.

> **Note:** If you're viewing this repo on GitHub, head over to [codecrafters.io](https://codecrafters.io) to try the original challenge.

---

## Project Goals

- Learn and reinforce C++ programming concepts.
- Understand how POSIX shells work internally.
- Implement command parsing, process management, and built-in command handling.

---

## Setup & Dependencies

### Prerequisites

- A Unix-like operating system (Linux or macOS recommended)
- [CMake](https://cmake.org/) (version 3.10 or higher)
- A C++ compiler supporting C++17 or newer (e.g., g++ or clang++)
- GNU Make

### Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/rodrigoarismendi/shell_cpp.git
    cd shell_cpp
    ```

2. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the shell:**
    ```sh
    ./your_program.sh
    ```

   _The implementation entry point is in `src/main.cpp`._

---

## Submitting to CodeCrafters

If you are participating in the CodeCrafters challenge:

- Submit your solution to their servers using:
    ```sh
    codecrafters submit
    ```
  _Test output will be streamed to your terminal._

---

## License

This project is for personal learning purposes.

---

Happy hacking! 🚀