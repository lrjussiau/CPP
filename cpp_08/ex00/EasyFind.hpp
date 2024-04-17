#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        std::cout << "No occurrence found in the container" << std::endl;
    return it;
}

#endif