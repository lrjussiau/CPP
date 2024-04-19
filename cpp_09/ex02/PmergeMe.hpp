#ifndef PMERGEME_H
# define PMERGEME_H

#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>

class PmergeMe {

    private:

        std::list<int>      _list;
        std::vector<int>    _vector;

        int     stoi(std::string);

        void                sortVector();
        void                setVector(const std::vector<int>& v);
        std::vector<int>    getVector() const;
        std::vector<int>	mergeVector(std::vector<int> left, std::vector<int> right);
        void                insertSortedVector(std::vector<int>& vec, int value);
        int                 binarySearchInsertVector(std::vector<int>& Vec, int target);

        void                sortList();
        void                setList(const std::list<int>& l);
        std::list<int>      getList() const;
        std::list<int>      mergeList(std::list<int> left, std::list<int> right);
        void                insertSortedList(std::list<int>& lst, int value);
        int                 binarySearchInsertList(std::list<int>& lst, int target);

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