#include "PmergeMe.hpp"

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
	_deque.push_back(n);
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
//             Sorting deque             //
//---------------------------------------//

void	PmergeMe::setDeque(const std::deque<int>& v) { 
	_deque = v; 
}

std::deque<int>    PmergeMe::getDeque() const {
	return _deque;
}

int PmergeMe::binarySearchInsertDeque(std::deque<int>& Vec, int target) {
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

void PmergeMe::insertSortedDeque(std::deque<int>& vec, int value) {
    int index = binarySearchInsertDeque(vec, value);
    vec.insert(vec.begin() + index, value);
}

std::deque<int>	PmergeMe::mergeDeque(std::deque<int> left, std::deque<int> right) {
	for (int i = 0; i < static_cast<int>(right.size()); i++) {
		insertSortedDeque(left, right[i]);
	}
	return (left);
}

void	PmergeMe::sortDeque(void) {
	if (_deque.size() <= 1)
		return;
	
	if (_deque.size() == 2) {
		if (_deque[0] > _deque[1])
			std::swap(_deque[0], _deque[1]);
		return;
	}

	size_t mid = _deque.size() / 2;
    std::deque<int> left(_deque.begin(), _deque.begin() + mid);
    std::deque<int> right(_deque.begin() + mid, _deque.end());

	PmergeMe 	leftPart;
	PmergeMe	rightPart;
	leftPart.setDeque(left);
	rightPart.setDeque(right);

	leftPart.sortDeque();
	rightPart.sortDeque();

	_deque = mergeDeque(leftPart.getDeque(), rightPart.getDeque());
}

//---------------------------------------//
//             Run Function              //
//---------------------------------------//

void	PmergeMe::run(void) {
	std::cout << "--- Vector ---" << std::endl;
	std::cout << "Before : ";
	printElements(_vector);
	clock_t start = clock();
	sortVector();
	clock_t end = clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 10000000;
	std::cout << "After : ";
	printElements(_vector);

	std::cout << "--- Deque ---" << std::endl;
	std::cout << "Before : ";
	printElements(_deque);
	clock_t start1 = clock();
	sortDeque();
	clock_t end1 = clock();
	_dequeTime = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 10000000;
	std::cout << "After : ";
	printElements(_deque);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}