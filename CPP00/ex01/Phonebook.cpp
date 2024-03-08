#include "Phonebook.hpp"

void Phonebook::ADD(){
	static int i = 0;
	std::string str;
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, str);
		if (str != "")
		{
			ContactList[i].SetFirstName(str);
			str = "";
			break;
		}
	}

	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, str);
		if (str != "")
		{
			ContactList[i].SetLastName(str);
			str = "";
			break;
		}
	}

	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, str);
		if (str != "")
		{
			ContactList[i].SetPhoneNumber(str);
			str = "";
			break;
		}
	}

	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter  Darkest Secret: ";
		std::getline(std::cin, str);
		if (str != "")
		{
			ContactList[i].SetDarkestSecret(str);
			str = "";
			break;
		}
	}

	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter NickName: ";
		std::getline(std::cin, str);
		if (str != "")
		{
			ContactList[i].SetNickName(str);
			str = "";
			break;
		}
	}
	if (++i % 8 == 0)
		i = 0;
}

void Phonebook::SEARCH(){
	int i;
	std::string str = "";
	if (this->ContactList[0].GetContact("FirstName").empty())
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	this->PrintTable();
	std::cout << "Please enter an index between 1 - 8: ";
	std::getline(std::cin, str);
	if (!std::cin.eof() && str != "")
	{
		for ( unsigned long i = 0; i < str.size(); i++)
		{
			if (std::isalpha(str[i])) // sorun olabilir.
			{
				std::cout << "Invalid input. Index must contain only numbers." << std::endl;
				return ;
			}
		}
		i = std::stoi(str);
		if (!(i >= 1 && i <= 8))
		{
			std::cout << "Invalid index. It is not in the specified interval." << std::endl;
			return ;
		}
		if (this->ContactList[--i].GetContact("FirstName").empty())
		{
			std::cout << "Index " << i + 1 << " is not filled yet." << std::endl;
			return ;
		}
		
		std::cout << "First Name : " << ContactList[i].GetContact("FirstName") << std::endl;
		std::cout << "Last Name : " << ContactList[i].GetContact("LastName") << std::endl;
		std::cout << "Phone Number : " << ContactList[i].GetContact("PhoneNumber") << std::endl;
		std::cout << "Darkest Secret : " << ContactList[i].GetContact("DarkestSecret") << std::endl;
		std::cout << "NickName : " << ContactList[i].GetContact("NickName") << std::endl;
	}

}

static std::string SetString(std::string str)
{
	unsigned long max = 10;
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

void Phonebook::PrintTable()
{
	for(int i = 0; i < 8 ; i++){
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << SetString(ContactList[i].GetContact("FirstName"));
		std::cout << "|" << std::setw(10) << SetString(ContactList[i].GetContact("LastName"));
		std::cout << "|" << std::setw(10) << SetString(ContactList[i].GetContact("NickName")) << "|" << std::endl;
	}
}
