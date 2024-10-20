#include "PmergeMe.hpp"

const char* InvalidArgument::what() const throw(){
	return "Invalid argument: not a number";
}

bool anyLetter(std::string input){
	for (size_t i = 0; i < input.size(); ++i) {
		if(i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}
