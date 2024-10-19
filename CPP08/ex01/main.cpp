#include "Span.hpp"
#define MAX_VAL 10001

int main(){
	Span sp = Span(5);
	sp.addNumber(-6);
	sp.addNumber(-3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printSpan();
	std::cout << "Shortest span is : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is : "<< sp.longestSpan() << std::endl;
	//SCOPE
	{
		std::cout << "\n---addnumbers section---" << std::endl;
		srand(time(NULL));
		std::vector<int> myVector;
		Span sp2 = Span(20);
		sp2.addNumber(6);
		sp2.addNumber(3);
		sp2.addNumber(17);
		sp2.addNumber(9);
		sp2.addNumber(11);
		int value;
		for(int i = 0; i < 15; i++){
			value = rand() % 100;
			myVector.push_back(value);
		}
		sp2.addNumbers(myVector);
		sp2.printSpan();
		std::cout << "Shortest span is : " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span is : "<< sp2.longestSpan() << std::endl;
	}
	//SCOPE
	{
		std::cout << "\n---10000 numbers adding section---" << std::endl;
		Span sp = Span(MAX_VAL);
		for(int i = 0; i < MAX_VAL; i++)
			sp.addNumber(i);
		std::cout << "Shortest span is : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is : "<< sp.longestSpan() << std::endl;
	}
	return 0;
}
