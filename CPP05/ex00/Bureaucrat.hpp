#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
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

        void incrementGrade();
		void decrementGrade();

		void setGrade(int value);


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object);



#endif