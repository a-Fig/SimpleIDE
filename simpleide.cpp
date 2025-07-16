#include <iostream>
#include <string>
#include <cstdlib>

const char* ANSI_GREEN = "\033[92m";
const char* ANSI_RED = "\033[91m";
const char* ANSI_RESET = "\033[0m";

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <source.cpp> [-o output] [-r]\n";
        return 1;
    }

    std::string source = argv[1];
    std::string output = "a.out";
    bool run = false;

    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-o" || arg == "--output") && i + 1 < argc) {
            output = argv[++i];
        } else if (arg == "-r" || arg == "--run") {
            run = true;
        } else {
            std::cerr << "Unknown argument: " << arg << '\n';
            return 1;
        }
    }

    std::string compileCmd = "g++ " + source + " -o " + output;
    std::cout << "Compiling " << source << " -> " << output << "..." << std::endl;
    int ret = std::system(compileCmd.c_str());
    if (ret != 0) {
        std::cerr << ANSI_RED << "Compilation failed." << ANSI_RESET << std::endl;
        return ret;
    }
    std::cout << ANSI_GREEN << "Compilation succeeded." << ANSI_RESET << std::endl;

    if (run) {
        std::cout << "Running " << output << "..." << std::endl;
        std::string runCmd = "./" + output;
        return std::system(runCmd.c_str());
    }

    return 0;
}
