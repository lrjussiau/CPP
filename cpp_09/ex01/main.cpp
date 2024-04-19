#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "wrong input" << std::endl;
        return 1;
    }
    RPN go;
    
    go.run(argv[1]);
    return 0;
}