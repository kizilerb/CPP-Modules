#include <iostream>

int main(int argc, char **argv){
	if(argc < 2)
	{
		std::cout << "Enter at least one argument" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++){
		for(int j = 0; argv[i][j]; j++)
			std::cout<< char(toupper(argv[i][j]));
		if (i != argc - 1)
			std::cout << " ";
	}
	return (0);
}
