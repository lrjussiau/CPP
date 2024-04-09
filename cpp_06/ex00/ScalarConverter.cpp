#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <sstream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void) src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) {
	(void) src;
	return *this;
}

//----------------------- Get the type of Input -----------------------------//

bool	handleCase(const std::string &number, _type type) {
	if (!number.compare("+inf") && type == _double)
		return true;
	if (!number.compare("-inf") && type == _double)
		return true;
	if (!number.compare("nan") && type == _double)
		return true;
	if (!number.compare("+inff") && type == _float)
		return true;
	if (!number.compare("-inff") && type == _float)
		return true;
	if (!number.compare("nanf") && type == _float)
		return true;
	return false;
}

bool	isInsideLimitInt(const std::string &number) {
    std::istringstream iss(number);
    double num;

    if (iss >> num) {
		if (num >= std::numeric_limits<int>::lowest() && num <= std::numeric_limits<int>::max())
        	return true;
    } else {
        std::cout << "Failed to convert the string to a double." << std::endl;
    }
	return false;
}

bool	isInsideLimitFloat(const std::string &number) {
    std::istringstream iss(number);
    double num;

    if (iss >> num) {
		if (num >= std::numeric_limits<float>::lowest() && num <= std::numeric_limits<float>::max())
        	return true;
    } else {
        std::cout << "Failed to convert the string to a double." << std::endl;
    }
	return false;
}

bool	isChar(const std::string &number) {
	if (number.length() == 1 && !isdigit(number[0]))
		return true;
	return false;
}

bool	isInt(const std::string &number) {
	unsigned int i = 0;

	if (number[0] == '-' || number[0] == '+')
		i = 1;
	for (; i < number.length(); i++) {
		if (!isdigit(number[i]))
			return false;
	}
	if (isInsideLimitInt(number))
		return true;
	return false;
}

bool	isFloat(const std::string &number) {
	unsigned int	i = 0;
	bool			isDot = false;
	bool			isF = false;	

	if (handleCase(number, _float))
		return true;
	if (number[0] == '-' || number[0] == '+')
		i = 1;
	for (; i < number.length(); i++) {
		if (number[i] == '.') {
			if (isDot) 
				return false;
			isDot = true;
			continue;
		}
		if (number[i] == 'f') {
			if (isF) 
				return false;
			isF = true;
			continue;
		}
		if (!isdigit(number[i]))
			return false;
	}
	if (isDot && isF && number[number.length() - 1] == 'f' && isInsideLimitFloat(number.substr(0, number.length() - 1)))
		return true;
	return false;
	
}

bool	isDouble(const std::string &number) {
	unsigned int	i = 0;
	bool			isDot = false;

	if (handleCase(number, _double))
		return true;
	if (number[0] == '-' || number[0] == '+')
		i = 1;
	for (; i < number.length(); i++) {
		if (number[i] == '.') {
			if (isDot) 
				return false;
			isDot = true;
			continue;
		}
		if (!isdigit(number[i]))
			return false;
	}
	if (isDot)
		return true;
	return false;
}

_type get_type(const std::string &number) {
	if (isChar(number))
		return _char;
	if (isInt(number))
		return _int;
	if (isDouble(number))
		return _double;
	if (isFloat(number))
		return _float;
	return _error;
}

//----------------------- Convert the Input ------------------------------//

void	convertChar(const std::string &number) {
	char charNum = number[0];
	std::cout << "char: '" << charNum << "'" << std::endl;
	int	intNum = static_cast<int>(charNum);
	std::cout << "int: " << intNum << std::endl;
	std::cout << "float: " << intNum << ".0f" << std::endl;
	std::cout << "double: " << intNum << ".0" << std::endl;
}

void	convertInt(const std::string &number) {
	int intNum;
    std::istringstream iss(number);

	if (iss >> intNum)
	{
		if (intNum >= 33 && intNum <= 126) {
			char charNum = static_cast<char>(intNum);
			std::cout << "char: '" << charNum << "'" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		std::cout << "int: " << intNum << std::endl;
		std::cout << "float: " << intNum << ".0f" << std::endl;
		std::cout << "double: " << intNum << ".0" << std::endl;
	}
}

void	convertDouble(const std::string &number) {
	double doubleNum;
    std::istringstream iss(number);

	if (iss >> doubleNum)
	{
		if (doubleNum >= 33 && doubleNum <= 126) {
			char charNum = static_cast<char>(doubleNum);
			std::cout << "char: '" << charNum << "'" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		if (isInsideLimitInt(number))
		{
			int intNum = static_cast<int>(doubleNum);
			std::cout << "int: " << intNum << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}
		if (isInsideLimitFloat(number))
			std::cout << "float: " << number << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << number << std::endl;
	}
}

void	convertFloat(const std::string &number) {
	float floatNum;
	std::string num = number.substr(0, number.length() - 1);
    std::istringstream iss(num);

	if (iss >> floatNum)
	{
		if (floatNum >= 33 && floatNum <= 126) {
			char charNum = static_cast<char>(floatNum);
			std::cout << "char: '" << charNum << "'" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
		if (isInsideLimitInt(num))
		{
			int intNum = static_cast<int>(floatNum);
			std::cout << "int: " << intNum << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}
		std::cout << "float: " << number << std::endl;
		std::cout << "double: " << num << std::endl;
	}
}

//----------------------- Display the Output -----------------------------//

void	ScalarConverter::convert(const std::string &number) {
	switch (get_type(number)) {
        case _char: 
			// std::cout << "Character" << std::endl;
			convertChar(number);
			break;
        case _int: 
			// std::cout << "Integer" << std::endl;
			convertInt(number);
			break;
		case _double:
			// std::cout << "Double" << std::endl;
			convertDouble(number);
			break;
        case _float:
			// std::cout << "Floating-point" << std::endl;
			convertFloat(number);
			break;
        case _error:
			std::cout << "Error or unsupported type" << std::endl;
			break;
    }
}
