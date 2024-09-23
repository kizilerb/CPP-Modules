#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), target("Default"){
	std::cout << "PresidentialPardonForm Default Constructor Called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target_):AForm("PresidentialPardonForm", 25, 5), target(target_){
	std::cout << "PresidentialPardonForm Constructor Called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):AForm("PresidentialPardonForm", 25, 5), target(copy.target){
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){
	std::cout << "Form Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
	this->target = copy.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget()const{
	return target;
}

void PresidentialPardonForm::execute(const Bureaucrat& execute) const{
	if(this->getSignedForm() == true)
		throw AForm::SignedFormExeption();
	if(this->getExecGrade() < execute.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " Forgiven by Zaphod Beeblebrox." << std::endl;
}