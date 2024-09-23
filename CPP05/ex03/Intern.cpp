#include "Intern.hpp"

Intern::Intern(){
	cout << "Intern Default Constructor Called" << endl;

	formList["Robotomy Request"] = &createRobotomyRequestForm;
    formList["Presidential Pardon"] = &createPresidentialPardonForm;
    formList["Shrubbery Creation"] = &createShrubberyCreationForm;
}

Intern::Intern(const Intern& copy){
	(void)copy;
	cout << "Intern Copy Constructor Called" << endl;
}

Intern& Intern::operator=(const Intern& copy){
	(void)copy;
	cout << "Intern Copy Assignment Operator Called" << endl;
	return *this;
}

Intern::~Intern(){
	cout << "Intern Destructor Called" << endl;
}

Form* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Form* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

Form * Intern::makeForm(std::string name, std::string target ){
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
