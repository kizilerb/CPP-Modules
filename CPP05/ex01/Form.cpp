#include "Form.hpp"

Form::Form(): formName("default"), execGrade(150) {
    signedForm = false;
    signGrade = 150;
    std::cout<< "Default constructor is called." << std::endl;
}

Form::Form(std::string namein, int signGradein, int execGradein): formName(namein), execGrade(this->setExecGrade(execGradein)) {
    this->setSignedGrade(signGradein);
    this->signedForm = false;
    std::cout<< "Constructor is called." << std::endl;
}

Form & Form::operator=(const Form & copy){
	this->signedForm = copy.signedForm;
	this->signGrade = copy.signGrade;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Form::Form(const Form& copy):formName(copy.formName), signedForm(copy.signedForm), signGrade(copy.signGrade), execGrade(copy.execGrade){
    std::cout << "Copy constructor is called." << std::endl;
}

Form::~Form(){
    std::cout << "Form Destructor is called." << std::endl;
}

std::string Form::getName() const{
    return this->formName;
}

bool Form::getSignedForm() const{
    return this->signedForm;
}

int Form::getSignedGrade() const{
    return this->signGrade;
}

int Form::getExecGrade() const{
    return this->execGrade;
}

void Form::setSignedGrade(int signGradein){
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
        std::cout << "Lowest value which is 150 is set as default for signed grade of the form." << std::endl;
        this->signGrade = 150;
    }
    
}
int Form::setExecGrade(int execGrade){ //const value
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
		std::cout << "Lowest value which is 150 is set as default for the exec grade of the form." << std::endl;
		return 150;
	}
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade is too high, out of interval.");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade is too low, out of interval.");
}

void Form::beSigned(Bureaucrat& officer){
    try{
        if(this->getSignedGrade() < officer.getGrade())
            throw GradeTooLowException();
        else
            std::cout << "The form" << this->getName() << "is signed by " << officer.getName() << "." << std::endl;
            this->signedForm = true;
    }
    catch(std::exception &e){
        std::cout << "The form "<< this->getName() << " could not be signed by " << officer.getName()<<  " because" << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Form& object){
	os	<< object.getName() << " Form Info.\n"
		<< "Is signed: " << (object.getSignedForm() ? "Yes" : "No") << ".\n"
		<< "Grade to sign: " << object.getSignedGrade() << ".\n"
		<< "Grade to execute: " << object.getExecGrade() << "." << std::endl;
	return os;
}