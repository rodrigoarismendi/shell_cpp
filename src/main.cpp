#include <iostream>
#include <string>
#include "../include/Parser.hpp"
#include "../include/Executor.hpp"
#include "../include/Prompt.hpp"
#include "../include/History.hpp"

int main() {
  // Flush after every std::cout / std::cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  
  // Initialize modules
  Parser parser;
  Executor executor;
  Prompt prompt;
  History history;
  
  // Main shell loop
  while (true) {
    // Display prompt and read input
    prompt.display();
    std::string input = prompt.readLine();
    
    // Parse the input
    parser.parse(input);
    
    // Execute the command
    bool should_continue = executor.execute(
        parser.getCommand(),
        parser.getArguments(),
        parser.getRawArgs()
    );
    
    // Exit if requested
    if (!should_continue) {
      break;
    }
    
    // Add to history (optional, for future use)
    history.add(input);
  }
  
  return 0;
}
