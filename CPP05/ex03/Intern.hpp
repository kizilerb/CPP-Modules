#ifndef
#define
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>

typedef Form* (*FormCreationFunction)(const std::string&);

class Intern {
	private:
		std::map<std::string, FormCreationFunction> formList;

		static Form* createRobotomyRequestForm(const std::string& target);
		static Form* createPresidentialPardonForm(const std::string& target);
		static Form* createShrubberyCreationForm(const std::string& target);
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		Form* makeForm(const string formName, const string target);

};
#endif
