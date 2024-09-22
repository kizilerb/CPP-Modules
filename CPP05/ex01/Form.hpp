#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string formName;
        bool signedForm;
        int signGrade;
		const int execGrade;

	public:
		Form();
		Form(std::string namein, int signGradein, int execGradein);
		Form(const Form& copy);
		Form& operator=(Form const& copy);
		~Form();

		std::string getName() const;
		bool getSignedForm() const;
		int getSignedGrade() const;
		int getExecGrade() const;
		void setSignedGrade(int signGradein);
		int setExecGrade(int execGradein);

		void beSigned(Bureaucrat& officer);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

};
std::ostream& operator<<(std::ostream& os, const Form& object);
#endif