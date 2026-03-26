#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>

class Prompt {
public:
    Prompt();
    
    // Display the prompt
    void display() const;
    
    // Read a line of input from the user
    std::string readLine() const;

private:
    std::string prompt_symbol_;
};

#endif // PROMPT_HPP
