#ifndef _BUREAUCRAT_
#define _BUREAUCRAT_
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(void);
	    Bureaucrat(std::string name, int grade);
	    Bureaucrat(const Bureaucrat &cpy);
	    ~Bureaucrat(void);
	    Bureaucrat&	operator = (const Bureaucrat &old);
	    std::string	getName(void)	const;
	    int	getGrade(void)	const;
        void increase();
        void decrement(); 
        class GradeTooHightException : public std::exception
        {
            public:
                GradeTooHightException(void);
                GradeTooHightException(const GradeTooHightException &cpy);
                GradeTooHightException &operator=(const GradeTooHightException &cpy);
                ~GradeTooHightException();
                virtual const char* what() const throw();

        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException(void);
                GradeTooLowException(const GradeTooLowException &cpy);
                GradeTooLowException &operator=(const GradeTooLowException &cpy);
                ~GradeTooLowException();
                virtual const char* what() const throw();
        };
        void signForm(Form &sign);
};
std::ostream &operator<<(std::ostream &cout, Bureaucrat &classe);

#endif