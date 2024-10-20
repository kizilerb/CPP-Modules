#include "BitcoinExchange.hpp"


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
		std::istringstream iss(tempPrice.c_str());
		iss >> price;
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
