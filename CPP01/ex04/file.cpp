#include "file.hpp"

static int fileErr(){
	cout << "File opening error." << endl;
	return -1;
}

int readFile(string file, string s1, string s2){
	std::ifstream inputf;
	std::ofstream outputf;
	size_t index;
	string str;

	inputf.open(file);
	if (!inputf.is_open())
		return(fileErr());

	outputf.open(file.append(".replace"));
	if (!outputf.is_open())
		return(fileErr());

	while(std::getline(inputf, str)){
		while(index = str.find(s1), index != std::string::npos)
		{
			str.erase(index, s1.length());
			str.insert(index, s2);
		}
		outputf << str << endl;
	}

	inputf.close();
	outputf.close();
	return 0;
}
