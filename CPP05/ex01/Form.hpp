#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

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
		Form& operator=(const Form& copy);
		~Form();

		std::string getName();
		bool getSignedForm();
		int getSignedGrade();
		int getexecGrade();
		void setSignedGrade(int signGradein);
		void setExecGrade(int execGradein);

		void beSigned(Bureaucrat& officer);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		}

};

#endif