#ifndef PMERGEME_H
# define PMERGEME_H

#include <deque>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
#include <ctime>

class PmergeMe {

    private:

        std::deque<int>     _deque;
        double              _dequeTime;
        std::vector<int>    _vector;
        double              _vectorTime;

        int     stoi(std::string);

        void                sortVector();
        void                setVector(const std::vector<int>& v);
        std::vector<int>    getVector() const;
        std::vector<int>	mergeVector(std::vector<int> left, std::vector<int> right);
        void                insertSortedVector(std::vector<int>& vec, int value);
        int                 binarySearchInsertVector(std::vector<int>& Vec, int target);

        void                sortDeque();
        void                setDeque(const std::deque<int>& l);
        std::deque<int>     getDeque() const;
        std::deque<int>     mergeDeque(std::deque<int> left, std::deque<int> right);
        void                insertSortedDeque(std::deque<int>& lst, int value);
        int                 binarySearchInsertDeque(std::deque<int>& lst, int target);

    public:

        PmergeMe();
        virtual ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        void    inputContainer(std::string);
        void    run(void);

    class WrongInput : public std::exception {
        public:
            virtual const char *what() const throw() {
                return("Wrong input, must have sequence of positif number");
            }
    };
    class FailedConvertion : public std::exception {
        public:
            virtual const char *what() const throw() {
                return("Convertion from string to int failed");
            }
    };

    template<typename Container>
    void printElements(const Container& c) {
        typename Container::const_iterator it;
        for (it = c.begin(); it != c.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

};


#endif