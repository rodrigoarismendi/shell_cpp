#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <string>
#include <vector>
#include <unordered_set>

class Executor {
public:
    Executor();
    
    // Execute a command with given arguments
    // Returns true if shell should continue, false if it should exit
    bool execute(const std::string& command, const std::vector<std::string>& args, const std::string& raw_args);

private:
    std::unordered_set<std::string> builtins_;
    
    // Builtin command handlers
    void handleEcho(const std::string& raw_args);
    void handleType(const std::vector<std::string>& args);
    
    // Helper to find command in PATH
    std::string findInPath(const std::string& command);
};

#endif // EXECUTOR_HPP
