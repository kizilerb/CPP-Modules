#include "RPN.hpp"

void execNumbers(int &value1, int &value2, std::stack<int> &list){
	value1 = list.top();
	list.pop();
	value2 = list.top();
	list.pop();
}

void calculate(const int &value1, const int &value2, const char &process,std::stack<int> &list){
	switch (process)
	{
		case '+':
			list.push(value2 + value1);
			break;
		case '-':
			list.push(value2 - value1);
			break;
		case '*':
			list.push(value2 * value1);
			break;
		case '/':
			list.push(value2 / value1);
			break;
		default:
			break;
	}
}

void startRPN(std::string input){
	if(input.find('(') != std::string::npos || input.find(')') != std::string::npos)
		std::cout << "Error." << std::endl;
	else{
		std::stack<int>	numbers;
		int value1, value2;
		size_t i = 0;
		for(; i != input.length() ; i++){
			if(isdigit(input.at(i)))
				numbers.push(static_cast<int>(input.at(i)) - 48);
			else if(input.at(i) == '-' || input.at(i) == '+' || \
				input.at(i) == '*' || input.at(i) == '/'){
				if(numbers.size() < 2)
					break;
				execNumbers(value1, value2, numbers);
				calculate(value1, value2, input.at(i), numbers);
			}
			else if (input.at(i) != ' '){
				std::cout << "Invalid Input => " << input.at(i) << std::endl;
			}
		}
		if(numbers.size() == 1 && i == input.length())
			std::cout << numbers.top() << std::endl;
		else
			std::cout << "Error." << std::endl;
	}
}
