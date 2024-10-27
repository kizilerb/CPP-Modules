#include "BitcoinExchange.hpp"

static bool isValidDate(const std::string& dateStr) {
	if (dateStr.size() != 10)
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            if (dateStr[i] != '-')
                return false;
        } else {
            if (!isdigit(dateStr[i]))
                return false;
        }
    }

    int year, month, day;
    std::istringstream iss(dateStr.substr(0, 4));
    iss >> year;
    std::istringstream iss2(dateStr.substr(5, 2));
    iss2 >> month;
    std::istringstream iss3(dateStr.substr(8, 2));
    iss3 >> day;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
	else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }
    return true;
}

void BitcoinExchange::startPrint(){
	std::vector<std::pair<std::string, double> >::iterator it;
	std::map<std::string, double>::iterator itMap;
	for(it = this->inputDB.begin(); it != this->inputDB.end(); it++){
		if(!isValidDate(it->first)){
			if(it->first.find("bad"))
				std::cerr << "Error: bad input => " << it->first.substr(0, it->first.find("bad")) << std::endl;
			else
				std::cerr << "Error: bad input => " << it->first << std::endl;
			continue;
		}
		else if(it->second < 0 || it->second > 1000){
            if(it->second == -1001)
				std::cerr << "Error: not a valid price." << std::endl;
			else if(it->second < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (it->second > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		itMap = this->btcDB.lower_bound(it->first);
		if(itMap != this->btcDB.end())
			std::cout << it->first <<  " => " << it->second << " = " << itMap->second * it->second << std::endl;
		else
			std::cout << "Lower bound for key " << it->first << " not found." << std::endl;
	}
}
