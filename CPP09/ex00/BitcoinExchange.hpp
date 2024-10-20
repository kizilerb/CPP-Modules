#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange{
	private:
		bool											emptyFile;
		std::string 									btcFile;
		std::string 									inputFile;
		std::map<std::string, double, std::greater<std::string> > 	btcDB;
		std::vector<std::pair<std::string, double> >	inputDB;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string _inputDB = "input.txt", std::string _btcDB = "data.csv");
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void readDB(std::string findString);
		void startPrint();
};
