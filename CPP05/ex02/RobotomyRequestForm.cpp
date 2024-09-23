#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), target("Default"){
	std::cout << "RobotomyRequestForm Default Constructor Called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_):AForm("RobotomyRequestForm", 72, 45), target(target_){
	std::cout << "RobotomyRequestForm Constructor Called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):AForm("RobotomyRequestForm", 72, 45), target(copy.target){
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
	std::cout << "Form Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
	this->target = copy.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget()const{
	return target;
}

void RobotomyRequestForm::execute(const Bureaucrat& execute) const{
	if(this->getSignedForm() == true)
		throw AForm::SignedFormExeption();
	if(this->getExecGrade() < execute.getGrade())
		throw AForm::GradeTooLowException();

		std::srand(std::time(nullptr)); //seed
		int random_number = rand() % 100;
		std::cout << "random number : " << random_number << std::endl;
		if(random_number % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << " the robotomy failed." << std::endl;
}
