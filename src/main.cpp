#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unistd.h>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  const char* path_env = std::getenv("PATH");

  const std::unordered_set<std::string> builtins = {
    "echo",
    "type",
    "exit"
    // Add any other built‑in commands you implement
  };
  while (true) { 
    std::string command;
    // TODO: Uncomment the code below to pass the first stage
    std::cout << "$ ";
    std::getline(std::cin, command);
    
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;
      
    if (command == "exit") {
      break;
    }
    else if (cmd == "echo") {
        std::string rest;
        std::getline(iss, rest); 
        if (!rest.empty() && rest[0] == ' ') rest.erase(0, rest.find_first_not_of(' '));
        std::cout << rest << std::endl;
    }
    else if (cmd == "type") {
        std::string arg;
        bool is_builtin = false; 
        iss >> arg;

        if (builtins.find(arg) != builtins.end()) {
            std::cout << arg << " is a shell builtin\n";
            break;
        } 
        else if (!is_builtin){
          std::stringstream ss_path(path_env);
          std::string path;
          while (std::getline(ss_path, path, ':')) {
            std::string full_path = path + '/' + arg;
            if (access(full_path.c_str(), X_OK) == 0){
              std::cout << arg << " is " << full_path << std::endl;
              break;
            }
          }
        }
        else {
            std::cout << arg << ": not found\n";
            break;
        }
    }
    else {
      std::cout << command << ": command not found" << std::endl;
    }

  }
  return 0;
}
