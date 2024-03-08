#include "Phonebook.hpp"

std::string Contact::GetContact(std::string input) const{
    if(input == "FirstName")
        return this->FirstName;
    else if(input == "LastName")
        return this->LastName;
    else if(input == "PhoneNumber")
        return this->PhoneNumber ;
    else if(input == "NickName")
        return this->NickName;
    else if(input == "DarkestSecret")
        return this->DarkestSecret;
    else
        return NULL;
}

void Contact::SetFirstName(std::string input) {
    this->FirstName = input;
}

void Contact::SetLastName(std::string input) {
    this->LastName = input;
}

void Contact::SetPhoneNumber(std::string input) {
    this->PhoneNumber = input;
}

void Contact::SetNickName(std::string input) {
    this->NickName = input;
}

void Contact::SetDarkestSecret(std::string input) {
    this->DarkestSecret = input;
}

int CheckInput(std::string input)
{
    if (input == "ADD")
        //fonksiyon yönlendirmesi
        return 1;
    else if (input == "SEARCH")
        //fonksiyon yönlendirmesi
        return 1;
    else if (input == "EXIT")
        return 0;
    else
    {
        std::cout<<"Please enter a valid command."<<std::endl;
        return 1;
    }
}

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
        std::cout << "First Name : " << ContactList[--i].GetContact("FirstName") << std::endl;
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

int	main(void)
{
	Phonebook 	ph1;
	std::string	str;
    
	while (!std::cin.eof())
	{
        if(str == "EXIT")
            return (0);
		std::cout << "Enter a command [ ADD | SEARCH | EXIT ] > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			ph1.ADD();
		else if (str == "SEARCH")
			ph1.SEARCH();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}

// ADD için get line ile alwhile (getline(cin, input) && !cin.eof())


