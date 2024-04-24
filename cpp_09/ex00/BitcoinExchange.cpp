#include "BitcoinExchange.hpp"

//-----Program-----//

// Open file
// Check format file if (date|value)
// While eof
	// get the line with the first date
	// Trim space
	// check format line (YYYY-MM-DD) + Check if year month day is ok + check value inside 0 - 1000
	// assign _data <date, value>
	// start comparing with csv
		// Find the ocurence, if not existing take the upper one
		// print std::cout date << " => " << value << " = " << value * value csv
	// look for the next line

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	(void)src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	(void)src;
	return *this;
}

//---------------------------------------//
//              Open File                //
//---------------------------------------//

bool BitcoinExchange::checkFile(std::string firstString) {
	if (firstString.compare("date | value")) {
		return false;
	}
	return true;
}

void	BitcoinExchange::getData(void) {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw BitcoinExchange::WrongInput();
	}
	std::string 		line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t separatorPos = line.find(",");
		std::string date = line.substr(0, separatorPos);
		std::string value = line.substr(separatorPos + 1, std::string::npos);
		_data[date]=value;
	}
}

//---------------------------------------//
//             Parsing Line              //
//---------------------------------------//

int		BitcoinExchange::stoi(std::string str) {
	std::istringstream iss(str);
	int	strInt;
	if (iss >> strInt) {
		return strInt;
	}
	throw BitcoinExchange::FailedConvert();
	return 0;
}

bool	BitcoinExchange::checkDateFormat(std::string date) {
	size_t separatorPos = date.find("-");
	size_t secondSeparatorPos = date.rfind("-");

	if (separatorPos == std::string::npos || secondSeparatorPos == std::string::npos || separatorPos == secondSeparatorPos)
        return false;

	std::string year = date.substr(0, separatorPos);
	std::string month = date.substr(separatorPos + 1, secondSeparatorPos - separatorPos - 1);
	std::string day = date.substr(secondSeparatorPos + 1, std::string::npos);

	if (year.empty() || month.empty() || day.empty())
		return false;
	if (year.size() != 4 && month.size() != 2 && day.size() != 2)
		return false;

    int yearInt = stoi(year);
	int monthInt = stoi(month);
	int dayInt = stoi(day);

	if (yearInt < 2009 || yearInt > 2024)
		throw BitcoinExchange::WrongDate();
	if (monthInt < 1 || monthInt > 12)
		return false;

	if ((monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7 || monthInt == 8 || monthInt == 10 || monthInt == 12) && (dayInt < 1 || dayInt > 31))
		return false;
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && (dayInt < 1 || dayInt > 30))
		return false;
	if ((monthInt == 2) && (dayInt < 1 || dayInt > 29))
		return false;

	return true;
}

bool	BitcoinExchange::checkValue(std::string value) {
	std::istringstream isb(value);
	float valueInt;
	if (isb >> valueInt) {
		if (valueInt < 0 || valueInt > 1000)
			return false;
    } else {
        return false;
    }
	return true;
}

void	BitcoinExchange::parsingLine(std::string line) {
	size_t separatorPos = line.find(" | ");
    if (separatorPos == std::string::npos) {
        throw WrongStringFormat();
    }
    std::string date = line.substr(0, separatorPos);
	if (!checkDateFormat(date)) {
		throw WrongDateFormat();
	}
	std::string value = line.substr(separatorPos + 3, std::string::npos);
	if (!checkValue(value)) {
		throw WrongValue();
	}
	_str[date]=value;
}

//---------------------------------------//
//              Process Line             //
//---------------------------------------//

std::string BitcoinExchange::getKey(std::map<std::string, std::string> map) {
	std::map<std::string, std::string>::iterator it = map.begin();
	return it->first;
}

std::string BitcoinExchange::getValue(std::map<std::string, std::string> map) {
	std::map<std::string, std::string>::iterator it = map.begin();
	return it->second;
}

void	BitcoinExchange::processLine(void) {
	std::string searchKey = getKey(_str);
	std::map<std::string, std::string>::iterator it = _data.upper_bound(searchKey);
    if (it != _data.begin()) {
        --it;
		std::istringstream iss(it->second);
		float searchValue;
		iss >> searchValue;
		std::istringstream isf(getValue(_str));
		float strValue;
		isf >> strValue;
		std::cout << searchKey << " => " << strValue << " = " << strValue * searchValue << std::endl;
    } else {
        std::cout << "No earlier date found in the data." << std::endl;
    }
	_str.clear();
}

//---------------------------------------//
//             Run Function              //
//---------------------------------------//

void	BitcoinExchange::run(std::string input) {
	try {
		std::ifstream file(input);
		if (!file.is_open()) {
			throw BitcoinExchange::WrongInput();
		}
		std::string 		line;
		std::getline(file, line);
		if (!BitcoinExchange::checkFile(line)) {
			throw BitcoinExchange::WrongFormat();
		}
		getData();
		while (std::getline(file, line)) {
			try {
				parsingLine(line);
				processLine();
			} catch (WrongStringFormat &e) {
				std::cerr << "Exception caught: " << e.what() << std::endl;
			} catch (WrongDateFormat &e) {
				std::cerr << "Exception caught: " << e.what() << std::endl;
			} catch (WrongDate &e) {
				std::cerr << "Exception caught: " << e.what() << std::endl;
			} catch (WrongValue &e) {
				std::cerr << "Exception caught: " << e.what() << std::endl;
			} catch (FailedConvert &e) {
				std::cerr << "Exception caught: " << e.what() << std::endl;
			}
		}
	} catch (WrongInput &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}  catch (WrongFormat &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
