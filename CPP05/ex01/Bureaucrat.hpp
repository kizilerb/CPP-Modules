#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string namein, int gradein);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        std::string getName()const;
		int getGrade()const;

        void increaseGrade();
		void decreaseGrade();

		void setGrade(int value);

        class GradeTooHighException : public std::exception{
            public: 
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception{
            public: 
                virtual const char* what() const throw();
        };

        void signForm(Form& form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object);



#endif