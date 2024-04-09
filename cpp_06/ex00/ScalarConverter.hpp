#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>

class ScalarConverter {

	private:

		ScalarConverter();
		virtual ~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

	public:
		static void convert(const std::string &number);
};

enum _type {
	_char,
	_int,
	_float,
	_double,
	_error
};

#endif