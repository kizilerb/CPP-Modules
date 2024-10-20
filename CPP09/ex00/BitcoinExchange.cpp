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
