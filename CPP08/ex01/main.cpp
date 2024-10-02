#include "Span.hpp"

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

	{
		srand(time(NULL));
		std::vector<int> myVector;
		Span sp2 = Span(20);
		sp2.addNumber(6);
		sp2.addNumber(3);
		sp2.addNumber(17);
		sp2.addNumber(9);
		sp2.addNumber(11);
		int rnd;
		for(int i = 0; i < 15; i++){
			rnd = rand() % 100;
			myVector.push_back(rnd);
		}
		sp2.addNumbers(myVector);
		sp2.printSpan();
		std::cout << "Shortest span is : " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span is : "<< sp2.longestSpan() << std::endl;
	}

	return 0;
}