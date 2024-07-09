#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("Me", 0);
	std::cout << b << std::endl;

	Bureaucrat a("Mike", 151);
	std::cout << a << std::endl;
	a.increaseGrade();
    std::cout << "Increment for grade function is called: " << a;

	Bureaucrat d("Sue", 10);
	std::cout << d << std::endl;
	d.increaseGrade();
    std::cout << "Increment for grade function is called: " << d;

	Bureaucrat c("Cindy", 149);
	std::cout << c << std::endl;
	c.decreaseGrade();
    std::cout << "Decrement for grade function is called: " << c;

	std::cout << "\nTesting copy assingnment" << std::endl;
	Bureaucrat e("Daniel", 42);
	std::cout << e << std::endl;
	e = c;
	std::cout << e << std::endl;
	return 0;
}

