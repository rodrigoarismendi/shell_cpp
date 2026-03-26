#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

class Parser {
public:
    Parser();
    
    // Parse a command line into command and arguments
    void parse(const std::string& input);
    
    // Get the parsed command
    std::string getCommand() const;
    
    // Get all arguments (excluding the command)
    std::vector<std::string> getArguments() const;
    
    // Get the raw argument string (useful for echo)
    std::string getRawArgs() const;

private:
    std::string command_;
    std::vector<std::string> arguments_;
    std::string raw_args_;
};

#endif // PARSER_HPP
