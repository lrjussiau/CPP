#include "EasyFind.hpp"

int main() {
    int vecArr[] = {1, 2, 3, 6, 5, 3, 4};
    std::vector<int> vec(vecArr, vecArr + sizeof(vecArr) / sizeof(vecArr[0]));

    int lstArr[] = {6, 7, 8, 9, 10};
    std::list<int> lst(lstArr, lstArr + sizeof(lstArr) / sizeof(lstArr[0]));

	int arrArr[] = {11, 7, 8, 22, 10};
    std::deque<int> arr(arrArr, arrArr + sizeof(arrArr) / sizeof(arrArr[0]));


    std::vector<int>::iterator vecIt = easyfind(vec, 3);
    if (vecIt != vec.end()) {
        std::cout << "Found in vector: " << *vecIt << std::endl;
		std::cout << "Next in the array: " << *(vecIt + 1) << std::endl;
    }

	std::deque<int>::iterator arrIt = easyfind(arr, 22);
    if (arrIt != arr.end()) {
        std::cout << "Found in Deque: " << *arrIt << std::endl;
		std::cout << "Next in the array: " << *(arrIt + 1) << std::endl;
    }

    std::list<int>::iterator lstIt = easyfind(lst, 8);
    if (lstIt != lst.end()) {
        std::cout << "Found in list: " << *lstIt << std::endl;
		// std::cout << "Next in the array: " << *(lstIt + 1) << std::endl;
    }

    std::vector<int>::iterator notFound = easyfind(vec, 10);
    if (notFound != vec.end()) {
        std::cout << "Found in list: " << *lstIt << std::endl;
	}

    return 0;
}