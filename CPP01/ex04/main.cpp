#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv){
	string file;
	string s1;
	string s2;
	if (argc != 4)
	{
		cout << "Invalid argument count." << endl;
		return 1;
	}
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
}
