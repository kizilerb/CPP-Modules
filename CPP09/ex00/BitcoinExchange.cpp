#include "BitcoinExchange.hpp"

 BitcoinExchange::BitcoinExchange():  btcFile("data.csv"), inputFile("input.txt"){
	std::cout << "Default Constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string _inputFile, std::string _btcFile)
	: btcFile(_btcFile), inputFile(_inputFile){
		std::cout << "Constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
	:btcFile(copy.btcFile), inputFile(copy.inputFile), btcDB(copy.btcDB), inputDB(copy.inputDB){
		std::cout << "Copy Constructor is called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
	if(this == &copy)
		return *this;
	this->btcDB.clear();
	this->inputDB.clear();
	this->btcDB = copy.btcDB;
	this->inputDB = copy.inputDB;
	this->btcFile = copy.btcFile;
	this->inputFile = copy.inputFile;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "Destructor is called" << std::endl;
}

bool BitcoinExchange::getEmptyFile(){
	return this->emptyFile;
}

bool anyLetter(std::string str){
	if (std::count(str.begin(), str.end(), 'f') > 1 || std::count(str.begin(), str.end(), '.') > 1)
		return false;
    for (size_t i = 0; i < str.size(); ++i) {
		if(i == 0 && (str[i] == ' '))
			i++;
		if(i == 1 && (str[i] == '+' || str[i] == '-'))
			i++;
		if (str.length() - 1 == i && str[i] == 'f' && std::isdigit(str[i - 1]))
			continue;
		else if(!str.find('.') && !std::isdigit(str[i]))
			return false;
		else if (str.find('.') && (str[i] != '.' && !std::isdigit(str[i])))
			return false;
	}
	return true;
}

void BitcoinExchange::readDB(std::string findString){
	std::ifstream readFile;
	if(findString == ",")
		readFile.open(this->btcFile);
	else
		readFile.open(this->inputFile);
	if(!readFile.is_open())
		std::cerr << "File could not be opened" << std::endl;

	std::string line, tempPrice, date;
	int 		pos;
	double 		price;
	std::getline(readFile, line);
	if(findString == "|" && line != std::string("date | value")){
		std::cerr << " Error: input file first line is wrong, format: date | value" << std::endl;
	}
	while(std::getline(readFile, line)){
		pos = line.find(findString);
		if(findString == "|" && pos == -1){
			this->inputDB.push_back(std::pair<std::string, double>(line + " bad", -1001));
			continue;
		}
		else if(pos == -1)
			continue;
		date = line.substr(0, pos);
		tempPrice = line.substr(pos + 1);
		if(!anyLetter(tempPrice))
			price = -1001;
		else
			price = std::strtod(tempPrice.c_str(), nullptr);
		if(findString == ",")
			this->btcDB.insert(btcDB.begin() , std::pair<std::string, double>(date, price));
		else{
			date = date.substr(0,date.size() - 1);
			this->inputDB.push_back(std::pair<std::string, double>(date, price));
		}
	}
	if(findString == "|" && this->inputDB.size() == 0)
		this->emptyFile = 1;
	readFile.close();
}
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
