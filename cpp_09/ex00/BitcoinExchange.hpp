#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:

		std::map<std::string, std::string>	_data;

	public:
		BitcoinExchange();
		virtual ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void	run(std::string);

	//Wrong input
	//Wrong format (not Date | Value)
	//Wrong date_format (day > 30 month > 12)
	//Wrong Date (too early/late) ??
	//Wrong Value (must be : 0 < value < 1000)
};


#endif