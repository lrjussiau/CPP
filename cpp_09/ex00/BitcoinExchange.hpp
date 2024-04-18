#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:

		std::map<std::string, std::string>	_data;
		std::map<std::string, std::string>	_str;
		std::ifstream 		open(std::string);
		void				getData(void);
		bool				checkFile(std::string);
		bool				checkDateFormat(std::string);
		bool				checkValue(std::string);
		void				parsingLine(std::string);
		std::string			getKey(std::map<std::string, std::string> map);
		std::string			getValue(std::map<std::string, std::string> map);
		void				processLine(void);

	public:
		BitcoinExchange();
		virtual ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void	run(std::string);


	class WrongInput : public std::exception {
		public:
			virtual const char *what() const throw () {
				return ("Wrong Input, please enter ./btc \"file\"");
			}
	};
	class WrongFormat : public std::exception {
		public:
			virtual const char *what() const throw () {
				return ("Wrong Format, the file must have a format Date | Value");
			}
	};
	class WrongDateFormat : public std::exception {
		public:
			virtual const char *what() const throw () {
				return ("Wrong Date Format, must have YYYY-MM-DD format and follow the rule of years months days");
			}
	};
	class WrongStringFormat : public std::exception {
		public:
			virtual const char *what() const throw () {
				return ("Wrong String Format, must have '|' to separate date and value");
			}
	};
	class WrongDate : public std::exception {
		public:
			virtual const char *what() const throw () {
				return ("Wrong Date, the Year must be beetween 2009 and 2024");
			}
	};
	class WrongValue : public std::exception {
		public:
			virtual const char *what() const throw () {
				return ("Wrong Value, the value must be between 0 and 1000");
			}
	};
};


#endif