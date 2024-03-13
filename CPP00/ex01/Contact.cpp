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
