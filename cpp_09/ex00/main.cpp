#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "wrong input" << std::endl;
        return 1;
    }
    BitcoinExchange btc;

    btc.run(argv[1]);
    return 0;
}