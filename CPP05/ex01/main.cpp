#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
	Bureaucrat	Jane("Jane", 10);
	Form		f("EB115", 10, 10);

	Jane.signForm(f);
	std::cout << f << std::endl; 
	Bureaucrat	Celine("Celine", 10);
	std::cout << f << std::endl; 
	Celine.signForm(f);
	return 0;
}

