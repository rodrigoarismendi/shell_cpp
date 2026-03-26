#include "../include/Prompt.hpp"
#include <iostream>

Prompt::Prompt() : prompt_symbol_("$ ") {}

void Prompt::display() const {
    std::cout << prompt_symbol_;
}

std::string Prompt::readLine() const {
    std::string line;
    std::getline(std::cin, line);
    return line;
}
