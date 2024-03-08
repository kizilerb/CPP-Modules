#include "Phonebook.hpp"

int	main(void)
{
	Phonebook 	ph;
	std::string	str;

	while (!std::cin.eof())
	{
		if(str == "EXIT")
			return (0);
		std::cout << "Enter a command [ ADD | SEARCH | EXIT ] > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			ph.ADD();
		else if (str == "SEARCH")
			ph.SEARCH();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
