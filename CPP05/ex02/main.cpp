#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat	Thor("Thor", 1);
	//AForm		f("EB115", 0, 156);
	PresidentialPardonForm a("Cara");
	RobotomyRequestForm b("John");
	ShrubberyCreationForm c("Dennis");

	Thor.executeForm(a);
	Thor.executeForm(b);
	Thor.executeForm(c);
	return 0;
}
