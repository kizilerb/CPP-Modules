#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Intern Default Constructor Called" << std::endl;

	formList["Robotomy Request"] = &createRobotomyRequestForm;
    formList["Presidential Pardon"] = &createPresidentialPardonForm;
    formList["Shrubbery Creation"] = &createShrubberyCreationForm;
}

Intern::Intern(const Intern& copy){
	(void)copy;
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy){
	(void)copy;
	std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	return *this;
}

Intern::~Intern(){
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm * Intern::makeForm(std::string name, std::string target ){
	std::map<std::string, FormCreationFunction>::iterator it = formList.find(name);
	if (it != formList.end()){
		std::cout<< "Intern creates" << name<<std::endl;
		return it->second(target);
	}
	else{
		std::cout<<"Invalid form name. The form cannot be made." << std::endl;
		return NULL;
	}
}
