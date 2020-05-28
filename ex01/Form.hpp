#ifndef _FORM_
#define _FORM_
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _sign;
        int const _grade_to_sign;
        int const _grade_to_execut;

    public:
        Form();
        Form(std::string const name, int grade_to_sign, int grade_to_execut);
        Form(const Form &cpy);
        Form &operator=(const Form &cpy);
        ~Form();
        int getGradeSign() const;
        int getGradeExecut()const;
        std::string getName() const;
        bool getSign() const;
        class GradeTooHightException : public std::exception 
        {
            public:
                GradeTooHightException();
                GradeTooHightException(const GradeTooHightException &cpy) {(void)cpy;}
                GradeTooHightException &operator=(const GradeTooHightException &cpy) {(void)cpy; return *this;}
                ~GradeTooHightException();
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                GradeTooLowException(const GradeTooLowException &cpy){(void)cpy;}
                GradeTooLowException &operator=(const GradeTooLowException &cpy){(void)cpy; return *this;}
                ~GradeTooLowException();
                virtual const char *what() const throw();

        };
        bool beSigned(Bureaucrat &man);
};

std::ostream &operator<<(std::ostream &cout, Form &classe);

#endif