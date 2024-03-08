#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(){
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;
	cout << "The memory address of the string variable: " << &str << endl;
	cout << "The memory address held by stringPTR: " << &stringPTR << endl;
	cout << "The memory address held by stringREF: " << &stringREF << endl;
	cout << "The value of the string variable: " << str << endl;
	cout << "The value pointed to by stringPTR: " << *stringPTR << endl;
	cout << "The value pointed to by stringREF: " << stringREF << endl;
}
