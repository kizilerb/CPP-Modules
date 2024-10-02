#include "MutantStack.hpp"
#include <sstream>

void defaultExample()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout <<"Top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack Size : " <<  mstack.size() << std::endl;
    mstack.push(3); 
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
}

void listExample()
{
    MutantStack <int, std::list<int> > mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout <<"Top : " << *std::prev(mstack.end()) << std::endl;
    mstack.pop();
    std::cout << "Stack Size : " <<  mstack.size() << std::endl;
    mstack.push(3); 
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
}

void vectorExample()
{
    std::vector<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout <<"Top : " << *std::prev(mstack.end()) << std::endl;
    mstack.pop_back();
    std::cout << "Stack Size : " <<  mstack.size() << std::endl;
    mstack.push_back(3); 
    mstack.push_back(5);
    mstack.push_back(737);
    std::vector<int>::iterator it = mstack.begin();
    std::vector<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
}

int main()
{
	std::string next = "Y"; 
	std::string exampleQuery;
	while(next != "N"){
		std::cout << "Example : 1-> Default(Deque) 2-> Vector 3-> List" << std::endl;
        std::cout << "Which one do you want? = ";
		std::cin >> exampleQuery;
        std::istringstream iss(exampleQuery);
        int examp;
        iss >>examp;
        switch (examp)
        {
            case 1:
                defaultExample();
                break;
            case 2:
                vectorExample();
                break;
            case 3:
                listExample();
                break;
            default:
                std::cout << "Invalid Input!" << std::endl;
                return 1;
                break;
        }
		std::cout << "Again? Y->Yes N->No" << std::endl;
        std::cout << "Next ? = ";
		std::cin >> next;
	}
	return (0);
}