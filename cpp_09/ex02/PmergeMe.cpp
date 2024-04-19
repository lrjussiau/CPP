#include "PmergeMe.hpp"
/*
Ford Johnson

3 step:

1 - Divide the list half and half
	- Preaty easy 2 container temp
	- Merge on the final container ??

2 - Sort Each half
	- Continue to subdivide the list recursivelly until have only 1 or 2 item in each list
	- Sorting them 

3 - Merge with strategy
	- Merge them efficiently with binary insertion
		- find wich part of the list to search etc..until find the right position
		- Merge all the small part each other until every part is united.

*/

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	(void) src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	(void) src;
	return *this;
}

//---------------------------------------//
//               Parsing                 //
//---------------------------------------//

int		PmergeMe::stoi(std::string str) {
	for (int i = 0; i < static_cast<int>(str.size()); i++) {
		if (!isdigit(str[i]))
			throw WrongInput();
	}
	std::istringstream iss(str);
	int n;
	if (iss >> n) {
		return n;
    } else {
        throw FailedConvertion();
    }
	return (0);
}

void    PmergeMe::inputContainer(std::string str) {
	int n = stoi(str);
	if (n < 0)
		throw WrongInput();
	_list.push_back(n);
	_vector.push_back(n);
}

//---------------------------------------//
//            Sorting Vector             //
//---------------------------------------//

void	PmergeMe::setVector(const std::vector<int>& v) { 
	_vector = v; 
}

std::vector<int>    PmergeMe::getVector() const {
	return _vector;
}

int PmergeMe::binarySearchInsertVector(std::vector<int>& Vec, int target) {
    int low = 0;
    int high = Vec.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (Vec[mid] < target) {
            low = mid + 1;
        } else if (Vec[mid] > target) {
            high = mid - 1;
        } else {
            return mid + 1;
        }
    }
    return low;
}

void PmergeMe::insertSortedVector(std::vector<int>& vec, int value) {
    int index = binarySearchInsertVector(vec, value);
    vec.insert(vec.begin() + index, value);
}

std::vector<int>	PmergeMe::mergeVector(std::vector<int> left, std::vector<int> right) {
	for (int i = 0; i < static_cast<int>(right.size()); i++) {
		insertSortedVector(left, right[i]);
	}
	return (left);
}

void	PmergeMe::sortVector(void) {
	if (_vector.size() <= 1)
		return;
	
	if (_vector.size() == 2) {
		if (_vector[0] > _vector[1])
			std::swap(_vector[0], _vector[1]);
		return;
	}

	size_t mid = _vector.size() / 2;
    std::vector<int> left(_vector.begin(), _vector.begin() + mid);
    std::vector<int> right(_vector.begin() + mid, _vector.end());

	PmergeMe 	leftPart;
	PmergeMe	rightPart;
	leftPart.setVector(left);
	rightPart.setVector(right);

	leftPart.sortVector();
	rightPart.sortVector();

	_vector = mergeVector(leftPart.getVector(), rightPart.getVector());
}

//---------------------------------------//
//             Sorting list              //
//---------------------------------------//

void	PmergeMe::setList(const std::list<int>& l) { 
	_list = l; 
}

std::list<int>    PmergeMe::getList() const {
	return _list;
}

int PmergeMe::binarySearchInsertList(std::list<int>& lst, int target) {
    int low = 0;
    int high = lst.size() - 1;
    int mid;
	std::list<int>::iterator it = lst.begin();

    while (low <= high) {
        mid = (low + (high - low) / 2);
		std::advance(it, mid);
        if (*it < target) {
            low = mid + 1;
        } else if (*it > target) {
            high = mid - 1;
        } else {
			std::cout << target << " lol " << std::endl;
            return mid + 1;
        }
    }
	std::cout << target << " : " << low << std::endl;
    return low;
}

void PmergeMe::insertSortedList(std::list<int>& lst, int value) {
    int index = binarySearchInsertList(lst, value);
	std::list<int>::iterator it = lst.begin();
	std::advance(it, index);
    lst.insert(it, value);
}

std::list<int>	PmergeMe::mergeList(std::list<int> left, std::list<int> right) {
	std::list<int>::iterator it = right.begin();
	printElements(left);
	printElements(right);
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(right.size()); i++) {
		std::cout << right.size() << std::endl;
		insertSortedList(left, *it);
		std::advance(it, 1);
	}
	printElements(left);
	std::cout << std::endl;
	std::cout << std::endl;
	return (left);
}

void	PmergeMe::sortList(void) {
	if (_list.size() <= 1)
		return;
	
	if (_list.size() == 2) {
		if (_list.front() > _list.back())
			std::swap(_list.front(), _list.back());
		return;
	}

	std::list<int>::iterator it = _list.begin();
	std::advance(it, _list.size() / 2);

    std::list<int> left(_list.begin(), it);
    std::list<int> right(it, _list.end());

	PmergeMe 	leftPart;
	PmergeMe	rightPart;
	leftPart.setList(left);
	rightPart.setList(right);

	leftPart.sortList();
	rightPart.sortList();

	_list = mergeList(leftPart.getList(), rightPart.getList());
}

//---------------------------------------//
//             Run Function              //
//---------------------------------------//

void	PmergeMe::run(void) {
	std::cout << "--- Vector ---" << std::endl;
	std::cout << "Before : ";
	printElements(_vector);
	sortVector();
	std::cout << "After : ";
	printElements(_vector);

	std::cout << "--- List ---" << std::endl;
	std::cout << "Before : ";
	printElements(_list);
	sortList();
	std::cout << "After : ";
	printElements(_list);
}