#include "RPN.hpp"

int main(int ac, char* arg[]){
	if(ac != 2){
		std::cout <<  "Please enter arguments.\nExample: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
	}
	else
		startRPN(arg[1]);
	return 0;
}
