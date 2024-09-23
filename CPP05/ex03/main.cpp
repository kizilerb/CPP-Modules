#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	Thor("Thor", 1);
	Intern intern;
	AForm *formPTR;


	formPTR =  intern.makeForm("Robotomy Request", "EFE");
	if(formPTR)
		Thor.executeForm(*formPTR);
	else {
		std::cout << "Not Created Form." << std::endl;
		exit(1);
	}

	delete formPTR;
	return 0;
}
