#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string formName;
        bool signedForm;
        int signGrade;
		const int execGrade;

	public:
		AForm();
		AForm(std::string namein, int signGradein, int execGradein);
		AForm(const AForm& copy);
		AForm& operator=(AForm const& copy);
		virtual ~AForm();

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

        class SignedFormException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		virtual void execute(const Bureaucrat& execute) const =0;

};
std::ostream& operator<<(std::ostream& os, const AForm& object);
#endif
