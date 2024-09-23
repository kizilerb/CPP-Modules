#ifndef INTERN_HPP
#define INTERN_HPP
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>

class AForm;
typedef AForm* (*FormCreationFunction)(const std::string&);

class Intern {
	private:
		std::map<std::string, FormCreationFunction> formList;

		static AForm* createRobotomyRequestForm(const std::string& target);
		static AForm* createPresidentialPardonForm(const std::string& target);
		static AForm* createShrubberyCreationForm(const std::string& target);
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		AForm* makeForm(const std::string formName, const std::string target);

};
#endif
