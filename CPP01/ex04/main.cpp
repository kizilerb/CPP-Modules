#include "file.hpp"

int main(int argc, char **argv){
	if (argc != 4)
	{
		cout << "Invalid argument count." << endl;
		return 1;
	}
	readFile(argv[1], argv[2], argv[3]);
	return (0);
}
