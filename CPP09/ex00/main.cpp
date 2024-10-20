#include "BitcoinExchange.hpp"

int main(int ac, char *argv[]){
	if(ac != 2){
		std::cerr << "Error: Usage " << argv[0] << " <inputDB file>" << std::endl;
		return 1;
	}
	else{
		BitcoinExchange btc(argv[1]);
		btc.readDB(",");
		btc.readDB("|");
		std::cout << "----------------------------------------------------------------" << std::endl;
		btc.startPrint();
		std::cout << "----------------------------------------------------------------" << std::endl;
		return 0;
	}
}
