#include "AForm.hpp"

AForm::AForm(): formName("default"), execGrade(150) {
    signedForm = false;
    signGrade = 150;
    std::cout<< "Default constructor is called." << std::endl;
}

AForm::AForm(std::string namein, int signGradein, int execGradein): formName(namein), execGrade(this->setExecGrade(execGradein)) {
    this->setSignedGrade(signGradein);
    this->signedForm = false;
    std::cout<< "Constructor is called." << std::endl;
}

AForm & AForm::operator=(const AForm & copy){
	this->signedForm = copy.signedForm;
	this->signGrade = copy.signGrade;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

AForm::AForm(const AForm& copy):formName(copy.formName), signedForm(copy.signedForm), signGrade(copy.signGrade), execGrade(copy.execGrade){
    std::cout << "Copy constructor is called." << std::endl;
}

AForm::~AForm(){
    std::cout << "AForm Destructor is called." << std::endl;
}

std::string AForm::getName() const{
    return this->formName;
}

bool AForm::getSignedForm() const{
    return this->signedForm;
}

int AForm::getSignedGrade() const{
    return this->signGrade;
}

int AForm::getExecGrade() const{
    return this->execGrade;
}

void AForm::setSignedGrade(int signGradein){
    try{
        if (signGradein > 150)
            throw GradeTooLowException();
        else if (signGradein < 1)
            throw GradeTooHighException();
        else
            this->signGrade = signGradein;
    }
    catch(std::exception &e){
        std::cout<< e.what() << std::endl;
        std::cout << "Lowest value which is 150 is set as default for signed grade of the AForm." << std::endl;
        this->signGrade = 150;
    }
    
}
int AForm::setExecGrade(int execGrade){ //const value
	try{
		if(execGrade < 1)
			throw GradeTooHighException();
		else if (execGrade > 150)
			throw GradeTooLowException();
		else
			return execGrade;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
		std::cout << "Lowest value which is 150 is set as default for the exec grade of the AForm." << std::endl;
		return 150;
	}
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("Grade is too high, out of interval.");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Grade is too low, out of interval.");
}

const char * AForm::SignedFormExeption::what() const throw(){
	return "This form is already signed.";
}

void AForm::beSigned(Bureaucrat& officer){
    try{
        if(this->getSignedGrade() < officer.getGrade())
            throw GradeTooLowException();
        else
            std::cout << "The AForm" << this->getName() << "is signed by " << officer.getName() << "." << std::endl;
            this->signedForm = true;
    }
    catch(std::exception &e){
        std::cout << "The AForm "<< this->getName() << " could not be signed by " << officer.getName()<<  " because" << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& object){
	os	<< object.getName() << " AForm Info.\n"
		<< "Is signed: " << (object.getSignedForm() ? "Yes" : "No") << ".\n"
		<< "Grade to sign: " << object.getSignedGrade() << ".\n"
		<< "Grade to execute: " << object.getExecGrade() << "." << std::endl;
	return os;
}