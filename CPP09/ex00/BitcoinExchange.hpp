#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

class BitcoinExchange{
	private:
		bool											emptyFile;
		std::string 									btcFile;
		std::string 									inputFile;
		std::map<std::string, double> 					btcDB;
		std::vector<std::pair<std::string, double> >	inputDB;
	public:
		BitcoinExchange(std::string _inputDB = "input.txt", std::string _btcDB = "data.csv");
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void readDB(std::string findString);
		void startPrint();
};
