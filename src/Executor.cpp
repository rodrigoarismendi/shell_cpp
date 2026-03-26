#include "../include/Executor.hpp"
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cstdlib>

Executor::Executor() {
    // Initialize builtin commands
    builtins_ = {
        "echo",
        "type",
        "exit"
    };
}

bool Executor::execute(const std::string& command, const std::vector<std::string>& args, const std::string& raw_args) {
    if (command.empty()) {
        return true;
    }
    
    if (command == "exit") {
        return false; // Signal to exit the shell
    }
    else if (command == "echo") {
        handleEcho(raw_args);
    }
    else if (command == "type") {
        handleType(args);
    }
    else {
        std::cout << command << ": command not found" << std::endl;
    }
    
    return true; // Continue running
}

void Executor::handleEcho(const std::string& raw_args) {
    std::cout << raw_args << std::endl;
}

void Executor::handleType(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cout << "type: missing argument\n";
        return;
    }
    
    const std::string& arg = args[0];
    
    // Check if it's a builtin
    if (builtins_.find(arg) != builtins_.end()) {
        std::cout << arg << " is a shell builtin\n";
        return;
    }
    
    // Check in PATH
    std::string path = findInPath(arg);
    if (!path.empty()) {
        std::cout << arg << " is " << path << std::endl;
        return;
    }
    
    // Not found
    std::cout << arg << ": not found\n";
}

std::string Executor::findInPath(const std::string& command) {
    const char* path_env = std::getenv("PATH");
    if (!path_env) {
        return "";
    }
    
    std::stringstream ss_path(path_env);
    std::string path;
    
    while (std::getline(ss_path, path, ':')) {
        std::string full_path = path + '/' + command;
        if (access(full_path.c_str(), X_OK) == 0) {
            return full_path;
        }
    }
    
    return "";
}
