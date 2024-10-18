#include "EasyFind.hpp"
#include <vector>
#include <list>

void listExample(){
	std::list<int> test;
	std::list<int>::iterator it;

	test.push_back(16);
	test.push_back(57);
	test.push_back(5);

	try
	{
		it = ::easyFind(test, 16);
		std::cout << "Value is " << *it <<", found at index " << std::distance(test.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		it = ::easyFind(test, 15);
		std::cout << "Value is " << *it <<", found at index " << std::distance(test.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void vectorExample(){
	std::vector<int> test2 (4, 10);
	std::vector<int>::iterator it_2;

	test2.push_back(123);
	test2.push_back(9);
	test2.push_back(8);
	test2.push_back(3);
    test2.insert(test2.begin() + 1, 222);

	try
	{
		it_2 = ::easyFind(test2, 222);
		std::cout << "Value is " << *it_2 <<", found at index " << std::distance(test2.begin(), it_2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		it_2 = ::easyFind(test2, 0);
		std::cout << "Value is " << *it_2 <<", found at index " << std::distance(test2.begin(), it_2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	std::string next = "Y";
	std::string exampleQuery;
	while(next != "N"){
		std::cout << "Example : 1-> Vector 2-> List" << std::endl;
		std::cin >> exampleQuery;
		if(exampleQuery == "1")
			vectorExample();
		else if(exampleQuery == "2")
			listExample();
		std::cout << "Again? Y->Yes N->No" << std::endl;
		std::cin >> next;
	}
	return (0);
}
