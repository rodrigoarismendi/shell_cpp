#include "../include/History.hpp"

History::History() {}

void History::add(const std::string& command) {
    if (!command.empty()) {
        commands_.push_back(command);
    }
}

std::vector<std::string> History::getAll() const {
    return commands_;
}

std::string History::get(size_t index) const {
    if (index < commands_.size()) {
        return commands_[index];
    }
    return "";
}
