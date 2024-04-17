#include "Span.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << " Case too much N inside span" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	{
		Span sp(3);
		try {
			sp.addNumber(11);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
		} catch (const Span::TooMuchNumber& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		} catch (const Span::TooLessNumber& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << " Case too less N inside span" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	{
		Span sp(3);
		try {
			sp.addNumber(11);
			sp.longestSpan();
		} catch (const Span::TooMuchNumber& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		} catch (const Span::TooLessNumber& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << " Case everythink work as execpted" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	{
		Span sp(5);
		try {
			sp.addNumber(11);
			sp.addNumber(15);
			sp.addNumber(-1);
			sp.addNumber(2);
			sp.addNumber(3);
			std::cout << "Longest span : " << sp.longestSpan() << std::endl;
			std::cout << "Smallest span : " << sp.shortestSpan() << std::endl;
		} catch (const Span::TooMuchNumber& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		} catch (const Span::TooLessNumber& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << " Case insert a range iterator" << std::endl;
	std::cout << "------------------------------" << std::endl;
	{
		Span sp(10);
		std::vector<int> initialNumbers = std::vector<int>();  // Can add Vector
			initialNumbers.push_back(2);
			initialNumbers.push_back(9);
			initialNumbers.push_back(4);
		std::list<int> listNumbers = std::list<int>(); // But also list with the template.
			listNumbers.push_back(1);
			listNumbers.push_back(3);
			listNumbers.push_back(5);
			listNumbers.push_back(6);
			listNumbers.push_back(8);
		try {
			sp.addNumbers(initialNumbers.begin(), initialNumbers.end());
			sp.addNumbers(listNumbers.begin(), listNumbers.end());
			// sp.addNumbers(initialNumbers, initialNumbers + sizeof(initialNumbers) / sizeof(int));
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const Span::TooMuchNumber& e) {
			std::cerr << "Exception caught: " << e.what() << '\n';
		}
	}

    return 0;
}