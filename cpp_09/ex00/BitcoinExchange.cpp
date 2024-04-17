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
