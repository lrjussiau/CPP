#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {
	this->_span = std::vector<int>();
}

Span::~Span() {}
		
Span::Span(const Span &src) : _N(src._N){

}
		
Span &Span::operator=(const Span &src) {
	this->_span = src._span;
	return *this;
}


void 	Span::addNumber(int n) {
	if (_span.size() >= _N) {
		throw Span::TooMuchNumber();
	}
	else {
		_span.push_back(n);
	}
}

unsigned int		Span::shortestSpan() {
	if (_span.size() < 2) {
		throw Span::TooLessNumber();
	}
	int diff = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < _span.size() - 1; i++) {
		int temp_diff = std::abs(_span[i + 1] - _span[i]);
		if (temp_diff < diff)
			diff = temp_diff;
	}
	return (diff);
}
		
unsigned int		Span::longestSpan() {
	if (_span.size() < 2) {
		throw Span::TooLessNumber();
	}
	std::vector<int>::iterator smallest = std::min_element(_span.begin(), _span.end());
	std::vector<int>::iterator largest = std::max_element(_span.begin(), _span.end());
		
	unsigned int	diff = *largest - *smallest;
	return (diff);
}