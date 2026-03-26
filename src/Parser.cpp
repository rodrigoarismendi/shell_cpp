#include "../include/Parser.hpp"
#include <sstream>

Parser::Parser() {}

void Parser::parse(const std::string& input) {
    std::istringstream iss(input);
    
    // Extract the command
    iss >> command_;
    
    // Clear previous arguments
    arguments_.clear();
    
    // Extract arguments
    std::string arg;
    while (iss >> arg) {
        arguments_.push_back(arg);
    }
    
    // Store the raw argument string (everything after the command)
    std::istringstream iss2(input);
    std::string cmd;
    iss2 >> cmd;
    std::getline(iss2, raw_args_);
    
    // Trim leading whitespace from raw_args
    if (!raw_args_.empty() && raw_args_[0] == ' ') {
        raw_args_.erase(0, raw_args_.find_first_not_of(' '));
    }
}

std::string Parser::getCommand() const {
    return command_;
}

std::vector<std::string> Parser::getArguments() const {
    return arguments_;
}

std::string Parser::getRawArgs() const {
    return raw_args_;
}
