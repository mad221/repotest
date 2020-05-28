#ifndef _BUREAUCRAT_
#define _BUREAUCRAT_
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

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
	    Bureaucrat&	operator=(const Bureaucrat &cpy);
	    std::string	getName(void)	const;
	    int			getGrade(void)	const;
        void increase(void);
        void decrement(void); 
        class GradeTooHightException : public std::exception
        {
            public:
                GradeTooHightException();
                GradeTooHightException(const GradeTooHightException &cpy) {(void)cpy;}
                GradeTooHightException &operator=(const GradeTooHightException &cpy) {(void)cpy; return *this;}
                ~GradeTooHightException();
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                GradeTooLowException(const GradeTooLowException &cpy) { (void)cpy;}
                GradeTooLowException &operator=(const GradeTooLowException &cpy){ (void)cpy; return *this;}
                ~GradeTooLowException();
                virtual const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream &cout, Bureaucrat &classe);

#endif