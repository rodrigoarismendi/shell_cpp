#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <string>
#include <vector>

class History {
public:
    History();
    
    // Add a command to history
    void add(const std::string& command);
    
    // Get all commands in history
    std::vector<std::string> getAll() const;
    
    // Get a specific command by index
    std::string get(size_t index) const;

private:
    std::vector<std::string> commands_;
};

#endif // HISTORY_HPP
