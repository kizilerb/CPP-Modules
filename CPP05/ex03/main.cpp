#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	Poseidon("Poseidon", 1);
	Intern intern;
	AForm *formPTR;


	formPTR =  intern.makeForm("Robotomy Request", "Alp");
	if(formPTR)
		Poseidon.executeForm(*formPTR);
	else {
		std::cout << "Not Created Form." << std::endl;
		exit(1);
	}

	delete formPTR;
	return 0;
}
