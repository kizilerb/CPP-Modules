#include "BitcoinExchange.hpp"
bool anyLetter(std::string str){
    for (size_t i = 0; i < str.size(); ++i) {
		if(i == 0 && (str[i] == ' '))
			i++;
		if(i == 1 && (str[i] == '+' || str[i] == '-'))
			i++;
		if(!str.find('.') && !std::isdigit(str[i]))
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
		std::istringstream iss(tempPrice); // price isdigit
		iss >> price;
		if(!anyLetter(tempPrice))
			price = -1001;
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
