#include "PmergeMe.hpp"

int main (int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "wrong input" << std::endl;
        return 1;
    }

    PmergeMe    merge;

    for (int i = 1; i < argc; i++) {
        try {
            merge.inputContainer(argv[i]);
        } catch (PmergeMe::WrongInput &e) {
            std::cout << "Exeception caught : " << e.what() << std::endl;
        } catch (PmergeMe::FailedConvertion &e) {
            std::cout << "Exeception caught : " << e.what() << std::endl;
        }
    }

    merge.run();

    
    return 0;
}