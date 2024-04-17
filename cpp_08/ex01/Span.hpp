#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <list>

class Span {

	private:

		unsigned int		_N;
		std::vector<int>	_span;

	public:

		Span(unsigned int N);
		virtual ~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);

		void 			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		template<typename InputIterator>
    	void addNumbers(InputIterator begin, InputIterator end) {
			size_t count = std::distance(begin, end);
			if (_span.size() + count > _N) {
				throw TooMuchNumber();
			}
			_span.insert(_span.end(), begin, end);
   		}

		class TooMuchNumber : public std::exception {
			public:
				virtual const char *what() const throw () {
					return ("Too much span, span is full");
				}
		};

		class TooLessNumber : public std::exception {
			public:
				virtual const char *what() const throw () {
					return ("Need at least 2 number in span");
				}
		};
};



#endif